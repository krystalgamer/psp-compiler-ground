/* cflags: -O2 -frename-registers -mext -fno-merge-constants */
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

int __sceSasSetVolume(SasCore *core, unsigned int voice, int l, int r, int el, int er)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;
	int m;
	int vl;
	int ve;
	SasVoice *v;
	int res;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	if (voice >= 32) {
		ret = 0x80420010;
	} else {
		vl = l;
		m = __builtin_allegrex_min(__builtin_allegrex_min(__builtin_allegrex_min(r, l), el), er);
		ve = el;
		m = __builtin_allegrex_max(m, -m);
		m = __builtin_allegrex_max(__builtin_allegrex_max(__builtin_allegrex_max(__builtin_allegrex_max(m, l), r), el), er);
		if (m > 0x1000) {
			ret = 0x80420018;
		} else {
			v = &core->voice[voice];
			vl = __builtin_allegrex_ins(vl, r, 16, 16);
			ve = __builtin_allegrex_ins(ve, er, 16, 16);
			res = sceKernelWaitSema(D_00001DD0, 1, 0);
			if (res < 0) {
				ret = res;
			} else {
				v->vol.pack = vl;
				v->evol.pack = ve;
				sceKernelSignalSema(D_00001DD0, 1);
				ret = 0;
			}
		}
	}
	return pspRetK1(ret, oldk1);
}

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

int __sceSasSetTrianglarWave(SasCore *core, unsigned int voice, unsigned int rate)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	ret = 0x80420010;
	if (voice < 32) {
		unsigned int rt = rate;

		ret = 0x80420017;
		if (rt < 101) {
			SasVoice *v = &core->voice[voice];

			rt = (rt * 44100) / 100;
			if (rt == 0)
				rt = 1;
			int r = sceKernelWaitSema(D_00001DD0, 1, 0);

			if (r < 0) {
				ret = r;
			} else {
				v->type = 3;
				v->addr = rt;
				sceKernelSignalSema(D_00001DD0, 1);
				ret = 0;
			}
		}
	}
	return pspRetK1(ret, oldk1);
}

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

int __sceSasSetADSR(SasCore *core, unsigned int voice, int flags, unsigned int a, unsigned int d, unsigned int s, unsigned int r)
{
	unsigned int oldk1 = pspShiftK1();
	int ret;

	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	{
		unsigned int ta = a;
		unsigned int td = d;
		unsigned int ts = s;
		unsigned int tr = r;

		if (voice >= 32) {
			ret = 0x80420010;
		} else {
			SasVoice *v = &core->voice[voice];
			int res = sceKernelWaitSema(D_00001DD0, 1, 0);

			if (res < 0) {
				ret = res;
			} else {
				if (!(flags & 1))
					ta = v->ar;
				if (!(flags & 2))
					td = v->dr;
				if (!(flags & 4))
					ts = v->sr;
				if (!(flags & 8))
					tr = v->rr;
				if ((int)MAX(MAX(MAX(ta, td), ts), tr) < 0) {
					sceKernelSignalSema(D_00001DD0, 1);
					ret = 0x80420019;
				} else {
					v->ar = ta;
					v->dr = td;
					v->sr = ts;
					v->rr = tr;
					sceKernelSignalSema(D_00001DD0, 1);
					ret = 0;
				}
			}
		}
	}
	return pspRetK1(ret, oldk1);
}

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
			unsigned int m = core->voice[voice].env.mode.w;

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
			core->voice[voice].env.mode.w = m;
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

int __sceSasInit(SasCore *core, int grain, int maxVoices, int outMode, int sampleRate)
{
	unsigned int oldk1;
	int ret;
	u8 *buf;
	int i;

	if (((unsigned int)core & 0x3F) != 0 || (((unsigned int)core >> 27) & 3) != 1
	    || !((0x35 >> __builtin_allegrex_ext((unsigned int)core, 29, 3)) & 1))
		return 0x80420005;
	oldk1 = pspShiftK1();
	if (CHECK_CORE(core)) {
		pspSetK1(oldk1);
		return 0x80000023;
	}
	buf = D_00001DE0;
	if ((grain & 0x1F) != 0 || grain < 0x40 || grain > 0x100) {
		ret = 0x80420001;
	} else if (sampleRate != 44100) {
		ret = 0x80420004;
	} else if ((unsigned int)(maxVoices - 1) >= 32) {
		ret = 0x80420002;
	} else if ((unsigned int)outMode >= 2) {
		ret = 0x80420003;
	} else {
		{
			u8 *p = (u8 *)core;

			for (i = sizeof(SasCore) - 1; i >= 0; i--)
				*p++ = 0;
		}
		for (i = 0; i < 32; i++) {
			SasVoice *v = &core->voice[i];

			v->buf = buf;
			buf += 0x4C;
			v->env.state = -1;
			v->env.mode.b[0] = 0;
			v->env.mode.b[1] = 1;
			v->env.mode.b[2] = 1;
			v->env.mode.b[3] = 1;
			v->env.unk8 = 7;
			v->env.unk9 = 7;
			v->evol.lr[1] = 0x1000;
			v->evol.lr[0] = 0x1000;
			v->vol.lr[1] = 0x1000;
			v->vol.lr[0] = 0x1000;
			v->pitch = 0x1000;
		}
		__builtin_memcpy(core->voice2, core->voice, sizeof(core->voice));
		core->unk8 = grain / 32;
		core->unk9 = outMode;
		core->unk0 = (int)buf;
		core->endFlag = -1;
		core->unkE14 = -1;
		if (sceKernelWaitSema(D_00001DD0, 1, 0) >= 0) {
			core->evolL = 0;
			core->rev.b[1] |= 8;
			core->evolR = 0;
			sceKernelSignalSema(D_00001DD0, 1);
		}
		if (sceKernelWaitSema(D_00001DD0, 1, 0) >= 0) {
			core->von = 1;
			core->rev.b[1] |= 8;
			sceKernelSignalSema(D_00001DD0, 1);
		}
		if (sceKernelWaitSema(D_00001DD0, 1, 0) >= 0) {
			core->rev.w = ((core->rev.w & ~0xFF) + (-1 & 0xFF)) | 0x100;
			sceKernelSignalSema(D_00001DD0, 1);
		}
		if (sceKernelWaitSema(D_00001DD0, 1, 0) >= 0) {
			core->rev.w = ((core->rev.w & 0xFFFF) + (0 << 24) + (0 << 16)) | 0x200;
			sceKernelSignalSema(D_00001DD0, 1);
		}
		sceKernelDcacheWritebackInvalidateAll();
		ret = 0;
	}
	return pspRetK1(ret, oldk1);
}

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
