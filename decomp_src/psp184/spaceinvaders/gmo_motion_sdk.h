typedef unsigned int size_t;
typedef int ptrdiff_t;
typedef struct __sFILE FILE;
struct _reent;
struct __sbuf {
 unsigned char *_base;
 int _size;
};
typedef long int _fpos_t;
typedef int _flock_t;
struct __sFILE {
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
typedef struct __sFILE __FILE;
struct _Bigint;
typedef long unsigned int __ULong;
struct _Bigint {
 struct _Bigint *_next;
 int _k;
 int _maxwds;
 int _sign;
 int _wds;
 __ULong _x[1];
};
union __reent_u;
struct __reent_s;
struct __tm;
struct __tm {
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
struct _rand48 {
 short unsigned int _seed[3];
 short unsigned int _mult[3];
 short unsigned int _add;
};
struct __mbstate_s;
union __wch_u;
typedef unsigned int wint_t;
union __wch_u {
 wint_t __wch;
 unsigned char __wchb[4];
};
struct __mbstate_s {
 int __count;
 union __wch_u __value;
};
typedef struct __mbstate_s _mbstate_t;
struct __reent_s {
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
struct __unused_s;
struct __unused_s {
 unsigned char *_nextf[30];
 unsigned int _nmalloc[30];
};
union __reent_u {
 struct __reent_s _reent;
 struct __unused_s _unused;
};
struct _atexit;
struct _on_exit_args;
struct _on_exit_args {
 void *_fnargs[32];
 __ULong _fntypes;
};
struct _atexit {
 struct _atexit *_next;
 int _ind;
 void (*_fns[32])(void);
 struct _on_exit_args _on_exit_args;
};
struct _glue;
struct _glue {
 struct _glue *_next;
 int _niobs;
 __FILE *_iobs;
};
struct _reent {
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
 union __reent_u _new;
 struct _atexit *_atexit;
 struct _atexit _atexit0;
 void (**_sig_func)(int);
 struct _glue __sglue;
 __FILE __sf[3];
};
extern struct _reent *_impure_ptr;
int fprintf(FILE *, const char *, ...);
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
int puts(const char *);
int putchar(int);
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
int vsprintf(char *, const char *, __gnuc_va_list);
void *malloc(size_t);
void free(void *);
void *memalign(size_t, size_t);
int atoi(const char *);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);
int memcmp(const void *, const void *, size_t);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
size_t strlen(const char *);
char *strdup(const char *);
double sin(double);
double cos(double);
double sqrt(double);
double atan(double);
double atan2(double, double);
float sinf(float);
float cosf(float);
float sqrtf(float);
double pow(double, double);
double fabs(double);
typedef unsigned char u_char8;
typedef unsigned short u_short16;
typedef unsigned short u_int16;
typedef unsigned int u_int32;
typedef unsigned int u_int64 __attribute__((mode(DI)));
typedef unsigned int u_long64 __attribute__((mode(DI)));
typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef char char8;
typedef short short16;
typedef short int16;
typedef int int32;
typedef int int64 __attribute__((mode(DI)));
typedef int long64 __attribute__((mode(DI)));
typedef int long128 __attribute__((mode(TI)));
typedef unsigned char SceUChar8;
typedef unsigned short SceUShort16;
typedef unsigned int SceUInt32;
typedef unsigned int SceUInt64 __attribute__((mode(DI)));
typedef unsigned int SceULong64 __attribute__((mode(DI)));
typedef unsigned int SceULong128 __attribute__((mode(TI)));
typedef char SceChar8;
typedef short SceShort16;
typedef int SceInt32;
typedef int SceInt64 __attribute__((mode(DI)));
typedef int SceLong64 __attribute__((mode(DI)));
typedef int SceLong128 __attribute__((mode(TI)));
typedef float SceFloat;
typedef float SceFloat32;
typedef unsigned short SceWChar16;
typedef unsigned int SceWChar32;
typedef int SceBool;
typedef void SceVoid;
typedef void * ScePVoid;
typedef struct ScePspSRect {
 short x, y, w, h;
} ScePspSRect;
typedef struct ScePspIRect {
 int x, y, w, h;
} ScePspIRect;
typedef struct ScePspL64Rect {
 SceLong64 x, y, w, h;
} ScePspL64Rect;
typedef struct ScePspFRect {
 float x, y, w, h;
} ScePspFRect;
typedef struct ScePspSVector2 {
 short x, y;
} ScePspSVector2;
typedef struct ScePspIVector2 {
 int x, y;
} ScePspIVector2;
typedef struct ScePspL64Vector2 {
 SceLong64 x, y;
} ScePspL64Vector2;
typedef struct ScePspFVector2 {
 float x, y;
} ScePspFVector2;
typedef union ScePspVector2 {
 ScePspFVector2 fv;
 ScePspIVector2 iv;
 float f[2];
 int i[2];
} ScePspVector2;
typedef struct ScePspSVector3 {
 short x, y, z;
} ScePspSVector3;
typedef struct ScePspIVector3 {
 int x, y, z;
} ScePspIVector3;
typedef struct ScePspL64Vector3 {
 SceLong64 x, y, z;
} ScePspL64Vector3;
typedef struct ScePspFVector3 {
 float x, y, z;
} ScePspFVector3;
typedef union ScePspVector3 {
 ScePspFVector3 fv;
 ScePspIVector3 iv;
 float f[3];
 int i[3];
} ScePspVector3;
typedef struct ScePspSVector4 {
 short x, y, z, w;
} ScePspSVector4;
typedef struct ScePspIVector4 {
 int x, y, z, w;
} ScePspIVector4;
typedef struct ScePspL64Vector4 {
 SceLong64 x, y, z, w;
} ScePspL64Vector4;
typedef struct ScePspFVector4 {
 float x, y, z, w;
} ScePspFVector4 __attribute__((aligned(16)));
typedef struct ScePspFVector4Unaligned {
 float x, y, z, w;
} ScePspFVector4Unaligned;
typedef union ScePspVector4 {
 ScePspFVector4 fv;
 ScePspIVector4 iv;
 SceULong128 qw;
 float f[4];
 int i[4];
} ScePspVector4 __attribute__((aligned(16)));
typedef struct ScePspIMatrix2 {
 ScePspIVector2 x, y;
} ScePspIMatrix2;
typedef struct ScePspFMatrix2 {
 ScePspFVector2 x, y;
} ScePspFMatrix2;
typedef union ScePspMatrix2 {
 ScePspFMatrix2 fm;
 ScePspIMatrix2 im;
 ScePspFVector2 fv[2];
 ScePspIVector2 iv[2];
 ScePspVector2 v[2];
 SceULong128 qw[2];
 float f[2][2];
 int i[2][2];
} ScePspMatrix2;
typedef struct ScePspIMatrix3 {
 ScePspIVector3 x, y, z;
} ScePspIMatrix3;
typedef struct ScePspFMatrix3 {
 ScePspFVector3 x, y, z;
} ScePspFMatrix3;
typedef union ScePspMatrix3 {
 ScePspFMatrix3 fm;
 ScePspIMatrix3 im;
 ScePspFVector3 fv[3];
 ScePspIVector3 iv[3];
 ScePspVector3 v[3];
 SceULong128 qw[3];
 float f[3][3];
 int i[3][3];
} ScePspMatrix3;
typedef struct ScePspIMatrix4 {
 ScePspIVector4 x, y, z, w;
} ScePspIMatrix4 __attribute__((aligned(16)));
typedef struct ScePspIMatrix4Unaligned {
 ScePspIVector4 x, y, z, w;
} ScePspIMatrix4Unaligned;
typedef struct ScePspFMatrix4 {
 ScePspFVector4 x, y, z, w;
} ScePspFMatrix4 __attribute__((aligned(16)));
typedef struct ScePspFMatrix4Unaligned {
 ScePspFVector4 x, y, z, w;
} ScePspFMatrix4Unaligned;
typedef union ScePspMatrix4 {
 ScePspFMatrix4 fm;
 ScePspIMatrix4 im;
 ScePspFVector4 fv[4];
 ScePspIVector4 iv[4];
 ScePspVector4 v[4];
 SceULong128 qw[4];
 float f[4][4];
 int i[4][4];
} ScePspMatrix4 __attribute__((aligned(16)));
typedef struct ScePspFQuaternion {
 float x, y, z, w;
} ScePspFQuaternion __attribute__((aligned(16)));
typedef struct ScePspFQuaternionUnaligned {
 float x, y, z, w;
} ScePspFQuaternionUnaligned;
typedef struct ScePspFColor {
 float r, g, b, a;
} ScePspFColor __attribute__((aligned(16)));
typedef struct ScePspFColorUnaligned {
 float r, g, b, a;
} ScePspFColorUnaligned;
typedef unsigned int ScePspRGBA8888;
typedef unsigned short ScePspRGBA4444;
typedef unsigned short ScePspRGBA5551;
typedef unsigned short ScePspRGB565;
typedef union ScePspUnion32 {
 unsigned int ui;
 int i;
 unsigned short us[2];
 short s[2];
 unsigned char uc[4];
 char c[4];
 float f;
 ScePspRGBA8888 rgba8888;
 ScePspRGBA4444 rgba4444[2];
 ScePspRGBA5551 rgba5551[2];
 ScePspRGB565 rgb565[2];
} ScePspUnion32;
typedef union ScePspUnion64 {
 SceULong64 ul;
 SceLong64 l;
 unsigned int ui[2];
 int i[2];
 unsigned short us[4];
 short s[4];
 unsigned char uc[8];
 char c[8];
 float f[2];
 ScePspSRect sr;
 ScePspSVector4 sv;
 ScePspRGBA8888 rgba8888[2];
 ScePspRGBA4444 rgba4444[4];
 ScePspRGBA5551 rgba5551[4];
 ScePspRGB565 rgb565[4];
} ScePspUnion64;
typedef union ScePspUnion128 {
 SceULong128 qw;
 SceULong128 uq;
 SceLong128 q;
 SceULong64 ul[2];
 SceLong64 l[2];
 unsigned int ui[4];
 int i[4];
 unsigned short us[8];
 short s[8];
 unsigned char uc[16];
 char c[16];
 float f[4];
 ScePspFRect fr;
 ScePspIRect ir;
 ScePspFVector4 fv;
 ScePspIVector4 iv;
 ScePspFQuaternion fq;
 ScePspFColor fc;
 ScePspRGBA8888 rgba8888[4];
 ScePspRGBA4444 rgba4444[8];
 ScePspRGBA5551 rgba5551[8];
 ScePspRGB565 rgb565[8];
} ScePspUnion128 __attribute__((aligned(16)));
typedef struct ScePspDateTime {
 unsigned short year;
 unsigned short month;
 unsigned short day;
 unsigned short hour;
 unsigned short minute;
 unsigned short second;
 unsigned int microsecond;
} ScePspDateTime;
void sceGuInit( void );
void sceGuTerm( void );
void sceGuStart( int mode, void *p, int size );
void sceGuFinish( void );
void sceGuFinishId( unsigned short id );
void sceGuSignal( int mode, unsigned short id );
void sceGuBreak( void );
void sceGuCallList( const void *p );
int sceGuCheckList( void );
int sceGuSync( int mode, int block );
void sceGuSignalSync( unsigned short id );
void *sceGuGetMemory( int size );
int sceGuDisplay( int sw );
void *sceGuSetCallback( int id, void (*cb)(int) );
void sceGuSetDither( const ScePspIMatrix4 *d );
void sceGuEnable( int cap );
void sceGuDisable( int cap );
int sceGuGetStatus( int cap );
void sceGuSetStatus( int cap, int flag );
unsigned int sceGuGetAllStatus( void );
void sceGuSetAllStatus( unsigned int status );
void sceGuBeginObject( int type, int count, const void *idx, const void *p );
void sceGuEndObject( void );
void sceGuDrawArray( int prim, int type, int count, const void *idx,
      const void *p );
void sceGuDrawArrayN( int prim, int type, int n_verts, int n_prims,
      const void *idx, const void *p );
void sceGuDrawBezier( int type, int ucount, int vcount, const void *idx,
      const void *p );
void sceGuDrawSpline( int type, int ucount, int vcount, int uflag, int vflag,
      const void *idx, const void *p );
void sceGuDrawSprite( int x, int y, int z, int u, int v, int flip, int rotate );
void sceGuPatchDivide( int udiv, int vdiv );
void sceGuPatchPrim( int prim );
void sceGuSpriteMode( int sw, int sh, int dw, int dh );
void sceGuClearColor( unsigned int col );
void sceGuClearStencil( int stencil );
void sceGuClearDepth( int depth );
void sceGuClear( int mask );
void sceGuCopyImage( int mode, int sx, int sy, int width, int height,
     int sbw, void *sbp, int dx, int dy, int dbw, void *dbp );
void sceGuViewport( int x, int y, int width, int height );
void sceGuDrawBuffer( int fpf, void *fbp, int fbw );
void sceGuDrawBufferList( int fpf, void *fbp, int fbw );
void sceGuDispBuffer( int width, int height, void *dbp, int dbw );
void sceGuDepthBuffer( void *zbp, int zbw );
void *sceGuSwapBuffers( void );
void sceGuDepthRange( int r_near, int r_far );
void sceGuDepthOffset( int offset );
void sceGuOffset( int x, int y );
void sceGuAmbient( unsigned int col );
void sceGuColor( unsigned int col );
void sceGuColorMaterial( int type );
void sceGuMaterial( int type, unsigned int col );
void sceGuAmbientColor( unsigned int ac );
void sceGuModelColor( unsigned int mec, unsigned int mac, unsigned int mdc,
      unsigned int msc );
void sceGuSpecular( float power );
void sceGuFrontFace( int mode );
void sceGuShadeModel( int model );
void sceGuLight( int n, int type, int comp, const ScePspFVector3 *vec );
void sceGuLightMode( int ssc );
void sceGuLightAtt( int n, float a, float b, float c );
void sceGuLightSpot( int n, float s, float c, const ScePspFVector3 *vec );
void sceGuLightColor( int n, int type, unsigned int col );
void sceGuTexMode( int tpf, int maxlod, int mc, int hsm );
void sceGuTexFilter( int min, int mag );
void sceGuTexFunc( int func, int component );
void sceGuTexEnvColor( unsigned int col );
void sceGuTexWrap( int uwrap, int vwrap );
void sceGuTexLevelMode( int calc, float offset );
void sceGuTexMapMode( int map, int lu, int lv );
void sceGuTexSync( void );
void sceGuTexFlush( void );
void sceGuTexImage( int level, int width, int height, int w, const void *tbp );
void sceGuTexScale( float su, float sv );
void sceGuTexOffset( float tu, float tv );
void sceGuTexProjMapMode( int mode );
void sceGuTexSlope( float tslope );
void sceGuClutMode( int cpf, int shift, int mask, int csa );
void sceGuClutLoad( int np, const void *cbp );
void sceGuFog( float zs, float ze, unsigned int col );
void sceGuColorFunc( int func, unsigned int cref, unsigned int cmsk );
void sceGuAlphaFunc( int func, int aref, int amsk );
void sceGuDepthFunc( int func );
void sceGuDepthMask( int flag );
void sceGuScissor( int x, int y, int width, int height );
void sceGuStencilFunc( int func, int sref, int smsk );
void sceGuStencilOp( int sfail, int zfail, int zpass );
void sceGuBlendFunc( int equ, int asel, int bsel, int afix, int bfix );
void sceGuLogicalOp( int lop );
void sceGuPixelMask( unsigned int pmsk );
void sceGuBoneMatrix( int n, const ScePspFMatrix4 *m );
void sceGuMorphWeight( int n, float f );
void sceGuSetMatrix( int mode, const ScePspFMatrix4 *f );
void sceGuDebugPrint( int x, int y, unsigned int col, const char *str );
void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world,
      int tex);
void sceGumSetCurMatrix(void);
void sceGumUpdateMatrix(void);
void sceGumMatrixMode(int mode);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumLoadMatrix(const ScePspFMatrix4 *m);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumLoadIdentity(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumRotateXYZ(const ScePspFVector3 *vec);
void sceGumRotateZYX(const ScePspFVector3 *vec);
void sceGumTranslate(const ScePspFVector3 *vec);
void sceGumScale(const ScePspFVector3 *vec);
void sceGumMultMatrix(const ScePspFMatrix4 *m);
void sceGumPerspective(float fovy, float aspect, float r_near, float r_far);
void sceGumOrtho(float left, float right, float bottom, float top,
     float r_near, float r_far);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center,
     const ScePspFVector3 *up);
void sceGumDrawArray(int prim, int type, int count, const void *idx,
     const void *p);
void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims,
     const void *idx, const void *p);
