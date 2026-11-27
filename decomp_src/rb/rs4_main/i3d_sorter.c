#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dSortStrictStable();                      /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
void EntryAscending(int arg0, void *arg1, int arg2) {
    void *temp_v0;
    void *temp_v1;
    void *var_a1;

    var_a1 = arg1;
    if (var_a1 != NULL) {
        do {
            temp_v0 = arg0 + ((((unsigned int) M2C_FIELD(var_a1, unsigned int *, 0) >> arg2) & 0xFF) * 0x10);
            temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
            M2C_FIELD(temp_v0, void **, 0xC) = var_a1;
            M2C_FIELD(temp_v1, void **, 4) = var_a1;
            var_a1 = M2C_FIELD(var_a1, void **, 4);
        } while (var_a1 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void EntryDescending(int arg0, void *arg1, int arg2) {
    void *temp_v0;
    void *temp_v1;
    void *var_a1;

    var_a1 = arg1;
    if (var_a1 != NULL) {
        do {
            temp_v0 = arg0 + ((((unsigned int) ~M2C_FIELD(var_a1, int *, 0) >> arg2) & 0xFF) * 0x10);
            temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
            M2C_FIELD(temp_v0, void **, 0xC) = var_a1;
            M2C_FIELD(temp_v1, void **, 4) = var_a1;
            var_a1 = M2C_FIELD(var_a1, void **, 4);
        } while (var_a1 != NULL);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", RadixSort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", BubbleSort);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dSortNop(int arg0) {
    return arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dSortByOT(void) {
    I3dSortStrictStable();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__Sort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSortStrictStable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__Construct);

int I3dRender__ProcessSortTagCmd_Recursive();
int I3dRender__SortTagCmdProc_Call(void *r, char *t)
{
	I3dRender__ProcessSortTagCmd_Recursive(r, *(void **)(t + 0x10));
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRender__SortTagCmdProc_Ret(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ChangeState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ChangeStateAndSendPacket);

int I3dRender__SortTagCmdProc_ClearState(char *r, char *t)
{
	r += *(int *)(t + 0x10) * 4;
	*(int *)(r + 0x1EC) = 0;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ClearStateAndSendPacket);

int I3dTtyPrintf();
int I3dRender__SortTagCmdProc_LogMsg(void *r, char *t)
{
	I3dTtyPrintf(*(void **)(t + 0x10));
	return 0;
}

int I3dRender__SortTagCmdProc_Callback(void *r, char *t)
{
	return (*(int (**)(void *, void *))(t + 0x10))(*(void **)(t + 0x14), *(void **)(t + 0x18)) != 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__ProcessSortTagCmd_Recursive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__ProcessSortTagCmd);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetCallCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetRetCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetChangeStateCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetChangeStateAndSendPacketCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetClearStateCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetClearStateAndSendPacketCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetLogMsgCmd_ByUint32);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__SetCallbackCmd_ByUint32);

void I3dTexEnv__SetParam(void) {
}

void I3dTexEnv__SetErrorTex(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dCheckTim2FileHeader);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dGetTim2PictureHeader);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dTim2PictureHeader__IsClut2(void *arg0) {
    return M2C_FIELD(arg0, unsigned char *, 0x11) == 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", s_apI3dSortFunc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__GetMipMapPictureSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__Get_pPictureImage);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dTim2PictureHeader__Get_nClut(void *arg0) {
    int var_a1;
    unsigned char temp_v1;

    temp_v1 = M2C_FIELD(arg0, unsigned char *, 0x13);
    var_a1 = 0;
    switch (temp_v1) {                              /* irregular */
    case 5:
        var_a1 = (int) (M2C_FIELD(arg0, unsigned short *, 0xE) + 0xFF) >> 8;
        break;
    case 4:
        var_a1 = (int) (M2C_FIELD(arg0, unsigned short *, 0xE) + 0xF) >> 4;
        break;
    }
    return var_a1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *I3dTim2PictureHeader__Get_pClutImage(void *arg0) {
    void *var_v1;

    var_v1 = NULL;
    if (M2C_FIELD(arg0, unsigned short *, 0xE) != 0) {
        var_v1 = arg0 + M2C_FIELD(arg0, unsigned short *, 0xC) + M2C_FIELD(arg0, int *, 8);
    }
    return var_v1;
}
