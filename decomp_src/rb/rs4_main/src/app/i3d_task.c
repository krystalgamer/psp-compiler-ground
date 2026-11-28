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

int taskMake(void *, void *, void *, int);
void *i3dTask_EzDraw(void *arg0, unsigned int arg1, int arg2, int arg3);
void *i3dTask_EzModel(void *arg0, unsigned int arg1, void *arg2, int arg3);
extern unsigned char D_000FD5C4, D_000FD608, D_000FD60C;

typedef struct { int a, b, prio; } LsEnt;

void consPrintf(const char *fmt, ...);
int taskDefaultMsg(int task, unsigned int msg, int p1, int p2);
void copUnitMat();
void *resGetDatTable(int a, int b);
int i3dMotSetMotion(void *arg0, int arg1);
void copLetMat();
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_Landscape);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD608);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD60C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD610);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", D_000FD624);

int gameGetGameMode(void);
void *i3dTask_Light(void *arg0, unsigned int arg1, void *arg2, int arg3);
void *i3dTask_WallPaper(void *arg0, unsigned int arg1, void *arg2, int arg3);
void *i3dTask_AiAi(void *arg0, unsigned int arg1, void *arg2, int arg3);
int i3dTask_Stage();
typedef struct { int a, b, c, d; } StageDef;
typedef struct { StageDef s[6]; } StageTbl;
extern const StageTbl D_000FD624;

