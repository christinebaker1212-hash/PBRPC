#!/usr/bin/env python3

###
# Infers how many integer and float arguments every function takes, from the
# split assembly, and writes them as C prototypes for m2c's --context (used by
# tools/automatch.py). m2c drops arguments a caller passes through unchanged
# (still in r4-r10 from its own caller) unless it knows the callee takes them.
#
# A function's arguments are the argument registers (r3-r10, f1-f8) it reads
# before writing them, in instruction order, counting a call as reading the
# callee's arguments; this is iterated over the call graph until nothing
# changes. Branches are ignored, so a register read on any path counts.
#
# Usage: python tools/arity.py [--version RPBE01]
#   writes build/<version>/m2c_context.c
###

import argparse
import re
from pathlib import Path
from typing import Dict, List, Set, Tuple

ROOT = Path(__file__).resolve().parent.parent
TYPEDEFS = """typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
"""
INSN = re.compile(r"^/\* [0-9A-F]+ [0-9A-F]+\s+(?:[0-9A-F]{2} ){4}\*/\t(\S+)\s*(.*)$")
GPR_ARGS = [f"r{i}" for i in range(3, 11)]
FPR_ARGS = [f"f{i}" for i in range(1, 9)]
VOLATILE = {f"r{i}" for i in range(0, 13)} | {f"f{i}" for i in range(0, 14)}
READ_ALL = re.compile(r"^(st|cmp|tw|mt|dcb|icb|psq_st)")
READ_WRITE_FIRST = {"rlwimi", "rlwimi."}


def parse(asm_dir: Path) -> Dict[str, List[Tuple[str, List[str], str]]]:
    fns = {}
    for s in sorted(asm_dir.rglob("*.s")):
        for m in re.finditer(r"^\.fn (\S+),.*?^\.endfn \1$", s.read_text(), re.S | re.M):
            body = []
            for line in m.group(0).split("\n"):
                im = INSN.match(line)
                if not im:
                    continue
                ops = im.group(2).split("#")[0]
                regs = re.findall(r"\b([rf]\d+)\b", ops)
                target = re.match(r"^([A-Za-z_][\w@$<>\\.]*)", ops.strip())
                body.append((im.group(1), regs, target.group(1) if target else ""))
            fns[m.group(1)] = body
    return fns


def live_in(body, arity: Dict[str, Set[str]]) -> Set[str]:
    written: Set[str] = set()
    reads: Set[str] = set()

    def read(r):
        if r not in written:
            reads.add(r)

    for op, regs, target in body:
        if op in ("bl", "b") and target in arity:
            for r in arity[target]:
                read(r)
            if op == "bl":
                written |= VOLATILE
            continue
        if op.startswith("b"):
            continue
        if READ_ALL.match(op):
            for r in regs:
                read(r)
            continue
        if not regs:
            continue
        if op in READ_WRITE_FIRST:
            read(regs[0])
        for r in regs[1:]:
            read(r)
        written.add(regs[0])
    return reads & set(GPR_ARGS + FPR_ARGS)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--version", default="RPBE01")
    args = ap.parse_args()
    fns = parse(ROOT / "build" / args.version / "asm")
    arity: Dict[str, Set[str]] = {n: set() for n in fns}
    for _ in range(20):
        changed = False
        for n, body in fns.items():
            r = live_in(body, arity)
            if r != arity[n]:
                arity[n] = r
                changed = True
        if not changed:
            break
    # Callers also show unused parameters: argument registers written since
    # the previous call or label are passed to the next call.
    sites: Dict[str, int] = {}
    passed: Dict[Tuple[str, str], int] = {}
    for body in fns.values():
        pending: Set[str] = set()
        for op, regs, target in body:
            if op == "bl" and target in arity:
                sites[target] = sites.get(target, 0) + 1
                for r in pending:
                    passed[target, r] = passed.get((target, r), 0) + 1
                pending = set()
            elif op.startswith("b"):
                pending = set()
            elif regs and not READ_ALL.match(op) and regs[0] in GPR_ARGS + FPR_ARGS:
                pending.add(regs[0])
    # ... when most call sites agree.
    for (target, r), n in passed.items():
        if 2 * n > sites[target]:
            arity[target].add(r)
    lines = []
    for n in sorted(fns):
        if not re.fullmatch(r"[A-Za-z_]\w*", n):
            continue
        a = arity[n]
        ng = max([GPR_ARGS.index(r) + 1 for r in a if r in GPR_ARGS], default=0)
        nf = max([FPR_ARGS.index(r) + 1 for r in a if r in FPR_ARGS], default=0)
        params = ["s32"] * ng + ["f32"] * nf
        if ng == len(GPR_ARGS) and nf == len(FPR_ARGS):
            params = ["s32", "..."]  # a variadic prologue saves every argument register
        lines.append(f"s32 {n}({', '.join(params) or 'void'});")
    out = ROOT / "build" / args.version / "m2c_context.c"
    out.write_text(TYPEDEFS + "\n".join(lines) + "\n")
    print(f"{len(lines)} prototypes -> {out}")


if __name__ == "__main__":
    main()
