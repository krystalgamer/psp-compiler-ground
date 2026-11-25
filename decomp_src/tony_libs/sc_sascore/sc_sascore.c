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

int __sceSasSetNoise(SasCore *core, unsigned int voice, unsigned int freq)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice >= 32) {
		ret = 0x80420010;
	} else if (freq >= 0x40) {
		ret = 0x80420011;
	} else {
		SasVoice *v = &core->voice[voice];
		int r = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (r < 0) {
			ret = r;
		} else {
			unsigned int c;

			v->type = 2;
			v->addr = -1;
			v->end = 0x4000 >> (freq >> 2);
			if (v->end != 0) {
				c = ((unsigned int)-0x1156 >> ((freq & 3) << 2)) & 0xFF;
				v->addr = c * 0x01010101;
			} else {
				v->end = 1;
			}
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetTrianglarWave);

int __sceSasSetSteepWave(SasCore *core, unsigned int voice, unsigned int rate)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice >= 32) {
		ret = 0x80420010;
	} else if (rate >= 101) {
		ret = 0x80420017;
	} else {
		int r = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (r < 0) {
			ret = r;
		} else {
			SasVoice *v = &core->voice[voice];

			v->type = 4;
			v->addr = (rate * 44100) / 100;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

INCLUDE_ASM("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", __sceSasSetADSR);

int __sceSasSetADSRmode(SasCore *core, unsigned int voice, int flags, int am, int dm, int sm, int rm)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice >= 32) {
		ret = 0x80420010;
	} else {
		int res = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (res < 0) {
			ret = res;
		} else {
			unsigned int m = core->voice[voice].env.mode;

			if (flags & 1) {
				if (am >= 32 || !((0x15 >> am) & 1))
					goto err;
				m = __builtin_allegrex_ins(m, am, 0, 8);
			}
			if (flags & 2) {
				if (dm >= 32 || !((0x2A >> dm) & 1))
					goto err;
				m = __builtin_allegrex_ins(m, dm, 8, 8);
			}
			if (flags & 4) {
				if (sm >= 32 || !((0x3F >> sm) & 1))
					goto err;
				m = __builtin_allegrex_ins(m, sm, 16, 8);
			}
			if (flags & 8) {
				if (rm >= 32 || !((0x2A >> rm) & 1))
					goto err;
				m = __builtin_allegrex_ins(m, rm, 24, 8);
			}
			core->voice[voice].env.mode = m;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
			goto end;
err:
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0x80420013;
		}
	}
end:
	return pspRetK1(ret, oldk1);
}

int __sceSasSetSL(SasCore *core, unsigned int voice, unsigned int sl)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice >= 32) {
		ret = 0x80420010;
	} else if (sl > 0x40000000) {
		ret = 0x80420019;
	} else {
		int r = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (r < 0) {
			ret = r;
		} else {
			core->voice[voice].env.sl = sl;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

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

int __sceSasRevVON(SasCore *core, int dry, int wet)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	ret = sceKernelWaitSema(D_00001DD0, 1, 0);
	if (ret >= 0) {
		core->von = (dry != 0) + ((wet != 0) << 1);
		core->rev.b[1] |= 8;
		sceKernelSignalSema(D_00001DD0, 1);
	}
	return pspRetK1(ret, oldk1);
}

int __sceSasRevEVOL(SasCore *core, int l, int r)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (l < 0 || l > 0x1000 || r < 0 || r > 0x1000) {
		ret = 0x80420023;
	} else {
		int res = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (res < 0) {
			ret = res;
		} else {
			core->evolL = l;
			core->evolR = r;
			core->rev.b[1] |= 8;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = res;
		}
	}
	return pspRetK1(ret, oldk1);
}

int __sceSasRevType(SasCore *core, int type)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (type < -1 || type > 8) {
		ret = 0x80420020;
	} else {
		int res = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (res < 0) {
			ret = res;
		} else {
			core->rev.w = ((core->rev.w & ~0xFF) + (type & 0xFF)) | 0x100;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

int __sceSasRevParam(SasCore *core, unsigned int delay, unsigned int fb)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (delay >= 0x80) {
		ret = 0x80420022;
	} else if (fb >= 0x80) {
		ret = 0x80420021;
	} else {
		int res = sceKernelWaitSema(D_00001DD0, 1, 0);

		if (res < 0) {
			ret = res;
		} else {
			core->rev.w = ((core->rev.w & 0xFFFF) + (fb << 24) + (delay << 16)) | 0x200;
			sceKernelSignalSema(D_00001DD0, 1);
			ret = 0;
		}
	}
	return pspRetK1(ret, oldk1);
}

INCLUDE_RODATA("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", D_00001DA0);

INCLUDE_RODATA("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", D_00001DA8);

INCLUDE_RODATA("tmp/asm/tony_libs/sc_sascore/nonmatchings/sc_sascore", D_00001DB0);

int module_start(void)
{
	D_00001DE0 = sceMeCalloc(0xB634, 1);
	if (D_00001DE0 == 0)
		return 1;
	D_00001DD0 = sceKernelCreateSema("SceSas", 0, 1, 1, 0);
	if (D_00001DD0 < 0)
		return 1;
	return 0;
}

int module_stop(void)
{
	if (D_00001DE0 != 0)
		sceMeFree(D_00001DE0);
	if (D_00001DD0 >= 0)
		sceKernelDeleteSema(D_00001DD0);
	return 0;
}
