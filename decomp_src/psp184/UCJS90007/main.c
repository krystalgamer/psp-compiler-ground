#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;
typedef struct SceFont_t_fontStyleInfo SceFont_t_fontStyleInfo;
struct SceFont_t_fontStyleInfo;
typedef float SceFont_t_f32;
typedef short unsigned int SceFont_t_u16;
typedef unsigned char SceFont_t_u8;
typedef long unsigned int SceFont_t_u32;
struct SceFont_t_fontStyleInfo { /* size 0xa8 */
    SceFont_t_f32 hSize;
    SceFont_t_f32 vSize;
    SceFont_t_f32 hResolution;
    SceFont_t_f32 vResolution;
    SceFont_t_f32 weight;
    SceFont_t_u16 familyCode;
    SceFont_t_u16 style;
    SceFont_t_u16 subStyle;
    SceFont_t_u16 languageCode;
    SceFont_t_u16 regionCode;
    SceFont_t_u16 countryCode;
    SceFont_t_u8 fontName[64];
    SceFont_t_u8 fileName[64];
    SceFont_t_u32 extraAttributes;
    SceFont_t_u32 expireDate;
};
struct _anon1;
struct _anon1 { /* size 0xa */
    short unsigned int u;
    short unsigned int v;
    short int vx;
    short int vy;
    short int vz;
};
typedef struct _anon1 SceGeVertexT16V16_UV_NORMAL;
typedef void *__gnuc_va_list;
typedef __gnuc_va_list va_list;
enum connect_state {
    STATE_FIRST_INIT = 0,
    STATE_TOP = 1,
    STATE_CONFIG = 2,
    STATE_LOAD_LOGFILE = 3,
    STATE_LOAD_BOOT_BINARY = 4,
    STATE_LOADING = 5,
    STATE_NETINIT = 6,
    STATE_NETTERM = 7,
    STATE_CONNECT = 8,
    STATE_CONNECTING = 9,
    STATE_CONNECTED = 10,
    STATE_MPEG_START = 11,
    STATE_MPEG_INITIALIZING = 12,
    STATE_MPEG_PLAY_START = 13,
    STATE_MOVIE_SCENE = 14,
    STATE_STATUS_SCENE = 15,
    STATE_DISCONNECT = 16,
    STATE_DISCONNECTING = 17,
    STATE_DISPLAY_LOG_MS = 18,
    STATE_DISPLAY_LOG_NEXT = 19,
    STATE_DISPLAY_LOG_PREV = 20,
    STATE_DISPLAY_LOG = 21,
    STATE_ERROR_DIALOG_NET = 22,
    STATE_ERROR_DIALOG_FILEIO = 23,
    STATE_ERROR_DIALOG_MPEG_FILEIO = 24,
    STATE_OSK = 25,
    STATE_BINLIST = 26,
    STATE_MPEGLIST = 27,
    STATE_DISPLAY_PARAMSFO_TOP = 28,
    STATE_DISPLAY_PARAMSFO_BINLIST = 29,
    STATE_DISPLAY_PARAMSFO_CONNECTED = 30,
};
typedef int SceUID;
struct _info;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct SceNetAdhocctlParameter;
struct SceNetAdhocctlGroupName;
typedef char SceChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceChar8 data[128];
};
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlParameter { /* size 0x94 */
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetAdhocctlBSSId bssid;
};
struct _info { /* size 0x58c */
    struct SceNetEtherAddr local_addr;
    enum connect_state prev_state;
    enum connect_state state;
    int blink_counter;
    int error_code;
    int actual_err_code;
    int actual_err_code_thr;
    int v_cursor_pos;
    int binlist_v_cursor_pos;
    int binlist_top_entry;
    int binlist_entry_num;
    int mpeglist_v_cursor_pos;
    int mpeglist_top_entry;
    int mpeglist_entry_num;
    char bin_filename[256];
    char movie_filename[1][256];
    char log_filename[256];
    int thread_num;
    unsigned int paramsfo_len;
    void *paramsfo;
    unsigned int datasize;
    void *databuf;
    struct SceNetAdhocctlParameter ibss_param;
    int peer_num;
    char paramsfo_filename[256];
    char paramsfo_title[128];
    unsigned int paramsfo_title_len;
    char paramsfo_discid[16];
    unsigned int paramsfo_discid_len;
    int paramsfo_parental;
    int lang;
    int ctrl_assign;
};
struct _fade_info;
enum fade_type {
    FADE_IN = 0,
    FADE_IDLE = 1,
    FADE_OUT = 2,
};
typedef int int32;
typedef unsigned int u_int32;
typedef long long unsigned int SceUInt64;
struct _fade_info { /* size 0x18 */
    enum fade_type fade_type;
    int32 alpha;
    u_int32 color;
    SceUInt64 time_to_change;
};
struct TextureImageTable;
struct TextureImageTable { /* size 0xc */
    int width64;
    int height64;
    int *buffer;
};
typedef SceFont_t_u16 SceFont_t_charCode;
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
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
struct _mpeg_info;
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    void *sys;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef int SceInt32;
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
struct _anon2;
struct _anon2 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon2 StrFile;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
struct t_displayBuffer { /* size 0x2c */
    SceUID lockSema;
    SceUID delayFlag;
    SceInt32 statusFlag;
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
struct t_soundBuffer { /* size 0x2c */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    SceInt32 statusFlag;
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
struct _mpeg_info { /* size 0x1bc */
    SceMpeg mpeg;
    SceMpegRingbuffer ringbuf;
    SceMpegStream *pStream[2];
    SceMpegAu avcAu;
    SceMpegAu atracAu;
    SceChar8 filename[256];
    StrFile strFile;
    SceInt32 bufferSize;
    SceInt32 workSize;
    SceInt32 fileSize;
    SceInt32 audioEsSize;
    SceInt32 audioOutSize;
    SceInt32 streamOffset;
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
    SceInt32 evf_id;
};

extern struct _info _info;
extern struct _fade_info _fade_info;
extern struct TextureImageTable DialogTextureImageTable[16];
extern short unsigned int clut_dialog[16];
extern SceFont_t_charCode enString_GameSharingServerDisc[26];
extern SceFont_t_charCode jpString_DistributeTitle[8];
extern SceFont_t_charCode enString_DistributeTitle[18];
extern SceFont_t_charCode *aString[2][6];
extern int _gp[];
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern int sce_newlib_heap_kb_size;
extern char disp_list[327680];
extern ScePspFMatrix4 matrix_stack[48];
extern int disp_line_color;
extern char disp_line[80];
extern struct _mpeg_info _mpeg_info;

static void gu_init(void);
static int font_init(void);
static void fade_init(void);
static int sysparam_init(void);
static int ms_data_init(void);
static int sceMScmIsMediumInserted(void);
static void draw_headline(void);
static void draw_top(void);
static void draw_title_mini(void);
static void draw_config(void);
static void draw_bottomline(void);
static void draw_frame(void);
static void check_osk_completed(void);
static void update(void);
void disp_printf(int color, const char *fmt, ...);
void change_state(enum connect_state state, int error_code);
static void CBInit(void);
int main(int argc, char **argv);

/* SDK functions (tools/sdk_protos.h) */
int sceDisplayWaitVblankStartCB(void);
void sceKernelExitGame(void);
void *memalign(unsigned int align, unsigned int size);
void free(void *p);


void *malloc64(unsigned int size) {
    return memalign(0x40U, ((unsigned int) (size + 0x3F) >> 6) << 6);
}

void free64(void *addr) {
    free(addr);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", gu_init);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", font_init);

static void fade_init(void)
{
	_fade_info.fade_type = 0;
	_fade_info.time_to_change = 0;
	_fade_info.color = 0;
	_fade_info.alpha = 0;
}

int sceUtilityGetSystemParamInt(int id, int *value);
static int sysparam_init(void)
{
	if (sceUtilityGetSystemParamInt(8, &_info.lang) >= 0) {
		if (_info.lang >= 6)
			_info.lang = 1;
		sceUtilityGetSystemParamInt(9, &_info.ctrl_assign);
	}
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", ms_data_init);

void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
unsigned int strlen(const char *s);
int snprintf(char *buf, unsigned int size, const char *fmt, ...);
unsigned int strlen(const char *s);
static void draw_headline(void)
{
	char buf[128];

	snprintf(buf, sizeof(buf), "****** Game Sharing Server Disc ver.%d.%02d (C)2005 SCEI *****", 2, 0);
	sceGuDebugPrint((480 - strlen(buf) * 8) / 2 + 1, 11, 0xFFFFFF, buf);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", draw_top);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", draw_title_mini);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", draw_config);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", draw_bottomline);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", check_osk_completed);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", update_1080);

int vsprintf(char *buf, const char *fmt, va_list ap);
void disp_printf(int color, const char *fmt, ...)
{
	va_list ap;

	disp_line_color = color;
	__builtin_va_start(ap, fmt);
	vsprintf(disp_line, fmt, ap);
	__builtin_va_end(ap);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", change_state);

int ExitFunction(int count, int arg_impose, void *arg_self) {
    mpeg_exit_func();
    sceKernelExitGame();
    return 0;
}

int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
extern int D_0008DB8C;
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
static void CBInit(void)
{
	int cbid;

	cbid = sceKernelCreateCallback("exit", ExitFunction, &D_0008DB8C);
	sceKernelRegisterExitCallback(cbid);
}

void wait_vblank(void) {
    sceDisplayWaitVblankStartCB();
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/main", main);
