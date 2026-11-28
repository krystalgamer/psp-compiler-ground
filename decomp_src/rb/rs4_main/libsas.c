/* cflags: -O2 -frename-registers */
#include "common.h"
extern int D_0012FA80;
extern char D_0012FAC0[];
#define g_init D_0012FA80
#define g_core D_0012FAC0

int __sceSasCore(void *core, void *buf);
int __sceSasGetEndFlag(void *core);
int __sceSasGetEnvelopeHeight(void *core, int voice);
int __sceSasCoreWithMix(void *core, void *buf, int a, int b);
int __sceSasSetPause(void *core, int mask, int flag);
int __sceSasGetPauseFlag(void *core);
int __sceSasInit(void *core, int grain, int maxvoices, int outmode, int freq);
int __sceSasRevEVOL(void *core, int left, int right);
int __sceSasRevParam(void *core, int delay, int feedback);
int __sceSasRevType(void *core, int type);
int __sceSasRevVON(void *core, int dry, int wet);
int __sceSasSetADSR(void *core, int voice, int flag, int a, int d, int s, int r);
int __sceSasSetADSRmode(void *core, int voice, int flag, int a, int d, int s, int r);
int __sceSasSetKeyOff(void *core, int voice);
int __sceSasSetKeyOn(void *core, int voice);
int __sceSasSetNoise(void *core, int voice, int freq);
int __sceSasSetPitch(void *core, int voice, int pitch);
int __sceSasSetSL(void *core, int voice, int level);
int __sceSasSetSimpleADSR(void *core, int voice, int adsr1, int adsr2);
int __sceSasSetVoice(void *core, int voice, int vag, int size, int loop);
int __sceSasSetVolume(void *core, int voice, int l, int r, int el, int er);

int sceSasCore(void *buf)
{
	if (!g_init)
		return 0x80420100;
	if (buf == NULL)
		return 0x80420005;
	if ((unsigned int)buf & 0x3f)
		return 0x80420005;
	return __sceSasCore(g_core, buf);
}

int sceSasCoreWithMix(void *buf, int a, int b)
{
	if (!g_init)
		return 0x80420100;
	if (buf == NULL)
		return 0x80420005;
	if ((unsigned int)buf & 0x3f)
		return 0x80420005;
	return __sceSasCoreWithMix(g_core, buf, a, b);
}

int sceSasInitWithGrain(int grain)
{
	int ret;
	int i;

	if (g_init)
		return 0x80420101;
	ret = __sceSasInit(g_core, grain, 32, 0, 44100);
	if (ret != 0)
		return ret;
	for (i = 0; i < 32; i++) {
		if (g_init)
			__sceSasSetPitch(g_core, i, 4096);
		if (g_init)
			__sceSasSetSimpleADSR(g_core, i, 15, 0x5fc0);
		if (g_init)
			__sceSasSetVolume(g_core, i, 0, 0, 0, 0);
	}
	g_init = 1;
	return 0;
}

int sceSasSetKeyOn(int voice)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetKeyOn(g_core, voice);
}

int sceSasSetKeyOff(int voice)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetKeyOff(g_core, voice);
}

int sceSasSetPause(int voice, int flag)
{
	if (!g_init)
		return 0x80420100;
	if ((unsigned int)voice >= 32)
		return 0x80420010;
	return __sceSasSetPause(g_core, 1 << voice, flag);
}

int sceSasSetPauseMulti(int mask, int flag)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetPause(g_core, mask, flag);
}

int sceSasGetPauseFlag(void)
{
	if (!g_init)
		return 0;
	return __sceSasGetPauseFlag(g_core);
}

int sceSasSetVolume(int voice, int l, int r, int el, int er)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetVolume(g_core, voice, l, r, el, er);
}

int sceSasSetPitch(int voice, int pitch)
{
	if (!g_init)
		return 0x80420100;
	if (pitch == 0)
		return 0x80420012;
	return __sceSasSetPitch(g_core, voice, pitch);
}

int sceSasSetVoice(int voice, int vag, int size, int loop)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetVoice(g_core, voice, vag, size, loop);
}

int sceSasSetNoise(int voice, int freq)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetNoise(g_core, voice, freq);
}

int sceSasSetADSR(int voice, int flag, int a, int d, int s, int r)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetADSR(g_core, voice, flag, a, d, s, r);
}

int sceSasSetADSRmode(int voice, int flag, int a, int d, int s, int r)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetADSRmode(g_core, voice, flag, a, d, s, r);
}

int sceSasSetSL(int voice, int level)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetSL(g_core, voice, level);
}

int sceSasSetSimpleADSR(int voice, int adsr1, int adsr2)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasSetSimpleADSR(g_core, voice, adsr1, adsr2);
}

int sceSasGetEndFlag(void)
{
	int ret = 0;

	if (g_init)
		ret = __sceSasGetEndFlag(g_core);
	return ret;
}

int sceSasGetEnvelope(int voice)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasGetEnvelopeHeight(g_core, voice);
}

int sceSasSetEffect(int dry, int wet)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasRevVON(g_core, dry, wet);
}

int sceSasSetEffectVolume(int left, int right)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasRevEVOL(g_core, left, right);
}

int sceSasSetEffectType(int type)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasRevType(g_core, type);
}

int sceSasSetEffectParam(int delay, int feedback)
{
	if (!g_init)
		return 0x80420100;
	return __sceSasRevParam(g_core, delay, feedback);
}

void sceSasInit(void)
{
	sceSasInitWithGrain(0x100);
}

int sceSasExit(void)
{
	if (g_init != 1)
		return 0x80420100;
	g_init = 0;
	return 0;
}


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/libsas", __psp_libinfo___10C120);
