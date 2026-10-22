#!/usr/bin/env python3

###
# Renames placeholder symbols (fn_...) after the reference functions that
# tools/find_functions.py found at their address, when exactly one reference
# name was found there and that name is not already used elsewhere.
#
# Usage: python tools/find_functions.py <version> <objs> > found.tsv
#        python tools/apply_found_names.py <version> found.tsv [--apply]
###

import re
import sys
from collections import defaultdict
from pathlib import Path

version, found = sys.argv[1], Path(sys.argv[2])
apply = "--apply" in sys.argv
by_addr = defaultdict(set)
cur_name = {}
for line in found.read_text().splitlines():
    p = line.split("\t")
    if len(p) < 6:
        continue
    by_addr[int(p[2], 16)].add(p[1])
    cur_name[int(p[2], 16)] = p[4]
cfgs = [Path("config/RPBP01/symbols.txt"), Path("config") / version / "symbols.txt"]
used = set()
for c in cfgs:
    used |= set(re.findall(r"^(\S+) = ", c.read_text(), re.M))
renames = {}
for addr, names in by_addr.items():
    if len(names) != 1:
        continue
    new = next(iter(names))
    old = cur_name[addr]
    if old == new or not old.startswith("fn_") or new in used or new.startswith("fn_"):
        continue
    renames[old] = new
    used.add(new)
for old, new in sorted(renames.items()):
    print(f"{old} -> {new}")
if apply:
    for c in cfgs:
        text = c.read_text()
        for old, new in renames.items():
            text = re.sub(r"^" + re.escape(old) + r" = ", new + " = ", text, flags=re.M)
        c.write_text(text)
print(f"{len(renames)} renames", file=sys.stderr)
