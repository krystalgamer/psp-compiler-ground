#ifndef SDK_DISPLAYSVC_H
#define SDK_DISPLAYSVC_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
int sceDisplayWaitVblankStart(void);
int sceDisplayWaitVblankStartCB(void);
int sceDisplaySetMode(int mode, int width, int height);
int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);
#endif
