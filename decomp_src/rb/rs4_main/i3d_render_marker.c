/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
int I3dPkDrawSphereMarkerA(int, int, int, int, float); /* extern */
int I3dPkDrawBoxMarkerA(int, int, int, int, int, int); /* extern */
int I3dPkDrawObbMarkerA(int, int, int, int, int);   /* extern */
int I3dSorter__ClosePacketAndClearStateUca();
M2C_UNK I3dSorter__OpenPacketAndClearState_ByUint32(int, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK I3dSorter__OpenPacketAndClearStateUca_ByUint32(int, M2C_UNK, M2C_UNK); /* extern */


unsigned int *I3dPkSendViewStatus();
unsigned int *I3dPkSendFogStatus();
unsigned int *I3dPkSetPixelBlend();
int I3dRenderStage__SetCurrentPacketEntry(char *st, char *e);
int I3dRenderStage__GetDefaultPacketEntry(void *arg0);
void I3dRenderStage__ClosePacketUca(void *arg0, int p);
int I3dRenderStage__OpenPacketUca_ByUint32(char *st, unsigned int n);
int I3dSorter__ClosePacketAndClearState(void *arg0, int arg1);
unsigned int *SendDefaultStatus(unsigned int *p, void *st)
{
	p = I3dPkSendViewStatus(p, st);
	p = I3dPkSendFogStatus(p, st);
	p = I3dPkSetPixelBlend(p, 2);
	*p++ = 0x22000000;
	return p;
}

void I3dVecCopyA(float *, const float *);
void *I3dMatGetUnitPtrA(void);
unsigned int *I3dPkDrawScissorLineStripFA(unsigned int *, char *, const void *, int, int, float (*)[4], const int *);
int I3dRenderStage__DrawLineA(char *st, float *a, float *b, int col)
{
	unsigned int *p;
	float v[2][4];
	I3dRenderStage__SetCurrentPacketEntry(st, (char *)I3dRenderStage__GetDefaultPacketEntry(st));
	p = SendDefaultStatus((unsigned int *)I3dRenderStage__OpenPacketUca_ByUint32(st, 0), st);
	I3dVecCopyA(v[0], a);
	I3dVecCopyA(v[1], b);
	p = I3dPkDrawScissorLineStripFA(p, st, I3dMatGetUnitPtrA(), 2, col, v, 0);
	I3dRenderStage__ClosePacketUca(st, (int)p);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderStage__DrawSphereMarkerA(int arg0, int arg1, int arg2, float fparg0) {
    I3dRenderStage__SetCurrentPacketEntry(arg0, I3dRenderStage__GetDefaultPacketEntry(arg0));
    I3dRenderStage__ClosePacketUca(arg0, I3dPkDrawSphereMarkerA(SendDefaultStatus(I3dRenderStage__OpenPacketUca_ByUint32(arg0, 0), arg0), arg0, arg1, arg2, fparg0));
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderStage__DrawBoxMarkerA(int arg0, int arg1, int arg2, int arg3, int arg4) {
    I3dRenderStage__SetCurrentPacketEntry(arg0, I3dRenderStage__GetDefaultPacketEntry(arg0));
    I3dRenderStage__ClosePacketUca(arg0, I3dPkDrawBoxMarkerA(SendDefaultStatus(I3dRenderStage__OpenPacketUca_ByUint32(arg0, 0), arg0), arg0, arg1, arg2, arg3, arg4));
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dRenderStage__DrawObbMarkerA(int arg0, int arg1, int arg2, int arg3) {
    I3dRenderStage__SetCurrentPacketEntry(arg0, I3dRenderStage__GetDefaultPacketEntry(arg0));
    I3dRenderStage__ClosePacketUca(arg0, I3dPkDrawObbMarkerA(SendDefaultStatus(I3dRenderStage__OpenPacketUca_ByUint32(arg0, 0), arg0), arg0, arg1, arg2, arg3));
    return 0;
}

int I3dRenderStage__SetCurrentPacketEntry(char *st, char *e)
{
	*(void **)(st + 0x828) = e;
	*(void **)(st + 0x818) = *(void **)(e + 0xC);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetCurrentLightStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x82C) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetCurrentFogStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x830) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetCurrentViewStatus(void *arg0, int arg1) {
    M2C_FIELD(arg0, int *, 0x834) = arg1;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetDefaultPacketEntry(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x824);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentPacketEntry(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x828);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentLightStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x82C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentFogStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x830);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetCurrentViewStatus(void *arg0) {
    return M2C_FIELD(arg0, int *, 0x834);
}

int I3dSorter__OpenPacketAndClearState_ByUint32();
int I3dRenderStage__OpenPacket(char *st, float z)
{
	union { float f; int i; } u;
	u.f = z;
	return I3dSorter__OpenPacketAndClearState_ByUint32(*(void **)(st + 0x818), u.i ^ ((u.i >> 31) | 0x80000000), 0);
}

int I3dSorter__OpenPacketAndClearState_ByUint32();
int I3dRenderStage__OpenPacket_ByUint32(char *st, unsigned int n)
{
	return I3dSorter__OpenPacketAndClearState_ByUint32(*(void **)(st + 0x818), n, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__ClosePacket(void *arg0, int p) {
    I3dSorter__ClosePacketAndClearState(M2C_FIELD(arg0, int *, 0x818), p);
}

int I3dSorter__OpenPacketAndClearStateUca_ByUint32();
int I3dRenderStage__OpenPacketUca(char *st, float z)
{
	union { float f; int i; } u;
	u.f = z;
	return I3dSorter__OpenPacketAndClearStateUca_ByUint32(*(void **)(st + 0x818), u.i ^ ((u.i >> 31) | 0x80000000), 0);
}

int I3dSorter__OpenPacketAndClearStateUca_ByUint32();
int I3dRenderStage__OpenPacketUca_ByUint32(char *st, unsigned int n)
{
	return I3dSorter__OpenPacketAndClearStateUca_ByUint32(*(void **)(st + 0x818), n, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__ClosePacketUca(void *arg0, int p) {
    I3dSorter__ClosePacketAndClearStateUca(M2C_FIELD(arg0, int *, 0x818), p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenInitPacket(void *arg0) {
    I3dSorter__OpenPacketAndClearState_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseInitPacket(void *arg0, int p) {
    I3dSorter__ClosePacketAndClearState(M2C_FIELD(arg0, int *, 0x81C), p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenInitPacketUca(void *arg0) {
    I3dSorter__OpenPacketAndClearStateUca_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseInitPacketUca(void *arg0, int p) {
    I3dSorter__ClosePacketAndClearStateUca(M2C_FIELD(arg0, int *, 0x81C), p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenTermPacket(void *arg0) {
    I3dSorter__OpenPacketAndClearState_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 2, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseTermPacket(void *arg0, int p) {
    I3dSorter__ClosePacketAndClearState(M2C_FIELD(arg0, int *, 0x81C), p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__OpenTermPacketUca(void *arg0) {
    I3dSorter__OpenPacketAndClearStateUca_ByUint32(M2C_FIELD(arg0, int *, 0x81C), 2, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dRenderStage__CloseTermPacketUca(void *arg0, int p) {
    I3dSorter__ClosePacketAndClearStateUca(M2C_FIELD(arg0, int *, 0x81C), p);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetMasterRegValue(int arg0, int arg1, int arg2) {
    M2C_FIELD(((arg1 * 8) + arg0), int *, 0x838) = arg2;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__SetMasterRegMask(int arg0, int arg1, int arg2) {
    M2C_FIELD(((arg1 * 8) + arg0), int *, 0x83C) = arg2;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetMasterRegValue(int arg0, int arg1) {
    return M2C_FIELD(((arg1 * 8) + arg0), int *, 0x838);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dRenderStage__GetMasterRegMask(int arg0, int arg1) {
    return M2C_FIELD(((arg1 * 8) + arg0), int *, 0x83C);
}

typedef struct { float z; int *tbl; unsigned int n; int a, b, c; } PkEntPrm;
typedef struct I3dRSt { int tag[3]; int *last; int num; int *bucket[256]; int b2[256]; int render; int s818, s81C, s820, def, cur, light, fog, view; int reg[256][2]; } I3dRSt;
int *I3dRenderStage__CreatePacketEntry(I3dRSt *rs, PkEntPrm *prm);
int *I3dRenderStage__CreatePacketEntry_FromMaterial(I3dRSt *rs, char **m, char *ofs)
{
	PkEntPrm prm;
	int tbl[16];
	unsigned int n = 0;
	unsigned int i;
	char *t = m[2];
	unsigned int cnt = (*(unsigned int *)(t + 4) << 8) >> 8;
	char *e;
	char *mat = m[0];
	if (cnt != 0) {
		char *end;
		e = *(char **)(t + 8);
		end = e + cnt * 16;
		do {
		int v = *(int *)(*(char **)e + 0x1C);
		e += 16;
		if (v != -1) tbl[n++] = v;
		} while (e != end);
	}
	prm.z = *(float *)mat;
	prm.tbl = tbl;
	prm.n = n;
	prm.a = ((unsigned char *)mat)[0xA];
	prm.b = ((unsigned char *)mat)[0xB];
	prm.c = *(int *)(mat + 4);
	if (ofs != NULL) prm.z = prm.z + *(float *)(ofs + 0x20);
	return I3dRenderStage__CreatePacketEntry(rs, &prm);
}

int *I3dRender__ReserveTrashQwc(int, int);
void I3dPacketEntry__Construct(int *e, I3dRSt *rs, PkEntPrm *prm, unsigned int h);
void I3dPacketEntry__InsertLruPrev(void *arg0, void *arg1);
void I3dPacketEntry__MoveLruPrev(void *arg0, void *arg1);
int *I3dRenderStage__CreatePacketEntry(I3dRSt *rs, PkEntPrm *prm)
{
	unsigned int h, idx;
	unsigned int i, j;
	int *t;
	int *head, *e, *ne, *p, *last;
	int key;
	int *et;
	unsigned int n;
	n = prm->n;
	h = *(int *)&prm->z + n + prm->a + prm->b + prm->c;
	t = prm->tbl;
	for (j = 0; j < prm->n; j++) h += t[j];
	h += h >> 16;
	h += h >> 8;
	idx = h & 0xFF;
	head = rs->bucket[idx];
	if (head != NULL) {
		e = head;
		do {
			if (h == e[0] && *(float *)&e[8] == prm->z && e[10] == prm->n && e[11] == prm->a && e[12] == prm->b && e[13] == prm->c) {
				et = (int *)e[9];
				for (i = 0; i < prm->n; i++)
					if (et[i] != prm->tbl[i]) goto next;
				if (e != head) {
					I3dPacketEntry__MoveLruPrev(e, head);
					rs->bucket[idx] = e;
				}
				return e;
			}
		next:
			e = (int *)e[1];
		} while (e != head);
	}
	ne = I3dRender__ReserveTrashQwc(rs->render, 4);
	I3dPacketEntry__Construct(ne, rs, prm, h);
	if (head != NULL) I3dPacketEntry__InsertLruPrev(ne, head);
	rs->bucket[idx] = ne;
	p = I3dRender__ReserveTrashQwc(rs->render, 1);
	last = rs->last;
	key = *(int *)&prm->z;
	p[0] = key ^ ((key >> 31) | 0x80000000);
	last[1] = (int)p;
	p[2] = (int)ne;
	rs->last = p;
	rs->num++;
	return ne;
}

int *I3dRender__ReserveTrashQwc(int, int);
void *I3dRender__CreateSorter(void *r, int a, int b, int c);
void I3dSorter__SetCallCmd_ByUint32(int *s, unsigned int key, int arg);
int I3dRenderStage__Construct(int *, int);
int *I3dRenderStage__CreateRenderStage(int *rs, float z)
{
	int *ns;
	union { float f; int i; } u;
	if (rs[0x820 / 4] == 0) {
		rs[0x820 / 4] = (int)I3dRender__CreateSorter((void *)rs[0x814 / 4], 1, 1, 0);
		I3dSorter__SetCallCmd_ByUint32((int *)rs[0x81C / 4], 3, rs[0x820 / 4]);
	}
	ns = I3dRender__ReserveTrashQwc(rs[0x814 / 4], 0x104);
	I3dRenderStage__Construct(ns, rs[0x814 / 4]);
	u.f = z;
	I3dSorter__SetCallCmd_ByUint32((int *)rs[0x820 / 4], u.i ^ ((u.i >> 31) | 0x80000000), ns[0x81C / 4]);
	return ns;
}

int *I3dRender__ReserveTrashQwc(int, int);
int I3dRenderStage__InitTexCache(int *rs, float z)
{
    int *p = I3dRender__ReserveTrashQwc(rs[0x814 / 4], 1);
    int *last = (int *)rs[3];
    union { float f; int i; } u;
    u.f = z;
    p[0] = u.i ^ ((u.i >> 31) | 0x80000000);
    last[1] = (int)p;
    p[2] = 0;
    rs[3] = (int)p;
    rs[4]++;
    return 0;
}

void *I3dRender__CreateSorter(void *r, int a, int b, int c);
void I3dSorter__SetCallbackCmd_ByUint32(void *s, unsigned int key, void *fn, void *arg, int x);
void I3dPacketEntryParam__Clear(void *);
int I3dRenderStage__CallPacketEntry();
int I3dRenderStage__Construct(int *rs, int r)
{
	int *s = I3dRender__CreateSorter((void *)r, 1, 1, 0);
	unsigned int i;
	int *e;
	int prm[6];
	I3dSortTag__ConstructAsHead(rs);
	rs[4] = 0;
	for (i = 0; i < 0x100; i++) rs[5 + i] = 0;
	for (i = 0; i < 0x100; i++) rs[0x105 + i] = 0;
	rs[0x814 / 4] = r;
	rs[0x81C / 4] = (int)s;
	rs[0x820 / 4] = 0;
	rs[0x828 / 4] = 0;
	rs[0x82C / 4] = 0;
	rs[0x830 / 4] = 0;
	rs[0x834 / 4] = 0;
	for (i = 0; i < 0x100; i++) {
		rs[0x838 / 4 + i * 2] = 0;
		rs[0x83C / 4 + i * 2] = 0;
	}
	I3dSorter__SetCallbackCmd_ByUint32(s, 1, I3dRenderStage__CallPacketEntry, rs, 0);
	I3dPacketEntryParam__Clear(prm);
	prm[0] = 0;
	prm[1] = 0;
	prm[2] = 0;
	prm[3] = 0;
	prm[4] = 0;
	prm[5] = 0;
	e = I3dRenderStage__CreatePacketEntry((I3dRSt *)rs, (PkEntPrm *)prm);
	rs[0x824 / 4] = (int)e;
	rs[0x828 / 4] = (int)e;
	rs[0x818 / 4] = e[3];
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dRenderStage__DrawStrip);

void I3dSortTag__ConstructAsHead(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = (int)t;
}

int I3dSorter__OpenPacket_ByUint32(int *s, unsigned int key)
{
	int *rd = (int *)s[4];
	int *c;
	int *t;
	int p;
	c = (int *)rd[0xF8 / 4];
	c -= 4;
	rd[0xF8 / 4] = (int)c;
	s[8] = (int)c;
	p = (rd[0xF4 / 4] + 0x7F) & 0x3FFFFF80;
	t = (int *)s[3];
	c[0] = key;
	t[1] = (int)c;
	c[2] = p;
	s[3] = (int)c;
	s[9]++;
	return p;
}

typedef struct { char p0[0x10]; char *rd; char p1[0xC]; char *cur; char p2[4]; int used; } SorterP;
int I3dSorter__ClosePacket(SorterP *s, char *end)
{
	char *c = s->cur;
	s->used += end - *(char **)(c + 0x8);
	*(char **)(c + 0xC) = end;
	*(unsigned int *)(s->rd + 0xF4) = (((unsigned int)end + 0x87) & 0x3FFFFF80) | 0x40000000;
	return 0;
}

int I3dSorter__OpenPacketUca_ByUint32(int *s, unsigned int key)
{
	int *rd = (int *)s[4];
	int *c;
	int *t;
	int p;
	c = (int *)rd[0xF8 / 4];
	c -= 4;
	rd[0xF8 / 4] = (int)c;
	s[8] = (int)c;
	p = rd[0xF4 / 4];
	t = (int *)s[3];
	c[0] = key;
	t[1] = (int)c;
	c[2] = p;
	s[3] = (int)c;
	s[9]++;
	return p;
}

int I3dSorter__ClosePacketUca(SorterP *s, char *end)
{
	char *c = s->cur;
	s->used += end - *(char **)(c + 0x8);
	*(char **)(c + 0xC) = end;
	end += 8;
	*(char **)(s->rd + 0xF4) = end;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndChangeState_ByUint32);

typedef struct { char p0[0x10]; char *rd; char p1[0xC]; char *cur; char p2[4]; int used; } SorterP2;
int I3dSorter__ClosePacketAndChangeState(SorterP2 *s, char *end)
{
	char *c = s->cur;
	s->used += end - *(char **)(c + 0x18);
	*(char **)(c + 0x1C) = end;
	*(unsigned int *)(s->rd + 0xF4) = (((unsigned int)end + 0x87) & 0x3FFFFF80) | 0x40000000;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndChangeStateUca_ByUint32);

int I3dSorter__ClosePacketAndChangeStateUca(SorterP2 *s, char *end)
{
	char *c = s->cur;
	s->used += end - *(char **)(c + 0x18);
	*(char **)(c + 0x1C) = end;
	end += 8;
	*(char **)(s->rd + 0xF4) = end;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndClearState_ByUint32);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3dSorter__ClosePacketAndClearState(void *arg0, int arg1) {
    void *temp_a3;

    temp_a3 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_a3, int *, 0x18) = arg1;
    M2C_FIELD(arg0, int *, 0x28) = (int) (M2C_FIELD(arg0, int *, 0x28) + (arg1 - M2C_FIELD(temp_a3, int *, 0x14)));
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0xF4) = (int) (((arg1 + 0x87) & 0x3FFFFF80) | 0x40000000);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__OpenPacketAndClearStateUca_ByUint32);

int I3dSorter__ClosePacketAndClearStateUca(SorterP2 *s, char *end)
{
	char *c = s->cur;
	*(char **)(c + 0x18) = end;
	s->used += end - *(char **)(c + 0x14);
	end += 8;
	*(char **)(s->rd + 0xF4) = end;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_render_marker", I3dSorter__MergePacket);
