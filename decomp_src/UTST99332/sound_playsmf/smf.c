/* cflags: -O2 -frename-registers */
#include "common.h"

typedef struct {
	unsigned char unk0;
	unsigned char vol;
	unsigned char exp;
	unsigned char pan;
	unsigned char unk4;
	unsigned char unk5[3];
	int id;
	int bend;
} SmfChannel;

typedef struct {
	unsigned char status;
	unsigned char unk1[3];
	unsigned char *data;
	signed char unk8;
	signed char hd;
	unsigned short division;
	unsigned char unkC;
	unsigned char unkD[3];
	int tempo;
	int addTempo;
	int unk18;
	unsigned char *ptr;
	int unk20;
	unsigned char unk24;
	signed char unk25;
	unsigned char vel;
	unsigned char pan;
	unsigned char sendVel;
	unsigned char sendPan;
	unsigned char unk2A[2];
	unsigned int mute;
	int unk30;
	int unk34;
	int unk38;
	int delta;
	SmfChannel ch[16];
} SmfData;

extern int D_00128F98;
extern SmfData *D_00128F9C[128];
#define g_smfmax D_00128F98
#define g_smf D_00128F9C
int sceSsSetSustainHold(int a0, int a1, int a2);
int sceSsKeyOffByID(int id);
int sceSsGetVoice(int ch, int id);
int _sceSsGetExpVel(int voice);
int sceSsVoiceSetPanpot(int voice, int pan);
int sceSsVoiceSetSendPanpot(int voice, int pan);
int sceSsVoiceSetVelocity(int voice, unsigned char vel);
int sceSsVoiceSetSendVelocity(int voice, unsigned char vel);

int func_00009EDC(SmfData *p, unsigned int id);
int func_0000A314(unsigned char *data, SmfData *p);

int smf_bindSmf(SmfData *smf, int size)
{
	unsigned int i;
	int r;

	if (g_smfmax == 0)
		return 0x80450001;
	if (size == 0)
		return 0x80450003;
	if (smf == NULL)
		return 0x80540004;
	for (i = 0; i < 128; i++) {
		if (g_smf[i] == NULL) {
			g_smf[i] = smf;
			func_00009EDC(smf, i);
			r = func_0000A314((unsigned char *)size, g_smf[i]);
			if (r != 0) {
				g_smf[i]->status = 3;
				g_smf[i] = NULL;
				return r;
			}
			return i;
		}
	}
	return 0x80540006;
}

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

int smf_play(unsigned int id, unsigned int vel, unsigned int pan, unsigned int sendVel, unsigned int sendPan, int count)
{
	if (g_smfmax == 0)
		return 0x80450001;
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (g_smf[id]->status != 0)
		return 0x80540009;
	if (count == 0)
		return 0x80540008;
	if (vel >= 128 || pan >= 128)
		return 0x8054000a;
	if (sendVel >= 128 || sendPan >= 128)
		return 0x8054000a;
	g_smf[id]->vel = vel;
	g_smf[id]->pan = pan;
	g_smf[id]->sendVel = sendVel;
	g_smf[id]->sendPan = sendPan;
	g_smf[id]->unk34 = count;
	g_smf[id]->unk38 = count;
	g_smf[id]->status = 1;
	return 0;
}

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

int smf_stop(unsigned int id)
{
	unsigned int i;

	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (g_smf[id]->status != 1 && g_smf[id]->status != 2)
		return 0x8054000d;
	for (i = 0; i < 16; i++) {
		sceSsSetSustainHold(i, 0, g_smf[id]->ch[i].id);
		sceSsKeyOffByID(g_smf[id]->ch[i].id);
	}
	g_smf[id]->ptr = g_smf[id]->data + 0x16;
	g_smf[id]->unk8 = -1;
	g_smf[id]->unk30 = 0;
	g_smf[id]->delta = 0;
	g_smf[id]->unkC = 1;
	g_smf[id]->status = 0;
	return 0;
}

int smf_setPlayVelocity(unsigned int id, unsigned int vel)
{
	unsigned int ch;
	unsigned int v;
	unsigned int mask;
	unsigned char e, x;
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (vel >= 128)
		return 0x8054000a;
	g_smf[id]->vel = vel;
	for (ch = 0; ch < 16; ch++) {
		mask = sceSsGetVoice(ch, g_smf[id]->ch[ch].id);
		if (mask != 0) {
		for (v = 0; v < 32; v++) {
			if ((mask >> v) & 1) {
				e = _sceSsGetExpVel(v);
				x = e * g_smf[id]->vel / 127;
				x = x * g_smf[id]->ch[ch].vol / 127;
				sceSsVoiceSetVelocity(v, x * g_smf[id]->ch[ch].exp / 127);
			}
		}
		}
	}
	return 0;
}

int smf_getPlayVelocity(unsigned int id)
{
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	return g_smf[id]->vel;
}

