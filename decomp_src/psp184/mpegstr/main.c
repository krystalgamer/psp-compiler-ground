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

const char D_00011B34[] = "ExitGame";
const char D_00011B40[] = "host0:";
const char D_00011B48[] = "disc0:/PSP_GAME/USRDIR/";
const char D_00011B60[] = "mode %s\n";
const char D_00011B6C[] = "-a";
const char D_00011B70[] = "-b";
const char D_00011B74[] = "-c";
const char D_00011B78[] = "-d";
const char D_00011B7C[] = "-e";
const char D_00011B80[] = "-f";
const char D_00011B84[] = "-g";
const char D_00011B88[] = "-h";
const char D_00011B8C[] = "-i";
const char D_00011B90[] = "-j";
const char D_00011B94[] = "-k";
const char D_00011B98[] = "-l";
const char D_00011B9C[] = "-on";
const char D_00011BA0[] = "-off";
const char D_00011BA8[] = "fatal error : strFileAssign()";
const char D_00011BC8[] = "fatal error : loadModuleVideo() 0x%x\n";
const char D_00011BF0[] = "fatal error : sceMpegInit() 0x%x\n";
const char D_00011C14[] = "fatal error : sceMpegRingbufferQueryMemSize 0x%x\n";
const char D_00011C48[] = "fatal error : sceMpegQueryMemSize 0x%x\n";
const char D_00011C70[] = "fatal error : malloc pPSPStream";
const char D_00011C90[] = "fatal error : sceMpegRingbufferConstruct() 0x%x\n";
const char D_00011CC4[] = "fatal error : sceMpegCreate() 0x%x\n";
const char D_00011CE8[] = "fatal error : strFileOpen()";
const char D_00011D04[] = "fatal error : readHeader";
const char D_00011D20[] = "fatal error : sceMpegRegistStream() AVC";
const char D_00011D48[] = "fatal error : sceMpegMallocAvcEsBuf()";
const char D_00011D70[] = "fatal error : sceMpegInitAu() AVC 0x%x\n";
const char D_00011D98[] = "fatal error : control_create() ";
const char D_00011DB8[] = "fatal error read_create()";
const char D_00011DD4[] = "fatal error avsync_create()";
const char D_00011DF0[] = "displayThread";
const char D_00011E00[] = "readThread";
const char D_00011E0C[] = "soundThread";
const char D_00011E18[] = "********** PlayMovie (%d) **********\n";
const char D_00011E40[] = "program end";

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011E4C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011E5C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011E68);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011E78);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011E8C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011E9C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011EAC);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011EC0);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011ED0);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011EE0);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011EF4);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F04);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F14);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F28);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F38);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F48);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F58);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F68);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F78);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F88);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011F98);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011FA8);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011FB8);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011FC8);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011FD8);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00011FE8);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00012010);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_0001202C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_0001204C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00012058);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00012078);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00012098);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_000120C8);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_000120EC);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_00012110);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_0001213C);

INCLUDE_RODATA("tmp/asm/psp184/mpegstr/nonmatchings/main", D_0001215C);

