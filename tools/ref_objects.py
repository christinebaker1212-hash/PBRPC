#!/usr/bin/env python3

###
# Compiles the sources of another dtk-template decomp project (e.g. a CC0
# reference such as wii-ipl or ogws) with that project's own flags, without
# needing its disc image, so tools/find_functions.py can look for its
# functions in this game.
#
# Usage: python tools/ref_objects.py <project dir> <out dir> [path filter regex]
###

import os
import re
import runpy
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main() -> None:
    proj = Path(sys.argv[1]).resolve()
    out = Path(sys.argv[2]).resolve()
    flt = re.compile(sys.argv[3]) if len(sys.argv) > 3 else None
    os.chdir(proj)
    sys.path.insert(0, str(proj))
    import tools.project as project  # the reference's tools/project.py

    project.generate_build = lambda config: None
    project.calculate_progress = lambda config: None
    sys.argv = ["configure.py", "configure"]
    g = runpy.run_path(str(proj / "configure.py"), run_name="__main__")
    config = g["config"]
    compilers = ROOT / "build" / "compilers"
    wibo = ROOT / "build" / "tools" / "wibo"
    ok = fail = 0
    for lib in config.libs:
        lib = dict(lib)
        for obj in lib["objects"]:
            name = obj.name
            src = Path(lib.get("src_dir", "src")) / name
            opts = obj.options
            if flt and not flt.search(str(src)):
                continue
            if not src.exists():
                continue
            cflags = opts.get("cflags") or lib.get("cflags")
            extra = opts.get("extra_cflags") or []
            mw = opts.get("mw_version") or lib.get("mw_version")
            o = out / src.with_suffix(".o")
            o.parent.mkdir(parents=True, exist_ok=True)
            if o.exists() and o.stat().st_mtime > src.stat().st_mtime:
                ok += 1
                continue
            flags = []
            for f in [*cflags, *extra]:
                flags += shlex.split(f)
            lang = ["-lang=c++"] if src.suffix in (".cpp", ".cp") else ["-lang=c"]
            cmd = [str(wibo), str(compilers / mw / "mwcceppc.exe"), *flags, *lang, "-c", str(src), "-o", str(o)]
            r = subprocess.run(cmd, capture_output=True, text=True)
            if r.returncode == 0 and o.exists():
                ok += 1
            else:
                fail += 1
    print(f"compiled {ok}, failed {fail}")


if __name__ == "__main__":
    main()
