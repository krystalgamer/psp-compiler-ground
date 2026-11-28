/* cflags: -O2 -frename-registers */
#include "common.h"

extern int D_000185C8;
#define g_state D_000185C8
typedef struct { void *hd; void *bd; } SsSoundData;
typedef struct { int flag; int type; int delay; int feedback; int left; int right; int dry; int wet; } SsEffectParam;
extern SsSoundData *D_00128E94[];
extern unsigned int D_00128F14;
extern int D_00128F18[];
#define g_hd D_00128E94
#define g_maxvoice D_00128F14
#define g_expvel D_00128F18
int func_00008544();
int func_00008628();
int voice_getVoiceByChannel2(int ch, int a1);
int voice_setReservedVoice(int voice, int mode);
unsigned int sceSasGetEndFlag(void);
int smf_atick();
int voice_refresh(void *buf);
int sceSasExit(void);
int smf_bindSmf(void *smf, int size);
int smf_setHdId(int id, int hd);
int sceSasInit();
int smf_init(int n);
int voice_init(int n);
int sceSasSetEffectType(int type);
int sceSasSetEffectParam(int delay, int feedback);
int sceSasSetEffectVolume(int left, int right);
int sceSasSetEffect(int dry, int wet);
unsigned int voice_getVoiceByID(int id);

int voice_setSustain(int a0, int a1);
int voice_noteOff(int a0);
int voice_setPitch(int a0, int a1);
int voice_setVelocity(int a0, int a1);
int voice_setPan(int a0, int a1);
int voice_setSendVelocity(int a0, int a1);
int voice_setSendPan(int a0, int a1);
int sceSasGetEnvelope(int a0);
int smf_unbindSmf(int a0);
int smf_play(int a0, int a1, int a2, int a3, int a4, int a5);
int smf_pause(int a0);
int smf_resume(int a0);
int smf_stop(int a0);
int smf_addTempo(int a0, int a1);
int smf_getTempo(int a0);
int smf_setPlayVelocity(int a0, int a1);
int smf_getPlayVelocity(int a0);
int smf_setPlaySendVelocity(int a0, int a1);
int smf_getPlaySendVelocity(int a0);
int smf_setPlayPanpot(int a0, int a1);
int smf_getPlayPanpot(int a0);
int smf_setPlaySendPanpot(int a0, int a1);
int smf_getPlaySendPanpot(int a0);
int smf_getPlayStatus(int a0);
int smf_setChannelMute(int a0, int a1);
int smf_resetChannelMute(int a0);
int smf_setChannelMuteBit(int a0, int a1);
int smf_getChannelMuteBit(int a0, int a1);
int voice_getVoiceStatus(int a0);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", _sceSsCalcAddPitch);

int sceSsInit(int maxvoice)
{
	int ret;
	int i;

	ret = sceSasInit();
	if (ret != 0)
		return ret;
	smf_init(256);
	ret = voice_init(maxvoice);
	if (ret != 0)
		return ret;
	for (i = 0; i < 32; i++)
		g_hd[i] = 0;
	for (i = 0; i < 32; i++)
		g_expvel[i] = 0x7f;
	g_maxvoice = maxvoice;
	g_state = 0;
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsBindSoundData);

int sceSsUnbindSoundData(unsigned int hd)
{
	if (g_state == -1)
		return 0x80450001;
	if (hd >= 33)
		return 0x80450002;
	if (g_hd[hd] == 0)
		return 0x80450002;
	g_hd[hd] = 0;
	return 0;
}

typedef struct { unsigned int n; int pad[3]; unsigned int tone[1]; } SsProgParam;
typedef struct { int pad[4]; unsigned int min; unsigned int max; } SsToneParam;
int sdphd_getProgramParam(void *pHd, unsigned int idx, void **ppParam);
int sdphd_getToneParam(void *pHd, unsigned int idx, void **ppParam);
int sceSsNoteOn(unsigned int hd, int ch, unsigned int prog, unsigned int note, int a4, int a5, int a6)
{
	SsProgParam *pp;
	SsToneParam *tp;
	unsigned int i;
	int v;
	int ret = 0;

	if (g_state == -1)
		return 0;
	if (hd > 32)
		return 0;
	if (g_hd[hd] == 0)
		return 0;
	if (sdphd_getProgramParam((void *)g_hd[hd]->hd, prog, (void **)&pp) != 0)
		return 0;
	for (i = 0; i < pp->n; i++) {
		if (sdphd_getToneParam((void *)g_hd[hd]->hd, pp->tone[i], (void **)&tp) >= 0) {
			if (note >= tp->min && note <= tp->max) {
				v = func_00008544(hd, pp->tone[i], ch, note, 0, a4, a6, a5);
				if (v >= 0)
					ret |= 1 << v;
			}
		}
	}
	return ret;
}