extern const char D_00011E4C[];
extern const char D_00011E5C[];
extern const char D_00011E68[];
extern const char D_00011E78[];
extern const char D_00011E8C[];
extern const char D_00011E9C[];
extern const char D_00011EAC[];
extern const char D_00011EC0[];
extern const char D_00011ED0[];
extern const char D_00011EE0[];
extern const char D_00011EF4[];
extern const char D_00011F04[];
extern const char D_00011F14[];
extern const char D_00011F28[];
extern const char D_00011F38[];
extern const char D_00011F48[];
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
extern const char D_00012010[];
extern const char D_0001202C[];
extern const char D_0001204C[];
extern const char D_00012058[];
extern const char D_00012078[];
extern const char D_00012098[];
extern const char D_000120C8[];
extern const char D_000120EC[];
extern const char D_00012110[];
extern const char D_0001213C[];
extern const char D_0001215C[];
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
extern int main_count __asm__("D_00013710");
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
	exit_cb = sceKernelCreateCallback(D_00011B34, exit_func, &pCtrl);
	if (exit_cb <= 0) {
		printf(D_0001215C, exit_cb);
		goto term4;
	}
	sceKernelRegisterExitCallback(exit_cb);
	saveflag = 1;
	strcpy(filename, argv[1]);
	if (strstr(filename, D_00011B40) == NULL)
		memcpy(local_host, D_00011B48, sizeof(D_00011B48));
	else
		memcpy(local_host, D_00011B40, sizeof(D_00011B40));
	printf(D_00011B60, local_host);
	puts(filename);
	if (strcmp(D_00011B6C, argv[2]) == 0)
		returnflag = 0;
	if (strcmp(D_00011B70, argv[2]) == 0)
		returnflag = 1;
	if (strcmp(D_00011B74, argv[2]) == 0)
		returnflag = 2;
	if (strcmp(D_00011B78, argv[2]) == 0)
		returnflag = 3;
	if (strcmp(D_00011B7C, argv[2]) == 0)
		returnflag = 4;
	if (strcmp(D_00011B80, argv[2]) == 0)
		returnflag = 5;
	if (strcmp(D_00011B84, argv[2]) == 0)
		returnflag = 6;
	if (strcmp(D_00011B88, argv[2]) == 0)
		returnflag = 7;
	if (strcmp(D_00011B8C, argv[2]) == 0)
		returnflag = 8;
	if (strcmp(D_00011B90, argv[2]) == 0)
		returnflag = 9;
	if (strcmp(D_00011B94, argv[2]) == 0)
		returnflag = 10;
	if (strcmp(D_00011B98, argv[2]) == 0)
		returnflag = 11;
	if (strcmp(D_00011B9C, argv[3]) == 0)
		saveflag = 1;
	saveflag = (strcmp(D_00011BA0, argv[3]) == 0) ? 0 : saveflag;
	sceKernelPowerTick(6);
	audioFlag = 1;
	if (strFileAssign(&strFile, filename) < 0) {
		puts(D_00011BA8);
		goto term4;
	}
	ret = loadModuleVideo();
	if (ret != 0) {
		printf(D_00011BC8, ret);
		goto term4;
	}
	ret = sceMpegInit();
	if (ret != 0) {
		printf(D_00011BF0, ret);
		goto term3;
	}
	bufferSize = sceMpegRingbufferQueryMemSize(960);
	if (bufferSize < 0) {
		printf(D_00011C14, bufferSize);
		goto term3;
	}
	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf(D_00011C48, workSize);
		goto term3;
	}
	pPSPStream = malloc(bufferSize);
	if (pPSPStream == NULL) {
		puts(D_00011C70);
		goto term3;
	}
	pWorkBuf = malloc(workSize);
	if (pWorkBuf == NULL) {
		printf(D_0001213C);
		goto term3;
	}
	ret = sceMpegRingbufferConstruct(&ringbuf, 960, pPSPStream, bufferSize, ringbufferCallBack, &strFile);
	if (ret != 0) {
		printf(D_00011C90, ret);
		goto term3;
	}
	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, 0);
	if (ret != 0) {
		printf(D_00011CC4, ret);
		goto term3;
	}
	if (strFileOpenCB(&strFile, filename, 1) < 0) {
		puts(D_00011CE8);
		goto term3;
	}
	if (readHeader(&mpeg, &strFile, &fileSize, &streamOffset) != 0) {
		puts(D_00011D04);
		goto term3;
	}
	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL) {
		puts(D_00011D20);
		goto term3;
	}
	if (audioFlag == 1) {
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL) {
			puts(D_00012110);
			goto term3;
		}
	}
	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		puts(D_00011D48);
		goto term3;
	}
	ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu);
	if (ret != 0) {
		printf(D_00011D70, ret);
		goto term3;
	}
	if (audioFlag == 1) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf(D_00012098, ret);
			goto term3;
		}
		pAudioBuf = memalign(64, audioEsSize);
		if (pAudioBuf == NULL) {
			puts(D_000120EC);
			goto term3;
		}
		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf(D_000120C8, ret);
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
		puts(D_00011D98);
		goto term2;
	}
	pDisp = malloc(sizeof(t_displayBuffer));
	if (pDisp == NULL)
		goto term2;
	if (dispbuf_create(pDisp, 0x88000, 4, pCtrl) < 0) {
		puts(D_00012078);
		goto term2;
	}
	if (audioFlag == 1) {
		pSound = malloc(sizeof(t_soundBuffer));
		if (pSound == NULL)
			goto term2;
		if (soundbuf_create(pSound, audioOutSize, 4, pCtrl) < 0) {
			puts(D_00012058);
			goto term2;
		}
	}
	pRing = malloc(sizeof(t_ringBuffer));
	if (pRing == NULL)
		goto term2;
	if (read_create(pRing, &ringbuf, pCtrl) < 0) {
		puts(D_00011DB8);
		goto term2;
	}
	pAvSync = malloc(sizeof(t_avSyncControl));
	if (pAvSync == NULL)
		goto term2;
	if (avsync_create(pAvSync, pDisp, pSound, 6) < 0) {
		puts(D_00011DD4);
		goto term2;
	}
	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x3F);
	dispThread = sceKernelCreateThread(D_00011DF0, dispbuf_func, 0x3E, 0x800, 0, NULL);
	readThread = sceKernelCreateThread(D_00011E00, read_func, 0x40, 0x800, 0, NULL);
	if (audioFlag == 1)
		soundThread = sceKernelCreateThread(D_00011E0C, soundbuf_func, 0x3D, 0x800, 0, NULL);
	playInfo.playMode = 0;
	for (;;) {
		if (main_count != 0) {
			puts(D_0001204C);
			goto term1;
		}
		printf(D_00011E18, main_count++);
		if (strFileLseek(&strFile, streamOffset, 0) < 0) {
			puts(D_0001202C);
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
			puts(D_00012010);
			goto term1;
		} else if (playInfo.playMode == 1) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);
			if (sceMpegFlushAllStream(&mpeg) != 0) {
				puts(D_00011FE8);
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
	puts(D_00011E40);
	{
		int i;
		const char *g_data;
		SceKernelLoadExecParam execParam;
		char retprxname[256];

		if (saveflag == 1) {
			switch (returnflag) {
			case 0: g_data = D_00011F28; break;
			case 1: g_data = D_00011F38; break;
			case 2: g_data = D_00011F48; break;
			case 3: g_data = D_00011F58; break;
			case 4: g_data = D_00011F68; break;
			case 5: g_data = D_00011F78; break;
			case 6: g_data = D_00011F88; break;
			case 7: g_data = D_00011F98; break;
			case 8: g_data = D_00011FA8; break;
			case 9: g_data = D_00011FB8; break;
			case 10: g_data = D_00011FC8; break;
			case 11: g_data = D_00011FD8; break;
			}
		} else {
			switch (returnflag) {
			case 0: g_data = D_00011E4C; break;
			case 1: g_data = D_00011E68; break;
			case 2: g_data = D_00011E78; break;
			case 3: g_data = D_00011E8C; break;
			case 4: g_data = D_00011E9C; break;
			case 5: g_data = D_00011EAC; break;
			case 6: g_data = D_00011EC0; break;
			case 7: g_data = D_00011ED0; break;
			case 8: g_data = D_00011EE0; break;
			case 9: g_data = D_00011EF4; break;
			case 10: g_data = D_00011F04; break;
			case 11: g_data = D_00011F14; break;
			}
		}
		for (i = 0; g_data[i] != '\0' || g_data[i + 1] != '\0'; i++)
			;
		execParam.size = sizeof(execParam);
		execParam.args = i + 1;
		if (saveflag == 1) {
			switch (returnflag) {
			case 0: execParam.argp = D_00011F28; break;
			case 1: execParam.argp = D_00011F38; break;
			case 2: execParam.argp = D_00011F48; break;
			case 3: execParam.argp = D_00011F58; break;
			case 4: execParam.argp = D_00011F68; break;
			case 5: execParam.argp = D_00011F78; break;
			case 6: execParam.argp = D_00011F88; break;
			case 7: execParam.argp = D_00011F98; break;
			case 8: execParam.argp = D_00011FA8; break;
			case 9: execParam.argp = D_00011FB8; break;
			case 10: execParam.argp = D_00011FC8; break;
			case 11: execParam.argp = D_00011FD8; break;
			}
		} else {
			switch (returnflag) {
			case 0: execParam.argp = D_00011E4C; break;
			case 1: execParam.argp = D_00011E68; break;
			case 2: execParam.argp = D_00011E78; break;
			case 3: execParam.argp = D_00011E8C; break;
			case 4: execParam.argp = D_00011E9C; break;
			case 5: execParam.argp = D_00011EAC; break;
			case 6: execParam.argp = D_00011EC0; break;
			case 7: execParam.argp = D_00011ED0; break;
			case 8: execParam.argp = D_00011EE0; break;
			case 9: execParam.argp = D_00011EF4; break;
			case 10: execParam.argp = D_00011F04; break;
			case 11: execParam.argp = D_00011F14; break;
			}
		}
		execParam.key = NULL;
		strcpy(retprxname, local_host);
		strcat(retprxname, D_00011E5C);
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

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/main", playMovie);

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
SceInt32 strFileReadCB(StrFile *file, void *buff, SceSize size);
extern const char D_0001202C[];

const char D_00012318[] = "fatal error : sceMpegQueryStreamOffset()";
const char D_00012344[] = "fatal error : sceMpegQueryStreamSize()";
const char D_0001236C[] = "fatal error : strFileReadRetry() 0x%x\n";

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
		printf(D_0001236C, iReadSize);
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		puts(D_00012318);
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		puts(D_00012344);
		ret = -1;
		goto term;
	}

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		puts(D_0001202C);
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

extern int D_00013714;
extern int D_00013718;

int pad_read(t_displayBuffer *pDisp) {
    SceCtrlData buf;
    int temp_v1;
    int var_a0;

    D_00013714 = D_00013718;
    sceCtrlReadBufferPositive(&buf, 1);
    var_a0 = 1;
    temp_v1 = buf.Buttons & ~D_00013714;
    D_00013718 = buf.Buttons;
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
