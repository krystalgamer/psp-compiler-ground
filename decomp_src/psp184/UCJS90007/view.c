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

void begin_scene(void)
{
	static const ScePspFVector3 eye = { 0.0f, 0.0f, 50.0f };
	static const ScePspFVector3 center = { 0.0f, 0.0f, 0.0f };
	static const ScePspFVector3 up = { 0.0f, 1.0f, 0.0f };

	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(0xE000, 0x1000);
	sceGuEnable(2);
	sceGuScissor(0, 0, 480, 272);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuClear(7);
	sceGumMatrixMode(1);
	sceGumLoadIdentity();
	sceGumLookAt(&eye, &center, &up);
	sceGumMatrixMode(0);
	sceGumLoadIdentity();
	sceGumPerspective(3.14f / 3.0f, 480.0f / 272.0f, 1.0f, 1000000.0f);
	sceGumMatrixMode(2);
	sceGuDisable(7);
	sceGuDisable(10);
	sceGuAmbient(0xFF404040);
	sceGuMaterial(1, 0xFFFFFFFF);
	sceGuEnable(4);
	sceGuEnable(6);
	sceGuEnable(9);
	sceGuEnable(8);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuTexFilter(7, 1);
	sceGuTexFunc(0, 1);
	sceGuTexWrap(1, 1);
}

