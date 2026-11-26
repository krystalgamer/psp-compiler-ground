/* cflags: -O2 -frename-registers */
#include "common.h"

typedef struct {
	unsigned char unk1;
	unsigned char vel;
	unsigned char pan;
	unsigned char unk3[5];
	int id;
	int unkC;
} SmfChannel;

typedef struct {
	unsigned char status;
	unsigned char unk1[8];
	unsigned char hd;
	unsigned char unkA[6];
	int tempo;
	int addTempo;
	int unk18;
	unsigned char *ptr;
	unsigned char unk20[6];
	unsigned char vel;
	unsigned char pan;
	unsigned char sendVel;
	unsigned char sendPan;
	unsigned char unk2A[2];
	unsigned int mute;
	int unk30[3];
	int delta;
	SmfChannel ch[16];
} SmfData;

extern int D_00128F98;
extern SmfData *D_00128F9C[128];
#define g_smfmax D_00128F98
#define g_smf D_00128F9C
int sceSsSetSustainHold(int a0, int a1, int a2);
int sceSsKeyOffByID(int id);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_bindSmf);

int smf_unbindSmf(unsigned int id)
{
	if (g_smfmax == 0)
		return 0x80450001;
	if (id >= 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	g_smf[id] = NULL;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_atick);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_play);

int smf_pause(unsigned int id)
{
	unsigned int i;

	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (g_smf[id]->status != 1)
		return 0x8054000b;
	for (i = 0; i < 16; i++) {
		sceSsSetSustainHold(i, 0, g_smf[id]->ch[i].id);
		sceSsKeyOffByID(g_smf[id]->ch[i].id);
	}
	g_smf[id]->status = 2;
	return 0;
}

int smf_resume(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (g_smf[id]->status != 2)
		return 0x8054000c;
	g_smf[id]->status = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_stop);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_setPlayVelocity);

int smf_getPlayVelocity(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	return g_smf[id]->vel;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_setPlaySendVelocity);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_setPlayPanpot);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", smf_setPlaySendPanpot);

int smf_setChannelMute(unsigned int id, unsigned int ch)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (ch >= 16)
		return 0x8054000a;
	g_smf[id]->mute &= ~(1 << ch);
	return 0;
}

int smf_setChannelMuteBit(unsigned int id, unsigned int bit)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	g_smf[id]->mute = (g_smf[id]->mute & 0xffff0000) | (bit & 0xffff);
	return 0;
}

int smf_init(int max)
{
	unsigned int i;

	if (max == 0)
		return -1;
	g_smfmax = max;
	for (i = 0; i < 128; i++)
		g_smf[i] = NULL;
	return 0;
}

int smf_setHdId(int id, int hd)
{
	g_smf[id]->hd = hd;
	g_smf[id]->status = 0;
	return 0;
}

int smf_addTempo(unsigned int id, int tempo)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	g_smf[id]->addTempo = tempo;
	return 0;
}

int smf_getTempo(unsigned int id)
{
	int tempo;

	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	tempo = g_smf[id]->tempo + g_smf[id]->addTempo;
	return tempo < 0 ? 0 : tempo;
}

int smf_getPlaySendVelocity(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	return g_smf[id]->sendVel;
}

int smf_getPlayPanpot(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	return g_smf[id]->pan;
}

int smf_getPlaySendPanpot(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	return g_smf[id]->sendPan;
}

int smf_getPlayStatus(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	return g_smf[id]->status;
}

int smf_resetChannelMute(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	g_smf[id]->mute = -1;
	return 0;
}

int smf_getChannelMuteBit(unsigned int id, unsigned int *bit)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	*bit = (unsigned short)g_smf[id]->mute;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_00009EDC);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_00009FA4);

static int func_0000A2C4(SmfData *smf)
{
	unsigned int v;
	unsigned char c;

	v = *smf->ptr++;
	if (v & 0x80) {
		v &= 0x7f;
		do {
			c = *smf->ptr++;
			v = (v << 7) + (c & 0x7f);
		} while ((signed char)c < 0);
	}
	smf->delta = v;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_0000A314);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_0000A444);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_0000A690);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_0000AB38);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", D_00017EAC);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", D_00017EB4);
