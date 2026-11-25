#ifndef WAVEMGR_H
#define WAVEMGR_H
int WaveMgrInit(int channel, int format);
void WaveMgrTerm(void);
int WaveMgrGetFreeSize(void);
void WaveMgrSetFormat(int format);
void WaveMgrSetVolume(int volL, int volR);
void WaveMgrWriteStart(void);
int WaveMgrWrite(void *p, int size);
void WaveMgrWriteTerm(void);
int WaveMgrIsEnd(void);
#endif
