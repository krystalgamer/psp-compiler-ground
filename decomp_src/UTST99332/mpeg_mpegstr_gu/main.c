#include "common.h"

/* declarations recovered from DWARF */
typedef void SceVoid;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct SceKernelLMOption;
typedef unsigned int SceSize;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct SceMpegRingbuffer;
typedef SceInt32 (*SceMpegRBCallback)(SceVoid *, SceInt32, SceVoid *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    SceVoid *m_pBuf;
    SceMpegRBCallback callback;
    SceVoid *m_CallbackData;
    SceVoid *pPack;
    SceInt32 iSemaRB;
    SceVoid *mp;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegStream;
typedef unsigned int SceUInt32;
typedef SceUInt32 SceMpegStreamId;
typedef unsigned char SceUChar8;
typedef short int SceShort16;
struct SceMpegStream { /* size 0x40 */
    SceMpegStreamId qStreamId;
    SceMpegStreamId qStreamIdMask;
    SceVoid *m_pRAPICtrlStream;
    SceUChar8 *m_pRAPI;
    SceInt32 m_iAuNum;
    SceInt32 m_iPesPacketForwardSize;
    SceInt32 m_iPesPacketForwardFlag;
    SceShort16 m_iPesPacketAULocator;
    SceShort16 reserved;
    SceInt32 m_iPesPacketNum;
    SceInt32 m_iAuSize;
    SceInt32 m_iBoundarySize;
    SceInt32 m_iAuSizeOfProceed;
    SceUInt32 m_iGetAuMode;
    SceInt32 m_iPayloadHeaderRemainderFlag;
    SceInt32 m_iPayloadHeaderRemainderSize;
    SceChar8 m_cPayloadHeaderBuf[4];
};
typedef struct SceMpegStream SceMpegStream;
struct SceMpegAu;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
typedef struct SceMpegAu SceMpegAu;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x38 */
    SceUID lock_sema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceChar8 *workBuf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 pixelFormat;
    SceInt32 displayMode;
    SceInt32 scale;
    t_conditionCtrl *pCtrl;
    SceMpeg *pMpeg;
};
typedef struct t_displayBuffer t_displayBuffer;
struct t_ringBuffer;
struct t_ringBuffer { /* size 0x14 */
    SceInt32 dataLen;
    SceUID ringbufSema;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct t_ringBuffer t_ringBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_avSyncControl;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_avSyncControl t_avSyncControl;
struct t_mpegStreamData;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef struct t_mpegStreamData t_mpegStreamData;
typedef SceUChar8 *SceMpegHandle;
struct _anon2;
struct _anon2 { /* size 0x8 */
    SceInt32 iDecodeMode;
    SceInt32 iPixelFormat;
};
typedef struct _anon2 SceMpegAvcMode;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};
typedef struct t_playInfo t_playInfo;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern SceInt32 sce_newlib_heap_kb_size;
extern SceInt32 audioFlag;
extern SceUID dispThread;
extern SceUID readThread;
extern SceUID soundThread;
extern t_playInfo playInfo;
extern SceUInt32 cont;

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl);
static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(t_displayBuffer *pDisp);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);


static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize = 0x800;
	SceInt32 iReadSize;
	StrFile *pStrFile = (StrFile *)CallbackData;

	iReadSize = strFileRead(pStrFile, pBuf, iNum * iTypeSize);

	if (iReadSize == (SceInt32)0x80210003 || iReadSize == (SceInt32)0x80210001) {
		return 0;
	}

	if (iReadSize % iTypeSize != 0) {
		return -1;
	}

	return iReadSize / iTypeSize;
}

int exit_func(int count, int arg1, void *arg2) {
    setPlayerEndCondition((t_conditionCtrl *) arg2);
    if (audioFlag != 1) {

    } else {
        sceKernelWaitThreadEnd(soundThread, 0);
    }
    sceKernelWaitThreadEnd(dispThread, 0);
    sceKernelWaitThreadEnd(readThread, 0);
    sceKernelExitGame();
    return 0;
}

SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option)
{
	SceInt32 res;
	SceInt32 mresult;

	do {
		*mid = sceKernelLoadModule(filename, 0, option);
	} while (*mid < 0);

	do {
		res = sceKernelStartModule(*mid, 0, NULL, &mresult, NULL);
	} while (res < 0);

	return 0;
}

SceInt32 unloadModule(SceUID *mid)
{
	SceInt32 mresult;

	if (sceKernelStopModule(*mid, 0, NULL, &mresult, NULL) < 0) {
		printf("fatal error : sceKernelStopModule\n");
		return -1;
	}

	if (sceKernelUnloadModule(*mid) < 0) {
		printf("fatal error : sceKernelUnloadModule\n");
		return -1;
	}

	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", main);

int startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl) {
    int var_a0;

    if (audioFlag != 1) {
        if (((dispbuf_getCapacity(pAvSync->pDisp) == 0) && (read_isFull(pRingCtrl) != 0)) || (var_a0 = -1, (checkDecodeEnd(pCtrl) == 1))) {
            goto block_5;
        }
    } else {
        if ((dispbuf_getCapacity(pAvSync->pDisp) != 0) || (soundbuf_getCapacity(pAvSync->pSound) != 0)) {
            goto block_9;
        }
        if (read_isFull(pRingCtrl) == 0) {
block_9:
            var_a0 = -1;
            if (checkDecodeEnd(pCtrl) == 1) {
                goto block_6;
            }
        } else {
block_5:
block_6:
            control_setCondition(pCtrl, 1);
            var_a0 = 0;
        }
    }
    return var_a0;
}

static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl)
{
	SceUInt32 cond;

	control_getCondition(pCtrl, &cond);
	if (cond & 8)
		return 1;
	return -1;
}

SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl)
{
	SceUInt32 pattern;

	control_getCondition(pCtrl, &pattern);

	if (pattern & 0x800) {
		return -1;
	}

	return 0;
}

static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl)
{
	control_setCondition(pCtrl, 0xFF);
	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000142DC);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000142FC);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014318);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_0001432C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014338);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014360);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014390);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000143B0);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000143DC);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014400);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014424);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014450);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014470);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014488);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_00014494);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000144AC);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000144B8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", D_000144D0);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", playMovie);

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
extern const char D_000142DC[];

static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize, ret;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto term;
	}

	iReadSize = strFileRead(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		printf("fatal error : strFileRead() 0x%x\n", iReadSize);
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		printf("fatal error : sceMpegQueryStreamOffset()\n");
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		printf("fatal error : sceMpegQueryStreamSize()\n");
		ret = -1;
		goto term;
	}

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		puts(D_000142DC); /* "fatal error : strFileLseek()", shared with an asm function */
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/main", pad_read);
