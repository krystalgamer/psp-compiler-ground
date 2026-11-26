/* SDK libgum (libgum.o, 1.9.2.internal -O4 (= -O3) -mext): the SDK 6.6.0 src/gum/libgum.c
   (USE_VFPU 0) without sceGumMultQuaternion, which this SDK does not have,
   preprocessed with the SDK headers; its variables stay in the
   module's .bss (declared extern instead of static). */
/* cflags: -O3 -std=iso9899:1999 */
typedef unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef long _off_t;
__extension__ typedef long long _off64_t;
typedef int _ssize_t;
typedef unsigned int wint_t;
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;
typedef int _flock_t;
typedef void *_iconv_t;
typedef unsigned long __ULong;
struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};
struct __tm
{
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
struct _on_exit_args {
 void * _fnargs[32];
 __ULong _fntypes;
};
struct _atexit {
 struct _atexit *_next;
 int _ind;
 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
struct __sbuf {
 unsigned char *_base;
 int _size;
};
typedef long _fpos_t;
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;
  void * _cookie;
  int (*_read) (void * _cookie, char *_buf, int _n);
  int (*_write) (void * _cookie, const char *_buf, int _n);
  _fpos_t (*_seek) (void * _cookie, _fpos_t _offset, int _whence);
  int (*_close) (void * _cookie);
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
struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;
};
struct _reent
{
  int _errno;
  __FILE *_stdin, *_stdout, *_stderr;
  int _inc;
  char _emergency[25];
  int _current_category;
  const char *_current_locale;
  int __sdidinit;
  void (*__cleanup) (struct _reent *);
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;
  int _cvtlen;
  char *_cvtbuf;
  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
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
        } _reent;
      struct
        {
          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;
  struct _atexit *_atexit;
  struct _atexit _atexit0;
  void (**(_sig_func))(int);
  struct _glue __sglue;
  __FILE __sf[3];
};
extern struct _reent *_impure_ptr ;
void _reclaim_reent (struct _reent *);
typedef short int __int16_t;
typedef unsigned short int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
__extension__ typedef long long __int64_t;
__extension__ typedef unsigned long long __uint64_t;
typedef int ptrdiff_t;
typedef int wchar_t;
typedef long int __off_t;
typedef int __pid_t;
__extension__ typedef long long int __loff_t;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long clock_t;
typedef long time_t;
struct timespec {
  time_t tv_sec;
  long tv_nsec;
};
struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};
typedef long daddr_t;
typedef char * caddr_t;
typedef unsigned short ino_t;
typedef short dev_t;
typedef long off_t;
typedef unsigned short uid_t;
typedef unsigned short gid_t;
typedef int pid_t;
typedef long key_t;
typedef _ssize_t ssize_t;
typedef unsigned int mode_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned short nlink_t;
typedef long fd_mask;
typedef struct _types_fd_set {
 fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;

typedef __FILE FILE;
typedef _fpos_t fpos_t;
FILE * tmpfile (void);
char * tmpnam (char *);
int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *, const char *, FILE *);
void setbuf (FILE *, char *);
int setvbuf (FILE *, char *, int, size_t);
int fprintf (FILE *, const char *, ...);
int fscanf (FILE *, const char *, ...);
int printf (const char *, ...);
int scanf (const char *, ...);
int sscanf (const char *, const char *, ...);
int vfprintf (FILE *, const char *, __gnuc_va_list);
int vprintf (const char *, __gnuc_va_list);
int vsprintf (char *, const char *, __gnuc_va_list);
int fgetc (FILE *);
char * fgets (char *, int, FILE *);
int fputc (int, FILE *);
int fputs (const char *, FILE *);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void *, size_t _size, size_t _n, FILE *);
size_t fwrite (const void * , size_t _size, size_t _n, FILE *);
int fgetpos (FILE *, fpos_t *);
int fseek (FILE *, long, int);
int fsetpos (FILE *, const fpos_t *);
long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);
FILE * fopen (const char *_name, const char *_type);
int sprintf (char *, const char *, ...);
int remove (const char *);
int rename (const char *, const char *);
int asprintf (char **, const char *, ...);
int fseeko (FILE *, off_t, int);
off_t ftello ( FILE *);
int vfiprintf (FILE *, const char *, __gnuc_va_list);
int iprintf (const char *, ...);
int fiprintf (FILE *, const char *, ...);
int siprintf (char *, const char *, ...);
char * tempnam (const char *, const char *);
int vasprintf (char **, const char *, __gnuc_va_list);
int vsnprintf (char *, size_t, const char *, __gnuc_va_list);
int vfscanf (FILE *, const char *, __gnuc_va_list);
int vscanf (const char *, __gnuc_va_list);
int vsscanf (const char *, const char *, __gnuc_va_list);
int fcloseall (void);
int snprintf (char *, size_t, const char *, ...);
FILE * fdopen (int, const char *);
int fileno (FILE *);
int getw (FILE *);
int pclose (FILE *);
FILE * popen (const char *, const char *);
int putw (int, FILE *);
void setbuffer (FILE *, char *, int);
int setlinebuf (FILE *);
int getc_unlocked (FILE *);
int getchar_unlocked (void);
void flockfile (FILE *);
int ftrylockfile (FILE *);
void funlockfile (FILE *);
int putc_unlocked (int, FILE *);
int putchar_unlocked (int);
int _asprintf_r (struct _reent *, char **, const char *, ...);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
FILE * _fopen_r (struct _reent *, const char *, const char *);
int _fscanf_r (struct _reent *, FILE *, const char *, ...);
int _getchar_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...);
int _mkstemp_r (struct _reent *, char *);
char * _mktemp_r (struct _reent *, char *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *, ...);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *, const char *_old, const char *_new);
int _scanf_r (struct _reent *, const char *, ...);
int _sprintf_r (struct _reent *, char *, const char *, ...);
int _snprintf_r (struct _reent *, char *, size_t, const char *, ...);
int _sscanf_r (struct _reent *, const char *, const char *, ...);
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list);
int _vfprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _vprintf_r (struct _reent *, const char *, __gnuc_va_list);
int _vsprintf_r (struct _reent *, char *, const char *, __gnuc_va_list);
int _vsnprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list);
int _vfscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list);
int _vscanf_r (struct _reent *, const char *, __gnuc_va_list);
int _vsscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list);
ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
int __srget (FILE *);
int __swbuf (int, FILE *);
FILE *funopen (const void * _cookie, int (*readfn)(void * _cookie, char *_buf, int _n), int (*writefn)(void * _cookie, const char *_buf, int _n), fpos_t (*seekfn)(void * _cookie, fpos_t _off, int _whence), int (*closefn)(void * _cookie));


