#!/usr/bin/env python3

###
# First-pass matcher for unmatched functions of a unit.
#
# Each function's target assembly is decompiled with m2c, compiled on its own
# with the unit's compiler flags, and compared with the target object byte for
# byte (relocations compared by symbol name). Functions that match are written
# to <out_dir>/<function>.cpp with the declarations they need; --apply appends
# them to the unit's source file.
#
# The output is scaffolding: raw types from m2c, to be rewritten following
# docs/STYLE.md like the rest of src/.unsorted.
#
# Usage:
#   python tools/automatch.py <unit> [--max-size 0x200] [--apply]
#   <unit> as in report.json, e.g. src/.unsorted/8031C124
#
# Requires m2c (https://github.com/matt-kempster/m2c); pass --m2c <path to m2c.py>.
# Run tools/arity.py first to give m2c the prototypes of all functions.
###

import argparse
import json
import os
import re
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path
from typing import Dict, List, Optional, Tuple

sys.path.insert(0, str(Path(__file__).resolve().parent))
from elf32 import ElfObject

ROOT = Path(__file__).resolve().parent.parent


def ninja_edges(version: str) -> Dict[str, Dict[str, str]]:
    text = (ROOT / "build.ninja").read_text().replace("$\n", "")
    edges: Dict[str, Dict[str, str]] = {}
    cur = None
    for line in text.splitlines():
        if line.startswith("build "):
            out = line[6:].split(":", 1)[0].strip()
            cur = edges.setdefault(out, {"rule": line.split(":", 1)[1].split()[0]})
        elif cur is not None and line.startswith("  ") and "=" in line:
            k, v = line.strip().split("=", 1)
            cur[k.strip()] = " ".join(v.split())
        elif not line.startswith(" "):
            cur = None
    return edges


class Obj:
    def __init__(self, path: Path) -> None:
        self.elf = ElfObject(path)
        self.data = path.read_bytes()
        import struct

        shoff = struct.unpack_from(">I", self.data, 0x20)[0]
        shentsize, shnum = struct.unpack_from(">HH", self.data, 0x2E)
        self.headers = [
            struct.unpack_from(">10I", self.data, shoff + i * shentsize) for i in range(shnum)
        ]

    def function(self, name: str) -> Optional[Tuple[bytes, List[Tuple[int, int, str]]]]:
        for s in self.elf.symbols:
            if s.name == name and s.type == 2 and self.elf.defined(s):
                h = self.headers[s.shndx]
                code = self.data[h[4] + s.value : h[4] + s.value + s.size]
                relocs = [
                    (r.offset - s.value, r.type, reloc_name(self.elf, r))
                    for r in self.elf.relocs.get(s.shndx, [])
                    if s.value <= r.offset < s.value + s.size
                ]
                return code, relocs
        return None


def reloc_name(elf: ElfObject, r) -> str:
    name = r.symbol.name
    if not name or name.startswith("@") or name.startswith(".") or r.symbol.type == 3:
        # Section or anonymous local symbol: identify by section name + addend.
        return f"<{elf.section_name(r.symbol.shndx)}+{r.addend}>"
    return name


def mask(code: bytes, relocs: List[Tuple[int, int, str]]) -> bytes:
    b = bytearray(code)
    for off, typ, _ in relocs:
        if typ in (4, 5, 6, 109):  # ADDR16_LO/HI/HA, EMB_SDA21: low half
            b[off + 2 : off + 4] = b"\0\0"
            if typ == 109:
                b[off + 1] &= 0xE0
        elif typ == 10:  # REL24
            b[off] &= 0xFC
            b[off + 1 : off + 3] = b"\0\0"
            b[off + 3] &= 0x03
        elif typ == 11:  # REL14
            b[off + 2 : off + 4] = bytes([0, b[off + 3] & 0x03])
        elif typ == 1:
            b[off : off + 4] = b"\0\0\0\0"
    return bytes(b)


def same(target, base) -> bool:
    tcode, trel = target
    bcode, brel = base
    if len(tcode) != len(bcode) or len(trel) != len(brel):
        return False
    if mask(tcode, trel) != mask(bcode, brel):
        return False
    for (to, tt, tn), (bo, bt, bn) in zip(trel, brel):
        if to != bo or tt != bt:
            return False
        # Local data (string pools, jump tables) is named differently on each
        # side; only global names must agree.
        if not (tn.startswith("<") or bn.startswith("<") or tn.startswith("jumptable_") or tn.startswith("@")):
            if tn != bn:
                return False
    return True


def similarity(target, base) -> float:
    """Share of instructions that agree (relocated words masked), aligned by difflib."""
    import difflib

    tw = mask(*target)
    bw = mask(*base)
    tw = [tw[i : i + 4] for i in range(0, len(tw), 4)]
    bw = [bw[i : i + 4] for i in range(0, len(bw), 4)]
    return difflib.SequenceMatcher(None, tw, bw, autojunk=False).ratio()


