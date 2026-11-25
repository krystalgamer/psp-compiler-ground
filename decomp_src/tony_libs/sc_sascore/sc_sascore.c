/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "sascore.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasCore);

int __sceSasGetEndFlag(SasCore *core)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	ret = core->endFlag;
	pspSetK1(oldk1);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetKeyOn);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetKeyOff);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetVolume);

int __sceSasSetPitch(SasCore *core, unsigned int voice, unsigned int pitch)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice >= 32) {
		ret = 0x80420010;
	} else if (pitch >= 0x4001) {
		ret = 0x80420012;
	} else {
		int r = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (r < 0) {
			ret = r;
		} else {
			core->voice[voice].pitch = pitch;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

int __sceSasSetVoice(SasCore *core, unsigned int voice, int addr, int size, unsigned int loop)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	int end = addr + size;

	if (size == 0 || (size & 0xF) != 0) {
		ret = 0x80420014;
	} else if (voice >= 32) {
		ret = 0x80420010;
	} else if (loop >= 2) {
		ret = 0x80420015;
	} else {
		SasVoice *v = &core->voice[voice];
		int r = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (r < 0) {
			ret = r;
		} else {
			v->type = 1;
			v->loop = loop;
			v->addr = addr;
			v->end = end;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetNoise);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetTrianglarWave);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetSteepWave);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetADSR);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetADSRmode);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetSL);

int __sceSasGetEnvelopeHeight(SasCore *core, unsigned int voice)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice < 32)
		ret = core->voice[voice].height;
	else
		ret = 0x80420010;
	return pspRetK1(ret, oldk1);
}

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetSimpleADSR);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasInit);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasRevVON);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasRevEVOL);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasRevType);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasRevParam);

INCLUDE_RODATA("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", D_00001DA0);

INCLUDE_RODATA("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", D_00001DA8);

INCLUDE_RODATA("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", D_00001DB0);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", module_start);

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", module_stop);