int smf_setPlaySendVelocity(unsigned int id, unsigned int vel)
{
	unsigned int ch;
	unsigned int v;
	unsigned int mask;
	unsigned char e, x;
	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (vel >= 128)
		return 0x8054000a;
	g_smf[id]->sendVel = vel;
	for (ch = 0; ch < 16; ch++) {
		mask = sceSsGetVoice(ch, g_smf[id]->ch[ch].id);
		if (mask != 0) {
		for (v = 0; v < 32; v++) {
			if ((mask >> v) & 1) {
				e = _sceSsGetExpVel(v);
				x = e * g_smf[id]->sendVel / 127;
				x = x * g_smf[id]->ch[ch].vol / 127;
				sceSsVoiceSetSendVelocity(v, x * g_smf[id]->ch[ch].exp / 127);
			}
		}
		}
	}
	return 0;
}

int smf_setPlayPanpot(unsigned int id, unsigned int pan)
{
	unsigned int ch;
	unsigned int v;
	unsigned int mask;
	int p;

	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (pan >= 128)
		return 0x8054000a;
	g_smf[id]->pan = pan;
	for (ch = 0; ch < 16; ch++) {
		mask = sceSsGetVoice(ch, g_smf[id]->ch[ch].id);
		if (mask != 0) {
		for (v = 0; v < 32; v++) {
			if ((mask >> v) & 1) {
				p = g_smf[id]->pan + g_smf[id]->ch[ch].pan - 64;
				p = p < 0 ? 0 : p;
				sceSsVoiceSetPanpot(v, p > 127 ? 127 : p);
			}
		}
		}
	}
	return 0;
}

int smf_setPlaySendPanpot(unsigned int id, unsigned int pan)
{
	unsigned int ch;
	unsigned int v;
	unsigned int mask;
	int p;

	if (id > 128)
		return 0x80540007;
	if (g_smf[id] == NULL)
		return 0x80540007;
	if (pan >= 128)
		return 0x8054000a;
	g_smf[id]->sendPan = pan;
	for (ch = 0; ch < 16; ch++) {
		mask = sceSsGetVoice(ch, g_smf[id]->ch[ch].id);
		if (mask != 0) {
		for (v = 0; v < 32; v++) {
			if ((mask >> v) & 1) {
				p = g_smf[id]->sendPan + g_smf[id]->ch[ch].pan - 64;
				p = p < 0 ? 0 : p;
				sceSsVoiceSetSendPanpot(v, p > 127 ? 127 : p);
			}
		}
		}
	}
	return 0;
}

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

extern const char D_00017EAC[];
extern const char D_00017EB4[];

static __inline__ int smf_chk(unsigned char *a, const char *b)
{
	return *(int *)a == *(const int *)b;
}

int func_0000A314(unsigned char *data, SmfData *p)
{
	unsigned char fmt[2];
	unsigned char div[2];
	unsigned char len[4];
	unsigned char sig[4];
	unsigned char *s;
	unsigned char *d;
	unsigned int i;
	int ret;

	sig[0] = data[0];
	sig[1] = data[1];
	sig[2] = data[2];
	sig[3] = data[3];
	ret = 0x80540005;
	if (smf_chk(sig, D_00017EAC)) {
		s = data + 8;
		i = 0;
		d = &fmt[1];
		for (; i < 2; i++)
			*d-- = *s++;
		ret = 0x80540005;
		if (*(unsigned short *)fmt == 0) {
			s = data + 12;
			i = 0;
			d = &div[1];
			for (; i < 2; i++)
				*d-- = *s++;
			sig[0] = data[14];
			sig[1] = data[15];
			sig[2] = data[16];
			sig[3] = data[17];
			s = data + 18;
			ret = 0x80540005;
			if (smf_chk(sig, D_00017EB4)) {
				i = 0;
				d = &len[3];
				for (; i < 4; i++)
					*d-- = *s++;
				p->ptr = data + 22;
				ret = 0;
				p->unk18 = *(int *)len;
				p->data = data;
				p->division = *(unsigned short *)div;
			}
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_0000A444);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", func_0000A690);

int _sceSsCalcAddPitch(int voice, int bend);
int sceSsVoiceSetPitch(int voice, int pitch);

int func_0000AB38(unsigned int ch, unsigned char lsb, unsigned char msb, SmfData *p)
{
	unsigned int bend;
	unsigned int mask;
	unsigned int v;

	bend = msb << 7;
	bend |= lsb;
	if (bend >= 0x4000)
		bend = 0x3FFF;
	ch &= 0xF;
	p->ch[ch].bend = bend;
	mask = sceSsGetVoice(ch, p->ch[ch].id);
	if (mask != 0) {
		for (v = 0; v < 32; v++) {
			if ((mask >> v) & 1)
				sceSsVoiceSetPitch(v, _sceSsCalcAddPitch(v, bend));
		}
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", D_00017EAC);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_playsmf/nonmatchings/smf", D_00017EB4);
