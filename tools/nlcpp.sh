#!/usr/bin/env bash
# nlcpp.sh FILE.c: preprocess a decomp_src unit that is an unmodified newlib
# 1.12.0 source ("/* upstream: newlib-1.12.0/newlib/DIR/X.c */") the way
# Sony's psp newlib build did (tools/nlcc.sh), to stdout.
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
T=$ROOT/tmp/toolchains; N=$ROOT/tmp/src/newlib-1.12.0/newlib
SRC=$(readlink -f "$1")
REL=$(grep -oP "upstream: newlib-1\.12\.0/newlib/\K\S+" "$SRC")
D=$(dirname "$N/$REL")
"$T/bin/rh9" "$T/psp-gcc-1.3.1/bin/psp-gcc" -E -isystem "$T/psp-gcc-1.3.1/psp/include" -I"$N" -I"$N/libc/include" -I"$D" \
  -I"$N/libc/stdio" -I"$N/libm/common" -D_LANGUAGE_C -U__GNUC_MINOR__ -D__GNUC_MINOR__=3 "$SRC"
