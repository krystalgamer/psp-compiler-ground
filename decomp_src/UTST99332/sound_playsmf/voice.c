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
	unsigned char pad2[6];
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

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_init);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_refresh);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_allocVoice);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_noteOn);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_noteOff);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_setSustain);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_setReservedVoice);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_getVoiceByGroup);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_getVoiceByMidi);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_getVoiceByID);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_getVoiceByChannel);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", voice_getVoiceByChannel2);

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

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C240);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C2D8);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C488);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C658);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/voice", func_0000C6F4);
