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

INCLUDE_RODATA("tmp/asm/umdt/hpremotetest/nonmatchings/hpremotetest", D_00001EC8);

INCLUDE_RODATA("tmp/asm/umdt/hpremotetest/nonmatchings/hpremotetest", D_00001ECC);

INCLUDE_RODATA("tmp/asm/umdt/hpremotetest/nonmatchings/hpremotetest", D_00001ED0);

INCLUDE_ASM("tmp/asm/umdt/hpremotetest/nonmatchings/hpremotetest", HpremoteTest);

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
