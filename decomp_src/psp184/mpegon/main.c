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


int printf(const char *fmt, ...);
int printf(const char *fmt, ...);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iReadSize;
	SceInt32 sectorSize = 2048;

	iReadSize = strFileRead((StrFile *)CallbackData, pBuf, iNum * sectorSize);
	if (iReadSize < 0) {
		printf("iReadSize = 0x%x\n", iReadSize);
		return iReadSize;
	}
	if (iReadSize % sectorSize != 0)
		return -1;
	return iReadSize / sectorSize;
}

void sceKernelExitGame(void);
int sceKernelWaitThreadEnd(SceUID thid, SceUInt32 *timeout);
int sceKernelPowerTick(int type);
void sceKernelExitGame(void);
static int exit_func(int count, int arg1, void *arg2)
{
	t_conditionCtrl *pCtrl = *(t_conditionCtrl **)arg2;

	if (pCtrl != NULL)
		setPlayerEndCondition(pCtrl);
	strFileUmdReadBreak();
	if (audioFlag == 1) {
		if (soundThread > 0)
			sceKernelWaitThreadEnd(soundThread, 0);
	}
	if (dispThread > 0)
		sceKernelWaitThreadEnd(dispThread, 0);
	if (readThread > 0)
		sceKernelWaitThreadEnd(readThread, 0);
	sceKernelPowerTick(0);
	sceKernelExitGame();
	return 0;
}

const char D_00011B64[] = "ExitGame";
const char D_00011B70[] = "host0:";
const char D_00011B78[] = "disc0:/PSP_GAME/USRDIR/";
const char D_00011B90[] = "mode %s\n";
const char D_00011B9C[] = "-a";
const char D_00011BA0[] = "-b";
const char D_00011BA4[] = "-c";
const char D_00011BA8[] = "-d";
const char D_00011BAC[] = "-e";
const char D_00011BB0[] = "-f";
const char D_00011BB4[] = "-g";
const char D_00011BB8[] = "-h";
const char D_00011BBC[] = "-i";
const char D_00011BC0[] = "-j";
const char D_00011BC4[] = "-k";
const char D_00011BC8[] = "-l";
const char D_00011BCC[] = "-on";
const char D_00011BD0[] = "-off";
const char D_00011BD8[] = "fatal error : strFileAssign()";
const char D_00011BF8[] = "fatal error : loadModuleVideo() 0x%x\n";
const char D_00011C20[] = "fatal error : sceMpegInit() 0x%x\n";
const char D_00011C44[] = "fatal error : sceMpegRingbufferQueryMemSize 0x%x\n";
const char D_00011C78[] = "fatal error : sceMpegQueryMemSize 0x%x\n";
const char D_00011CA0[] = "fatal error : malloc pPSPStream";
const char D_00011CC0[] = "fatal error : sceMpegRingbufferConstruct() 0x%x\n";
const char D_00011CF4[] = "fatal error : sceMpegCreate() 0x%x\n";
const char D_00011D18[] = "fatal error : strFileOpen()";
const char D_00011D34[] = "fatal error : readHeader";
const char D_00011D50[] = "fatal error : sceMpegRegistStream() AVC";
const char D_00011D78[] = "fatal error : sceMpegMallocAvcEsBuf()";
const char D_00011DA0[] = "fatal error : sceMpegInitAu() AVC 0x%x\n";
const char D_00011DC8[] = "fatal error : control_create() ";
const char D_00011DE8[] = "fatal error read_create()";
const char D_00011E04[] = "fatal error avsync_create()";
const char D_00011E20[] = "displayThread";
const char D_00011E30[] = "readThread";
const char D_00011E3C[] = "soundThread";
const char D_00011E48[] = "********** PlayMovie (%d) **********\n";
const char D_00011E70[] = "program end";

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

