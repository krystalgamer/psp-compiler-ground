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
- Some modules have no symbols or DWARF but link known open-source
  libraries, e.g. navi's zlib, libpng, libjpeg and OpenSSL.  For those,
  `tools/srccmp.py` compiles the upstream sources and finds each function
  in the module's code.

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

- Resolved: originals keeping a constant in a callee-saved register across
  calls (tony_libs, pspnet_inet `sppp_ipcp_scr`, flowars 284/292) are a
  source form, not a compiler difference: the constant is the argument of a
  static inline helper whose body makes calls before using it
  (`auth_reset(50)` keeps 50 in s0). Written directly or via a local, gcc
  rematerialises it.

- Open candidate (puzzle_bobble `DrawCharcter2`, `DrawCharcterFlip`): a
  float passed both in `$f16` and on the stack is converted into a temporary
  and copied with `mov.s` by every cc1; the original converts straight into
  `$f16`. Several call/temporary forms tried.

- Open candidate (puzzle_bobble `SpriteDrawZoom` no/color, `DrawSprite`
  f0/f1, 1.5.1): two parameters with equal allocation priority get their
  registers the other way round. In the original the later parameter wins
  the tie, in every cc1 (1.3.1-orig..1.8.4) the earlier one does.

- Open candidate (puzzle_bobble `main`, `begin_scene`, maybe `TitleDisp`,
  1.5.1): the original loads float literals in source order through one
  register; every cc1 reverses each pair and interleaves the address loads.

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
  Its gmo_model and gim_picture libraries are SDK revision 1.5.0
  (between devkit 0.6.0's sources and the 6.6.0 SDK's, which marks the
  "1.5.0 and before" lines): material/primitive caches, gmo_math, 16-byte
  rects, `sceGmo*Load` helpers, clz-based pow2.  All their C units match
  with 1.6.1 (gmo_material, gmo_part, gmo_model, gmo_bone, gmo_motion,
  gmo_context, gim_picture, gim_activate, gim_animate), including the
  whole-unit rodata order (constants per object, then jump tables, with
  `__psp_libinfo__` opening gmo_model's and gim_picture's rodata).
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

- flowars' SDK libraries (libgim's nine objects, libgu, libwave) are the
  1.6.1.internal objects psp184/spaceinvaders links (same object sizes, same
  C): its .comment has 13 `1.6.1.internal` strings = crt0, kernel_bridge and
  these 11. All of libgim and all but three functions each of libgu and
  libwave match with the 1.6.1 tree (and 1.7.1-orig, 1.8.4); 1.3.1-orig misses only
  `sceGimPictureActivateTexture` (no branch-likely `bnel` delay-slot fill),
  1.5.1 misses 24, 1.9.2 about 70. Still asm everywhere this
  libgu/libwave revision occurs: `sceGuDepthRange`, `sceGuLight`,
  `sceGuLightSpot` (same diff with every cc1: the original loads the vector
  words before the `lcmd` bytes and computes DepthRange's first command
  before the min/max branch) and libwave's three VAG/PCM block fetchers
  (their 16-byte copies are pointer loops reversed by loop.c, like `wclr`).
  crtbegin/crtend are gcc 3.3.3 crtstuff.c; `memmove`'s gaps are its own
  `-falign-loops=64` alignment.

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

