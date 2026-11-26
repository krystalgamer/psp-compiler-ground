#include "common.h"

/* declarations recovered from DWARF */
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
typedef int SceBool;
struct _anon1;
struct _anon1 { /* size 0x30 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int format;
    short unsigned int order;
    short unsigned int width;
    short unsigned int height;
    short unsigned int bpp;
    short unsigned int pitch_align;
    short unsigned int height_align;
    short unsigned int dim_count;
    short unsigned int reserved;
    short unsigned int reserved2;
    unsigned int offsets;
    unsigned int images;
    unsigned int total;
    unsigned int plane_mask;
    short unsigned int level_type;
    short unsigned int level_count;
    short unsigned int frame_type;
    short unsigned int frame_count;
};
typedef struct _anon1 SceGimImageHeader;
typedef int SceUID;
struct _anon2;
struct _anon2 { /* size 0xa */
    short unsigned int u;
    short unsigned int v;
    short int vx;
    short int vy;
    short int vz;
};
typedef struct _anon2 SceGeVertexT16V16_UV_NORMAL;
struct _anon3;
struct _anon3 { /* size 0x1c */
    unsigned int rgba;
    ScePspFVector3 normal;
    ScePspFVector3 vertex;
};
typedef struct _anon3 MODEL;
struct _info;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
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

extern struct _info _info;
extern struct _fade_info _fade_info;
extern int g_vformat;
extern float g_vbuffer[32];
extern SceGimPicture *g_picture[2];
extern SceGimPicture *g_copies[1][2];
extern ScePspFVector3 g_translate[2];
extern ScePspFVector3 g_rotate[2];
extern ScePspFVector3 g_scale[2];
extern int __sscale_x;
extern int __sscale_y;

void set_translate(void);
void process_fade(void);
static int sceMScmIsMediumInserted(void);
void draw_objects(int index);
SceBool load_objects(const char *filename, int index);
SceBool load_file(const char *filename, int **buf, unsigned int *size);
void unload_objects(int index);
void DrawSprite(int x, int y, int w, int h, int u, int v, SceGeVertexT16V16_UV_NORMAL *model);
void DrawTitleLine(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuViewport(int cx, int cy, int width, int height);
void sceGuDepthRange(int near, int far);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClear(int flags);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuAmbient(unsigned int color);
void sceGuMaterial(int mode, unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);


void set_translate(void)
{
	g_translate[1].x = 32.0f;
	g_translate[1].y = -26.4f;
	g_translate[1].z = 0.0f;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/view", begin_scene);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF38);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF3C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF40);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF44);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF48);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF4C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF50);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF54);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF58);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF64);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF70);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/view", process_fade);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/view", draw_objects);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/view", load_objects);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/view", load_file);

void unload_objects(int index)
{
	if (g_picture[index] != NULL) {
		sceGimPictureDelete(g_copies[0][index]);
		g_copies[0][index] = NULL;
		sceGimPictureDelete(g_picture[index]);
		g_picture[index] = NULL;
	}
}

void SpriteScale(int x, int y) {
    __sscale_x = x;
    __sscale_y = y;
}

void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceKernelDcacheWritebackRange(const void *p, unsigned int size);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void DrawSprite(int x, int y, int w, int h, int u, int v, SceGeVertexT16V16_UV_NORMAL *model)
{
	sceGuEnable(9);
	model[0].u = u;
	model[0].v = v + h;
	model[0].vx = x;
	model[0].vy = y + h * __sscale_y;
	model[0].vz = 0;
	model[1].u = u;
	model[1].v = v;
	model[1].vx = x;
	model[1].vy = y;
	model[1].vz = 0;
	model[2].u = u + w;
	model[2].v = v + h;
	model[2].vx = x + w * __sscale_x;
	model[2].vy = y + h * __sscale_y;
	model[2].vz = 0;
	model[3].u = u + w;
	model[3].v = v;
	model[3].vx = x + w * __sscale_x;
	model[3].vy = y;
	model[3].vz = 0;
	sceKernelDcacheWritebackRange(model, sizeof(SceGeVertexT16V16_UV_NORMAL) * 4);
	sceGumDrawArray(4, 0x800102, 4, NULL, model);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/view", DrawTitleLine);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF88);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/view", D_0002EF98);
