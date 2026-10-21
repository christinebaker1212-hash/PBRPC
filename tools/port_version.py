#!/usr/bin/env python3

###
# Ports symbols.txt and splits.txt from one game version to another.
#
# The other version's main.dol is analyzed with dtk to find its functions and
# data objects. Each section's symbols are then aligned against the source
# version's symbols by size. Runs of equal sizes become anchors with a fixed
# address delta, and symbols between two anchors that agree on the delta are
# carried over with it. Source names are kept, so the same C/C++ sources can
# be compiled and diffed against both versions.
#
# Usage:
#   python tools/port_version.py --src RPBP01 --dst RPBE01
#
# Inputs:
#   config/<dst>/seed_symbols.txt   symbols dtk needs to analyze the DOL
#                                   (e.g. sizes of unbounded jump tables)
#   orig/<dst>/sys/main.dol         extracted by `python configure.py` + ninja,
#                                   or pass --dol
# Outputs:
#   config/<dst>/symbols.txt, config/<dst>/splits.txt, config/<dst>/port.log
###

import argparse
import bisect
import difflib
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path
from typing import Dict, List, Optional, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))

SYMBOL_RE = re.compile(
    r"^(?P<name>\S+) = (?P<section>[^:\s]+):0x(?P<addr>[0-9A-Fa-f]+);"
    r"(?: // (?P<attrs>.*))?$"
)
auto_header: List[str] = []
SECTION_ORDER = [
    ".init",
    "extab",
    "extabindex",
    ".text",
    ".ctors",
    ".dtors",
    ".rodata",
    ".data",
    ".bss",
    ".sdata",
    ".sbss",
    ".sdata2",
    ".sbss2",
]


@dataclass
class Symbol:
    name: str
    section: str
    addr: int
    attrs: List[str] = field(default_factory=list)

    @property
    def size(self) -> int:
        for a in self.attrs:
            if a.startswith("size:"):
                return int(a[5:], 16)
        return 0

    @property
    def kind(self) -> str:
        for a in self.attrs:
            if a.startswith("type:"):
                return a[5:]
        return ""

    def with_size(self, size: int) -> "Symbol":
        attrs = [a for a in self.attrs if not a.startswith("size:")]
        if size:
            attrs.insert(1, f"size:0x{size:X}")
        return Symbol(self.name, self.section, self.addr, attrs)

    def line(self) -> str:
        out = f"{self.name} = {self.section}:0x{self.addr:08X};"
        if self.attrs:
            out += " // " + " ".join(self.attrs)
        return out


def read_symbols(path: Path) -> List[Symbol]:
    out = []
    for line in path.read_text().splitlines():
        m = SYMBOL_RE.match(line.strip())
        if m:
            attrs = (m.group("attrs") or "").split()
            out.append(
                Symbol(m.group("name"), m.group("section"), int(m.group("addr"), 16), attrs)
            )
    return out


@dataclass
class Split:
    unit: str
    header: List[str]  # unit-level attribute lines (comment:, order:, ...)
    ranges: List[Tuple[str, int, int, str]]  # section, start, end, extra attrs


def read_splits(path: Path) -> Tuple[List[str], List[Split]]:
    header: List[str] = []
    splits: List[Split] = []
    cur: Optional[Split] = None
    in_sections = False
    for line in path.read_text().splitlines():
        if line.startswith("Sections:"):
            in_sections = True
            header.append(line)
            continue
        if in_sections:
            if line.strip() == "":
                in_sections = False
            else:
                header.append(line)
            continue
        if line and not line[0].isspace() and line.rstrip().endswith(":"):
            cur = Split(line.rstrip()[:-1], [], [])
            splits.append(cur)
            continue
        if cur is None or not line.strip():
            continue
        m = re.match(
            r"^\s+(\S+)\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)(.*)$", line
        )
        if m:
            cur.ranges.append(
                (m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4))
            )
        else:
            cur.header.append(line)
    return header, splits


