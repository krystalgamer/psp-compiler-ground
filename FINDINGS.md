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
  store: that is 1.6.1's newlib assembler, see "No delay-slot swap across
  source lines" under psp-gcc 1.6.1.
- A module's libgcc compile units were built inside the gcc tree, so their
  DWARF describes the compiler's own headers: `tconfig.h` and
  `config/mips/mips.h` (`enum cmp_type`, `enum reg_class`, `struct
  mips_args`, `enum mips_builtins`, ...) with every enumerator and
  declaration line.  `tools/gcchdr.py MODULE.prx --tree V` diffs them
  against a tree.

## psp-gcc 1.5.1

- **No integer conditional moves (`movn`/`movz`).** UTST99261's newlib
  (built by 1.5.1): with 1.3.1's `ISA_HAS_INT_CONDMOVE` 157 instead of 135
  of 169 functions are identical, e.g. `strchr`, `strcasecmp`, `exit`,
  `_strtod_r`, which 1.5.1 compiled with branches where 1.3.1 and 1.7.1
  use `movz`/`movn`.  With it, libgcc built from the tree reproduces all
  26 libgcc functions of UTST99261 (1.3.1: 19, 1.7.1: 15).

- Neither the 32-bit `HOST_WIDE_INT` nor `abssi2` as `smax` of 1.7.1:
  either one breaks UTST99261's libgcc (19 → 16 or 18 of 26).
  Firmware confirms it: pspnet_inet's (1.5.1.internal) `sppp_ipcp_close`
  tests a 64-bit `pp_saved_mtu > 0` the way only 1.5.1/1.3.1-orig compile
  it; 1.6.1 and 1.7.1-orig differ. Its `pppoe_send_padt` copies a 6-byte
  address with byte loads/stores, again the `-mno-ulsw` default.
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

- `tony_libs` (stripped 1.5.1.internal firmware modules) agree with the
  1.5.1 tree. libatrac3plus is built `-O2 -frename-registers` (the same
  style as libwave): every tiny helper is called, never inlined, so not
  `-O3` (which in gcc 3.3 would also defer every function to the end of the
  file). Strict aliasing is on (the `-O2` default): `func_0000340C` and
  `func_00003178` move stores to pointer-typed buffer fields past loads of
  `unsigned int` fields, which only `-fstrict-aliasing` with those types
  allows. Kernel modules (audiocodec) save and
  shift `$k1` with inline asm and read it as a global register variable;
  the restore is inline asm too, which is why it never lands in a delay
  slot. Sony's code calls `__builtin_allegrex_ext` directly.
- libatrac3plus is a fourth independent confirmation of the condmove change:
  all 44 functions decompiled so far match with the 1.5.1 tree, but only 29
  with the 1.3.1 or 1.6.1 cc1 (e.g. `func_0000224C`, a 5-instruction
  `min`, and `func_00002064` are `beql`/`bnel` where they use `movz`/`movn`).
  The remaining near-misses compile the same with every cc1, so they are
  source-level.
- **The condmove change is gated by `-mext`.** In 1.5.1, integer
  conditional moves are available only together with Allegrex insert/extract
  (`ISA_HAS_INT_CONDMOVE` = `TARGET_ALLEGREX31 && TARGET_EXT`, was
  `TARGET_ALLEGREX31` in 1.3.1). sc_sascore is the only 1.5.1-era module built
  with `-mext` (its shifts and masks become exactly the original's `ext`
  instructions only with it) and the only one with `movz`/`movn` in compiled
  C (five functions); `__sceSasSetTrianglarWave` matches exactly with the
  gated tree and `-mext`, and cannot match with conditional moves off. All
  other modules, built without `-mext`, compile exactly as before (full
  rebuild unchanged). Excluded: a different default CPU (allegrex2/3 would
  give 8-byte stack alignment; every frame is 16-byte aligned) and an older
  cc1 (`.comment` says 1.5.1.internal).
- gcc 3.3 marks a function defined earlier in the same file const/pure
  (`mark_constant_function`) when it only reads memory, so calls to it don't
  force reloads. Where the original reloads after calling such a helper,
  the two were in different objects; this places object boundaries in
  stripped modules.