void *i3dTask_EzDraw(void *arg0, unsigned int arg1, int arg2, int arg3) {
    StageTbl tbl;
    unsigned int i;

    switch (arg1) {
    case 0:
        if (arg0 == NULL) {
            consPrintf(&D_000FD5C4, &D_000FD5E0, 0xA7, "i3dTask_EzDraw", &D_000FD608);
        }
        M2C_FIELD(arg0, int *, 0x28) = 0;
        M2C_FIELD(arg0, signed char *, 0x24) = 0;
        M2C_FIELD(arg0, int *, 0x2C) = 0;
        taskMake(NULL, i3dTask_Light, NULL, 0);
        taskMake(NULL, &i3dTask_View, NULL, 1);
        if (gameGetGameMode() == 1) {
            taskMake(NULL, i3dTask_WallPaper, NULL, 0);
            taskMake(NULL, i3dTask_AiAi, NULL, 0xFF);
        }
        tbl = D_000FD624;
        for (i = 0; i < 6; i++) {
            if (sceKernelGetGPI() & 1) {
                consPrintf("i3dTask_Stage : %d %d %d %d\n", tbl.s[i].a, tbl.s[i].b, tbl.s[i].c, tbl.s[i].d);
            }
            taskMake(NULL, i3dTask_Stage, &tbl.s[i], 0);
        }
        return arg0;
    case 4:
        return arg0;
    case 1:
        return NULL;
    case 2:
        return NULL;
    case 3:
        return NULL;
    default:
        return taskDefaultMsg((int) arg0, arg1, arg2, arg3);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d_task", i3dTask_EzModel);

M2C_UNK copInitAttr(void *);                        /* extern */
M2C_UNK i3dDrawMdl(void *, void *, void *);         /* extern */
M2C_UNK i3dFreeMdl(void *);                         /* extern */
void *i3dMakeMdl(void *);                           /* extern */
M2C_UNK i3dMotAnimate(void *);                      /* extern */
extern unsigned char D_000FD5C4, D_000FD608;
extern unsigned char D_000FD5C4, D_000FD608;
extern unsigned char D_000FD60C;

void *i3dTask_Model(void *arg0, unsigned int arg1, void *arg2, int arg3) {
    void *temp_v0;

    switch (arg1) {
    case 0:
        if (arg0 == NULL) {
            consPrintf(&D_000FD5C4, &D_000FD5E0, 0x125, "i3dTask_Model", &D_000FD608);
        }
        if (arg2 == NULL) {
            consPrintf(&D_000FD5C4, &D_000FD5E0, 0x126, "i3dTask_Model", &D_000FD60C);
        }
        M2C_FIELD(arg0, int *, 0x28) = -1;
        M2C_FIELD(arg0, signed char *, 0x24) = arg3;
        M2C_FIELD(arg0, int *, 0x2C) = 0;
        copUnitMat(arg0 + 0x90);
        copUnitMat(arg0 + 0xD0);
        copInitAttr(arg0 + 0x60);
        temp_v0 = i3dMakeMdl(resGetDatTable(M2C_FIELD(arg2, int *, 0), M2C_FIELD(arg2, int *, 4)));
        if (temp_v0 == NULL) {
            consPrintf(&D_000FD5C4, &D_000FD5E0, 0x137, "i3dTask_Model", "pI3d");
        }
        M2C_FIELD(arg0, void **, 0x30) = temp_v0;
        if (M2C_FIELD(temp_v0, int *, 0x34) != 0) {
            i3dMotSetMotion(temp_v0, 0);
        }
        /* fallthrough */
    case 4:
        return arg0;
    case 1:
        { void *m = M2C_FIELD(arg0, void **, 0x30); M2C_FIELD(arg0, void **, 0x30) = NULL; i3dFreeMdl(m); }
        return NULL;
    case 2:
        i3dMotAnimate(M2C_FIELD(arg0, void **, 0x30));
        copLetMat(arg0 + 0x90, arg0 + 0xD0);
        return NULL;
    case 3:
        i3dDrawMdl(M2C_FIELD(arg0, void **, 0x30), arg0 + 0xD0, arg0 + 0x60);
        return NULL;
    default:
        return taskDefaultMsg((int) arg0, arg1, (int) arg2, (int) arg3);
    }
}

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

typedef struct {
	char pad0[0x24];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	void *anm;
	char pad34[0x60 - 0x34];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} WpTask;
extern WpTask *D_001199D8;
void *resGetDatLocal(int, int);
void *bxAnmInit(void *);
void bxAnmTerm(void *);
int bxAnmExec(void *);
void bxAnmDraw(void *, void *, void *);
int taskKill(void *, int, int);
void *i3dTask_WallPaper(void *arg0, unsigned int arg1, void *arg2, int arg3)
{
	WpTask *Tp = arg0;
	switch (arg1) {
	case 0:
		if (Tp == NULL)
			consPrintf(&D_000FD5C4, &D_000FD5E0, 0x42C, "i3dTask_WallPaper", &D_000FD608);
		if (D_001199D8 != NULL) {
			Tp->anm = NULL;
			taskKill(Tp, 0, 0);
		} else {
			Tp->f28 = -1;
			Tp->f24 = 0;
			Tp->f2C = 0;
			copUnitMat(Tp->m0);
			copUnitMat(Tp->m1);
			copInitAttr(Tp->attr);
			Tp->anm = bxAnmInit(resGetDatLocal(1, 0x190));
			D_001199D8 = Tp;
		}
		return Tp;
	case 4:
		D_001199D8 = D_001199D8 == Tp ? NULL : D_001199D8;
		return Tp;
	case 1:
		if (Tp->anm) {
			bxAnmTerm(Tp->anm);
			Tp->anm = NULL;
		}
		return NULL;
	case 2:
		bxAnmExec(Tp->anm);
		copLetMat(Tp->m0, Tp->m1);
		return NULL;
	case 3:
		bxAnmDraw(Tp->anm, Tp->m1, Tp->attr);
		return NULL;
	default:
		return (void *)taskDefaultMsg((int)arg0, arg1, (int)arg2, arg3);
	}
}

int i3dCameraInit(void) {
    return 1;
}

int i3dCameraTerm(void) {
    return 1;
}

extern unsigned char D_000FD840;
extern char *pCameraNodeTbl[];
int I3rRoot__GetNodeIndexByName(void *, char *);
void copSubVec(void *, void *, void *);
void copNomMat(void *, void *);
void copMulMat(void *, void *, void *);
float tanf(float);
typedef struct { void *root; char *node; } CamArg;
int i3dCameraProc(char *Tp, CamArg *Ap)
{
	float prm[16];
	float mat[4][4];
	float near = 1.0f;
	float far = 20000.0f;
	float aspect = 1.7647059f;
	float fov = 0.7853982f;
	void *root = Ap->root;
	unsigned int i;
	float w, h;
	taskSendProc(Tp, &i3dTask_View, 0x10, (int)prm, 0);
	taskSendProc(Tp, &i3dTask_View, 0x12, (int)mat, 0);
	for (i = 0; i < 6; i++) {
		int idx = I3rRoot__GetNodeIndexByName(root, pCameraNodeTbl[i]);
		char *n;
		if (idx < 0)
			continue;
		n = Ap->node + idx * 64;
		switch (i) {
		default:
			consPrintf(&D_000FD5C4, &D_000FD5E0, 0x497, "i3dCameraProc", &D_000FD840);
			break;
		case 0:
			copLetMat(n, mat);
			break;
		case 1:
			copSubVec(n + 0x30, mat[3], mat[2]);
			copNomMat(mat, mat);
			break;
		case 2:
			near = *(float *)(n + 0x38);
			break;
		case 3:
			far = *(float *)(n + 0x38);
			break;
		case 4:
			aspect = *(float *)(n + 0x30);
			break;
		case 5:
			fov = *(float *)(n + 0x30);
			break;
		}
	}
	w = near * tanf(fov * 0.5f);
	h = w * aspect;
	prm[0] = near;
	prm[1] = far;
	prm[2] = -h;
	prm[3] = h;
	prm[4] = -w;
	prm[5] = w;
	copMulMat(Tp + 0xD0, mat, mat);
	taskSendProc(Tp, &i3dTask_View, 0x11, (int)prm, 0);
	taskSendProc(Tp, &i3dTask_View, 0x13, (int)mat, 0);
	return 1;
}

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

float tanf(float);
void i3dCameraCardBattle(void)
{
	float p[16];
	float w;
	float h;
	float fov;
	taskSendProc(0, &i3dTask_View, 0x10, (int)p, 0);
	p[0] = 50.0f;
	p[1] = 350.0f;
	fov = 0.7853982f;
	w = p[0] * tanf(fov * 0.5f);
	h = w * 1.7647059f;
	p[2] = -h;
	p[3] = h;
	p[4] = -w;
	p[5] = w;
	taskSendProc(0, &i3dTask_View, 0x11, (int)p, 0);
}

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
