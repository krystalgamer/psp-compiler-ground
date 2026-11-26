/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
void startMsgDialog();
extern unsigned char msgdialog_param_28E1FC;


#ifndef NULL
#define NULL ((void *)0)
#endif
void sceKernelExitGame(void);
int ExitFunction_16448(void) {
    sceKernelExitGame();
    return 0;
}

extern int loop_28E444;
int sceUtilityMsgDialogGetStatus(void);
int sceUtilityMsgDialogUpdate(int n);
int sceUtilityMsgDialogShutdownStart(void);
int utility_update_msgdialog_16468(void)
{
	int ret = 0;

	switch (sceUtilityMsgDialogGetStatus()) {
	case 1:
		break;
	case 2:
		ret = sceUtilityMsgDialogUpdate(1);
		break;
	case 0:
		loop_28E444 = 0;
		break;
	case 3:
		ret = sceUtilityMsgDialogShutdownStart();
		break;
	case 4:
		break;
	}
	return ret;
}

extern int looprule;
extern int exit_cb, utility_type;
void psp_loopstart(void);
void psp_loopend(void);
int sceKernelGetCallbackCount(int cb);
int sceKernelCheckCallback(void);
int sceDisplayWaitVblankStartCB(void);
int sceKernelExitDeleteThread(int status);

typedef struct {
	int size, language, buttonSwap, graphicsThread, accessThread, fontThread, soundThread;
	int f1c[6];
	int mode, errorValue;
	char message[512];
} MDPARAM2;
int GetMessageLang(void);
int GetAssign(void);
int sceUtilityMsgDialogInitStart(void *p);
#define MDP (*(MDPARAM2 *)&msgdialog_param_28E1FC)
int sub_thread_164DC(void)
{
	int cnt;

	loop_28E444 = 1;
	utility_type = 1;
	do {
		if (looprule)
			psp_loopstart();
		cnt = sceKernelGetCallbackCount(exit_cb);
		utility_update_msgdialog_16468();
		sceKernelCheckCallback();
		if (looprule)
			psp_loopend();
		else
			sceDisplayWaitVblankStartCB();
	} while (cnt == 0 && loop_28E444 != 0);
	sceKernelExitDeleteThread(0);
	utility_type = -1;
	return 0;
}

typedef struct {
	int size, language, buttonSwap, graphicsThread, accessThread, fontThread, soundThread;
	int f1c[6];
	int mode, errorValue;
} MDPARAM;
void *memset(void *s, int c, unsigned int n);
int GetMessageLang(void);
int GetAssign(void);
int sceUtilityMsgDialogInitStart(void *p);

extern int looprule, thread_id_28E440;
extern const char D_0007B804[];
int sub_thread_164DC();
int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, int attr, void *opt);
int sceKernelStartThread(int thid, int len, void *argp);
int sceKernelDeleteThread(int thid);
int sceKernelWaitThreadEnd(int thid, void *timeout);
void OnPush_MsgDialogNumber(int err)
{
	MDPARAM *p = (MDPARAM *)&msgdialog_param_28E1FC;

	memset(p, 0, 0x244);
	p->size = 0x244;
	p->language = GetMessageLang();
	p->buttonSwap = GetAssign();
	p->graphicsThread = 0x11;
	p->accessThread = 0x13;
	p->fontThread = 0x12;
	p->soundThread = 0x10;
	p->mode = 0;
	p->errorValue = err;
	sceUtilityMsgDialogInitStart(p);
}

int sysmsg_errornum(int err, int rule)
{
	looprule = rule;
	thread_id_28E440 = sceKernelCreateThread(D_0007B804, sub_thread_164DC, 0x10, 0x10000, 0, 0);
	if (thread_id_28E440 <= 0)
		return 1;
	OnPush_MsgDialogNumber(err);
	if (sceKernelStartThread(thread_id_28E440, 0, 0) != 0) {
		sceKernelDeleteThread(thread_id_28E440);
		return 1;
	}
	sceKernelWaitThreadEnd(thread_id_28E440, 0);
	return 0;
}

void startMsgDialog(char *msg)
{
	MDP.size = 0x244;
	MDP.language = GetMessageLang();
	MDP.buttonSwap = GetAssign();
	MDP.graphicsThread = 0x11;
	MDP.accessThread = 0x13;
	MDP.fontThread = 0x12;
	MDP.soundThread = 0x10;
	MDP.mode = 1;
	memcpy(MDP.message, msg, 512);
	sceUtilityMsgDialogInitStart(&MDP);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogNormal(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 1;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogNormal_YesNo_Yes(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x11;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogNormal_YesNo_No(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x111;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogError(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogError_YesNo_Yes(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x10;
    startMsgDialog(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void MsgDialogError_YesNo_No(int arg0) {
    memset(&msgdialog_param_28E1FC, 0, 0x244U);
    M2C_FIELD(&msgdialog_param_28E1FC, int *, 0x23C) = 0x110;
    startMsgDialog(arg0);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", D_0007B804);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_sysmsg", sysmsg_string);
