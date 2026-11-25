#include "common.h"

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_thread_enter);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", sceNetFreeThreadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", func_00001F0C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_get_threadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_lock_threadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_unlock_threadinfo);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_thread_leave);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_get_thread_errno);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_set_thread_errno);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", _sce_pspnet_thread_busycount);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", func_00002300);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/thread", sceNetThreadAbort);