int sceIoDevctl(const char *dev, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
SceUInt64 sceKernelGetSystemTimeWide(void);
void change_state(int state, int error_code);
int utility_msgdialog_fileio(int error_code);
static __inline__ int sceMScmIsMediumInserted(void)
{
	int status;
	int ret;

	ret = sceIoDevctl("mscmhc0:", 0x02025806, NULL, 0, &status, 4);
	if (ret < 0)
		return ret;
	return status == 1;
}

void sceGuColor(unsigned int color);
void process_fade(void)
{
	int ret;

	_fade_info.color = (_fade_info.alpha << 24) | 0xF0F0F0;
	sceGuColor(_fade_info.color);
	switch (_fade_info.fade_type) {
	case 0:
		if (_fade_info.alpha < 0xFF)
			_fade_info.alpha += 3;
		if (_fade_info.alpha >= 0x100)
			_fade_info.alpha = 0xFF;
		if (_fade_info.alpha == 0xFF)
			_fade_info.fade_type = 1;
		break;
	case 1:
		if (_info.state == 1) {
			if (_fade_info.time_to_change == 0) {
				_fade_info.time_to_change = sceKernelGetSystemTimeWide() + 8000000;
			} else if (_fade_info.time_to_change < sceKernelGetSystemTimeWide()) {
				_fade_info.fade_type = 2;
				_fade_info.time_to_change = 0;
			}
		}
		break;
	case 2:
		if (_fade_info.alpha > 0)
			_fade_info.alpha -= 4;
		if (_fade_info.alpha < 0)
			_fade_info.alpha = 0;
		if (_fade_info.alpha == 0) {
			_fade_info.fade_type = 0;
			ret = sceMScmIsMediumInserted();
			if (ret < 0)
				change_state(1, 0);
			else if (ret == 1)
				change_state(4, 0);
			else if (ret == 0) {
				ret = utility_msgdialog_fileio(0x80410C8A);
				if (ret < 0)
					change_state(1, 0);
				else
					change_state(0x17, 0);
			}
		}
		break;
	}
}

void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
int sceGimPictureAnimate(SceGimPicture *picture, float frame);
int sceGimPictureActivate(SceGimPicture *picture);
const float *sceGimPictureGetImageCrop(SceGimPicture *picture);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumScale(const ScePspFVector3 *v);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void draw_objects(int index)
{
	int i;
	ScePspFVector3 move;
	const float *crop;
	SceGimPicture *picture;
	static const float NoCrop[4] = { 0.0f, 0.0f, 1.0f, 1.0f };

	sceGumMatrixMode(2);
	sceGumLoadIdentity();
	sceGumTranslate(&g_translate[index]);
	sceGumRotateY(g_rotate[index].y);
	sceGumRotateX(g_rotate[index].x);
	sceGumRotateZ(g_rotate[index].z);
	sceGumScale(&g_scale[index]);
	for (i = 0; i < 1; i++) {
		sceGumPushMatrix();
		move.x = (float)i;
		move.y = 0.0f;
		move.z = 0.0f;
		sceGumTranslate(&move);
		picture = g_copies[i][index];
		sceGimPictureAnimate(picture, 1.0f / 60.0f);
		sceGimPictureActivate(picture);
		crop = sceGimPictureGetImageCrop(picture);
		if (crop == NULL)
			crop = NoCrop;
		sceGuTexOffset(crop[0], crop[1]);
		sceGuTexScale(crop[2], crop[3]);
		sceGumDrawArray(4, g_vformat, 4, NULL, g_vbuffer);
		sceGumPopMatrix();
	}
	sceGuTexOffset(0.0f, 0.0f);
	sceGuTexScale(1.0f, 1.0f);
}

SceGimPicture *sceGimPictureCreate(void *mem);
int sceGimPictureLoadFile(SceGimPicture *picture, void *buf, unsigned int size, int flags);
SceGimPicture *sceGimPictureDuplicate(SceGimPicture *picture, int mode);
void sceGimPictureSetCurrentSequence(SceGimPicture *picture, int seq);
void sceGimPictureSetFrameRate(SceGimPicture *picture, float rate);
SceGimImageHeader *sceGimPictureGetImage(SceGimPicture *picture);
void free(void *p);
extern float load_objects_FrameRates[1] __asm__("D_00030D54");
int load_objects(const char *filename, int index)
{
	int i;
	int *data;
	unsigned int size;
	SceGimImageHeader *image;

	if (g_picture[index] != NULL)
		return 0;
	if (!load_file(filename, &data, &size))
		return 0;
	g_picture[index] = sceGimPictureCreate(NULL);
	sceGimPictureLoadFile(g_picture[index], data, size, 0);
	for (i = 0; i < 1; i++) {
		g_copies[i][index] = sceGimPictureDuplicate(g_picture[index], 2);
		sceGimPictureSetCurrentSequence(g_copies[i][index], 0);
		sceGimPictureSetFrameRate(g_copies[i][index], load_objects_FrameRates[i]);
	}
	g_translate[index].x = 0.0f;
	g_translate[index].y = 0.0f;
	g_translate[index].z = 0.0f;
	g_rotate[index].x = 0.0f;
	g_rotate[index].y = 0.0f;
	g_rotate[index].z = 0.0f;
	g_scale[index].x = 1.0f;
	g_scale[index].y = 1.0f;
	g_scale[index].z = 1.0f;
	image = sceGimPictureGetImage(g_picture[index]);
	if (image != NULL) {
		g_scale[index].x = image->width * 0.212261036f;
		g_scale[index].y = image->height * 0.212261036f;
	}
	free(data);
	return g_picture[index] != NULL;
}

long long sceIoLseek(SceUID fd, long long offset, int whence);
void *malloc(unsigned int size);
SceBool load_file(const char *filename, int **buf, unsigned int *size)
{
	SceUID fd;

	fd = sceIoOpen(filename, 1, 0777);
	if (fd < 0)
		return 0;
	*size = sceIoLseek(fd, 0, 2);
	if (*size == 0) {
		sceIoClose(fd);
		return 0;
	}
	sceIoLseek(fd, 0, 0);
	*buf = malloc(*size);
	if (*buf == NULL) {
		sceIoClose(fd);
		return 0;
	}
	sceIoRead(fd, *buf, *size);
	sceIoClose(fd);
	return 1;
}

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

extern MODEL line_model[2] __asm__("D_00030D68");
void DrawTitleLine(void)
{
	ScePspFVector3 rect_translate = { 0.0f, 0.0f, 0.0f };
	static const ScePspFVector3 rect_scale = { 1.0f, 1.0f, 1.0f };

	line_model[0].rgba = _fade_info.color;
	line_model[1].rgba = _fade_info.color;
	sceGumMatrixMode(2);
	sceGumLoadIdentity();
	if (_info.state == 9) {
		rect_translate.x = 26.0f;
		rect_translate.y = -24.5f;
	} else {
		rect_translate.x = -30.0f;
		rect_translate.y = 28.0f;
	}
	sceGumTranslate(&rect_translate);
	sceGumScale(&rect_scale);
	sceGumDrawArray(1, 0x1FC, 2, NULL, line_model);
}
