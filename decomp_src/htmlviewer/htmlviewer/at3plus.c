#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char SceUChar8;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x10 */
    SceInt32 atracID;
    SceUID finishflag;
    SceInt32 outputChannel;
    SceInt32 iEndSample;
};
typedef struct _anon1 SceAtracArg;
typedef int SceSSize;
typedef unsigned int SceSize;
typedef unsigned int SceUInt32;



SceInt32 init_atrac3plus(SceUChar8 *pucReadBuf, SceInt32 iInputBufferSize, SceInt32 iOutputChannel, SceAtracArg *pPlayArg);
int play_atrac3plus(SceSize args, void *argp);
void finish_atrac3plus(SceAtracArg *pPlayArg);
static void release_arg(SceAtracArg *pPlayArg);

typedef short SceShort16;
int printf(const char *, ...);
void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
int sceAtracSetDataAndGetID(void *, SceSize);
int sceAtracGetSoundSample(int, int *, int *, int *);
int sceAtracSetLoopNum(int, int);
int sceAtracReleaseAtracID(int);
int sceAtracGetRemainFrame(int, int *);
int sceAtracDecodeData(int, SceShort16 *, int *, int *, int *);
int sceAtracGetInternalErrorInfo(int, int *);
SceUID sceKernelCreateEventFlag(const char *, int, int, void *);
int sceKernelDeleteEventFlag(SceUID);
int sceKernelSetEventFlag(SceUID, unsigned int);
int sceKernelPollEventFlag(SceUID, unsigned int, unsigned int, unsigned int *);
int sceKernelExitThread(int);
int sceWaveAudioSetSample(int, int);
int sceWaveAudioWriteBlocking(int, int, int, void *);

INCLUDE_ASM("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", init_atrac3plus);

int play_atrac3plus(SceSize args, void *argp)
{
    SceAtracArg *pPlayArg = (SceAtracArg *)argp;
    SceInt32 status;
    SceUInt32 finishflag;
    SceUInt32 uiWritePosition = 0;
    SceUInt32 uiPlayPosition = 0;
    SceInt32 iRemainFrame;
    SceInt32 iReadThreshold;
    SceInt32 iVol = 0x8000;
    SceInt32 fadeoutflag = 0;
    SceInt32 *outputBuf;
    SceInt32 aiOutputBuf[8206];

    outputBuf = (SceInt32 *)((unsigned int)&aiOutputBuf[15] & ~63);
    status = sceAtracGetRemainFrame(pPlayArg->atracID, &iRemainFrame);
    if (status < 0) {
        printf("sceAtracGetRemainFrame err 0x%x\n", status);
    }
    do {
        SceUInt32 sample;

        status = sceAtracDecodeData(pPlayArg->atracID, (SceShort16 *)(outputBuf + uiWritePosition), (int *)&sample, (int *)&finishflag, &iRemainFrame);
        if (status < 0) {
            SceInt32 innerInfo;
            sceAtracGetInternalErrorInfo(pPlayArg->atracID, &innerInfo);
            printf("sceAtracDecodeData err 0x%x (%d)\n", status, innerInfo);
            break;
        }
        uiWritePosition += sample;
        if (uiWritePosition - uiPlayPosition >= 2048) {
            SceInt32 output_samples = (uiWritePosition - uiPlayPosition) & ~63;
            sceWaveAudioSetSample(pPlayArg->outputChannel, output_samples);
            sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, outputBuf + uiPlayPosition);
            uiPlayPosition += output_samples;
        }
        if (uiWritePosition >= 6144) {
            uiWritePosition -= uiPlayPosition;
            memcpy(outputBuf, outputBuf + uiPlayPosition, uiWritePosition * 4);
            uiPlayPosition = 0;
        }
        if (fadeoutflag != 0) {
            iVol -= 0x400;
            if (iVol < 0) {
                iVol = 0;
                finishflag = 1;
            }
        } else {
            status = sceKernelPollEventFlag(pPlayArg->finishflag, 1, 1, 0);
            fadeoutflag = (status == 0);
            if (status < 0 && status != (SceInt32)0x800201AF) {
                printf("status = 0x%x(in sceKernelPollEventFlag)\n", status);
            }
        }
    } while (finishflag == 0);
    if (iVol != 0 && uiPlayPosition < uiWritePosition) {
        SceInt32 paddingSize = 2048 - (uiWritePosition - uiPlayPosition);
        memset(outputBuf + uiWritePosition, 0, paddingSize * 4);
        sceWaveAudioSetSample(pPlayArg->outputChannel, 2048);
        sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, outputBuf + uiPlayPosition);
    }
    sceWaveAudioWriteBlocking(pPlayArg->outputChannel, iVol, iVol, 0);
    release_arg(pPlayArg);
    sceKernelExitThread(0);
    return 0;
}

void finish_atrac3plus(SceAtracArg *pPlayArg)
{
    SceInt32 status;

    status = sceKernelSetEventFlag(pPlayArg->finishflag, 1);
    if (status < 0) {
        printf("status = 0x%x(in sceKernelSetEventFlag)\n", status);
    }
}

static void release_arg(SceAtracArg *pPlayArg)
{
    SceInt32 status;

    if (pPlayArg->atracID >= 0) {
        status = sceAtracReleaseAtracID(pPlayArg->atracID);
        if (status < 0) {
            printf("status = 0x%x(in sceAtracReleaseID)\n", status);
        }
    }
    if (pPlayArg->finishflag >= 0) {
        sceKernelDeleteEventFlag(pPlayArg->finishflag);
    }
}

/* bgm_at3 and the icons are a separate 16-aligned object in the original link */
__asm__(".section .rodata\n\t.space 4\n\t.previous");
INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", bgm_at3);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", D_0007F304);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", _icon0);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", _icon1);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", _pic1);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", _snd0);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/at3plus", _icon_new);
