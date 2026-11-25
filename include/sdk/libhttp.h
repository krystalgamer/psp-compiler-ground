#ifndef _LIBHTTP_H
#define _LIBHTTP_H
/* SDK prototypes as used by the decompiled code */
int sceHttpInit(unsigned int poolsize);
int sceHttpEnd(void);
int sceHttpInitCache(unsigned int max_size);
int sceHttpEndCache(void);
int sceHttpsInitWithPath(int rootcert, int option, int reserved);
int sceHttpsEnd(void);
int sceHttpsLoadDefaultCert(int option, int reserved);
int sceHttpsDisableOption(unsigned int option);
#endif