typedef struct { unsigned char ch; unsigned char note; } SsMidiKey;
unsigned int voice_getVoiceByMidi(SsMidiKey *key, int a1);
int sceSsNoteOff(unsigned int ch, unsigned int note, int id)
{
	SsMidiKey key;
	unsigned int voices;
	unsigned int i;
	int ret = 0;

	if (g_state == -1)
		return 0;
	if (ch >= 16 || note >= 128)
		return 0;
	key.ch = ch;
	key.note = note;
	voices = voice_getVoiceByMidi(&key, id);
	if (voices != 0) {
		for (i = 0; i < g_maxvoice; i++) {
			if ((voices >> i) & 1) {
				if (voice_noteOff(i) == 0)
					ret |= 1 << i;
			}
		}
	}
	return ret;
}

int sceSsSetSustainHold(unsigned int ch, unsigned int on, int id)
{
	unsigned int voices;
	unsigned int i;
	int ret = 0;

	if (g_state == -1)
		return 0;
	if (ch >= 16)
		return 0;
	if (on >= 2)
		return 0;
	voices = voice_getVoiceByChannel(ch, id);
	if (voices != 0) {
		for (i = 0; i < g_maxvoice; i++) {
			if ((voices >> i) & 1) {
				if (voice_setSustain(i, on) == 0)
					ret |= 1 << i;
			}
		}
	}
	return ret;
}

int sceSsKeyOffByID(int id)
{
	unsigned int ret = 0;
	unsigned int mask;
	unsigned int i;

	if (g_state == -1)
		return 0;
	mask = voice_getVoiceByID(id);
	if (mask != 0) {
		for (i = 0; i < g_maxvoice; i++) {
			if ((mask >> i) & 1) {
				if (voice_noteOff(i) == 0)
					ret |= 1 << i;
			}
		}
	}
	return ret;
}

int sceSsVoiceSetSustainHold(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setSustain(a0, a1);
}

int sceSsSetEffectParam(SsEffectParam *p)
{
	int ret;

	if (g_state == -1)
		return 0x80450001;
	if (p->flag & 1) {
		ret = sceSasSetEffectType(p->type);
		if (ret != 0)
			return ret;
	}
	if (p->flag & 2) {
		ret = sceSasSetEffectParam(p->delay, p->feedback);
		if (ret != 0)
			return ret;
	}
	if (p->flag & 4) {
		ret = sceSasSetEffectVolume(p->left, p->right);
		if (ret != 0)
			return ret;
	}
	if (p->flag & 8) {
		ret = sceSasSetEffect(p->dry, p->wet);
		if (ret != 0)
			return ret;
	}
	return 0;
}

int sceSsSMFBind(void *smf, int size, unsigned int hd)
{
	int ret;

	if (g_state == -1)
		return 0x80450001;
	if (hd >= 33)
		return 0x80450002;
	if (g_hd[hd] == 0)
		return 0x80450002;
	ret = smf_bindSmf(smf, size);
	if (ret < 0)
		return ret;
	smf_setHdId(ret, hd);
	return ret;
}

void _sceSsSetExpVel(int ch, int vel)
{
	g_expvel[ch] = vel;
}

int _sceSsGetExpVel(int ch)
{
	return g_expvel[ch];
}

int sceSsExit(void)
{
	int ret;

	if (g_state == -1)
		return 0x80450001;
	ret = sceSasExit();
	if (ret != 0)
		return ret;
	g_state = -1;
	return 0;
}

int sceSsSynthesis(void *buf)
{
	if (g_state == -1)
		return 0x80450001;
	smf_atick();
	voice_refresh(buf);
	return 0;
}

