#!/usr/bin/env bash
# regen_all.sh: regenerate every config; re-split (keeping hand-written
# files) and rebuild the modules whose config changed.  Log: tmp/regen.log
cd "$(dirname "$0")/.."
: > tmp/regen.log
for tm in $(.venv/bin/python tools/modules.py | tr ' ' ':'); do
  t=${tm%%:*}; m=${tm#*:}
  .venv/bin/python tools/gen_config.py $t $m --force >/dev/null 2>&1 || { echo "$tm CONFIG-FAIL" >> tmp/regen.log; continue; }
  git diff --quiet config/$t/$m.yaml && continue
  if tools/resplit.sh $t $m && make -j${J:-3} TARGET=$t MODULE=$m 2>&1 | tail -1 | grep -q ": OK"; then
    echo "$tm OK" >> tmp/regen.log
  else
    echo "$tm FAIL" >> tmp/regen.log
  fi
done
cat tmp/regen.log
