#!/usr/bin/env python3

###
# Merges a unit into the unit next to it, in every version's config: the
# sections of the merged unit must each adjoin the same section of the other
# unit, which is extended over them. The merged unit is removed from
# splits.txt; remove its object from configure.py and move its code by hand.
#
# Usage: python tools/merge_unit.py <unit> <into unit>
#   e.g. python tools/merge_unit.py src/.unsorted/80272BCC.cpp libs/RVL_SDK/src/os/OSTime.c
###

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LINE = re.compile(r"\t(\S+)(\s+)start:0x(\w+) end:0x(\w+)(.*)$")


def block(lines, unit):
    i = lines.index(unit + ":")
    j = i + 1
    while j < len(lines) and lines[j].startswith("\t"):
        j += 1
    return i, j


def main() -> None:
    unit, into = sys.argv[1:3]
    for cfg in sorted((ROOT / "config").iterdir()):
        path = cfg / "splits.txt"
        if not path.exists():
            continue
        lines = path.read_text().split("\n")
        i, j = block(lines, unit)
        secs = {}
        for l in lines[i + 1 : j]:
            m = LINE.match(l)
            secs[m.group(1)] = (int(m.group(3), 16), int(m.group(4), 16))
        del lines[i : j + 1 if j < len(lines) and lines[j] == "" else j]
        a, b = block(lines, into)
        for k in range(a + 1, b):
            m = LINE.match(lines[k])
            if m and m.group(1) in secs:
                s, e = int(m.group(3), 16), int(m.group(4), 16)
                us, ue = secs.pop(m.group(1))
                if ue == s:
                    s = us
                elif us == e:
                    e = ue
                else:
                    sys.exit(f"{cfg.name}: {m.group(1)} of {unit} does not adjoin {into}")
                lines[k] = f"\t{m.group(1)}{m.group(2)}start:0x{s:08X} end:0x{e:08X}{m.group(5)}"
        if secs:
            sys.exit(f"{cfg.name}: {into} has no {', '.join(secs)} to extend")
        path.write_text("\n".join(lines))
        print(f"{cfg.name}: merged {unit} into {into}")


if __name__ == "__main__":
    main()
