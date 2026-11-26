#include "common.h"

/* declarations recovered from DWARF */
typedef int SceInt32;
typedef int SceUID;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceInt32 atracID;
    SceUID finishflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;

extern int bgm_at3;
/* bgm_at3size is an absolute linker symbol (the size of the linked-in .at3 file) */
extern char PRX_ZERO[];
#define bgm_at3size (*(int *)(PRX_ZERO + 0x7F304))
extern SceUID thread_id01;
extern SceAtracArg atracArg;

int at3start(void);
int at3end(void);


SceInt32 init_atrac3plus(unsigned char *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg);
int play_atrac3plus(unsigned int args, void *argp);
void finish_atrac3plus(SceAtracArg *pPlayArg);
int sceWaveInit(void);
SceUID sceKernelCreateThread(const char *, int (*)(unsigned int, void *), int, int, unsigned int, void *);
int sceKernelStartThread(SceUID, unsigned int, void *);
int sceKernelWaitThreadEnd(SceUID, unsigned int *);
int sceKernelDeleteThread(SceUID);
int printf(const char *, ...);

void init_sound(void)
{
    sceWaveInit();
}

int at3start(void)
{
    SceInt32 status;
    SceInt32 thread_status;

    status = init_atrac3plus((unsigned char *)&bgm_at3, (int)&bgm_at3size, 1, &atracArg);
    if (status < 0) {
        printf("init_atrac3plus error: 0x%08x\n", status);
        return -1;
    }
    thread_id01 = sceKernelCreateThread("thread01", play_atrac3plus, 0x10, 0x10000, 0, NULL);
    if (thread_id01 < 0) {
        status = thread_id01;
        printf("sceKernelCreateThread:0x%08X\n", status);
        return -1;
    }
    thread_status = sceKernelStartThread(thread_id01, sizeof(SceAtracArg), &atracArg);
    if (thread_status != 0) {
        status = thread_status;
        printf("sceKernelStartThread:0x%08X\n", status);
        thread_status = sceKernelDeleteThread(thread_id01);
        if (thread_status != 0) {
            printf("sceKernelDeleteThread: 0x%08X\n", thread_status);
        }
        return -1;
    }
    return status;
}

int at3end(void)
{
    SceInt32 status = 0;
    SceInt32 thread_status;

    finish_atrac3plus(&atracArg);
    thread_status = sceKernelWaitThreadEnd(thread_id01, 0);
    if (thread_status != 0) {
        status = thread_status;
        printf("sceKernelWaitThread: 0x%08X\n", thread_status);
    }
    thread_status = sceKernelDeleteThread(thread_id01);
    if (thread_status != 0) {
        status = thread_status;
        printf("sceKernelDeleteThread: 0x%08X\n", thread_status);
    }
    return status;
}
