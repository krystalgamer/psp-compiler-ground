/* cflags: -O2 -frename-registers */
#include "common.h"

typedef struct {
	unsigned char b0;
	unsigned char pad1[3];
	int i4;
	int i8;
	signed char bC;
	unsigned char bD;
	signed char bE;
	unsigned char bF;
	unsigned char b10;
	unsigned char pad11[3];
	int i14;
	int i18;
} SsVoiceTone;

typedef struct {
	unsigned char no;
	signed char status;
	unsigned char pad2[2];
	int i4;
	unsigned char b8;
	unsigned char b9;
	unsigned char bA;
	unsigned char bB;
	int iC;
	int id;
	int i14;
	int i18;
	int i1C;
	int i20;
	int i24;
	unsigned char b28;
	unsigned char pad29[3];
	int i2C;
	int i30;
	int i34;
	unsigned char b38;
	unsigned char pad39[3];
	int i3C;
	SsVoiceTone tone;
	signed char ch;
	unsigned char b5D;
	unsigned char pad5E[2];
	unsigned char vel;
	unsigned char pan;
	unsigned char sendVel;
	unsigned char sendPan;
	int pitch;
} SsVoice;

extern int D_000186E4;
extern unsigned int D_0012919C;
extern SsVoice D_001291C8[];
#define g_vstate D_000186E4
#define g_vmax D_0012919C
#define g_voice D_001291C8

extern SsVoice *D_00129F48[];
extern unsigned int D_001291A4;

int voice_init(unsigned int num)
{
	unsigned int i;

	if (num - 1 >= 32)
		return 0x8054000a;
	g_vmax = num;
	for (i = 0; i < g_vmax; i++) {
		SsVoice *p = &g_voice[i];

		p->status = 1;
		p->i18 = 0;
		p->i4 = 0;
		func_0000C1B0(p);
		p->no = i;
		D_00129F48[i] = p;
	}
	D_001291A4 = g_vmax;
	g_vstate = 0;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_refresh);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_allocVoice);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_noteOn);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_noteOff);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_setSustain);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_setReservedVoice);

unsigned int voice_getVoiceByGroup(unsigned int group)
{
	unsigned int mask = 0;
	unsigned int i;

	if (g_vstate == -1)
		return 0;
	if (group == 0)
		return 0;
	if (group >= 128)
		return 0;
	for (i = 0; i < g_vmax; i++) {
		SsVoice *p = &g_voice[i];

		if (p->status == 2 || p->status == 3 || p->status == 6 || p->status == 7 || p->status == 8 || p->status == 9) {
			if (p->tone.i14 == group)
				mask |= 1 << p->no;
		}
	}
	return mask;
}

unsigned int voice_getVoiceByMidi(unsigned char *midi, int id)
{
	unsigned int mask = 0;
	unsigned int i;

	if (g_vstate == -1)
		return 0;
	if (midi == NULL)
		return 0;
	for (i = 0; i < g_vmax; i++) {
		SsVoice *p = &g_voice[i];

		if (p->status == 2 || p->status == 3 || p->status == 6 || p->status == 7 || p->status == 8 || p->status == 9) {
			if ((unsigned char)p->ch == midi[0] && p->b5D == midi[1] && p->id == id)
				mask |= 1 << p->no;
		}
	}
	return mask;
}

unsigned int voice_getVoiceByID(int id)
{
	unsigned int mask = 0;
	unsigned int i;

	if (g_vstate == -1)
		return 0;
	for (i = 0; i < g_vmax; i++) {
		SsVoice *p = &g_voice[i];

		if (p->status == 2 || p->status == 3 || p->status == 6 || p->status == 7 || p->status == 8 || p->status == 9) {
			if (p->id == id)
				mask |= 1 << p->no;
		}
	}
	return mask;
}

unsigned int voice_getVoiceByChannel(unsigned int ch, int id)
{
	unsigned int mask = 0;
	unsigned int i;

	if (g_vstate == -1)
		return 0;
	if (ch >= 16)
		return 0;
	for (i = 0; i < g_vmax; i++) {
		SsVoice *p = &g_voice[i];

		if (p->status == 2 || p->status == 3 || p->status == 6 || p->status == 7 || p->status == 8 || p->status == 9) {
			if ((unsigned char)p->ch == ch && p->id == id)
				mask |= 1 << p->no;
		}
	}
	return mask;
}