def extract_fn(asm_text: str, fn: str, tmp: Path) -> Optional[Path]:
    m = re.search(r"^\.fn " + re.escape(fn) + r",.*?^\.endfn " + re.escape(fn) + r"$", asm_text, re.S | re.M)
    if not m:
        return None
    path = tmp / "fn.s"
    path.write_text(".text\n" + m.group(0) + "\n")
    return path


def expand_macros(src: str, known: bool = False) -> Optional[str]:
    """Rewrites m2c's valid-syntax macros as plain C, so the output needs no
    header. Returns None if the code uses a macro with no plain equivalent."""
    src = re.sub(r"\bM2C_UNK(8|16|32|64)\b", r"s\1", src)
    # A symbol of unknown type is addressed in bytes (&sym + 0x10).
    src = re.sub(r"^extern M2C_UNK (\w+);", r"extern u8 \1;", src, flags=re.M)
    src = re.sub(r"\bM2C_UNK\b", "s32", src)

    def expand(name: str, fmt) -> None:
        nonlocal src
        while True:
            i = src.find(name + "(")
            if i < 0:
                return
            j = i + len(name) + 1
            depth, args, start = 1, [], j
            while depth:
                c = src[j]
                if c in "([":
                    depth += 1
                elif c in ")]":
                    depth -= 1
                elif c == "," and depth == 1:
                    args.append(src[start:j].strip())
                    start = j + 1
                j += 1
            args.append(src[start : j - 1].strip())
            src = src[:i] + fmt(*args) + src[j:]

    expand("M2C_FIELD", lambda e, t, o: f"(*({t})((u8 *)({e}) + ({o})))")
    expand("M2C_BITWISE", lambda t, e: f"(({t})({e}))")
    if "M2C_" in src:
        return None
    # C++ has no arithmetic on void pointers; m2c means byte offsets.
    src = re.sub(r"\bvoid \*", "u8 *", src)
    # Mangled names ending in "e" are variadic.
    src = re.sub(r"^(\S[^(\n]*\b\w+__F\w*e)\([^;\n]*\);", r"\1(...);", src, flags=re.M)
    if known:
        src = known_prototypes(src)
    return prototype_unknown_calls(src)


# Library functions m2c often guesses the wrong number of arguments for.
KNOWN = {
    "memset": ("u8 *memset(u8 *, s32, u32);", 3),
    "memcpy": ("u8 *memcpy(u8 *, const u8 *, u32);", 3),
    "memmove": ("u8 *memmove(u8 *, const u8 *, u32);", 3),
    "memcmp": ("s32 memcmp(const u8 *, const u8 *, u32);", 3),
    "strlen": ("u32 strlen(const s8 *);", 1),
    "strcmp": ("s32 strcmp(const s8 *, const s8 *);", 2),
    "strncmp": ("s32 strncmp(const s8 *, const s8 *, u32);", 3),
    "strcpy": ("s8 *strcpy(s8 *, const s8 *);", 2),
    "strncpy": ("s8 *strncpy(s8 *, const s8 *, u32);", 3),
    "strcat": ("s8 *strcat(s8 *, const s8 *);", 2),
    "OSReport": ("void OSReport(const s8 *, ...);", None),
    "OSPanic": ("void OSPanic(const s8 *, s32, const s8 *, ...);", None),
    "sprintf": ("s32 sprintf(s8 *, const s8 *, ...);", None),
    "snprintf": ("s32 snprintf(s8 *, u32, const s8 *, ...);", None),
    "printf": ("s32 printf(const s8 *, ...);", None),
    "OSDisableInterrupts": ("s32 OSDisableInterrupts(void);", 0),
    "OSEnableInterrupts": ("s32 OSEnableInterrupts(void);", 0),
    "OSRestoreInterrupts": ("s32 OSRestoreInterrupts(s32);", 1),
    "OSLockMutex": ("void OSLockMutex(u8 *);", 1),
    "OSUnlockMutex": ("void OSUnlockMutex(u8 *);", 1),
    "DCFlushRange": ("void DCFlushRange(u8 *, u32);", 2),
    "DCStoreRange": ("void DCStoreRange(u8 *, u32);", 2),
    "DCInvalidateRange": ("void DCInvalidateRange(u8 *, u32);", 2),
}


def known_prototypes(src: str) -> str:
    """Declares known library functions with their real prototypes, and drops
    the extra arguments m2c passes them (live registers it could not rule out)."""
    for name, (proto, nargs) in KNOWN.items():
        dm = re.search(r"^[^\n]*\b" + name + r"\([^;\n]*\);[^\n]*$", src, re.M)
        if dm is None:
            continue
        src = src[: dm.start()] + proto + src[dm.end() :]
        if nargs is None:
            continue
        pos = 0
        while True:
            c = re.compile(r"\b" + name + r"\(").search(src, pos)
            if c is None:
                break
            if src.startswith(proto, src.rfind("\n", 0, c.start()) + 1):
                pos = c.end()
                continue
            args, end = split_args(src, c.end() - 1)
            new = name + "(" + ", ".join(args[:nargs]) + ")"
            src = src[: c.start()] + new + src[end + 1 :]
            pos = c.start() + len(new)
    return src


