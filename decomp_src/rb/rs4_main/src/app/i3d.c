/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK copLetVec(int, int);                        /* extern */
M2C_UNK copSubVec(int, int, int);                   /* extern */
M2C_UNK copQuatMat(int, int);                       /* extern */
M2C_UNK copSclMat3(int, int, int);                  /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dAsmMotOpt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmMot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmHit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dReleaseImg);

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dReleaseMdl(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dReleaseMot(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dReleaseHit(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmRes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dReleaseRes);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF70);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeMotAssignTbl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFB4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dMakeMdl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD004);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD010);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD01C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD024);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD030);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD03C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD048);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeMdl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD060);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD068);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeMdlEx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dFreeMdl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dImgGetWidth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dImgGetHeight);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dMotTimeAdj);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotTimeAdj);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetMotion);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetMotion);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetMaxTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetSpeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetSpeed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetRate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetRate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetSmooth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetSmooth);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetLoop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeAttach);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dFreeAttach);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttachGetInfo);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD24C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD254);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttach);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDetach);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttachProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeHitAssignTbl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionInitModel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionTermModel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionMakePrim);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD2FC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionFreePrim);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionSetSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionGetSize);

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dCollisionMovePrim(int arg0, int arg1, int arg2) {
    copLetVec(arg1, arg0);
    copSubVec(arg2, arg1, arg0 + 0x10);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionGetInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dTriIntersect);

#ifndef NULL
#define NULL ((void *)0)
#endif
int _i3dBoxIntersect(void) {
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD358);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD368);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD394);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD410);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD434);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD448);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD458);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD46C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD478);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD48C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD500);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD504);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD508);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionCheck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dBeginScene);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dEndScene);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeStage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeView);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dGetRender);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dGetStage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dSetTex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dGetPos2D);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawMdl);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawSprt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawSprtN);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawSprtR);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawImg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dDrawNum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawScore);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dDrawTexCut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawTexCut);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawTexCutEx);

#ifndef NULL
#define NULL ((void *)0)
#endif

void i3dPosture2Mat(int arg0, int arg1) {
    copQuatMat(arg1 + 0x10, arg0);
    copSclMat3(arg0, arg1 + 0x20, arg0);
    copLetVec(arg1, arg0 + 0x30);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dGetNodeIndexByName);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", I3dGetNodeMatPtr);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD540);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD548);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD550);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD558);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD55C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD564);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", AmbientColor);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD58C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5E0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Landscape);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD608);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD60C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD610);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD624);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_EzDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_EzModel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Model);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Stage);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD750);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_View);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD7E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD800);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD810);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_AiAi);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD840);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD848);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Light);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD86C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD874);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD880);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD8A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD8BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_WallPaper);

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dCameraInit(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dCameraTerm(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraGetParam);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraSetParam);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraGetMatrix);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraSetMatrix);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD96C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD97C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD98C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FDA00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dLightInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dLightTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dLightProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initInitSys);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FDA40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FDA48);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initTermSys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initInitApp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initTermApp);
