/* cflags: -O2 -frename-registers */
#include "common.h"

extern int D_000185C8;
#define g_state D_000185C8

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

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsInit);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsBindSoundData);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsUnbindSoundData);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsNoteOn);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsNoteOff);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsSetSustainHold);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsKeyOffByID);

int sceSsVoiceSetSustainHold(int a0, int a1)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_setSustain(a0, a1);
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsSetEffectParam);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsSMFBind);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", _sceSsSetExpVel);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", _sceSsGetExpVel);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsExit);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsSynthesis);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsNoteOnByTone);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsKeyOnByTone);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsVoiceNoteOnByTone);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsVoiceKeyOnByTone);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsGetVoice);

int sceSsVoiceKeyoff(int a0)
{
	if (g_state == -1)
		return 0x80450001;
	return voice_noteOff(a0);
}

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsVoiceSetReserveMode);

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

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsVoiceAllKeyOff);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", sceSsVoiceGetEndFlag);

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

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", func_00008544);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", func_00008628);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", func_0000872C);

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/libsndp", func_00008918);