def split_args(text: str, start: int) -> Tuple[List[str], int]:
    """Arguments of the call whose '(' is at text[start]; returns (args, end)."""
    depth, args, cur, i = 0, [], start + 1, start
    while True:
        c = text[i]
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
            if depth == 0:
                a = text[cur:i].strip()
                if a:
                    args.append(a)
                return args, i
        elif c == "," and depth == 1:
            args.append(text[cur:i].strip())
            cur = i + 1
        i += 1


def prototype_unknown_calls(src: str) -> str:
    """m2c declares callees it knows nothing about as 'T f();', which C++ reads
    as taking no arguments. Give them one s32 (or float) parameter per argument
    and cast integer and pointer arguments to s32, which costs no code."""
    decl = r"^(?![ \t])(?!.*=)(?!.*\.\.\.)(.*?\b{})\(\);[ \t]*(?:/\*.*\*/)?[ \t]*$"
    float_vars = {v: t for t, v in re.findall(r"\b(f32|f64)\s+(\w+)\s*[;,=)]", src)}
    names = [m.group(1).split()[-1].lstrip("*") for m in re.finditer(decl.format(r"\w+"), src, re.M)]
    for name in names:
        dm = re.search(decl.format(re.escape(name)), src, re.M)
        if dm is None:
            continue
        calls = [c for c in re.finditer(r"\b" + re.escape(name) + r"\(", src) if not (dm.start() <= c.start() < dm.end())]
        sigs = set()
        parsed = []
        for c in calls:
            args, end = split_args(src, c.end() - 1)
            kinds = tuple(
                float_vars.get(a) or ("f32" if re.fullmatch(r"-?\d+\.\d*f", a) else "s32") for a in args
            )
            sigs.add(kinds)
            parsed.append((c.end() - 1, end, args, kinds))
        if len(sigs) > 1:
            continue
        kinds = next(iter(sigs)) if sigs else ()
        for open_, close, args, k in sorted(parsed, reverse=True):
            new_args = ", ".join(x if t != "s32" else f"(s32)({x})" for x, t in zip(args, k))
            src = src[: open_ + 1] + new_args + src[close:]
        dm = re.search(decl.format(re.escape(name)), src, re.M)
        src = src[: dm.start()] + dm.group(1) + "(" + (", ".join(kinds) or "void") + ");" + src[dm.end() :]
    return src


CONTEXT: Dict[str, str] = {}
CONTEXT_FILE = Path()


def load_context(path: Path) -> None:
    """Prototypes from tools/arity.py, given to m2c and declared in its output."""
    for line in path.read_text().splitlines():
        m = re.match(r"^\w[\w \*]*?\b(\w+)\(.*\);$", line)
        if m:
            CONTEXT[m.group(1)] = line


def declare_context(src: str) -> str:
    """m2c leaves out declarations of functions the context has."""
    # Declared or defined here already (m2c infers the function's own
    # signature, which the context's guess would contradict)
    have = set(re.findall(r"^\S[^\n(]*\b(\w+)\s*\([^;{]*\)\s*[;{]", src, re.M))
    used = set(re.findall(r"\b(\w+)\(", src))
    extra = [CONTEXT[n] for n in sorted(used) if n in CONTEXT and n not in have]
    return "".join(e + "\n" for e in extra) + src


_CONTEXT_LINES: List[str] = []


def CONTEXT_TEXT() -> List[str]:
    if not _CONTEXT_LINES:
        _CONTEXT_LINES.extend(CONTEXT_FILE.read_text().splitlines())
    return _CONTEXT_LINES


def fill_parameters(src: str, fn: str) -> str:
    """m2c names parameters after their registers (arg2 is r5) and leaves out
    the ones the function never reads; put them back, up to the arity the
    context gives, so the others stay in their registers."""
    m = re.search(r"^([^\n(]*\b" + re.escape(fn) + r")\(([^)]*)\) \{", src, re.M)
    if m is None:
        return src
    params = [p.strip() for p in m.group(2).split(",")] if m.group(2).strip() not in ("", "void") else []
    # m2c takes the register save area set up through r11 (_savegpr) for a
    # stack argument; one the body never reads is not a parameter
    body = src[m.end() :]
    params = [p for p in params if not (re.search(r"\barg_sp\w*$", p) and not re.search(r"\b" + p.split()[-1] + r"\b", body))]
    by_index = {}
    for p in params:
        pm = re.search(r"\barg(\d+)$", p)
        if pm is None:
            return src  # stack or float arguments: leave as m2c wrote them
        by_index[int(pm.group(1))] = p
    arity = 0
    ctx = CONTEXT.get(fn)
    if ctx:
        cm = re.search(r"\(([^)]*)\)", ctx)
        if cm and cm.group(1).strip() not in ("", "void"):
            arity = len(cm.group(1).split(","))
    count = max([arity] + [i + 1 for i in by_index])
    if count == len(params) and m.group(2).count(",") + 1 == len(params):
        return src
    full = [by_index.get(i, f"s32 arg{i}") for i in range(count)]
    return src[: m.start(2)] + ", ".join(full) + src[m.end(2) :]


