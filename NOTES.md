# Agent notes

Shared notes between the agents working on this repository (Claude and GPT).
Add to your own section, read the other's before starting, and keep entries
dated. Write facts and next steps, not narration.

## Ground rules (from the user)

- Target: a matching decomp of Pokémon Battle Revolution, USA (`RPBE01`).
- Develop on branch `claude/affectionate-faraday-jfatks`; never commit game data.
- Never make changes to the Moemon Kai repository.
- Commit and push for every 2% of progress. Next checkpoint: **35.42%** matched,
  then 37.42%, and so on.
- The build must stay byte-identical: `build/RPBE01/main.dol` SHA1
  `b8d70d7500497dc74bed4223260f3c0ac8540c83`. Check before every commit:
  `python3 configure.py --version RPBE01 && ninja && sha1sum build/RPBE01/main.dol`.
- Commit trailer:
  ```
  Co-Authored-By: Claude Opus 5.5 <noreply@anthropic.com>
  Claude-Session: https://claude.ai/code/session_01SM4WnDseWjVNb54wjCYnzd
  ```
  No model IDs in commit messages.

## Claude — 2026-10-23

### State

- 35.10% matched, 38.59% fuzzy (9129 / 13766 functions), pushed at `0ea9a9b`.
- Libraries (`libs/`) are mostly done; what is left is listed below. Game
  code (`src/.unsorted/*`, `src/gs/*`, `src/ds/*`) is where the bytes are.

### Tools (all in `tools/`)

- `automatch.py UNIT --apply`: runs m2c on each unmatched function of a unit
  (≤ 0x400 bytes), compiles several variants, and writes the ones that match
  into the unit. Near misses go to `build/RPBE01/automatch/UNIT/differs/`.
  Recent fixes that matter:
  - m2c no longer gets the function's own prototype from the context
    (`build/RPBE01/m2c_context.c`, from `tools/arity.py`); the context typed
    every parameter `s32`, so most outputs failed to compile.
  - Variants: small-integer locals widened to `s32`; locals in reverse order.
    On `src/.unsorted/8038F1CC` this took small functions from 155 to 193 of
    201 matched.
  - Apply: when the unit already declares the function with other types, the
    prototype is replaced and the unit's calls are cast (`retype_calls`), or
    the unit's signature is kept and converted inside (`adopt_signature`).
  - Resumable: a unit's tried functions are recorded in `tried.txt` in its
    output directory; a restarted run skips them and still applies earlier
    matches.
- `name_by_code.py VERSION UNIT... [--apply]`: names placeholder `fn_` symbols
  after same-code functions of the compiled source. Skips names already in
  `symbols.txt` (a duplicate weak name made the linker fold two functions and
  broke the hash once).
- `graft.py FILE REF FN...`: copies function definitions from a reference
  source (zeldaret/tp, doldecomp/ogws, wii-ipl; checked out under
  `/home/user/ref`, compiled objects under `/home/user/ref/objs`).
- `split_unit.py`, `merge_unit.py`: move unit boundaries in every config.
- `permute_decls.py`: hill-climbs local declaration order. It found nothing on
  75 automatch near misses; not worth running in bulk.
- `decomp/fn_diff.py -u main/UNIT SYMBOL`: compact diff of one function.

### Running automatch at scale

- Two git worktrees, `/home/user/wt/auto` and `/home/user/wt/auto2` (branches
  `wt/auto`, `wt/auto2`), each with its own build directory, run automatch
  unit by unit and commit a unit only when the DOL hash still matches. Merge
  them into the main branch periodically (`git merge wt/auto wt/auto2`).
- The container restarts every hour or two and kills background processes.
  The runs had been relaunched with the units sorted biggest first; they were
  killed again at about 04:40 UTC with ~30 functions done per unit.
- **Speed is the bottleneck**: about 2 minutes per function. m2c spends ~6 s
  parsing the 15,000-line context on every call (0.2 s without it), and a
  function can need up to ~16 compiled variants. I started trimming the
  context to the declarations the function's asm refers to (only prototypes
  are in it, plus 10 typedef lines), but did not finish checking that the
  output is unchanged, so the change is not committed. That is the most
  valuable next step.

### Library leftovers (lower value)

- THPDec: CompY/U/V carry hand-inlined asm copies of the Huffman decoder in
  this SDK; TP's GameCube copy does not. `fn_8029EEFC` is not
  `__THPHuffDecodeTab` (that is inlined everywhere here).
- WPAD, WUD, `uusb_ppc`, parts of OSExec (`__OSLaunchNextFirmware`-like
  `fn_8026BD34`, `fn_8026C328`, `__OSBootDolSimple`): another SDK revision
  than any reference; struct offsets differ.
- nw4r: the remaining diffs are register allocation or static-local names.

### Pitfalls

- An undefined macro in C compiles as a call to an undeclared function; check
  `nm` of the object for unexpected uppercase undefined symbols.
- MWCC C mode needs parameter names in definitions.
- Never `pkill -f` a pattern that matches your own shell; kill by PID.
- dtk exports a local symbol referenced from another unit as `name_ADDR`;
  objdiff then cannot pair it with the source's `name` (objdiff
  `symbol_mappings` did not help).

## GPT

(Add your notes here.)
