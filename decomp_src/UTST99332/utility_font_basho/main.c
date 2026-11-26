/* cflags: -O0 */
#include "common.h"

/* declarations recovered from DWARF */
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelLMOption;
typedef unsigned int SceSize;
typedef int SceUID;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
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
typedef unsigned int u_int32;
struct _reent;
typedef struct __sFILE __FILE;
struct __sFILE;
struct __sbuf;
struct __sbuf { /* size 0x8 */
    unsigned char *_base;
    int _size;
};
typedef long int _fpos_t;
typedef int _flock_t;
struct __sFILE { /* size 0x5c */
    unsigned char *_p;
    int _r;
    int _w;
    short int _flags;
    short int _file;
    struct __sbuf _bf;
    int _lbfsize;
    void *_cookie;
    int (*_read)(void *, char *, int);
    int (*_write)(void *, const char *, int);
    _fpos_t (*_seek)(void *, _fpos_t, int);
    int (*_close)(void *);
    struct __sbuf _ub;
    unsigned char *_up;
    int _ur;
    unsigned char _ubuf[3];
    unsigned char _nbuf[1];
    struct __sbuf _lb;
    int _blksize;
    int _offset;
    struct _reent *_data;
    _flock_t _lock;
};
struct _Bigint;
typedef long unsigned int __ULong;
struct _Bigint { /* size 0x18 */
    struct _Bigint *_next;
    int _k;
    int _maxwds;
    int _sign;
    int _wds;
    __ULong _x[1];
};
union _anon1;
struct _anon2;
struct __tm;
struct __tm { /* size 0x24 */
    int __tm_sec;
    int __tm_min;
    int __tm_hour;
    int __tm_mday;
    int __tm_mon;
    int __tm_year;
    int __tm_wday;
    int __tm_yday;
    int __tm_isdst;
};
struct _rand48;
struct _rand48 { /* size 0xe */
    short unsigned int _seed[3];
    short unsigned int _mult[3];
    short unsigned int _add;
};
struct _anon3;
union _anon4;
typedef unsigned int wint_t;
union _anon4 { /* size 0x4 */
    wint_t __wch;
    unsigned char __wchb[4];
};
struct _anon3 { /* size 0x8 */
    int __count;
    union _anon4 __value;
};
typedef struct _anon3 _mbstate_t;
struct _anon2 { /* size 0xd0 */
    unsigned int _unused_rand;
    char *_strtok_last;
    char _asctime_buf[26];
    struct __tm _localtime_buf;
    int _gamma_signgam;
    long long unsigned int _rand_next;
    struct _rand48 _r48;
    _mbstate_t _mblen_state;
    _mbstate_t _mbtowc_state;
    _mbstate_t _wctomb_state;
    char _l64a_buf[8];
    char _signal_buf[24];
    int _getdate_err;
    _mbstate_t _mbrlen_state;
    _mbstate_t _mbrtowc_state;
    _mbstate_t _mbsrtowcs_state;
    _mbstate_t _wcrtomb_state;
    _mbstate_t _wcsrtombs_state;
};
struct _anon5;
struct _anon5 { /* size 0xf0 */
    unsigned char *_nextf[30];
    unsigned int _nmalloc[30];
};
union _anon1 { /* size 0xf0 */
    struct _anon2 _reent;
    struct _anon5 _unused;
};
struct _atexit;
struct _on_exit_args;
struct _on_exit_args { /* size 0x84 */
    void *_fnargs[32];
    __ULong _fntypes;
};
struct _atexit { /* size 0x10c */
    struct _atexit *_next;
    int _ind;
    void (*_fns[32])(void);
    struct _on_exit_args _on_exit_args;
};
struct _glue;
struct _glue { /* size 0xc */
    struct _glue *_next;
    int _niobs;
    __FILE *_iobs;
};
struct _reent { /* size 0x380 */
    int _errno;
    __FILE *_stdin;
    __FILE *_stdout;
    __FILE *_stderr;
    int _inc;
    char _emergency[25];
    int _current_category;
    const char *_current_locale;
    int __sdidinit;
    void (*__cleanup)(struct _reent *);
    struct _Bigint *_result;
    int _result_k;
    struct _Bigint *_p5s;
    struct _Bigint **_freelist;
    int _cvtlen;
    char *_cvtbuf;
    union _anon1 _new;
    struct _atexit *_atexit;
    struct _atexit _atexit0;
    void (**_sig_func)(int);
    struct _glue __sglue;
    __FILE __sf[3];
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

extern struct _reent *_impure_ptr;
extern SceUID fontModukeID;
extern int sce_newlib_heap_kb_size;
extern int _gp[];
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;

int main(void);
static void draw_frame(void);
static int myLoadModule(void);
static int myUnloadModule(void);
static void init_all(void);
static int pad_read(void);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceDisplayWaitVblankStart(void);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void sceGuStart(int type, void *list, int size);
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/main", main);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/main", draw_frame);

typedef int SceInt32;
typedef char SceChar8;
SceUID sceKernelLoadModule(const char *path, int flags, SceKernelLMOption *option);
int sceKernelStartModule(SceUID modid, SceSize args, void *argp, int *status, void *option);
int sceKernelStopModule(SceUID modid, SceSize args, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);
int fprintf(__FILE *fp, const char *fmt, ...);

static int myLoadModule(void)
{
	SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option)
	{
		SceInt32 res;
		SceInt32 mresult;

		do {
			*mid = sceKernelLoadModule((const char *)filename, 0, option);
		} while (*mid < 0);
		do {
			res = sceKernelStartModule(*mid, 0, NULL, &mresult, NULL);
		} while (res < 0);
		return 0;
	}

	SceKernelLMOption uMode;

	uMode.size = sizeof(SceKernelLMOption);
	uMode.mpidtext = 2;
	uMode.mpiddata = 2;
	uMode.position = 0;
	uMode.access = 1;

	if (loadModule(&fontModukeID, (SceChar8 *)"disc0:/PSP_GAME/USRDIR/MODULE/libfont.prx", &uMode) != 0) {
		fprintf(_impure_ptr->_stderr, "fatal error : can not load Module (libfont.prx)\n");
		return -1;
	}

	return 0;
}

static int myUnloadModule(void)
{
	SceInt32 unloadModule(SceUID *mid)
	{
		SceInt32 mresult;

		if (sceKernelStopModule(*mid, 0, NULL, &mresult, NULL) < 0) {
			fprintf(_impure_ptr->_stderr, "fatal error : sceKernelStopModule\n");
			return -1;
		}
		if (sceKernelUnloadModule(*mid) < 0) {
			fprintf(_impure_ptr->_stderr, "fatal error : sceKernelUnloadModule\n");
			return -1;
		}
		return 0;
	}

	return unloadModule(&fontModukeID);
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/utility_font_basho/nonmatchings/main", pad_read);