void sceGumDrawBezier(int type, int ucount, int vcount, const void *idx,
     const void *p);
void sceGumDrawSpline(int type, int ucount, int vcount, int uflag, int vflag,
     const void *idx, const void *p);
enum {
 SCEGMO_HALF_CHUNK = 0x8000,
 SCEGMO_BLOCK = 0x0001,
 SCEGMO_FILE = 0x0002,
 SCEGMO_MODEL = 0x0003,
 SCEGMO_BONE = 0x0004,
 SCEGMO_PART = 0x0005,
 SCEGMO_MESH = 0x0006,
 SCEGMO_ARRAYS = 0x0007,
 SCEGMO_MATERIAL = 0x0008,
 SCEGMO_LAYER = 0x0009,
 SCEGMO_TEXTURE = 0x000a,
 SCEGMO_MOTION = 0x000b,
 SCEGMO_FCURVE = 0x000c,
 SCEGMO_BLIND_BLOCK = 0x000f,
 SCEGMO_COMMAND = 0x0011,
 SCEGMO_FILE_NAME = 0x0012,
 SCEGMO_FILE_IMAGE = 0x0013,
 SCEGMO_BOUNDING_BOX = 0x0014,
 SCEGMO_VERTEX_OFFSET = 0x0015,
 SCEGMO_PARENT_BONE = 0x0041,
 SCEGMO_VISIBILITY = 0x0042,
 SCEGMO_MORPH_WEIGHTS = 0x0043,
 SCEGMO_MORPH_INDEX = 0x004f,
 SCEGMO_BLEND_BONES = 0x0044,
 SCEGMO_BLEND_OFFSETS = 0x0045,
 SCEGMO_PIVOT = 0x0046,
 SCEGMO_MULT_MATRIX = 0x0047,
 SCEGMO_TRANSLATE = 0x0048,
 SCEGMO_ROTATE_ZYX = 0x0049,
 SCEGMO_ROTATE_YXZ = 0x004a,
 SCEGMO_ROTATE_Q = 0x004b,
 SCEGMO_SCALE = 0x004c,
 SCEGMO_SCALE_2 = 0x004d,
 SCEGMO_DRAW_PART = 0x004e,
 SCEGMO_SET_MATERIAL = 0x0061,
 SCEGMO_BLEND_SUBSET = 0x0062,
 SCEGMO_SUBDIVISION = 0x0063,
 SCEGMO_KNOT_VECTOR_U = 0x0064,
 SCEGMO_KNOT_VECTOR_V = 0x0065,
 SCEGMO_DRAW_ARRAYS = 0x0066,
 SCEGMO_DRAW_PARTICLE = 0x0067,
 SCEGMO_DRAW_B_SPLINE = 0x0068,
 SCEGMO_DRAW_RECT_MESH = 0x0069,
 SCEGMO_DRAW_RECT_PATCH = 0x006a,
 SCEGMO_RENDER_STATE = 0x0081,
 SCEGMO_DIFFUSE = 0x0082,
 SCEGMO_SPECULAR = 0x0083,
 SCEGMO_EMISSION = 0x0084,
 SCEGMO_AMBIENT = 0x0085,
 SCEGMO_REFLECTION = 0x0086,
 SCEGMO_REFRACTION = 0x0087,
 SCEGMO_BUMP = 0x0088,
 SCEGMO_SET_TEXTURE = 0x0091,
 SCEGMO_MAP_TYPE = 0x0092,
 SCEGMO_MAP_FACTOR = 0x0093,
 SCEGMO_BLEND_FUNC = 0x0094,
 SCEGMO_TEX_FUNC = 0x0095,
 SCEGMO_TEX_FILTER = 0x0096,
 SCEGMO_TEX_WRAP = 0x0097,
 SCEGMO_TEX_CROP = 0x0098,
 SCEGMO_FRAME_LOOP = 0x00b1,
 SCEGMO_FRAME_RATE = 0x00b2,
 SCEGMO_ANIMATE = 0x00b3,
 SCEGMO_BLIND_DATA = 0x00f1,
} ;
enum {
 SCEGMO_PRIM_SEQUENTIAL = 0x0100,
 SCEGMO_PRIM_OPEN_U = 0x3000,
 SCEGMO_PRIM_OPEN_V = 0xc000,
} ;
enum {
 SCEGMO_FCURVE_CONSTANT = 0,
 SCEGMO_FCURVE_LINEAR = 1,
 SCEGMO_FCURVE_HERMITE = 2,
 SCEGMO_FCURVE_CUBIC = 3,
 SCEGMO_FCURVE_SPHERICAL = 4,
} ;
enum {
 SCEGMO_STATE_LIGHTING = 0,
 SCEGMO_STATE_FOG = 1,
 SCEGMO_STATE_TEXTURE = 2,
 SCEGMO_STATE_CULL_FACE = 3,
 SCEGMO_STATE_DEPTH_TEST = 4,
 SCEGMO_STATE_DEPTH_MASK = 5,
 SCEGMO_STATE_ALPHA_TEST = 6,
 SCEGMO_STATE_ALPHA_MASK = 7,
 SCEGMO_STATE_ENABLE_LIGHTING = 0,
 SCEGMO_STATE_ENABLE_FOG = 1,
} ;
typedef struct SceGmoHeader {
 unsigned int signature ;
 unsigned int version ;
 unsigned int style ;
 unsigned int option ;
} SceGmoHeader ;
typedef struct SceGmoChunk {
 unsigned short type ;
 unsigned short args_offs ;
 unsigned int next_offs ;
 unsigned int child_offs ;
 unsigned int data_offs ;
} SceGmoChunk ;
static inline int SCEGMO_CHUNK_TYPE( SceGmoChunk *chunk )
{
 return ( ~SCEGMO_HALF_CHUNK & chunk->type ) ;
}
static inline SceGmoChunk *SCEGMO_CHUNK_NEXT( SceGmoChunk *chunk )
{
 return (SceGmoChunk *)( (char *)chunk + chunk->next_offs ) ;
}
static inline SceGmoChunk *SCEGMO_CHUNK_CHILD( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return SCEGMO_CHUNK_NEXT( chunk ) ;
 return (SceGmoChunk *)( (char *)chunk + chunk->child_offs ) ;
}
static inline char *SCEGMO_CHUNK_NAME( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return "" ;
 return (char *)( chunk + 1 ) ;
}
static inline void *SCEGMO_CHUNK_ARGS( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return (char *)chunk + 8 ;
 return (char *)chunk + chunk->args_offs ;
}
static inline void *SCEGMO_CHUNK_DATA( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return SCEGMO_CHUNK_ARGS( chunk ) ;
 return (SceGmoChunk *)( (char *)chunk + chunk->data_offs ) ;
}
static inline int SCEGMO_CHUNK_SIZE( SceGmoChunk *chunk )
{
 return chunk->next_offs ;
}
static inline int SCEGMO_CHUNK_TAGSIZE( SceGmoChunk *chunk )
{
 return ( SCEGMO_HALF_CHUNK & chunk->type ) ? 8 : 16 ;
}
static inline int SCEGMO_CHUNK_NAMESIZE( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
 return chunk->args_offs - 16 ;
}
static inline int SCEGMO_CHUNK_ARGSSIZE( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return chunk->next_offs - 8 ;
 return chunk->data_offs - chunk->args_offs ;
}
static inline int SCEGMO_CHUNK_DATASIZE( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
 return chunk->child_offs - chunk->data_offs ;
}
static inline int SCEGMO_CHUNK_CHILDSIZE( SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
 return chunk->next_offs - chunk->child_offs ;
}
static inline void *SCEGMO_CHUNK_SKIPSTRING( const char *str, int align )
{
 str += strlen( str ) + 1 ;
 align -= 1 ;
 return (void *)( ( (int)str + align ) & ~align ) ;
}
typedef struct {
 int format ;
 int n_verts ;
 int n_morphs ;
 int format2 ;
} SceGmoArraysHeader ;
typedef struct {
 int format ;
 int n_dims ;
 int n_keys ;
 int reserved ;
} SceGmoFCurveHeader ;
typedef struct {
 char name[ 1 ] ;
} SceGmoFileName ;
typedef struct {
 int size ;
 int data[ 1 ] ;
} SceGmoFileImage ;
typedef struct {
 ScePspFVector3 lower ;
 ScePspFVector3 upper ;
} SceGmoBoundingBox ;
typedef struct {
 int format ;
 float offset[ 1 ] ;
} SceGmoVertexOffset ;
typedef struct {
 int bone ;
} SceGmoParentBone ;
typedef struct {
 int visibility ;
} SceGmoVisibility ;
typedef struct {
 int n_weights ;
 float weights[ 1 ] ;
} SceGmoMorphWeights ;
typedef struct {
 float index ;
} SceGmoMorphIndex ;
typedef struct {
 int n_bones ;
 int bones[ 1 ] ;
} SceGmoBlendBones ;
typedef struct {
 int n_offsets ;
 ScePspFMatrix4 offsets[ 1 ] ;
} __attribute__((packed))
  SceGmoBlendOffsets ;
