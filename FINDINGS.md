# Findings

Evidence for each change to the compiler trees, from compiling sources
whose original is known (newlib 1.12.0, libgcc) and comparing with the
modules (`tools/nltest.py`, `tools/objcmp.py`).

## Method

- newlib 1.12.0 is compiled with `-O2 -g -fno-builtin` (Sony's psp-newlib
  build; without `-fno-builtin`, e.g. libm's `fabs` calls get inlined).
  `tools/nltest.py TARGET MODULE CC1...` compiles each newlib unit of a
  module and compares its functions.
- libgcc is built from the tree itself (`tools/build_gcc.sh V --libgcc`) and
  compared with `tools/objcmp.py`.
- `tools/patchtest.sh` builds a tree with patches applied and scores it;
  the psp-gcc 1.7.1 changes on top of 1.3.1 are the candidates.
- What is left after this is Sony's own newlib changes (`memcpy`,
  `_vfprintf_r`, malloc, `_setlocale_r`, ...): those differ for every
  compiler, 1.7.1 included, and need decompiling.

## psp-gcc 1.5.1

- **No integer conditional moves (`movn`/`movz`).** UTST99261's newlib
  (built by 1.5.1): with 1.3.1's `ISA_HAS_INT_CONDMOVE` 157 instead of 135
  of 169 functions are identical, e.g. `strchr`, `strcasecmp`, `exit`,
  `_strtod_r`, which 1.5.1 compiled with branches where 1.3.1 and 1.7.1
  use `movz`/`movn`.  With it, libgcc built from the tree reproduces all
  26 libgcc functions of UTST99261 (1.3.1: 19, 1.7.1: 15).

- Neither the 32-bit `HOST_WIDE_INT` nor `abssi2` as `smax` of 1.7.1:
  either one breaks UTST99261's libgcc (19 → 16 or 18 of 26).
- With these, 170 of UTST99261's 176 newlib functions are reproduced; the
  other 6 are Sony's newlib changes.

- Game code confirms the `-mno-ulsw` driver default: UTST99261's
  `addDownload` copies a constant string with byte loads/stores (an inline
  `strcpy`); only the `-mno-ulsw` compilers (1.5.1, 1.3.1) reproduce it,
  while 1.6.1 and 1.7.1 use `lwl`/`lwr`.
- Inline asm can still go into delay slots: `usrKernelIcacheInvalidate`'s
  second `cache` sits in a `j` delay slot, as with every cc1 we have.

- UTST99261's 1.5.1 game code (all 22 units) is decompiled except for 15
  functions.  Everything that matches does so with the 1.5.1 tree.  The
  remaining near-misses compile the same way with every cc1 we have, so they
  are source-level, not compiler, differences.  Units where only 1.5.1
  matches: `AOSS_Sleep` (1.3.1 uses `movn`, i.e. no integer conditional
  moves in 1.5.1) and `addDownload`/`CnfSaveInitStart` (byte copies,
  `-mno-ulsw`).

## psp-gcc 1.6.1

- **32-bit `HOST_WIDE_INT`** (psp-gcc 1.7.1, `psp: use a 32-bit
  HOST_WIDE_INT`) and **`abssi2` as `smax (x, -x)`** (1.7.1): together
  they reproduce every libgcc function of puzzle_bobble (1.6.1, 24),
  sampler (18) and UTST99332 (24, both 1.6.1.internal); 1.3.1 gets 19 of
  24, each change alone 23 or 20.
- None of 1.7.1's other code generation changes (earlyclobbers, madd/msub,
  insv, loadgpsym, rotates, asm in delay slots, block moves) changes
  anything in libgcc or newlib; the game code has to decide.
- newlib: puzzle_bobble 108/115, sampler 77/83, UTST99332 menu 94/99 and
  graphics_cube 88/93; the rest are Sony's newlib changes (plus
  `__ieee754_rem_pio2` in puzzle_bobble, still open).
- **No `-mno-ulsw` by default** (1.7.1 patch 0002): the unaligned copies
  of the 1.6.1 units use `lwl`/`swl` block moves, which `-mno-ulsw`
  forbids.
- **gthr-psp.h mutexes by suspending interrupts** (1.7.1 patch 0018):
  with it, UTST99332 demo_duck's libgcc (1.6.1.internal, the only libgcc
  here with the unwinder) goes from 71/78 to 75/78 functions:
  `__register_frame_info*`, `__deregister_frame_info*` and
  `_Unwind_Find_FDE` match.  Patch 0021 (`sceKernelCpuResumeIntr`
  returning void) changes no code.
- The last three (`execute_cfa_program`, `execute_stack_op`,
  `extract_cie_info`) are not a compiler change.  cc1 emits the `ulw`
  macro for the reads through `union unaligned`.  The 1.3.1 psp-as
  expands it to four `lbu`, while the original has `lwl`/`lwr`, as
  1.7.1's assembler does.  With `psp-as -mulsw` all of unwind-dw2 matches
  (29/29), so libgcc matches completely.  `config/compilers.txt` passes
  `as:-mulsw` for 1.6.1.internal.  Whether the 1.6.1 release's
  binutils already did this is open; none of its code seen so far uses
  `ulw`.
- **TImode types with the 32-bit `HOST_WIDE_INT`** (1.7.1 patch 0011):
  psptypes.h types `u_long128` and friends as `mode(TI)`.  In every
  1.6.1 and 1.6.1.internal compile unit the DWARF base type is
  `__uint128_t`/`__int128_t`, as with 1.7.1's cc1.  In 1.4.0, 1.5.0.internal,
  1.5.1 and 1.5.1.internal units, as with 1.3.1's cc1, it is an unnamed
  16-byte type (`__unknown__`).  Without the patch, 1.6.1's cc1 rejects
  `mode(TI)` altogether.
- UTST99261's 1.6.1 game code (mpeg/*, mp3/*): everything decompiled so far
  matches with the 1.6.1 tree and with 1.7.1's cc1 alike.  `tools/discrim.py`
  compiles every decompiled unit and the m2c draft of every remaining
  function with both cc1s and compares the assembly: UTST99261 and sampler
  give no difference at all.  So 1.7.1's remaining changes (DI
  earlyclobbers, madd/msub, insv, loadgpsym, rotate counts, asm delay
  slots, gp_safe, block-move offsets) are not exercised by this code: there
  are no madd/msub/ins/ext instructions in any of the game modules, and
  inline asm never ends up in a delay slot with either cc1 (only psp-as
  swaps it there, as in 1.5.1's `usrKernelIcacheInvalidate`).  They stay
  out of the 1.6.1 tree for lack of evidence.
- Things that looked like compiler differences but are source-level:
  `strFileOpen`'s missing `movz` (`ret = -1; if (fd >= 0) ret = 1;` keeps the
  branch, an if/else converts), the constant 0 of Allegrex `max` kept in an
  s-register (a `MAX()` macro folds to MAX_EXPR at tree level, so the 0 is
  loop-invariant; an `if` is turned into `max` by if-conversion after the
  loop optimizer), and constants hoisted to an outer loop (a goto-loop has
  no loop notes, so 3.3's loop.c treats it as part of the outer loop).
- `__builtin_allegrex_wsbh` already exists in 1.6.1 (`sceNetHtons` in
  UTST99261 mp3/netmgr uses it).
