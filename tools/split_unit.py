#!/usr/bin/env python3

###
# Splits a unit's .text at a symbol, in config/RPBP01 and every other
# version's config: the unit keeps the code before the symbol, and a new unit
# gets the code from the symbol to the old end. The symbol's address is looked
# up in each version's symbols.txt.
#
# Usage: python tools/split_unit.py <unit> <symbol> <new unit>
#   e.g. python tools/split_unit.py libs/RVL_SDK/src/exi/EXICommon.c CompleteTransfer libs/RVL_SDK/src/si/SIBios.c
###

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main() -> None:
    unit, symbol, new_unit = sys.argv[1:4]
    for cfg in sorted((ROOT / "config").iterdir()):
        splits = cfg / "splits.txt"
        if not splits.exists():
            continue
        m = re.search(r"^" + re.escape(symbol) + r" = \.text:0x([0-9A-Fa-f]+);", (cfg / "symbols.txt").read_text(), re.M)
        if m is None:
            sys.exit(f"{cfg.name}: {symbol} not found")
        addr = int(m.group(1), 16)
        lines = splits.read_text().split("\n")
        i = lines.index(unit + ":")
        j = i + 1
        while j < len(lines) and lines[j].startswith("\t"):
            if lines[j].split()[0] == ".text":
                t = re.match(r"\t\.text(\s+)start:0x(\w+) end:0x(\w+)", lines[j])
                start, end = int(t.group(2), 16), int(t.group(3), 16)
                if not start < addr < end:
                    sys.exit(f"{cfg.name}: {symbol} 0x{addr:08X} not inside 0x{start:08X}-0x{end:08X}")
                lines[j] = f"\t.text{t.group(1)}start:0x{start:08X} end:0x{addr:08X}"
                new = [f"{new_unit}:", f"\t.text{t.group(1)}start:0x{addr:08X} end:0x{end:08X}", ""]
            j += 1
        k = j + 1 if j < len(lines) and lines[j] == "" else j
        lines[k:k] = new
        splits.write_text("\n".join(lines))
        print(f"{cfg.name}: {unit} | {new_unit} at 0x{addr:08X}")


if __name__ == "__main__":
    main()
