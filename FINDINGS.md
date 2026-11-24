# Findings

Evidence for each change to the compiler trees, from compiling sources
whose original is known (newlib 1.12.0, libgcc) and comparing with the
modules (`tools/nltest.py`, `tools/objcmp.py`).

## psp-gcc 1.5.1

- **No integer conditional moves (`movn`/`movz`).** UTST99261's newlib
  (built by 1.5.1): with 1.3.1's `ISA_HAS_INT_CONDMOVE` 157 instead of 135
  of 169 functions are identical, e.g. `strchr`, `strcasecmp`, `exit`,
  `_strtod_r`, which 1.5.1 compiled with branches where 1.3.1 and 1.7.1
  use `movz`/`movn`.

## psp-gcc 1.6.1
