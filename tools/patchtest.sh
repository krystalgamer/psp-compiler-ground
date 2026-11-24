#!/usr/bin/env bash
# patchtest.sh BASE_TREE NAME PATCH... : build cc1+libgcc from BASE_TREE with
# the patches applied (tmp/var/NAME), then print the newlib/libgcc scores
# for the TESTS (TARGET:MODULE, default puzzle_bobble:BOOT) with FLAGS.
set -e
cd "$(dirname "$0")/.."
BASE=$1; NAME=$2; shift 2
D=tmp/var/$NAME
mkdir -p tmp/var; rm -rf "$D"; cp -a "$BASE" "$D"
for p in "$@"; do patch -s -p1 -d "$D" < "$p" || { echo "$NAME: patch $p failed"; exit 1; }; done
rm -rf tmp/gccbuild/$NAME
tools/build_gcc.sh $NAME "$D" --libgcc > tmp/var/$NAME.build.log 2>&1 || { echo "$NAME: build failed"; exit 1; }
for t in ${TESTS:-puzzle_bobble:BOOT}; do
  nl=$(.venv/bin/python tools/nltest.py ${t%%:*} ${t#*:} $NAME --flags "${FLAGS:--O2 -g}" | head -1 | awk '{print $2}')
  lg=$(.venv/bin/python tools/objcmp.py ${t%%:*} ${t#*:} tmp/gccbuild/$NAME/gcc-bin/gcc/libgcc.a | tail -1 | awk '{print $2}')
  eh=$(.venv/bin/python tools/objcmp.py ${t%%:*} ${t#*:} tmp/gccbuild/$NAME/gcc-bin/gcc/libgcc/unwind-dw2*.o 2>/dev/null | tail -1 | awk '{print $2}')
  echo "$NAME $t newlib=$nl libgcc=$lg unwind=$eh"
done
