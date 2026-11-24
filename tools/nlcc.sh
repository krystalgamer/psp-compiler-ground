#!/usr/bin/env bash
# nlcc.sh CC1 OUT.o SRC [cflags...]: compile a newlib 1.12.0 source file like
# Sony's psp newlib build (headers: the installed psp newlib headers).
set -e
ROOT=$(cd "$(dirname "$0")/.." && pwd)
T=$ROOT/tmp/toolchains; N=$ROOT/tmp/src/newlib-1.12.0/newlib
CC1=$1; OUT=$2; SRC=$3; shift 3
D=$(dirname "$SRC")
"$T/bin/rh9" "$T/psp-gcc-1.3.1/bin/psp-gcc" -E -isystem "$T/psp-gcc-1.3.1/psp/include" -I"$N/libc/include" -I"$D" -I"$N/libc/stdio" -I"$N/libm/common" \
  -D_LANGUAGE_C -U__GNUC_MINOR__ -D__GNUC_MINOR__=3 "$SRC" -o "$OUT.i" ${CPPFLAGS:-}
"$CC1" -quiet -G0 "$@" "$OUT.i" -o "$OUT.s"
"$T/bin/psp-as" -G0 -o "$OUT" "$OUT.s"
