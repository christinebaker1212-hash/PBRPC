#!/usr/bin/env python3

###
# Replaces function definitions in a source file with the definitions of the
# same functions from a reference source file (e.g. a CC0 decomp of another
# game built with the same SDK). Functions missing from the target file are
# appended. The result still has to be compiled and diffed.
#
# Usage: python tools/graft.py <file> <reference file> <function>...
###

import re
import sys
from pathlib import Path
from typing import Optional, Tuple


def find_def(src: str, name: str) -> Optional[Tuple[int, int]]:
    """Span of the definition of name: from the start of its signature line
    (including comments directly above) to its closing brace."""
    # A definition starts at the beginning of a line; an indented match is a
    # call inside another function's body
    for m in re.finditer(r"^(?![ \t])[^\n;{}#]*?\b" + re.escape(name) + r"\s*\(", src, re.M):
        # The signature ends at the first '{' or ';' after the parameter list.
        depth, i = 0, m.end() - 1
        while i < len(src):
            c = src[i]
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        j = i + 1
        while j < len(src) and src[j] not in "{;":
            j += 1
        if j >= len(src) or src[j] == ";":
            continue
        # Between the parameter list and the body: only `const` or a
        # constructor's initializer list
        if not re.fullmatch(r"\s*(?:const\s*)?(?::[^{;]*)?", src[i + 1 : j]):
            continue
        depth = 0
        k = j
        while k < len(src):
            if src[k] == "{":
                depth += 1
            elif src[k] == "}":
                depth -= 1
                if depth == 0:
                    break
            k += 1
        start = m.start()
        # Keep "static"/"inline" lines and asm prefixes that sit on the previous line.
        prev = src.rfind("\n", 0, max(start - 1, 0))
        line = src[prev + 1 : start].strip()
        if line and not line.endswith((";", "}", "{")) and not line.startswith(("#", "//", "/*")):
            start = prev + 1
        return start, k + 1
    return None


def main() -> None:
    path, ref = Path(sys.argv[1]), Path(sys.argv[2])
    src = path.read_text(encoding="latin-1")
    rsrc = ref.read_text(encoding="latin-1")
    for name in sys.argv[3:]:
        r = find_def(rsrc, name)
        if r is None:
            print(f"{name}: not in {ref}")
            continue
        body = rsrc[r[0] : r[1]]
        t = find_def(src, name)
        if t is None:
            src = src.rstrip("\n") + "\n\n" + body + "\n"
            print(f"{name}: appended")
        else:
            src = src[: t[0]] + body + src[t[1] :]
            print(f"{name}: replaced")
    path.write_text(src, encoding="latin-1")


if __name__ == "__main__":
    main()
