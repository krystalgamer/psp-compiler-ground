# psp-compiler-ground

Reconstructing the psp-gcc 1.5.1 and 1.6.1 compilers from PSP modules they
built. The decompiled sources in `decomp_src/` are the tests: each compiler
version is right when it turns them back into the original machine code.

- `inputs/` – the original modules (`151_and_161.zip`, plus `bigbangbang.prx`); **not committed**
- `config/` – splat configs, one per module
- `decomp_src/` – decompiled C, per module
- `gcc1.5.1_src/`, `gcc1.6.1_src/` – GCC 3.3.3 trees for psp-gcc 1.5.1 and
  1.6.1; both start from the reconstructed psp-gcc 1.3.1
  (<https://github.com/krystalgamer/psp-gcc-1.3.1>, branch `sony`), since the
  releases are cumulative
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