int sceSsNoteOnByTone(int a0, int a1, int a2, int a3, int a4)
{
	return func_00008544(a0, a1, 0xff, a2, 0, 0, a3, a4);
}

int sceSsKeyOnByTone(int a0, int a1, int a2, int a3, int a4)
{
	return func_00008544(a0, a1, 0xff, 0xff, a2, 0, a3, a4);
}

int sceSsVoiceNoteOnByTone(int a0, int a1, int a2, int a3, int a4, int a5)
{
	return func_00008628(a0, a1, a2, 0xff, a3, 0, 0, a4, a5);
}

int sceSsVoiceKeyOnByTone(int a0, int a1, int a2, int a3, int a4, int a5)
{
	return func_00008628(a0, a1, a2, 0xff, 0xff, a3, 0, a4, a5);
}

int sceSsGetVoice(unsigned int ch, int a1)
{
	int ret = 0;

	if (g_state != -1) {
		if (ch < 16)
			ret = voice_getVoiceByChannel2(ch, a1);
	}
	return ret;
}

int sceSsVoiceKeyoff(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_noteOff(a0);
}

int sceSsVoiceSetReserveMode(int voice, unsigned int mode)
{
	if (g_state == -1)
		return 0x80450001;
	if (mode >= 2)
		return 0x8054000a;
	return voice_setReservedVoice(voice, mode);
}

int sceSsVoiceSetPitch(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setPitch(a0, a1);
}

int sceSsVoiceSetVelocity(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setVelocity(a0, a1);
}

int sceSsVoiceSetPanpot(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setPan(a0, a1);
}

int sceSsVoiceSetSendVelocity(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setSendVelocity(a0, a1);
}

int sceSsVoiceSetSendPanpot(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setSendPan(a0, a1);
}

int sceSsVoiceAllKeyOff(void)
{
	int i;

	if (g_state == -1)
		return 0x80450001;
	for (i = 0; i < 32; i++) {
		sceSsVoiceSetSustainHold(i, 0);
		voice_noteOff(i);
	}
	return 0;
}

int sceSsVoiceGetEndFlag(int voice)
{
	if (g_state == -1)
		return 0x80450001;
	return (sceSasGetEndFlag() >> voice) & 1;
}

int sceSsVoiceGetEnvelope(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return sceSasGetEnvelope(a0);
}

int sceSsSMFUnbind(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_unbindSmf(a0);
}

int sceSsSMFPlay(int a0, int a1, int a2, int a3, int a4, int a5)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_play(a0, a1, a2, a3, a4, a5);
}

int sceSsSMFPause(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_pause(a0);
}

int sceSsSMFResume(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_resume(a0);
}

int sceSsSMFStop(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_stop(a0);
}

int sceSsSMFAddTempo(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_addTempo(a0, a1);
}

int sceSsSMFGetTempo(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getTempo(a0);
}

int sceSsSMFSetPlayVelocity(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_setPlayVelocity(a0, a1);
}

int sceSsSMFGetPlayVelocity(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getPlayVelocity(a0);
}

int sceSsSMFSetPlaySendVelocity(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_setPlaySendVelocity(a0, a1);
}

int sceSsSMFGetPlaySendVelocity(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getPlaySendVelocity(a0);
}

int sceSsSMFSetPlayPanpot(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_setPlayPanpot(a0, a1);
}

int sceSsSMFGetPlayPanpot(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getPlayPanpot(a0);
}

int sceSsSMFSetPlaySendPanpot(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_setPlaySendPanpot(a0, a1);
}

int sceSsSMFGetPlaySendPanpot(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getPlaySendPanpot(a0);
}

int sceSsSMFGetPlayStatus(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getPlayStatus(a0);
}

int sceSsSMFSetChannelMute(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_setChannelMute(a0, a1);
}

int sceSsSMFResetChannelMute(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_resetChannelMute(a0);
}

int sceSsSMFSetPlayChannel(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_setChannelMuteBit(a0, a1);
}

int sceSsSMFGetPlayChannel(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return smf_getChannelMuteBit(a0, a1);
}

int sceSsVoiceGetStatus(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_getVoiceStatus(a0);
}

