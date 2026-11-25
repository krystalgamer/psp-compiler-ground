#!/usr/bin/env bash
# libgcccpp.sh FILE.c: preprocess a decomp_src libgcc unit ("/* upstream:
# libgcc ... tree: VERSION */", the L_* defines, #include of libgcc2.c or the
# generated dp-bit.c/fp-bit.c) like the libgcc build of that gcc tree
# (tools/build_gcc.sh), to stdout.
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
T=$ROOT/tmp/toolchains
SRC=$(readlink -f "$1")
V=$(grep -oP "upstream: libgcc.*tree: \K[\w.]+" "$SRC")
B=$ROOT/tmp/gccbuild/$V/gcc-bin/gcc; S=$ROOT/gcc${V}_src/gcc
"$T/bin/rh9" "$T/psp-gcc-1.3.1/bin/psp-gcc" -E -isystem "$B/include" -DIN_GCC -DCROSS_COMPILE -D_IN_GCC_LIB \
  -DHAVE_GTHR_DEFAULT -DIN_LIBGCC2 -D__GCC_FLOAT_NOT_NEEDED -Dinhibit_libc \
  -I"$B" -I"$S" -I"$S/config" -I"$S/../include" -U__GNUC_MINOR__ -D__GNUC_MINOR__=3 "$SRC"
