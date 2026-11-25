#include "common.h"

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdIoInit);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdIoTerm);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryWaitSemaCB);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryOpen);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", D_00030B1C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", D_00030B30);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryRead);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryOpenCB);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdReadNoRetry);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryReadCB);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", __psp_libinfo___30B80);