def dol_sections(dol: bytes) -> List[Tuple[int, int, int]]:
    """(file offset, address, size) for each non-empty DOL segment."""
    offs = struct.unpack(">18I", dol[0:72])
    addrs = struct.unpack(">18I", dol[72:144])
    sizes = struct.unpack(">18I", dol[144:216])
    return [(offs[i], addrs[i], sizes[i]) for i in range(18) if sizes[i]]


def analyze(dtk: Path, dol: Path, seed: Path, work: Path) -> List[Symbol]:
    """Run dtk's analysis on the target DOL and return the symbols it found."""
    work.mkdir(parents=True, exist_ok=True)
    shutil.copy(seed, work / "symbols.txt")
    (work / "splits.txt").write_text("")
    (work / "config.yml").write_text(
        f"object: {dol.resolve()}\nsymbols: symbols.txt\nsplits: splits.txt\n"
    )
    subprocess.run(
        [str(dtk), "-C", str(work), "dol", "split", "config.yml", "out"],
        check=True,
        stdout=subprocess.DEVNULL,
    )
    syms = read_symbols(work / "symbols.txt")
    global auto_header
    auto_header = read_splits(work / "splits.txt")[0]
    # dtk labels both small bss sections ".sbss"; the one after the last
    # initialized section is .sbss2.
    data_end = max(a + n for _, a, n in dol_sections(dol.read_bytes()))
    for s in syms:
        if s.section == ".sbss" and s.addr >= data_end:
            s.section = ".sbss2"
    return syms


