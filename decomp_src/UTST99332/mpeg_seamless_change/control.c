#include "common.h"

/* declarations recovered from DWARF */
struct t_conditionCtrl;
typedef int SceUID;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
typedef int SceInt32;
typedef unsigned int SceUInt32;
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
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;



SceInt32 control_getCondition(t_conditionCtrl *pCtrl, SceUInt32 *pPattern);


int control_create(t_conditionCtrl *pCtrl) {
    pCtrl->control_flag = sceKernelCreateEventFlag("control_flag", 0x200, 0, 0);
    return 0;
}

int control_delete(t_conditionCtrl *pCtrl) {
    return sceKernelDeleteEventFlag(pCtrl->control_flag);
}

int control_reset(t_conditionCtrl *pCtrl) {
    return sceKernelClearEventFlag(pCtrl->control_flag, 0);
}

int control_setCondition(t_conditionCtrl *pCtrl, unsigned int pattern) {
    return sceKernelSetEventFlag(pCtrl->control_flag);
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/control", control_getCondition);

int control_waitConditionDispStart(t_conditionCtrl *pCtrl) {
    sceKernelWaitEventFlag(pCtrl->control_flag, 1, 0, 0, 0);
    return 0;
}

int control_waitConditionSoundStart(t_conditionCtrl *pCtrl) {
    sceKernelWaitEventFlag(pCtrl->control_flag, 2, 0, 0, 0);
    return 0;
}
