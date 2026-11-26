/* cflags: -O0 */
#include "common.h"

int sprintf(char *buf, const char *fmt, ...);
int sceHprmIsRemoteExist(void);
int sceHprmIsHeadphoneExist(void);
int sceHprmReadLatch(unsigned int *latch);
int sceHprmIsMicrophoneExist(void);
unsigned int strlen(const char *s);
void *memcpy(void *d, const void *s, unsigned int n);
int sceIoWrite(int fd, const void *buf, unsigned int size);
int sceRtcGetCurrentTick(unsigned long long *tick);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadLatch(unsigned int *latch);
int PowerTestSetPowerSuspend(void);
void DrawHpremoteMenu(void);
void DrawHpOn(unsigned int bits);
void DrawHpOff(unsigned int bits);
void DrawHpRemoteExist(int exist);
void DrawHpHeadphoneExist(int exist);
void DrawHpMicrophoneExist(int exist);

void HpremoteTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041028_1");
}

int HpremoteTest(int product)
{
	int unused0;
	int unused1;
	int remote = 1;
	int headphone = 1;
	int result = 0;
	unsigned int ctrl[4];
	unsigned int latch[4];
	unsigned long long tick[2];
	int prev[3] = { -1, -1, -1 };
	int cur[3];
	char msg0[112];
	char msg1[112];
	char msg2[112];
	char msg3[112];
	register unsigned long long elapsed;

	if (product) {
		if (!sceHprmIsRemoteExist() || !sceHprmIsHeadphoneExist()) {
			memcpy(&result, "198", 3);
			goto end;
		}
		memcpy(&result, "199", 3);
		sceRtcGetCurrentTick(&tick[0]);
	}
	sprintf(msg0, "sceHprmIsRemoteExist %d\n", sceHprmIsRemoteExist());
	sceIoWrite(0, msg0, strlen(msg0));
	sprintf(msg1, "sceHprmIsHeadphoneExist %d\n", sceHprmIsHeadphoneExist());
	sceIoWrite(0, msg1, strlen(msg1));
	sprintf(msg2, "sceHprmIsMicrophoneExist %d\n", sceHprmIsMicrophoneExist());
	sceIoWrite(0, msg2, strlen(msg2));
	DrawHpremoteMenu();
	DrawHpOff(-1);
	for (;;) {
		sceDisplayWaitVblankStart();
		if (product) {
			sceRtcGetCurrentTick(&tick[1]);
			elapsed = tick[1] - tick[0];
			if (elapsed > 2000000)
				break;
		}
		cur[0] = sceHprmIsRemoteExist();
		cur[1] = sceHprmIsHeadphoneExist();
		cur[2] = sceHprmIsMicrophoneExist();
		if (cur[0] != prev[0]) {
			prev[0] = cur[0];
			DrawHpRemoteExist(cur[0]);
		}
		if (cur[1] != prev[1]) {
			prev[1] = cur[1];
			DrawHpHeadphoneExist(cur[1]);
		}
		if (cur[2] != prev[2]) {
			prev[2] = cur[2];
			DrawHpMicrophoneExist(cur[2]);
		}
		if (sceHprmReadLatch(latch)) {
			sprintf(msg3, "Hp input\n");
			sceIoWrite(0, msg3, strlen(msg3));
			if (latch[1] || latch[0]) {
				if (product && (latch[0] & 1)) {
					result = 0;
					break;
				}
				DrawHpOn(latch[2]);
				DrawHpOff(latch[3]);
			}
		}
		if (sceCtrlReadLatch(ctrl)) {
			if (ctrl[1] & 0x4000)
				break;
			if (ctrl[1] & 0x8000)
				PowerTestSetPowerSuspend();
		}
	}
end:
	return result;
}

int HpremoteInputFfTest(void)
{
	int ret;
	unsigned int latch[4];

	ret = 0;
	if (sceHprmIsRemoteExist() == 1 && sceHprmIsHeadphoneExist() == 1 && sceHprmReadLatch(latch) != 0 && (latch[0] & 4))
		ret = 1;
	return ret;
}

int HpremoteTestEntry(int a, int b)
{
	return 0;
}