typedef struct { int vag; int prio; int group; unsigned char nclk; unsigned char padD[3]; int pad10[4]; int adsr1; unsigned char b24; unsigned char pad25[3]; int adsr2; unsigned char b2C; unsigned char pad2D[3]; unsigned char b30; unsigned char pad31[3]; unsigned char b34; unsigned char pad35[3]; unsigned char b38; unsigned char pad39[7]; unsigned char b40; unsigned char pad41[3]; unsigned char b44; unsigned char pad45[11]; int i50; int i54; } SsTone;
typedef struct { int offset; int loop; int size; } SsVag;
typedef struct { int noise; char * addr; int size; unsigned char nclk; unsigned char padD[3]; int loop; int pitch; int adsr1; unsigned char b1C; unsigned char pad1D[3]; int adsr2; unsigned char b24; unsigned char pad25[3]; int i28; int i2C; signed char b30; unsigned char b31; signed char b32; unsigned char b33; unsigned char b34; unsigned char pad35[3]; int group; int prio; } SsVoiceTone2;
typedef struct { int i0; unsigned int hd; unsigned int i8; SsVoiceTone2 tone; unsigned char ch; unsigned char note; unsigned char pad4E[2]; int i50; int i54; int pad58[2]; } SsVoiceParam;
int func_00008544(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
	SsVoiceParam param;
	unsigned int voices;
	int i;
	int ret;

	ret = func_0000872C(a0, a1, a2, a3, a4, a5, a6, a7, &param);
	if (ret != 0)
		return ret;
	if (param.tone.group != 0) {
		voices = voice_getVoiceByGroup(param.tone.group, param.tone.prio);
		if (voices != 0) {
			for (i = 0; i < (int)g_maxvoice; i++) {
				if ((voices >> i) & 1) {
					sceSsVoiceSetSustainHold(i, 0);
					voice_noteOff(i);
				}
			}
		}
	}
	i = voice_allocVoice(param.tone.prio);
	if (i < 0)
		return 0x80540010;
	ret = voice_noteOn(i, &param);
	if (ret != 0)
		return ret;
	return i;
}

int func_00008628(int a0, unsigned int voice, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
	SsVoiceParam param;
	unsigned int voices;
	int ret;

	if (voice >= g_maxvoice)
		return 0x80540011;
	ret = func_0000872C(a0, a2, a3, a4, a5, a6, a7, a8, &param);
	if (ret != 0)
		return ret;
	if (param.tone.group != 0) {
		voices = voice_getVoiceByGroup(param.tone.group, param.tone.prio);
		if (voices != 0) {
			for (voice = 0; voice < g_maxvoice; voice++) {
				if ((voices >> voice) & 1) {
					sceSsVoiceSetSustainHold(voice, 0);
					voice_noteOff(voice);
				}
			}
		}
	}
	ret = voice_noteOn(voice, &param);
	if (ret < 0)
		return ret;
	return voice;
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", func_0000872C);

int sdphd_getVagParam(void *pHd, unsigned int idx, void **ppParam);
int func_00008918(unsigned int hd, unsigned int idx, SsVoiceTone2 *out)
{
	SsTone *tp;
	SsVag *vp;

	if (sdphd_getToneParam((void *)g_hd[hd]->hd, idx, (void **)&tp) < 0)
		return 0x80540005;
	if (tp->vag == -1) {
		out->noise = 1;
		out->nclk = tp->nclk;
	} else {
		if (sdphd_getVagParam((void *)g_hd[hd]->hd, tp->vag, (void **)&vp) < 0)
			return 0x80540005;
		out->noise = 0;
		out->addr = (char *)g_hd[hd]->bd + vp->offset;
		out->size = vp->size;
		out->loop = vp->loop;
	}
	out->adsr1 = tp->adsr1;
	out->b1C = tp->b24;
	out->adsr2 = tp->adsr2;
	out->b24 = tp->b2C;
	out->i28 = tp->i50;
	out->i2C = tp->i54;
	out->b30 = tp->b38;
	out->b31 = tp->b30;
	out->b32 = tp->b34;
	out->group = tp->group;
	out->prio = tp->prio;
	out->b33 = tp->b40;
	out->b34 = tp->b44;
	return 0;
}

