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
 SCEGIM_PICTURE_HAS_IMAGE_LEVELS = 0x0001,
 SCEGIM_PICTURE_HAS_IMAGE_FRAMES = 0x0002,
 SCEGIM_PICTURE_HAS_PALETTE_LEVELS = 0x0004,
 SCEGIM_PICTURE_HAS_PALETTE_FRAMES = 0x0008,
 SCEGIM_PICTURE_HAS_ANIMATION = 0x0010,
 SCEGIM_PICTURE_HAS_CROPPING = 0x0020,
 SCEGIM_PICTURE_HAS_NONPOW2 = 0x0040,
} ;
struct SceGimPicture {
 int m_reference ;
 int m_flags ;
 int m_enable_bits ;
 void *m_unk0C ;
 SceGimImageHeader *m_image ;
 SceGimPaletteHeader *m_palette ;
 int m_buf_width ;
 int m_clut_load ;
 float m_image_crop[ 4 ] ;
 float m_frame_loop[ 2 ] ;
 float m_frame_rate ;
 float m_frame ;
 float m_dissolve ;
 int m_image_frame ;
 int m_image_frame2 ;
 int m_palette_frame ;
 int m_palette_frame2 ;
 SceGimSequenceHeader **m_sequences ;
 int m_n_sequences ;
 int m_current_sequence ;
 int m_image_plane ;
 int m_palette_offset[ 3 ] ;
 int m_blend[ 1 ] ;
 int m_func[ 2 ] ;
 int m_filter[ 2 ] ;
 int m_wrap[ 2 ] ;
} ;
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
extern int sceGimPictureCountChunk( SceGimChunk *chunk, int type ) ;
extern SceGimChunk *sceGimPictureFindChunk( SceGimChunk *chunk, int type, int idx ) ;
typedef struct {
 short type ;
 int size ;
 short res1 ;
 short res2 ;
 int bits ;
 int size2 ;
 int width ;
 int height ;
 short plane_count ;
 short bit_count ;
 int compress ;
 int image_size ;
 int xppm ;
 int yppm ;
 int used_cols ;
 int important ;
} BmpHeader ;
static void *read_header( void *src, BmpHeader *header ) ;
static void *read_short( void *src, short *val ) ;
static void *read_int( void *src, int *val ) ;
static void copy_idx4( void *dst, void *src, int width, int height ) ;
static void copy_idx8( void *dst, void *src, int width, int height ) ;
static void copy_5551( void *dst, void *src, int width, int height ) ;
static void copy_5650( void *dst, void *src, int width, int height ) ;
static void copy_8880( void *dst, void *src, int width, int height ) ;
static void copy_8888( void *dst, void *src, int width, int height, int alpha ) ;
static void copy_rle4( void *dst, void *src, int width, int height ) ;
static void copy_rle8( void *dst, void *src, int width, int height ) ;
