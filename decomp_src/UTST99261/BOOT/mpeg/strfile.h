#ifndef STRFILE_H
#define STRFILE_H
typedef struct {
	SceUID fd;
	SceChar8 assignName[10];
} StrFile;

typedef SceUID (*FUNC_OPEN)(const char *, int, SceMode);
typedef int (*FUNC_CLOSE)(SceUID);
typedef SceOff (*FUNC_LSEEK)(SceUID, SceOff, int);
typedef SceSSize (*FUNC_READ)(SceUID, void *, SceSize);

SceInt32 strFileAssign(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileUnassign(StrFile *file);
SceInt32 strFileOpen(StrFile *file, const SceChar8 *filename, SceInt32 flags);
SceInt32 strFileClose(StrFile *file);
SceInt32 strFileRead(StrFile *file, void *buff, SceInt32 size);
SceOff strFileLseek(StrFile *file, SceOff offset, SceInt32 whence);
#endif
