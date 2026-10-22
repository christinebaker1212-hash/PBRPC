#!/usr/bin/env python3

###
# Adds the data sections of a unit to splits.txt, placed from relocations.
#
# Functions that are the same size in the compiled object and in the object
# split from the target are paired, and their relocations to data the
# compiled object defines give where each of its data sections starts in the
# target. The section size comes from the compiled object. The source config
# (PAL) gets the same range through the PAL names of the target symbols.
#
# Usage: python tools/split_data.py <version> <unit> [--apply]
#   <unit> as in objdiff.json, e.g. libs/RVL_SDK/src/exi/EXIBios
###

import argparse
import json
import re
import sys
from collections import Counter
from pathlib import Path
from typing import Dict, Optional

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject

ROOT = Path(__file__).resolve().parent.parent
DATA_SECTIONS = [".rodata", ".data", ".bss", ".sdata", ".sbss", ".sdata2", ".sbss2"]
ORDER = [".init", "extab", "extabindex", ".text", ".ctors", ".dtors", *DATA_SECTIONS]


def read_symbols(path: Path, sections: Optional[Dict[str, str]] = None) -> Dict[str, int]:
    out = {}
    for line in path.read_text().splitlines():
        m = re.match(r"(\S+) = (\S+):0x([0-9A-Fa-f]+);", line)
        if m:
            out.setdefault(m.group(1), int(m.group(3), 16))
            if sections is not None:
                sections.setdefault(m.group(1), m.group(2))
    return out


def add_split(path: Path, unit: str, sec: str, start: int, end: int) -> bool:
    lines = path.read_text().split("\n")
    try:
        i = lines.index(unit + ":")
    except ValueError:
        return False
    j = i + 1
    while j < len(lines) and lines[j].startswith("\t"):
        j += 1
    block = [l for l in lines[i + 1 : j] if l.split()[0] != sec]
    block.append(f"\t{sec:<11} start:0x{start:08X} end:0x{end:08X}")
    block.sort(key=lambda l: ORDER.index(l.split()[0]) if l.split()[0] in ORDER else -1)
    lines[i + 1 : j] = block
    path.write_text("\n".join(lines))
    return True


def overlaps(path: Path, sec: str, start: int, end: int, unit: str) -> Optional[str]:
    cur = None
    for line in path.read_text().splitlines():
        if line and not line[0].isspace() and line.endswith(":") and not line.startswith("Sections"):
            cur = line[:-1]
        m = re.match(r"\t(\S+)\s+start:0x(\w+) end:0x(\w+)", line)
        if m and cur != unit and m.group(1) == sec:
            s, e = int(m.group(2), 16), int(m.group(3), 16)
            if s < end and start < e:
                return cur
    return None


def symbol_ranges(path: Path) -> Dict[str, list]:
    out: Dict[str, list] = {}
    for line in path.read_text().splitlines():
        m = re.match(r"\S+ = (\S+):0x([0-9A-Fa-f]+); // type:\w+ size:0x([0-9A-Fa-f]+)", line)
        if m:
            a = int(m.group(2), 16)
            out.setdefault(m.group(1), []).append((a, a + int(m.group(3), 16)))
    return out


def snap(ranges: Dict[str, list], sec: str, start: int, end: int) -> Optional[tuple]:
    """Moves the end out of any symbol it falls in; None if the start does."""
    for a, b in ranges.get(sec, []):
        if a < start < b:
            return None
        if a < end < b:
            end = b
    if end % 4:
        # The padding after the last object belongs to the unit.
        nxt = [a for a, _ in ranges.get(sec, []) if a >= end]
        end = min(nxt) if nxt else (end + 3) & ~3
    return start, end


def close_gap(path: Path, sec: str, start: int, end: int) -> int:
    """Extends end to the next split of the section when only padding is left between."""
    starts = []
    prev_end = []
    for line in path.read_text().splitlines():
        m = re.match(r"\t(\S+)\s+start:0x(\w+) end:0x(\w+)", line)
        if m and m.group(1) == sec:
            starts.append(int(m.group(2), 16))
    return end