- The 1.5.1.internal toolchain's assembler creates `.rodata`/`.rodata.cst4`
  in the order an object first uses them, like 1.6.1.internal's
  (`objorder` in config/compilers.txt). umdt's graphics_model, built with
  1.5.1.internal, shows it: gmo_material and gmo_motion (devkit 0.6.0 source)
  match function by function but the module is byte-identical only when
  linked `obj(.rodata .rodata.*)`. Applying it to every 1.5.1.internal unit
  leaves all other modules byte-identical. Release 1.5.1 modules
  (UTST99261, puzzle_bobble, flashData_check) rebuild without it; whether
  the release toolchain differs is not shown.
- The same gmo/gim C compiled by cc1 1.5.1 matches umdt's graphics_model and,
  by cc1 1.6.1, UTST99332's (1.6.1.internal) graphics_model; the two builds
  differ only at the conditional-move sites, i.e. by compiler alone. Two
  exceptions are source changes, not compiler ones: UTST99332's newer SDK
  has `sceGmoPartLoad`/`sceGmoMotionLoad(…, const SceGmoChunk *load_chunk)`
  with a separate `chunk` local (from DWARF). No cc1 reproduces it from the
  older source and 1.6.1 does from the newer.

- bigbangbang (1.5.1.internal): newlib 31/31 and libgcc fp-bit/dp-bit 8/8
  from upstream source. Sony's newlib malloc is built with
  `MALLOC_ALIGNMENT 16`; `mlock.c` is Sony's own. Only 1.5.1's cc1 matches
  `malloc_extend_top`, `_malloc_r`, `__truncdfsf2`, `__pack_d`, `__pack_f`
  (condmove).
- 1.5.1.internal objects were built without `-fno-merge-constants`: float
  constants go to `.rodata.cst4`, which comes first in the object (objorder),
  before strings and jump tables. Fully-C units match at plain `-O2`.
- Open candidate: bigbangbang `DrawGround`. All cc1s give the same code,
  3 instructions off. The two loop-invariant float constant loads (1.0,
  -16.0) are hoisted in the opposite order and the -16.0 address uses `v1`
  instead of `v0`. ~20 source forms tried.

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
  `__ieee754_rem_pio2` in puzzle_bobble: the assembler, see below).
- **1.7.1's header layout** (1.7.1 patches 0008+0012, 0013, 0019, 0020):
  the libgcc of the 1.6.1 release (spaceinvaders in psp184, puzzle_bobble)
  declares `rtx` at `tconfig.h:25` (one more tm_define than this tree had:
  `MAX_WCHAR_TYPE_SIZE=32`, the 32-bit `cppchar_t`), `enum reg_class` at
  `mips.h:2089`, `struct mips_args` at 2792 and `enum mips_builtins`
  (`MIPS_BUILTIN_CLZ` … `MIPS_BUILTIN_SQRT_S`) at 4813, exactly
  1.7.1's mips.h: 18 more lines before `reg_class` (7 from
  `-mcallee-saved-gp`/`gp_safe`, which needs the `loadgpsym` pattern, and
  1.7.1's 11 unknown lines) and the builtins enum moved from mips.c.  With
  the four commits `tools/gcchdr.py --tree 1.6.1` finds no difference for
  either module, and the clean rebuild of every 1.6.1 target is
  unchanged: no code depends on them.  No code shows whether the other
  1.7.1 changes are in 1.6.1 either; 1.6.1's headers are 1.7.1's.
- **1.6.1.internal's mips.h has 22 more lines**: sampler's and UTST99332's
  libgcc (1.6.1.internal) put `reg_class` at 2098 (+9) and `mips_builtins`
  at 4835 (+13 more after `CUMULATIVE_ARGS`), with the same enumerators.
  1.8.4.internal has the same two insertions over 1.8.3 (below), so this
  is an internal-only addition carried from release to release.  Its
  content is unknown and no code depends on it (1.6.1.internal code all
  matches with the 1.6.1 tree).
