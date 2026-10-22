#!/usr/bin/env python3

###
# Names a unit's placeholder functions (fn_XXXXXXXX) after the compiled
# object's functions with the same size and the same code, comparing
# instruction words with the relocated ones masked to their opcode. For units
# whose source compiles functions the target still has unnamed, in any order.
#
# Usage: python tools/name_by_code.py <version> <unit>... [--apply] [--min 0.9]
#   <unit> as the object path under build/<version>/obj, without .o
#   (e.g. libs/nw4r/src/snd/snd_StrmPlayer or src/.unsorted/80012345)
# Renames apply to config/RPBP01/symbols.txt and config/<version>/symbols.txt
# (the source and target configs share placeholder names).
###

import argparse
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject

PLACEHOLDER = re.compile(r"^fn_[0-9A-F]{8}$")


def function_words(o: ElfObject):
    out = {}
    for s in sorted(o.symbols, key=lambda s: s.value):
        if s.type != 2 or not o.defined(s) or not s.name or o.section_name(s.shndx) != ".text":
            continue
        base = o.section_offsets[s.shndx] + s.value
        words = list(struct.unpack_from(">%dI" % (s.size // 4), o.data, base))
        for r in o.relocs.get(s.shndx, []):
            if s.value <= r.offset < s.value + s.size:
                i = (r.offset - s.value) // 4
                words[i] &= 0xFC000000
        out[s.name] = words
    return out


def score(a, b) -> float:
    if len(a) != len(b) or not a:
        return 0.0
    return sum(x == y for x, y in zip(a, b)) / len(a)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("version")
    ap.add_argument("units", nargs="+")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--min", type=float, default=0.9)
    args = ap.parse_args()
    renames = {}
    for unit in args.units:
        base = Path("build") / args.version / re.sub(r"^libs/[^/]+/", "", unit + ".o")
        target = Path("build") / args.version / "obj" / (unit + ".o")
        if not base.exists() or not target.exists():
            print(f"{unit}: missing objects")
            continue
        b, t = function_words(ElfObject(base)), function_words(ElfObject(target))
        free = {n: w for n, w in b.items() if n not in t}
        taken = set()
        for tn, tw in t.items():
            if not PLACEHOLDER.match(tn):
                continue
            # Ties (identical code) go to the earliest free source function, so
            # runs of identical functions pair up in address order.
            order = {n: i for i, n in enumerate(free)}
            ranked = sorted(
                ((score(tw, bw), -order[bn], bn) for bn, bw in free.items() if bn not in taken), reverse=True
            )
            if not ranked or ranked[0][0] < args.min:
                continue
            best = ranked[0]
            tied = sum(r[0] == best[0] for r in ranked)
            renames[tn] = best[2]
            taken.add(best[2])
            print(f"  {tn} -> {best[2]} ({best[0]:.2f}{', tie of %d' % tied if tied > 1 else ''})")
    if args.apply and renames:
        for cfg in {Path("config/RPBP01/symbols.txt"), Path("config") / args.version / "symbols.txt"}:
            text = cfg.read_text()
            for old, new in renames.items():
                text = re.sub(r"^" + re.escape(old) + r" = ", lambda m, new=new: new + " = ", text, flags=re.M)
            cfg.write_text(text)
    print(f"{len(renames)} renames total")


if __name__ == "__main__":
    main()