def align_section(
    src: List[Symbol], dst: List[Symbol], seed: Dict[int, int], log
) -> Dict[int, int]:
    """Maps source addresses to target addresses for one section.

    seed holds mappings known from relocations; they take priority."""
    src = sorted(src, key=lambda s: s.addr)
    dst = sorted(dst, key=lambda s: s.addr)
    mapping: Dict[int, int] = {s.addr: seed[s.addr] for s in src if s.addr in seed}
    taken = set(mapping.values())
    key = lambda s: (s.kind == "function", s.size)
    sm = difflib.SequenceMatcher(
        None, [key(s) for s in src], [key(s) for s in dst], autojunk=False
    )
    fuzzy = []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            for k in range(i2 - i1):
                a, b = src[i1 + k].addr, dst[j1 + k].addr
                if a not in mapping and b not in taken:
                    mapping[a] = b
        elif tag == "replace" and i2 - i1 == j2 - j1:
            fuzzy.append((i1, i2, j1))

    # Anchors: equal-size runs. Fill gaps where both neighbours agree on delta.
    dst_funcs = {d.addr for d in dst if d.kind == "function"}
    anchors = sorted(mapping.items())
    anchor_addrs = [a for a, _ in anchors]
    for s in src:
        if s.addr in mapping:
            continue
        i = bisect.bisect_left(anchor_addrs, s.addr)
        if 0 < i < len(anchors):
            dl = anchors[i - 1][1] - anchors[i - 1][0]
            dr = anchors[i][1] - anchors[i][0]
            # Functions must land on a function the analysis found; data may
            # be split finer than the analysis splits it.
            if dl == dr and (s.kind != "function" or s.addr + dl in dst_funcs):
                mapping[s.addr] = s.addr + dl

    # Same number of symbols between anchors, different sizes: the code
    # changed between versions but the symbols are most likely the same.
    for i1, i2, j1 in fuzzy:
        for k in range(i2 - i1):
            s = src[i1 + k]
            if s.addr not in mapping and dst[j1 + k].addr not in taken:
                mapping[s.addr] = dst[j1 + k].addr
                log.write(
                    f"fuzzy {s.section} {s.name} 0x{s.addr:08X} -> "
                    f"0x{dst[j1 + k].addr:08X} size 0x{s.size:X} -> 0x{dst[j1 + k].size:X}\n"
                )
    return mapping


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--src", default="RPBP01")
    parser.add_argument("--dst", default="RPBE01")
    parser.add_argument("--dol", type=Path, help="target main.dol")
    parser.add_argument("--dtk", type=Path, default=Path("build/tools/dtk"))
    parser.add_argument(
        "--no-refine",
        action="store_true",
        help="ignore objects from a previous build of the target version",
    )
    args = parser.parse_args()

    root = Path(__file__).resolve().parent.parent
    os.chdir(root)
    src_dir = Path("config") / args.src
    dst_dir = Path("config") / args.dst
    dol_path = args.dol or Path("orig") / args.dst / "sys" / "main.dol"
    if not dol_path.exists():
        sys.exit(f"{dol_path} not found; pass --dol")

    log = open(dst_dir / "port.log", "w")
    src_syms = read_symbols(src_dir / "symbols.txt")
    with tempfile.TemporaryDirectory() as tmp:
        dst_auto = analyze(args.dtk, dol_path, dst_dir / "seed_symbols.txt", Path(tmp))
    seed_syms = read_symbols(dst_dir / "seed_symbols.txt")

    # Hints from a previous build: relocations of matched functions tell where
    # the symbols they reference are in the target.
    seed: Dict[int, int] = {}
    unit_starts: Dict[Tuple[str, str], int] = {}
    if not args.no_refine and Path("objdiff.json").exists():
        seed, unit_starts = collect_hints(src_syms, dst_dir, log)
    seed.update(sinit_hints(src_syms, dst_auto, src_dir, dol_path, log))

    # A hint must land in the right section, and a function hint on a
    # function the analysis found with the same size.
    src_by_addr = {}
    for s in src_syms:
        src_by_addr.setdefault(s.addr, s)
    auto_funcs = {s.addr: s.size for s in dst_auto if s.kind == "function"}
    auto_bounds: Dict[str, Tuple[int, int]] = {}
    for s in dst_auto:
        lo, hi = auto_bounds.get(s.section, (s.addr, s.addr))
        auto_bounds[s.section] = (min(lo, s.addr), max(hi, s.addr + s.size))
    for a, t in list(seed.items()):
        s = src_by_addr[a]
        lo, hi = auto_bounds.get(s.section, (0, 0))
        ok = lo <= t < hi
        if ok and s.kind == "function" and not s.name.startswith("__sinit_"):
            ok = auto_funcs.get(t) == s.size
        if not ok:
            log.write(f"hint rejected {s.name} 0x{a:08X} -> 0x{t:08X}\n")
            del seed[a]

    # Hints fill gaps in the size alignment; they never move a symbol the
    # alignment placed, nor claim an address it gave to another symbol.
    pure: Dict[int, int] = {}
    for sec in SECTION_ORDER:
        pure.update(
            align_section(
                [s for s in src_syms if s.section == sec],
                [s for s in dst_auto if s.section == sec],
                {},
                open(os.devnull, "w"),
            )
        )
    pure_inv = {t: a for a, t in pure.items()}
    for a, t in list(seed.items()):
        # Data references are reliable; a call can go to a different
        # function in the other version (DEBUGPrint vs OSReport).
        if src_by_addr[a].kind != "function":
            continue
        if pure.get(a, t) != t or pure_inv.get(t, a) != a:
            log.write(f"hint rejected {src_by_addr[a].name} 0x{a:08X} -> 0x{t:08X}: conflicts with alignment\n")
            del seed[a]

    # Map every source symbol to a target address, section by section.
    mapping: Dict[int, int] = {}
    for sec in SECTION_ORDER:
        a = [s for s in src_syms if s.section == sec]
        b = [s for s in dst_auto if s.section == sec]
        m = align_section(a, b, seed, log)
        mapping.update(m)
        log.write(f"section {sec}: {len(m)}/{len(a)} mapped ({len(b)} found in target)\n")
        print(f"{sec:12} {len(m):6}/{len(a):<6} mapped")

    # Target symbols: mapped source symbols, then analyzed symbols that don't
    # overlap any of them.
    auto_by_addr = {s.addr: s for s in dst_auto}
    mapped_src = sorted(mapping)
    # Several symbols can share an address (a label and an object).
    out: Dict[int, List[Symbol]] = {}
    names = set()
    for s in src_syms:
        if s.addr not in mapping:
            log.write(f"unmapped {s.section} {s.name} 0x{s.addr:08X}\n")
            continue
        t = mapping[s.addr]
        sym = Symbol(s.name, s.section, t, list(s.attrs))
        auto = auto_by_addr.get(t)
        if auto is not None and auto.section == s.section and auto.size and auto.size != s.size:
            # Only trust the analyzed size if the object changed; dtk merges
            # objects the source config split by hand.
            # Function bounds from the analysis are always reliable.
            if s.kind == "function" or t + s.size > (
                next_mapped(mapped_src, mapping, s.addr) or 0xFFFFFFFF
            ):
                sym = sym.with_size(auto.size)
        if any(o.kind == sym.kind for o in out.get(t, [])):
            log.write(f"duplicate {s.name} at 0x{t:08X}\n")
            continue
        out.setdefault(t, []).append(sym)
        names.add(s.name)
    for s in seed_syms:
        if s.addr not in out:
            out[s.addr] = [s]
            names.add(s.name)

    all_syms = [s for v in out.values() for s in v]
    covered = sorted((s.addr, s.addr + max(s.size, 1)) for s in all_syms)
    starts = [c[0] for c in covered]
    max_end = []
    for c in covered:
        max_end.append(max(c[1], max_end[-1] if max_end else 0))
    for s in dst_auto:
        if s.addr in out:
            continue
        i = bisect.bisect_right(starts, s.addr) - 1
        if i >= 0 and max_end[i] > s.addr:
            continue
        end = s.addr + max(s.size, 1)
        j = bisect.bisect_left(starts, s.addr)
        if j < len(starts) and starts[j] < end:
            continue
        if s.name in names:
            s = Symbol(s.name + "_" + args.dst, s.section, s.addr, s.attrs)
        out[s.addr] = [s]
        names.add(s.name)

    # Hand-placed target symbols, for code that differs between versions
    # so that the alignment can't place it.
    overrides_path = dst_dir / "symbol_overrides.txt"
    if overrides_path.exists():
        for o in read_symbols(overrides_path):
            for addr in list(out):
                out[addr] = [
                    s for s in out[addr]
                    if s.name != o.name and not (addr == o.addr and s.kind == o.kind)
                ]
                if not out[addr]:
                    del out[addr]
            out.setdefault(o.addr, []).append(o)

    with open(dst_dir / "symbols.txt", "w", newline="\n") as f:
        for addr in sorted(out):
            for sym in out[addr]:
                f.write(sym.line() + "\n")
    all_syms = [s for v in out.values() for s in v]

    # Splits: map every range through the symbol mapping.
    header, splits = read_splits(src_dir / "splits.txt")
    src_by_sec: Dict[str, List[int]] = {}
    for s in src_syms:
        src_by_sec.setdefault(s.section, []).append(s.addr)
    for v in src_by_sec.values():
        v.sort()

    def map_addr(sec: str, addr: int) -> Optional[int]:
        if addr in mapping:
            return mapping[addr]
        addrs = src_by_sec.get(sec, [])
        i = bisect.bisect_left(addrs, addr)
        left = addrs[i - 1] if i > 0 else None
        right = addrs[i] if i < len(addrs) else None
        dl = mapping[left] - left if left in mapping else None
        dr = mapping[right] - right if right in mapping else None
        if dl is not None and (dl == dr or right is None):
            return addr + dl
        if dr is not None and left is None:
            return addr + dr
        return None

    dst_bounds = {}
    for s in all_syms:
        lo, hi = dst_bounds.get(s.section, (s.addr, s.addr))
        dst_bounds[s.section] = (min(lo, s.addr), max(hi, s.addr + s.size))

    ported: List[Split] = []
    dropped = 0
    for sp in splits:
        ranges = []
        for sec, start, end, extra in sp.ranges:
            ms = map_addr(sec, start)
            me = map_addr(sec, end)
            hint = unit_starts.get((sp.unit, sec))
            if hint is not None and hint != ms:
                log.write(f"split {sp.unit} {sec}: start 0x{hint:08X} from relocations (was {ms and hex(ms)})\n")
                if me is None or me <= hint or (ms is not None and me - ms != end - start):
                    me = hint + (end - start)
                ms = hint
            if ms is None or me is None or me <= ms:
                log.write(
                    f"split {sp.unit} {sec} 0x{start:08X}-0x{end:08X}: "
                    f"unresolved ({ms and hex(ms)}, {me and hex(me)})\n"
                )
                dropped += 1
                continue
            ranges.append((sec, ms, me, extra))
        ported.append(Split(sp.unit, sp.header, ranges))

    func_starts = sorted(s.addr for s in dst_auto if s.kind == "function")

    # Resolve unmapped boundaries from the neighbouring unit's range when the
    # source ranges were contiguous.
    for i, sp in enumerate(splits):
        have = {r[0] for r in ported[i].ranges}
        for sec, start, end, extra in sp.ranges:
            if sec in have:
                continue
            prev = next_range(splits, ported, i, sec, -1)
            nxt = next_range(splits, ported, i, sec, 1)
            ms = me = None
            if prev and prev[0][2] == start:
                ms = prev[1][2]
            else:
                ms = map_addr(sec, start)
            if nxt and nxt[0][1] == end:
                me = nxt[1][1]
            else:
                me = map_addr(sec, end)
            # One side known: assume the range kept its size. Code boundaries
            # snap to the nearest function the analysis found.
            if ms is not None and me is None:
                me = ms + (end - start)
                if sec == ".text":
                    me = nearest(func_starts, me)
            elif me is not None and ms is None:
                ms = me - (end - start)
                if sec == ".text":
                    ms = nearest(func_starts, ms)
            if ms is not None and me is not None and me > ms:
                ported[i].ranges.append((sec, ms, me, extra))
                ported[i].ranges.sort(key=lambda r: SECTION_ORDER.index(r[0]))
                log.write(f"split {sp.unit} {sec}: resolved from neighbours\n")
                dropped -= 1

    # The last unit of a section can't extend past the section's last
    # object; the remainder of the DOL segment is padding.
    for sp in ported:
        sp.ranges = [
            (sec, st, min(en, dst_bounds[sec][1]), extra) if sec in dst_bounds else (sec, st, en, extra)
            for sec, st, en, extra in sp.ranges
        ]
        sp.ranges = [r for r in sp.ranges if r[2] > r[1]]

    # Range edges must fall between symbols.
    sym_ranges: Dict[str, List[Tuple[int, int]]] = {}
    for sym in all_syms:
        if sym.size:
            sym_ranges.setdefault(sym.section, []).append((sym.addr, sym.addr + sym.size))
    for v in sym_ranges.values():
        v.sort()

    def inside(sec: str, addr: int) -> Optional[Tuple[int, int]]:
        rs = sym_ranges.get(sec, [])
        i = bisect.bisect_right(rs, (addr, 0xFFFFFFFF)) - 1
        while i >= 0 and rs[i][0] < addr:
            if rs[i][1] > addr:
                return rs[i]
            i -= 1
            if i >= 0 and addr - rs[i][0] > 0x100000:
                break
        return None

    for sp in ported:
        fixed = []
        for sec, st, en, extra in sp.ranges:
            r = inside(sec, st)
            if r:
                st = r[0]
            r = inside(sec, en)
            if r:
                en = r[0] if r[0] > st else r[1]
            if en > st:
                fixed.append((sec, st, en, extra))
        sp.ranges = fixed

    # Ranges must not overlap; drop the later one if they do.
    for sec in SECTION_ORDER:
        rs = sorted(
            ((r[1], r[2], k) for k, sp in enumerate(ported) for r in sp.ranges if r[0] == sec)
        )
        last_end = 0
        for st, en, k in rs:
            if st < last_end:
                log.write(f"split {ported[k].unit} {sec}: overlaps previous unit, dropped\n")
                ported[k].ranges = [r for r in ported[k].ranges if not (r[0] == sec and r[1] == st)]
                dropped += 1
                continue
            last_end = en

    # Section alignment: the larger of the source's and what the analysis
    # inferred from the target's section addresses.
    auto_align = {}
    for line in auto_header:
        m = re.match(r"^\s+(\S+)\s.*align:(\d+)", line)
        if m:
            auto_align.setdefault(m.group(1), int(m.group(2)))
    for k, line in enumerate(header):
        m = re.match(r"^(\s+(\S+)\s.*align:)(\d+)(.*)$", line)
        if m and m.group(2) in auto_align:
            align = max(int(m.group(3)), auto_align[m.group(2)])
            header[k] = f"{m.group(1)}{align}{m.group(4)}"

    with open(dst_dir / "splits.txt", "w", newline="\n") as f:
        f.write("\n".join(header) + "\n\n")
        for sp in ported:
            f.write(sp.unit + ":\n")
            for h in sp.header:
                f.write(h + "\n")
            for sec, st, en, extra in sp.ranges:
                f.write(f"\t{sec:<11} start:0x{st:08X} end:0x{en:08X}{extra}\n")
            f.write("\n")
    print(f"{len(all_syms)} symbols, {len(ported)} units, {dropped} ranges unresolved (see port.log)")


