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
- In `decomp_src` the newlib and libgcc units that reproduce are the
  upstream sources themselves (`tools/libsrc.py`).  `-g` changes no code.
  Sony's newlib was configured with long long printf: `_vfprintf_r` with
  `WANT_PRINTF_LONG_LONG` comes within 8 bytes, and the rest is register
  allocation.  `powf` (only in 1.6.1.internal modules) leaves one branch
  delay slot empty where every cc1 we have fills it with the preceding
  store.  This is still open.

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
  the single-float DSP code decompiled since (UTST99261's Xing mp3
  decoder: fdct, imdct, window, sbt, l3hybrid, l3msis; sampler's movie,
  display, utils) compiles identically with both cc1s too, and
  inline asm never ends up in a delay slot with either cc1 (only psp-as
  swaps it there, as in 1.5.1's `usrKernelIcacheInvalidate`).  They stay
  out of the 1.6.1 tree for lack of evidence.  On UTST99332
  (1.6.1.internal, still mostly asm) the discriminator went through 45 of
  the 63 modules without a single difference; most m2c drafts there do
  not compile yet (889 skipped), so this is weak evidence.
- Things that looked like compiler differences but are source-level:
  `strFileOpen`'s missing `movz` (`ret = -1; if (fd >= 0) ret = 1;` keeps the
  branch, an if/else converts), the constant 0 of Allegrex `max` kept in an
  s-register (a `MAX()` macro folds to MAX_EXPR at tree level, so the 0 is
  loop-invariant; an `if` is turned into `max` by if-conversion after the
  loop optimizer), and constants hoisted to an outer loop (a goto-loop has
  no loop notes, so 3.3's loop.c treats it as part of the outer loop).
- Objects without DWARF (`tools/nodwarf.py`): the SDK's libgum, libgu and
  kernel_bridge (newlib's syscall glue) are linked into almost every
  UTST99332 sample and were built by 1.6.1.internal too (the module's only
  `.comment` version).  They decompile with plain `-O2` and the 1.6.1
  tree; what looked like compiler differences were source details:
  libgum calls `sinf`/`cosf`/`sqrtf` without a prototype, so they are
  GCC's builtins (pure, `sqrtf` inline with its NaN fallback) and calls
  can be scheduled across the stores of the matrix being built; libgu
  reads float arguments through a union (float-typed loads, which do not
  alias the display-list stores, so all loads are hoisted);
  kernel_bridge's `_sys_open` is a K&R definition that `_open` calls with
  two arguments.
- The same SDK libraries built by 1.5.1.internal (sampler) are an older
  source revision (`send_commandi`/`send_commandf` are real functions, not
  inlines), but the 1.6.1.internal C carries over: 58 of libgu's functions
  match.  `sceGuTexLevelMode` (the bias clamp) matches only with 1.5.1's
  cc1; 1.3.1's, 1.6.1's and 1.7.1's emit conditional moves.  This is a
  second, independent confirmation of the 1.5.1 condmove change and that
  1.5.1.internal uses the 1.5.1 compiler; the module build checks it.
- bigbangbang (1.5.1.internal throughout, with DWARF; `.comment` says
  `allegrex-2.2.1`, like every 1.4.0–1.5.1 build, against `2.2.2` for
  1.6.1): its SDK libgu is the same older revision as sampler's and again
  matches 62 functions with 1.5.1's cc1 and 61 with every other compiler
  (`sceGuTexLevelMode`).  Its own game code confirms it too: `KeyGame`'s
  cursor clamps match only with 1.5.1's cc1 (the others turn them into
  conditional moves).  Several near-matches there were missing prototypes
  in our C (implicit declarations change argument evaluation and register
  choice), not compiler differences.
- Per-library flags under 1.6.1.internal: UTST99332 demo_luga's copy of the
  gmo model library (an older revision than graphics_model's: different
  function order, a `geModelDoTextureFunc` hook in `sceGmoTextureActivate`)
  was built with `-O2 -frename-registers`, like sampler's 1.5.0.internal
  libraries.  graphics_model and graphics_model2 compile the same sources
  with plain `-O2`.  Same compiler, different makefile: not a compiler
  change.
- puzzle_bobble's game code has no DWARF, but its symbol table keeps the
  `STT_FILE` symbols, so it is split into its 23 source files
  (`config/puzzle_bobble/files.BOOT.txt`).  The `.comment` entries in link
  order give each file's compiler: the game is 1.5.1, except `file_sub.c`
  and `savedata.c`, which are 1.6.1 (and the map data, 1.4.0).  Both
  1.6.1 files match with the 1.6.1 tree (24 of 28 functions so far) and
  with 1.7.1's cc1.  1.5.1 and 1.3.1 fail exactly at `load_buf` and
  `set_param_save`, which copy the 40-byte save data with an inline block
  move.  It checks the alignment at run time and copies with `lwl`/`lwr`
  when it is unaligned, which is more evidence for the `-mno-ulsw` default
  being gone in 1.6.1.
- Source-level traps found on the way: a `memcpy` whose length is a
  variable that holds a constant (`len = strlen("ULKS46002")`) stays a
  call, while a literal length of 32 bytes or less is expanded inline.
  GCC 3.3's `while (c) body` and `for (;;) { if (!c) break; body }`
  schedule differently.
- `__builtin_allegrex_wsbh` already exists in 1.6.1 (`sceNetHtons` in
  UTST99261 mp3/netmgr uses it).
- **1.6.1.internal's constants: no compiler change, a link-order and
  library-build difference.**  App code built by 1.6.1.internal keeps its
  float constants in `.rodata.cst4` (constant merging on, as with every
  release cc1) and strings and aggregate initializers in `.rodata`.  What
  differs is how they are linked: Sony's `*(.rodata .rodata.*)` takes an
  object's sections in the object's own order, and the internal toolchain's
  assembler creates them in order of first use.  So a unit whose first
  constant is a float has all its floats *before* its strings and
  aggregates.  Of 66 internal units with both kinds, 62 are exactly two
  blocks, floats first (26) or strings first (36).  This is what looked
  like aggregate constants held back to the end of the unit: in
  graphics_torus, graphics_gears and graphics_dragon `init_all`'s auto
  `ScePspIMatrix4 dith = {...}` is the only `.rodata` constant, after
  every float.  In graphics_vtxformat and graphics_stick the first constant
  is an aggregate, so the aggregates come first.  graphics_torus's
  `main.c` built by 1.6.1's own cc1 with this link order and Sony's
  `ScePspIMatrix4` (`__attribute__((aligned(16)))`, not in DWARF) is
  byte-identical, `init_all` included.  The release toolchains' objects
  (UTST99261, sampler, puzzle_bobble) always have `.rodata` first.  The
  remaining interleaved internal units (utility_font_basho) are `-O0`
  builds: frame pointer, unsplit addresses, and no constant merging at
  `-O0`.
- The internal newlib and libgcc, on the other hand, were built without
  constant merging: in `_dtoa_r` the strings after the function follow its
  `double`s in one `.rodata`.  `config/compilers.txt` passes
  `-fno-merge-constants` for those (`lib:`), and for app units that still
  mix C with asm (`mixed:`, so C and asm floats stay in one section in
  emission order) until they are all C.

## psp-gcc 1.5.0.internal

- Only sampler's libmpeg/libpsmf objects (libpsmf, psmfBase,
  libmpeg_util) were built with it.  It still has **conditional moves**:
  `_type_check`, `_version_check` and `scePsmfQueryStreamOffset` need
  `movz`/`movn`, which 1.5.1's cc1 (`ISA_HAS_INT_CONDMOVE 0`) cannot emit
  and 1.3.1's original cc1 does.  So 1.5.0.internal is 1.3.1's compiler
  (its DWARF also has 1.3.1's unnamed 16-byte TImode type);
  `config/compilers.txt` maps it to `cc1-1.3.1-orig -mno-ulsw`.  The
  condmove change is new in 1.5.1.
- Sony built these libraries with register renaming: every value gets a
  fresh hard register (`-frename-registers`, i.e. `-O3` without its
  inlining: with `-O3` the small static helpers such as
  `_streamId2sceMpegStreamId` would be inlined and gone).  The units say
  `cflags: -O2 -frename-registers`.
- `tools/discrim.py --cc1 1.3.1-orig,1.5.1` on these units differs exactly
  where a conditional move is made (`_type_check`, `_version_check`,
  `scePsmfGetCurrentStreamType`, `scePsmfCheckEP_map_Base`,
  `scePsmfCheckStreamType_Base`, `_sceMpegId2type`); the 1.3.1 side is the
  one that matches.