def m2c(m2c_path: Path, asm: Path, fn: str, use_context: bool = True) -> List[str]:
    """m2c's output as plain C, as is and with known library prototypes."""
    ctx = []
    if CONTEXT and use_context:
        # The context's guess at fn's own prototype types every parameter as
        # s32, which keeps m2c from seeing pointers; let m2c infer fn's own.
        own = asm.parent / "context.c"
        # Only what the function refers to: m2c parses the whole context on
        # every run, which took most of the time.
        used = set(re.findall(r"[A-Za-z_][\w@$]*", asm.read_text()))
        keep = []
        for l in CONTEXT_TEXT():
            m = re.search(r"\b(\w+)\s*(?:\(|\[|;)", l)
            if l.startswith("typedef"):
                keep.append(l)
            elif m and m.group(1) in used and m.group(1) != fn:
                keep.append(l)
        own.write_text("".join(l + "\n" for l in keep))
        ctx = ["--context", str(own)]
    try:
        out = subprocess.run(
            [sys.executable, str(m2c_path), "-t", "ppc-mwcc-c", "--valid-syntax", *ctx, "-f", fn, str(asm)],
            capture_output=True,
            text=True,
            timeout=60,
        )
    except subprocess.TimeoutExpired:
        return []
    if out.returncode != 0 or "M2C_ERROR" in out.stdout or "/* unknown instruction" in out.stdout:
        return []
    variants = []
    text = declare_context(out.stdout) if CONTEXT and use_context else out.stdout
    text = fill_parameters(text, fn)
    text = re.sub(r"\bCLZ\(", "__cntlzw(", text)
    # A function m2c only takes the address of is declared as data, which
    # MWCC would address through the small data area
    text = re.sub(r"^extern [\w ]+?\*? ?\b(fn_[0-9A-F]{8})\s*;", r"void \1(void);", text, flags=re.M)
    for known in (False, True):
        v = expand_macros(text, known)
        if v is not None and v not in variants:
            variants.append(v)
    # m2c types byte and halfword stores as signed, so constants like 0xFF
    # compile to li -1; try the stores as unsigned too.
    for v in list(variants):
        u = re.sub(r"\(\*\((s8|s16) \*\)(\([^;=]*\)\)) = (0x[0-9A-F]+|\d+);", lambda m: f"(*(u{m.group(1)[1:]} *){m.group(2)} = {m.group(3)};", v)
        u = s64_stores(u)
        if u not in variants:
            variants.append(u)
    # MWCC narrows a small-integer local after every change; source that kept
    # the value in an int narrows it only where it is stored or returned.
    for v in list(variants[:2]):
        w = re.sub(r"^(\s+)(?:u8|s8|u16|s16) ((?:var|temp)_\w+);", r"\1s32 \2;", v, flags=re.M)
        if w not in variants:
            variants.append(w)
    # MWCC assigns registers partly by declaration order; m2c sorts locals by
    # name, so the other order is worth a try.
    for v in [variants[0], variants[-1]] if variants else []:
        r = reverse_locals(v)
        if r not in variants:
            variants.append(r)
    return variants


def reverse_locals(src: str) -> str:
    """The function's leading local declarations in reverse order."""
    lines = src.split("\n")
    for i, l in enumerate(lines):
        if re.match(r"^[^ /].*\)\s*\{\s*$", l):
            j = i + 1
            while j < len(lines) and re.match(r"^\s+[\w ]+[\s\*]+\w+(?:\[[^\]]*\])?;$", lines[j]):
                j += 1
            lines[i + 1 : j] = lines[i + 1 : j][::-1]
            break
    return "\n".join(lines)


def s64_stores(src: str) -> str:
    """Two word stores of zero, low word first, are one s64 store."""

    def repl(m):
        lo, hi = int(m.group(3), 0), int(m.group(5), 0)
        if m.group(2) != m.group(4) or lo != hi + 4:
            return m.group(0)
        return f"{m.group(1)}(*(s64 *)({m.group(2)} + ({m.group(5)}))) = 0;"

    return re.sub(
        r"^(\s*)\(\*\(s32 \*\)\((\(u8 \*\)[^;]*?) \+ \((0x[0-9A-F]+|\d+)\)\)\) = 0;\n\s*\(\*\(s32 \*\)\(((?:\(u8 \*\))[^;]*?) \+ \((0x[0-9A-F]+|\d+)\)\)\) = 0;",
        repl,
        src,
        flags=re.M,
    )


PREAMBLE = """typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed long s32;
typedef unsigned long u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
#define NULL 0
"""


LAST_SOURCE = ""