- **No delay-slot swap across source lines in 1.6.1's newlib.**  In every
  1.6.1 and 1.6.1.internal module the newlib compile units' line tables
  have a `DW_LNE_set_address` for every row; libgcc's, 1.5.1's and 1.8.x's
  newlib and all application code advance the address instead
  (`tools/linestyle.py`: in spaceinvaders 69 units of the first kind, all
  newlib, and 24 libgcc units of the second).  psp-newlib 1.6.1 was assembled by a psp-as that
  starts afresh at each `.loc`, and so never moves an instruction into a
  branch delay slot across a source line change.  This explains every
  open newlib function with an empty slot: compiled with `-g` and with a
  label put on each such branch (`tools/locfix.py`, which stops the 1.3.1
  psp-as the same way), `powf`, `asinf`, `expf`, `acosf`, `sqrt` and
  `__ieee754_rem_pio2` (UTST99332), `acosf` and `fmodf` (spaceinvaders)
  match, and no other 1.6.1 newlib unit changes.  puzzle_bobble's
  `__ieee754_rem_pio2`, spaceinvaders' two and `acosf` in five UTST99332
  modules are now upstream source; the other UTST99332 ones stay asm
  because their constants are not split out of the module's rodata.  The same treatment
  breaks 9 of UTST99261's 1.5.1 newlib units and two of 1.6.1's libgcc
  functions (`__muldf3`, `__unpack_d`), whose assembler still swaps.
  `config/compilers.txt` says `newlib:locfix` for 1.6.1(.internal); the
  clean rebuild of every 1.6.1 target, with all converted newlib units
  now compiled this way, is unchanged.
- **spaceinvaders** (psp184; 1.6.1 game, newlib and libgcc, 1.6.1.internal
  SDK libraries) agrees with the 1.6.1 tree: its libgcc and newlib give
  75 of 89 units from source (the rest are Sony's newlib changes, the
  same as in the other 1.6.1 modules: `_vfprintf_r`, malloc alignment,
  `atexit`/`findfp`/`locale` data, rodata ranges).  Its game code (about
  400 KB) has no DWARF, and its `STT_FILE` symbols are not in link
  order, so `tools/nodwarf.py` cannot split it yet.
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

- flowars (release 1.6.1, DWARF, `-O2`): 226/305 app functions and 68/82
  newlib/libgcc units in C. None matches only with 1.6.1; all also match with
  1.3.1-orig, 1.7.1-orig and 1.8.4, while 1.5.1 fails only at condmove sites
  (`_open`, `strFileReadCB`, `DvdUmdRetryReadCB`, `debugMsg`, `printMsg`,
  `wait_stage`, `is_bisang`, `fade_out`, `draw_checked_pae`, `show_warning`,
  `draw_face`).
  Open candidate: `load_file` and `vag_file_read`.
  - **What the original looks like:** what our cc1 gives with interblock
    scheduling off for just that function. `vag_file_read` is
    byte-identical with `-fno-sched-interblock`. `load_file` then differs
    only by an s1/s2 swap, which also stays with scheduling off entirely.
  - **Not a size limit:** the scheduler's region limits (10 blocks/100
    insns) don't apply: `load_file` has 8 blocks and 63 insns. Padding it
    with 38 empty `asm()`s gives the original exactly.
  - **Same-size functions get the motion:** `load_image` (8 blocks/73
    insns), `draw_character` (10/89), `give_pae` (6/76) and
    `assign_mission` all do. So it isn't a uniform threshold.
  - **Source variants:** none changed it (volatile, goto/else structure,
    inline helper, long long temporaries, `-fno-gcse`, ...).
  - Unresolved: a source detail that rejects the whole-function region, or a
    per-function compiler difference.

- Release 1.6.1's newlib was also built without constant merging: flowars'
  `dtoa` matches upstream only with `-fno-merge-constants`.
- Open pattern (flowars `get_mission_grade`, `count_A300`,
  `update_sp_status`): the original copies a register known to hold 0
  (`t = i`, `cnt = sum`, `my_cnt = opp_cnt`) where every cc1 (1.3.1-orig
  to 1.8.4) loads the constant 0. Maybe a source form, maybe a cse/reload
  difference; not found.

- Rodata order is a property of the game's build, not of 1.6.1: spaceinvaders'
  release 1.6.1 objects link `.rodata`, `.rodata.cst4`, `.rodata.cst8` in
  first-use order (all units fit; `-fno-merge-constants` contradicts 5 of
  them, e.g. `psp_dev`, `inv_game`), while UTST99261's 1.6.1 mp3 units break
  with that order. flowars is the same (animator: every function's doubles,
  then floats, then strings). `config/compilers.txt` now takes per-module additions
  (`@psp184/spaceinvaders 1.6.1 objorder`). Its libwave/libgum are built
  `-O2 -frename-registers`, UTST99332's plain `-O2`: also per game.

- Sony's `memmove` (in every 1.6.1-era module's newlib) is C built with
  `-falign-loops=64` (its forward loops are 64-byte aligned); 1.5.1's and
  1.3.1's psp-as can't assemble the result. UTST99332's SDK `libsas` is
  `-O2 -frename-registers` like libwave.