extern const char D_00011E7C[];
extern const char D_00011E8C[];
extern const char D_00011E98[];
extern const char D_00011EA8[];
extern const char D_00011EBC[];
extern const char D_00011ECC[];
extern const char D_00011EDC[];
extern const char D_00011EF0[];
extern const char D_00011F00[];
extern const char D_00011F10[];
extern const char D_00011F24[];
extern const char D_00011F34[];
extern const char D_00011F44[];
extern const char D_00011F58[];
extern const char D_00011F68[];
extern const char D_00011F78[];
extern const char D_00011F88[];
extern const char D_00011F98[];
extern const char D_00011FA8[];
extern const char D_00011FB8[];
extern const char D_00011FC8[];
extern const char D_00011FD8[];
extern const char D_00011FE8[];
extern const char D_00011FF8[];
extern const char D_00012008[];
extern const char D_00012018[];
extern const char D_00012040[];
extern const char D_0001205C[];
extern const char D_0001207C[];
extern const char D_00012088[];
extern const char D_000120A8[];
extern const char D_000120C8[];
extern const char D_000120F8[];
extern const char D_0001211C[];
extern const char D_00012140[];
extern const char D_0001216C[];
extern const char D_0001218C[];
void *memcpy(void *d, const void *s, unsigned int n);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
int sceKernelDeleteCallback(int cbid);
char *strcpy(char *d, const char *s);
char *strcat(char *d, const char *s);
char *strstr(const char *s1, const char *s2);
int strcmp(const char *s1, const char *s2);
int puts(const char *s);
int sceAudioRoutingSetMode(int mode);
SceInt32 strFileAssign(StrFile *file, const char *filename);
SceInt32 strFileOpenCB(StrFile *file, const char *filename, SceInt32 mode);
SceInt32 strFileClose(StrFile *file);
SceInt32 strFileUnassign(StrFile *file);
long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
SceInt32 loadModuleVideo(void);
SceInt32 unloadModuleVideo(void);
SceInt32 sceMpegInit(SceVoid);
SceInt32 sceMpegRingbufferQueryMemSize(SceInt32 iPackNum);
SceInt32 sceMpegQueryMemSize(SceInt32 iReserved);
SceInt32 sceMpegRingbufferConstruct(SceMpegRingbuffer *rb, SceInt32 iPackNum, SceVoid *pData, SceInt32 iSize, void *callback, SceVoid *cbdata);
SceInt32 sceMpegCreate(SceMpeg *mpeg, SceVoid *pData, SceInt32 iSize, SceMpegRingbuffer *rb, SceInt32 iFrameWidth, SceInt32 iReserved1, SceInt32 iReserved2);
SceMpegStream *sceMpegRegistStream(SceMpeg *mpeg, SceInt32 iStreamID, SceInt32 iStreamNum);
SceMpegHandle sceMpegMallocAvcEsBuf(SceMpeg *mpeg);
SceInt32 sceMpegInitAu(SceMpeg *mpeg, SceVoid *pEsBuffer, SceMpegAu *pAu);
SceInt32 sceMpegQueryAtracEsSize(SceMpeg *mpeg, SceInt32 *iEsSize, SceInt32 *iOutSize);
SceInt32 sceMpegFreeAvcEsBuf(SceMpeg *mpeg, SceMpegHandle buf);
SceInt32 sceMpegUnRegistStream(SceMpeg *mpeg, SceMpegStream *stream);
SceInt32 sceMpegDelete(SceMpeg *mpeg);
SceVoid sceMpegRingbufferDestruct(SceMpegRingbuffer *rb);
SceVoid sceMpegFinish(SceVoid);
SceInt32 sceMpegFlushAllStream(SceMpeg *mpeg);
int sceCtrlSetSamplingMode(int mode);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
void free(void *p);
SceInt32 decode_setStreamData(t_mpegStreamData *pStreamData, SceMpegStream *pStreamV, SceMpegAu *pAvcAu, SceMpegStream *pStreamA, SceMpegAu *pAtracAu);
SceInt32 control_create(t_conditionCtrl *pCtrl);
SceInt32 control_delete(t_conditionCtrl *pCtrl);
SceInt32 control_reset(t_conditionCtrl *pCtrl);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 dispSize, SceInt32 dispNum, t_conditionCtrl *pCtrl);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 size, SceInt32 num, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl);
SceInt32 read_delete(t_ringBuffer *pRing);
SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize);
SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
SceInt32 avsync_reset(t_avSyncControl *pAvSync);
int dispbuf_func(SceSize size, void *argp);
int read_func(SceSize size, void *argp);
int soundbuf_func(SceSize size, void *argp);
int sceKernelGetThreadId(void);
int sceKernelChangeThreadPriority(int thid, int priority);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDeleteThread(int thid);
int sceKernelLoadExec(const char *file, SceKernelLoadExecParam *param);
extern int main_count __asm__("D_00013740");
int main(int argc, const char *const *argv)
{
	SceMpeg mpeg;
	SceMpegRingbuffer ringbuf;
	SceMpegStream *pStream[2];
	SceMpegAu avcAu;
	SceMpegAu atracAu;
	char filename[256];
	StrFile strFile;
	SceInt32 bufferSize;
	SceInt32 workSize;
	SceInt32 fileSize;
	SceInt32 audioEsSize;
	SceInt32 audioOutSize;
	SceInt32 streamOffset;
	SceInt32 ret;
	t_displayBuffer *pDisp;
	t_ringBuffer *pRing;
	t_soundBuffer *pSound;
	t_avSyncControl *pAvSync;
	t_conditionCtrl *pCtrl;
	t_mpegStreamData *pStreamData;
	SceMpegHandle avcEsBuf;
	SceChar8 *pPSPStream;
	SceChar8 *pWorkBuf;
	SceChar8 *pAudioBuf;
	int exit_cb;

	pRing = NULL;
	pDisp = NULL;
	pSound = NULL;
	pAvSync = NULL;
	pPSPStream = NULL;
	avcEsBuf = NULL;
	pCtrl = NULL;
	pWorkBuf = NULL;
	pAudioBuf = NULL;
	pStream[0] = NULL;
	pStream[1] = NULL;
	exit_cb = sceKernelCreateCallback(D_00011B64, exit_func, &pCtrl);
	if (exit_cb <= 0) {
		printf(D_0001218C, exit_cb);
		goto term4;
	}
	sceKernelRegisterExitCallback(exit_cb);
	saveflag = 1;
	strcpy(filename, argv[1]);
	if (strstr(filename, D_00011B70) == NULL)
		memcpy(local_host, D_00011B78, sizeof(D_00011B78));
	else
		memcpy(local_host, D_00011B70, sizeof(D_00011B70));
	printf(D_00011B90, local_host);
	puts(filename);
	if (strcmp(D_00011B9C, argv[2]) == 0)
		returnflag = 0;
	if (strcmp(D_00011BA0, argv[2]) == 0)
		returnflag = 1;
	if (strcmp(D_00011BA4, argv[2]) == 0)
		returnflag = 2;
	if (strcmp(D_00011BA8, argv[2]) == 0)
		returnflag = 3;
	if (strcmp(D_00011BAC, argv[2]) == 0)
		returnflag = 4;
	if (strcmp(D_00011BB0, argv[2]) == 0)
		returnflag = 5;
	if (strcmp(D_00011BB4, argv[2]) == 0)
		returnflag = 6;
	if (strcmp(D_00011BB8, argv[2]) == 0)
		returnflag = 7;
	if (strcmp(D_00011BBC, argv[2]) == 0)
		returnflag = 8;
	if (strcmp(D_00011BC0, argv[2]) == 0)
		returnflag = 9;
	if (strcmp(D_00011BC4, argv[2]) == 0)
		returnflag = 10;
	if (strcmp(D_00011BC8, argv[2]) == 0)
		returnflag = 11;
	if (strcmp(D_00011BCC, argv[3]) == 0)
		saveflag = 1;
	saveflag = (strcmp(D_00011BD0, argv[3]) == 0) ? 0 : saveflag;
	sceAudioRoutingSetMode(1);
	sceKernelPowerTick(6);
	audioFlag = 1;
	if (strFileAssign(&strFile, filename) < 0) {
		puts(D_00011BD8);
		goto term4;
	}
	ret = loadModuleVideo();
	if (ret != 0) {
		printf(D_00011BF8, ret);
		goto term4;
	}
	ret = sceMpegInit();
	if (ret != 0) {
		printf(D_00011C20, ret);
		goto term3;
	}
	bufferSize = sceMpegRingbufferQueryMemSize(960);
	if (bufferSize < 0) {
		printf(D_00011C44, bufferSize);
		goto term3;
	}
	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf(D_00011C78, workSize);
		goto term3;
	}
	pPSPStream = malloc(bufferSize);
	if (pPSPStream == NULL) {
		puts(D_00011CA0);
		goto term3;
	}
	pWorkBuf = malloc(workSize);
	if (pWorkBuf == NULL) {
		printf(D_0001216C);
		goto term3;
	}
	ret = sceMpegRingbufferConstruct(&ringbuf, 960, pPSPStream, bufferSize, ringbufferCallBack, &strFile);
	if (ret != 0) {
		printf(D_00011CC0, ret);
		goto term3;
	}
	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, 0);
	if (ret != 0) {
		printf(D_00011CF4, ret);
		goto term3;
	}
	if (strFileOpenCB(&strFile, filename, 1) < 0) {
		puts(D_00011D18);
		goto term3;
	}
	if (readHeader(&mpeg, &strFile, &fileSize, &streamOffset) != 0) {
		puts(D_00011D34);
		goto term3;
	}
	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL) {
		puts(D_00011D50);
		goto term3;
	}
	if (audioFlag == 1) {
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL) {
			puts(D_00012140);
			goto term3;
		}
	}
	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		puts(D_00011D78);
		goto term3;
	}
	ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu);
	if (ret != 0) {
		printf(D_00011DA0, ret);
		goto term3;
	}
	if (audioFlag == 1) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf(D_000120C8, ret);
			goto term3;
		}
		pAudioBuf = memalign(64, audioEsSize);
		if (pAudioBuf == NULL) {
			puts(D_0001211C);
			goto term3;
		}
		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf(D_000120F8, ret);
			goto term3;
		}
	}
	sceCtrlSetSamplingMode(0);
	pStreamData = malloc(sizeof(t_mpegStreamData));
	if (pStreamData == NULL)
		goto term2;
	decode_setStreamData(pStreamData, pStream[0], &avcAu, pStream[1], &atracAu);
	pCtrl = malloc(sizeof(t_conditionCtrl));
	if (pCtrl == NULL)
		goto term2;
	if (control_create(pCtrl) < 0) {
		puts(D_00011DC8);
		goto term2;
	}
	pDisp = malloc(sizeof(t_displayBuffer));
	if (pDisp == NULL)
		goto term2;
	if (dispbuf_create(pDisp, 0x88000, 4, pCtrl) < 0) {
		puts(D_000120A8);
		goto term2;
	}
	if (audioFlag == 1) {
		pSound = malloc(sizeof(t_soundBuffer));
		if (pSound == NULL)
			goto term2;
		if (soundbuf_create(pSound, audioOutSize, 4, pCtrl) < 0) {
			puts(D_00012088);
			goto term2;
		}
	}
	pRing = malloc(sizeof(t_ringBuffer));
	if (pRing == NULL)
		goto term2;
	if (read_create(pRing, &ringbuf, pCtrl) < 0) {
		puts(D_00011DE8);
		goto term2;
	}
	pAvSync = malloc(sizeof(t_avSyncControl));
	if (pAvSync == NULL)
		goto term2;
	if (avsync_create(pAvSync, pDisp, pSound, 6) < 0) {
		puts(D_00011E04);
		goto term2;
	}
	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x3F);
	dispThread = sceKernelCreateThread(D_00011E20, dispbuf_func, 0x3E, 0x800, 0, NULL);
	readThread = sceKernelCreateThread(D_00011E30, read_func, 0x40, 0x800, 0, NULL);
	if (audioFlag == 1)
		soundThread = sceKernelCreateThread(D_00011E3C, soundbuf_func, 0x3D, 0x800, 0, NULL);
	playInfo.playMode = 0;
	for (;;) {
		if (main_count != 0) {
			puts(D_0001207C);
			goto term1;
		}
		printf(D_00011E48, main_count++);
		if (strFileLseek(&strFile, streamOffset, 0) < 0) {
			puts(D_0001205C);
			goto term1;
		}
		if (audioFlag == 1)
			soundbuf_reset(pSound);
		dispbuf_reset(pDisp);
		read_reset(pRing, fileSize);
		avsync_reset(pAvSync);
		control_reset(pCtrl);
		if (audioFlag == 1)
			sceKernelStartThread(soundThread, 4, &pAvSync);
		sceKernelStartThread(dispThread, 4, &pAvSync);
		sceKernelStartThread(readThread, 4, &pRing);
		ret = playMovie(&mpeg, &ringbuf, pStreamData, pRing, pAvSync, pCtrl);
		if (ret == 0) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);
		} else if (ret < 0) {
			puts(D_00012040);
			goto term1;
		} else if (playInfo.playMode == 1) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);
			if (sceMpegFlushAllStream(&mpeg) != 0) {
				puts(D_00012018);
				goto term1;
			}
			playInfo.playMode = 0;
		} else if (playInfo.playMode == 10) {
			goto term1;
		}
	}
