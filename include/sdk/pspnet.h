#ifndef _PSPNET_H
#define _PSPNET_H
/* SDK prototypes as used by the decompiled code */
#include <kerneltypes.h>
int sceNetInit(int poolsize, int calloutprio, int calloutstack, int netintrprio, int netintrstack);
int sceNetTerm(void);
int sceNetFreeThreadinfo(SceUID thid);
#endif
