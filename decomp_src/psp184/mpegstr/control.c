#include "common.h"

/* declarations recovered from DWARF */
typedef int SceInt32;
typedef void SceVoid;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
typedef int SceUID;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
typedef unsigned int SceUInt32;
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct SceKernelEventFlagInfo;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
struct SceKernelEventFlagInfo { /* size 0x34 */
    SceSize size;
    char name[32];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
};



static void vblankHandler(SceInt32 idx, SceVoid *cookie);
SceInt32 control_getCondition(t_conditionCtrl *pCtrl, SceUInt32 *pPattern);


INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", vblankHandler);

int control_create(t_conditionCtrl *pCtrl) {
    pCtrl->controlFlag = sceKernelCreateEventFlag("controlFlag", 0x200, 0, 0);
    pCtrl->waitFlag = sceKernelCreateEventFlag("waitFlag", 0x200, 0, 0);
    sceDisplaySetVblankCallback(0, vblankHandler, pCtrl);
    return 0;
}

int control_delete(t_conditionCtrl *pCtrl) {
    sceDisplaySetVblankCallback(0, 0, 0);
    sceKernelDeleteEventFlag(pCtrl->controlFlag);
    sceKernelDeleteEventFlag(pCtrl->waitFlag);
    return 0;
}

int control_reset(t_conditionCtrl *pCtrl) {
    sceKernelClearEventFlag(pCtrl->controlFlag, 0);
    sceKernelClearEventFlag(pCtrl->waitFlag, 0);
    return 0;
}

int control_waitDisp(t_conditionCtrl *pCtrl) {
    sceKernelWaitEventFlag(pCtrl->waitFlag, 1, 0x21, 0, 0);
    return 0;
}

int control_waitDecode(t_conditionCtrl *pCtrl) {
    sceKernelWaitEventFlag(pCtrl->waitFlag, 2, 0x21, 0, 0);
    return 0;
}

int control_setCondition(t_conditionCtrl *pCtrl, unsigned int pattern) {
    return sceKernelSetEventFlag(pCtrl->controlFlag);
}

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_getCondition);

int control_waitConditionDispStart(t_conditionCtrl *pCtrl) {
    sceKernelWaitEventFlag(pCtrl->controlFlag, 1, 0, 0, 0);
    return 0;
}

int control_waitConditionSoundStart(t_conditionCtrl *pCtrl) {
    sceKernelWaitEventFlag(pCtrl->controlFlag, 2, 0, 0, 0);
    return 0;
}
