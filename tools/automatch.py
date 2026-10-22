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
            b[off + 1 : off + 4] = b"\0\0\0"
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


def m2c(m2c_path: Path, asm: Path, fn: str) -> List[str]:
    """m2c's output as plain C, as is and with known library prototypes."""
    try:
        out = subprocess.run(
            [sys.executable, str(m2c_path), "-t", "ppc-mwcc-c", "--valid-syntax", "-f", fn, str(asm)],
            capture_output=True,
            text=True,
            timeout=60,
        )
    except subprocess.TimeoutExpired:
        return []
    if out.returncode != 0 or "M2C_ERROR" in out.stdout or "/* unknown instruction" in out.stdout:
        return []
    variants = []
    for known in (False, True):
        v = expand_macros(out.stdout, known)
        if v is not None and v not in variants:
            variants.append(v)
    return variants


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


def compile_cpp(edge: Dict[str, str], src: str, m2c_dir: Path, tmp: Path) -> Optional[Path]:
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
    if r.returncode != 0 or not obj.exists():
        dump = os.environ.get("AUTOMATCH_DUMP")
        if dump:
            # Keep failing sources and compiler output, to improve the rewriting.
            d = Path(dump)
            d.mkdir(parents=True, exist_ok=True)
            n = len(list(d.glob("*.cpp")))
            (d / f"{n:04}.cpp").write_text(cpp.read_text(encoding="latin-1"), encoding="latin-1")
            (d / f"{n:04}.err").write_text(r.stdout + r.stderr)
        return None
    return obj


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
    return r.returncode == 0


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
    declared: Dict[str, str] = {}
    applied: List[str] = []
    # Address order; names that are not fn_<addr> go first.
    def key(n: str) -> int:
        m = re.match(r"fn_([0-9A-F]{8})$", n)
        return int(m.group(1), 16) if m else 0
    for name in sorted(names, key=key):
        decls, body = split_output((out_dir / f"{name}.cpp").read_text())
        if re.search(r"\b" + re.escape(name) + r"\s*\([^;{]*\)\s*\{", text):
            continue  # already defined by hand
        new_decls = []
        ok = True
        for d in decls:
            n = decl_name(d)
            if n is None:
                ok = False
                break
            if n in declared:
                if declared[n] != d:
                    ok = False
                    break
                continue
            new_decls.append((n, d))
        if not ok or name in declared:
            continue
        block = 'extern "C" {\n\n' + "".join(d + "\n" for _, d in new_decls)
        block += ("\n" if new_decls else "") + body.strip() + "\n}\n"
        candidate = text.rstrip("\n") + "\n\n" + block
        src_path.write_text(candidate, encoding="latin-1")
        if build_unit([], obj):
            text = candidate
            for n, d in new_decls:
                declared[n] = d
            declared[name] = body.split("{", 1)[0].strip() + ";"
            applied.append(name)
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
    args = ap.parse_args()
    os.chdir(ROOT)

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
    with tempfile.TemporaryDirectory() as t:
        tmp = Path(t)
        for f in todo:
            name = f["name"]
            tf = target.function(name)
            if tf is None:
                continue
            fn_asm = extract_fn(asm_text, name, tmp)
            variants = m2c(args.m2c, fn_asm, name) if fn_asm else []
            if not variants:
                print(f"  {name}: m2c failed", flush=True)
                continue
            result = "compile failed"
            best = (-1.0, "")
            for src in variants:
                obj = compile_cpp(edge, src, args.m2c.parent, tmp)
                if obj is None:
                    continue
                bf = Obj(obj).function(name)
                if bf is not None and same(tf, bf):
                    matched.append((name, int(f["size"])))
                    (out_dir / f"{name}.cpp").write_text(src)
                    result = f"MATCH ({int(f['size']):#x})"
                    break
                if bf is not None:
                    best = max(best, (similarity(tf, bf), src))
                result = "differs"
            if result == "differs" and best[0] >= 0:
                # Near misses are worth finishing by hand.
                (out_dir / "differs").mkdir(exist_ok=True)
                (out_dir / "differs" / f"{name}.cpp").write_text(f"// similarity {best[0]:.3f}\n" + best[1])
                result = f"differs ({best[0]:.3f})"
            print(f"  {name}: {result}", flush=True)
    total = sum(s for _, s in matched)
    print(f"{unit}: {len(matched)}/{len(todo)} matched, {total:#x} bytes")
    if args.apply and matched:
        applied = apply(unit, args.version, out_dir, [n for n, _ in matched], target)
        sizes = dict(matched)
        print(f"{unit}: applied {len(applied)}, {sum(sizes[n] for n in applied):#x} bytes")


if __name__ == "__main__":
    main()