## psp-gcc 1.7.1 (release build)

htmlviewer is the first module built by release 1.7.1 (plus SDK libraries
built by 1.8.4.internal). Its app code (devkit 0.6.0 `sample/utility/basic`
style, plain `-O2`) is 149/157 functions in byte-matching C. Every matched
function also matches with 1.6.1, 1.8.3 and 1.8.4. No case of right-looking
C that no cc1 reproduces. The older cc1s differ only by known changes:
with `-mulsw` (cc1 and as) instead of their `-mno-ulsw` driver default,
1.3.1-orig matches everything, and 1.5.1 fails only at conditional-move
sites (`Menu_MenuUp`, `Menu_ScrollLines`, `sub_thread`). Without it both
fail `setHoldDisplay`/`startMsgDialog` (512-byte copies through a runtime
alignment check). So the module is
consistent with 1.7.1-orig but doesn't distinguish it from 1.6.1/1.8.x. Its
1.8.4.internal code contains no VFPU instructions.

## psp-gcc 1.4.0.internal

- The PSP devkit 0.6.0 ships library sources with the libraries built from
  them (`.comment` 1.4.0.internal) and their Makefiles' flags.
  `tools/libtest.py` compiles each source with a cc1 and compares every
  function with the shipped object. With 1.3.1's original cc1 all of them
  are reproduced: libgmo_model 203/203, libgim_picture 70/70 (`-O2
  -std=gnu9x`), libvfpu 251/251, libfpu 41/41, libsha1 3/3, libmt19937 1/1
  (`-O4 -G0`). So 1.4.0.internal is 1.3.1's compiler, like 1.5.0.internal.
- The 1.5.1 tree fails 23 gmo_model, 13 gim_picture and 1 vfpu function
  (`sceVfpuColorToRGB565`), all where 1.4.0 uses `movz`/`movn`, which
  confirms from real sources that the condmove change is new in 1.5.1.
- 1.6.1's and 1.7.1's cc1 differ in `sceGmoBoneLoad` and libsha1, which
  confirms from real sources that 1.6.1's patches are not in 1.4.0.
- `config/compilers.txt` now maps 1.4.0 to `cc1-1.3.1-orig` (it was the
  1.5.1 tree, unconfirmed).
- The sources need newlib's `math.h` and a C99 `stdbool.h`
  (`tmp/sdk/inc`) besides `include/libc` and the devkit's `include/`.

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

- sampler's 1.5.0.internal libraries (libpsmf, psmfBase, libmpeg_util):
  every function has DWARF "declared inline but not inlined"
  (`DW_AT_inline` 2), which 1.3.1's cc1 emits only with
  `-finline-functions`; psmfBase's DWARF also shows helpers inlined into
  later functions. So they were not plain `-O2 -frename-registers`. `-O3`
  with default limits doesn't reproduce the function order, so probably a
  smaller inline limit; the units use `-O2 -frename-registers` with the
  inlined helpers as `static inline` copies.
- Sony's newlib `vfprintf` (sampler) declares `base` as `int` instead of
  the enum and is built with long long support; with that the whole unit
  matches upstream.

## psp-gcc 1.8.3

psp184's mpegon and mpegstr (Sony's mpeg player sample) are built by the
1.8.3 release (`DW_AT_producer` "GNU C 3.3.3+allegrex-2.2.2-psp-1.8.3 -g",
newlib and libgcc from Sony's `psp-gcc_1.8.3`/`psp-newlib_1.8.3` build
trees), one SDK object (`userinterrupt.c`) by 1.8.3.internal.

- **Code generation is 1.7.1's.**  `gcc1.8.3_src` is the reconstructed
  1.7.1 tree with the 1.8.3 version string; what 1.8.3 adds (below) leaves
  no trace in any code we have.  Matching with it: 83 of the 135
  application functions of each module (59 m2c drafts as they are, 20 from
  the UTST99332/UTST99261 player sources, the rest by hand), and 38 of the
  64 newlib/libgcc units from source.  The other newlib units are Sony's
  newer newlib, not the compiler: `_REENT` became a call (`__sread`,
  `printf`, `puts`, `strtol`, the `*_r` wrappers grow by that call),
  `MALLOC_ALIGNMENT` is 16 (`_memalign_r`, `_realloc_r`,
  `malloc_extend_top` differ only in the alignment constants), the
  psp `sys/` files are new.  Near-misses in the player turned out to be
  source changes too (`read_checkConditionEnd` status 3, `dispbuf_show`
  waits through `control_waitDisp`, `DvdUmdRetryReadFile` assigns the
  `DvdUmdRetryOpen` result to `ret` first), and the 1.8.3.internal
  `sceDisplaySetVblankCallback` is built `-O2 -frename-registers` like
  Sony's other libraries.
