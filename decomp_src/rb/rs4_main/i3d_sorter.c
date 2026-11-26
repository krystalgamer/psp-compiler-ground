#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", EntryAscending);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", EntryDescending);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", RadixSort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", BubbleSort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSortNop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSortByOT);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__Sort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSortStrictStable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dSorter__Construct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_Call);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_Ret);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ChangeState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ChangeStateAndSendPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ClearState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_ClearStateAndSendPacket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_LogMsg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dRender__SortTagCmdProc_Callback);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__IsClut2);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", s_apI3dSortFunc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__GetMipMapPictureSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__Get_pPictureImage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__Get_nClut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_sorter", I3dTim2PictureHeader__Get_pClutImage);
