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
extern unsigned int D_001291A0;
extern SsVoice *D_00129EC8[32];
extern unsigned int D_001291A4;
extern SsVoice *D_00129F48[32];
extern unsigned int D_001291A8;
extern SsVoice *D_00129FC8[32];
extern unsigned int D_001291AC;
extern SsVoice *D_0012A048[32];
extern unsigned int D_001291B0;
extern SsVoice *D_0012A0C8[32];
extern unsigned int D_001291B4;
extern SsVoice *D_0012A148[32];
extern unsigned int D_001291B8;
extern SsVoice *D_0012A1C8[32];
extern unsigned int D_001291BC;
extern SsVoice *D_0012A248[32];
extern unsigned int D_001291C0;
extern SsVoice *D_0012A2C8[32];
extern unsigned int D_001291C4;
extern SsVoice *D_0012A348[32];
#define g_cnt0 D_001291A0
#define g_lst0 D_00129EC8
#define g_cnt1 D_001291A4
#define g_lst1 D_00129F48
#define g_cnt2 D_001291A8
#define g_lst2 D_00129FC8
#define g_cnt3 D_001291AC
#define g_lst3 D_0012A048
#define g_cnt4 D_001291B0
#define g_lst4 D_0012A0C8
#define g_cnt5 D_001291B4
#define g_lst5 D_0012A148
#define g_cnt6 D_001291B8
#define g_lst6 D_0012A1C8
#define g_cnt7 D_001291BC
#define g_lst7 D_0012A248
#define g_cnt8 D_001291C0
#define g_lst8 D_0012A2C8
#define g_cnt9 D_001291C4
#define g_lst9 D_0012A348

static void func_0000C1B0(SsVoice *p);
int sceSasSetVoice(int voice, void *vag, int size, int loop);
int sceSasSetNoise(int voice, int freq);
int sceSasSetPitch(int voice, int pitch);
int sceSasSetVolume(int voice, int l, int r, int el, int er);
int sceSasSetSimpleADSR(int voice, int adsr1, int adsr2);
int sceSasSetKeyOn(int voice);
unsigned short sceSsNote2Pitch(unsigned short center_note, unsigned short center_fine, unsigned short note, short fine);

SsVoice *func_0000C240(unsigned int *pCount, SsVoice **list, unsigned int *pOutCount, SsVoice **outList, unsigned int no);


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
		g_lst1[i] = p;
	}
	g_cnt1 = g_vmax;
	g_vstate = 0;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_refresh);

int voice_allocVoice(unsigned int prio)
{
	int v;

	if (g_vstate == -1)
		return 0x80450001;
	if (g_cnt1 != 0)
		return g_lst1[0]->no;
	if (g_cnt5 != 0) {
		v = func_0000C658(g_lst5, g_cnt5, prio);
		if (v != -1)
			return v;
	}
	if (g_cnt4 != 0) {
		v = func_0000C658(g_lst4, g_cnt4, prio);
		if (v != -1)
			return v;
	}
	if (g_cnt7 != 0) {
		v = func_0000C658(g_lst7, g_cnt7, prio);
		if (v != -1)
			return v;
	}
	if (g_cnt3 != 0) {
		v = func_0000C658(g_lst3, g_cnt3, prio);
		if (v != -1)
			return v;
	}
	if (g_cnt8 != 0) {
		v = func_0000C658(g_lst8, g_cnt8, prio);
		if (v != -1)
			return v;
	}
	if (g_cnt9 != 0) {
		v = func_0000C658(g_lst9, g_cnt9, prio);
		if (v != -1)
			return v;
	}
	if (g_cnt2 != 0) {
		v = func_0000C658(g_lst2, g_cnt2, prio);
		if (v != -1)
			return v;
	}
	/* the last test checks list 6 but searches list 2 (as in the original) */
	if (g_cnt6 != 0) {
		v = func_0000C658(g_lst2, g_cnt2, prio);
		if (v != -1)
			return v;
	}
	return 0x80540010;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_noteOn);

