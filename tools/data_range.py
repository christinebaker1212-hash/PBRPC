#!/usr/bin/env python3

###
# Prints the .data range a unit's code references through jump tables, in the
# version's addresses and in the source (PAL) names, to help split .data.
#
# Usage: python tools/data_range.py <version> <unit object path relative to build/<version>/obj>
###

import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject

version, unit = sys.argv[1], sys.argv[2]
obj = ElfObject(Path("build") / version / "obj" / unit)
syms = {}
for line in (Path("config") / version / "symbols.txt").read_text().splitlines():
    m = re.match(r"(\S+) = (\S+):0x([0-9A-Fa-f]+); // type:\w+(?: size:0x([0-9A-Fa-f]+))?", line)
    if m:
        syms[m.group(1)] = (m.group(2), int(m.group(3), 16), int(m.group(4) or "0", 16))
tables = set()
for relocs in obj.relocs.values():
    for r in relocs:
        name = r.symbol.name
        if name.startswith("jumptable_"):
            base = re.match(r"(jumptable_[0-9A-F]+)", name).group(1)
            if base in syms:
                tables.add(base)
if not tables:
    sys.exit("no jump tables")
lo = min(syms[t][1] for t in tables)
hi = max(syms[t][1] + syms[t][2] for t in tables)
first = min(tables, key=lambda t: syms[t][1])
last = max(tables, key=lambda t: syms[t][1])
print(f"{len(tables)} tables, {version} .data 0x{lo:08X}-0x{hi:08X} ({first} .. {last})")
