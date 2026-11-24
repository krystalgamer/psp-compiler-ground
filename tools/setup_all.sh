#!/usr/bin/env bash
# Generate configs, split and verify every module (or those given as
# TARGET:MODULE).  Results in tmp/setup_all.log.
cd "$(dirname "$0")/.."
LOG=tmp/setup_all.log; : > $LOG
if [ $# -eq 0 ]; then set -- $(.venv/bin/python tools/modules.py | tr ' ' ':'); fi
for tm in "$@"; do
  t=${tm%%:*}; m=${tm#*:}
  [ -f config/$t/$m.yaml ] || .venv/bin/python tools/gen_config.py $t $m >/dev/null || { echo "$tm CONFIG-FAIL" >> $LOG; continue; }
  if make split TARGET=$t MODULE=$m > tmp/split.$t.$m.log 2>&1 && make -j4 TARGET=$t MODULE=$m > tmp/build.$t.$m.log 2>&1; then
    echo "$tm OK" >> $LOG; rm -f tmp/split.$t.$m.log tmp/build.$t.$m.log
  else
    echo "$tm FAIL" >> $LOG
  fi
done
sort $LOG | awk '{print $2}' | uniq -c