- **C++ (cc1plus-1.6.1, the 1.6.1 tree's cp/ front end).** UTST99332's
  libsupc++ (1.6.1.internal, `-O2`) is the 1.6.1 tree's own source: every
  function of `new_op`, `new_opv`, `del_op`, `del_opv`, `eh_catch`,
  `eh_throw`, `eh_alloc`, `eh_globals`, `eh_terminate`, `eh_exception`,
  `eh_personality` and `tinfo` (76) compiles byte-identically from
  `gcc1.6.1_src/libstdc++-v3/libsupc++/*.cc` (all 14 libsupc++ units of
  demo_duck and demo_harmonic are now these sources; their variables stay
  in the module's data as externs). cc1plus-1.5.1 misses 13 of
  them (`operator new`'s `sz == 0 ? 1 : sz` is `movz` only with 1.6.1:
  1.5.1 needs `-mext` and still differs; `__cxa_throw`,
  `read_encoded_value_with_base`, `__gxx_personality_v0`, 5 `tinfo`
  functions, `get_globals_init_once`). The installed libstdc++ headers of
  the 1.3.1 release are the 1.6.1 tree's except `bits/gthr-default.h`:
  1.6.1.internal's `eh_alloc` locks with `*mutex = sceKernelCpuSuspendIntr()`
  (the 1.6.1/1.7.1 `gcc/gthr-psp.h`), 1.3.1's had semaphore mutexes; C++
  units now get 1.6.1's (`include/cxx/bits/gthr-default.h`).
- C++ inlining decisions are source order, not compiler changes: cc1plus
  (tree-inline.c) marks a callee `DECL_UNINLINABLE` the first time a call
  to it is found uninlinable, e.g. when a function compiled before the
  callee's definition calls it; from then on it is inlined nowhere in the
  unit, later callers included.  So the original `Transform::setIdentity`
  calls `setTranslation`/`setScale` out of line (an earlier caller exists),
  and a public caller in a discarded section reproduces it.  Likewise
  `StateMachine::process` calls `update_internal` because that function is
  a few statements over the inline limit.
- UTST99332's demo C++ (demo_duck's `main.cpp`, demo_harmonic's
  `CityApp.cpp` ranges: ~117 objects each, the same library objects) is
  `-O3 -fno-exceptions` with RTTI: every object's
  `__static_initialization_and_destruction_0` comes first in its .text,
  which cc1plus only does with `-finline-functions` (it then defers every
  function to the end of the file), and constructors that build
  `std::vector`s have no landing pads (WaterPatch's matches only so;
  `-O2 -frename-registers` reproduces small functions but not
  `std::vector`'s inlining in WaterPatch's constructor clones). A unit that
  still has asm functions needs its asm deferred the same way
  (`include/cxx/defer_asm.h`). 1.5.1 builds WaterPatch's constructor too,
  but not `WaterPatch::set_disk` (it uses `movz` for `if (r == 0) r = 1`). 1.6.1's
  `a == b` store-flag (`xor; sltiu`) where 1.5.1 branches makes
  `Date::operator==` 4 bytes shorter: 1.5.1 can't build them.
  No C++ function so far needs a cc1plus change. With ~700 demo functions per
  module in C++ (math, scene, sgl, support library), 1.5.1 differs only in
  `set_disk`, the `operator==`s and `std::_Deque_base<math::matrix>::
  _M_initialize_map` (0x134 vs 0x128), `sh::Vector::eval` (`movz`) and
  `Texture::isPow2`. Inlining at -O3 follows GCC 3.3's
  rules: a function called before its definition is never inlined there,
  and out-of-class members of class templates (weak instances) are never
  auto-inlined (the original calls `t_array<T>::addr()`/`handle::release()`).
  The original calls `textures::Texture::setFiltering` from `linear()`
  where a first draft inlined it: that is the source, not the compiler.
  1.6.1's cp/, tree-inline.c, integrate.c and params.def are identical to
  FSF 3.3.3 (limits 300/600 insns, 10 per statement), and the decision is
  `DECL_NUM_STMTS` of setFiltering after its inline helpers are merged.
  Writing `SetBitField`'s body as three statements (`v = value & mask;
  reg &= ~...; reg |= v << start_bit;`) instead of one expression keeps the
  identical code but puts setFiltering over the limit, so `linear`/
  `nearest` match (adding >= 6 empty statements does the same). The copy
  constructor calling `operator=` is presumably the same effect.
  Template instances: none of the demo's instances appears twice in the
  module, and for all 48 instances that our C++ units emit, the object that
  holds the original copy comes before every other object emitting it: the
  link kept the first `.gnu.linkonce.t` copy, as GNU ld does. Instances sit
  at the end of their object (after `_GLOBAL__D_`), where ld puts linkonce
  sections, so 1.6.1's C++ used linkonce sections like FSF 3.3 (no
  `-fno-implicit-templates`/repository); `tools/split.py` links each C++
  object's own instances (by original address range) after its `.text`.
  Instances in the middle of a unit therefore mark object boundaries that
  the static-initializer split missed (objects without static constructors).
- UTST99332 demo_duck/demo_harmonic's libraries need no compiler change
  either: the 1.6.1 tree's libstdc++ `src/codecvt.cc`, `ctype.cc`, `ios.cc`,
  `locale.cc`, `localename.cc`, `fstream.cc` and `config/io/basic_file_stdio.cc`,
  `config/locale/generic/{c_locale,collate,messages,monetary,numeric,time}_members.cc`
  compile byte-identically with cc1plus-1.6.1 `-O2` (their initialized
  `.data` stays asm), libgcc's `unwind-dw2.c`/`unwind-dw2-fde.c` with
  `-O2 -fexceptions` (not `-fnon-call-exceptions`: that adds 4-8 bytes to
  several functions), newlib's `vfscanf.c` with `WANT_PRINTF_LONG_LONG`
  (like `vfprintf.c`).  Only the units' `.rodata`/`.bss` had to be carved.
- In the demo C++, inline functions of the libstdc++ headers that main.hpp
  includes after its `#pragma interface` are never emitted out of line
  (e.g. stl_tree.h's `_Rb_tree_rebalance`, which scene_Graph's object
  holds): including the header before main.hpp gives the original's copies.
  An inline function defined under `#pragma implementation` or explicitly
  instantiated (`template void deque<T>::push_back(...)`) is no longer
  inlined into the unit's callers; taking its address (a static pointer in
  a discarded section, so no .rodata constant) emits the copy and keeps the
  inlining.

- Divide-by-zero traps can vanish without a flag: in 1.6.1's mips.md the
  trap pattern (`div_trap_normal`) prints nothing when the scheduler linked it
  as an anti-dependence to a previous trap. UTST99332 graphics_picture2
  `draw_objects2` has divisions with and without traps; the source order
  (width/height locals first, the /bpp division, then the two /dbpp ones)
  reproduces exactly which traps survive. Not a patch; a source-order effect.

### SDK 1.50 library sources

The first test of 1.6.1.internal on real sources. SDK 1.50 (`inputs/psp_sdk150.zip`)
ships its runtime libraries next to the sources and Makefiles they were built from.
Every archive says `3.3.3+allegrex-2.2.2-psp-1.6.1.internal` (`.comment`, and
`DW_AT_producer "GNU C ... -g"`). They were built from 2005-02-18 to 2005-04-05 in
`/home/munekis/psp-svn/relkit/trunk/sys/trunk/devkit/src/LIB`.

- **Method.** `tools/libtest.py` with each Makefile's flags and defines.
  New options: `--pspgcc 0x010601` preprocesses the way the driver does (cc1
  itself, the driver's predefines, SDK and release headers as `-isystem`).
  `--member libgum_vfpu.o=libgum.c:USE_VFPU=1` covers the `_vfpu`
  variants. For example:
  `tools/libtest.py SDK/lib/libvfpu.a SDK/src/vfpu --cc1 1.6.1 --pspgcc 0x010601
  --inc SDK/include --flags "-O4 -G0 -g -std=gnu9x"`.
  A scratch script also assembled the `.s` units (cpp, then psp-as) and compared
  more of each object: the whole `.text` with gaps, `.data`/`.rodata*`/`.bss`,
  `.pdr`, `.debug_frame`, the symbol tables and the DWARF DIE tree (tags and names).
- **Result: the 1.6.1 tree builds every function.**

  | library | flags | C functions | asm |
  |---|---|---|---|
  | libgum, libgum_vfpu | `-O4 -G0 -g -std=gnu9x` | 28/28, 28/28 | |
  | libgim_picture | `-O2 -std=gnu9x`, SCEGIM_* | 94/94 | |
  | libgmo_model, libgmo_model_vfpu | `-O2 -std=gnu9x`, SCEGMO_* | 234/238 (238 with the older source), 238/238 | |
  | libvfpu | `-O4 -G0 -g -std=gnu9x` | 267/267 | |
  | libfpu | `-O4 -G0 -g -std=iso9899:1999` | 45/45 | 2/2 |
  | crt0_prx, crt0_elf, kernel_bridge | `-O4 -G0 -g -std=gnu9x` | 2/2, 2/2, 22/22 | |
  | libmd5, libsha1, libmt19937 | `-O4 -G0 -g -std=iso9899:1999` | 4/4, 3/3, 1/1 | 1/1, 2/2, 1/1 |
  | libadler, libbase64 | | | 1/1, 2/2 |
  | libccc | `-O4 -G0 -g -std=iso9899:1999` | 27/27 | |
  | libdeflt | `-O4 -G0 -g -std=iso9899:1999` | 10/10 | 1/1 |

  That is 1009 of 1009 C functions and 10 of 10 asm functions. All the extra
  comparisons give the same bytes except in three places:
  - `__psp_libinfo__`, which is not in the shipped sources (below).
  - crt0_elf's post-link sections (`.psp_lib_mark_` removed, plus psplibgen's
    `.lib.ent`/`.rodata.sceResident`).
  - DWARF declaration lines: the shipped sources and headers are a later revision
    than the one built. For example, psptypes.h's typedefs are 5 lines lower.

  The DIE trees are otherwise identical. So the 1.3.1 release's newlib and gcc
  headers have the same contents that 1.6.1.internal had installed. The `-g`
  objects match with our psp-as filling delay slots across source lines. The
  newlib-only `locfix` assembler behaviour does not apply to the SDK libraries.