void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *, const void *, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *, const char *);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *, const char *);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *, const char *, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *, const char *, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);
char *strtok (char *, const char *);
size_t strxfrm (char *, const char *, size_t);
char *strtok_r (char *, const char *, char **);
int bcmp (const void *, const void *, size_t);
void bcopy (const void *, void *, size_t);
void bzero (void *, size_t);
int ffs (int);
char *index (const char *, int);
void * memccpy (void *, const void *, int, size_t);
void * mempcpy (void *, const void *, size_t);
char *rindex (const char *, int);
int strcasecmp (const char *, const char *);
char *strdup (const char *);
char *_strdup_r (struct _reent *, const char *);
char *strndup (const char *, size_t);
char *_strndup_r (struct _reent *, const char *, size_t);
char *strerror_r (int, char *, size_t);
size_t strlcat (char *, const char *, size_t);
size_t strlcpy (char *, const char *, size_t);
int strncasecmp (const char *, const char *, size_t);
size_t strnlen (const char *, size_t);
char *strsep (char **, const char *);
char *strlwr (char *);
char *strupr (char *);

typedef char char8;
typedef unsigned char u_char8;
typedef short short16;
typedef unsigned short u_short16;
typedef short int16;
typedef unsigned short u_int16;
typedef int int32;
typedef unsigned int u_int32;
typedef int int64 __attribute__((mode(DI)));
typedef unsigned int u_int64 __attribute__((mode(DI)));
typedef int long64 __attribute__((mode(DI)));
typedef unsigned int u_long64 __attribute__((mode(DI)));
typedef char SceChar8;
typedef unsigned char SceUChar8;
typedef short SceShort16;
typedef unsigned short SceUShort16;
typedef int SceInt32;
typedef unsigned int SceUInt32;
typedef int SceInt64 __attribute__((mode(DI)));
typedef unsigned int SceUInt64 __attribute__((mode(DI)));
typedef int SceLong64 __attribute__((mode(DI)));
typedef unsigned int SceULong64 __attribute__((mode(DI)));
typedef float SceFloat;
typedef float SceFloat32;
typedef signed char SceSByte;
typedef signed char SceSByte8;
typedef unsigned char SceByte;
typedef unsigned char SceByte8;
typedef unsigned short SceWChar16;
typedef unsigned int SceWChar32;
typedef int SceBool;
typedef int SceIntPtr;
typedef unsigned int SceUIntPtr;
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
} __attribute__((aligned(16))) ScePspIVector4;
typedef struct ScePspIVector4Unaligned {
 int x, y, z, w;
} ScePspIVector4Unaligned;
typedef struct ScePspL64Vector4 {
 SceLong64 x, y, z, w;
} ScePspL64Vector4;
typedef struct ScePspFVector4 {
 float x, y, z, w;
} __attribute__((aligned(16))) ScePspFVector4;
typedef struct ScePspFVector4Unaligned {
 float x, y, z, w;
} ScePspFVector4Unaligned;
typedef union ScePspVector4 {
 ScePspFVector4 fv;
 ScePspIVector4 iv;
 float f[4];
 int i[4];
} __attribute__((aligned(16))) ScePspVector4;
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
 float f[3][3];
 int i[3][3];
} ScePspMatrix3;
typedef struct ScePspIMatrix4 {
 ScePspIVector4 x, y, z, w;
} __attribute__((aligned(16))) ScePspIMatrix4;
typedef struct ScePspIMatrix4Unaligned {
 ScePspIVector4Unaligned x, y, z, w;
} ScePspIMatrix4Unaligned;
typedef struct ScePspFMatrix4 {
 ScePspFVector4 x, y, z, w;
} __attribute__((aligned(16))) ScePspFMatrix4;
typedef struct ScePspFMatrix4Unaligned {
 ScePspFVector4Unaligned x, y, z, w;
} ScePspFMatrix4Unaligned;
typedef union ScePspMatrix4 {
 ScePspFMatrix4 fm;
 ScePspIMatrix4 im;
 ScePspFVector4 fv[4];
 ScePspIVector4 iv[4];
 ScePspVector4 v[4];
 float f[4][4];
 int i[4][4];
} __attribute__((aligned(16))) ScePspMatrix4;
typedef struct ScePspFQuaternion {
 float x, y, z, w;
} __attribute__((aligned(16))) ScePspFQuaternion;
typedef struct ScePspFQuaternionUnaligned {
 float x, y, z, w;
} ScePspFQuaternionUnaligned;
typedef struct ScePspFPlane {
 float a, b, c, d;
} __attribute__((aligned(16))) ScePspFPlane;
typedef struct ScePspFPlaneUnaligned {
 float a, b, c, d;
} ScePspFPlaneUnaligned;
typedef struct ScePspFColor {
 float r, g, b, a;
} __attribute__((aligned(16))) ScePspFColor;
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
 void *p;
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
 ScePspFPlane fp;
 ScePspFColor fc;
 ScePspRGBA8888 rgba8888[4];
 ScePspRGBA4444 rgba4444[8];
 ScePspRGBA5551 rgba5551[8];
 ScePspRGB565 rgb565[8];
} __attribute__((aligned(16))) ScePspUnion128;
typedef union ScePspUnion512 {
 ScePspUnion32 un32[16];
 ScePspUnion64 un64[8];
 ScePspUnion128 un128[4];
 SceULong64 ul[8];
 SceLong64 l[8];
 unsigned int ui[16];
 int i[16];
 unsigned short us[32];
 short s[32];
 unsigned char uc[64];
 char c[64];
 float f[16];
 ScePspFRect fr[4];
 ScePspIRect ir[4];
 ScePspFVector4 fv[4];
 ScePspIVector4 iv[4];
 ScePspFQuaternion fq[4];
 ScePspFPlane fp[4];
 ScePspFColor fc[4];
 ScePspRGBA8888 rgba8888[16];
 ScePspRGBA4444 rgba4444[32];
 ScePspRGBA5551 rgba5551[32];
 ScePspRGB565 rgb565[32];
 ScePspFMatrix4 fm;
 ScePspIMatrix4 im;
} __attribute__((aligned(16))) ScePspUnion512;
typedef struct ScePspDateTime {
 unsigned short year;
 unsigned short month;
 unsigned short day;
 unsigned short hour;
 unsigned short minute;
 unsigned short second;
 unsigned int microsecond;
} ScePspDateTime;
static __inline__ unsigned int sceGeExtractFloat24(float _float32);
static __inline__ unsigned int sceGeExtractFloat24(float _float32)
{
 ScePspUnion32 u;
 u.f = _float32;
 return (u.ui>>8);
}
unsigned int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
int sceGeEdramSetAddrTranslation(int width);
unsigned int sceGeGetCmd(int cmdno);
int sceGeGetMtx(int mtxno, unsigned int *puiMtx);
typedef struct SceGeContext {
 unsigned int buffer[512];
} SceGeContext;
int sceGeSaveContext(SceGeContext *pCtx);
int sceGeRestoreContext(const SceGeContext *pCtx);
typedef struct SceGeStack {
 unsigned int buffer[8];
} SceGeStack;
typedef struct SceGeListOptParam {
 unsigned int size;
 SceGeContext *pGeContext;
 int nStackDepth;
 SceGeStack *pStackBuf;
} SceGeListOptParam;
int sceGeListEnQueue(const void *pMadr, const void *pSadr, int cbid,
 const SceGeListOptParam *pOpt);
