#ifndef SDK_LIBGU_H
#define SDK_LIBGU_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
#endif