def cast_call_arguments(src: str, name: str) -> Optional[str]:
    """Casts the arguments of calls to name to the types of its prototype
    (the one in src, or a known library one)."""
    p = re.search(r"^[^\n(]*\b" + re.escape(name) + r"\(([^)]*)\);", src, re.M) or re.search(
        r"\b" + re.escape(name) + r"\(([^)]*)\);", KNOWN.get(name, "")
    )
    if p is None:
        return None
    params = [param_type(x) for x in p.group(1).split(",")] if p.group(1).strip() not in ("", "void") else []
    if "..." in p.group(1) or "" in params:
        return None
    out, pos, changed = [], 0, False
    for c in re.finditer(r"\b" + re.escape(name) + r"\(", src):
        if c.start() < pos:
            continue
        line_start = src.rfind("\n", 0, c.start()) + 1
        if re.match(r"^[A-Za-z_]", src[line_start:]):
            continue
        args, end = split_args(src, c.end() - 1)
        if len(args) != len(params):
            continue
        new = name + "(" + ", ".join(a if a.startswith(f"({t})") else f"({t})({a})" for t, a in zip(params, args)) + ")"
        changed |= new != src[c.start() : end + 1]
        out.append(src[pos : c.start()] + new)
        pos = end + 1
    return "".join(out) + src[pos:] if changed else None


def cast_conversion(src: str, err: str, first_line: int) -> Optional[str]:
    """Fixes an "illegal implicit conversion" (C++ does not convert between
    integers and pointers as C does) by casting the assigned or returned
    value to the type the compiler wanted."""
    u = re.search(r"\(10140\) undefined identifier '(sp[0-9A-F]+(?:_\w+)?)'", err)
    if u:
        # a stack temporary m2c used without declaring it
        d = re.search(r"^[A-Za-z_][^\n;]*\)\s*\{\n", src, re.M)
        if d is None:
            return None
        return src[: d.end()] + f"    s32 {u.group(1)};\n" + src[d.end() :]
    c = re.search(r"\(10248\) function call '(\w+)\(", err)
    if c:
        return cast_call_arguments(src, c.group(1))
    m = re.search(r"^#\s+(\d+): .*\n#\s+Error:.*\n#\s+\(10209\) illegal implicit conversion from '[^']*' to\s*\n?#?\s*'([^']+)'", err, re.M)
    if m is None:
        return None
    lines = src.split("\n")
    i = int(m.group(1)) - first_line
    if not 0 <= i < len(lines):
        return None
    t, l = m.group(2), lines[i]
    a = re.match(r"^(\s*)(.+?) = (.+);\s*$", l)
    r = re.match(r"^(\s*)return (.+);\s*$", l)
    if a and not a.group(3).startswith(f"({t})"):
        lines[i] = f"{a.group(1)}{a.group(2)} = ({t})({a.group(3)});"
    elif r and not r.group(2).startswith(f"({t})"):
        lines[i] = f"{r.group(1)}return ({t})({r.group(2)});"
    else:
        return None
    return "\n".join(lines)


def compile_cpp(edge: Dict[str, str], src: str, m2c_dir: Path, tmp: Path) -> Optional[Path]:
    """Compiles src; LAST_SOURCE is src with the casts it needed."""
    global LAST_SOURCE
    first_line = PREAMBLE.count("\n") + 2
    for _ in range(12):
        cpp = tmp / "scratch.cpp"
        cpp.write_text(PREAMBLE + f'extern "C" {{\n{src}\n}}\n', encoding="latin-1")
        obj = tmp / "scratch.o"
        if obj.exists():
            obj.unlink()
        cflags = shlex.split(edge["cflags"])
        cmd = [
            str(ROOT / "build/tools/wibo"),
            str(ROOT / "build/compilers" / edge["mw_version"] / "mwcceppc.exe"),
            *cflags,
            "-c",
            str(cpp),
            "-o",
            str(obj),
        ]
        r = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
        if r.returncode == 0 and obj.exists():
            LAST_SOURCE = src
            return obj
        fixed = cast_conversion(src, r.stdout + r.stderr, first_line)
        if fixed is None:
            break
        src = fixed
    dump = os.environ.get("AUTOMATCH_DUMP")
    if dump:
        # Keep failing sources and compiler output, to improve the rewriting.
        d = Path(dump)
        d.mkdir(parents=True, exist_ok=True)
        n = len(list(d.glob("*.cpp")))
        (d / f"{n:04}.cpp").write_text(cpp.read_text(encoding="latin-1"), encoding="latin-1")
        (d / f"{n:04}.err").write_text(r.stdout + r.stderr)
    return None


DECL_NAME = re.compile(r"\b(\w+)\s*(?:\[[^\]]*\])?\s*(?:\(|;)")


def split_output(src: str) -> Tuple[List[str], str]:
    """m2c output -> (declaration lines, function definition)."""
    lines = src.strip("\n").split("\n")
    i = 0
    decls = []
    while i < len(lines) and not re.match(r"^[^ /].*\)\s*\{\s*$", lines[i]):
        if lines[i].strip():
            decls.append(re.sub(r"\s*/\*.*\*/\s*$", "", lines[i]).strip())
        i += 1
    return decls, "\n".join(lines[i:])