def fix_gaps(path: Path) -> None:
    """Closes padding-sized gaps between consecutive data splits of a section
    when no symbol starts in the gap."""
    sym_starts: Dict[str, list] = {}
    for line in (path.parent / "symbols.txt").read_text().splitlines():
        m = re.match(r"\S+ = (\S+):0x([0-9A-Fa-f]+);", line)
        if m:
            sym_starts.setdefault(m.group(1), []).append(int(m.group(2), 16))
    lines = path.read_text().split("\n")
    rows = []
    for i, line in enumerate(lines):
        m = re.match(r"\t(\S+)(\s+)start:0x(\w+) end:0x(\w+)(.*)$", line)
        if m and m.group(1) in DATA_SECTIONS:
            rows.append((m.group(1), int(m.group(3), 16), int(m.group(4), 16), i, m))
    by_sec: Dict[str, list] = {}
    for r in rows:
        by_sec.setdefault(r[0], []).append(r)
    n = 0
    for sec, rs in by_sec.items():
        rs.sort(key=lambda r: r[1])
        for a, b in zip(rs, rs[1:]):
            if 0 < b[1] - a[2] < 0x20 and not any(a[2] <= x < b[1] for x in sym_starts.get(sec, [])):
                m = a[4]
                lines[a[3]] = f"\t{m.group(1)}{m.group(2)}start:0x{a[1]:08X} end:0x{b[1]:08X}{m.group(5)}"
                n += 1
    path.write_text("\n".join(lines))
    print(f"{path}: {n} gaps closed")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("version")
    ap.add_argument("unit", help="unit, or --fix-gaps")
    ap.add_argument("--src", default="RPBP01")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    if args.unit == "--fix-gaps":
        for v in (args.version, args.src):
            fix_gaps(ROOT / "config" / v / "splits.txt")
        return

    units = json.loads((ROOT / "objdiff.json").read_text())["units"]
    entry = next(u for u in units if u["name"] == "main/" + args.unit)
    base = ElfObject(ROOT / entry["base_path"])
    target = ElfObject(ROOT / entry["target_path"])
    split_unit = entry["metadata"]["source_path"]
    dst_secs: Dict[str, str] = {}
    dst_syms = read_symbols(ROOT / "config" / args.version / "symbols.txt", dst_secs)
    sec_of_addr = {a: dst_secs[n] for n, a in dst_syms.items()}
    src_syms = read_symbols(ROOT / "config" / args.src / "symbols.txt")

    votes: Dict[str, Counter] = {}
    src_votes: Dict[str, Counter] = {}
    bfns = {s.name: s for s in base.symbols if s.type == 2 and base.defined(s)}
    tfns = {s.name: s for s in target.symbols if s.type == 2 and target.defined(s)}
    for name, bf in bfns.items():
        tf = tfns.get(name)
        if tf is None or tf.size != bf.size:
            continue
        bsec = bf.shndx
        tsec = tf.shndx
        brel = [r for r in base.relocs.get(bsec, []) if bf.value <= r.offset < bf.value + bf.size]
        trel = [r for r in target.relocs.get(tsec, []) if tf.value <= r.offset < tf.value + tf.size]
        if len(brel) != len(trel):
            continue
        for br, tr in zip(brel, trel):
            if br.offset - bf.value != tr.offset - tf.value or br.type != tr.type:
                break
            bs = br.symbol
            if not base.defined(bs):
                continue
            sec = base.section_name(bs.shndx)
            if sec not in DATA_SECTIONS:
                continue
            tname = tr.symbol.name
            if target.defined(tr.symbol):
                continue  # already split into this unit
            taddr = dst_syms.get(tname)
            m = re.match(r"(.+)_([0-9A-F]{8})$", tname)
            if taddr is None and m:
                # dtk suffixes local symbols with their address
                taddr = int(m.group(2), 16)
            if taddr is None:
                continue
            tsec = dst_secs.get(tname) or (dst_secs.get(m.group(1)) if m else None)
            if tsec != sec:
                continue
            votes.setdefault(sec, Counter())[taddr + tr.addend - br.addend - bs.value] += 1
            saddr = src_syms.get(tname)
            if saddr is None and m and dst_syms.get(m.group(1)) == taddr:
                saddr = src_syms.get(m.group(1))
            if saddr is not None:
                src_votes.setdefault(sec, Counter())[saddr + tr.addend - br.addend - bs.value] += 1

    dst_ranges = symbol_ranges(ROOT / "config" / args.version / "symbols.txt")
    src_ranges = symbol_ranges(ROOT / "config" / args.src / "symbols.txt")
    for sec, v in votes.items():
        size = base.section_sizes[base.section_names.index(sec)]
        start = v.most_common(1)[0][0]
        r = snap(dst_ranges, sec, start, start + size)
        if r is None:
            print(f"{sec}: start 0x{start:08X} inside a symbol, skipped")
            continue
        end = close_gap(ROOT / "config" / args.version / "splits.txt", sec, start, r[1])
        line = f"{sec}: {args.version} 0x{start:08X}-0x{end:08X}"
        sv = src_votes.get(sec)
        sstart = sv.most_common(1)[0][0] if sv else None
        if sstart is not None:
            line += f", {args.src} 0x{sstart:08X}-0x{sstart + size:08X}"
        clash = overlaps(ROOT / "config" / args.version / "splits.txt", sec, start, end, split_unit)
        if clash:
            line += f"  (overlaps {clash}, skipped)"
        print(line)
        if args.apply and not clash:
            add_split(ROOT / "config" / args.version / "splits.txt", split_unit, sec, start, end)
            rs = snap(src_ranges, sec, sstart, sstart + size) if sstart is not None else None
            if rs:
                rs = (rs[0], close_gap(ROOT / "config" / args.src / "splits.txt", sec, rs[0], rs[1]))
            if rs and not overlaps(ROOT / "config" / args.src / "splits.txt", sec, rs[0], rs[1], split_unit):
                add_split(ROOT / "config" / args.src / "splits.txt", split_unit, sec, rs[0], rs[1])


if __name__ == "__main__":
    main()
