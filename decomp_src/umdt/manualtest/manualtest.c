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
void LcdDrawSetForeColor(unsigned int color);
void LcdDrawSetBackColor(unsigned int color);
void LcdDrawClr(void);
void *SetPosition(void *pos, int x, int y);
void LcdDrawChars(void *pos, const char *str, int size);
void LcdDrawCharsFine(void *pos, const char *str, int size);
int UtilityCmdProcessIDRead(int id, unsigned char *value);
void *memset(void *s, int c, unsigned int n);
int sceIoOpen(const char *path, int flags, int mode);
int sceIoRead(int fd, void *buf, unsigned int size);
int sceIoClose(int fd);
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

int ManualTestInfoDraw(void)
{
	unsigned char val;
	int pos[4];
	char buf[256];
	int i;
	int n;
	int ret = 0;
	int fd;
	int size;
	int lines[4] = { 0, 0, 0, 0 };
	char msg1[112];
	char msg2[112];
	char msg3[112];
	char msg4[112];

	LcdDrawSetForeColor(0xff00);
	LcdDrawSetBackColor(0xffffff);
	LcdDrawClr();
	LcdDrawChars(SetPosition(pos, 10000, 0), "Process ID", 4);
	for (i = 0; i < 10; i++) {
		UtilityCmdProcessIDRead(i, &val);
		if (val != 1)
			ret = -1;
		sprintf(msg1, "id %d = %d\n", i, val);
		sceIoWrite(0, msg1, strlen(msg1));
		sprintf(buf, "%d", val);
		if (i < 5)
			LcdDrawChars(SetPosition(pos, i * 4 + 5, 3), buf, 4);
		else
			LcdDrawChars(SetPosition(pos, i * 4 - 15, 5), buf, 4);
		switch (i) {
		case 0:
			sprintf(buf, "TEST1");
			break;
		case 1:
			sprintf(buf, "TEST2");
			break;
		case 2:
			sprintf(buf, "LCD");
			break;
		case 3:
			sprintf(buf, "GRAPHICS");
			break;
		case 4:
			sprintf(buf, "MOVIE");
			break;
		case 5:
			sprintf(buf, "PAD");
			break;
		case 6:
			sprintf(buf, "SPEAKER");
			break;
		default:
			sprintf(buf, "");
			break;
		}
		if (i < 5)
			LcdDrawCharsFine(SetPosition(pos, i * 64 + 64, 50), buf, 3);
		else
			LcdDrawCharsFine(SetPosition(pos, i * 64 - 256, 90), buf, 3);
	}
	memset(buf, 0, 256);
	fd = sceIoOpen("flash0:/vsh/etc/version.txt", 1, 644);
	if (fd < 0) {
		sprintf(msg2, "fatal error : strFileOpen()\n");
		sceIoWrite(0, msg2, strlen(msg2));
		ret = -1;
	} else {
		size = sceIoRead(fd, buf, 256);
		if (size < 0) {
			sprintf(msg3, "read error ret=%08X\n", size);
			sceIoWrite(0, msg3, strlen(msg3));
			ret = -1;
		}
		sprintf(msg4, "size:%d\n", size);
		sceIoWrite(0, msg4, strlen(msg4));
		sceIoClose(fd);
	}
	for (i = 0, n = 1; i < size && n < 4; i++) {
		if (buf[i] == '\r' || buf[i] == '\n') {
			buf[i] = 0;
			if (buf[i + 1] != '\r' && buf[i + 1] != '\n') {
				lines[n] = i + 1;
				n++;
			}
		}
	}
	LcdDrawSetForeColor(0);
	LcdDrawChars(SetPosition(pos, 0, 10), buf + lines[1], 4);
	LcdDrawChars(SetPosition(pos, 0, 11), buf + lines[3], 4);
	LcdDrawSetForeColor(0xff0000);
	if (ret == 0)
		LcdDrawChars(SetPosition(pos, 10000, 1), "OK", 4);
	else
		LcdDrawChars(SetPosition(pos, 10000, 1), "NG", 4);
	return ret;
}

static int AudioTestThread(unsigned int args, void *argp)
{
	AudioTest(argp);
	return 0;
}

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