def decl_name(decl: str) -> Optional[str]:
    m = re.search(r"\b(\w+)\s*\(", decl)
    if m and not decl.startswith("extern"):
        return m.group(1)
    names = re.findall(r"\b(\w+)\s*(?:\[[^\]]*\])*\s*;", decl)
    return names[-1] if names else None


def build_unit(edge_inputs: List[str], obj: str) -> bool:
    r = subprocess.run(["ninja", obj], capture_output=True, text=True, cwd=ROOT)
    if r.returncode != 0 and os.environ.get("AUTOMATCH_DEBUG"):
        err = [l for l in r.stdout.splitlines() if l.startswith("#")]
        print("    apply failed:", " | ".join(l.strip("# ") for l in err[2:7]), flush=True)
    return r.returncode == 0


def param_type(param: str) -> str:
    """The type of a parameter declaration ("" if it has none to cast to)."""
    param = param.strip()
    m = re.match(r"^(.*[\s\*&])\s*(\w+)$", param)
    if m and m.group(1).strip() and m.group(1).strip() not in ("const", "unsigned", "signed"):
        return m.group(1).strip()
    if re.fullmatch(r"[\w\s\*&]+", param) and re.search(r"\b(s8|u8|s16|u16|s32|u32|s64|u64|f32|f64|int|char|short|long|float|double|void|bool|BOOL)\b|\*", param):
        return param
    return ""


def adopt_signature(body: str, protos: Dict[str, List[str]], rets: Dict[str, str]) -> str:
    """When the unit already declares the function m2c defined, with other
    types, the definition takes the unit's signature (C linkage cannot
    overload) and converts its parameters and results inside, which compiles
    to the same code."""
    m = re.match(r"^([A-Za-z_][\w \*]*?)\b(\w+)\(([^)]*)\) \{", body)
    if m is None or m.group(2) not in protos:
        return body
    name = m.group(2)
    ret, params = m.group(1).strip(), [x.strip() for x in m.group(3).split(",")] if m.group(3).strip() not in ("", "void") else []
    old_ret, old_params = rets.get(name, ""), protos[name]
    if len(old_params) != len(params) or "" in old_params or not old_ret:
        return body
    if old_ret == ret and all(param_type(p) == t for p, t in zip(params, old_params)):
        return body
    if (old_ret == "void") != (ret == "void"):
        return body
    head, rest = body[: m.end()], body[m.end() :]
    new_params, converts = [], []
    for p, t in zip(params, old_params):
        pm = re.match(r"^(.*?)(\w+)$", p)
        if pm is None:
            return body
        pt, pn = pm.group(1).strip(), pm.group(2)
        if pt == t:
            new_params.append(p)
        else:
            new_params.append(f"{t} {pn}_")
            converts.append(f"    {pt} {pn} = ({pt}){pn}_;")
    head = f"{old_ret} {name}(" + ", ".join(new_params) + ") {"
    if old_ret != ret and old_ret != "void":
        rest = re.sub(r"\breturn ([^;]+);", lambda r: f"return ({old_ret})({r.group(1)});", rest)
    # The conversions go after m2c's own declarations
    lines = rest.split("\n")
    i = 1
    while i < len(lines) and re.match(r"^\s+[\w ]+[\s\*]+\w+(?:\[[^\]]*\])?;$", lines[i]):
        i += 1
    lines[i:i] = converts
    return head + "\n".join(lines)


def merge_into(text: str, src: str, adopt: bool = True) -> str:
    """Appends an m2c function (with its declarations) to a unit's source:
    declarations the unit already has are dropped, call arguments are cast to
    the unit's parameter types, and calls whose argument count disagrees with
    the unit go through a cast to the m2c prototype."""
    protos = {}
    rets = {}
    # Top-level declarations only: an indented call statement is not a prototype
    for m in re.finditer(r"^(?:extern\s+)?([A-Za-z_][\w \*]*?)\b(\w+)\(([^;(){}]*)\)\s*(?:;|\{)", text, re.M):
        p = m.group(3).strip()
        protos[m.group(2)] = [param_type(x) for x in p.split(",")] if p not in ("", "void") else []
        rets[m.group(2)] = m.group(1).strip()
    have = set(re.findall(r"^(?:extern )?[^\n(;]*?\b(\w+)\s*[\[(;]", text, re.M))
    own = {}
    for m in re.finditer(r"^([A-Za-z_][\w \*]*?)\b(\w+)\(([^;()]*)\);", src, re.M):
        own[m.group(2)] = (m.group(1).strip(), m.group(3).strip() or "void")
    decls, body = split_output(src)
    if adopt:
        body = adopt_signature(body, protos, rets)
    decls = [d for d in decls if decl_name(d) not in have]
    # m2c offsets symbols in bytes; the unit may type them as arrays or structs
    body = re.sub(r"&(lbl_\w+) \+ ", r"(u8 *)&\1 + ", body)
    for name, params in protos.items():
        if "..." in params:
            continue
        pos = body.find("{")
        while True:
            m = re.compile(r"\b" + re.escape(name) + r"\(").search(body, pos)
            if m is None:
                break
            args, end = split_args(body, m.end() - 1)
            if len(args) == len(params):
                new = name + "(" + ", ".join(f"({t})({a})" if t else a for t, a in zip(params, args)) + ")"
                # A result the unit types differently is cast to what m2c expected
                if name in own and rets.get(name) and own[name][0] != rets[name] and own[name][0] != "void":
                    if rets[name] == "void":
                        new = f"(({own[name][0]} (*)({own[name][1]})){name})(" + ", ".join(args) + ")"
                    else:
                        new = f"(({own[name][0]}){new})"
            elif name in own:
                ret, ps = own[name]
                new = f"(({ret} (*)({ps})){name})(" + ", ".join(args) + ")"
            else:
                pos = m.end()
                continue
            body = body[: m.start()] + new + body[end + 1 :]
            pos = m.start() + len(new)
    if '"common.hpp"' not in text:
        # The basic types; a unit with no code yet has only its own header.
        text = text.rstrip("\n") + '\n\n#include "common.hpp"\n'
    block = 'extern "C" {\n\n' + "".join(d + "\n" for d in decls)
    block += ("\n" if decls else "") + body.strip() + "\n}\n"
    return text.rstrip("\n") + "\n\n" + block


