#ifndef _IOFILEMGR_H
#define _IOFILEMGR_H
/* SDK prototypes as used by the decompiled code (no Sony headers available). */
#include <kerneltypes.h>
#define SCE_O_RDONLY	0x0001
#define SCE_O_WRONLY	0x0002
#define SCE_O_RDWR	0x0003
#define SCE_O_CREAT	0x0200
#define SCE_O_TRUNC	0x0400
#define SCE_SEEK_SET	0
#define SCE_SEEK_CUR	1
#define SCE_SEEK_END	2
#include <psptypes.h>
struct SceIoStat {
	SceMode st_mode;
	unsigned int st_attr;
	SceOff st_size;
	ScePspDateTime st_ctime;
	ScePspDateTime st_atime;
	ScePspDateTime st_mtime;
	unsigned int st_private[6];
};
typedef struct SceIoStat SceIoStat;
int sceIoGetstat(const char *name, SceIoStat *buf);
SceUID sceIoOpen(const char *name, int flag, SceMode mode);
int sceIoClose(SceUID fd);
SceSSize sceIoRead(SceUID fd, void *buf, SceSize nbyte);
SceSSize sceIoWrite(SceUID fd, const void *buf, SceSize nbyte);
int sceIoRemove(const char *name);
SceOff sceIoLseek(SceUID fd, SceOff offset, int whence);
#endif