def collect_hints(
    src_syms: List[Symbol], dst_dir: Path, log
) -> Tuple[Dict[int, int], Dict[Tuple[str, str], int]]:
    """Pairs relocations of functions present in both the compiled source
    object and the object split from the target DOL.

    Returns source address -> target address for symbols with a unique name,
    and (unit, section) -> target start for sections the source object
    defines."""
    import json
    from collections import Counter

    from elf32 import ElfObject

    src_by_name: Dict[str, List[Symbol]] = {}
    for s in src_syms:
        src_by_name.setdefault(s.name, []).append(s)
    dst_by_name: Dict[str, int] = {}
    for s in read_symbols(dst_dir / "symbols.txt"):
        dst_by_name.setdefault(s.name, s.addr)
    _, dst_splits = read_splits(dst_dir / "splits.txt")
    dst_unit_start = {
        (sp.unit, sec): st for sp in dst_splits for sec, st, _en, _x in sp.ranges
    }

    name_votes: Dict[str, Counter] = {}
    unit_votes: Dict[Tuple[str, str], Counter] = {}
    units = json.loads(Path("objdiff.json").read_text())["units"]
    for unit in units:
        source = unit.get("metadata", {}).get("source_path")
        base_path = unit.get("base_path")
        target_path = unit.get("target_path")
        if not source or not base_path or not target_path:
            continue
        if not Path(base_path).exists() or not Path(target_path).exists():
            continue
        base = ElfObject(Path(base_path))
        target = ElfObject(Path(target_path))
        base_fns = base.functions()
        target_fns = target.functions()

        def target_addr(sym) -> Optional[int]:
            if target.defined(sym):
                sec = target.section_name(sym.shndx)
                start = dst_unit_start.get((source, sec))
                return None if start is None else start + sym.value
            return dst_by_name.get(sym.name)

        for name, bf in base_fns.items():
            tf = target_fns.get(name)
            if tf is None or tf.size != bf.size:
                continue
            bsec = base.section_names.index(base.section_name(bf.shndx))
            tsec = target.section_names.index(target.section_name(tf.shndx))
            brel = [
                r for r in base.relocs.get(bsec, [])
                if bf.value <= r.offset < bf.value + bf.size
            ]
            trel = [
                r for r in target.relocs.get(tsec, [])
                if tf.value <= r.offset < tf.value + tf.size
            ]
            if len(brel) != len(trel):
                continue
            for br, tr in zip(brel, trel):
                if br.offset - bf.value != tr.offset - tf.value or br.type != tr.type:
                    break
                taddr = target_addr(tr.symbol)
                if taddr is None:
                    continue
                addr = taddr + tr.addend - br.addend
                bsym = br.symbol
                # Code layout comes from the function mapping; data sections
                # are placed by what the code references.
                sec = base.section_name(bsym.shndx) if base.defined(bsym) else None
                if sec and sec != ".text" and bsym.bind != 2:  # not weak
                    unit_votes.setdefault((source, sec), Counter())[addr - bsym.value] += 1
                if bsym.bind == 1 and bsym.name:  # global, not weak
                    name_votes.setdefault(bsym.name, Counter())[addr] += 1

    seed: Dict[int, int] = {}
    for name, votes in name_votes.items():
        cands = src_by_name.get(name, [])
        # Weak functions (inline constructors) exist once per unit in the
        # target; only trust names whose references all agree.
        if len(cands) != 1 or len(votes) != 1:
            continue
        addr, _ = votes.most_common(1)[0]
        seed[cands[0].addr] = addr
    unit_starts = {}
    for k, v in unit_votes.items():
        if len(v) == 1:
            unit_starts[k] = next(iter(v))
        else:
            log.write(f"hint conflict {k[0]} {k[1]}: {[hex(a) for a in v]}\n")
    log.write(f"hints: {len(seed)} symbols, {len(unit_starts)} unit sections from relocations\n")
    print(f"hints: {len(seed)} symbols, {len(unit_starts)} unit sections from relocations")
    return seed, unit_starts


