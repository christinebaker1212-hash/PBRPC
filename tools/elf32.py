###
# Minimal reader for big-endian ELF32 relocatable objects (Gekko/Broadway).
###

import struct
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, List, Optional

SHT_SYMTAB = 2
SHT_RELA = 4
SHN_UNDEF = 0
SHN_ABS = 0xFFF1
SHN_COMMON = 0xFFF2
STB_LOCAL = 0


@dataclass
class ElfSymbol:
    name: str
    value: int
    size: int
    bind: int
    type: int
    shndx: int


@dataclass
class ElfReloc:
    offset: int
    type: int
    symbol: ElfSymbol
    addend: int


class ElfObject:
    def __init__(self, path: Path) -> None:
        data = path.read_bytes()
        if data[:4] != b"\x7fELF":
            raise ValueError(f"{path}: not an ELF file")
        shoff = struct.unpack_from(">I", data, 0x20)[0]
        shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
        headers = []
        for i in range(shnum):
            headers.append(struct.unpack_from(">10I", data, shoff + i * shentsize))
        strtab_off = headers[shstrndx][4]

        def cstr(off: int) -> str:
            end = data.index(b"\0", off)
            return data[off:end].decode("latin-1")

        self.section_names: List[str] = [cstr(strtab_off + h[0]) for h in headers]
        self.section_sizes: List[int] = [h[5] for h in headers]
        self.symbols: List[ElfSymbol] = []
        # Relocations keyed by the index of the section they apply to.
        self.relocs: Dict[int, List[ElfReloc]] = {}

        for h in headers:
            if h[1] != SHT_SYMTAB:
                continue
            names_off = headers[h[6]][4]
            for k in range(h[5] // 16):
                name, value, size, info, _other, shndx = struct.unpack_from(
                    ">IIIBBH", data, h[4] + k * 16
                )
                self.symbols.append(
                    ElfSymbol(cstr(names_off + name), value, size, info >> 4, info & 0xF, shndx)
                )
        for h in headers:
            if h[1] != SHT_RELA:
                continue
            out = self.relocs.setdefault(h[7], [])
            for k in range(h[5] // 12):
                offset, info, addend = struct.unpack_from(">IIi", data, h[4] + k * 12)
                out.append(ElfReloc(offset, info & 0xFF, self.symbols[info >> 8], addend))
            out.sort(key=lambda r: r.offset)

    def section_name(self, shndx: int) -> Optional[str]:
        if 0 < shndx < len(self.section_names):
            return self.section_names[shndx]
        return None

    def defined(self, sym: ElfSymbol) -> bool:
        return sym.shndx not in (SHN_UNDEF, SHN_ABS, SHN_COMMON) and sym.shndx < len(
            self.section_names
        )

    def functions(self) -> Dict[str, ElfSymbol]:
        return {
            s.name: s
            for s in self.symbols
            if s.type == 2 and self.defined(s) and s.name
        }
