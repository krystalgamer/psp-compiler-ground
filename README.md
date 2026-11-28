# psp-compiler-ground

Reconstructing the psp-gcc 1.5.1, 1.6.1, 1.8.3, 1.8.4.internal, 1.9.2 and 1.11.0
compilers
from PSP modules they built. The decompiled sources in `decomp_src/` are the
tests: each compiler version is right when it turns them back into the
original machine code.

- `inputs/` – the original modules (`151_and_161.zip`, `psp_161_to_184.zip`,
  plus `bigbangbang.prx`, `flowars.prx`, `171_184_htmlviewer.prx`, `umdt.zip`,
  `psp_random_batch.zip` (target `rb`), `navi.zip` (target `navi`: a game's
  psp-gcc 1.11.0 libraries), `tony_libs.zip`, 13 stripped
  1.5.1.internal firmware modules, and `psp_devkit.zip`/`psp_sdk150.zip`/
  `psp_sdk_660.7z`, SDKs with library sources: `tools/libtest.py` compares
  them with the shipped libraries); **not committed**
- `config/` – splat configs, one per module
- `decomp_src/` – decompiled C, per module
- `gcc1.5.1_src/`, `gcc1.6.1_src/` – GCC 3.3.3 trees for psp-gcc 1.5.1 and
  1.6.1; both start from the reconstructed psp-gcc 1.3.1
  (<https://github.com/krystalgamer/psp-gcc-1.3.1>, branch `sony`), since the
  releases are cumulative
- `gcc1.8.3_src/`, `gcc1.8.4_src/` – psp-gcc 1.8.3 and 1.8.4.internal; they
  start from the reconstructed psp-gcc 1.7.1 (`~/psp-gcc-1.7.1`, branch
  `sony`)
- `gcc1.9.2_src/` – psp-gcc 1.9.2: pristine GCC 3.3.6 plus the gcc-3.3.3 →
  `gcc1.8.4_src` patch set, plus what the 1.9.2-built module rb/rs4_main
  proves (FINDINGS.md); `tools/build_gcc.sh VERSION --cxx` also builds cc1plus
- `gcc1.11.0_src/` – psp-gcc 1.11.0: the 1.9.2 tree with the VFPU vector
  registers no longer fixed, as navi's zlib, libpng and libjpeg (built from
  their upstream sources) require (FINDINGS.md)
- `tools/` – helper scripts
- `tmp/` – everything generated (toolchains, splat output, builds); **not
  committed**

The compilers are built the way Sony built them: as 32-bit programs on
Red Hat Linux 9 (gcc 3.2.2).

Library units that are unmodified newlib 1.12.0 sources (`/* upstream:
newlib-1.12.0/... */`) include the original file from `tmp/src`, fetched by
`tools/setup_toolchain.sh`, and are preprocessed like Sony's newlib build
(`tools/nlcpp.sh`). `tools/libsrc.py TARGET MODULE --write` converts the
ones that reproduce; Sony's modified functions stay asm.

Modules without a symbol table (`tony_libs`) get their export and import
names from their NIDs: `tools/nids.py` accepts a name only if the first four
bytes of its SHA-1 are the NID, and keeps the resolved ones in
`config/nids.txt`. Their object boundaries are guessed and documented in
`config/TARGET/files.MODULE.txt`.

A unit with a `/* lang: c++ */` comment is C++: it is preprocessed with the
psp-gcc 1.3.1 release's libstdc++ and newlib headers (`include/cxx` first:
g++'s predefines, 1.6.1's `gthr-psp.h`) and built by `cc1plus-VERSION`.
`#pragma interface` in a unit's header keeps vtables and typeinfo in the
module's data. Without it, cc1plus puts the vtables, typeinfo and type names
of classes without a key function in `.gnu.linkonce.r.*` sections (and their
implicit destructors in `.gnu.linkonce.t.*`): `tools/split.py` links each C++
object's linkonce sections of the symbols in its own `.text`/`.rodata`
ranges (the first copy wins, as in Sony's link), the `.r` ones after its
`.rodata`, with its `.rodata.*` (rb/rs4_main has them right after the
object's strings, in cc1plus's order). With `-O3` cc1plus outputs every function at the end of the
file, so a C++ unit that still has asm includes `cxx/defer_asm.h`, whose
`INCLUDE_ASM` defers the asm the same way. A unit's data can be given to it
with `rodata ADDR UNIT` / `bss ADDR UNIT` lines (and `rodata|bss ADDR -` to
end the range) in `config/TARGET/files.MODULE.txt`; the rest stays asm. A data label marked `size:0xN nosplit` in
`config/TARGET/symbol_addrs.MODULE.txt` is one object: references inside it
become `NAME + offset` (e.g. a double the code loads as two words), and
`gen_config --force` keeps such lines. A `/* srcname: PATH */` comment makes cc1 see
its input as PATH (the original's file name, `tools/cc1name.py`): an object
with no public symbol names its static constructor after it, plus six
letters from `-frandom-seed` (the original's random value, set in `cflags`). `tools/dwarf2cpp.py TARGET MODULE UNIT [--probe FILE]` gives
C++ declarations from a C++ compile unit's DWARF (checking every member
offset with cc1plus), or a class skeleton from the symbol table (vtable
order, bases from typeinfo) for objects without DWARF.
