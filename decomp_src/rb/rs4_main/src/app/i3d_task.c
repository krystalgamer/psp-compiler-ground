/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);
extern unsigned char i3dTask_View;

extern unsigned char i3dTask_View;

extern unsigned char i3dTask_View;

extern unsigned char i3dTask_View;

extern unsigned char D_000FD5E0;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", AmbientColor);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD58C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD5E0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_Landscape);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD608);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD60C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD610);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD624);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_EzDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_EzModel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_Model);

extern unsigned char D_000FD5C4, D_000FD608;
int taskDefaultMsg();
typedef struct { unsigned char b0; char p[3]; int f4; int f8; int fC; } StageArg;
typedef struct { char p[0x24]; unsigned char b24; char p25[3]; int f28; int f2C; char p30[0x10]; int f40; int f44; char p48[8]; float f50; } StageTask;
int i3dMakeStage(int, int, float);
int i3dTask_Stage(StageTask *t, unsigned int msg, StageArg *a, int d)
{
	switch (msg) {
	case 0:
		if (t == NULL)
			consPrintf(&D_000FD5C4, &D_000FD5E0, 0x172, "i3dTask_Stage", &D_000FD608);
		t->f28 = -1;
		t->b24 = a->b0;
		t->f2C = 0;
		t->f50 = a->f4 * 5000;
		t->f40 = a->f8;
		t->f44 = a->fC;
		return (int)t;
	case 1:
	case 2:
		return 0;
	case 4:
		return (int)t;
	case 3:
		i3dMakeStage(t->f40, t->f44, 0.0f);
		return 0;
	default:
		return taskDefaultMsg(t, msg, a, d);
	}
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD750);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_View);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD7E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD800);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD810);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_AiAi);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD840);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD848);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_Light);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD86C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD874);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD880);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD8A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD8BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_WallPaper);

int i3dCameraInit(void) {
    return 1;
}

int i3dCameraTerm(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dCameraProc);

void i3dCameraGetParam(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x10, b, 0);
}

void i3dCameraSetParam(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x11, b, 0);
}

void i3dCameraGetMatrix(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x12, b, 0);
}

void i3dCameraSetMatrix(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x13, b, 0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD96C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD97C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD98C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD9FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FDA00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dCameraCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dLightInit);

int i3dLightTerm(int a, char *p)
{
	int t = *(int *)(p + 0x70);
	*(int *)(p + 0x70) = 0;
	if (t)
		_memFree(t, &D_000FD5E0, 0x577);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dLightProc);
