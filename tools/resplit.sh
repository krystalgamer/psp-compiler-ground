#!/usr/bin/env bash
# resplit.sh TARGET MODULE: split again after a config change.  splat does
# not overwrite existing C files, so the stubs are regenerated and the
# hand-written files (anything that is not purely splat's output) restored.
set -e
cd "$(dirname "$0")/.."
t=$1 m=$2
src=decomp_src/$t/$m save=tmp/resplit/$t/$m
rm -rf "$save"; mkdir -p "$(dirname "$save")"
[ -d "$src" ] && mv "$src" "$save"
make split TARGET=$t MODULE=$m > tmp/resplit/split.log 2>&1 || { cat tmp/resplit/split.log; exit 1; }
[ -d "$save" ] && (cd "$save" && find . -type f) | while read -r f; do
  if [ "${f##*.}" != c ] || grep -qvE '^(#include "common.h"|INCLUDE_ASM\(.*|INCLUDE_RODATA\(.*|[A-Za-z_][^;]*\) \{|\}|)$' "$save/$f"; then
    mkdir -p "$(dirname "$src/$f")"; cp "$save/$f" "$src/$f"
  fi
done
rm -rf "$save"