- **The only mismatches are a source revision (a).** libgmo_model.a (2005-03-01)
  differs from libgmo_model_vfpu.a (2005-03-15) in `sceGmoMaterialLoad` and
  `sceGmoModelGetMetrics`/`GetMemoryClusterSize`/`GetMemoryClusterSize2`: it
  uses `sltiu` where the source has `slti`. The shipped source has 7 `(int)sizeof(...)`
  casts in those functions. Removing them gives libgmo_model.a 238/238. With
  them, libgmo_model_vfpu.a is 238/238.
- **Assembler (b): the 1.6.1.internal psp-as (binutils `allegrex-2.2.2`).**
  - **Newer VFPU syntax.** `vcmmul.X D,A,B` is the 1.3.1 psp-as's
    `vmmul.X D,B,A`, `vctfmN`/`vchtfm4` are `vtfmN`/`vhtfm4`, and a `W`
    destination-prefix field (plain write) is an empty field. Sources pick these
    forms with `#if __psp_gcc__ > 0x010501` (libvfpu, libgum_vfpu, gmo_math_vfpu).
    `libtest.py` rewrites them before assembling (`vfpu_compat`), and every
    instruction matches.
  - **`ulw` expands to `lwl`/`lwr` by default.** deflate.s's `ulw` (libdeflt's
    Makefile has no `-mulsw`) reproduces `sceDeflateDecompress` only with
    `psp-as -mulsw`. This confirms `as:-mulsw` for 1.6.1.internal from an
    assembler-only source. libsha1's Makefile passes `-mulsw` explicitly; the
    driver hands it to as only when it is given.
- **Compiler (c): none.** 1.7.1-orig, 1.8.3 and 1.8.4 give exactly the same
  results as 1.6.1, so this code does not separate 1.6.1 from later compilers.
  The other cc1s miss only known changes:
  - 1.3.1-orig misses libdeflt's `sceGzipDecompress`, `sceGzipGetInfo` and
    `sceZlibDecompress` (the `-mno-ulsw` default: unaligned header copies). With
    `-mulsw` it misses only `sceGimPictureActivateTexture` (the `bnel` delay-slot
    fill, as in flowars).
  - 1.5.1 misses 23 gim_picture, 23 gmo_model, 4 ccc, `_open`,
    `sceVfpuColorToRGB565` and 7 deflt functions (condmove and `-mno-ulsw`).
  - 1.9.2 misses about 70.

  No tree patch is proposed: there is no difference to explain.
- **`__psp_libinfo__`**: a 24-byte obfuscated library record, local. It is the
  first object in the C units' `.rodata` (`.data` in libgum: not const). It comes from a generated
  `version.h` in the source directory, which the SDK doesn't ship (DWARF file
  table; line 28 in fpu.c's, 42 in libgum.c's). Cut out of the comparison, the
  data sections are byte-identical.
- **Sony's build setup (driver and specs).**
  - `bin/psp-gcc` is a selector script. It runs `$PREFIX/gcc-$PSP_GCC_VERSION/bin/CMD`
    or else the last `/usr/local/psp/gcc-1.x.y` directory.
  - 1.6.1.internal was installed as `/usr/local/psp/gcc-1.6.1.internal`, with
    newlib headers in `psp/include` and gcc's in
    `lib/gcc-lib/psp/3.3.3+allegrex-2.2.2-psp-1.6.1.internal/include`.
  - The SDK lives in `/usr/local/psp/devkit` (`SCE_PSP_SDK_HOME`). The driver
    adds `-isystem /usr/local/psp/devkit/include` (`-nodevkitinc` drops it),
    `-G 0 -march=allegrex -mtune=allegrex`, and as `-G0 -EL -g0 -mabi=eabi`. The
    Makefiles add `-I../../include` (DWARF directory `../../include`).
  - The SDK's `lib/pspspecs` replaces `cpp_unique_options`. It uses
    `%{!std=*:%p}%{std=gnu*:%p}`, so the `-std=iso9899:1999` libraries don't get
    `MIPSEL`/`R3000` (only the reserved forms, `__psp_gcc__` and `__SCE__`).
    Its `*lib:` links `kernel_bridge.o -lc -lkernel` into everything.
  - `-O4` is `-O3`.
  - The SDK libraries keep constant merging (`.rodata.cst4`), unlike
    1.6.1.internal's newlib and libgcc.
  - Our cc1-1.6.1 still identifies itself as `allegrex-2.2.1-psp-1.3.1`
    (version.c). That affects only `.comment` and `.debug_str`. psp.h's driver
    predefine still says `__psp_gcc__=0x010301`, but cc1 doesn't use it.
