#!/usr/bin/env python3

###
# Searches for an order of a function's local variable declarations that
# makes the function match better. MWCC assigns registers and stack slots
# partly by declaration order, so near-matches often differ only in that.
#
# The declarations are the lines between the function's opening brace and its
# first statement that hold one declaration each. Each step moves one line to
# another position; a move is kept when the match (as tools/decomp/fn_diff.py
# reports it) rises, and the search stops at a full match or when no single
# move helps. The source file is left with the best order found.
#
# Usage: python tools/permute_decls.py <source> <function name in source> <symbol> [--version RPBE01]
#   e.g. python tools/permute_decls.py src/ds/battle/battle_lib.cpp BattleSystem_CalcMoveDamage \
#            BattleSystem_CalcMoveDamage__FP12BattleSystemP13BattleContextiUlUlUsUcUcUcUc
###

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path
from typing import List, Tuple

ROOT = Path(__file__).resolve().parent.parent
DECL = re.compile(r"^\s+(?:const\s+|static\s+|register\s+|volatile\s+|struct\s+|unsigned\s+|signed\s+)*[A-Za-z_]\w*(?:<[^;()]*>)?[\s\*&]+\**\s*\w+(?:\[[^\]]*\])*\s*(?:=[^;]*)?;\s*(?://.*)?$")


def decl_block(src: str, fn: str) -> Tuple[int, int]:
    """Line range [a, b) of the declarations at the top of fn's body."""
    lines = src.split("\n")
    for i, l in enumerate(lines):
        if re.match(r"^[^\s#/].*\b" + re.escape(fn) + r"\s*\(", l):
            j = i
            while "{" not in lines[j]:
                j += 1
            a = j + 1
            b = a
            while b < len(lines) and (DECL.match(lines[b]) or not lines[b].strip()):
                b += 1
            while b > a and not lines[b - 1].strip():
                b -= 1
            return a, b
    sys.exit(f"{fn}: definition not found")


def score(obj: str, symbol: str, env) -> float:
    r = subprocess.run(["ninja", obj], cwd=ROOT, capture_output=True, text=True)
    if r.returncode != 0:
        return -1.0
    r = subprocess.run(
        [sys.executable, "tools/decomp/fn_diff.py", symbol], cwd=ROOT, capture_output=True, text=True, env=env
    )
    m = re.search(r"match: ([\d.]+)%", r.stdout)
    return float(m.group(1)) if m else -1.0


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("source", type=Path)
    ap.add_argument("function")
    ap.add_argument("symbol")
    ap.add_argument("--version", default="RPBE01")
    args = ap.parse_args()
    env = dict(os.environ, PBR_VERSION=args.version)

    path = ROOT / args.source
    text = path.read_text(encoding="latin-1")
    a, b = decl_block(text, args.function)
    lines = text.split("\n")
    decls: List[str] = [l for l in lines[a:b] if l.strip()]
    edges = subprocess.run(["ninja", "-t", "query", str(path.relative_to(ROOT))], cwd=ROOT, capture_output=True, text=True).stdout
    obj = next(l.strip() for l in edges.split("outputs:")[1].split("\n") if l.strip().endswith(".o"))

    def write(order: List[str]) -> None:
        path.write_text("\n".join(lines[:a] + order + lines[b:]), encoding="latin-1")

    best = score(obj, args.symbol, env)
    print(f"start {best:.2f}% ({len(decls)} declarations)", flush=True)
    order = decls[:]
    improved = True
    while improved and best < 100:
        improved = False
        for i in range(len(order)):
            for j in range(len(order)):
                if i == j:
                    continue
                cand = order[:]
                cand.insert(j, cand.pop(i))
                write(cand)
                s = score(obj, args.symbol, env)
                if s > best:
                    best, order, improved = s, cand, True
                    print(f"{best:.2f}%: moved {cand[j].strip()}", flush=True)
                    break
            if improved or best >= 100:
                break
    write(order)
    score(obj, args.symbol, env)
    print(f"best {best:.2f}%")


if __name__ == "__main__":
    main()
