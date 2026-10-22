#!/usr/bin/env python3

###
# Names a unit's target functions after the compiled object's functions when
# both list the same number of functions with the same sizes in order (for
# imported library code whose symbols.txt still has placeholder names).
#
# Usage: python tools/name_from_objects.py <version> <unit>... [--apply]
#   <unit> as the object path under build/<version>/obj, without .o
#   (e.g. libs/RVL_SDK/src/bte/btm_sec)
# Renames apply to config/RPBP01/symbols.txt and config/<version>/symbols.txt
# (the source and target configs share placeholder names).
###

import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject


def functions(path: Path):
    o = ElfObject(path)
    fns = [s for s in o.symbols if s.type == 2 and o.defined(s) and o.section_name(s.shndx) == ".text"]
    return [(s.name, s.size) for s in sorted(fns, key=lambda s: s.value)]


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("version")
    ap.add_argument("units", nargs="+")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args()
    renames = {}
    for unit in args.units:
        base = Path("build") / args.version / re.sub(r"^libs/[^/]+/", "", unit + ".o")
        target = Path("build") / args.version / "obj" / (unit + ".o")
        if not base.exists() or not target.exists():
            print(f"{unit}: missing objects")
            continue
        b, t = functions(base), functions(target)
        sizes_b = [s for _, s in b]
        sizes_t = [s for _, s in t]
        if sizes_b != sizes_t:
            # Same sizes with a few extra source functions (not in retail): align greedily.
            pairs = []
            j = 0
            for name, size in t:
                while j < len(b) and b[j][1] != size:
                    j += 1
                if j == len(b):
                    pairs = None
                    break
                pairs.append(((name, size), b[j]))
                j += 1
            if pairs is None:
                print(f"{unit}: {len(t)} target vs {len(b)} source functions, sizes differ")
                continue
        else:
            pairs = list(zip(t, b))
        n = 0
        for (tn, _), (bn, _) in pairs:
            if tn != bn:
                renames[tn] = bn
                n += 1
        print(f"{unit}: {n} renames")
    if args.apply and renames:
        for cfg in {Path("config/RPBP01/symbols.txt"), Path("config") / args.version / "symbols.txt"}:
            text = cfg.read_text()
            for old, new in renames.items():
                text = re.sub(r"^" + re.escape(old) + r" = ", new + " = ", text, flags=re.M)
            cfg.write_text(text)
    print(f"{len(renames)} renames total")


if __name__ == "__main__":
    main()