- SDK 1.50 also has 1.6.1.internal libgu, libwave, libsas, libsndp and libkernel
  (2005-04-05, no sources). They are full objects with symbols and relocations,
  for the still-asm libgu/libwave functions above.

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
  patterns, mips.c expanders) cannot be reconstructed, so the trees
  leave it out; the declarations (all three enums, at the original
  lines: comments stand in for the unknown lines) and the VFPU
  registers (see "210 hard registers" under 1.9.2) are there for
  whoever finds such code.  `tconfig.h` and the rest of mips.h are
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

- UCJS90007's `mpeg_display.c` (SDK mpeg sample code) matches only with
  `-fmove-all-movables` (loop-invariant hoisting of everything movable); the
  module's other units break with it, so it's that object's own build flag,
  not a 1.8.x default. mpegon's `DvdUmdRetryRead` gets close with it too.

## psp-gcc 1.9.2

rb's rs4_main (a retail sampler disc's main.prx) is built by the 1.9.2
release (app code, SDK gim_picture/libwave/libsas, newlib, libgcc,
libsupc++), with SDK libraries (libgu, libgum, libfpu, font, libsha1,
kernel_bridge, userinterrupt) by 1.9.2.internal and one 1.4.0 object.
Its `.comment`/`DW_AT_producer` say "3.3.6+allegrex-2.2.2-psp-1.9.2": the
same Allegrex patch level as 1.6.1/1.7.1 on **gcc-3.3.6**, and its
libgcc/libsupc++ DWARF names `gcc-3.3.6/` paths.

- **`gcc1.9.2_src` is pristine FSF gcc-3.3.6 plus the psp-gcc patch set**
  (the diff from gcc-3.3.3 to `gcc1.8.4_src`).  Every hunk applies; the one
  mips.md hunk that doesn't (`can_delay` "no" for asm statements) is
  already in 3.3.6, so 1.7.1's change was that upstream backport.  The
  libgcc DWARF confirms the base: every `mips.h` declaration line equals
  1.8.3's except `enum mips_builtins`, 21 lines up, exactly gcc-3.3.6's
  shorter `ASM_OUTPUT_ALIGNED_DECL_COMMON` (22 lines become 1).  So
  1.9.2 adds nothing to mips.h before `mips_builtins` (the VFPU
  declarations of 1.8.3 are there, the 1.8.4.internal lines are not).
- **Upstream 3.3.4–3.3.6 changes do show**: SDK libgim_picture's
  `sceGimPictureLoad` (unmodified SDK 6.6.0 gim_picture.c) matches with
  the 1.9.2 tree and not with a 1.8.4 tree that has the `ins` change below
  (`cc1-184ins`, an experiment); its relocation loop `*p++ += base` keeps
  a pointer copy (`addu v1,a0,zero`) because the post-increment of `p` is
  emitted before the store.  That is gcc-3.3.4's PR middle-end/14470
  (expr.c `store_expr` emits only the increments queued while expanding
  the source, `emit_insns_enqueued_after_mark`): the 1.8.4 tree with
  3.3.6's expr.c reproduces it.  The other functions compared (libgum,
  libgu, libfpu, font, the rest of gim_picture) are the same with both;
  the 3.3.3 libgcc2/dp-bit/fp-bit/unwind-dw2 sources still reproduce
  1.9.2's libgcc, and the 3.3.6 libsupc++ (eh_*.cc, tinfo.cc) built by
  `cc1plus-1.9.2` reproduces all 8 C++ units.
- Beyond that expr.c change and the `ins` pattern, nothing else in
  3.3.4–3.3.6 has shown: a 1.8.4 tree with both (`cc1-184ins` with
  3.3.6's expr.c) compiles every C unit of rs4_main (94 units, about
  1,300 functions: newlib, libgcc, SDK libraries, middleware, game code)
  exactly like the 1.9.2 tree.
- **Register ext/ins are on by default** (`-mext` in
  `config/compilers.txt`): 1.9.2's newlib and libgcc use them, and so does
  the SDK's libgim_picture although its Makefile (SDK 6.6.0
  src/gim_picture) passes no `-mext`: gim_metrics, load_bmp, load_tga and
  load_tm2 match only with it.  The libgu/libgum/libfpu Makefiles pass
  `-mext` themselves.
