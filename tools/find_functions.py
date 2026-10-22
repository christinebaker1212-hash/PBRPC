#!/usr/bin/env python3

###
# Finds functions of compiled reference objects in a version's main.dol.
#
# Every function of the given objects is compared with the DOL's code: words
# that carry a relocation in the object are skipped, all others must be equal.
# Prints one line per function found: object, function, address, size, and
# the name the version's symbols.txt has at that address.
#
# Usage: python tools/find_functions.py <version> <objects dir or .o>... [--min-size 0x20]
###

import argparse
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject

ROOT = Path(__file__).resolve().parent.parent


def dol_text(path: Path):
    d = path.read_bytes()
    offs = struct.unpack(">18I", d[0:72])
    addrs = struct.unpack(">18I", d[72:144])
    sizes = struct.unpack(">18I", d[144:216])
    segs = []
    for i in range(7):
        if sizes[i]:
            segs.append((addrs[i], d[offs[i] : offs[i] + sizes[i]]))
    return segs


def obj_functions(path: Path):
    o = ElfObject(path)
    data = path.read_bytes()
    shoff = struct.unpack_from(">I", data, 0x20)[0]
    shentsize, shnum = struct.unpack_from(">HH", data, 0x2E)
    headers = [struct.unpack_from(">10I", data, shoff + i * shentsize) for i in range(shnum)]
    for s in o.symbols:
        if s.type != 2 or not o.defined(s) or s.size < 8:
            continue
        if o.section_name(s.shndx) != ".text":
            continue
        h = headers[s.shndx]
        code = data[h[4] + s.value : h[4] + s.value + s.size]
        masked = set()
        for r in o.relocs.get(s.shndx, []):
            if s.value <= r.offset < s.value + s.size:
                masked.add((r.offset - s.value) // 4)
        words = struct.unpack(f">{len(code) // 4}I", code[: len(code) // 4 * 4])
        yield s.name, words, masked


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("version")
    ap.add_argument("paths", nargs="+", type=Path)
    ap.add_argument("--min-size", type=lambda x: int(x, 0), default=0x20)
    args = ap.parse_args()

    names = {}
    for line in (ROOT / "config" / args.version / "symbols.txt").read_text().splitlines():
        m = re.match(r"(\S+) = \.text:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)", line)
        if m:
            names[int(m.group(2), 16)] = (m.group(1), int(m.group(3), 16))

    segs = dol_text(ROOT / "orig" / args.version / "sys" / "main.dol")
    index = defaultdict(list)
    seg_words = []
    for base, data in segs:
        words = struct.unpack(f">{len(data) // 4}I", data)
        seg_words.append((base, words))
        for i in range(len(words) - 3):
            index[words[i : i + 4]].append((len(seg_words) - 1, i))

    objs = []
    for p in args.paths:
        objs += sorted(p.rglob("*.o")) if p.is_dir() else [p]
    for op in objs:
        for name, words, masked in obj_functions(op):
            if len(words) * 4 < args.min_size:
                continue
            # First window of four words without relocations.
            k = next((i for i in range(len(words) - 3) if not any(j in masked for j in range(i, i + 4))), None)
            if k is None:
                continue
            hits = []
            for si, pos in index.get(words[k : k + 4], []):
                start = pos - k
                base, dw = seg_words[si]
                if start < 0 or start + len(words) > len(dw):
                    continue
                if all(i in masked or dw[start + i] == w for i, w in enumerate(words)):
                    hits.append(base + start * 4)
            for addr in hits:
                cur, size = names.get(addr, ("?", 0))
                print(f"{op}\t{name}\t0x{addr:08X}\t0x{len(words) * 4:X}\t{cur}\t0x{size:X}")


if __name__ == "__main__":
    main()
