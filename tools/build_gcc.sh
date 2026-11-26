#!/usr/bin/env bash
# Build cc1 from gcc<VERSION>_src the way Sony built psp-gcc: as a 32-bit
# program, in the Red Hat Linux 9 i386 sandbox with its gcc 3.2.2,
# configured from a sibling directory of the source tree.
#
# Usage: tools/build_gcc.sh VERSION [SRC] [--libgcc] [--cxx]
#   VERSION  e.g. 1.5.1; SRC defaults to gcc<VERSION>_src (VERSION can then
#            be any name, e.g. for experiments)
#   --libgcc also build libgcc (tmp/gccbuild/VERSION/gcc-bin/gcc/libgcc.a)
#   --cxx    also build cc1plus (tmp/toolchains/bin/cc1plus-VERSION)
# Result: tmp/toolchains/bin/cc1-VERSION (runs the i386 cc1 on the host)
#
# Incremental: rerunning after a source change only rebuilds what changed.
set -euo pipefail
cd "$(dirname "$0")/.."
ROOT=$PWD
V=$1
LIBGCC= CXX=
[ "${@: -1}" = --cxx ] && { CXX=1; set -- "${@:1:$(($#-1))}"; }
[ "${@: -1}" = --libgcc ] && { LIBGCC=1; set -- "${@:1:$(($#-1))}"; }
SRC=$(cd "${2:-$ROOT/gcc${V}_src}" && pwd)
T=$ROOT/tmp/toolchains
B=$ROOT/tmp/gccbuild/$V
[ -d "$SRC" ] || { echo "no $SRC" >&2; exit 1; }
[ -x "$T/bin/rh9" ] || tools/setup_toolchain.sh

mkdir -p "$B/gcc-bin"
ln -sfn "$SRC" "$B/gcc-3.3.3"
if [ ! -f "$B/gcc-bin/config.status" ]; then
  # Generated files that ship with the sources must look newer than their
  # sources, or make tries to regenerate them.
  (cd "$SRC" && find . \( -name '*.gmo' -o -name '*.info' -o -name '*.info-[0-9]*' \
      -o -name configure -o -name aclocal.m4 -o -name config.in -o -name Makefile.in \
      -o -name c-parse.c -o -name c-parse.y -o -name '*.pot' \) -exec touch {} +)
  "$T/bin/rh9" sh -c "cd $B/gcc-bin && ../gcc-3.3.3/configure --target=psp \
    --prefix=/usr/local/psp/gcc-$V --with-gnu-ld --with-gnu-as \
    --enable-languages=c,c++ --enable-c-mbchar --enable-threads=psp \
    --enable-cxx-flags=-D_IN_GCC_LIB > configure.log 2>&1"
fi
"$T/bin/rh9" sh -c "cd $B/gcc-bin && make all-build-libiberty all-libiberty > make.log 2>&1 \
  && make -C gcc cc1 CFLAGS='-g -O2' >> make.log 2>&1" \
  || { echo "build failed, see $B/gcc-bin/make.log" >&2; tail -20 "$B/gcc-bin/make.log" >&2; exit 1; }
if [ -n "$LIBGCC" ]; then
  # libgcc's objects don't depend on headers such as gthr-psp.h
  rm -rf "$B/gcc-bin/gcc/libgcc" "$B/gcc-bin/gcc/libgcc.a" "$B/gcc-bin/gcc/stmp-multilib"
  RH9_PSP=$V "$T/bin/rh9" sh -c "cd $B/gcc-bin && make all-gcc > make-all.log 2>&1" \
    || { echo "libgcc build failed, see $B/gcc-bin/make-all.log" >&2; exit 1; }
fi
"$T/bin/rh9" strip -g -o "$T/bin/cc1-$V.bin" "$B/gcc-bin/gcc/cc1"
printf '#!/bin/sh\nexec "%s/bin/run32" "%s/bin/cc1-%s.bin" "$@"\n' "$T" "$T" "$V" > "$T/bin/cc1-$V"
chmod +x "$T/bin/cc1-$V"
echo "$T/bin/cc1-$V"
if [ -n "$CXX" ]; then
  "$T/bin/rh9" sh -c "cd $B/gcc-bin && make -C gcc cc1plus CFLAGS='-g -O2' > make-cp.log 2>&1" \
    || { echo "cc1plus build failed, see $B/gcc-bin/make-cp.log" >&2; exit 1; }
  "$T/bin/rh9" strip -g -o "$T/bin/cc1plus-$V.bin" "$B/gcc-bin/gcc/cc1plus"
  printf '#!/bin/sh\nexec "%s/bin/run32" "%s/bin/cc1plus-%s.bin" "$@"\n' "$T" "$T" "$V" > "$T/bin/cc1plus-$V"
  chmod +x "$T/bin/cc1plus-$V"
  echo "$T/bin/cc1plus-$V"
fi