int voice_noteOff(unsigned int v)
{
	SsVoice *p;
	SsVoice *q;

	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	p = &g_voice[v];
	switch (p->status) {
	case 0:
		return 0x80540012;
	case 2:
		if (p->i18 == 0)
			{
			q = func_0000C240(&g_cnt2, g_lst2, &g_cnt1, g_lst1, v);
			q->status = 1;
		}
		else
			{
			q = func_0000C240(&g_cnt2, g_lst2, &g_cnt9, g_lst9, v);
			q->status = 9;
		}
		break;
	case 3:
		if (p->i18 == 0)
			{
			q = func_0000C240(&g_cnt3, g_lst3, &g_cnt4, g_lst4, v);
			q->status = 4;
		}
		else
			{
			q = func_0000C240(&g_cnt3, g_lst3, &g_cnt7, g_lst7, v);
			q->status = 7;
		}
		break;
	case 6:
		if (p->i18 == 0)
			{
			q = func_0000C240(&g_cnt6, g_lst6, &g_cnt4, g_lst4, v);
			q->status = 4;
		}
		else
			{
			q = func_0000C240(&g_cnt6, g_lst6, &g_cnt8, g_lst8, v);
			q->status = 8;
		}
		break;
	}
	return 0;
}

int voice_setSustain(unsigned int v, unsigned int on)
{
	SsVoice *p;
	SsVoice *q;

	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	if (on >= 2)
		return 0x8054000a;
	p = &g_voice[v];
	if (p->status == 0)
		return 0x80540012;
	if (on == 0) {
		if (p->status == 7) {
			q = func_0000C240(&g_cnt7, g_lst7, &g_cnt4, g_lst4, v);
			q->status = 4;
			q->i18 = 0;
		} else if (p->status == 3) {
			p->i18 = 0;
		} else if (p->status == 2 || p->status == 6) {
			p->i18 = 0;
		}
	} else {
		if (p->status == 3)
			p->i18 = on;
		if (p->status == 2 || p->status == 6)
			p->i18 = on;
	}
	return 0;
}

int voice_setReservedVoice(unsigned int v, int flag)
{
	SsVoice *q;

	if (g_vstate == -1)
		return 0x80450001;
	if (v >= g_vmax)
		return 0x80540011;
	if (flag == 0) {
		if (g_voice[v].status != 0)
			return 0x8054000e;
		q = func_0000C240(&g_cnt0, g_lst0, &g_cnt1, g_lst1, v);
		q->status = 1;
	} else {
		if (g_voice[v].status == 0)
			return 0x8054000e;
		switch (g_voice[v].status) {
		case 1:
			q = func_0000C240(&g_cnt1, g_lst1, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 2:
			q = func_0000C240(&g_cnt2, g_lst2, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 3:
			q = func_0000C240(&g_cnt3, g_lst3, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 4:
			q = func_0000C240(&g_cnt4, g_lst4, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 5:
			q = func_0000C240(&g_cnt5, g_lst5, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 6:
			q = func_0000C240(&g_cnt6, g_lst6, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 7:
			q = func_0000C240(&g_cnt7, g_lst7, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 8:
			q = func_0000C240(&g_cnt8, g_lst8, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		case 9:
			q = func_0000C240(&g_cnt9, g_lst9, &g_cnt0, g_lst0, v);
			q->status = 0;
			break;
		}
	}
	return 0;
}

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

int func_0000C2D8(SsVoice *p)
{
	SsVoice *v;
	SsVoiceTone *t;
	int pitch;
	int pl, pr, el, er;

	if (p->i1C == 0)
		sceSasSetVoice(p->no, (void *)p->i20, p->i24, 1);
	else
		sceSasSetNoise(p->no, p->b28);

	v = &g_voice[p->no];
	t = &v->tone;
	pitch = sceSsNote2Pitch(t->bD, t->bE * 127 / 100, v->b5D, t->bC * 127 / 100);
	pitch = (unsigned int)(v->i2C * pitch) / 44100 + v->pitch;
	pitch = (pitch < 0x4000) ? pitch : 0x4000;
	pitch = (pitch > 1) ? pitch : 1;
	sceSasSetPitch(p->no, pitch);
	v->iC = v->pitch;

	func_0000C6F4(p->i34, p->vel, p->b38, p->pan, &pl, &pr);
	func_0000C6F4(p->i3C, p->sendVel, p->tone.b0, p->sendPan, &el, &er);
	sceSasSetVolume(p->no, pl, pr, el, er);
	sceSasSetSimpleADSR(p->no, p->tone.i4, p->tone.i8);
	p->b8 = p->vel;
	p->b9 = p->pan;
	p->bA = p->sendVel;
	p->bB = p->sendPan;
	if (sceSasSetKeyOn(p->no) < 0)
		return -1;
	return 0;
}

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
