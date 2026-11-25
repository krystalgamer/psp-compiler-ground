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
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    void *sys;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef SceInt32 (*SceMpegRBCallback)(void *, SceInt32, void *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    void *m_pBuf;
    SceMpegRBCallback callback;
    void *m_CallbackData;
    void *pPack;
    SceInt32 iSemaRB;
    void *mp;
};
typedef struct SceMpegStream SceMpegStream;
struct SceMpegStream;
typedef unsigned int SceUInt32;
typedef SceUInt32 SceMpegStreamId;
typedef unsigned char SceUChar8;
typedef short int SceShort16;
struct SceMpegStream { /* size 0x40 */
    SceMpegStreamId qStreamId;
    SceMpegStreamId qStreamIdMask;
    void *m_pRAPICtrlStream;
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
typedef struct SceMpegAu SceMpegAu;
struct SceMpegAu;
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x28 */
    SceUID lockSema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
struct t_ringBuffer { /* size 0x10 */
    SceInt32 dataLen;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct t_soundBuffer t_soundBuffer;
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
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_mpegStreamData t_mpegStreamData;
struct t_mpegStreamData;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef SceUChar8 *SceMpegHandle;
typedef struct SceKernelLoadExecParam SceKernelLoadExecParam;
struct SceKernelLoadExecParam;
typedef unsigned int SceSize;
struct SceKernelLoadExecParam { /* size 0x10 */
    SceSize size;
    SceSize args;
    const void *argp;
    const char *key;
};
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
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
typedef struct t_playInfo t_playInfo;
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};

extern int returnflag;
extern int saveflag;
extern char local_host[128];
extern int _gp[];
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

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
static int exit_func(int count, int arg1, void *arg2);
int main(int argc, const char *const *argv);
static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl);
static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);


INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", ringbufferCallBack);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", exit_func);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", main);

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

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", checkDecodeEnd);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011E7C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011E8C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011E98);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011EA8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011EBC);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011ECC);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011EDC);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011EF0);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F00);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F10);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F24);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F34);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F44);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F58);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F68);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F78);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F88);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011F98);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011FA8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011FB8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011FC8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011FD8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011FE8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00011FF8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00012008);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00012018);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00012040);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001205C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001207C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00012088);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_000120A8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_000120C8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_000120F8);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001211C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_00012140);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001216C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001218C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_000121BC);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_000121EC);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001221C);

INCLUDE_RODATA("tmp/asm/psp184/mpegon/nonmatchings/main", D_0001224C);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", checkPlayerErrCondition);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", setPlayerEndCondition);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", playMovie);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", readHeader);

extern int D_00013744;
extern int D_00013748;

int pad_read(t_displayBuffer *pDisp) {
    SceCtrlData buf;
    int temp_v1;
    int var_a0;

    D_00013744 = D_00013748;
    sceCtrlReadBufferPositive(&buf, 1);
    var_a0 = 1;
    temp_v1 = buf.Buttons & ~D_00013744;
    D_00013748 = buf.Buttons;
    if (temp_v1 & 0x4000) {
        playInfo.playMode = 0xA;
    } else {
        var_a0 = 0;
        if (temp_v1 & 8) {
            playInfo.playMode = 0xA;
            var_a0 = 1;
        }
    }
    return var_a0;
}
