/* cflags: -O0 */
#include "common.h"

typedef struct {
	int status;
	int *result;
	int unk8;
	int unkC;
} AudioTestArg;

int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);
int sceIoWrite(int fd, const void *buf, unsigned int size);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadLatch(unsigned int *latch);
int sceKernelGetThreadCurrentPriority(void);
int sceKernelCreateThread(const char *name, int (*entry)(unsigned int, void *), int prio, int stack, unsigned int attr, void *opt);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDelayThread(unsigned int usec);
int sceKernelGetThreadExitStatus(int thid);
int sceKernelDeleteThread(int thid);
int AudioTest(void *arg);
int UtilityCmdLed(int mode);
int UtilityCmdProcessIDWrite(int id, int value);
int ManualTestInfoDraw(void);
void LcdDrawCharsLog(const char *str, int size);
void LcdDrawSetLogHeight(int height);
int wlantoolmain(int arg);
int LcdTest4Product(int mode);
int GraphicsModelMain(int mode);
int MovieTest(int mode);
int PadTest(int mode);

void ManualTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041028_1");
}

INCLUDE_ASM("tmp/asm/umdt/manualtest/nonmatchings/manualtest", ManualTestInfoDraw);

static int AudioTestThread(unsigned int args, void *argp)
{
	AudioTest(argp);
	return 0;
}

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002320);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002324);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002340);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002360);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002378);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002384);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_00002388);

INCLUDE_RODATA("tmp/asm/umdt/manualtest/nonmatchings/manualtest", D_0000238C);

int AudioTest_Swing(void *arg)
{
	int ret;
	unsigned int ctrl[4];
	int a = 1;
	int thid;
	int status;
	int count = 10;
	int b = -2;
	int *p = &a;
	char msg[112];

	thid = sceKernelCreateThread("USB_AudioTestThread", AudioTestThread, sceKernelGetThreadCurrentPriority(), 0x1000, 0, NULL);
	sceKernelStartThread(thid, 12, arg);
	UtilityCmdLed(1);
	UtilityCmdProcessIDWrite(6, 1);
	UtilityCmdProcessIDWrite(7, 1);
	ret = ManualTestInfoDraw();
	do {
		sceKernelDelayThread(10);
		status = sceKernelGetThreadExitStatus(thid);
	} while (status < 0);
	sprintf(msg, "audio stop\n");
	sceIoWrite(0, msg, strlen(msg));
	LcdDrawCharsLog("audio stop", 3);
	sceKernelDeleteThread(thid);
	while (ret) {
		sceDisplayWaitVblankStart();
		if (sceCtrlReadLatch(ctrl) && (ctrl[1] & 0x4000)) {
			count--;
			if (count == 0)
				break;
		}
	}
	return ret;
}

int ManualTest(int arg)
{
	int a = 1;
	AudioTestArg targ;
	int ret;

	targ.status = -2;
	targ.result = &a;
	ret = 0;

	wlantoolmain(arg);
	LcdDrawSetLogHeight(16);
	UtilityCmdLed(1);
	LcdTest4Product(0);
	UtilityCmdProcessIDWrite(2, 1);
	if (GraphicsModelMain(1) == 0)
		UtilityCmdProcessIDWrite(3, 1);
	else
		UtilityCmdProcessIDWrite(3, 9);
	if (MovieTest(1) == 0)
		UtilityCmdProcessIDWrite(4, 1);
	else
		UtilityCmdProcessIDWrite(4, 9);
	UtilityCmdLed(1);
	UtilityCmdProcessIDWrite(5, 9);
	PadTest(1);
	UtilityCmdProcessIDWrite(5, 1);
	ret = AudioTest_Swing(&targ);
	UtilityCmdLed(0);
	return ret;
}

int ManualTestEntry(int a, int b)
{
	return 0;
}
