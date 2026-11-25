#include "common.h"

/* declarations recovered from DWARF */
typedef int SceInt32;
typedef int SceUID;
typedef int SceMode;
typedef unsigned int SceSize;
typedef int SceSSize;

extern SceUID gDvdUmdIoSemaphoreId;

SceInt32 DvdUmdRetryOpen(const char *filepath, int flag, SceMode mode);
static int DvdUmdRetryWaitSema(void);
static int DvdUmdRetrySignalSema(void);
SceInt32 DvdUmdRetryRead(SceUID fd, unsigned char *readbuf, SceSize readsize);
SceInt32 DvdUmdRetryOpenCB(const char *filepath, int flag, SceMode mode);
SceInt32 DvdUmdRetryReadCB(SceUID fd, unsigned char *readbuf, SceSize readsize);
static SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sceKernelDeleteSema(int semid);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sceIoRead(int fd, void *buf, unsigned int nbyte);


int DvdUmdIoInit(void) {
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    if (gDvdUmdIoSemaphoreId < 0) {
        temp_v0 = sceKernelCreateSema("UMD_SAMPLE_IO_SEMA", 0U, 1, 1, NULL);
        var_v1 = temp_v0;
        if (temp_v0 >= 0) {
            gDvdUmdIoSemaphoreId = temp_v0;
            var_v1 = 0;
        }
    }
    return var_v1;
}

int DvdUmdIoTerm(void) {
    int temp_a0;

    if (gDvdUmdIoSemaphoreId >= 0) {
        sceUmdCancelWaitDriveStat();
        sceKernelWaitSema(gDvdUmdIoSemaphoreId, 1, NULL);
        temp_a0 = gDvdUmdIoSemaphoreId;
        gDvdUmdIoSemaphoreId = -1;
        sceKernelDeleteSema(temp_a0);
    }
    return 0;
}

int DvdUmdRetryWaitSemaCB(void) {
    return sceKernelWaitSemaCB(gDvdUmdIoSemaphoreId, 1, 0);
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryOpen);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", D_00030B1C);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", D_00030B30);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryRead);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryOpenCB);

int DvdUmdReadNoRetry(int fd, unsigned char *readbuf, unsigned int readsize) {
    int var_v1;

    var_v1 = 0;
    if (sceUmdGetDriveStat() & 0x20) {
        var_v1 = sceIoRead(fd, readbuf, readsize);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", DvdUmdRetryReadCB);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/dvdumd_io", __psp_libinfo___30B80);