unsigned int voice_getVoiceByChannel2(unsigned int ch, int id)
{
	unsigned int mask = 0;
	unsigned int i;

	if (g_vstate == -1)
		return 0;
	if (ch >= 16)
		return 0;
	for (i = 0; i < g_vmax; i++) {
		SsVoice *p = &g_voice[i];

		if (p->status == 2 || p->status == 3 || p->status == 6 || p->status == 7 || p->status == 8 || p->status == 9 || p->status == 5) {
			if ((unsigned char)p->ch == ch && p->id == id)
				mask |= 1 << p->no;
		}
	}
	return mask;
}

int voice_setVelocity(unsigned int v, unsigned int val)
{
	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	if (val >= 128)
		return 0x8054000a;
	g_voice[v].vel = val;
	return 0;
}

int voice_setPan(unsigned int v, unsigned int val)
{
	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	if (val >= 128)
		return 0x8054000a;
	g_voice[v].pan = val;
	return 0;
}

int voice_setSendVelocity(unsigned int v, unsigned int val)
{
	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	if (val >= 128)
		return 0x8054000a;
	g_voice[v].sendVel = val;
	return 0;
}

int voice_setSendPan(unsigned int v, unsigned int val)
{
	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	if (val >= 128)
		return 0x8054000a;
	g_voice[v].sendPan = val;
	return 0;
}

int voice_setPitch(unsigned int v, int pitch)
{
	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	g_voice[v].pitch = pitch;
	return 0;
}

void voice_getNoteOnCommon(int v, int *a, int *b, int *c, int *d, int *e, int *f, int *g)
{
	SsVoice *p = &g_voice[v];
	SsVoiceTone *t = &p->tone;

	*a = t->b10;
	*b = t->bF;
	*c = p->b5D;
	*d = t->bC;
	*e = t->bD;
	*f = t->bE;
	*g = p->i2C;
}

int voice_getVoiceStatus(unsigned int v)
{
	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	return g_voice[v].status;
}

static void func_0000C1B0(SsVoice *p)
{
	p->b8 = 0;
	p->b9 = 64;
	p->bA = 0;
	p->bB = 64;
	p->iC = 0;
	p->id = -1;
	p->i14 = -1;
	p->i1C = 1;
	p->i20 = 0;
	p->i24 = 0;
	p->b28 = 0;
	p->i2C = -1;
	p->i34 = 0;
	p->b38 = 64;
	p->i3C = 0;
	p->tone.b0 = 64;
	p->tone.i4 = 0;
	p->tone.i8 = 0;
	p->tone.bC = 0;
	p->tone.bD = 0;
	p->tone.bE = 0;
	p->tone.bF = 0;
	p->tone.b10 = 0;
	p->tone.i14 = -1;
	p->tone.i18 = -1;
	p->ch = -1;
	p->b5D = 0;
	p->vel = 0;
	p->pan = 64;
	p->sendVel = 0;
	p->sendPan = 64;
	p->pitch = 0;
}

SsVoice *func_0000C240(unsigned int *pCount, SsVoice **list, unsigned int *pOutCount, SsVoice **outList, unsigned int no)
{
	SsVoice *found = NULL;
	unsigned int i, j;

	for (i = 0; i < *pCount; i++) {
		if (list[i]->no == no) {
			found = list[i];
			break;
		}
	}
	if (i != *pCount - 1) {
		for (j = i; j < *pCount - 1; j++)
			list[j] = list[j + 1];
	}
	(*pCount)--;
	outList[(*pOutCount)++] = found;
	return found;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C2D8);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C488);

int func_0000C658(SsVoice **list, unsigned int count, unsigned int prio)
{
	SsVoice *cand[32];
	unsigned int n = 0;
	unsigned int minv = 0xFFFFFFFF;
	unsigned int i;

	for (i = 0; i < count; i++) {
		SsVoice *p = list[i];

		if (p->tone.i18 <= prio) {
			cand[n++] = p;
			if (p->i4 < minv)
				minv = p->i4;
		}
	}
	if (n == 0)
		return -1;
	for (i = 0; i < n; i++) {
		if (cand[i]->i4 == minv)
			return cand[i]->no;
	}
	return -1;
}

void func_0000C6F4(unsigned int vol, unsigned int vel, int pan1, int pan2, unsigned int *pL, unsigned int *pR)
{
	int pan = pan1 + pan2 - 64;

	pan = (pan > 0) ? pan : 0;
	pan = (pan < 127) ? pan : 127;

	if (pan == 0) {
		*pL = vol;
		*pR = 0;
	} else if (pan < 64) {
		*pL = vol;
		*pR = (vol * pan) >> 6;
	} else if (pan > 64) {
		*pL = (vol * (127 - pan)) >> 6;
		*pR = vol;
	} else {
		*pL = vol;
		*pR = vol;
	}
	*pL = *pL * vel / 127;
	*pR = *pR * vel / 127;
}
