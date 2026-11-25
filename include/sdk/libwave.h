#ifndef _LIBWAVE_H
#define _LIBWAVE_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
int sceWaveInit(void);
int sceWaveExit(void);
int sceWaveStart(int priority);
int sceWaveEnd(void);
int sceWaveSetVoice(int voice, void *vag, int size, int loop);
int sceWavePlay(int voice, int vol_l, int vol_r);
#endif