typedef struct {
 ScePspFVector3 pivot ;
} SceGmoPivot ;
typedef struct {
 ScePspFMatrix4 matrix ;
} SceGmoMultMatrix ;
typedef struct {
 ScePspFVector3 translate ;
} SceGmoTranslate ;
typedef struct {
 ScePspFVector3 rotate ;
} SceGmoRotateZYX ;
typedef struct {
 ScePspFVector3 rotate ;
} SceGmoRotateYXZ ;
typedef struct {
 ScePspFQuaternion rotate ;
} SceGmoRotateQ ;
typedef struct {
 ScePspFVector3 scale ;
} SceGmoScale ;
typedef struct {
 ScePspFVector3 scale ;
} SceGmoScale2 ;
typedef struct {
 int part ;
} SceGmoDrawPart ;
typedef struct {
 int material ;
} SceGmoSetMaterial ;
typedef struct {
 int n_indices ;
 int indices[ 1 ] ;
} SceGmoBlendSubset ;
typedef struct {
 float div_u ;
 float div_v ;
} SceGmoSubdivision ;
typedef struct {
 int arrays ;
 int mode ;
 int n_verts ;
 int n_prims ;
 short indices[ 1 ] ;
} SceGmoDrawArrays ;
typedef struct {
 int arrays ;
 int mode ;
 int n_verts ;
 int n_prims ;
 short indices[ 1 ] ;
} SceGmoDrawParticle ;
typedef struct {
 int arrays ;
 int mode ;
 int width ;
 int height ;
 short indices[ 1 ] ;
} SceGmoDrawBSpline ;
typedef struct {
 int arrays ;
 int mode ;
 int width ;
 int height ;
 short indices[ 1 ] ;
} SceGmoDrawRectMesh ;
typedef struct {
 int arrays ;
 int mode ;
 int width ;
 int height ;
 short indices[ 1 ] ;
} SceGmoDrawRectPatch ;
typedef struct {
 int state ;
 int value ;
} SceGmoRenderState ;
typedef struct {
 ScePspFVector4 color ;
} SceGmoDiffuse ;
typedef struct {
 ScePspFVector4 color ;
 float shininess ;
} SceGmoSpecular ;
typedef struct {
 ScePspFVector4 color ;
} SceGmoEmission ;
typedef struct {
 ScePspFVector4 color ;
} SceGmoAmbient ;
typedef struct {
 float reflection ;
} SceGmoReflection ;
typedef struct {
 float refraction ;
} SceGmoRefraction ;
typedef struct {
 float bump ;
} SceGmoBump ;
typedef struct {
 int texture ;
} SceGmoSetTexture ;
typedef struct {
 int type ;
} SceGmoMapType ;
typedef struct {
 float factor ;
} SceGmoMapFactor ;
typedef struct {
 int mode ;
 int src ;
 int dst ;
} SceGmoBlendFunc ;
typedef struct {
 int func ;
 int comp ;
} SceGmoTexFunc ;
typedef struct {
 int mag ;
 int min ;
} SceGmoTexFilter ;
typedef struct {
 int wrap_u ;
 int wrap_v ;
} SceGmoTexWrap ;
typedef struct {
 ScePspFRect crop ;
} SceGmoTexCrop ;
typedef struct {
 float start ;
 float end ;
} SceGmoFrameLoop ;
typedef struct {
 float fps ;
} SceGmoFrameRate ;
typedef struct {
 int block ;
 int cmd ;
 int index ;
 int fcurve ;
} SceGmoAnimate ;
typedef struct {
 char name[ 1 ] ;
} SceGmoBlindData ;
enum {
 SCEGIM_BLOCK = 0x0001,
 SCEGIM_FILE = 0x0002,
 SCEGIM_PICTURE = 0x0003,
 SCEGIM_IMAGE = 0x0004,
 SCEGIM_PALETTE = 0x0005,
 SCEGIM_SEQUENCE = 0x0006,
} ;
enum {
 SCEGIM_RGBA_5650 = 0,
 SCEGIM_RGBA_5551 = 1,
 SCEGIM_RGBA_4444 = 2,
 SCEGIM_RGBA_8888 = 3,
 SCEGIM_INDEX_4 = 4,
 SCEGIM_INDEX_8 = 5,
 SCEGIM_INDEX_16 = 6,
 SCEGIM_INDEX_32 = 7,
} ;
enum {
 SCEGIM_ORDER_NORMAL = 0,
 SCEGIM_ORDER_PSPIMAGE = 1,
} ;
enum {
 SCEGIM_TYPE_GENERIC = 0,
 SCEGIM_TYPE_MIPMAP = 1,
 SCEGIM_TYPE_MIPMAP2 = 2,
 SCEGIM_TYPE_SEQUENCE = 3,
} ;
enum {
 SCEGIM_INTERP_CONSTANT = 0,
 SCEGIM_INTERP_LINEAR = 1,
 SCEGIM_INTERP_DISSOLVE = 0x80,
} ;
enum {
 SCEGIM_PARAM_IMAGE_INDEX = 0,
 SCEGIM_PARAM_IMAGE_PLANE = 1,
 SCEGIM_PARAM_IMAGE_LEVEL = 2,
 SCEGIM_PARAM_IMAGE_FRAME = 3,
 SCEGIM_PARAM_PALETTE_INDEX = 8,
 SCEGIM_PARAM_PALETTE_LEVEL = 10,
 SCEGIM_PARAM_PALETTE_FRAME = 11,
 SCEGIM_PARAM_CROP_U = 16,
 SCEGIM_PARAM_CROP_V = 17,
 SCEGIM_PARAM_CROP_W = 18,
 SCEGIM_PARAM_CROP_H = 19,
 SCEGIM_PARAM_BLEND_MODE = 32,
 SCEGIM_PARAM_FUNC_MODE = 34,
 SCEGIM_PARAM_FUNC_COMP = 35,
 SCEGIM_PARAM_FILTER_MAG = 36,
 SCEGIM_PARAM_FILTER_MIN = 37,
 SCEGIM_PARAM_WRAP_U = 38,
 SCEGIM_PARAM_WRAP_V = 39,
} ;
enum {
 SCEGIM_BLEND_OFF = 0,
 SCEGIM_BLEND_MIX = 1,
 SCEGIM_BLEND_ADD = 2,
 SCEGIM_BLEND_SUB = 3,
} ;
enum {
 SCEGIM_FUNC_MODULATE = 0,
 SCEGIM_FUNC_DECAL = 1,
 SCEGIM_FUNC_RGB = 0,
 SCEGIM_FUNC_RGBA = 1,
} ;
enum {
 SCEGIM_FILTER_NEAREST = 0,
 SCEGIM_FILTER_LINEAR = 1,
 SCEGIM_FILTER_NEAREST_MIPMAP_NEAREST = 4,
 SCEGIM_FILTER_LINEAR_MIPMAP_NEAREST = 5,
 SCEGIM_FILTER_NEAREST_MIPMAP_LINEAR = 6,
 SCEGIM_FILTER_LINEAR_MIPMAP_LINEAR = 7,
} ;
enum {
 SCEGIM_WRAP_REPEAT = 0,
 SCEGIM_WRAP_CLAMP = 1,
} ;
typedef struct {
 unsigned int signature ;
 unsigned int version ;
 unsigned int style ;
 unsigned int option ;
} SceGimHeader ;
typedef struct {
 unsigned short type ;
 unsigned short unused ;
 unsigned int next_offs ;
 unsigned int child_offs ;
 unsigned int data_offs ;
} SceGimChunk ;
static inline int SCEGIM_CHUNK_TYPE( SceGimChunk *chunk )
{
 return chunk->type ;
}
static inline SceGimChunk *SCEGIM_CHUNK_NEXT( SceGimChunk *chunk )
{
 return (SceGimChunk *)( (char *)chunk + chunk->next_offs ) ;
}
static inline SceGimChunk *SCEGIM_CHUNK_CHILD( SceGimChunk *chunk )
{
 return (SceGimChunk *)( (char *)chunk + chunk->child_offs ) ;
}
static inline void *SCEGIM_CHUNK_DATA( SceGimChunk *chunk )
{
 return (SceGimChunk *)( (char *)chunk + chunk->data_offs ) ;
}
static inline int SCEGIM_CHUNK_SIZE( SceGimChunk *chunk )
{
 return chunk->next_offs ;
}
static inline int SCEGIM_CHUNK_TAG_SIZE( SceGimChunk *chunk )
{
 (void)chunk ;
 return 16 ;
}
static inline int SCEGIM_CHUNK_DATA_SIZE( SceGimChunk *chunk )
{
 return chunk->child_offs - chunk->data_offs ;
}
static inline int SCEGIM_CHUNK_CHILD_SIZE( SceGimChunk *chunk )
{
 return chunk->next_offs - chunk->child_offs ;
}
typedef struct {
 unsigned short header_size ;
 unsigned short reference ;
 unsigned short format ;
 unsigned short order ;
 unsigned short width ;
 unsigned short height ;
 unsigned short bpp ;
 unsigned short pitch_align ;
 unsigned short height_align ;
 unsigned short dim_count ;
 unsigned short reserved ;
 unsigned short reserved2 ;
 unsigned int offsets ;
 unsigned int images ;
 unsigned int total ;
 unsigned int plane_mask ;
 unsigned short level_type ;
 unsigned short level_count ;
 unsigned short frame_type ;
 unsigned short frame_count ;
} SceGimImageHeader ;
typedef SceGimImageHeader SceGimPaletteHeader ;
typedef struct {
 unsigned short header_size ;
 unsigned short reference ;
 unsigned short frame_start ;
 unsigned short frame_end ;
 unsigned short frame_rate ;
 unsigned short reserved ;
 unsigned short n_constants ;
 unsigned short n_functions ;
 unsigned int constants ;
 unsigned int functions ;
 unsigned int keyframes ;
 unsigned int total ;
} SceGimSequenceHeader ;
typedef struct {
 unsigned short param ;
 short value ;
} SceGimConstant ;
typedef struct {
 unsigned short param ;
 unsigned short interp ;
 unsigned int keyframes ;
} SceGimFunction ;
typedef struct {
 short count ;
 short values[ 1 ] ;
} SceGimKeyframe ;
enum {
 SCEGIM_DUPLICATE_REFERENCE = 0x0000,
 SCEGIM_DUPLICATE_STRUCTURE = 0x0001,
 SCEGIM_DUPLICATE_AUTOMATIC = 0x0002,
 SCEGIM_DUPLICATE_PICTURE = 0x0008,
 SCEGIM_DUPLICATE_IMAGE = 0x0010,
 SCEGIM_DUPLICATE_PALETTE = 0x0020,
 SCEGIM_DUPLICATE_SEQUENCE = 0x0040,
} ;
enum {
 SCEGIM_ENABLE_ALL = 0xffff,
 SCEGIM_ENABLE_DISSOLVE = 0x0001,
} ;
typedef struct SceGimPicture SceGimPicture ;
void sceGimPictureSetMemoryManager( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGimPictureSetMemoryManager2( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void *sceGimPictureAllocMemory( size_t size ) ;
void sceGimPictureFreeMemory( void *addr ) ;
void *sceGimPictureAllocMemory2( size_t size ) ;
void sceGimPictureFreeMemory2( void *addr ) ;
_Bool sceGimPictureCheckFileHeader( const void *buf, int size ) ;
int sceGimPictureGetChunkCount( const void *buf, int size ) ;
SceGimChunk *sceGimPictureGetChunk( const void *buf, int size, int index ) ;
SceGimPicture *sceGimPictureCreate( SceGimChunk *chunk ) ;
void sceGimPictureDelete( SceGimPicture *picture ) ;
SceGimPicture *sceGimPictureDuplicate( SceGimPicture *picture, int flags ) ;
_Bool sceGimPictureLoadFile( SceGimPicture *picture, const void *buf, int size, int index ) ;
_Bool sceGimPictureLoadGim( SceGimPicture *picture, const void *buf, int size, int index ) ;
_Bool sceGimPictureLoadTm2( SceGimPicture *picture, const void *buf, int size, int index ) ;
_Bool sceGimPictureLoadTga( SceGimPicture *picture, const void *buf, int size ) ;
_Bool sceGimPictureLoadBmp( SceGimPicture *picture, const void *buf, int size ) ;
_Bool sceGimPictureLoad( SceGimPicture *picture, SceGimChunk *chunk ) ;
void sceGimPictureUnload( SceGimPicture *picture ) ;
void sceGimPictureAnimate( SceGimPicture *picture, float step ) ;
void sceGimPictureActivate( SceGimPicture *picture ) ;
void sceGimPictureSetEnableBits( SceGimPicture *picture, int bits, int value ) ;
int sceGimPictureGetEnableBits( SceGimPicture *picture ) ;
SceGimImageHeader *sceGimPictureGetImage( SceGimPicture *picture ) ;
SceGimPaletteHeader *sceGimPictureGetPalette( SceGimPicture *picture ) ;
void *sceGimPictureGetImagePixels( SceGimPicture *picture, int level, int frame ) ;
void *sceGimPictureGetPalettePixels( SceGimPicture *picture, int level, int frame ) ;
void sceGimPictureSetImagePixels( SceGimPicture *picture, int level, int frame, void *pixels ) ;
void sceGimPictureSetPalettePixels( SceGimPicture *picture, int level, int frame, void *pixels ) ;
_Bool sceGimPictureReallocImage( SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels ) ;
_Bool sceGimPictureReallocPalette( SceGimPicture *picture, int format, int w, int level, int frame, void *pixels ) ;
_Bool sceGimPictureHasAnimation( SceGimPicture *picture ) ;
void sceGimPictureSetFrameLoop( SceGimPicture *picture, float start, float end ) ;
const float *sceGimPictureGetFrameLoop( SceGimPicture *picture ) ;
void sceGimPictureSetFrameRate( SceGimPicture *picture, float fps ) ;
float sceGimPictureGetFrameRate( SceGimPicture *picture ) ;
void sceGimPictureSetFrame( SceGimPicture *picture, float frame ) ;
float sceGimPictureGetFrame( SceGimPicture *picture ) ;
void sceGimPictureSetImageFrame( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetImageFrame( SceGimPicture *picture ) ;
void sceGimPictureSetImageFrame2( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetImageFrame2( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteFrame( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetPaletteFrame( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteFrame2( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetPaletteFrame2( SceGimPicture *picture ) ;
void sceGimPictureSetDissolve( SceGimPicture *picture, float dissolve ) ;
float sceGimPictureGetDissolve( SceGimPicture *picture ) ;
void sceGimPictureSetImageCrop( SceGimPicture *picture, const float *crop ) ;
const float *sceGimPictureGetImageCrop( SceGimPicture *picture ) ;
enum {
 SCEGMO_DUPLICATE_REFERENCE = 0x0000,
 SCEGMO_DUPLICATE_STRUCTURE = 0x0001,
 SCEGMO_DUPLICATE_AUTOMATIC = 0x0002,
 SCEGMO_DUPLICATE_MODEL = 0x0008,
 SCEGMO_DUPLICATE_BONE = 0x0010,
 SCEGMO_DUPLICATE_PART = 0x0020,
 SCEGMO_DUPLICATE_MESH = 0x0040,
 SCEGMO_DUPLICATE_ARRAYS = 0x0080,
 SCEGMO_DUPLICATE_MATERIAL = 0x0100,
 SCEGMO_DUPLICATE_LAYER = 0x0200,
 SCEGMO_DUPLICATE_TEXTURE = 0x0400,
 SCEGMO_DUPLICATE_MOTION = 0x0800,
 SCEGMO_DUPLICATE_FCURVE = 0x1000,
} ;
enum {
 SCEGMO_ENABLE_ALL = 0xffff,
 SCEGMO_ENABLE_LIGHTING = 0x0001,
 SCEGMO_ENABLE_FOG = 0x0002,
 SCEGMO_ENABLE_TEXTURE = 0x0004,
 SCEGMO_ENABLE_CULL_FACE = 0x0008,
 SCEGMO_ENABLE_DEPTH_TEST = 0x0010,
 SCEGMO_ENABLE_DEPTH_MASK = 0x0020,
 SCEGMO_ENABLE_ALPHA_TEST = 0x0040,
 SCEGMO_ENABLE_ALPHA_MASK = 0x0080,
} ;
typedef struct SceGmoModel SceGmoModel ;
typedef struct SceGmoBone SceGmoBone ;
typedef struct SceGmoPart SceGmoPart ;
typedef struct SceGmoMesh SceGmoMesh ;
typedef struct SceGmoMaterial SceGmoMaterial ;
typedef struct SceGmoLayer SceGmoLayer ;
typedef struct SceGmoTexture SceGmoTexture ;
typedef struct SceGmoMotion SceGmoMotion ;
void sceGmoModelSetMemoryManager( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetMemoryManager2( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetPictureManager( SceGimPicture *(*get_func)( const char *filename ), void (*set_func)( const char *filename, SceGimPicture *picture ) ) ;
void *sceGmoModelAllocMemory( size_t size ) ;
void *sceGmoModelAllocMemory2( size_t size ) ;
void sceGmoModelFreeMemory( void *addr ) ;
void sceGmoModelFreeMemory2( void *addr ) ;
SceGimPicture *sceGmoModelImportPicture( const char *filename ) ;
void sceGmoModelExportPicture( const char *filename, SceGimPicture *picture ) ;
_Bool sceGmoModelCheckFileHeader( const void *buf, int size ) ;
int sceGmoModelGetChunkCount( const void *buf, int size ) ;
SceGmoChunk *sceGmoModelGetChunk( const void *buf, int size, int index ) ;
SceGmoModel *sceGmoModelCreate( SceGmoChunk *chunk ) ;
void sceGmoModelDelete( SceGmoModel *model ) ;
SceGmoModel *sceGmoModelDuplicate( SceGmoModel *model, int flags ) ;
_Bool sceGmoModelLoadFile( SceGmoModel *model, const void *buf, int size, int index ) ;
_Bool sceGmoModelLoad( SceGmoModel *model, SceGmoChunk *chunk ) ;
void sceGmoModelUnload( SceGmoModel *model ) ;
void sceGmoModelAnimate( SceGmoModel *model, float step ) ;
void sceGmoModelUpdate( SceGmoModel *model ) ;
void sceGmoModelDraw( SceGmoModel *model ) ;
void sceGmoModelSetWorldMatrix( SceGmoModel *model, const ScePspFMatrix4 *m ) ;
const ScePspFMatrix4 *sceGmoModelGetWorldMatrix( SceGmoModel *model ) ;
void sceGmoModelSetCurrentMotion( SceGmoModel *model, int index, float delay ) ;
int sceGmoModelGetCurrentMotion( SceGmoModel *model ) ;
void sceGmoModelSetEnableBits( SceGmoModel *model, int bits, int value ) ;
int sceGmoModelGetEnableBits( SceGmoModel *model ) ;
void sceGmoModelSetEnableMask( SceGmoModel *model, int mask, int value ) ;
int sceGmoModelGetEnableMask( SceGmoModel *model ) ;
const ScePspFVector3 *sceGmoModelGetBoundingBox( SceGmoModel *model ) ;
const ScePspFMatrix4 *sceGmoModelGetVertexOffset( SceGmoModel *model ) ;
const ScePspFRect *sceGmoModelGetTexcoordOffset( SceGmoModel *model ) ;
int sceGmoModelGetBoneCount( SceGmoModel *model ) ;
int sceGmoModelGetPartCount( SceGmoModel *model ) ;
int sceGmoModelGetMaterialCount( SceGmoModel *model ) ;
int sceGmoModelGetTextureCount( SceGmoModel *model ) ;
int sceGmoModelGetMotionCount( SceGmoModel *model ) ;
SceGmoBone *sceGmoModelGetBone( SceGmoModel *model, int index ) ;
SceGmoPart *sceGmoModelGetPart( SceGmoModel *model, int index ) ;
SceGmoMaterial *sceGmoModelGetMaterial( SceGmoModel *model, int index ) ;
SceGmoTexture *sceGmoModelGetTexture( SceGmoModel *model, int index ) ;
SceGmoMotion *sceGmoModelGetMotion( SceGmoModel *model, int index ) ;
SceGmoBone *sceGmoModelSetBone( SceGmoModel *model, int index, SceGmoBone *bone, int flags ) ;
SceGmoPart *sceGmoModelSetPart( SceGmoModel *model, int index, SceGmoPart *part, int flags ) ;
SceGmoMaterial *sceGmoModelSetMaterial( SceGmoModel *model, int index, SceGmoMaterial *material, int flags ) ;
SceGmoTexture *sceGmoModelSetTexture( SceGmoModel *model, int index, SceGmoTexture *texture, int flags ) ;
SceGmoMotion *sceGmoModelSetMotion( SceGmoModel *model, int index, SceGmoMotion *motion, int flags ) ;
SceGmoBone *sceGmoBoneCreate( SceGmoChunk *chunk ) ;
void sceGmoBoneDelete( SceGmoBone *bone ) ;
SceGmoBone *sceGmoBoneDuplicate( SceGmoBone *bone, int flags ) ;
_Bool sceGmoBoneLoad( SceGmoBone *bone, SceGmoChunk *chunk ) ;
void sceGmoBoneUnload( SceGmoBone *bone ) ;
void sceGmoBoneUpdate( SceGmoBone *bone, SceGmoModel *model ) ;
void sceGmoBoneDraw( SceGmoBone *bone, SceGmoModel *model ) ;
void sceGmoBoneActivate( SceGmoBone *bone, SceGmoModel *model, const int *indices, int nIndices ) ;
void sceGmoBoneAnimate( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoBoneSetParent( SceGmoBone *bone, SceGmoModel *parent ) ;
SceGmoModel *sceGmoBoneGetParent( SceGmoBone *bone ) ;
const ScePspFMatrix4 *sceGmoBoneGetWorldMatrix( SceGmoBone *bone ) ;
SceGmoPart *sceGmoPartCreate( SceGmoChunk *chunk ) ;
void sceGmoPartDelete( SceGmoPart *part ) ;
SceGmoPart *sceGmoPartDuplicate( SceGmoPart *part, int flags ) ;
_Bool sceGmoPartLoad( SceGmoPart *part, SceGmoChunk *chunk ) ;
void sceGmoPartUnload( SceGmoPart *part ) ;
void sceGmoPartDraw( SceGmoPart *part, SceGmoModel *model, SceGmoBone *bone ) ;
void sceGmoPartSetParent( SceGmoPart *part, SceGmoModel *parent ) ;
SceGmoModel *sceGmoPartGetParent( SceGmoPart *part ) ;
int sceGmoPartGetMeshCount( SceGmoPart *part ) ;
int sceGmoPartGetArraysCount( SceGmoPart *part ) ;
SceGmoMesh *sceGmoPartGetMesh( SceGmoPart *part, int index ) ;
SceGmoChunk *sceGmoPartGetArrays( SceGmoPart *part, int index ) ;
SceGmoMesh *sceGmoMeshCreate( SceGmoChunk *chunk ) ;
void sceGmoMeshDelete( SceGmoMesh *mesh ) ;
SceGmoMesh *sceGmoMeshDuplicate( SceGmoMesh *mesh, int flags ) ;
_Bool sceGmoMeshLoad( SceGmoMesh *mesh, SceGmoChunk *chunk ) ;
void sceGmoMeshUnload( SceGmoMesh *mesh ) ;
void sceGmoMeshDraw( SceGmoMesh *mesh, SceGmoModel *model, SceGmoBone *bone, SceGmoPart *part ) ;
SceGmoMaterial *sceGmoMaterialCreate( SceGmoChunk *chunk ) ;
void sceGmoMaterialDelete( SceGmoMaterial *material ) ;
SceGmoMaterial *sceGmoMaterialDuplicate( SceGmoMaterial *material, int flags ) ;
_Bool sceGmoMaterialLoad( SceGmoMaterial *material, SceGmoChunk *chunk ) ;
void sceGmoMaterialUnload( SceGmoMaterial *material ) ;
void sceGmoMaterialUpdate( SceGmoMaterial *material, SceGmoModel *model ) ;
int sceGmoMaterialActivate( SceGmoMaterial *material, SceGmoModel *model, int index ) ;
void sceGmoMaterialAnimate( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoMaterialSetParent( SceGmoMaterial *material, SceGmoModel *parent ) ;
SceGmoModel *sceGmoMaterialGetParent( SceGmoMaterial *material ) ;
int sceGmoMaterialGetLayerCount( SceGmoMaterial *material ) ;
SceGmoLayer *sceGmoMaterialGetLayer( SceGmoMaterial *material, int index ) ;
SceGmoLayer *sceGmoLayerCreate( SceGmoChunk *chunk ) ;
void sceGmoLayerDelete( SceGmoLayer *layer ) ;
SceGmoLayer *sceGmoLayerDuplicate( SceGmoLayer *layer, int flags ) ;
_Bool sceGmoLayerLoad( SceGmoLayer *layer, SceGmoChunk *chunk ) ;
void sceGmoLayerUnload( SceGmoLayer *layer ) ;
int sceGmoLayerActivate( SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material ) ;
void sceGmoLayerSetMapType( SceGmoLayer *layer, int type ) ;
int sceGmoLayerGetMapType( SceGmoLayer *layer ) ;
void sceGmoLayerSetTexCrop( SceGmoLayer *layer, const ScePspFRect *crop ) ;
const ScePspFRect *sceGmoLayerGetTexCrop( SceGmoLayer *layer ) ;
SceGmoTexture *sceGmoTextureCreate( SceGmoChunk *chunk ) ;
void sceGmoTextureDelete( SceGmoTexture *texture ) ;
SceGmoTexture *sceGmoTextureDuplicate( SceGmoTexture *texture, int flags ) ;
_Bool sceGmoTextureLoad( SceGmoTexture *texture, SceGmoChunk *chunk ) ;
void sceGmoTextureUnload( SceGmoTexture *texture ) ;
void sceGmoTextureUpdate( SceGmoTexture *texture, SceGmoModel *model, float step ) ;
void sceGmoTextureActivate( SceGmoTexture *texture, SceGmoModel *model ) ;
void sceGmoTextureSetParent( SceGmoTexture *texture, SceGmoModel *parent ) ;
SceGmoModel *sceGmoTextureGetParent( SceGmoTexture *texture ) ;
void sceGmoTextureSetPicture( SceGmoTexture *texture, SceGimPicture *picture, int flags ) ;
SceGimPicture *sceGmoTextureGetPicture( SceGmoTexture *texture ) ;
_Bool sceGmoTextureHasAnimation( SceGmoTexture *texture ) ;
SceGmoMotion *sceGmoMotionCreate( SceGmoChunk *chunk ) ;
void sceGmoMotionDelete( SceGmoMotion *motion ) ;
SceGmoMotion *sceGmoMotionDuplicate( SceGmoMotion *motion, int flags ) ;
_Bool sceGmoMotionLoad( SceGmoMotion *motion, SceGmoChunk *chunk ) ;
void sceGmoMotionUnload( SceGmoMotion *motion ) ;
void sceGmoMotionUpdate( SceGmoMotion *motion, SceGmoModel *model, float step ) ;
void sceGmoMotionSetParent( SceGmoMotion *motion, SceGmoModel *parent ) ;
SceGmoModel *sceGmoMotionGetParent( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameLoop( SceGmoMotion *motion, float start, float end ) ;
const float *sceGmoMotionGetFrameLoop( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameRate( SceGmoMotion *motion, float fps ) ;
float sceGmoMotionGetFrameRate( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameRepeat( SceGmoMotion *motion, int mode ) ;
int sceGmoMotionGetFrameRepeat( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrame( SceGmoMotion *motion, float frame ) ;
float sceGmoMotionGetFrame( SceGmoMotion *motion ) ;
void sceGmoMotionSetWeight( SceGmoMotion *motion, float weight ) ;
float sceGmoMotionGetWeight( SceGmoMotion *motion ) ;
int sceGmoMotionGetAnimationCount( SceGmoMotion *motion ) ;
int sceGmoMotionGetFcurveCount( SceGmoMotion *motion ) ;
SceGmoChunk *sceGmoMotionGetAnimation( SceGmoMotion *motion, int index ) ;
SceGmoChunk *sceGmoMotionGetFcurve( SceGmoMotion *motion, int index ) ;
typedef struct SceGmoSubject {
 struct SceGmoObserver *m_observers ;
} SceGmoSubject ;
typedef struct SceGmoObserver {
 struct SceGmoObserver *m_next ;
 struct SceGmoSubject *m_subject ;
 void *m_reserved ;
} SceGmoObserver ;
typedef struct SceGmoBase {
 struct SceGmoSubject m_subject ;
 struct SceGmoObserver m_parent ;
} SceGmoBase ;
void sceGmoSubjectConstruct( SceGmoSubject *subject ) ;
void sceGmoSubjectDestruct( SceGmoSubject *subject ) ;
void sceGmoSubjectCopy( SceGmoSubject *subject, const SceGmoSubject *src ) ;
void sceGmoSubjectAttachObserver( SceGmoSubject *subject, SceGmoObserver *observer ) ;
void sceGmoSubjectDetachObserver( SceGmoSubject *subject, SceGmoObserver *observer ) ;
void sceGmoObserverConstruct( SceGmoObserver *observer ) ;
void sceGmoObserverDestruct( SceGmoObserver *observer ) ;
void sceGmoObserverCopy( SceGmoObserver *observer, const SceGmoObserver *src ) ;
void sceGmoObserverSetSubject( SceGmoObserver *observer, SceGmoSubject *subject ) ;
static inline SceGmoSubject *sceGmoObserverGetSubject( const SceGmoObserver *observer )
{
 return ( observer == 0 ) ? 0 : observer->m_subject ;
}
void sceGmoBaseConstruct( SceGmoBase *base ) ;
void sceGmoBaseDestruct( SceGmoBase *base ) ;
void sceGmoBaseCopy( SceGmoBase *base, const SceGmoBase *src ) ;
void sceGmoBaseAttachObserver( SceGmoBase *base, SceGmoObserver *observer ) ;
void sceGmoBaseDetachObserver( SceGmoBase *base, SceGmoObserver *observer ) ;
void sceGmoBaseSetParent( SceGmoBase *base, SceGmoSubject *parent ) ;
static inline SceGmoSubject *sceGmoBaseGetParent( const SceGmoBase *base )
{
 return ( base == 0 ) ? 0 : base->m_parent.m_subject ;
}
enum {
 SCEGMO_MODEL_HAS_BOUNDING_BOX = 0x0001,
 SCEGMO_MODEL_HAS_VERTEX_OFFSET = 0x0002,
 SCEGMO_MODEL_HAS_TEXCOORD_OFFSET = 0x0004,
} ;
struct SceGmoModel {
 SceGmoBase m_base ;
 int m_reference ;
 int m_flags ;
 SceGmoBone **m_bones ;
 SceGmoPart **m_parts ;
 SceGmoMaterial **m_materials ;
 SceGmoTexture **m_textures ;
 SceGmoMotion **m_motions ;
 int m_n_bones ;
 int m_n_parts ;
 int m_n_materials ;
 int m_n_textures ;
 int m_n_motions ;
 int m_current_motion ;
 float m_change_motion ;
 ScePspFMatrix4 m_world_matrix ;
 int m_enable_bits ;
 int m_enable_mask ;
 ScePspFVector3 m_bounding_box[ 2 ] ;
 ScePspFMatrix4 m_vertex_offset ;
 ScePspFRect m_texcoord_offset ;
} ;
struct SceGmoBone {
 SceGmoBase m_base ;
 SceGmoBone *m_initial ;
 int m_reference ;
 int m_flags ;
 int m_parent_bone ;
 int m_visibility ;
 ScePspFVector3 m_pivot ;
 ScePspFVector3 m_translate ;
 ScePspFQuaternion m_rotate ;
 ScePspFVector3 m_scale ;
 ScePspFMatrix4 m_local_matrix ;
 ScePspFMatrix4 m_stack_matrix ;
 ScePspFVector3 m_stack_scale ;
 ScePspFMatrix4 m_world_matrix ;
 int *m_draw_parts ;
 float *m_morph_weights ;
 int *m_blend_bones ;
 ScePspFMatrix4 *m_blend_offsets ;
 int m_n_draw_parts ;
 int m_n_morph_weights ;
 int m_n_blend_bones ;
 int m_n_blend_offsets ;
 int m_anim_flags ;
 float m_anim_weights[ 5 ] ;
} ;
struct SceGmoPart {
 SceGmoBase m_base ;
 SceGmoChunk *m_chunk ;
 int m_reference ;
 int m_flags ;
 SceGmoMesh **m_meshes ;
 SceGmoChunk **m_arrays ;
 int m_n_meshes ;
 int m_n_arrays ;
} ;
struct SceGmoMesh {
 SceGmoChunk *m_chunk ;
 int m_reference ;
 int m_flags ;
 int m_material ;
 int *m_blend_subset ;
 int m_n_blend_subset ;
} ;
struct SceGmoMaterial {
 SceGmoBase m_base ;
 SceGmoMaterial *m_initial ;
 int m_reference ;
 int m_flags ;
 SceGmoLayer *m_layers[ 8 ] ;
 int m_n_layers ;
 int m_enable_mask ;
 int m_enable_bits ;
 int m_colors[ 6 ] ;
 float m_shininess ;
 float m_refraction ;
 float m_bump ;
 int m_anim_flags ;
 float m_anim_weights[ 5 ] ;
} ;
struct SceGmoLayer {
 SceGmoLayer *m_initial ;
 int m_reference ;
 int m_flags ;
 int m_map_type ;
 float m_map_factor ;
 int m_blend_func[ 5 ] ;
 int m_texture ;
 ScePspFRect m_tex_crop ;
 int m_enable_mask ;
 int m_enable_bits ;
 int m_diffuse ;
 int m_specular ;
 int m_ambient ;
} ;
struct SceGmoTexture {
 SceGmoBase m_base ;
 SceGimPicture *m_picture ;
 int m_reference ;
 int m_flags ;
} ;
struct SceGmoMotion {
 SceGmoBase m_base ;
 SceGmoChunk *m_chunk ;
 int m_reference ;
 int m_flags ;
 SceGmoChunk **m_anims ;
 SceGmoChunk **m_fcurves ;
 int m_n_anims ;
 int m_n_fcurves ;
 float m_frame_loop[ 2 ] ;
 float m_frame_rate ;
 float m_frame ;
 float m_weight ;
} ;
enum {
 SCEGMO_ENABLE_PRIVATE = 0xffff0000,
 SCEGMO_ENABLE_FLUSH = 0x80000000,
 SCEGMO_ENABLE_SEPARATE_SPECULAR = 0x00010000,
 SCEGMO_ENABLE_SHADE_MAP = 0x00020000,
 SCEGMO_ENABLE_DEFAULT = SCEGMO_ENABLE_ALL
     | SCEGMO_ENABLE_SEPARATE_SPECULAR,
} ;
void sceGmoContextBegin() ;
void sceGmoContextEnd() ;
void sceGmoContextSetBone( SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices ) ;
int sceGmoContextSetMaterial( SceGmoMaterial *material, SceGmoModel *model, int index ) ;
void sceGmoContextSetTexture( SceGmoTexture *texture, SceGmoModel *model ) ;
void sceGmoContextDefaultEnableBits( int mask, int bits ) ;
void sceGmoContextSetEnableBits( int mask, int bits ) ;
void sceGmoContextDefaultTexOffs( const ScePspFRect *offs ) ;
void sceGmoContextDefaultTexCrop( const ScePspFRect *crop ) ;
void sceGmoContextDefaultTexTrim( const ScePspFRect *trim ) ;
void sceGmoContextSetTexOffs( const ScePspFRect *offs ) ;
void sceGmoContextSetTexCrop( const ScePspFRect *crop ) ;
void sceGmoContextSetTexTrim( const ScePspFRect *trim ) ;
void sceKernelDcacheWritebackAll(void);
void sceKernelDcacheWritebackInvalidateAll(void);
void sceKernelDcacheWritebackRange(const char *start, unsigned int size);
void sceKernelDcacheWritebackInvalidateRange(const char *start, unsigned int size);
static __inline__ unsigned int sceKernelMakePhysicalAddr(const void *v)
{
 return (((unsigned int)v) & 0x1FFFFFFF);
}
typedef struct SceKernelUtilsMd5Context {
 unsigned int h[4];
 unsigned int pad;
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long int ullTotalLen;
 unsigned char buf[64];
} SceKernelUtilsMd5Context;
int sceKernelUtilsMd5Digest(const unsigned char *plain, unsigned int uiLen, unsigned char *digest);
int sceKernelUtilsMd5BlockInit(SceKernelUtilsMd5Context *pContext);
int sceKernelUtilsMd5BlockUpdate(SceKernelUtilsMd5Context *pContext, const unsigned char *plain, unsigned int uiLen);
int sceKernelUtilsMd5BlockResult(SceKernelUtilsMd5Context *pContext, unsigned char *digest);
typedef struct SceKernelUtilsSha1Context {
 unsigned int h[5];
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long int ullTotalLen;
 unsigned char buf[64];
} SceKernelUtilsSha1Context;
int sceKernelUtilsSha1Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);
int sceKernelUtilsSha1BlockInit(SceKernelUtilsSha1Context *pContext);
int sceKernelUtilsSha1BlockUpdate(SceKernelUtilsSha1Context *pContext, const unsigned char *plain, unsigned int uiLen);
int sceKernelUtilsSha1BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);
typedef struct SceKernelUtilsMt19937Context {
 unsigned int count;
 unsigned int state[624];
} SceKernelUtilsMt19937Context;
int sceKernelUtilsMt19937Init(SceKernelUtilsMt19937Context *pCtx, unsigned int seed);
unsigned int sceKernelUtilsMt19937UInt(SceKernelUtilsMt19937Context *pCtx);
typedef ScePspFVector2 vec2 ;
typedef ScePspFVector3 vec3 ;
typedef ScePspFVector4 vec4 ;
typedef ScePspFMatrix4 mat4 ;
typedef ScePspFRect rect ;
typedef ScePspFQuaternion quat ;
int sceGmoModelCountChunk( SceGmoChunk *chunk, int type ) ;
SceGmoChunk *sceGmoModelFindChunk( SceGmoChunk *chunk, int type, int index ) ;
_Bool sceGmoModelAllocPtr( void *ptr_ptr, int size ) ;
_Bool sceGmoModelAllocPtr2( void *ptr_ptr, int size ) ;
_Bool sceGmoModelCopyPtr( void *ptr_ptr, const void *src, int size ) ;
_Bool sceGmoModelCopyPtr2( void *ptr_ptr, const void *src, int size ) ;
static int eval_fcurve( SceGmoChunk *chunk, float frame, float *output ) ;
static float find_root( float f0, float f1, float f2, float f3, float frame ) ;
static quat *quat_slerp( quat *dst, const quat *src1, const quat *src2, float rate ) ;
enum {
 NOREPEAT = 0x0001,
} ;
void sceGmoBoneControl( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoMaterialControl( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoMotionAnimate( SceGmoMotion *motion, SceGmoModel *model, float step ) ;
float fmodf( float x, float y ) ;
static float extrap_frame( float frame, float start, float end, int extrap ) ;
quat *sceGmoQuatSlerp( quat *dst, const quat *src1, const quat *src2, float rate ) ;