def sinit_hints(
    src_syms: List[Symbol], dst_auto: List[Symbol], src_dir: Path, dol_path: Path, log
) -> Dict[int, int]:
    """Maps each unit's static initializer through the .ctors table, which
    has the same layout in both versions."""
    _, splits = read_splits(src_dir / "splits.txt")
    src_ctors = next((s.addr for s in src_syms if s.name == "_ctors"), None)
    dst_ctors = next((s.addr for s in dst_auto if s.name == "_ctors"), None)
    if src_ctors is None or dst_ctors is None:
        return {}
    dol = dol_path.read_bytes()

    def read_word(addr: int) -> Optional[int]:
        for off, a, n in dol_sections(dol):
            if a <= addr < a + n:
                return struct.unpack_from(">I", dol, off + addr - a)[0]
        return None

    sinits = {}
    for s in src_syms:
        if s.name.startswith("__sinit_") and s.kind == "function":
            sinits.setdefault(s.addr, s)
    out: Dict[int, int] = {}
    for sp in splits:
        text = [r for r in sp.ranges if r[0] == ".text"]
        ctors = [r for r in sp.ranges if r[0] == ".ctors"]
        if not text or not ctors:
            continue
        found = [a for a in sinits if text[0][1] <= a < text[0][2]]
        if len(found) != 1:
            continue
        target = read_word(dst_ctors + ctors[0][1] - src_ctors)
        if target is not None:
            out[found[0]] = target
    log.write(f"hints: {len(out)} static initializers from .ctors\n")
    return out


def nearest(sorted_addrs: List[int], addr: int) -> int:
    i = bisect.bisect_left(sorted_addrs, addr)
    cands = sorted_addrs[max(i - 1, 0) : i + 1]
    return min(cands, key=lambda a: abs(a - addr)) if cands else addr


def next_mapped(mapped_src: List[int], mapping: Dict[int, int], addr: int) -> Optional[int]:
    # Target address of the next mapped source symbol after addr.
    i = bisect.bisect_right(mapped_src, addr)
    return mapping[mapped_src[i]] if i < len(mapped_src) else None


def next_range(splits, ported, i, sec, step):
    j = i + step
    while 0 <= j < len(splits):
        src = [r for r in splits[j].ranges if r[0] == sec]
        dst = [r for r in ported[j].ranges if r[0] == sec]
        if src:
            if dst:
                return src[0], dst[0]
            return None
        j += step
    return None


if __name__ == "__main__":
    main()