term1:
	sceKernelPowerTick(0);
	if (audioFlag == 1)
		sceKernelWaitThreadEnd(soundThread, NULL);
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);
	if (audioFlag == 1)
		sceKernelDeleteThread(soundThread);
	sceKernelDeleteThread(dispThread);
	sceKernelDeleteThread(readThread);
term2:
	if (pRing != NULL) {
		read_delete(pRing);
		free(pRing);
		pRing = NULL;
	}
	if (pAvSync != NULL) {
		avsync_delete(pAvSync);
		free(pAvSync);
		pAvSync = NULL;
	}
	if (pSound != NULL) {
		soundbuf_delete(pSound);
		free(pSound);
	}
	if (pDisp != NULL) {
		dispbuf_delete(pDisp);
		free(pDisp);
	}
	if (pCtrl != NULL) {
		control_delete(pCtrl);
		free(pCtrl);
		pCtrl = NULL;
	}
	if (pStreamData != NULL)
		free(pStreamData);
term3:
	if (audioFlag == 1) {
		if (pAudioBuf != NULL)
			free(pAudioBuf);
	}
	if (avcEsBuf != NULL)
		sceMpegFreeAvcEsBuf(&mpeg, avcEsBuf);
	if (pStream[0] != NULL) {
		sceMpegUnRegistStream(&mpeg, pStream[0]);
		pStream[0] = NULL;
	}
	if (audioFlag == 1) {
		if (pStream[1] != NULL) {
			sceMpegUnRegistStream(&mpeg, pStream[1]);
			pStream[1] = NULL;
		}
	}
	strFileClose(&strFile);
	sceMpegDelete(&mpeg);
	sceMpegRingbufferDestruct(&ringbuf);
	sceMpegFinish();
	if (pWorkBuf != NULL)
		free(pWorkBuf);
	if (pPSPStream != NULL)
		free(pPSPStream);
	unloadModuleVideo();
