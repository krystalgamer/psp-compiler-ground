/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FEA94;
extern unsigned char D_000FEAB4;
extern unsigned char D_000FEAD0;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEA94);

int ActorGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FEAB4, &D_000FEA94, 0x85, "ActorGetNum", &D_000FEAD0);
    }
    return M2C_FIELD(arg0, int *, 0x80);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEAB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEAD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEAD8);

extern unsigned char D_000FEAD8, D_000FEB10;
unsigned int sceKernelGetGPI(void);
int ActorSetTask(void *s, int idx, int task)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x128) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x80)) {
			M2C_FIELD(s, int **, 0x128)[idx] = task;
			return 1;
		}
		if (sceKernelGetGPI() & 8)
			consPrintf(&D_000FEB10, "ActorSetTask", idx);
		return 0;
	}
	consPrintf(&D_000FEAD8, "ActorSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB10);

extern unsigned char D_000FEAD8, D_000FEB10;
unsigned int sceKernelGetGPI(void);
int ActorGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x128) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x80))
			return M2C_FIELD(s, int **, 0x128)[idx];
		if (sceKernelGetGPI() & 8)
			consPrintf(&D_000FEB10, "ActorGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FEAD8, "ActorGetTask", idx);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorGetVariable);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEC48);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorSetVariable);

int rsvKeyState(void *p, int k);
int ActorRecvMotion(char *a, char *name)
{
	char *m = *(char **)(a + 0x34);
	void *t = *(void **)(m + 4);
	int st;
	char *x;

	if (t == NULL)
		return 0;
	st = rsvKeyState(t, *(int *)(m + 8));
	x = *(char **)(a + 0x38);
	if (sceKernelGetGPI() & 1)
		consPrintf("%s : %s : %d\n", "ActorRecvMotion", name, *(int *)(x + 8));
	switch (st) {
	default:
		return 0;
	case 2:
		*(void **)(m + 4) = NULL;
		*(int *)(m + 8) = 0;
		taskProc(t, 100, a, 0);
		return 1;
	case 3:
	case 4:
		*(void **)(m + 4) = NULL;
		*(int *)(m + 8) = 0;
		return 1;
	}
}

int SequenceExec(void *, int, unsigned int, float);
int ActorScriptRun(char *t)
{
	int *w = *(int **)(t + 0x34);
	int r = 0;
	if (w[3] == 0 && w[4] == 0) {
		w[0] = SequenceExec(t, w[0], *(unsigned short *)(t + 0x40), 0.0f);
		r = 1;
	}
	return r;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FED88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FED90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FED98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDAC);

#ifndef FALSE
#define FALSE 0
#endif
extern const float D_000FF25C, D_000FF260, D_000FF264, D_000FF268, D_000FF26C;
extern char *D_00112390[];
extern unsigned char D_000FEB58;
float tanf(float);
void copLetMat(void *, void *);
void copMulMat(void *, void *, void *);
void copSubVec(void *, void *, void *);
void copNomMat(void *, void *);
int taskSendProc(void *, void *, int, void *, int);
void *i3dTask_View();
int I3rRoot__GetNodeIndexByName(void *, char *);
typedef struct { void *root; char *node; } AcmMdl;
typedef struct { char pad[0x38]; AcmMdl **mdl; char pad3c[0xD0 - 0x3C]; char m1[0x40]; } AcmTask;
int ActorCameraMove(AcmTask *Tp)
{
	float cam[16];
	float mat[4][4];
	AcmMdl *m = *Tp->mdl;
	void *root = m->root;
	float nearz = D_000FF25C;
	float farz = D_000FF260;
	float aspect = D_000FF264;
	float fov = D_000FF268;
	float w, h;
	unsigned int i;
	int n;
	float *node;
	taskSendProc(Tp, i3dTask_View, 0x10, cam, 0);
	taskSendProc(Tp, i3dTask_View, 0x12, mat, 0);
	for (i = 0; i < 6; i++) {
		n = I3rRoot__GetNodeIndexByName(root, D_00112390[i]);
		if (n < 0)
			continue;
		node = (float *)(m->node + n * 64);
		switch (i) {
		default:
			consPrintf(&D_000FEAB4, &D_000FEA94, 0x22F, "ActorCameraMove", &D_000FEB58);
			break;
		case 0:
			copLetMat(node, mat);
			break;
		case 1:
			copSubVec(node + 12, mat[3], mat[2]);
			copNomMat(mat, mat);
			break;
		case 2:
			nearz = node[14];
			break;
		case 3:
			farz = node[14];
			break;
		case 4:
			aspect = node[12];
			break;
		case 5:
			fov = node[12];
			break;
		}
	}
	w = nearz * tanf(fov * D_000FF26C);
	h = w * aspect;
	cam[0] = nearz;
	cam[1] = farz;
	cam[2] = -h;
	cam[3] = h;
	cam[4] = -w;
	cam[5] = w;
	copMulMat(Tp->m1, mat, mat);
	taskSendProc(Tp, i3dTask_View, 0x11, cam, 0);
	taskSendProc(Tp, i3dTask_View, 0x13, mat, 0);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDDC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE00);

extern char *D_001123A8[];
extern const float D_000FF270, D_000FF274, D_000FF278, D_000FF27C, D_000FF280;
void *_memAllocZero(int, const void *, int);
typedef struct { void **mdl; char pad4[0x164 - 4]; int type; float *param; } AliTask;
int ActorLightInit(AliTask *Tp)
{
	void *root = *Tp->mdl;
	int i;
	float *p;
	for (i = 0; i < 4; i++) {
		if (I3rRoot__GetNodeIndexByName(root, D_001123A8[i]) >= 0) {
			if (sceKernelGetGPI() & 1)
				consPrintf("%s : findout : %s\n", "ActorLightInit", D_001123A8[i]);
			break;
		}
	}
	Tp->type = i;
	switch (i) {
	default:
		if (sceKernelGetGPI() & 1)
			consPrintf("%s : undefined\n", "ActorLightInit");
		return 0;
	case 0:
		p = _memAllocZero(0x20, &D_000FEA94, 0x283);
		if (!p)
			consPrintf(&D_000FEAB4, &D_000FEA94, 0x284, "ActorLightInit", "pParam");
		Tp->param = p;
		p[0] = 0;
		p[1] = D_000FF270;
		p[2] = 0;
		p[4] = D_000FF274;
		p[5] = D_000FF274;
		p[6] = D_000FF274;
		p[7] = 0;
		return 1;
	case 1:
		p = _memAllocZero(0x20, &D_000FEA94, 0x292);
		if (!p)
			consPrintf(&D_000FEAB4, &D_000FEA94, 0x293, "ActorLightInit", "pParam");
		Tp->param = p;
		p[0] = 0;
		p[1] = D_000FF270;
		p[2] = 0;
		p[4] = D_000FF274;
		p[5] = D_000FF274;
		p[6] = D_000FF274;
		p[7] = 0;
		return 1;
	case 2:
		p = _memAllocZero(0x40, &D_000FEA94, 0x2A1);
		if (!p)
			consPrintf(&D_000FEAB4, &D_000FEA94, 0x2A2, "ActorLightInit", "pParam");
		Tp->param = p;
		p[0] = 0;
		p[1] = D_000FF270;
		p[2] = 0;
		p[4] = 0;
		p[5] = D_000FF270;
		p[6] = 0;
		p[8] = D_000FF274;
		p[9] = D_000FF274;
		p[10] = D_000FF274;
		p[11] = 0;
		p[12] = D_000FF278;
		p[13] = D_000FF27C;
		return 1;
	case 3:
		p = _memAllocZero(0x10, &D_000FEA94, 0x2B7);
		if (!p)
			consPrintf(&D_000FEAB4, &D_000FEA94, 0x2B8, "ActorLightInit", "pParam");
		Tp->param = p;
		p[0] = D_000FF280;
		p[1] = D_000FF280;
		p[2] = D_000FF280;
		p[3] = D_000FF274;
		return 1;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE58);

extern char *D_001123B8[];
extern const float D_000FF284, D_000FF288;
void copRotVec(void *, void *, void *);
void *i3dTask_Light();
typedef struct { void *root; char *node; } AlmMdl;
typedef struct { AlmMdl *mdl; char pad4[0x164 - 4]; int type; float *param; } AlmEx;
typedef struct { char pad[0x38]; AlmEx *ex; char pad3c[0xD0 - 0x3C]; char m1[0x40]; } AlmTask;
int ActorLightMove(AlmTask *Tp)
{
	float c[4], d[4], p[4], a[4];
	AlmEx *ex = Tp->ex;
	AlmMdl *m = ex->mdl;
	void *root = m->root;
	unsigned int i;
	int n;
	float *node;
	float r, t;
	switch (ex->type) {
	case 0:
		{
		float *q = ex->param;
		d[0] = q[0];
		d[1] = q[1];
		d[2] = q[2];
		c[0] = q[4];
		c[1] = q[5];
		c[2] = q[6];
		}
		break;
	case 1:
		{
		float *q = ex->param;
		p[0] = q[0];
		p[1] = q[1];
		p[2] = q[2];
		c[0] = q[4];
		c[1] = q[5];
		c[2] = q[6];
		}
		break;
	case 2:
		{
		float *q = ex->param;
		p[0] = q[0];
		p[1] = q[1];
		p[2] = q[2];
		d[0] = q[4];
		d[1] = q[5];
		d[2] = q[6];
		c[0] = q[8];
		c[1] = q[9];
		c[2] = q[10];
		a[0] = q[12];
		a[1] = q[13];
		}
		break;
	case 3:
		{
		float *q = ex->param;
		c[0] = q[0];
		c[1] = q[1];
		c[2] = q[2];
		}
		break;
	}
	for (i = 0; i < 4; i++) {
		n = I3rRoot__GetNodeIndexByName(root, D_001123B8[i]);
		if (n < 0)
			continue;
		node = (float *)(m->node + n * 64);
		switch ((int)i) {
		default:
			consPrintf(&D_000FEAB4, &D_000FEA94, 0x324, "ActorLightMove", &D_000FEB58);
			break;
		case 0:
			c[0] = node[12];
			c[1] = node[13];
			c[2] = node[14];
			break;
		case 1:
			d[0] = node[12];
			d[1] = node[13];
			d[2] = node[14];
			break;
		case 2:
			p[0] = node[12];
			p[1] = node[13];
			p[2] = node[14];
			break;
		case 3:
			a[0] = node[12];
			a[1] = node[13];
			a[2] = node[14];
			break;
		}
	}
	copRotVec(Tp->m1, d, d);
	copRotTraVec(Tp->m1, p, p);
	switch (ex->type) {
	case 0:
		{
		float *q = ex->param;
		q[0] = d[0];
		q[1] = d[1];
		q[2] = d[2];
		q[4] = c[0];
		q[5] = c[1];
		q[6] = c[2];
		taskSendProc(Tp, i3dTask_Light, 0x14, q, 0);
		}
		break;
	case 1:
		{
		float *q = ex->param;
		q[0] = p[0];
		q[1] = p[1];
		q[2] = p[2];
		r = a[0] == 0.0f ? D_000FF284 : a[0];
		a[0] = r;
		q[4] = c[0] * (r * r);
		q[5] = c[1] * (r * r);
		q[6] = c[2] * (r * r);
		taskSendProc(Tp, i3dTask_Light, 0x15, ex->param, 0);
		}
		break;
	case 2:
		{
		float *q = ex->param;
		q[0] = p[0];
		q[1] = p[1];
		q[2] = p[2];
		q[4] = d[0];
		q[5] = d[1];
		q[6] = d[2];
		r = a[2] == 0.0f ? D_000FF284 : a[2];
		a[2] = r;
		q[8] = c[0] * (r * r);
		q[9] = c[1] * (r * r);
		q[10] = c[2] * (r * r);
		q[12] = a[0] * D_000FF288;
		q[13] = a[1] * D_000FF288;
		taskSendProc(Tp, i3dTask_Light, 0x16, ex->param, 0);
		}
		break;
	case 3:
		{
		float *q = ex->param;
		q[0] = c[0];
		q[1] = c[1];
		q[2] = c[2];
		taskSendProc(Tp, i3dTask_Light, 0x17, q, 0);
		}
		break;
	}
	return 1;
}

float i3dMotTimeAdj(void *c, int mot, float t, int loop);
void i3dMotUpdate(void *c, int mot, float t, float b, int f);
float I3mRoot__GetMaxTime(void *);
int ActorRecvMotion(char *a, char *name);
typedef struct { void *c; int r4; int mot; int loop; float blend; float time; float spd; float bspd; } AMot;
int ActorMotionMove(char *a)
{
	AMot *m = *(AMot **)(a + 0x38);
	char *c = m->c;
	float max;
	void *root;
	float b;

	if (*(int *)(c + 0x34) != 0) {
		if (m->mot < 0) {
			i3dMotUpdate(c, -1, 0.0f, 0.0f, 1);
		} else {
			m->blend -= m->spd;
			b = 0.0f;
			if (m->blend > 0.0f)
				b = m->blend;
			m->blend = b;
			m->time += m->bspd;
			root = (*(void ***)(c + 0x38))[m->mot];
			max = root != NULL ? I3mRoot__GetMaxTime(root) : 0.0f;
			if (m->time < 0.0f || max <= m->time)
				ActorRecvMotion(a, "Loop Mot");
			m->time = i3dMotTimeAdj(c, m->mot, m->time, m->loop == 0);
			i3dMotUpdate(c, m->mot, m->time, m->blend, 1);
		}
	}
	return 1;
}

int rsvKeyState(void *p, int k);
void copLetMat(void *, void *);
void copSclMat3(void *, void *, void *);
void copMulMat(void *, void *, void *);
void copMulMat3(void *, void *, void *);
void copRotTraVec(void *, void *, void *);
int ActorAttachProc(char *a)
{
	char *m = *(char **)(a + 0x38);
	char *t = *(char **)(m + 0xF0);
	float mat[16];
	float mat2[16];
	char *bone;

	if (t != NULL) {
		if (rsvKeyState(t, *(int *)(m + 0xF4)) != 2) {
			copLetMat(a + 0xD0, a + 0x90);
			*(void **)(m + 0xF0) = NULL;
			*(int *)(m + 0xF4) = 0;
		} else {
			bone = *(char **)(**(char ***)(t + 0x38) + 8) + *(int *)(m + 0xF8) * 64;
			copSclMat3(t + 0xD0, t + 0x60, mat);
			copMulMat(mat, bone, mat);
			copMulMat(t + 0xD0, bone, mat2);
			copMulMat3(mat2, a + 0x90, a + 0xD0);
			copRotTraVec(mat, a + 0xC0, a + 0x100);
			return 1;
		}
	}
	copLetMat(a + 0x90, a + 0xD0);
	return 0;
}

extern int D_001123C8[];
void *ActorGetAvatar(int n)
{
	if (((int *)gameGetCntx())[0x38 / 4] == 9)
		return resGetDatLocal(2, ((int *)resGetPtrTable(2, 5))[n]);
	return resGetDatLocal(2, D_001123C8[n]);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE80);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEED4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEFA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEFB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF158);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF16C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF18C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF1AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF1CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF1EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF20C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF22C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF230);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF234);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF238);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF23C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF240);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF244);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF248);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF24C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF250);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF254);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF258);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF25C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF260);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF264);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF268);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF26C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF270);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF274);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF278);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF27C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF280);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF284);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF288);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF28C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF290);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF294);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF298);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF29C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2B8);