int sceGeListEnQueueHead(const void *pMadr, const void *pSadr, int cbid,
 const SceGeListOptParam *pOpt);
int sceGeListDeQueue(int id);
int sceGeListUpdateStallAddr(int id, const void *pSadr);
int sceGeListSync(int id, int mode);
int sceGeDrawSync(int mode);
typedef struct SceGeBreakParam {
 unsigned int buf[4];
} SceGeBreakParam;
int sceGeBreak(int mode, SceGeBreakParam *pParam);
int sceGeContinue(void);
typedef struct SceGeCbParam {
 void (*pSignalFunc)(int intrcode, void *cookie, const void *madr);
 void *pSignalCookie;
 void (*pFinishFunc)(int intrcode, void *cookie, const void *madr);
 void *pFinishCookie;
} SceGeCbParam;
int sceGeSetCallback(const SceGeCbParam *pParam);
int sceGeUnsetCallback(int id);
typedef SceGeContext SceGuContext;
int sceGuInit( void );
int sceGuTerm( void );
int sceGuStart( int mode, void *p, int size );
int sceGuFinish( void );
int sceGuFinishId( unsigned short id );
void *sceGuGetMemory( int size );
void *sceGuGetAlignedMemory(unsigned int uiAlign, unsigned int uiSize);
int sceGuCheckList( void );
void *sceGuBeginPacket(unsigned int *puiSize);
void sceGuEndPacket(void *pEnd);
int sceGuFlush(void);
void sceGuSignal( int mode, unsigned short id );
int sceGuSignalSync( unsigned short id );
void *sceGuSetCallback( int id, void (*cb)(int) );
void *sceGuSetCallback2( int id, void (*cb)(int, const void *) );
int sceGuBreak( int mode );
int sceGuContinue( void );
void sceGuCallMode( int mode );
int sceGuCallList( const void *p );
void *sceGuJumpList( const void *p );
int sceGuSendList( int mode, const void *p, SceGuContext *ctx, int nStackDepth, SceGeStack *stack );
int sceGuSignalCall(const void *p);
void sceGuSignalRet(void);
void sceGuSignalDrawSync(void);
int sceGuSync( int mode, int block );
int sceGuDisplay( int sw );
void sceGuDispBuffer( int width, int height, void *dbp, int dbw );
void sceGuDispBuffer2( int fpf, int width, int height, void *dbp, int dbw );
void sceGuDrawBuffer( int fpf, void *fbp, int fbw );
void sceGuDrawBuffer2( int fpf, void *fbp, int fbw );
void sceGuDrawBufferList( int fpf, void *fbp, int fbw );
void *sceGuSwapBuffers( void );
void sceGuDepthBuffer( void *zbp, int zbw );
void sceGuSetDither( const ScePspIMatrix4 *d );
void sceGuEnable( int cap );
void sceGuDisable( int cap );
void sceGuSetStatus( int cap, int flag );
int sceGuGetStatus( int cap );
unsigned int sceGuGetAllStatus( void );
void sceGuSetAllStatus( unsigned int status );
void sceGuBeginObject( int type, int count, const void *idx, const void *p );
int sceGuEndObject( void );
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
void sceGuCopyImage2( int mode, int sx, int sy, int width, int height,
     int sbw, void *sbp, int dx, int dy, int dbw, void *dbp,
     int sbh, int dbh, int sbm, int dbm );
