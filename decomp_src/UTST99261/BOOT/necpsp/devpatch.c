#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", usrKernelIcacheInvalidate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", usrKernelIcacheInvalidateRange);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", PatchAdrs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", UnpatchAdrs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", localNetInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", localNetTerm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", localNetInetInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", localNetInetTerm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", localNetApctlInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", localNetApctlTerm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", DevPatchInit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/necpsp/devpatch", DevPatchTerm);
