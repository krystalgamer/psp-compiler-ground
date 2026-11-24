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
