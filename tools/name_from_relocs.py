#!/usr/bin/env python3

###
# Names placeholder symbols (fn_..., lbl_...) after the names the compiled
# sources use for them.
#
# For every unit, functions that are the same size in the compiled object and
# in the object split from the target are paired, and their relocations are
# compared in order. Where the compiled object refers to an undefined name
# that symbols.txt doesn't have, and the target refers to a placeholder at the
# same offset, the placeholder is a candidate for that name. A rename is kept
# only when every vote for the placeholder agrees on one name, and that name
# gets no votes for another placeholder.
#
# Usage: python tools/name_from_relocs.py <version> [--apply]
# Renames apply to config/RPBP01/symbols.txt and config/<version>/symbols.txt.
###

import argparse
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject

ROOT = Path(__file__).resolve().parent.parent
PLACEHOLDER = re.compile(r"^(fn|lbl)_[0-9A-F]{8}$")


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("version")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()

    cfgs = [ROOT / "config/RPBP01/symbols.txt", ROOT / "config" / args.version / "symbols.txt"]
    used = set()
    for c in cfgs:
        used |= set(re.findall(r"^(\S+) = ", c.read_text(), re.M))

    votes = defaultdict(lambda: defaultdict(int))  # placeholder -> name -> count
    units = json.loads((ROOT / "objdiff.json").read_text())["units"]
    for u in units:
        if "base_path" not in u or "target_path" not in u:
            continue
        bp, tp = ROOT / u["base_path"], ROOT / u["target_path"]
        if not bp.exists() or not tp.exists():
            continue
        try:
            base, target = ElfObject(bp), ElfObject(tp)
        except Exception:
            continue
        bdefs = {s.name for s in base.symbols if base.defined(s)}
        tfns = {s.name: s for s in target.symbols if s.type == 2 and target.defined(s)}
        for bf in base.symbols:
            if bf.type != 2 or not base.defined(bf):
                continue
            tf = tfns.get(bf.name)
            if tf is None or tf.size != bf.size:
                continue
            brel = [r for r in base.relocs.get(bf.shndx, []) if bf.value <= r.offset < bf.value + bf.size]
            trel = [r for r in target.relocs.get(tf.shndx, []) if tf.value <= r.offset < tf.value + tf.size]
            if len(brel) != len(trel):
                continue
            if any(b.offset - bf.value != t.offset - tf.value or b.type != t.type for b, t in zip(brel, trel)):
                continue
            for b, t in zip(brel, trel):
                new, old = b.symbol.name, t.symbol.name
                if not new or new in used or new in bdefs or new.startswith("@"):
                    continue
                if new.startswith(("fn_", "lbl_")) or not PLACEHOLDER.match(old) or b.addend != t.addend:
                    continue
                votes[old][new] += 1

    by_new = defaultdict(set)
    for old, names in votes.items():
        for n in names:
            by_new[n].add(old)
    renames = {}
    for old, names in votes.items():
        if len(names) != 1:
            continue
        new = next(iter(names))
        if len(by_new[new]) != 1:
            continue
        renames[old] = new
    for old, new in sorted(renames.items()):
        print(f"{old} -> {new}")
    print(f"{len(renames)} renames", file=sys.stderr)
    if args.apply:
        for c in cfgs:
            text = c.read_text()
            for old, new in renames.items():
                text = re.sub(r"^" + re.escape(old) + r" = ", new + " = ", text, flags=re.M)
            c.write_text(text)


if __name__ == "__main__":
    main()
