#ifndef _LIBWAVE_H
#define _LIBWAVE_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
int sceWaveInit(void);
int sceWaveExit(void);
int sceWaveStart(int priority);
int sceWaveEnd(void);
int sceWaveSetVoice(int voice, void *vag, int size, int loop);
int sceWavePlay(int voice, int vol_l, int vol_r);
int sceWaveStop(int voice);
int sceWaveGetStat(int voice);
int sceWaveAudioSetSample(int channel, int samples);
int sceWaveAudioWriteBlocking(int channel, int vol_l, int vol_r, void *buf);
int sceWaveAudioSetVolume(int channel, int vol_l, int vol_r);
int sceWaveAudioSetFormat(int channel, int format);
int sceWaveAudioGetRestSample(int channel);
#endif
