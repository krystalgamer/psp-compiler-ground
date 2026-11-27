#include "common.h"

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _read);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _write);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _sys_open);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _open);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _close);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _sys_lseek);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _lseek);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _fstat);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", isatty);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _exit);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _kill);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _getpid);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", free_heap);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _sbrk);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _fork);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _wait);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", clock);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", time);

INCLUDE_ASM("tmp/asm/selfboot/loadexec_test/nonmatchings/kernel_bridge", _gettimeofday);