void sceGuViewport( int x, int y, int width, int height );
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
void sceGuClutCopyLoad( int np, const void *cbp );
void sceGuFog( float zs, float ze, unsigned int col );
void sceGuColorFunc( int func, unsigned int cref, unsigned int cmsk );
void sceGuAlphaFunc( int func, unsigned int aref, unsigned int amsk );
void sceGuDepthFunc( int func );
void sceGuDepthMask( int flag );
void sceGuScissor( int x, int y, int width, int height );
void sceGuStencilFunc( int func, unsigned int sref, unsigned int smsk );
void sceGuStencilOp( int sfail, int zfail, int zpass );
void sceGuBlendFunc( int equ, int asel, int bsel, unsigned int afix, unsigned int bfix );
void sceGuLogicalOp( int lop );
void sceGuPixelMask( unsigned int pmsk );
void sceGuBoneMatrix( int n, const ScePspFMatrix4 *m );
void sceGuMorphWeight( int n, float f );
void sceGuSetMatrix( int mode, const ScePspFMatrix4 *f );
void sceGuDebugPrint( int x, int y, unsigned int col, const char *str );
void sceGuDebugFlush( void );
typedef struct {
 int buffer[32];
} SceGumContext;
void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex);
void sceGumSetCurMatrix(void);
void sceGumUpdateMatrix(void);
void sceGumLoadContext(SceGumContext *ctx);
void sceGumStoreContext(SceGumContext *ctx);
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
void sceGumOrtho(float left, float right, float bottom, float top, float r_near, float r_far);
void sceGumFrustum(float left, float right, float bottom, float top, float r_near, float r_far);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumMultQuaternion(const ScePspFQuaternion *q);
ScePspFVector4 *sceGumProject(ScePspFVector4 *xyzq, const ScePspFVector3 *pos);
void sceGumMatrixMode(int mode);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumLoadMatrix(const ScePspFMatrix4 *m);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumDrawArray(int prim, int type, int count, const void *idx,
     const void *p);
void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims,
     const void *idx, const void *p);
void sceGumDrawBezier(int type, int ucount, int vcount, const void *idx,
     const void *p);
void sceGumDrawSpline(int type, int ucount, int vcount, int uflag, int vflag,
     const void *idx, const void *p);

union __dmath
{
  __ULong i[2];
  double d;
};
extern const union __dmath __infinity[];
extern double atan (double);
extern double cos (double);
extern double sin (double);
extern double tan (double);
extern double tanh (double);
extern double frexp (double, int *);
extern double modf (double, double *);
extern double ceil (double);
extern double fabs (double);
extern double floor (double);
extern double acos (double);
extern double asin (double);
extern double atan2 (double, double);
extern double cosh (double);
extern double sinh (double);
extern double exp (double);
extern double ldexp (double, int);
extern double log (double);
extern double log10 (double);
extern double pow (double, double);
extern double sqrt (double);
extern double fmod (double, double);
typedef float float_t;
typedef double double_t;
extern int __fpclassifyf (float x);
extern int __fpclassifyd (double x);
extern int __signbitf (float x);
extern int __signbitd (double x);
extern double infinity (void);
extern double nan (const char *);
extern int isnan (double);
extern int isinf (double);
extern int finite (double);
extern double copysign (double, double);
extern int ilogb (double);
extern double asinh (double);
extern double cbrt (double);
extern double nextafter (double, double);
extern double rint (double);
extern double scalbn (double, int);
extern double exp2 (double);
extern double scalbln (double, long int);
extern double tgamma (double);
extern double nearbyint (double);
extern long int lrint (double);
extern double round (double);
extern long int lround (double);
extern double trunc (double);
extern double remquo (double, double, int *);
extern double copysign (double, double);
extern double fdim (double, double);
extern double fmax (double, double);
extern double fmin (double, double);
extern double fma (double, double, double);
extern void sincos (double, double *, double *);
extern double log1p (double);
extern double expm1 (double);
extern double acosh (double);
extern double atanh (double);
extern double remainder (double, double);
extern double gamma (double);
extern double gamma_r (double, int *);
extern double lgamma (double);
extern double lgamma_r (double, int *);
extern double erf (double);
extern double erfc (double);
extern double y0 (double);
extern double y1 (double);
extern double yn (int, double);
extern double j0 (double);
extern double j1 (double);
extern double jn (int, double);
extern double hypot (double, double);
extern double cabs();
extern double drem (double, double);
extern float atanf (float);
extern float cosf (float);
extern float sinf (float);
extern float tanf (float);
extern float tanhf (float);
extern float frexpf (float, int *);
extern float modff (float, float *);
extern float ceilf (float);
extern float fabsf (float);
extern float floorf (float);
extern float acosf (float);
extern float asinf (float);
extern float atan2f (float, float);
extern float coshf (float);
extern float sinhf (float);
extern float expf (float);
extern float ldexpf (float, int);
extern float logf (float);
extern float log10f (float);
extern float powf (float, float);
extern float sqrtf (float);
extern float fmodf (float, float);
extern float exp2f (float);
extern float scalblnf (float, long int);
extern float tgammaf (float);
extern float nearbyintf (float);
extern long int lrintf (float);
extern float roundf (float);
extern long int lroundf (float);
extern float truncf (float);
extern float remquof (float, float, int *);
extern float copysignf (float, float);
extern float fdimf (float, float);
extern float fmaxf (float, float);
extern float fminf (float, float);
extern float fmaf (float, float, float);
extern float infinityf (void);
extern float nanf (const char *);
extern int isnanf (float);
extern int isinff (float);
extern int finitef (float);
extern float copysignf (float, float);
extern int ilogbf (float);
extern float asinhf (float);
extern float cbrtf (float);
extern float nextafterf (float, float);
extern float rintf (float);
extern float scalbnf (float, int);
extern float log1pf (float);
extern float expm1f (float);
extern void sincosf (float, float *, float *);
extern float acoshf (float);
extern float atanhf (float);
extern float remainderf (float, float);
extern float gammaf (float);
extern float gammaf_r (float, int *);
extern float lgammaf (float);
extern float lgammaf_r (float, int *);
extern float erff (float);
extern float erfcf (float);
extern float y0f (float);
extern float y1f (float);
extern float ynf (int, float);
extern float j0f (float);
extern float j1f (float);
extern float jnf (int, float);
extern float hypotf (float, float);
extern float cabsf();
extern float dremf (float, float);
extern int *__signgam (void);
struct exception
{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};
extern int matherr (struct exception *e);
enum __fdlibm_version
{
  __fdlibm_ieee = -1,
  __fdlibm_svid,
  __fdlibm_xopen,
  __fdlibm_posix
};
extern const enum __fdlibm_version __fdlib_version;

