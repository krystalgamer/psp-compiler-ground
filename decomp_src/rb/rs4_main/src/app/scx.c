/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int sceKernelGetGPI();                              /* extern */
M2C_UNK sgxResClose(int);                           /* extern */
extern unsigned char D_000FE640;

void consPrintf(const char *, ...);
M2C_UNK sgxResCloseAll();                           /* extern */
M2C_UNK sgxSndStopAll(M2C_UNK);                     /* extern */
M2C_UNK sgxTerm();                                  /* extern */
extern unsigned char D_000FE5F4;

extern char D_000FE5A0[];

extern char D_000FE5A0[];

extern unsigned char D_000FE65C, D_000FE69C;
void sgxSndSetVolume(int, int, int);

extern unsigned char D_000FE65C, D_000FE6A8;
int sgxSndStop();

extern unsigned char D_000FE65C, D_000FE6B0;
int sgxSndPause();

extern unsigned char D_000FE65C, D_000FE6BC;
int sgxSndGetStatus();

int sgxSetMallocFunc(int arg0);
int sgxSetFreeFunc(int arg0);
int sgxSetPrintFunc(int arg0);
int sgxSetDebugFlags(int arg0);
void sgxSndSetMasterVolume(int a, int b);
void sgxEffSetType(int ch, unsigned int type);
void sgxEffSetDepth(int ch, int l, int r);
void sgxEffSetParam(int ch, int which, int v);
void *scxMalloc(int size)
{
	return _memAlloc(size, D_000FE5A0, 0x34);
}

void scxMfree(void *p)
{
	_memFree(p, D_000FE5A0, 0x3D);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5A0);

extern unsigned char D_000FE5F8, D_000FE604, D_000FE620;
int sprintf(char *, const char *, ...);
int sgxInit(char *);
int scxInit(void)
{
	char buf[256];
	int r;
	consPrintf("%s {\n", "scxInit");
	sgxSetMallocFunc(scxMalloc);
	sgxSetFreeFunc(scxMfree);
	sgxSetPrintFunc(consPrintf);
	sprintf(buf, "sgx-snd-nslot=%d\nsgx-seq-nslot=%d\nsgx-seq-nunit=%d\n", 48, 48, 48);
	consPrintf(&D_000FE5F4, buf);
	r = sgxInit(buf);
	if (r != 1)
		consPrintf(&D_000FE604, D_000FE5A0, 0x5D, "scxInit", &D_000FE5F8);
	sgxSetDebugFlags(7);
	sgxSndSetMasterVolume(0, 0);
	sgxSndSetMasterVolume(0x80, 0x80);
	sgxEffSetType(0, 4);
	sgxEffSetDepth(0, 15, 15);
	sgxEffSetParam(0, 0, 0);
	consPrintf(&D_000FE620);
	return r;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE604);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE620);

int scxTerm(void) {
    consPrintf(&D_000FE5F4, "scxTerm");
    sgxSndStopAll(0);
    sgxResCloseAll();
    sgxTerm();
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE62C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE634);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE640);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE64C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE654);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE65C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE678);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE69C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6BC);

extern unsigned int D_00119D80;
extern const float D_000FE6C8, D_000FE6CC;
unsigned int sceKernelGetSystemTimeLow(void);
void sgxProc(float);
void scxUpdate(void)
{
	unsigned int now = sceKernelGetSystemTimeLow();
	float dt = (float)(now - D_00119D80) / D_000FE6C8 / D_000FE6C8;
	if (D_00119D80 == 0) dt = D_000FE6CC;
	sgxProc(dt);
	D_00119D80 = now;
}
const float D_000FE6C8 = 1000.0f;
const float D_000FE6CC = 0.01668335125f;

extern unsigned char D_000FE62C, D_000FE634;
extern char *TypeTbl[3];
char *resArg();
int strcmp(const char *, const char *);
int sgxResOpen(int, int);
void *scxAsm(int *res, int *s)
{
	int id;
	int type;
	char *ext;
	if (sceKernelGetGPI() & 1)
		consPrintf(&D_000FE5F4, &D_000FE62C);
	id = sgxResOpen(res[0], 0);
	if (id < 0)
		consPrintf(&D_000FE604, D_000FE5A0, 0x9D, &D_000FE62C, &D_000FE634);
	res[4] = (int)s;
	ext = resArg(res, 3);
	type = 0;
	if (strcmp(ext, TypeTbl[0]) == 0) type = 0;
	if (strcmp(ext, TypeTbl[1]) == 0) type = 1;
	if (strcmp(ext, TypeTbl[2]) == 0) type = 2;
	s[0] = id;
	s[1] = type;
	return (void *)(((int)(s + 2) + 15) & ~15);
}

int scxRelease(void *arg0) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FE5F4, &D_000FE640);
    }
    sgxResClose(*M2C_FIELD(arg0, int **, 0x10));
    return 1;
}

int sgxSndEnumUseID(int *);
int sgxSndPlayWave(int, int, int);
int sgxSndPlayNote(int, int, int, int);
int sgxSndPlaySeq(int, int, int, int);
void sgxSndSetPr2Pan(int, float);
void sgxSndSetDry(int, int);
void sgxSndSetWet(int, int);
void sgxSndSetPitch(int, float);
void sgxSndSetSpeed(int, float);
extern unsigned char D_000FE64C, D_000FE654, D_000FE678;
int scxPlay(int *res, int a, int b)
{
	int id = -1;
	if (sgxSndEnumUseID(0) < 0x30) {
		int *s = (int *)res[4];
		switch (s[1]) {
		default:
			consPrintf(&D_000FE604, D_000FE5A0, 0xD0, &D_000FE64C, &D_000FE654);
			break;
		case 0:
			id = sgxSndPlayWave(s[0], a, 0);
			break;
		case 1:
			id = sgxSndPlayNote(s[0], a, b, 0);
			break;
		case 2:
			id = sgxSndPlaySeq(s[0], a, b, 0);
			break;
		}
		if (id >= 0) {
			sgxSndSetVolume(id, 0x80, 0x80);
			sgxSndSetPr2Pan(id, 0.0f);
			sgxSndSetDry(id, 0x80);
			sgxSndSetWet(id, 0x80);
			sgxSndSetPitch(id, 1.0f);
			sgxSndSetSpeed(id, 1.0f);
		} else
			consPrintf(&D_000FE65C, &D_000FE64C, id);
	} else
		consPrintf(&D_000FE678, &D_000FE64C);
	return id;
}

int scxVolume(int id, int vol, int arg)
{
	if (id >= 0) {
		sgxSndSetVolume(id, vol, arg);
	} else {
		consPrintf(&D_000FE65C, &D_000FE69C, id);
	}
	return 1;
}

int scxStop(int id, int arg)
{
	if (id >= 0) {
		sgxSndStop(id, arg);
	} else {
		consPrintf(&D_000FE65C, &D_000FE6A8, id);
	}
	return 1;
}

int scxPause(int id, int arg)
{
	if (id >= 0) {
		sgxSndPause(id, arg);
	} else {
		consPrintf(&D_000FE65C, &D_000FE6B0, id);
	}
	return 1;
}

int scxState(int id)
{
	if (id >= 0)
		return sgxSndGetStatus(id);
	consPrintf(&D_000FE65C, &D_000FE6BC, id);
	return 0;
}

void scxStopAll(void) {
    sgxSndStopAll(0);
}