- **VFPU support in the compiler.**  The DWARF of 1.8.3's libgcc
  (`tools/gcchdr.py mpegon.prx --tree 1.8.3`) shows a mips.h that 1.7.1
  does not have: `enum cmp_type` gains `CMP_V4SF`, `CMP_V16SF` and
  `CMP_V4SF_BUILTIN` (`CMP_MAX` = 7), `enum reg_class` gains `VFPU_REGS`,
  `VFPU_SRAND` and `VFPU_CC` before `ALL_REGS` (28 classes), and `enum
  mips_builtins` grows from 22 to 437 entries:
  `MIPS_BUILTIN_VFPU_<op>_<S|P|T|Q>` with `_PARTIAL` variants for some
  hundred VFPU operations (`VADD`, `VMUL`, `VDOT`, `VCRS`, `VSCL`,
  `VROT`, `VF2IN`, `VI2F`, `VSIN`, `VCMP`, `VMMUL_Q`, `VTFM4_Q`,
  `VMIDT_Q`, ...) and four `MIPS_BUILTIN_VFPU_SUBREG_*` conversions
  between `SF`, `V4SF` and `V16SF`.  Lines: +4 before `cmp_type`, +55
  between `mips_cpu_info` and `reg_class`, +14 before `mips_args`, +39
  before `mips_builtins`.  So 1.8 added vector modes (`V4SF`: a VFPU
  column/row, `V16SF`: a matrix), a VFPU register file and builtins for
  it.  No module here uses it: there is not one VFPU instruction outside
  inline asm in psp184 (the SDK's libgu/libgum still use inline asm or
  plain FPU code), and ordinary float code is unaffected (see 1.8.4).
  Without code that uses the builtins, their implementation (mips.md
  patterns, mips.c expanders, register numbering) cannot be
  reconstructed, so the trees leave it out; the declarations are there
  for whoever finds such code.  `tconfig.h` and the rest of mips.h are
  1.7.1's.
- The 1.8.x newlib line tables are ordinary again (address advances, see
  1.6.1), so no `newlib:locfix`.
- `__psp_gcc__` (0x010803) and the specs file name (`pspspecs_1_8_3`)
  follow the 1.3.1/1.7.1 scheme; no object shows them.

## psp-gcc 1.8.4.internal

UCJS90007 (built against SDK 2.5.0, "release_250") is all
1.8.4.internal: game code, SDK libraries, newlib and libgcc
(`psp-gcc_1.8.4.internal`/`psp-newlib_1.8.4.internal` trees).

- **Code generation is 1.7.1's.**  `gcc1.8.4_src` is `gcc1.8.3_src` with
  the version string "3.3.3+allegrex-2.2.2-psp-1.8.4.internal".  Matching
  with it: 128 of 459 application functions (106 m2c drafts, 18 from the
  1.8.3 player, libgum's `sceGumLoadIdentity`, `sceGumScale` and
  `sceGumTranslate`, float code with Sony's `-O2 -frename-registers`,
  `sceDisplaySetVblankCallback`), and 57 of 93 newlib/libgcc units from
  source, among them the single-float libm (`sinf`, `cosf`, the `kf_*`
  kernels, `__ieee754_rem_pio2f`, `floorf`) and libgcc's soft double.
  Everything else is source-level: the SDK 2.5.0 libgu inlines
  `send_commandi` and libgum composes rotations inline, the newlib is
  1.8.3's.
- **Its mips.h has 22 more lines than 1.8.3's**: `reg_class` at 2160
  (+9) and `mips_builtins` at 4953 (+13 after `CUMULATIVE_ARGS`), the
  same two insertions 1.6.1.internal has over 1.6.1, with no new
  enumerator.  An internal-only addition, content unknown, no effect on
  code.
- Like 1.6.1.internal, units that still mix C and asm need
  `-fno-merge-constants` to keep their float constants in emission order
  with the asm's (`mixed:` in `config/compilers.txt`; libgum).
