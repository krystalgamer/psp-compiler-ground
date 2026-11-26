#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
struct _anon1 { /* size 0xc */
    SceInt32 atracId;
    SceInt32 fd;
    SceInt32 outputChannel;
};
typedef struct _anon1 ScePlayArg;
typedef int SceSSize;
typedef unsigned int SceSize;
typedef void *ScePVoid;
typedef unsigned int SceUInt32;



SceInt32 init_atrac3plus(SceChar8 *filename, SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 ioutputChannel, ScePlayArg *pPlayArg);
SceInt32 play_atrac3plus(SceSize args, ScePVoid argp);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd);

/* SDK functions (tools/sdk_protos.h) */
int sceIoClose(int fd);
int printf(const char *fmt, ...);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoRead(int fd, void *buf, unsigned int nbyte);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3doubleplay/nonmatchings/at3plus", init_atrac3plus);

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3doubleplay/nonmatchings/at3plus", play_atrac3plus);

void release_at3playArgID(ScePlayArg *pPlayArg) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = pPlayArg->atracId;
    if ((temp_v0 < 0) || (temp_v0_2 = sceAtracReleaseAtracID(temp_v0), (temp_v0_2 >= 0))) {

    } else {
        printf("status = 0x%x (in sceAtracReleaseAtracID)\n", temp_v0_2);
    }
    if ((pPlayArg->fd < 0) || (temp_v0_3 = sceIoClose(pPlayArg->fd), (temp_v0_3 >= 0))) {

    } else {
        printf("status = 0x%x (in sceIoClose)\n", temp_v0_3);
    }
}

int sceAtracGetStreamDataInfo(SceInt32 atracID, SceUChar8 **ppucWritePointer, SceUInt32 *puiWritableByte, SceUInt32 *puiReadPosition);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceAtracAddStreamData(SceInt32 atracID, SceUInt32 uiAddByte);
static void at3plus_addData(SceInt32 atracId, SceInt32 fd)
{
	SceUChar8 *pucWritePointer;
	SceUInt32 uiWritableByte, uiReadPosition;
	SceInt32 status, iAddByte;

	status = sceAtracGetStreamDataInfo(atracId, &pucWritePointer, &uiWritableByte, &uiReadPosition);
	if (status < 0)
		printf("status = 0x%x (in sceAtracGetStreamDataInfo)", status);
	status = sceIoLseek(fd, uiReadPosition, 0);
	if (status < 0)
		printf("status = 0x%x (in sceIoLseek)", status);
	iAddByte = sceIoRead(fd, pucWritePointer, uiWritableByte);
	if (iAddByte < 0) {
		printf("status = 0x%x (in sceIoRead)", iAddByte);
		return;
	}
	status = sceAtracAddStreamData(atracId, (SceUInt32)iAddByte);
	if (status < 0)
		printf("status = 0x%x (in sceAtracAddStreamData)", status);
}