typedef struct {
 ScePspFMatrix4 *top;
 ScePspFMatrix4 *bottom;
 ScePspFMatrix4 *cur;
} MATRIX_STACK;
typedef struct {
 int cur_matrix;
 ScePspFMatrix4 *cur_stack;
 MATRIX_STACK mat_stack[4];
 int update[4];
 int padding[14];
} _SceGumContext;
static void _sceGumSetMatrix(int n);
static void _sceGumCheckUpdate(void);
static ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2);
static ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1);
static const unsigned char __psp_libinfo__[24] __attribute__((used)) = { 0x5C, 0x79, 0x72, 0x3D, 0x60, 0x63, 0x60, 0x30, 0x7E, 0x7B, 0x74, 0x79, 0x87, 0x7F, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x46, 0x4B, 0x45, 0x44 };
extern int cur_matrix;
extern ScePspFMatrix4 *cur_stack;
extern MATRIX_STACK mat_stack[4];
extern int update[4];
static void _sceGumSetMatrix(int n)
{
 mat_stack[cur_matrix].cur = cur_stack;
 if (mat_stack[n].cur!=((void *)0)) {
  sceGuSetMatrix(n, mat_stack[n].cur);
 }
 return;
}
static void _sceGumCheckUpdate(void)
{
 int i;
 for (i = 0; i < 4; i++) {
  if (update[i]) {
   _sceGumSetMatrix(i);
   update[i] = 0;
  }
 }
 return;
}
static ScePspFMatrix4 *_sceGumMulMatrix(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1, const ScePspFMatrix4 *m2)
{
 ScePspFMatrix4 tm;
 tm.x.x = m1->x.x*m2->x.x + m1->y.x*m2->x.y + m1->z.x*m2->x.z + m1->w.x*m2->x.w;
 tm.x.y = m1->x.y*m2->x.x + m1->y.y*m2->x.y + m1->z.y*m2->x.z + m1->w.y*m2->x.w;
 tm.x.z = m1->x.z*m2->x.x + m1->y.z*m2->x.y + m1->z.z*m2->x.z + m1->w.z*m2->x.w;
 tm.x.w = m1->x.w*m2->x.x + m1->y.w*m2->x.y + m1->z.w*m2->x.z + m1->w.w*m2->x.w;
 tm.y.x = m1->x.x*m2->y.x + m1->y.x*m2->y.y + m1->z.x*m2->y.z + m1->w.x*m2->y.w;
 tm.y.y = m1->x.y*m2->y.x + m1->y.y*m2->y.y + m1->z.y*m2->y.z + m1->w.y*m2->y.w;
 tm.y.z = m1->x.z*m2->y.x + m1->y.z*m2->y.y + m1->z.z*m2->y.z + m1->w.z*m2->y.w;
 tm.y.w = m1->x.w*m2->y.x + m1->y.w*m2->y.y + m1->z.w*m2->y.z + m1->w.w*m2->y.w;
 tm.z.x = m1->x.x*m2->z.x + m1->y.x*m2->z.y + m1->z.x*m2->z.z + m1->w.x*m2->z.w;
 tm.z.y = m1->x.y*m2->z.x + m1->y.y*m2->z.y + m1->z.y*m2->z.z + m1->w.y*m2->z.w;
 tm.z.z = m1->x.z*m2->z.x + m1->y.z*m2->z.y + m1->z.z*m2->z.z + m1->w.z*m2->z.w;
 tm.z.w = m1->x.w*m2->z.x + m1->y.w*m2->z.y + m1->z.w*m2->z.z + m1->w.w*m2->z.w;
 tm.w.x = m1->x.x*m2->w.x + m1->y.x*m2->w.y + m1->z.x*m2->w.z + m1->w.x*m2->w.w;
 tm.w.y = m1->x.y*m2->w.x + m1->y.y*m2->w.y + m1->z.y*m2->w.z + m1->w.y*m2->w.w;
 tm.w.z = m1->x.z*m2->w.x + m1->y.z*m2->w.y + m1->z.z*m2->w.z + m1->w.z*m2->w.w;
 tm.w.w = m1->x.w*m2->w.x + m1->y.w*m2->w.y + m1->z.w*m2->w.z + m1->w.w*m2->w.w;
 memcpy(m0, &tm, sizeof(ScePspFMatrix4));
 return (m0);
}
static ScePspFVector4 *_sceGumHomogeneousTransform(ScePspFVector4 *v0, const ScePspFMatrix4 *m, const ScePspFVector3 *v1)
{
 ScePspFVector4 tv;
 tv.x = m->x.x*v1->x + m->y.x*v1->y + m->z.x*v1->z + m->w.x;
 tv.y = m->x.y*v1->x + m->y.y*v1->y + m->z.y*v1->z + m->w.y;
 tv.z = m->x.z*v1->x + m->y.z*v1->y + m->z.z*v1->z + m->w.z;
 tv.w = m->x.w*v1->x + m->y.w*v1->y + m->z.w*v1->z + m->w.w;
 memcpy(v0, &tv, sizeof(ScePspFVector4));
 return (v0);
}
void sceGumSetMatrixStack(ScePspFMatrix4 *m, int proj, int view, int world, int tex)
{
 cur_stack = ((void *)0);
 if (tex) {
  mat_stack[3].top = &m[(proj+view+world)];
  mat_stack[3].cur = &m[(proj+view+world)];
  mat_stack[3].bottom = &m[(proj+view+world+tex)];
  cur_stack = mat_stack[3].cur;
  cur_matrix = 3;
  sceGumLoadIdentity();
  update[3] = 1;
 } else {
  mat_stack[3].top = ((void *)0);
  mat_stack[3].cur = ((void *)0);
  mat_stack[3].bottom = ((void *)0);
  update[3] = 0;
 }
 if (world) {
  mat_stack[2].top = &m[(proj+view)];
  mat_stack[2].cur = &m[(proj+view)];
  mat_stack[2].bottom = &m[(proj+view+world)];
  cur_stack = mat_stack[2].cur;
  cur_matrix = 2;
  sceGumLoadIdentity();
  update[2] = 1;
 } else {
  mat_stack[2].top = ((void *)0);
  mat_stack[2].cur = ((void *)0);
  mat_stack[2].bottom = ((void *)0);
  update[2] = 0;
 }
 if (view) {
  mat_stack[1].top = &m[proj];
  mat_stack[1].cur = &m[proj];
  mat_stack[1].bottom = &m[(proj+view)];
  cur_stack = mat_stack[1].cur;
  cur_matrix = 1;
  sceGumLoadIdentity();
  update[1] = 1;
 } else {
  mat_stack[1].top = ((void *)0);
  mat_stack[1].cur = ((void *)0);
  mat_stack[1].bottom = ((void *)0);
  update[1] = 0;
 }
 if (proj) {
  mat_stack[0].top = &m[0];
  mat_stack[0].cur = &m[0];
  mat_stack[0].bottom = &m[proj];
  cur_stack = mat_stack[0].cur;
  cur_matrix = 0;
  sceGumLoadIdentity();
  update[0] = 1;
 } else {
  mat_stack[0].top = ((void *)0);
  mat_stack[0].cur = ((void *)0);
  mat_stack[0].bottom = ((void *)0);
  update[0] = 1;
 }
 cur_matrix = 0;
 return;
}
void sceGumSetCurMatrix(void)
{
 _sceGumSetMatrix(cur_matrix);
 return;
}
void sceGumUpdateMatrix(void)
{
 _sceGumCheckUpdate();
 return;
}
void sceGumStoreContext(SceGumContext *ctx)
{
 int i;
 _SceGumContext *cp = (_SceGumContext *)ctx;
 cp->cur_matrix = cur_matrix;
 cp->cur_stack = cur_stack;
 for (i = 0; i < 4; i++) {
  cp->mat_stack[i].top = mat_stack[i].top;
  cp->mat_stack[i].bottom = mat_stack[i].bottom;
  cp->mat_stack[i].cur = mat_stack[i].cur;
  cp->update[i] = update[i];
 }
 return;
}
void sceGumLoadContext(SceGumContext *ctx)
{
 int i;
 const _SceGumContext *cp = (const _SceGumContext *)ctx;
 cur_matrix = cp->cur_matrix;
 cur_stack = cp->cur_stack;
 for (i = 0; i < 4; i++) {
  mat_stack[i].top = cp->mat_stack[i].top;
  mat_stack[i].bottom = cp->mat_stack[i].bottom;
  mat_stack[i].cur = cp->mat_stack[i].cur;
  update[i] = cp->update[i];
 }
 return;
}
void sceGumLoadIdentity(void)
{
 int i;
 for (i=0; i<16; i++) {
  ((float *)cur_stack)[i]=0.0f;
 }
 cur_stack->x.x = 1.0f;
 cur_stack->y.y = 1.0f;
 cur_stack->z.z = 1.0f;
 cur_stack->w.w = 1.0f;
 update[cur_matrix] = 1;
}
void sceGumRotateX(float angle)
{
 ScePspFMatrix4 m;
 float s, c;
 s = (float)sinf(angle);
 c = (float)cosf(angle);
 m.x.x = 1.0f;
 m.x.y = 0.0f;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = c;
 m.y.z = s;
 m.y.w = 0.0f;
 m.z.x = 0.0f;
 m.z.y = -1.0f * s;
 m.z.z = c;
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}
void sceGumRotateY(float angle)
{
 ScePspFMatrix4 m;
 float s, c;
 s = (float)sinf(angle);
 c = (float)cosf(angle);
 m.x.x = c;
 m.x.y = 0.0f;
 m.x.z = -1.0f * s;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = 1.0f;
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = s;
 m.z.y = 0.0f;
 m.z.z = c;
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}
void sceGumRotateZ(float angle)
{
 ScePspFMatrix4 m;
 float s, c;
 s = (float)sinf(angle);
 c = (float)cosf(angle);
 m.x.x = c;
 m.x.y = s;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = -1.0f*s;
 m.y.y = c;
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = 0.0f;
 m.z.y = 0.0f;
 m.z.z = 1.0f;
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}
void sceGumRotateXYZ(const ScePspFVector3 *vec)
{
 ScePspFMatrix4 m;
 float s[3], c[3];
 s[0] = (float)sinf(vec->x);
 c[0] = (float)cosf(vec->x);
 s[1] = (float)sinf(vec->y);
 c[1] = (float)cosf(vec->y);
 s[2] = (float)sinf(vec->z);
 c[2] = (float)cosf(vec->z);
 m.x.x = c[2] * c[1];
 m.x.y = (c[2] * s[1] * s[0]) + (s[2] * c[0]);
 m.x.z = (-1.0f * c[2] * s[1] * c[0]) + (s[2] * s[0]);
 m.x.w = 0.0f;
 m.y.x = -1.0f * s[2] * c[1];
 m.y.y = (-1.0f * s[2] * s[1] * s[0]) + (c[2] * c[0]);
 m.y.z = (s[2] * s[1] * c[0]) + (c[2] * s[0]);
 m.y.w = 0.0f;
 m.z.x = s[1];
 m.z.y = -1.0f * c[1] * s[0];
 m.z.z = c[1] * c[0];
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}
void sceGumRotateZYX(const ScePspFVector3 *vec)
{
 ScePspFMatrix4 m;
 float s[3], c[3];
 s[0] = (float)sinf(vec->x);
 c[0] = (float)cosf(vec->x);
 s[1] = (float)sinf(vec->y);
 c[1] = (float)cosf(vec->y);
 s[2] = (float)sinf(vec->z);
 c[2] = (float)cosf(vec->z);
 m.x.x = c[1] * c[2];
 m.x.y = c[1] * s[2];
 m.x.z = -1.0f * s[1];
 m.x.w = 0.0f;
 m.y.x = (-1.0f * c[0] * s[2]) + (s[0] * s[1] * c[2]);
 m.y.y = (c[0] * c[2]) + (s[0] * s[1] * s[2]);
 m.y.z = s[0] * c[1];
 m.y.w = 0.0f;
 m.z.x = (s[0] * s[2]) + (c[0] * s[1] * c[2]);
 m.z.y = (-1.0f * s[0] * c[2]) + (c[0] * s[1] * s[2]);
 m.z.z = c[0] * c[1];
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 _sceGumMulMatrix(cur_stack, cur_stack, &m);
 update[cur_matrix] = 1;
 return;
}
void sceGumTranslate(const ScePspFVector3 *vec)
{
 ScePspFVector4 v;
 v.x = cur_stack->x.x * vec->x + cur_stack->y.x * vec->y + cur_stack->z.x * vec->z;
 v.y = cur_stack->x.y * vec->x + cur_stack->y.y * vec->y + cur_stack->z.y * vec->z;
 v.z = cur_stack->x.z * vec->x + cur_stack->y.z * vec->y + cur_stack->z.z * vec->z;
 v.w = cur_stack->x.w * vec->x + cur_stack->y.w * vec->y + cur_stack->z.w * vec->z;
 cur_stack->w.x = cur_stack->w.x + v.x;
 cur_stack->w.y = cur_stack->w.y + v.y;
 cur_stack->w.z = cur_stack->w.z + v.z;
 cur_stack->w.w = cur_stack->w.w + v.w;
 update[cur_matrix] = 1;
 return;
}
void sceGumScale(const ScePspFVector3 *vec)
{
 cur_stack->x.x = cur_stack->x.x * vec->x;
 cur_stack->x.y = cur_stack->x.y * vec->x;
 cur_stack->x.z = cur_stack->x.z * vec->x;
 cur_stack->y.x = cur_stack->y.x * vec->y;
 cur_stack->y.y = cur_stack->y.y * vec->y;
 cur_stack->y.z = cur_stack->y.z * vec->y;
 cur_stack->z.x = cur_stack->z.x * vec->z;
 cur_stack->z.y = cur_stack->z.y * vec->z;
 cur_stack->z.z = cur_stack->z.z * vec->z;
 update[cur_matrix] = 1;
 return;
}
void sceGumMultMatrix(const ScePspFMatrix4 *m)
{
 _sceGumMulMatrix(cur_stack, cur_stack, m);
 update[cur_matrix] = 1;
 return;
}
void sceGumPerspective(float fovy, float aspect, float r_near, float r_far)
{
 ScePspFMatrix4 m;
 float f, asp, nf1, nf2;
 f = fovy * 0.5f;
 f = (float)cosf(f) / (float)sinf(f);
 asp = 1.0f / aspect;
 nf1 = 1.0f / (r_near - r_far);
 nf2 = r_near + r_far;
 m.x.x = f * asp;
 m.x.y = 0.0f;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = f;
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = 0.0f;
 m.z.y = 0.0f;
 m.z.z = nf1 * nf2;
 m.z.w = -1.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 2.0f * r_near * r_far * nf1;
 m.w.w = 0.0f;
 sceGumMultMatrix(&m);
 return;
}
void sceGumOrtho(float left, float right, float bottom, float top,
   float r_near, float r_far)
{
 ScePspFMatrix4 m;
 float rl1, rl2;
 float tb1, tb2;
 float fn1, fn2;
 rl1 = 1.0f / (right - left);
 rl2 = right + left;
 tb1 = 1.0f / (top - bottom);
 tb2 = top + bottom;
 fn1 = 1.0f / (r_far - r_near);
 fn2 = r_far + r_near;
 m.x.x = 2.0f * rl1;
 m.x.y = 0.0f;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = 2.0f * tb1;
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = 0.0f;
 m.z.y = 0.0f;
 m.z.z = -2.0f * fn1;
 m.z.w = 0.0f;
 m.w.x = -1.0f * rl2 * rl1;
 m.w.y = -1.0f * tb2 * tb1;
 m.w.z = -1.0f * fn2 * fn1;
 m.w.w = 1.0f;
 sceGumMultMatrix(&m);
 return;
}
void sceGumFrustum(float left, float right, float bottom, float top,
   float r_near, float r_far)
{
 ScePspFMatrix4 m;
 m.x.x = 2.0f * r_near / (right - left);
 m.x.y = 0.0f;
 m.x.z = 0.0f;
 m.x.w = 0.0f;
 m.y.x = 0.0f;
 m.y.y = 2.0f * r_near / (top - bottom);
 m.y.z = 0.0f;
 m.y.w = 0.0f;
 m.z.x = (right + left) / (right - left);
 m.z.y = (top + bottom) / (top - bottom);
 m.z.z = -(r_far + r_near) / (r_far - r_near);
 m.z.w = -1.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = -2.0f * r_far * r_near / (r_far - r_near);
 m.w.w = 0.0f;
 sceGumMultMatrix(&m);
 return;
}
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center,
     const ScePspFVector3 *up)
{
 ScePspFMatrix4 m;
 ScePspFVector3 xvec, yvec, zvec;
 ScePspFVector3 tmpvec;
 float tmpscal;
 zvec.x = eye->x - center->x;
 zvec.y = eye->y - center->y;
 zvec.z = eye->z - center->z;
 tmpvec.x = zvec.x * zvec.x;
 tmpvec.y = zvec.y * zvec.y;
 tmpvec.z = zvec.z * zvec.z;
 tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);
 if (tmpscal) {
  zvec.x = zvec.x * tmpscal;
  zvec.y = zvec.y * tmpscal;
  zvec.z = zvec.z * tmpscal;
 }
 yvec.x = up->x;
 yvec.y = up->y;
 yvec.z = up->z;
 xvec.x = yvec.y * zvec.z - yvec.z * zvec.y;
 xvec.y = yvec.z * zvec.x - yvec.x * zvec.z;
 xvec.z = yvec.x * zvec.y - yvec.y * zvec.x;
 yvec.x = zvec.y * xvec.z - zvec.z * xvec.y;
 yvec.y = zvec.z * xvec.x - zvec.x * xvec.z;
 yvec.z = zvec.x * xvec.y - zvec.y * xvec.x;
 tmpvec.x = xvec.x * xvec.x;
 tmpvec.y = xvec.y * xvec.y;
 tmpvec.z = xvec.z * xvec.z;
 tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);
 if (tmpscal) {
  xvec.x = xvec.x * tmpscal;
  xvec.y = xvec.y * tmpscal;
  xvec.z = xvec.z * tmpscal;
 }
 tmpvec.x = yvec.x * yvec.x;
 tmpvec.y = yvec.y * yvec.y;
 tmpvec.z = yvec.z * yvec.z;
 tmpscal = 1.0f / (float)sqrtf(tmpvec.x + tmpvec.y + tmpvec.z);
 if (tmpscal) {
  yvec.x = yvec.x * tmpscal;
  yvec.y = yvec.y * tmpscal;
  yvec.z = yvec.z * tmpscal;
 }
 m.x.x = xvec.x;
 m.x.y = yvec.x;
 m.x.z = zvec.x;
 m.x.w = 0.0f;
 m.y.x = xvec.y;
 m.y.y = yvec.y;
 m.y.z = zvec.y;
 m.y.w = 0.0f;
 m.z.x = xvec.z;
 m.z.y = yvec.z;
 m.z.z = zvec.z;
 m.z.w = 0.0f;
 m.w.x = 0.0f;
 m.w.y = 0.0f;
 m.w.z = 0.0f;
 m.w.w = 1.0f;
 sceGumMultMatrix(&m);
 tmpvec.x = eye->x * ( -1.0f );
 tmpvec.y = eye->y * ( -1.0f );
 tmpvec.z = eye->z * ( -1.0f );
 sceGumTranslate(&tmpvec);
 return;
}
ScePspFVector4 *sceGumProject(ScePspFVector4 *xyzq, const ScePspFVector3 *pos)
{
 ScePspFMatrix4 tm;
 ScePspFVector4 tv;
 float q;
 if (mat_stack[1].cur!=((void *)0)) {
  _sceGumMulMatrix(&tm, mat_stack[0].cur, mat_stack[1].cur);
 } else {
  memcpy(&tm, mat_stack[0].cur, sizeof(ScePspFMatrix4));
 }
 if (mat_stack[2].cur!=((void *)0)) {
  _sceGumMulMatrix(&tm, &tm, mat_stack[2].cur);
 }
 _sceGumHomogeneousTransform(&tv, &tm, pos);
 q = 1.0f / tv.w;
 xyzq->x = tv.x * q;
 xyzq->y = tv.y * q;
 xyzq->z = tv.z * q;
 xyzq->w = q;
 return (xyzq);
}
void sceGumMatrixMode(int mode)
{
 mat_stack[cur_matrix].cur = cur_stack;
 if (mat_stack[mode].cur!=((void *)0)) {
  cur_matrix = mode;
  cur_stack = mat_stack[cur_matrix].cur;
 } else {
 }
 return;
}
void sceGumPushMatrix(void)
{
 if ((cur_stack + 1)>= mat_stack[cur_matrix].bottom) {
  return;
 }
 cur_stack++;
 memcpy(cur_stack, (cur_stack-1), sizeof(ScePspFMatrix4));
 return;
}
void sceGumPopMatrix(void)
{
 if (cur_stack==mat_stack[cur_matrix].top) {
  return;
 }
 cur_stack--;
 update[cur_matrix] = 1;
 return;
}
void sceGumLoadMatrix(const ScePspFMatrix4 *m)
{
 memcpy(cur_stack, m, sizeof(ScePspFMatrix4));
 update[cur_matrix] = 1;
 return;
}
void sceGumStoreMatrix(ScePspFMatrix4 *m)
{
 memcpy(m, cur_stack, sizeof(ScePspFMatrix4));
 return;
}
void sceGumDrawArray(int prim, int type, int count, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawArray(prim, type, count, idx, p);
 return;
}
void sceGumDrawArrayN(int prim, int type, int n_verts, int n_prims, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawArrayN(prim, type, n_verts, n_prims, idx, p);
 return;
}
void sceGumDrawBezier(int type, int ucount, int vcount, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawBezier(type, ucount, vcount, idx, p);
 return;
}
void sceGumDrawSpline(int type, int ucount, int vcount, int uflag,
     int vflag, const void *idx, const void *p)
{
 _sceGumCheckUpdate();
 sceGuDrawSpline(type, ucount, vcount, uflag, vflag, idx, p);
 return;
}
