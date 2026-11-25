#ifndef _CTRLSVC_H
#define _CTRLSVC_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
struct SceCtrlData {
	unsigned int TimeStamp;
	unsigned int Buttons;
	unsigned char Lx;
	unsigned char Ly;
	unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlLatch {
	unsigned int uiMake;
	unsigned int uiBreak;
	unsigned int uiPress;
	unsigned int uiRelease;
};
typedef struct SceCtrlLatch SceCtrlLatch;
int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlPeekBufferPositive(SceCtrlData *data, int count);
#endif
