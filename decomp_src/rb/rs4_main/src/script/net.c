/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
M2C_UNK ctrlSetVirtualType(M2C_UNK);                /* extern */
M2C_UNK ctrlSuspend(M2C_UNK);                       /* extern */
extern unsigned char D_000FF4B4;

extern unsigned char D_000FF4CC, D_000FF4E8, D_000FF4FC;
void ctrlFlushVirtualDataAll(void);
int taskProc();
void Script_NetStartCB(int a, char *w)
{
	void *t, *p;
	consPrintf(&D_000FF4B4, "Script_NetStartCB", a, w);
	*(int *)(w + 0x40) = 1;
	*(int *)(w + 0x44) = 1;
	ctrlSuspend(0);
	ctrlFlushVirtualDataAll();
	ctrlSetVirtualType(3);
	t = *(void **)(w + 0x10);
	if (t != 0) {
		p = *(void **)(w + 0x48);
		if (!p)
			consPrintf(&D_000FF4CC, &D_000FF4E8, 0x33, "Script_NetStartCB", &D_000FF4FC);
		taskProc(t, p, 0, 0);
	}
	return;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4FC);

void Script_NetTermCB(int arg0, int arg1) {
    consPrintf(&D_000FF4B4, "Script_NetTermCB", arg0, arg1);
    ctrlSuspend(0);
    ctrlSetVirtualType(0);
}

void Script_NetErrCB(int arg0, void *arg1) {
    consPrintf(&D_000FF4B4, "Script_NetErrCB", arg0, arg1);
    M2C_FIELD(arg1, int *, 0x44) = 0;
    ctrlSuspend(0);
    ctrlSetVirtualType(0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef FALSE
#define FALSE 0
#endif
int taskDefaultMsg(void *, int, int, int);
int ctrlFlushCtrlDataAll(void);
void drawPrintf(const char *, ...);
void *memset(void *, int, unsigned int);
void *SaruNet_PetitGame_NetworkTask__Get_Instance_p(void);
void *SaruNet_Network__Get_Instance_p(void);
void SaruNet_Network__Update(void *);
typedef struct {
	int f0;
	void (*start)(int, char *);
	void *startArg;
	void (*term)(int, int);
	void *termArg;
	void (*err)(int, void *);
	void *errArg;
	char pad1C[0x54 - 0x1C];
} SnParam;
void *SaruNet_PetitGame_NetworkTask__Create(SnParam *);
typedef struct {
	char pad0[0x10];
	void *parent;
	char pad14[0x24 - 0x14];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	void *net;
	char pad34[0x40 - 0x34];
	int st;
	int f44;
	int msg;
	int wait;
} SnTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_000FF4CC, &D_000FF4E8, l, "Script_Net", #e)
int Script_Net(SnTask *Tp, unsigned int msg, int a, int arg)
{
	SnParam prm;
	void *n;
	switch (msg) {
	case 0:
		cassert(Tp, 0x5F);
		Tp->f28 = -1;
		Tp->msg = arg;
		Tp->f24 = 0;
		Tp->f2C = 0;
		Tp->st = 0;
		Tp->f44 = 0;
		n = SaruNet_PetitGame_NetworkTask__Get_Instance_p();
		if (n) {
			Tp->net = n;
			Tp->st = 2;
			Tp->wait = 10;
		} else {
		consPrintf("SaruNet_PetitGame_NetworkTask__Create {\n");
		ctrlSuspend(1);
		ctrlFlushCtrlDataAll();
		memset(&prm, 0, sizeof(prm));
		prm.start = Script_NetStartCB;
		prm.term = Script_NetTermCB;
		prm.err = Script_NetErrCB;
		prm.startArg = Tp;
		prm.termArg = Tp;
		prm.errArg = Tp;
		Tp->net = SaruNet_PetitGame_NetworkTask__Create(&prm);
		consPrintf("}\n");
		}
		return (int)Tp;
	case 4:
		consPrintf("%s : Msg_Kill\n", "Script_Net");
		return (int)Tp;
	case 2:
		switch (Tp->st) {
		default:
			cassert(FALSE, 0xA5);
			return 0;
		case 0:
			drawPrintf("%s : Proc_StartWait\n", "Script_Net");
			n = SaruNet_Network__Get_Instance_p();
			if (n)
				SaruNet_Network__Update(n);
			return 0;
		case 1:
			drawPrintf("%s : Proc_Start\n", "Script_Net");
			n = SaruNet_Network__Get_Instance_p();
			if (n)
				SaruNet_Network__Update(n);
			return 0;
		case 2:
			drawPrintf("%s : Proc_StartCBEmulate Wait=%d\n", "Script_Net", Tp->wait);
			if (Tp->wait > 0)
				Tp->wait--;
			if (Tp->wait == 0) {
				void *t, *p;
				Tp->st = 1;
				Tp->f44 = 1;
				ctrlSetVirtualType(3);
				t = Tp->parent;
				if (t != NULL) {
					p = (void *)Tp->msg;
					if (!p)
						consPrintf(&D_000FF4CC, &D_000FF4E8, 0xC9, "Script_Net", &D_000FF4FC);
					taskProc(t, p, 0, 0);
				}
			}
			return 0;
		}
	case 1:
	case 3:
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
