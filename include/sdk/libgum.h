#ifndef SDK_LIBGUM_H
#define SDK_LIBGUM_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
#endif
