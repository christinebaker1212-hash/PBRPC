#!/usr/bin/env python3

###
# Finds which units can be linked for a version without breaking the match.
#
# Each candidate is linked on its own and the resulting DOL is checked
# against the version's build.sha1. Units that pass are written to
# config/<version>/linked.txt.
#
# Usage:
#   python tools/verify_linked.py --version RPBE01 [candidates.txt]
#
# Without a candidate list, every unit marked Matching or MatchingFor in
# configure.py, and every unit already in linked.txt, is tried.
###

import argparse
import hashlib
import os
import re
import subprocess
import sys
from pathlib import Path


def build(version: str, units: list) -> bool:
    linked = Path("config") / version / "linked.txt"
    linked.write_text("\n".join(units) + "\n")
    subprocess.run(
        [sys.executable, "configure.py", "--version", version],
        check=True,
        stdout=subprocess.DEVNULL,
    )
    subprocess.run(
        ["ninja", f"build/{version}/main.dol"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    expected = (Path("config") / version / "build.sha1").read_text().split()[0]
    dol = Path("build") / version / "main.dol"
    return dol.exists() and hashlib.sha1(dol.read_bytes()).hexdigest() == expected


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--version", default="RPBE01")
    parser.add_argument("candidates", nargs="?", type=Path)
    args = parser.parse_args()
    os.chdir(Path(__file__).resolve().parent.parent)

    if args.candidates:
        candidates = [
            l.strip()
            for l in args.candidates.read_text().splitlines()
            if l.strip() and not l.startswith("#")
        ]
    else:
        candidates = re.findall(
            r'Object\(\s*(?:Matching|MatchingFor\([^)]*\)),\s*"([^"]+)"',
            Path("configure.py").read_text(),
        )
        linked = Path("config") / args.version / "linked.txt"
        if linked.exists():
            for l in linked.read_text().splitlines():
                l = l.strip()
                if l and not l.startswith("#") and l not in candidates:
                    candidates.append(l)

    good = []
    for unit in candidates:
        ok = build(args.version, [unit])
        print(f"{'ok  ' if ok else 'FAIL'} {unit}", flush=True)
        if ok:
            good.append(unit)

    header = f"# Units verified to match {args.version}; written by tools/verify_linked.py.\n"
    ok = build(args.version, good)
    (Path("config") / args.version / "linked.txt").write_text(header + "\n".join(good) + "\n")
    print(f"{len(good)}/{len(candidates)} units link; all together: {'ok' if ok else 'FAIL'}")


if __name__ == "__main__":
    main()