term4:
	strFileUnassign(&strFile);
	if (exit_cb > 0)
		sceKernelDeleteCallback(exit_cb);
	puts(D_00011E70);
	{
		int i;
		const char *g_data;
		SceKernelLoadExecParam execParam;
		char retprxname[256];

		if (saveflag == 1) {
			switch (returnflag) {
			case 0: g_data = D_00011F58; break;
			case 1: g_data = D_00011F68; break;
			case 2: g_data = D_00011F78; break;
			case 3: g_data = D_00011F88; break;
			case 4: g_data = D_00011F98; break;
			case 5: g_data = D_00011FA8; break;
			case 6: g_data = D_00011FB8; break;
			case 7: g_data = D_00011FC8; break;
			case 8: g_data = D_00011FD8; break;
			case 9: g_data = D_00011FE8; break;
			case 10: g_data = D_00011FF8; break;
			case 11: g_data = D_00012008; break;
			}
		} else {
			switch (returnflag) {
			case 0: g_data = D_00011E7C; break;
			case 1: g_data = D_00011E98; break;
			case 2: g_data = D_00011EA8; break;
			case 3: g_data = D_00011EBC; break;
			case 4: g_data = D_00011ECC; break;
			case 5: g_data = D_00011EDC; break;
			case 6: g_data = D_00011EF0; break;
			case 7: g_data = D_00011F00; break;
			case 8: g_data = D_00011F10; break;
			case 9: g_data = D_00011F24; break;
			case 10: g_data = D_00011F34; break;
			case 11: g_data = D_00011F44; break;
			}
		}
		for (i = 0; g_data[i] != '\0' || g_data[i + 1] != '\0'; i++)
			;
		execParam.size = sizeof(execParam);
		execParam.args = i + 1;
		if (saveflag == 1) {
			switch (returnflag) {
			case 0: execParam.argp = D_00011F58; break;
			case 1: execParam.argp = D_00011F68; break;
			case 2: execParam.argp = D_00011F78; break;
			case 3: execParam.argp = D_00011F88; break;
			case 4: execParam.argp = D_00011F98; break;
			case 5: execParam.argp = D_00011FA8; break;
			case 6: execParam.argp = D_00011FB8; break;
			case 7: execParam.argp = D_00011FC8; break;
			case 8: execParam.argp = D_00011FD8; break;
			case 9: execParam.argp = D_00011FE8; break;
			case 10: execParam.argp = D_00011FF8; break;
			case 11: execParam.argp = D_00012008; break;
			}
		} else {
			switch (returnflag) {
			case 0: execParam.argp = D_00011E7C; break;
			case 1: execParam.argp = D_00011E98; break;
			case 2: execParam.argp = D_00011EA8; break;
			case 3: execParam.argp = D_00011EBC; break;
			case 4: execParam.argp = D_00011ECC; break;
			case 5: execParam.argp = D_00011EDC; break;
			case 6: execParam.argp = D_00011EF0; break;
			case 7: execParam.argp = D_00011F00; break;
			case 8: execParam.argp = D_00011F10; break;
			case 9: execParam.argp = D_00011F24; break;
			case 10: execParam.argp = D_00011F34; break;
			case 11: execParam.argp = D_00011F44; break;
			}
		}
		execParam.key = NULL;
		strcpy(retprxname, local_host);
		strcat(retprxname, D_00011E8C);
		sceKernelLoadExec(retprxname, &execParam);
	}
	return 0;
}

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

int puts(const char *s);
int puts(const char *s);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl)
{
	SceUInt32 cond;

	control_getCondition(pCtrl, &cond);
	if (cond & 0x800) {
		puts("fatal error : player error occured");
		return -1;
	}
	return 0;
}

static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl)
{
	control_setCondition(pCtrl, 0xFF);
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/main", playMovie);

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
SceInt32 strFileReadCB(StrFile *file, void *buff, SceSize size);
extern const char D_0001205C[];

const char D_00012348[] = "fatal error : sceMpegQueryStreamOffset()";
const char D_00012374[] = "fatal error : sceMpegQueryStreamSize()";
const char D_0001239C[] = "fatal error : strFileReadRetry() 0x%x\n";

static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize, ret;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto term;
	}

	iReadSize = strFileReadCB(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		printf(D_0001239C, iReadSize);
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		puts(D_00012348);
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		puts(D_00012374);
		ret = -1;
		goto term;
	}

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		puts(D_0001205C);
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

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