- **210 hard registers (`FIRST_PSEUDO_REGISTER` 210, not 176).**  rs4_main's
  libgcc unwinder (unwind-dw2.c from the 1.9.2 tree's gcc-3.3.6) has
  `_Unwind_Context.reg[211]`, a 211-byte (0xD3) `dwarf_reg_size_table`, and
  `__builtin_init_dwarf_reg_size_table` stores a size for each of 210
  registers (`init_dwarf_reg_size_table` 0x358 bytes: 210 `sb` of 4 plus
  the prologue); demo_duck/harmonic's 1.6.1.internal unwinder has 0xB1 =
  177 bytes, i.e. stock mips' 176.  The stores are 4 at DWARF columns 0-30,
  64 (for `$31`), 32-209: register *i* goes to column *i* (mips'
  `DWARF_FRAME_REGNUM`), so the 34 new registers are at the end, 176-209.
  The sizes say nothing more: `GET_MODE_SIZE (reg_raw_mode[i])` is 4 for
  any register that holds SImode or SFmode (`choose_hard_reg_mode` tries
  integer modes first, then floats, then vectors) and for one that holds
  nothing (the previous register's mode), so 16-byte vector registers that
  also take SFmode store 4 too.  The count of 34 = 32 + 1 + 1 is fixed by
  mips.h's line numbers: 1.8's mips.h has 39 more lines than 1.7.1's
  between `struct mips_args` and `enum mips_builtins`, exactly 34 more
  `REGISTER_NAMES` lines (one per register) plus 5 more
  `DEBUG_REGISTER_NAMES` lines (eight names per line); the +14 between
  `reg_class` and `mips_args` fit `REG_CLASS_NAMES` (+3),
  `REG_CLASS_CONTENTS` (+3) and `REG_ALLOC_ORDER` (+3, 16 per line) plus
  5 unknown lines, and the +55 before `reg_class` hold the new
  `FIXED_REGISTERS`/`CALL_USED_REGISTERS`/`CALL_REALLY_USED_REGISTERS`
  rows and register macros (24 lines here) plus unknown ones.  With the
  three new classes `VFPU_REGS`, `VFPU_SRAND`, `VFPU_CC` that gives the
  layout in the trees (1.8.3, 1.8.4 and 1.9.2, as 1.8.3's mips.h DWARF is
  line for line 1.9.2's): 176-207 are 32 VFPU vector registers
  (`VFPU_REGS`, named `C000`...`C730`, the columns of the eight 4x4
  matrices; SFmode or V4SFmode, a V16SFmode matrix in four), 208 the VFPU
  random number state (`VFPU_SRAND`, `vrnd`), 209 the VFPU condition code
  (`VFPU_CC`, `vcc`), both SImode; all fixed and call-used, no debug
  register number.  The numbering within the 34, the modes and the names
  are a reconstruction.  Nothing allocates them, and code generation is
  unchanged: rs4_main (with the unwind units now plain gcc-3.3.6 source),
  mpegon, mpegstr, UCJS90007 and htmlviewer rebuild identically from
  clean with the new cc1s, and `tools/gcchdr.py` reports no mips.h
  difference for rs4_main (1.9.2), mpegon and mpegstr (1.8.3); for
  UCJS90007 (1.8.4) only the 22 internal lines remain.
- **1.9.2's newlib is a locfix build** like 1.6.1's (`newlib:locfix`):
  `rand` and `powf` match only that way and all 94 C newlib units of
  rs4_main match with it.
- Per-object flags in rs4_main's game build: `network_lobby_message_queue.cc`
  is built with strength reduction on (its loops walk pointers with a
  count-down register: 22/34 functions match with it, 10/34 without), while
  the other game objects need or tolerate `-fno-strength-reduce`; newlib's
  `dtoa` needs `-fno-merge-constants` (its doubles sit between its strings
  and its jump table).
- **An AND that clears one contiguous bit field is `ins rt,$0,pos,size`**,
  the input tied to the output (`andsi3` keeps such a constant;
  `*andsi3_allegrex_ins`).  When combine rebuilds the AND
  (`make_compound_operation` in `simplify_set`) a low mask (2^n-1) still
  becomes a zero_extract, i.e. `ext`: newlib `fabsf` is `ext` (the AND
  feeds the copy into a new pseudo), `isnanf` (`ix &= 0x7fffffff`),
  `finitef` and `copysignf` (`ins` of bit 31 and of bits 0–30) are
  `ins`.  Evidence, all from unmodified sources that no other cc1
  reproduces: newlib `isnanf`, `finitef`, `copysignf`, `fabsf`, the libm
  float kernels (`__ieee754_powf`/`sqrtf`/`rem_pio2f`, `__kernel_*f`,
  `sinf`/`cosf`/`tanf`, `floorf`), `rint`, `_wctomb_r`, `mprec`,
  mallocr's `_free_r`/`_calloc_r`, libgcc fp-bit/dp-bit
  `__pack_*`/`__unpack_*` (24 more newlib/libgcc units from source), the
  SDK libfpu `sceFpuLog*`/`sceFpuExp` (with the duplicated `mfc1` the
  tied operand causes), libsupc++'s `read_encoded_value_with_base`
  (`& ~3`), libgu (12 more functions than without it).  App code has 940
  `ins`, about a third with `$0`.
- rs4_main's own build flags (the game's, not the compiler's): its game
  code (src/app, dev, lib, fw, script, menu_mod) is `-Os` (m2c drafts match
  only with it; `ctrlTrgProc`'s block layout), the middleware (i3d*, sgx*,
  bin_common, libwave, libsas) `-O2`, the SDK libraries as their Makefiles
  say (`-O4`, gim_picture `-O2 -std=gnu9x`).  None of these depends on the
  cc1: 1.6.1 and 1.8.4 give the same code.  The game code is
  `-Os -fno-strength-reduce` (a game Makefile flag, not a compiler change).
  Evidence: two original loops that run exactly once survive
  (`ctrlFlushCtrlDataAll`: `addiu s0,1; beqz s0`; `saveDataInit`: `blez`).
  With strength reduction on, gcc 3.3 deletes a loop whose iteration count
  is 1 (`unroll_loop`, called from `strength_reduce`, n_iterations == 1);
  `for (i = 0; i < 1; i++) r |= f(i);` keeps exactly the original's loop
  only with `-fno-strength-reduce`.  Seven more functions (`ScriptEnumOperand`,
  `_SortCardListGet`, `_CardListDel`, `_ShopCursorInitSet`,
  `databaseAssortNameRefresh`, `salbumCalcKinds`) recompute `base + i*size`
  each iteration; with the flag their natural loops match, while plain
  `-Os` needs contrived shapes (an address in a user variable updated in
  place, a dead copy in an accessor, duplicated counter increments, gotos),
  which were tried and do match, but two `goto` loops plus five odd
  accessors are a less likely source than one flag.  Over the 531 matched
  functions of these units no function needs strength reduction on.
  Pristine gcc-3.3.6's `toplev.c` sets `flag_strength_reduce` for every
  `optimize >= 2`, `-Os` included, and the psp patches don't touch it, so
  the flag is the game's own.
- Everything else that differs is source: SDK 6.6.0 vs the module's SDK
  (struct layouts in libgu and gim_picture, `sceGumMultQuaternion`
  missing), Sony's newer newlib (`_REENT` is `__getreent()`, i.e.
  `__DYNAMIC_REENT__`, as in 1.8.3).
- No VFPU instruction comes from compiled C as far as checked: the VFPU
  code (i3dcs_obb, i3d_collision, i3d_packet_util, ... `lv.q`/`sv.q`/
  `vdot`/`vmmul`) sits in Sony's middleware without DWARF, and the
  libgum/libgu functions with VFPU variants are the `USE_VFPU 0` C ones.
  So the 1.8 VFPU builtins remain unrecovered.  The game's own C++
  (`Ys::Cop::Matrix4x4::Set_Zero`/`Set_Unit`/`Set_Matrix` in ys_cop.cc:
  `vmzero.q`/`vmidt.q`, `lv.q`/`sv.q` at fixed `$a0`/`$a1` offsets) is
  reproduced exactly by `asm volatile` blocks with no operands, i.e. it
  needs no builtin either.
- rs4_main links prebuilt libraries from older psp-gcc releases.  Its
  `.comment` strings are in link order (1.9.2, 1.7.1, 1.4.0,
  1.9.2.internal, 1.3.1, 1.6.1) and its `.lib.ent` names every linked
  archive in order, which assigns them:
  - SCERT (the six `librt*PSP.a`, 53 objects named from their
    `$Header: /projects/rtime/CVS/...` rcsids, ~1,050 functions) is 1.6.1:
    abs as `negu`+`max` (not 1.3.1/1.5.1), `lwl`/`lwr` copies (not
    `-mno-ulsw`), no `ext`/`ins` (not 1.9.2; `reloadMT` keeps its masks in
    registers, which 1.9.2 never does, even with `-mno-ext`).  No SCERT
    function tells 1.6.1 from 1.7.1; 1.6.1 is the string at its link
    position.  Its own sources call `memcpy` out of line at every constant
    size (24–512 bytes) while its SHA1.c inlines a 64-byte one: a
    conflicting `memcpy` declaration in those files, not a library-wide
    `-fno-builtin`.
  - The title key archive `PIPOSARU2SCEJ_11444key_psp.a` is the 1.3.1 object.
  - `i3d_parser_i3c` is exported under i3d_collision_psp.a but linked
    before the i3d_share_psp.a objects, i.e. the copy pulled in from
    i3d_model_psp.a: taken as 1.9.2 (medium confidence; its C compiles the
    same with 1.7.1 and 1.9.2).
  - `i3d_collision_psp.a` (i3d_parser_i3c, i3d_collision, i3dcs_sph_cap,
    i3dcs_obb) is the 1.7.1 object: `(x>>4)&0xf` stays `srl`+`andi`, which
    1.9.2 always makes `ext`.
  - libpspdemo is the 1.4.0 object; sgx*, bin_common and i3d_scissor are
    1.9.2 (their archives use `ext`/`ins`).
- Why the module's VFPU code (2,304 VFPU words in 214 functions; none of
  them in a compile unit with DWARF, and no DWARF unit has a vector type)
  is taken to be inline asm and not output of the 1.8 VFPU builtins:
  values cross FPU -> GPR -> VFPU and back (40 of 48 `mtv` are fed by an
  `mfc1`, 77 of 103 `mfv` feed an `mtc1`), as inline asm `"r"` operands
  force, where VFPU-aware code generation would load the value with one
  `lv.s` from its memory slot; the C between VFPU instructions is control
  flow and loop updates (separate asm statements), not scheduled into
  straight-line VFPU runs; reorg never puts a VFPU instruction into a
  compiler branch's delay slot (those stay `nop` next to VFPU code), and
  the 126 function-final VFPU stores in `jr ra` delay slots are psp-as's
  reorder swap, which it also does for 1.5.1's inline asm. About 180 such
  functions match byte for byte as `asm volatile` blocks, surrounding
  compiler code included.  Some of the round trips are even inside the asm
  text: i3d_collision's `I3dcs_GetSqrDist*` and `I3dQtSlerp` move every
  `vdot` result with `mfv $6,S…; mtc1 $6,%0` (a fixed `$6` and a
  `"$6"` clobber: QtSlerp first copies the pointer that arrived in `$a2`
  to `$v1`), and `I3dViewStatus__ObbClipTest_SkinMeshA` passes 0.5f
  to `mtv` as the integer `0x3f000000` (`lui`), while `I3dQtGetSplineCP`
  passes -1.0f as an `"r"` float (`lwc1` + `mfc1`).  Compiler branches next
  to the asm (`if (i == 0)` after a `vmmul` block) get the last VFPU
  instruction in their delay slot from psp-as's reorder, not from reorg.
  Confidence: medium-high.  A VFPU function with DWARF
  (vector-typed variables) or one whose VFPU code is interleaved with
  scheduled C would reopen it.
- The game's C++ objects keep their float constants with their strings
  and aggregates in one `.rodata` in emission order (ys_fx_fade_cif:
  `"src/ys/ys_object.h"`, two `1.0f`, then the vtable); with this repo's
  link order that needs `-fno-merge-constants` per unit, as for 1.8.4's
  mixed units.  The C++ is `-Os -fno-exceptions` with strength reduction
  per object (counted over each whole object): on in ys_anim_task,
  saru_netlib_controller(_set), network_data_transfer_client,
  saru_network_lobby_menu(_view), vfs_tartefs, vfs_internal, network_lobby,
  network_object_daemon, network_lobby_message_queue and bx/b2a (objects
  whose loops use pointer or down-counting counters); off in the rest.
- Rechecked with much more C (libgu at `-O3`, the game's libxu, 208
  functions of the stripped SCERT network library at `-O2`): all 179 C
  units of rs4_main still compile to the same assembly with `cc1-184ins`
  (3.3.3-based, with the `ins` change and 3.3.6's expr.c) and `cc1-1.9.2`.
  No other 3.3.4–3.3.6 change shows.
- libgu (`-O4` = `-O3`) shows 1.9.2's function output order: functions
  the tree inliner may inline (at most 30 statements, `max-inline-insns-auto`
  300 / 10 per statement) are deferred to the end of the file, the others
  are output where they are defined.  The order is the module's when
  `sceGuDisplay` is short enough to be deferred.  This SDK revision lacks
  `_sceGuSetDebugFontCallback`, `sceGuSetCallback2`,
  `sceGuSignalCall/Ret/DrawSync` and `sceGuClutCopyLoad`, and its
  `initList` sends 0xF0–0xF9.  103 of the 119 functions are C.
  `sceGupClear` (0x94FC8) doesn't match: the depth value and the vertex
  pointer get `$t1`/`$t3` the other way round (and sched2 then orders two
  loads differently).  `cc1-184ins` gives the same code, so it's not
  3.3.4–3.3.6.  Without `-mext` the loads come in the module's order but the
  `ext`s are missing.  The cause is unknown, maybe a source detail as in
  the `REG_FREQ` case below.
- Game code: `cvt.w.s` (7 times; casts give `trunc.w.s`, 165 times) is
  inline asm, since the tree has no `cvt.w.s` pattern (`cardlistCpyTtr2Int32`
  matches with `__asm__ volatile ("cvt.w.s %0, %1" ...)`).  `consPrintf` and
  `drawPrintf` are `void f(const char *, ...)`.  The argument setup after
  a call (`addu a2,v0` before the `%lo` of the format) only matches with
  that prototype.  The m2c guesses (fixed arity, int) don't match.  This
  is source, not compiler.  libxu is built with the game's
  `-Os -fno-strength-reduce`.

## psp-gcc 1.11.0

Target `navi` (`inputs/navi.zip`, a game's modules) has five PRX libraries
whose `.comment` is "3.3.6+allegrex-2.2.2-psp-1.11.0": libz (zlib 1.2.3),
libpng (libpng 1.2.12), libjpeg (IJG jpeg 6b), libblowfish and librsa
(OpenSSL 0.9.6c's blowfish and RSA, from their strings).  They have no
symbols and no DWARF.  Their sources were fetched into `tmp/navi/src`,
compiled with each cc1 and compared function by function by
`tools/srccmp.py`. It finds each compiled function by exact search of the
relocation-masked words, names exports by NID, places the rest between
the exact matches and lists the module code that nothing covers
(`--gaps`).

- **Build flags and configuration (object-wide; the libraries' own
  Makefiles):**
  - zlib: `-O3`.  Function order is gcc 3.3's `-O3` deferral, e.g.
    `deflateInit_` comes after `deflateInit2_`.
  - libpng: `-O3 -funroll-loops` (its makefiles' default).  It links zlib
    `-O3`, newlib's libm (`pow`, `__ieee754_pow`, `sqrt`, `fabs`, `finite`,
    `isnan`, `rint`, `scalbn`, `copysign`, `matherr`: `-O2 -fno-builtin`,
    a locfix build like 1.9.2's newlib) and libgcc's soft double.
  - libjpeg: `-O2`, with configure's `jconfig.h`.  `jmemnobs.c` is replaced
    by Sony's memory manager (user malloc/free hooks), and there is a
    memory source manager (an unknown export).
  - blowfish and RSA: `-O0` with no `ext`/`ins` at all (`-mno-ext`, or no
    `-mext`), and RSA with `-DNO_ERR`.
  - Headers: newlib's with `__DYNAMIC_REENT__` (`stderr` is
    `__getreent()->_stderr`, as in 1.8.3 and later).  The C library itself
    is the firmware's `sceLibc`, imported.
- **Results.**  Every upstream function that is linked matches with the
  1.11.0 tree, using only the flags above:

  | Library | 1.11.0 tree | cc1-1.9.2 | 184ins | 1.8.4 `-mext` |
  |---|---|---|---|---|
  | zlib | 89/89 (+63 in libpng) | 87 | 87 | 84 |
  | libpng | 336/336 | 330 | 328 | 307 |
  | libjpeg | 330/330 | 315 | 314 | 304 |
  | blowfish | 8/8 | 8 | – | – |

  - libgcc from the tree (its libgcc2.c, dp-bit.c and fp-bit.c members,
    preprocessed as `tools/libgcccpp.sh` does, `-O2 -mext`) matches all of libpng's 23 functions, libjpeg's 11 and librsa's 16.
    crtbegin/crtend are the tree's crtstuff.c.  So only the libraries'
    own glue code is not covered: libjpeg's memory manager and source,
    and librsa's Sony `RAND_poll`.
  - RSA: 301 compiled functions match (282 distinct module functions;
    identical getters share one copy).  What is left is source-level:
    - stack.c and lhash.c pass `__LINE__` values one higher (Sony
      edited them);
    - `_dopr` reads `(_ctype_+1)[c]`, the newer ctype.h;
    - `CRYPTO_get_ex_new_index` differs;
    - the `RAND_poll` replacement is probably the 4.0.3 object.
  - 1.8.4 and 1.7.1-orig miss 4 of blowfish's 8 `-O0` functions, which
    1.9.2 matches (the gcc-3.3.6 base again).
  - libpng's `png_do_unshift` and `png_do_read_invert_alpha` and libjpeg's
    `compress_data` match with the 1.9.2 tree but not with `cc1-184ins`
    (gcc 3.3.3 with 3.3.6's expr.c).  compress_data's difference is the
    order of its stack spill slots.  These are more upstream 3.3.4–3.3.6
    changes besides PR14470.
- **The one compiler change: the 32 VFPU vector registers are no longer
  fixed.**  All the functions the 1.9.2 tree misses differ the same way:
  1.11.0 hoists more loop invariants out of large loops.
  - Examples: zlib's `deflate_fast` keeps two table addresses in
    s-registers (1.9.2 keeps one and rebuilds the other with `lui`/`addiu`
    in the loop), and `inflate` keeps the constants 16, 17 and -1 in
    registers.
  - The deciding inequality in loop.c's `move_movables` is
    `threshold * savings * lifetime >= insn_count`, with
    `threshold = 2 * (1 + n_non_fixed_regs)` (half that when the loop has
    a call).  The same formula, with `3 +`, applies in `strength_reduce`.
  - An environment knob added to the threshold (a test tree only) shows
    that the libraries need `n_non_fixed_regs` 32 or 33 higher than 1.9.2's:
    - +16 to +30 still miss zlib's `deflate_fast`;
    - +31 misses libjpeg's `encode_mcu_AC_first`;
    - +32 and +33 match everything;
    - +34 and more break zlib's `send_tree`.
  - 32 is exactly the vector registers 176–207 that 1.8 added.
    `gcc1.11.0_src` clears their `FIXED_REGISTERS` entries, while
    VFPU_SRAND and VFPU_CC stay fixed.  They stay call-used, and no
    pattern moves values into or out of them, so nothing is allocated
    there.  A high-pressure float and integer test compiles exactly as
    with 1.9.2.
  - Why the registers were unfixed: VFPU code generation (the 1.8
    builtins) needs allocatable VFPU registers, so this is presumably part
    of Sony's VFPU work.  The navi libraries contain no VFPU instruction.
  - 1.9.2 is unchanged.  No module built by 1.8.3, 1.8.4 or 1.9.2 tells
    the two thresholds apart: rs4_main's 302 C units and UCJS90007's,
    mpegon's and mpegstr's units compile to the same assembly with
    `cc1-1.9.2` and `cc1-1.11.0`, apart from the version strings in
    `-g` units.  Their loops are too small for the threshold to matter.
    So the change could be as old as 1.8.3, but there is no evidence for
    it before 1.11.0.
  - Confidence: high that the threshold is 32 or 33 registers higher (23
    functions, three libraries, every one of them fixed by the same knob
    value with no losses).  Medium-high that it is the vector registers
    (the only group of 32 that the trees keep fixed besides the COP0/2/3
    registers, which stock gcc fixes too).
- **The `-O0` libraries have no `ext` or `ins`.**  They clear bit fields
  with `lui`/`addiu` and `and`, 30 times in librsa (`& 0xffff0000`,
  `& ~7`, ...).  The 1.9.2 tree with `-mext` would emit `ins rt,$0` there,
  because its `andsi3` keeps such masks.
  - Two explanations fit equally well:
    - the `-O0` objects were built without `-mext`: with `-mno-ext`,
      `cc1-1.9.2` and `cc1-1.11.0` both give 301 RSA functions, against
      294 without it;
    - the expander keeps the mask only when optimizing (`optimize &&` in
      `andsi3`): this gives the same 301.  This form is not in the tree.
  - No `-O0` bit-field code exists to tell them apart, so the tree keeps
    1.9.2's `andsi3`.  A plain `andsi3` (always `force_reg`) is ruled out
    for 1.9.2: it changes rs4_main's `__ieee754_rem_pio2f` scheduling.
- **The other navi modules:**
  - librsa also contains one "4.0.3+allegrex-2.2.3-psp-2.3.1" object,
    probably the `RAND_poll` replacement.
  - libpep is all "4.0.4+allegrex-2.2.3-psp-2.5.3" and has a
    `.gcc_compiled_long32` section.
  - libsmojgb is 4.0.4 plus "3.3.6+allegrex-2.2.2-psp-1.13.0.internal".
    Its libpng, libjpeg and zlib copies do not match 1.11.0 at `-O2`,
    `-O3` or `-O3 -funroll-loops` (at most 50/337 png functions).  They
    are probably the 4.0.4 objects; which code is 1.13.0.internal is open.
  - print_msg:
    - Its game code and runtime are SN Systems ProDG: EDG-style `__0F`
      mangling (`__0FDmsgPc` = `msg(char *)`,
      `__0FKerror_text6Nan_error_code`), `__std__needed_destruction_list`,
      `__snmain` and libsn's `sn_floor`/`sn_log`/`fftoa`.
    - Its crt0, crt0mark and kernel_bridge are psp-gcc 1.12.1.internal
      (DWARF).  The SDK 6.6.0 kernel_bridge.c and crt0mark.c
      (`-O4 -std=gnu9x`) match 26 of its 29 crt0/crt0mark/kernel_bridge
      functions, with 1.9.2 and 1.11.0 alike.  crt0's `_start`, `_main`
      and `_exit` differ (a source revision).
    - Its libgcc (dp-bit, `__udivdi3`) is an old one: no `ext`/`ins`, abs
      as `bltzl`/`negu`, the 1.5.1/1.3.1 trees' code.
  - BOOT is SN Systems C++ (Windows paths `d:/develop/navichu/...`,
    `.cplinit`) with Sony's i3d middleware.  It is stripped and has no
    `.comment`.
  - psmf and libpsmfplayer (`.wos`) are prebuilt SDK modules with the
    newer 0x700000A1 relocation format and no sections.  They were not
    analysed.

## Solved: libgu two-command register tie (stale `REG_FREQ`)

`sceGuTexScale`, `sceGuTexOffset`, `sceGuMorphWeight` and `sceGuLightColor`
(the 1.6.1.internal libgu linked into 58 modules) send two GE command words.
The original gives the first value the other register of a pair (v0/v1 or
a1/a2) than our cc1s did with the obvious source. The real 1.3.1 and 1.7.1
binaries agree with our 1.6.1 on all of libgu, so this is a source shape
and not a compiler patch. It can't be per-object flags either: libgu.c is
one object (one `STT_FILE`).

How it works: local-alloc (`block_alloc`) orders quantities by
`QTY_CMP_PRI = floor_log2(n_refs) * freq / (death - birth)`, with
qty-number order breaking ties. `update_equiv_regs` moves the constant
`(cmd << 24)` right before its `or`, so it always lives for one insn and
gets priority 20000. In TexScale the mfc1 -> srl -> or chain is tied into
one qty: 6 refs, freq 12000, life 14, priority 17142. The constant
therefore takes `$2` first. gcc 3.3's `allocate_reg_life_data` resets
`REG_N_REFS` but never `REG_FREQ` (GCC 3.4 resets it). As a result,
`REG_FREQ` keeps adding up over every life analysis, including references
that combine later deletes. When a user variable is modified in place
before combine folds it, the chain gets extra freq. In TexScale freq goes
12000 -> 16000 and priority 17142 -> 22857. In MorphWeight the chain is
mfc1 -> srl only: freq 8000 -> 12000 and priority 13333 -> exactly 20000,
a tie that goes to the older qty. The chain then takes `$2`. The matching helper is:

    static __inline__ void send_commandf(int cmd, float argument)
    {
    	unsigned int v = *(unsigned int *)&argument;

    	v >>= 8;
    	v &= 0xffffff;
    	send_commandi(cmd, v);
    }

`v >>= 8; send_commandi(cmd, v)` alone fixes TexScale/TexOffset but not
MorphWeight. Forms that put the expression straight into `send_commandi`,
use a local union, or store directly change Specular, LightAtt, Viewport
or SetMatrix. All other libgu functions are unchanged. LightColor masks
`color &= 0xffffff` on entry. In its two-command cases it reads the second
command byte into a local first (`int cmd = lcmd[light].diffuse;`), which
adds the same kind of extra freq. Since `REG_FREQ` depends on references
before combine, register ties in other modules that resist every form may
have the same cause. The puzzle_bobble parameter tie above is one example.
