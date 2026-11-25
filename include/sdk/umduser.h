#ifndef _UMDUSER_H
#define _UMDUSER_H
/* SDK prototypes as used by the decompiled code */
int sceUmdActivate(int mode, const char *aliasname);
int sceUmdWaitDriveStat(int stat);
int sceUmdDeactivate(int mode, const char *aliasname);
int sceUmdCheckMedium(void);
int sceUmdGetDriveStat(void);
#endif