def remove_definition(text: str, name: str) -> str:
    """Removes the definition of name (one that does not match) from a source."""
    sys.path.insert(0, str(ROOT / "tools"))
    from graft import find_def

    r = find_def(text, name)
    return text if r is None else text[: r[0]] + text[r[1] :]


def retype_calls(text: str, name: str, old_text: str, new_sig: str) -> str:
    """Casts the unit's calls of name to the types of its new signature, and
    their results back to the type the old prototype gave them."""
    old = re.search(r"^([A-Za-z_][^\n(;{]*?)\b" + re.escape(name) + r"\s*\([^;{]*\)\s*;", old_text, re.M)
    m = re.match(r"^(.*?)\b" + re.escape(name) + r"\(([^)]*)\)$", new_sig)
    if old is None or m is None:
        return text
    old_ret, new_ret = old.group(1).strip(), m.group(1).strip()
    params = [param_type(x) for x in m.group(2).split(",")] if m.group(2).strip() not in ("", "void") else []
    out, pos = [], 0
    for c in re.finditer(r"\b" + re.escape(name) + r"\(", text):
        if c.start() < pos:
            continue
        line_start = text.rfind("\n", 0, c.start()) + 1
        if not text[line_start : c.start()].strip() or re.match(r"^[A-Za-z_]", text[line_start:]):
            # a declaration or definition, not a call
            if re.match(r"^[A-Za-z_]", text[line_start:]):
                continue
        args, end = split_args(text, c.end() - 1)
        if len(args) != len(params):
            continue
        call = name + "(" + ", ".join(f"({t})({a})" if t else a for t, a in zip(params, args)) + ")"
        if old_ret and old_ret != new_ret and old_ret != "void" and new_ret != "void":
            call = f"(({old_ret}){call})"
        out.append(text[pos : c.start()] + call)
        pos = end + 1
    return "".join(out) + text[pos:]


def function_matches(obj: str, target: "Obj", name: str) -> bool:
    base = Obj(ROOT / obj)
    return bool(target.function(name) and base.function(name) and same(target.function(name), base.function(name)))


def apply(unit: str, version: str, out_dir: Path, names: List[str], target: "Obj") -> List[str]:
    src_path = next(
        ROOT / p
        for p in json.loads((ROOT / "objdiff.json").read_text())["units"]
        if p["name"] == "main/" + unit
        for p in [p["metadata"]["source_path"]]
    )
    original = src_path.read_text(encoding="latin-1")
    obj = f"build/{version}/{unit}.o"
    text = original
    applied: List[str] = []
    # Address order; names that are not fn_<addr> go first.
    def key(n: str) -> int:
        m = re.match(r"fn_([0-9A-F]{8})$", n)
        return int(m.group(1), 16) if m else 0
    for name in sorted(names, key=key):
        src = (out_dir / f"{name}.cpp").read_text()
        # A definition already here does not match (or the function would not
        # have been tried), so the matching one replaces it.
        base = remove_definition(text, name)
        # First with m2c's own signature in place of the unit's prototypes
        # (callers may then need it), else with the unit's signature kept.
        candidates = [merge_into(base, src)]
        own = re.search(r"^([A-Za-z_][\w \*]*?\b" + re.escape(name) + r"\([^)]*\)) \{", src, re.M)
        if own:
            proto = re.compile(r"^[A-Za-z_][^\n(;{]*\b" + re.escape(name) + r"\s*\([^;{]*\)\s*;", re.M)
            reprototyped = retype_calls(proto.sub(own.group(1) + ";", base), name, base, own.group(1))
            if reprototyped != base:
                candidates.insert(0, merge_into(reprototyped, src, adopt=False))
        for candidate in candidates:
            src_path.write_text(candidate, encoding="latin-1")
            if build_unit([], obj) and function_matches(obj, target, name):
                text = candidate
                applied.append(name)
                break
        else:
            src_path.write_text(text, encoding="latin-1")
    src_path.write_text(text, encoding="latin-1")
    build_unit([], obj)
    # Keep only functions that still match in the full unit.
    base = Obj(ROOT / obj)
    bad = [n for n in applied if not (target.function(n) and base.function(n) and same(target.function(n), base.function(n)))]
    if bad:
        print(f"  {len(bad)} no longer match in the unit: {bad[:5]}")
    return [n for n in applied if n not in bad]


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("unit")
    ap.add_argument("--version", default="RPBE01")
    ap.add_argument("--max-size", type=lambda x: int(x, 0), default=0x400)
    ap.add_argument("--m2c", type=Path, default=Path("/home/user/ref/m2c/m2c.py"))
    ap.add_argument("--out", type=Path, default=None)
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--no-context", action="store_true", help="don't use build/<version>/m2c_context.c")
    args = ap.parse_args()
    os.chdir(ROOT)
    global CONTEXT_FILE
    CONTEXT_FILE = ROOT / "build" / args.version / "m2c_context.c"
    if not args.no_context and CONTEXT_FILE.exists():
        load_context(CONTEXT_FILE)

    unit = args.unit
    report = json.loads((ROOT / "build" / args.version / "report.json").read_text())
    entry = next(u for u in report["units"] if u["name"] == "main/" + unit)
    todo = [
        f
        for f in entry.get("functions", [])
        if f.get("fuzzy_match_percent", 0) < 100 and int(f["size"]) <= args.max_size
    ]
    edges = ninja_edges(args.version)
    edge = edges[f"build/{args.version}/{unit}.o"]
    target = Obj(ROOT / "build" / args.version / "obj" / (unit + ".o"))
    asm = ROOT / "build" / args.version / "asm" / (unit + ".s")
    out_dir = args.out or (ROOT / "build" / args.version / "automatch" / unit)
    out_dir.mkdir(parents=True, exist_ok=True)

    asm_text = asm.read_text()
    matched = []
    # A run that was cut short resumes: functions already tried are skipped,
    # and the ones that matched are applied with the rest.
    tried_file = out_dir / "tried.txt"
    tried = set(tried_file.read_text().split()) if tried_file.exists() else set()
    with tempfile.TemporaryDirectory() as t:
        tmp = Path(t)
        for f in todo:
            name = f["name"]
            tf = target.function(name)
            if tf is None:
                continue
            if name in tried:
                if (out_dir / f"{name}.cpp").exists():
                    matched.append((name, int(f["size"])))
                continue
            fn_asm = extract_fn(asm_text, name, tmp)
            variants = m2c(args.m2c, fn_asm, name) if fn_asm else []
            if not variants and fn_asm:
                variants = m2c(args.m2c, fn_asm, name, use_context=False)
            if not variants:
                print(f"  {name}: m2c failed", flush=True)
                continue
            result = "compile failed"
            best = (-1.0, "")
            tried_plain = False
            while True:
                for src in variants:
                    obj = compile_cpp(edge, src, args.m2c.parent, tmp)
                    if obj is None:
                        continue
                    bf = Obj(obj).function(name)
                    if bf is not None and same(tf, bf):
                        matched.append((name, int(f["size"])))
                        (out_dir / f"{name}.cpp").write_text(LAST_SOURCE)
                        result = f"MATCH ({int(f['size']):#x})"
                        break
                    if bf is not None:
                        best = max(best, (similarity(tf, bf), LAST_SOURCE))
                    result = "differs"
                # Without the context m2c infers every type itself, which
                # compiles where the context's guesses did not.
                if result != "compile failed" or tried_plain:
                    break
                tried_plain = True
                variants = m2c(args.m2c, fn_asm, name, use_context=False)
            if result == "differs" and best[0] >= 0:
                # Near misses are worth finishing by hand.
                (out_dir / "differs").mkdir(exist_ok=True)
                (out_dir / "differs" / f"{name}.cpp").write_text(f"// similarity {best[0]:.3f}\n" + best[1])
                result = f"differs ({best[0]:.3f})"
            print(f"  {name}: {result}", flush=True)
            with tried_file.open("a") as tf_out:
                tf_out.write(name + "\n")
    total = sum(s for _, s in matched)
    tried_file.unlink(missing_ok=True)
    print(f"{unit}: {len(matched)}/{len(todo)} matched, {total:#x} bytes")
    if args.apply and matched:
        applied = apply(unit, args.version, out_dir, [n for n, _ in matched], target)
        sizes = dict(matched)
        print(f"{unit}: applied {len(applied)}, {sum(sizes[n] for n in applied):#x} bytes")


if __name__ == "__main__":
    main()
