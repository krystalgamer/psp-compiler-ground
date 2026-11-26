/* SDK headers used by libgum.c (stdio.h, string.h, libgu.h, libgum.h, math.h) and its
   USE_VFPU 0 setting, preprocessed with their macros kept (cpp -dD), SDK 6.6.0 versions. */
#ifndef LIBGUM_SDK_H
#define LIBGUM_SDK_H
#define _STDIO_H_ 

#define _ANSIDECL_H_ 

#define __NEWLIB_H__ 1

#define _NEWLIB_VERSION "1.12.0"

#define _MB_LEN_MAX 1

#define __SYS_CONFIG_H__ 

#define __IEEE_LITTLE_ENDIAN 
#define _POINTER_INT long
#define __RAND_MAX 0x7fffffff
#define __IMPORT 

#define _READ_WRITE_RETURN_TYPE int

#define _HAVE_STDC 

#define _PTR void *
#define _AND ,
#define _NOARGS void
#define _CONST const
#define _VOLATILE volatile
#define _SIGNED signed
#define _DOTS , ...
#define _VOID void

#define _EXFUN(name,proto) name proto
#define _EXPARM(name,proto) (* name) proto

#define _DEFUN(name,arglist,args) name(args)
#define _DEFUN_VOID(name) name(_NOARGS)
#define _CAST_VOID (void)

#define _LONG_DOUBLE long double

#define _PARAMS(paramlist) paramlist
#define _ATTRIBUTE(attrs) __attribute__ (attrs)
#define _BEGIN_STD_C 
#define _END_STD_C 

#define _FSTDIO 

#define __need_size_t 
#define __size_t__ 
#define __SIZE_T__ 
#define _SIZE_T 
#define _SYS_SIZE_T_H 
#define _T_SIZE_ 
#define _T_SIZE 
#define __SIZE_T 
#define _SIZE_T_ 
#define _BSD_SIZE_T_ 
#define _SIZE_T_DEFINED_ 
#define _SIZE_T_DEFINED 
#define _BSD_SIZE_T_DEFINED_ 
#define _SIZE_T_DECLARED 
#define ___int_size_t_h 
#define _GCC_SIZE_T 
#define _SIZET_ 

#define __size_t 

typedef unsigned int size_t;
#undef __need_size_t

#define __need___va_list 
#undef __need___va_list

#define __GNUC_VA_LIST 
typedef __builtin_va_list __gnuc_va_list;

#define _SYS_REENT_H_ 

#define _SYS__TYPES_H 

typedef long _off_t;
__extension__ typedef long long _off64_t;

typedef int _ssize_t;

#define __need_wint_t 
#define _WINT_T 

typedef unsigned int wint_t;

#undef __need_wint_t

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

#define __Long long
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

#define _ATEXIT_SIZE 32

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
#define _REENT_SMALL_CHECK_INIT(fp) 

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
#define _RAND48_SEED_0 (0x330e)
#define _RAND48_SEED_1 (0xabcd)
#define _RAND48_SEED_2 (0x1234)
#define _RAND48_MULT_0 (0xe66d)
#define _RAND48_MULT_1 (0xdeec)
#define _RAND48_MULT_2 (0x0005)
#define _RAND48_ADD (0x000b)
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;

};

#define _REENT_EMERGENCY_SIZE 25
#define _REENT_ASCTIME_SIZE 26
#define _REENT_SIGNAL_SIZE 24
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
#define _N_LISTS 30
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

#define _REENT_INIT(var) { 0, &var.__sf[0], &var.__sf[1], &var.__sf[2], 0, "", 0, "C", 0, _NULL, _NULL, 0, _NULL, _NULL, 0, _NULL, { {0, _NULL, "", { 0,0,0,0,0,0,0,0}, 0, 1, {{_RAND48_SEED_0, _RAND48_SEED_1, _RAND48_SEED_2}, {_RAND48_MULT_0, _RAND48_MULT_1, _RAND48_MULT_2}, _RAND48_ADD}, {0, {0}}, {0, {0}}, {0, {0}}, "", "", 0, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}}, {0, {0}} } } }

#define _REENT_INIT_PTR(var) { int i; char *tmp_ptr; var->_errno = 0; var->_stdin = &var->__sf[0]; var->_stdout = &var->__sf[1]; var->_stderr = &var->__sf[2]; var->_inc = 0; for (i = 0; i < _REENT_EMERGENCY_SIZE; ++i) var->_emergency[i] = 0; var->_current_category = 0; var->_current_locale = "C"; var->__sdidinit = 0; var->__cleanup = _NULL; var->_result = _NULL; var->_result_k = 0; var->_p5s = _NULL; var->_freelist = _NULL; var->_cvtlen = 0; var->_cvtbuf = _NULL; var->_new._reent._unused_rand = 0; var->_new._reent._strtok_last = _NULL; var->_new._reent._asctime_buf[0] = 0; tmp_ptr = (char *)&var->_new._reent._localtime_buf; for (i = 0; i < sizeof(struct __tm); ++i) tmp_ptr[i] = 0; var->_new._reent._gamma_signgam = 0; var->_new._reent._rand_next = 1; var->_new._reent._r48._seed[0] = _RAND48_SEED_0; var->_new._reent._r48._seed[1] = _RAND48_SEED_1; var->_new._reent._r48._seed[2] = _RAND48_SEED_2; var->_new._reent._r48._mult[0] = _RAND48_MULT_0; var->_new._reent._r48._mult[1] = _RAND48_MULT_1; var->_new._reent._r48._mult[2] = _RAND48_MULT_2; var->_new._reent._r48._add = _RAND48_ADD; var->_new._reent._mblen_state.__count = 0; var->_new._reent._mblen_state.__value.__wch = 0; var->_new._reent._mbtowc_state.__count = 0; var->_new._reent._mbtowc_state.__value.__wch = 0; var->_new._reent._wctomb_state.__count = 0; var->_new._reent._wctomb_state.__value.__wch = 0; var->_new._reent._mbrlen_state.__count = 0; var->_new._reent._mbrlen_state.__value.__wch = 0; var->_new._reent._mbrtowc_state.__count = 0; var->_new._reent._mbrtowc_state.__value.__wch = 0; var->_new._reent._mbsrtowcs_state.__count = 0; var->_new._reent._mbsrtowcs_state.__value.__wch = 0; var->_new._reent._wcrtomb_state.__count = 0; var->_new._reent._wcrtomb_state.__value.__wch = 0; var->_new._reent._wcsrtombs_state.__count = 0; var->_new._reent._wcsrtombs_state.__value.__wch = 0; var->_new._reent._l64a_buf[0] = '\0'; var->_new._reent._signal_buf[0] = '\0'; var->_new._reent._getdate_err = 0; var->_atexit = _NULL; var->_atexit0._ind = 0; var->_atexit0._fns[0] = _NULL; var->_atexit0._on_exit_args._fntypes = 0; var->_atexit0._on_exit_args._fnargs[0] = _NULL; var->_sig_func = _NULL; var->__sglue._next = _NULL; var->__sglue._niobs = 0; var->__sglue._iobs = _NULL; memset(var->__sf,0,sizeof(var->__sf)); }
#define _REENT_CHECK_RAND48(ptr) 
#define _REENT_CHECK_MP(ptr) 
#define _REENT_CHECK_TM(ptr) 
#define _REENT_CHECK_ASCTIME_BUF(ptr) 
#define _REENT_CHECK_EMERGENCY(ptr) 
#define _REENT_CHECK_MISC(ptr) 
#define _REENT_CHECK_SIGNAL_BUF(ptr) 

#define _REENT_SIGNGAM(ptr) ((ptr)->_new._reent._gamma_signgam)
#define _REENT_RAND_NEXT(ptr) ((ptr)->_new._reent._rand_next)
#define _REENT_RAND48_SEED(ptr) ((ptr)->_new._reent._r48._seed)
#define _REENT_RAND48_MULT(ptr) ((ptr)->_new._reent._r48._mult)
#define _REENT_RAND48_ADD(ptr) ((ptr)->_new._reent._r48._add)
#define _REENT_MP_RESULT(ptr) ((ptr)->_result)
#define _REENT_MP_RESULT_K(ptr) ((ptr)->_result_k)
#define _REENT_MP_P5S(ptr) ((ptr)->_p5s)
#define _REENT_MP_FREELIST(ptr) ((ptr)->_freelist)
#define _REENT_ASCTIME_BUF(ptr) ((ptr)->_new._reent._asctime_buf)
#define _REENT_TM(ptr) (&(ptr)->_new._reent._localtime_buf)
#define _REENT_EMERGENCY(ptr) ((ptr)->_emergency)
#define _REENT_STRTOK_LAST(ptr) ((ptr)->_new._reent._strtok_last)
#define _REENT_MBLEN_STATE(ptr) ((ptr)->_new._reent._mblen_state)
#define _REENT_MBTOWC_STATE(ptr) ((ptr)->_new._reent._mbtowc_state)
#define _REENT_WCTOMB_STATE(ptr) ((ptr)->_new._reent._wctomb_state)
#define _REENT_MBRLEN_STATE(ptr) ((ptr)->_new._reent._mbrlen_state)
#define _REENT_MBRTOWC_STATE(ptr) ((ptr)->_new._reent._mbrtowc_state)
#define _REENT_MBSRTOWCS_STATE(ptr) ((ptr)->_new._reent._mbsrtowcs_state)
#define _REENT_WCRTOMB_STATE(ptr) ((ptr)->_new._reent._wcrtomb_state)
#define _REENT_WCSRTOMBS_STATE(ptr) ((ptr)->_new._reent._wcsrtombs_state)
#define _REENT_L64A_BUF(ptr) ((ptr)->_new._reent._l64a_buf)
#define _REENT_SIGNAL_BUF(ptr) ((ptr)->_new._reent._signal_buf)
#define _REENT_GETDATE_ERR_P(ptr) (&((ptr)->_new._reent._getdate_err))

#define _NULL 0

#define __ATTRIBUTE_IMPURE_PTR__ 

extern struct _reent *_impure_ptr ;

void _reclaim_reent (struct _reent *);
#define _REENT _impure_ptr

#define _GLOBAL_REENT _impure_ptr
#define __INTTYPES_DEFINED__ 
typedef short int __int16_t;
typedef unsigned short int __uint16_t;

typedef int __int32_t;
typedef unsigned int __uint32_t;

__extension__ typedef long long __int64_t;
__extension__ typedef unsigned long long __uint64_t;

#define _SYS_TYPES_H 
#define _STDDEF_H 
#define _STDDEF_H_ 

#define _ANSI_STDDEF_H 

#define __STDDEF_H__ 
#define _PTRDIFF_T 
#define _T_PTRDIFF_ 
#define _T_PTRDIFF 
#define __PTRDIFF_T 
#define _PTRDIFF_T_ 
#define _BSD_PTRDIFF_T_ 
#define ___int_ptrdiff_t_h 
#define _GCC_PTRDIFF_T 

typedef int ptrdiff_t;
#define __wchar_t__ 
#define __WCHAR_T__ 
#define _WCHAR_T 
#define _T_WCHAR_ 
#define _T_WCHAR 
#define __WCHAR_T 
#define _WCHAR_T_ 
#define _BSD_WCHAR_T_ 
#define _WCHAR_T_DEFINED_ 
#define _WCHAR_T_DEFINED 
#define _WCHAR_T_H 
#define ___int_wchar_t_h 
#define __INT_WCHAR_T_H 
#define _GCC_WCHAR_T 
#define _WCHAR_T_DECLARED 
#undef _BSD_WCHAR_T_
typedef int wchar_t;
#define NULL ((void *)0)
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define _MACHTYPES_H_ 
#define _CLOCK_T_ unsigned long
#define _TIME_T_ long
#define _CLOCKID_T_ unsigned long
#define _TIMER_T_ unsigned long

typedef long int __off_t;
typedef int __pid_t;

__extension__ typedef long long int __loff_t;
#define _ST_INT32 __attribute__ ((__mode__ (__SI__)))

#define physadr physadr_t
#define quad quad_t

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
#define _BSDTYPES_DEFINED 

typedef unsigned short ushort;
typedef unsigned int uint;

typedef unsigned long clock_t;
#define __clock_t_defined 

typedef long time_t;
#define __time_t_defined 

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
#define _SYS_TYPES_FD_SET 
#define NBBY 8

#define FD_SETSIZE 64

typedef long fd_mask;
#define NFDBITS (sizeof (fd_mask) * NBBY)

#define howmany(x,y) (((x)+((y)-1))/(y))

typedef struct _types_fd_set {
        fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;

#define fd_set _types_fd_set

#define FD_SET(n,p) ((p)->fds_bits[(n)/NFDBITS] |= (1L << ((n) % NFDBITS)))
#define FD_CLR(n,p) ((p)->fds_bits[(n)/NFDBITS] &= ~(1L << ((n) % NFDBITS)))
#define FD_ISSET(n,p) ((p)->fds_bits[(n)/NFDBITS] & (1L << ((n) % NFDBITS)))
#define FD_ZERO(p) (__extension__ (void)({ size_t __i; char *__tmp = (char *)p; for (__i = 0; __i < sizeof (*(p)); ++__i) *__tmp++ = 0; }))
#undef _ST_INT32

typedef __FILE FILE;
typedef _fpos_t fpos_t;

#define _NEWLIB_STDIO_H 

#define _flockfile(fp) 

#define _funlockfile(fp) 

#define __SLBF 0x0001
#define __SNBF 0x0002
#define __SRD 0x0004
#define __SWR 0x0008

#define __SRW 0x0010
#define __SEOF 0x0020
#define __SERR 0x0040
#define __SMBF 0x0080
#define __SAPP 0x0100
#define __SSTR 0x0200
#define __SOPT 0x0400
#define __SNPT 0x0800
#define __SOFF 0x1000
#define __SMOD 0x2000

#define __SL64 0x8000
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define EOF (-1)

#define BUFSIZ 1024

#define FOPEN_MAX 20

#define FILENAME_MAX 1024

#define L_tmpnam FILENAME_MAX

#define P_tmpdir "/tmp"

#define SEEK_SET 0

#define SEEK_CUR 1

#define SEEK_END 2

#define TMP_MAX 26

#define stdin (_REENT->_stdin)
#define stdout (_REENT->_stdout)
#define stderr (_REENT->_stderr)

#define _stdin_r(x) ((x)->_stdin)
#define _stdout_r(x) ((x)->_stdout)
#define _stderr_r(x) ((x)->_stderr)

#define __VALIST __gnuc_va_list

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

#define fropen(cookie,fn) funopen(cookie, fn, (int (*)())0, (fpos_t (*)())0, (int (*)())0)
#define fwopen(cookie,fn) funopen(cookie, (int (*)())0, fn, (fpos_t (*)())0, (int (*)())0)

#define __sgetc_raw(p) (--(p)->_r < 0 ? __srget(p) : (int)(*(p)->_p++))
#define __sgetc(p) __sgetc_raw(p)
#define __sputc_raw(c,p) (--(p)->_w < 0 ? (p)->_w >= (p)->_lbfsize ? (*(p)->_p = (c)), *(p)->_p != '\n' ? (int)*(p)->_p++ : __swbuf('\n', p) : __swbuf((int)(c), p) : (*(p)->_p = (c), (int)*(p)->_p++))
#define __sputc(c,p) __sputc_raw(c, p)

#define __sfeof(p) (((p)->_flags & __SEOF) != 0)
#define __sferror(p) (((p)->_flags & __SERR) != 0)
#define __sclearerr(p) ((void)((p)->_flags &= ~(__SERR|__SEOF)))
#define __sfileno(p) ((p)->_file)

#define feof(p) __sfeof(p)
#define ferror(p) __sferror(p)
#define clearerr(p) __sclearerr(p)

#define getc(fp) __sgetc(fp)
#define putc(x,fp) __sputc(x, fp)

#define getchar() getc(stdin)
#define putchar(x) putc(x, stdout)

#define fast_putc(x,p) (--(p)->_w < 0 ? __swbuf((int)(x), p) == EOF : (*(p)->_p = (x), (p)->_p++, 0))

#define L_cuserid 9

#define _STRING_H_ 

#define __need_size_t 
#undef __need_size_t
#undef NULL

#define NULL ((void *)0)
#define offsetof(TYPE,MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

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
#define strcmpi strcasecmp

#define stricmp strcasecmp

#define strncmpi strncasecmp

#define strnicmp strncasecmp

#define _SCE_PSPTYPES_H 

#define SCE_PSPTYPES_ALIGNED(_a) __attribute__((aligned(_a)))
#define SCE_PSPTYPES_USE_ULONG128 
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
typedef int long128 __attribute__((mode(TI)));
typedef unsigned int u_long128 __attribute__((mode(TI)));

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
typedef int SceLong128 __attribute__((mode(TI)));
typedef unsigned int SceULong128 __attribute__((mode(TI)));

typedef float SceFloat;
typedef float SceFloat32;

typedef signed char SceSByte;
typedef signed char SceSByte8;
typedef unsigned char SceByte;
typedef unsigned char SceByte8;

typedef unsigned short SceWChar16;
typedef unsigned int SceWChar32;

#define SCE_FALSE (0)
#define SCE_TRUE (1)
typedef int SceBool;

typedef int SceIntPtr;
typedef unsigned int SceUIntPtr;

typedef void SceVoid;
typedef void * ScePVoid;

#define SCE_NULL ((void *)0)

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

        SceULong128 qw;

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

        SceULong128 qw[4];

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

#define ScePspRGBA32 ScePspRGBA8888
typedef unsigned int ScePspRGBA8888;
typedef unsigned short ScePspRGBA4444;
typedef unsigned short ScePspRGBA5551;
typedef unsigned short ScePspRGB565;
#define SCE_PSP_MAKE_RGBA8888(_r,_g,_b,_a) ((ScePspRGBA8888)((((unsigned int)_a)<<24) | (((unsigned int)_b)<<16) | (((unsigned int)_g)<<8) | ((unsigned int)_r)))

#define SCE_PSP_MAKE_RGBA4444(_r,_g,_b,_a) ((ScePspRGBA4444)((((unsigned int)_a)<<12) | (((unsigned int)_b)<<8) | (((unsigned int)_g)<<4) | ((unsigned int)_r)))

#define SCE_PSP_MAKE_RGBA5551(_r,_g,_b,_a) ((ScePspRGBA5551)((((unsigned int)_a)<<15) | (((unsigned int)_b)<<10) | (((unsigned int)_g)<<5) | ((unsigned int)_r)))

#define SCE_PSP_MAKE_RGB565(_r,_g,_b) ((ScePspRGB565) ( (((unsigned int)_b)<<11) | (((unsigned int)_g)<<5) | ((unsigned int)_r)))

#define SCE_PSP_EXTRACT_R_FROM_RGBA8888(_rgba8888) ((_rgba8888 ) & 0xFF)
#define SCE_PSP_EXTRACT_G_FROM_RGBA8888(_rgba8888) ((_rgba8888>> 8) & 0xFF)
#define SCE_PSP_EXTRACT_B_FROM_RGBA8888(_rgba8888) ((_rgba8888>>16) & 0xFF)
#define SCE_PSP_EXTRACT_A_FROM_RGBA8888(_rgba8888) ((_rgba8888>>24) & 0xFF)
#define SCE_PSP_EXTRACT_R_FROM_RGBA4444(_rgba4444) ((_rgba4444 ) & 0xF)
#define SCE_PSP_EXTRACT_G_FROM_RGBA4444(_rgba4444) ((_rgba4444>> 4) & 0xF)
#define SCE_PSP_EXTRACT_B_FROM_RGBA4444(_rgba4444) ((_rgba4444>> 8) & 0xF)
#define SCE_PSP_EXTRACT_A_FROM_RGBA4444(_rgba4444) ((_rgba4444>>12) & 0xF)
#define SCE_PSP_EXTRACT_R_FROM_RGBA5551(_rgba5551) ((_rgba5551 ) & 0x1F)
#define SCE_PSP_EXTRACT_G_FROM_RGBA5551(_rgba5551) ((_rgba5551>> 5) & 0x1F)
#define SCE_PSP_EXTRACT_B_FROM_RGBA5551(_rgba5551) ((_rgba5551>>10) & 0x1F)
#define SCE_PSP_EXTRACT_A_FROM_RGBA5551(_rgba5551) ((_rgba5551>>15) & 0x1)
#define SCE_PSP_EXTRACT_R_FROM_RGB565(_rgba565) ((_rgba565 ) & 0x1F)
#define SCE_PSP_EXTRACT_G_FROM_RGB565(_rgba565) ((_rgba565>> 5) & 0x3F)
#define SCE_PSP_EXTRACT_B_FROM_RGB565(_rgba565) ((_rgba565>>11) & 0x1F)

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
        ScePspFPlane fp;
        ScePspFColor fc;
        ScePspRGBA8888 rgba8888[4];
        ScePspRGBA4444 rgba4444[8];
        ScePspRGBA5551 rgba5551[8];
        ScePspRGB565 rgb565[8];
} __attribute__((aligned(16))) ScePspUnion128;

typedef union ScePspUnion512 {

        SceULong128 qw[4];
        SceULong128 uq[4];
        SceLong128 q[4];

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
#define _SCE_GEMAN_H 

#define _SCE_GECMD_H 
#define SCE_GE_EXTRACT_ADDR24(_adr32) (((SceUInt32)(_adr32)) & 0x00FFFFFFU)
#define SCE_GE_EXTRACT_BASE8(_adr32) ((((SceUInt32)(_adr32))>>24) & 0x0FU)
#define SCE_GE_EXTRACT_BASE24(_adr32) ((((SceUInt32)(_adr32))>>8) & 0x000FFFFFU)
static __inline__ unsigned int sceGeExtractFloat24(float _float32);
static __inline__ unsigned int sceGeExtractFloat24(float _float32)
{
        ScePspUnion32 u;
        u.f = _float32;
        return (u.ui>>8);
}
#define SCE_GE_EXTRACT_FLOAT24(_float32) sceGeExtractFloat24(_float32)
#define _SCE_GE_CMD_DEFINE(_n) (_n ##U)

#define SCE_GE_CMD_NOP _SCE_GE_CMD_DEFINE(0x00)

#define SCE_GE_CMD_VADR _SCE_GE_CMD_DEFINE(0x01)

#define SCE_GE_CMD_IADR _SCE_GE_CMD_DEFINE(0x02)

#define SCE_GE_CMD_PRIM _SCE_GE_CMD_DEFINE(0x04)

#define SCE_GE_CMD_BEZIER _SCE_GE_CMD_DEFINE(0x05)

#define SCE_GE_CMD_SPLINE _SCE_GE_CMD_DEFINE(0x06)

#define SCE_GE_CMD_BBOX _SCE_GE_CMD_DEFINE(0x07)

#define SCE_GE_CMD_JUMP _SCE_GE_CMD_DEFINE(0x08)

#define SCE_GE_CMD_BJUMP _SCE_GE_CMD_DEFINE(0x09)

#define SCE_GE_CMD_CALL _SCE_GE_CMD_DEFINE(0x0A)

#define SCE_GE_CMD_RET _SCE_GE_CMD_DEFINE(0x0B)

#define SCE_GE_CMD_END _SCE_GE_CMD_DEFINE(0x0C)

#define SCE_GE_CMD_SIGNAL _SCE_GE_CMD_DEFINE(0x0E)

#define SCE_GE_CMD_FINISH _SCE_GE_CMD_DEFINE(0x0F)

#define SCE_GE_CMD_BASE _SCE_GE_CMD_DEFINE(0x10)

#define SCE_GE_CMD_VTYPE _SCE_GE_CMD_DEFINE(0x12)

#define SCE_GE_CMD_OFFSET _SCE_GE_CMD_DEFINE(0x13)

#define SCE_GE_CMD_ORIGIN _SCE_GE_CMD_DEFINE(0x14)

#define SCE_GE_CMD_REGION1 _SCE_GE_CMD_DEFINE(0x15)

#define SCE_GE_CMD_REGION2 _SCE_GE_CMD_DEFINE(0x16)

#define SCE_GE_CMD_LTE _SCE_GE_CMD_DEFINE(0x17)

#define SCE_GE_CMD_LE0 _SCE_GE_CMD_DEFINE(0x18)

#define SCE_GE_CMD_LE1 _SCE_GE_CMD_DEFINE(0x19)

#define SCE_GE_CMD_LE2 _SCE_GE_CMD_DEFINE(0x1A)

#define SCE_GE_CMD_LE3 _SCE_GE_CMD_DEFINE(0x1B)

#define SCE_GE_CMD_CLE _SCE_GE_CMD_DEFINE(0x1C)

#define SCE_GE_CMD_BCE _SCE_GE_CMD_DEFINE(0x1D)

#define SCE_GE_CMD_TME _SCE_GE_CMD_DEFINE(0x1E)

#define SCE_GE_CMD_FGE _SCE_GE_CMD_DEFINE(0x1F)

#define SCE_GE_CMD_DTE _SCE_GE_CMD_DEFINE(0x20)

#define SCE_GE_CMD_ABE _SCE_GE_CMD_DEFINE(0x21)

#define SCE_GE_CMD_ATE _SCE_GE_CMD_DEFINE(0x22)

#define SCE_GE_CMD_ZTE _SCE_GE_CMD_DEFINE(0x23)

#define SCE_GE_CMD_STE _SCE_GE_CMD_DEFINE(0x24)

#define SCE_GE_CMD_AAE _SCE_GE_CMD_DEFINE(0x25)

#define SCE_GE_CMD_PCE _SCE_GE_CMD_DEFINE(0x26)

#define SCE_GE_CMD_CTE _SCE_GE_CMD_DEFINE(0x27)

#define SCE_GE_CMD_LOE _SCE_GE_CMD_DEFINE(0x28)

#define SCE_GE_CMD_BONEN _SCE_GE_CMD_DEFINE(0x2A)

#define SCE_GE_CMD_BONED _SCE_GE_CMD_DEFINE(0x2B)

#define SCE_GE_CMD_WEIGHT0 _SCE_GE_CMD_DEFINE(0x2C)

#define SCE_GE_CMD_WEIGHT1 _SCE_GE_CMD_DEFINE(0x2D)

#define SCE_GE_CMD_WEIGHT2 _SCE_GE_CMD_DEFINE(0x2E)

#define SCE_GE_CMD_WEIGHT3 _SCE_GE_CMD_DEFINE(0x2F)

#define SCE_GE_CMD_WEIGHT4 _SCE_GE_CMD_DEFINE(0x30)

#define SCE_GE_CMD_WEIGHT5 _SCE_GE_CMD_DEFINE(0x31)

#define SCE_GE_CMD_WEIGHT6 _SCE_GE_CMD_DEFINE(0x32)

#define SCE_GE_CMD_WEIGHT7 _SCE_GE_CMD_DEFINE(0x33)

#define SCE_GE_CMD_DIVIDE _SCE_GE_CMD_DEFINE(0x36)

#define SCE_GE_CMD_PPM _SCE_GE_CMD_DEFINE(0x37)

#define SCE_GE_CMD_PFACE _SCE_GE_CMD_DEFINE(0x38)

#define SCE_GE_CMD_WORLDN _SCE_GE_CMD_DEFINE(0x3A)

#define SCE_GE_CMD_WORLDD _SCE_GE_CMD_DEFINE(0x3B)

#define SCE_GE_CMD_VIEWN _SCE_GE_CMD_DEFINE(0x3C)

#define SCE_GE_CMD_VIEWD _SCE_GE_CMD_DEFINE(0x3D)

#define SCE_GE_CMD_PROJN _SCE_GE_CMD_DEFINE(0x3E)

#define SCE_GE_CMD_PROJD _SCE_GE_CMD_DEFINE(0x3F)

#define SCE_GE_CMD_TGENN _SCE_GE_CMD_DEFINE(0x40)

#define SCE_GE_CMD_TGEND _SCE_GE_CMD_DEFINE(0x41)

#define SCE_GE_CMD_SX _SCE_GE_CMD_DEFINE(0x42)

#define SCE_GE_CMD_SY _SCE_GE_CMD_DEFINE(0x43)

#define SCE_GE_CMD_SZ _SCE_GE_CMD_DEFINE(0x44)

#define SCE_GE_CMD_TX _SCE_GE_CMD_DEFINE(0x45)

#define SCE_GE_CMD_TY _SCE_GE_CMD_DEFINE(0x46)

#define SCE_GE_CMD_TZ _SCE_GE_CMD_DEFINE(0x47)

#define SCE_GE_CMD_SU _SCE_GE_CMD_DEFINE(0x48)

#define SCE_GE_CMD_SV _SCE_GE_CMD_DEFINE(0x49)

#define SCE_GE_CMD_TU _SCE_GE_CMD_DEFINE(0x4A)

#define SCE_GE_CMD_TV _SCE_GE_CMD_DEFINE(0x4B)

#define SCE_GE_CMD_OFFSETX _SCE_GE_CMD_DEFINE(0x4C)

#define SCE_GE_CMD_OFFSETY _SCE_GE_CMD_DEFINE(0x4D)

#define SCE_GE_CMD_SHADE _SCE_GE_CMD_DEFINE(0x50)

#define SCE_GE_CMD_NREV _SCE_GE_CMD_DEFINE(0x51)

#define SCE_GE_CMD_MATERIAL _SCE_GE_CMD_DEFINE(0x53)

#define SCE_GE_CMD_MEC _SCE_GE_CMD_DEFINE(0x54)

#define SCE_GE_CMD_MAC _SCE_GE_CMD_DEFINE(0x55)

#define SCE_GE_CMD_MDC _SCE_GE_CMD_DEFINE(0x56)

#define SCE_GE_CMD_MSC _SCE_GE_CMD_DEFINE(0x57)

#define SCE_GE_CMD_MAA _SCE_GE_CMD_DEFINE(0x58)

#define SCE_GE_CMD_MK _SCE_GE_CMD_DEFINE(0x5B)

#define SCE_GE_CMD_AC _SCE_GE_CMD_DEFINE(0x5C)

#define SCE_GE_CMD_AA _SCE_GE_CMD_DEFINE(0x5D)

#define SCE_GE_CMD_LMODE _SCE_GE_CMD_DEFINE(0x5E)

#define SCE_GE_CMD_LTYPE0 _SCE_GE_CMD_DEFINE(0x5F)

#define SCE_GE_CMD_LTYPE1 _SCE_GE_CMD_DEFINE(0x60)

#define SCE_GE_CMD_LTYPE2 _SCE_GE_CMD_DEFINE(0x61)

#define SCE_GE_CMD_LTYPE3 _SCE_GE_CMD_DEFINE(0x62)

#define SCE_GE_CMD_LX0 _SCE_GE_CMD_DEFINE(0x63)

#define SCE_GE_CMD_LY0 _SCE_GE_CMD_DEFINE(0x64)

#define SCE_GE_CMD_LZ0 _SCE_GE_CMD_DEFINE(0x65)

#define SCE_GE_CMD_LX1 _SCE_GE_CMD_DEFINE(0x66)

#define SCE_GE_CMD_LY1 _SCE_GE_CMD_DEFINE(0x67)

#define SCE_GE_CMD_LZ1 _SCE_GE_CMD_DEFINE(0x68)

#define SCE_GE_CMD_LX2 _SCE_GE_CMD_DEFINE(0x69)

#define SCE_GE_CMD_LY2 _SCE_GE_CMD_DEFINE(0x6A)

#define SCE_GE_CMD_LZ2 _SCE_GE_CMD_DEFINE(0x6B)

#define SCE_GE_CMD_LX3 _SCE_GE_CMD_DEFINE(0x6C)

#define SCE_GE_CMD_LY3 _SCE_GE_CMD_DEFINE(0x6D)

#define SCE_GE_CMD_LZ3 _SCE_GE_CMD_DEFINE(0x6E)

#define SCE_GE_CMD_LDX0 _SCE_GE_CMD_DEFINE(0x6F)

#define SCE_GE_CMD_LDY0 _SCE_GE_CMD_DEFINE(0x70)

#define SCE_GE_CMD_LDZ0 _SCE_GE_CMD_DEFINE(0x71)

#define SCE_GE_CMD_LDX1 _SCE_GE_CMD_DEFINE(0x72)

#define SCE_GE_CMD_LDY1 _SCE_GE_CMD_DEFINE(0x73)

#define SCE_GE_CMD_LDZ1 _SCE_GE_CMD_DEFINE(0x74)

#define SCE_GE_CMD_LDX2 _SCE_GE_CMD_DEFINE(0x75)

#define SCE_GE_CMD_LDY2 _SCE_GE_CMD_DEFINE(0x76)

#define SCE_GE_CMD_LDZ2 _SCE_GE_CMD_DEFINE(0x77)

#define SCE_GE_CMD_LDX3 _SCE_GE_CMD_DEFINE(0x78)

#define SCE_GE_CMD_LDY3 _SCE_GE_CMD_DEFINE(0x79)

#define SCE_GE_CMD_LDZ3 _SCE_GE_CMD_DEFINE(0x7A)

#define SCE_GE_CMD_LKA0 _SCE_GE_CMD_DEFINE(0x7B)

#define SCE_GE_CMD_LKB0 _SCE_GE_CMD_DEFINE(0x7C)

#define SCE_GE_CMD_LKC0 _SCE_GE_CMD_DEFINE(0x7D)

#define SCE_GE_CMD_LKA1 _SCE_GE_CMD_DEFINE(0x7E)

#define SCE_GE_CMD_LKB1 _SCE_GE_CMD_DEFINE(0x7F)

#define SCE_GE_CMD_LKC1 _SCE_GE_CMD_DEFINE(0x80)

#define SCE_GE_CMD_LKA2 _SCE_GE_CMD_DEFINE(0x81)

#define SCE_GE_CMD_LKB2 _SCE_GE_CMD_DEFINE(0x82)

#define SCE_GE_CMD_LKC2 _SCE_GE_CMD_DEFINE(0x83)

#define SCE_GE_CMD_LKA3 _SCE_GE_CMD_DEFINE(0x84)

#define SCE_GE_CMD_LKB3 _SCE_GE_CMD_DEFINE(0x85)

#define SCE_GE_CMD_LKC3 _SCE_GE_CMD_DEFINE(0x86)

#define SCE_GE_CMD_LKS0 _SCE_GE_CMD_DEFINE(0x87)

#define SCE_GE_CMD_LKS1 _SCE_GE_CMD_DEFINE(0x88)

#define SCE_GE_CMD_LKS2 _SCE_GE_CMD_DEFINE(0x89)

#define SCE_GE_CMD_LKS3 _SCE_GE_CMD_DEFINE(0x8A)

#define SCE_GE_CMD_LKO0 _SCE_GE_CMD_DEFINE(0x8B)

#define SCE_GE_CMD_LKO1 _SCE_GE_CMD_DEFINE(0x8C)

#define SCE_GE_CMD_LKO2 _SCE_GE_CMD_DEFINE(0x8D)

#define SCE_GE_CMD_LKO3 _SCE_GE_CMD_DEFINE(0x8E)

#define SCE_GE_CMD_LAC0 _SCE_GE_CMD_DEFINE(0x8F)

#define SCE_GE_CMD_LDC0 _SCE_GE_CMD_DEFINE(0x90)

#define SCE_GE_CMD_LSC0 _SCE_GE_CMD_DEFINE(0x91)

#define SCE_GE_CMD_LAC1 _SCE_GE_CMD_DEFINE(0x92)

#define SCE_GE_CMD_LDC1 _SCE_GE_CMD_DEFINE(0x93)

#define SCE_GE_CMD_LSC1 _SCE_GE_CMD_DEFINE(0x94)

#define SCE_GE_CMD_LAC2 _SCE_GE_CMD_DEFINE(0x95)

#define SCE_GE_CMD_LDC2 _SCE_GE_CMD_DEFINE(0x96)

#define SCE_GE_CMD_LSC2 _SCE_GE_CMD_DEFINE(0x97)

#define SCE_GE_CMD_LAC3 _SCE_GE_CMD_DEFINE(0x98)

#define SCE_GE_CMD_LDC3 _SCE_GE_CMD_DEFINE(0x99)

#define SCE_GE_CMD_LSC3 _SCE_GE_CMD_DEFINE(0x9A)

#define SCE_GE_CMD_CULL _SCE_GE_CMD_DEFINE(0x9B)

#define SCE_GE_CMD_FBP _SCE_GE_CMD_DEFINE(0x9C)

#define SCE_GE_CMD_FBW _SCE_GE_CMD_DEFINE(0x9D)

#define SCE_GE_CMD_ZBP _SCE_GE_CMD_DEFINE(0x9E)

#define SCE_GE_CMD_ZBW _SCE_GE_CMD_DEFINE(0x9F)

#define SCE_GE_CMD_TBP0 _SCE_GE_CMD_DEFINE(0xA0)

#define SCE_GE_CMD_TBP1 _SCE_GE_CMD_DEFINE(0xA1)

#define SCE_GE_CMD_TBP2 _SCE_GE_CMD_DEFINE(0xA2)

#define SCE_GE_CMD_TBP3 _SCE_GE_CMD_DEFINE(0xA3)

#define SCE_GE_CMD_TBP4 _SCE_GE_CMD_DEFINE(0xA4)

#define SCE_GE_CMD_TBP5 _SCE_GE_CMD_DEFINE(0xA5)

#define SCE_GE_CMD_TBP6 _SCE_GE_CMD_DEFINE(0xA6)

#define SCE_GE_CMD_TBP7 _SCE_GE_CMD_DEFINE(0xA7)

#define SCE_GE_CMD_TBW0 _SCE_GE_CMD_DEFINE(0xA8)

#define SCE_GE_CMD_TBW1 _SCE_GE_CMD_DEFINE(0xA9)

#define SCE_GE_CMD_TBW2 _SCE_GE_CMD_DEFINE(0xAA)

#define SCE_GE_CMD_TBW3 _SCE_GE_CMD_DEFINE(0xAB)

#define SCE_GE_CMD_TBW4 _SCE_GE_CMD_DEFINE(0xAC)

#define SCE_GE_CMD_TBW5 _SCE_GE_CMD_DEFINE(0xAD)

#define SCE_GE_CMD_TBW6 _SCE_GE_CMD_DEFINE(0xAE)

#define SCE_GE_CMD_TBW7 _SCE_GE_CMD_DEFINE(0xAF)

#define SCE_GE_CMD_CBP _SCE_GE_CMD_DEFINE(0xB0)

#define SCE_GE_CMD_CBW _SCE_GE_CMD_DEFINE(0xB1)

#define SCE_GE_CMD_XBP1 _SCE_GE_CMD_DEFINE(0xB2)

#define SCE_GE_CMD_XBW1 _SCE_GE_CMD_DEFINE(0xB3)

#define SCE_GE_CMD_XBP2 _SCE_GE_CMD_DEFINE(0xB4)

#define SCE_GE_CMD_XBW2 _SCE_GE_CMD_DEFINE(0xB5)

#define SCE_GE_CMD_TSIZE0 _SCE_GE_CMD_DEFINE(0xB8)

#define SCE_GE_CMD_TSIZE1 _SCE_GE_CMD_DEFINE(0xB9)

#define SCE_GE_CMD_TSIZE2 _SCE_GE_CMD_DEFINE(0xBA)

#define SCE_GE_CMD_TSIZE3 _SCE_GE_CMD_DEFINE(0xBB)

#define SCE_GE_CMD_TSIZE4 _SCE_GE_CMD_DEFINE(0xBC)

#define SCE_GE_CMD_TSIZE5 _SCE_GE_CMD_DEFINE(0xBD)

#define SCE_GE_CMD_TSIZE6 _SCE_GE_CMD_DEFINE(0xBE)

#define SCE_GE_CMD_TSIZE7 _SCE_GE_CMD_DEFINE(0xBF)

#define SCE_GE_CMD_TMAP _SCE_GE_CMD_DEFINE(0xC0)

#define SCE_GE_CMD_TSHADE _SCE_GE_CMD_DEFINE(0xC1)

#define SCE_GE_CMD_TMODE _SCE_GE_CMD_DEFINE(0xC2)

#define SCE_GE_CMD_TPF _SCE_GE_CMD_DEFINE(0xC3)

#define SCE_GE_CMD_CLOAD _SCE_GE_CMD_DEFINE(0xC4)

#define SCE_GE_CMD_CLUT _SCE_GE_CMD_DEFINE(0xC5)

#define SCE_GE_CMD_TFILTER _SCE_GE_CMD_DEFINE(0xC6)

#define SCE_GE_CMD_TWRAP _SCE_GE_CMD_DEFINE(0xC7)

#define SCE_GE_CMD_TLEVEL _SCE_GE_CMD_DEFINE(0xC8)

#define SCE_GE_CMD_TFUNC _SCE_GE_CMD_DEFINE(0xC9)

#define SCE_GE_CMD_TEC _SCE_GE_CMD_DEFINE(0xCA)

#define SCE_GE_CMD_TFLUSH _SCE_GE_CMD_DEFINE(0xCB)

#define SCE_GE_CMD_TSYNC _SCE_GE_CMD_DEFINE(0xCC)

#define SCE_GE_CMD_FOG1 _SCE_GE_CMD_DEFINE(0xCD)

#define SCE_GE_CMD_FOG2 _SCE_GE_CMD_DEFINE(0xCE)

#define SCE_GE_CMD_FC _SCE_GE_CMD_DEFINE(0xCF)

#define SCE_GE_CMD_TSLOPE _SCE_GE_CMD_DEFINE(0xD0)

#define SCE_GE_CMD_FPF _SCE_GE_CMD_DEFINE(0xD2)

#define SCE_GE_CMD_CMODE _SCE_GE_CMD_DEFINE(0xD3)

#define SCE_GE_CMD_SCISSOR1 _SCE_GE_CMD_DEFINE(0xD4)

#define SCE_GE_CMD_SCISSOR2 _SCE_GE_CMD_DEFINE(0xD5)

#define SCE_GE_CMD_MINZ _SCE_GE_CMD_DEFINE(0xD6)

#define SCE_GE_CMD_MAXZ _SCE_GE_CMD_DEFINE(0xD7)

#define SCE_GE_CMD_CTEST _SCE_GE_CMD_DEFINE(0xD8)

#define SCE_GE_CMD_CREF _SCE_GE_CMD_DEFINE(0xD9)

#define SCE_GE_CMD_CMSK _SCE_GE_CMD_DEFINE(0xDA)

#define SCE_GE_CMD_ATEST _SCE_GE_CMD_DEFINE(0xDB)

#define SCE_GE_CMD_STEST _SCE_GE_CMD_DEFINE(0xDC)

#define SCE_GE_CMD_SOP _SCE_GE_CMD_DEFINE(0xDD)

#define SCE_GE_CMD_ZTEST _SCE_GE_CMD_DEFINE(0xDE)

#define SCE_GE_CMD_BLEND _SCE_GE_CMD_DEFINE(0xDF)

#define SCE_GE_CMD_FIXA _SCE_GE_CMD_DEFINE(0xE0)

#define SCE_GE_CMD_FIXB _SCE_GE_CMD_DEFINE(0xE1)

#define SCE_GE_CMD_DITH1 _SCE_GE_CMD_DEFINE(0xE2)

#define SCE_GE_CMD_DITH2 _SCE_GE_CMD_DEFINE(0xE3)

#define SCE_GE_CMD_DITH3 _SCE_GE_CMD_DEFINE(0xE4)

#define SCE_GE_CMD_DITH4 _SCE_GE_CMD_DEFINE(0xE5)

#define SCE_GE_CMD_LOP _SCE_GE_CMD_DEFINE(0xE6)

#define SCE_GE_CMD_ZMSK _SCE_GE_CMD_DEFINE(0xE7)

#define SCE_GE_CMD_PMSK1 _SCE_GE_CMD_DEFINE(0xE8)

#define SCE_GE_CMD_PMSK2 _SCE_GE_CMD_DEFINE(0xE9)

#define SCE_GE_CMD_XSTART _SCE_GE_CMD_DEFINE(0xEA)

#define SCE_GE_CMD_XPOS1 _SCE_GE_CMD_DEFINE(0xEB)

#define SCE_GE_CMD_XPOS2 _SCE_GE_CMD_DEFINE(0xEC)

#define SCE_GE_CMD_XSIZE _SCE_GE_CMD_DEFINE(0xEE)

#define SCE_GE_CMD_DUMMY _SCE_GE_CMD_DEFINE(0xFF)

#define SCE_GE_KEEP 0
#define SCE_GE_UPDATE 1
#define SCE_GE_OFF 0
#define SCE_GE_ON 1

#define SCE_GE_SET_NOP() (SCE_GE_CMD_NOP<<24)
#define SCE_GE_SET_NOP_LABEL24(_label24) ((SCE_GE_CMD_NOP<<24) | ((_label24) & 0x00FFFFFF))

#define SCE_GE_SET_VADR(_adr) ((SCE_GE_CMD_VADR<<24) | ((_adr) & 0x00FFFFFF))
#define SCE_GE_SET_VADR_ADDR24(_adr32) ((SCE_GE_CMD_VADR<<24) | SCE_GE_EXTRACT_ADDR24(_adr32))

#define SCE_GE_SET_IADR(_adr) ((SCE_GE_CMD_IADR<<24) | ((_adr) & 0x00FFFFFF))
#define SCE_GE_SET_IADR_ADDR24(_adr32) ((SCE_GE_CMD_IADR<<24) | SCE_GE_EXTRACT_ADDR24(_adr32))

#define SCE_GE_SET_PRIM(_count,_prim) ((SCE_GE_CMD_PRIM<<24) | ((_prim)<<16) | (_count))
#define SCE_GE_PRIM_POINTS 0
#define SCE_GE_PRIM_LINES 1
#define SCE_GE_PRIM_LINE_STRIP 2
#define SCE_GE_PRIM_TRIANGLES 3
#define SCE_GE_PRIM_TRIANGLE_STRIP 4
#define SCE_GE_PRIM_TRIANGLE_FAN 5
#define SCE_GE_PRIM_RECTANGLES 6

#define SCE_GE_SET_BEZIER(_ucount,_vcount) ((SCE_GE_CMD_BEZIER<<24) | ((_vcount)<<8) | (_ucount))

#define SCE_GE_SET_SPLINE(_ucount,_vcount,_uf,_vf) ((SCE_GE_CMD_SPLINE<<24) | ((_vf)<<18) | ((_uf)<<16) | ((_vcount)<<8) | (_ucount))

#define SCE_GE_SPLINE_CLOSE_CLOSE 0
#define SCE_GE_SPLINE_OPEN_CLOSE 1
#define SCE_GE_SPLINE_CLOSE_OPEN 2
#define SCE_GE_SPLINE_OPEN_OPEN 3

#define SCE_GE_SET_BBOX(_count) ((SCE_GE_CMD_BBOX<<24) | (_count))

#define SCE_GE_SET_JUMP(_adr) ((SCE_GE_CMD_JUMP<<24) | ((_adr) & 0x00FFFFFF))
#define SCE_GE_SET_JUMP_ADDR24(_adr32) ((SCE_GE_CMD_JUMP<<24) | SCE_GE_EXTRACT_ADDR24(_adr32))

#define SCE_GE_SET_BJUMP(_adr) ((SCE_GE_CMD_BJUMP<<24) | ((_adr) & 0x00FFFFFF))
#define SCE_GE_SET_BJUMP_ADDR24(_adr32) ((SCE_GE_CMD_BJUMP<<24) | SCE_GE_EXTRACT_ADDR24(_adr32))

#define SCE_GE_SET_CALL(_adr) ((SCE_GE_CMD_CALL<<24) | ((_adr) & 0x00FFFFFF))
#define SCE_GE_SET_CALL_ADDR24(_adr32) ((SCE_GE_CMD_CALL<<24) | SCE_GE_EXTRACT_ADDR24(_adr32))

#define SCE_GE_SET_RET() ((SCE_GE_CMD_RET<<24))

#define SCE_GE_SET_END() ((SCE_GE_CMD_END<<24))

#define SCE_GE_SET_SIGNAL() ((SCE_GE_CMD_SIGNAL<<24))

#define SCE_GE_SET_FINISH() ((SCE_GE_CMD_FINISH<<24))

#define SCE_GE_SET_BASE(_base) ((SCE_GE_CMD_BASE<<24) | (((_base) & 0x0F)<<16))
#define SCE_GE_SET_BASE_BASE8(_base32) ((SCE_GE_CMD_BASE<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16))

#define SCE_GE_SET_VTYPE(_tt,_ct,_nt,_vt,_wt,_it,_wc,_mc,_tru) ((SCE_GE_CMD_VTYPE<<24) | ((_tru)<<23) | ((_mc)<<18) | ((_wc)<<14) | ((_it)<<11) | ((_wt)<<9) | ((_vt)<<7) | ((_nt)<<5) | ((_ct)<<2) | (_tt))

#define SCE_GE_VTYPE_NONE 0
#define SCE_GE_VTYPE_CHAR 1
#define SCE_GE_VTYPE_UCHAR 1
#define SCE_GE_VTYPE_SHORT 2
#define SCE_GE_VTYPE_USHORT 2
#define SCE_GE_VTYPE_FLOAT 3

#define SCE_GE_VTYPE_TTNONE SCE_GE_VTYPE_NONE
#define SCE_GE_VTYPE_TTUCHAR SCE_GE_VTYPE_UCHAR
#define SCE_GE_VTYPE_TTUSHORT SCE_GE_VTYPE_USHORT
#define SCE_GE_VTYPE_TTFLOAT SCE_GE_VTYPE_FLOAT

#define SCE_GE_VTYPE_CTNONE 0
#define SCE_GE_VTYPE_CT5650 4
#define SCE_GE_VTYPE_CT5551 5
#define SCE_GE_VTYPE_CT4444 6
#define SCE_GE_VTYPE_CT8888 7

#define SCE_GE_VTYPE_NTNONE SCE_GE_VTYPE_NONE
#define SCE_GE_VTYPE_NTCHAR SCE_GE_VTYPE_CHAR
#define SCE_GE_VTYPE_NTSHORT SCE_GE_VTYPE_SHORT
#define SCE_GE_VTYPE_NTFLOAT SCE_GE_VTYPE_FLOAT

#define SCE_GE_VTYPE_VTCHAR SCE_GE_VTYPE_CHAR
#define SCE_GE_VTYPE_VTSHORT SCE_GE_VTYPE_SHORT
#define SCE_GE_VTYPE_VTFLOAT SCE_GE_VTYPE_FLOAT

#define SCE_GE_VTYPE_WTNONE SCE_GE_VTYPE_NONE
#define SCE_GE_VTYPE_WTUCHAR SCE_GE_VTYPE_UCHAR
#define SCE_GE_VTYPE_WTUSHORT SCE_GE_VTYPE_USHORT
#define SCE_GE_VTYPE_WTFLOAT SCE_GE_VTYPE_FLOAT

#define SCE_GE_VTYPE_ITNONE SCE_GE_VTYPE_NONE
#define SCE_GE_VTYPE_ITUCHAR SCE_GE_VTYPE_UCHAR
#define SCE_GE_VTYPE_ITUSHORT SCE_GE_VTYPE_USHORT

#define SCE_GE_VTYPE_WEIGHT1 0
#define SCE_GE_VTYPE_WEIGHT2 1
#define SCE_GE_VTYPE_WEIGHT3 2
#define SCE_GE_VTYPE_WEIGHT4 3
#define SCE_GE_VTYPE_WEIGHT5 4
#define SCE_GE_VTYPE_WEIGHT6 5
#define SCE_GE_VTYPE_WEIGHT7 6
#define SCE_GE_VTYPE_WEIGHT8 7

#define SCE_GE_VTYPE_BLEND0 0
#define SCE_GE_VTYPE_BLEND2 1
#define SCE_GE_VTYPE_BLEND3 2
#define SCE_GE_VTYPE_BLEND4 3
#define SCE_GE_VTYPE_BLEND5 4
#define SCE_GE_VTYPE_BLEND6 5
#define SCE_GE_VTYPE_BLEND7 6
#define SCE_GE_VTYPE_BLEND8 7

#define SCE_GE_VTYPE_NORMAL 0
#define SCE_GE_VTYPE_THROUGH 1

#define SCE_GE_SET_OFFSET(_offset) ((SCE_GE_CMD_OFFSET<<24) | ((_offset) & 0x00FFFFFF))
#define SCE_GE_SET_OFFSET_BASE24(_offset) ((SCE_GE_CMD_OFFSET<<24) | SCE_GE_EXTRACT_BASE24(_offset))

#define SCE_GE_SET_ORIGIN() ((SCE_GE_CMD_ORIGIN<<24))

#define SCE_GE_SET_REGION1(_sx1,_sy1) ((SCE_GE_CMD_REGION1<<24) | ((_sy1)<<10) | (_sx1))

#define SCE_GE_SET_REGION2(_sx2,_sy2) ((SCE_GE_CMD_REGION2<<24) | ((_sy2)<<10) | (_sx2))

#define SCE_GE_SET_LTE(_lte) ((SCE_GE_CMD_LTE<<24) | (_lte))

#define SCE_GE_SET_LE0(_le) ((SCE_GE_CMD_LE0<<24) | (_le))

#define SCE_GE_SET_LE1(_le) ((SCE_GE_CMD_LE1<<24) | (_le))

#define SCE_GE_SET_LE2(_le) ((SCE_GE_CMD_LE2<<24) | (_le))

#define SCE_GE_SET_LE3(_le) ((SCE_GE_CMD_LE3<<24) | (_le))

#define SCE_GE_SET_LEn(_n,_le) (((SCE_GE_CMD_LE0+(_n))<<24) | (_le))

#define SCE_GE_SET_CLE(_cle) ((SCE_GE_CMD_CLE<<24) | (_cle))

#define SCE_GE_SET_BCE(_bce) ((SCE_GE_CMD_BCE<<24) | (_bce))

#define SCE_GE_SET_TME(_tme) ((SCE_GE_CMD_TME<<24) | (_tme))

#define SCE_GE_SET_FGE(_fge) ((SCE_GE_CMD_FGE<<24) | (_fge))

#define SCE_GE_SET_DTE(_dte) ((SCE_GE_CMD_DTE<<24) | (_dte))

#define SCE_GE_SET_ABE(_abe) ((SCE_GE_CMD_ABE<<24) | (_abe))

#define SCE_GE_SET_ATE(_ate) ((SCE_GE_CMD_ATE<<24) | (_ate))

#define SCE_GE_SET_ZTE(_zte) ((SCE_GE_CMD_ZTE<<24) | (_zte))

#define SCE_GE_SET_STE(_ste) ((SCE_GE_CMD_STE<<24) | (_ste))

#define SCE_GE_SET_AAE(_aae) ((SCE_GE_CMD_AAE<<24) | (_aae))

#define SCE_GE_SET_PCE(_pce) ((SCE_GE_CMD_PCE<<24) | (_pce))

#define SCE_GE_SET_CTE(_cte) ((SCE_GE_CMD_CTE<<24) | (_cte))

#define SCE_GE_SET_LOE(_loe) ((SCE_GE_CMD_LOE<<24) | (_loe))

#define SCE_GE_SET_BONEN(_num) ((SCE_GE_CMD_BONEN<<24) | (_num))

#define SCE_GE_SET_BONED(_bone) ((SCE_GE_CMD_BONED<<24) | (_bone))
#define SCE_GE_SET_BONED_FLOAT24(_bone) ((SCE_GE_CMD_BONED<<24) | SCE_GE_EXTRACT_FLOAT24(_bone))

#define SCE_GE_SET_WEIGHT0(_weight0) ((SCE_GE_CMD_WEIGHT0<<24) | (_weight0))
#define SCE_GE_SET_WEIGHT0_FLOAT24(_wgt0) ((SCE_GE_CMD_WEIGHT0<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt0))

#define SCE_GE_SET_WEIGHT1(_weight1) ((SCE_GE_CMD_WEIGHT1<<24) | (_weight1))
#define SCE_GE_SET_WEIGHT1_FLOAT24(_wgt1) ((SCE_GE_CMD_WEIGHT1<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt1))

#define SCE_GE_SET_WEIGHT2(_weight2) ((SCE_GE_CMD_WEIGHT2<<24) | (_weight2))
#define SCE_GE_SET_WEIGHT2_FLOAT24(_wgt2) ((SCE_GE_CMD_WEIGHT2<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt2))

#define SCE_GE_SET_WEIGHT3(_weight3) ((SCE_GE_CMD_WEIGHT3<<24) | (_weight3))
#define SCE_GE_SET_WEIGHT3_FLOAT24(_wgt3) ((SCE_GE_CMD_WEIGHT3<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt3))

#define SCE_GE_SET_WEIGHT4(_weight4) ((SCE_GE_CMD_WEIGHT4<<24) | (_weight4))
#define SCE_GE_SET_WEIGHT4_FLOAT24(_wgt4) ((SCE_GE_CMD_WEIGHT4<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt4))

#define SCE_GE_SET_WEIGHT5(_weight5) ((SCE_GE_CMD_WEIGHT5<<24) | (_weight5))
#define SCE_GE_SET_WEIGHT5_FLOAT24(_wgt5) ((SCE_GE_CMD_WEIGHT5<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt5))

#define SCE_GE_SET_WEIGHT6(_weight6) ((SCE_GE_CMD_WEIGHT6<<24) | (_weight6))
#define SCE_GE_SET_WEIGHT6_FLOAT24(_wgt6) ((SCE_GE_CMD_WEIGHT6<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt6))

#define SCE_GE_SET_WEIGHT7(_weight7) ((SCE_GE_CMD_WEIGHT7<<24) | (_weight7))
#define SCE_GE_SET_WEIGHT7_FLOAT24(_wgt7) ((SCE_GE_CMD_WEIGHT7<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt7))

#define SCE_GE_SET_WEIGHTn(_n,_weight) (((SCE_GE_CMD_WEIGHT0+(_n))<<24) | (_weight))
#define SCE_GE_SET_WEIGHTn_FLOAT24(_n,_wgt) (((SCE_GE_CMD_WEIGHT0+(_n))<<24) | SCE_GE_EXTRACT_FLOAT24(_wgt))

#define SCE_GE_SET_DIVIDE(_udiv,_vdiv) ((SCE_GE_CMD_DIVIDE<<24) | ((_vdiv)<<8) | (_udiv))

#define SCE_GE_SET_PPM(_ppm) ((SCE_GE_CMD_PPM<<24) | (_ppm))
#define SCE_GE_PPM_TRIANGLE 0
#define SCE_GE_PPM_LINE 1
#define SCE_GE_PPM_POINT 2

#define SCE_GE_SET_PFACE(_pface) ((SCE_GE_CMD_PFACE<<24) | (_pface))
#define SCE_GE_PFACE_CLOCKWISE 0
#define SCE_GE_PFACE_COUNTERCLOCKWISE 1
#define SCE_GE_PFACE_CW SCE_GE_PFACE_CLOCKWISE
#define SCE_GE_PFACE_CCW SCE_GE_PFACE_COUNTERCLOCKWISE

#define SCE_GE_SET_WORLDN(_num) ((SCE_GE_CMD_WORLDN<<24) | (_num))

#define SCE_GE_SET_WORLDD(_world) ((SCE_GE_CMD_WORLDD<<24) | (_world))
#define SCE_GE_SET_WORLDD_FLOAT24(_world) ((SCE_GE_CMD_WORLDD<<24) | SCE_GE_EXTRACT_FLOAT24(_world))

#define SCE_GE_SET_VIEWN(_num) ((SCE_GE_CMD_VIEWN<<24) | (_num))

#define SCE_GE_SET_VIEWD(_view) ((SCE_GE_CMD_VIEWD<<24) | (_view))
#define SCE_GE_SET_VIEWD_FLOAT24(_view) ((SCE_GE_CMD_VIEWD<<24) | SCE_GE_EXTRACT_FLOAT24(_view))

#define SCE_GE_SET_PROJN(_num) ((SCE_GE_CMD_PROJN<<24) | (_num))

#define SCE_GE_SET_PROJD(_proj) ((SCE_GE_CMD_PROJD<<24) | (_proj))
#define SCE_GE_SET_PROJD_FLOAT24(_proj) ((SCE_GE_CMD_PROJD<<24) | SCE_GE_EXTRACT_FLOAT24(_proj))

#define SCE_GE_SET_TGENN(_num) ((SCE_GE_CMD_TGENN<<24) | (_num))

#define SCE_GE_SET_TGEND(_tgen) ((SCE_GE_CMD_TGEND<<24) | (_tgen))
#define SCE_GE_SET_TGEND_FLOAT24(_tgen) ((SCE_GE_CMD_TGEND<<24) | SCE_GE_EXTRACT_FLOAT24(_tgen))

#define SCE_GE_SET_SX(_sx) ((SCE_GE_CMD_SX<<24) | (_sx))
#define SCE_GE_SET_SX_FLOAT24(_sx) ((SCE_GE_CMD_SX<<24) | SCE_GE_EXTRACT_FLOAT24(_sx))

#define SCE_GE_SET_SY(_sy) ((SCE_GE_CMD_SY<<24) | (_sy))
#define SCE_GE_SET_SY_FLOAT24(_sy) ((SCE_GE_CMD_SY<<24) | SCE_GE_EXTRACT_FLOAT24(_sy))

#define SCE_GE_SET_SZ(_sz) ((SCE_GE_CMD_SZ<<24) | (_sz))
#define SCE_GE_SET_SZ_FLOAT24(_sz) ((SCE_GE_CMD_SZ<<24) | SCE_GE_EXTRACT_FLOAT24(_sz))

#define SCE_GE_SET_TX(_tx) ((SCE_GE_CMD_TX<<24) | (_tx))
#define SCE_GE_SET_TX_FLOAT24(_tx) ((SCE_GE_CMD_TX<<24) | SCE_GE_EXTRACT_FLOAT24(_tx))

#define SCE_GE_SET_TY(_ty) ((SCE_GE_CMD_TY<<24) | (_ty))
#define SCE_GE_SET_TY_FLOAT24(_ty) ((SCE_GE_CMD_TY<<24) | SCE_GE_EXTRACT_FLOAT24(_ty))

#define SCE_GE_SET_TZ(_tz) ((SCE_GE_CMD_TZ<<24) | (_tz))
#define SCE_GE_SET_TZ_FLOAT24(_tz) ((SCE_GE_CMD_TZ<<24) | SCE_GE_EXTRACT_FLOAT24(_tz))

#define SCE_GE_SET_SU(_su) ((SCE_GE_CMD_SU<<24) | (_su))
#define SCE_GE_SET_SU_FLOAT24(_su) ((SCE_GE_CMD_SU<<24) | SCE_GE_EXTRACT_FLOAT24(_su))

#define SCE_GE_SET_SV(_sv) ((SCE_GE_CMD_SV<<24) | (_sv))
#define SCE_GE_SET_SV_FLOAT24(_sv) ((SCE_GE_CMD_SV<<24) | SCE_GE_EXTRACT_FLOAT24(_sv))

#define SCE_GE_SET_TU(_tu) ((SCE_GE_CMD_TU<<24) | (_tu))
#define SCE_GE_SET_TU_FLOAT24(_tu) ((SCE_GE_CMD_TU<<24) | SCE_GE_EXTRACT_FLOAT24(_tu))

#define SCE_GE_SET_TV(_tv) ((SCE_GE_CMD_TV<<24) | (_tv))
#define SCE_GE_SET_TV_FLOAT24(_tv) ((SCE_GE_CMD_TV<<24) | SCE_GE_EXTRACT_FLOAT24(_tv))

#define SCE_GE_SET_OFFSETX(_offx) ((SCE_GE_CMD_OFFSETX<<24) | (_offx))

#define SCE_GE_SET_OFFSETY(_offy) ((SCE_GE_CMD_OFFSETY<<24) | (_offy))

#define SCE_GE_SET_SHADE(_iip) ((SCE_GE_CMD_SHADE<<24) | (_iip))
#define SCE_GE_SHADE_FLAT 0
#define SCE_GE_SHADE_GOURAUD 1

#define SCE_GE_SET_NREV(_nrev) ((SCE_GE_CMD_NREV<<24) | (_nrev))
#define SCE_GE_NREV_NORMAL 0
#define SCE_GE_NREV_REVERSE 1

#define SCE_GE_SET_MATERIAL(_ac,_dc,_sc) ((SCE_GE_CMD_MATERIAL<<24) | ((_sc)<<2) | ((_dc)<<1) | (_ac))
#define SCE_GE_MATERIAL_KEEP SCE_GE_KEEP
#define SCE_GE_MATERIAL_UPDATE SCE_GE_UPDATE

#define SCE_GE_SET_MEC(_r,_g,_b) ((SCE_GE_CMD_MEC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_MEC_RGB24(_rgb24) ((SCE_GE_CMD_MEC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_MAC(_r,_g,_b) ((SCE_GE_CMD_MAC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_MAC_RGB24(_rgb24) ((SCE_GE_CMD_MAC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_MDC(_r,_g,_b) ((SCE_GE_CMD_MDC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_MDC_RGB24(_rgb24) ((SCE_GE_CMD_MDC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_MSC(_r,_g,_b) ((SCE_GE_CMD_MSC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_MSC_RGB24(_rgb24) ((SCE_GE_CMD_MSC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_MAA(_a) ((SCE_GE_CMD_MAA<<24) | (_a))

#define SCE_GE_SET_MK(_k) ((SCE_GE_CMD_MK<<24) | (_k))
#define SCE_GE_SET_MK_FLOAT24(_k) ((SCE_GE_CMD_MK<<24) | SCE_GE_EXTRACT_FLOAT24(_k))

#define SCE_GE_SET_AC(_r,_g,_b) ((SCE_GE_CMD_AC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_AC_RGB24(_rgb24) ((SCE_GE_CMD_AC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_AA(_a) ((SCE_GE_CMD_AA<<24) | (_a))

#define SCE_GE_SET_LMODE(_ssc) ((SCE_GE_CMD_LMODE<<24) | (_ssc))
#define SCE_GE_LMODE_SINGLE_COLOR 0
#define SCE_GE_LMODE_SEPARATE_SPECULAR_COLOR 1

#define SCE_GE_SET_LTYPE0(_comp,_type) ((SCE_GE_CMD_LTYPE0<<24) | ((_type)<<8) | (_comp))

#define SCE_GE_SET_LTYPE1(_comp,_type) ((SCE_GE_CMD_LTYPE1<<24) | ((_type)<<8) | (_comp))

#define SCE_GE_SET_LTYPE2(_comp,_type) ((SCE_GE_CMD_LTYPE2<<24) | ((_type)<<8) | (_comp))

#define SCE_GE_SET_LTYPE3(_comp,_type) ((SCE_GE_CMD_LTYPE3<<24) | ((_type)<<8) | (_comp))

#define SCE_GE_SET_LTYPEn(_n,_comp,_type) (((SCE_GE_CMD_LTYPE0+(_n))<<24) | ((_type)<<8) | (_comp))

#define SCE_GE_LTYPE_DIRECTION 0
#define SCE_GE_LTYPE_POINT 1
#define SCE_GE_LTYPE_SPOT 2
#define SCE_GE_LTYPE_PARALLEL SCE_GE_LTYPE_DIRECTION
#define SCE_GE_LTYPE_DIFFUSE 0
#define SCE_GE_LTYPE_DIFFUSE_AND_SPECULAR 1
#define SCE_GE_LTYPE_POWERED_DIFFUSE_AND_SPECULAR 2

#define SCE_GE_SET_LX0(_lx) ((SCE_GE_CMD_LX0<<24) | (_lx))
#define SCE_GE_SET_LX0_FLOAT24(_lx) ((SCE_GE_CMD_LX0<<24) | SCE_GE_EXTRACT_FLOAT24(_lx))

#define SCE_GE_SET_LY0(_ly) ((SCE_GE_CMD_LY0<<24) | (_ly))
#define SCE_GE_SET_LY0_FLOAT24(_ly) ((SCE_GE_CMD_LY0<<24) | SCE_GE_EXTRACT_FLOAT24(_ly))

#define SCE_GE_SET_LZ0(_lz) ((SCE_GE_CMD_LZ0<<24) | (_lz))
#define SCE_GE_SET_LZ0_FLOAT24(_lz) ((SCE_GE_CMD_LZ0<<24) | SCE_GE_EXTRACT_FLOAT24(_lz))

#define SCE_GE_SET_LX1(_lx) ((SCE_GE_CMD_LX1<<24) | (_lx))
#define SCE_GE_SET_LX1_FLOAT24(_lx) ((SCE_GE_CMD_LX1<<24) | SCE_GE_EXTRACT_FLOAT24(_lx))

#define SCE_GE_SET_LY1(_ly) ((SCE_GE_CMD_LY1<<24) | (_ly))
#define SCE_GE_SET_LY1_FLOAT24(_ly) ((SCE_GE_CMD_LY1<<24) | SCE_GE_EXTRACT_FLOAT24(_ly))

#define SCE_GE_SET_LZ1(_lz) ((SCE_GE_CMD_LZ1<<24) | (_lz))
#define SCE_GE_SET_LZ1_FLOAT24(_lz) ((SCE_GE_CMD_LZ1<<24) | SCE_GE_EXTRACT_FLOAT24(_lz))

#define SCE_GE_SET_LX2(_lx) ((SCE_GE_CMD_LX2<<24) | (_lx))
#define SCE_GE_SET_LX2_FLOAT24(_lx) ((SCE_GE_CMD_LX2<<24) | SCE_GE_EXTRACT_FLOAT24(_lx))

#define SCE_GE_SET_LY2(_ly) ((SCE_GE_CMD_LY2<<24) | (_ly))
#define SCE_GE_SET_LY2_FLOAT24(_ly) ((SCE_GE_CMD_LY2<<24) | SCE_GE_EXTRACT_FLOAT24(_ly))

#define SCE_GE_SET_LZ2(_lz) ((SCE_GE_CMD_LZ2<<24) | (_lz))
#define SCE_GE_SET_LZ2_FLOAT24(_lz) ((SCE_GE_CMD_LZ2<<24) | SCE_GE_EXTRACT_FLOAT24(_lz))

#define SCE_GE_SET_LX3(_lx) ((SCE_GE_CMD_LX3<<24) | (_lx))
#define SCE_GE_SET_LX3_FLOAT24(_lx) ((SCE_GE_CMD_LX3<<24) | SCE_GE_EXTRACT_FLOAT24(_lx))

#define SCE_GE_SET_LY3(_ly) ((SCE_GE_CMD_LY3<<24) | (_ly))
#define SCE_GE_SET_LY3_FLOAT24(_ly) ((SCE_GE_CMD_LY3<<24) | SCE_GE_EXTRACT_FLOAT24(_ly))

#define SCE_GE_SET_LZ3(_lz) ((SCE_GE_CMD_LZ3<<24) | (_lz))
#define SCE_GE_SET_LZ3_FLOAT24(_lz) ((SCE_GE_CMD_LZ3<<24) | SCE_GE_EXTRACT_FLOAT24(_lz))

#define SCE_GE_SET_LXn(_n,_lx) (((SCE_GE_CMD_LX0+(_n)*3)<<24) | (_lx))
#define SCE_GE_SET_LYn(_n,_ly) (((SCE_GE_CMD_LY0+(_n)*3)<<24) | (_ly))
#define SCE_GE_SET_LZn(_n,_lz) (((SCE_GE_CMD_LZ0+(_n)*3)<<24) | (_lz))
#define SCE_GE_SET_LXn_FLOAT24(_n,_lx) (((SCE_GE_CMD_LX0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_lx))
#define SCE_GE_SET_LYn_FLOAT24(_n,_ly) (((SCE_GE_CMD_LY0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_ly))
#define SCE_GE_SET_LZn_FLOAT24(_n,_lz) (((SCE_GE_CMD_LZ0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_lz))

#define SCE_GE_SET_LDX0(_ldx) ((SCE_GE_CMD_LDX0<<24) | (_ldx))
#define SCE_GE_SET_LDX0_FLOAT24(_ldx) ((SCE_GE_CMD_LDX0<<24) | SCE_GE_EXTRACT_FLOAT24(_ldx))

#define SCE_GE_SET_LDY0(_ldy) ((SCE_GE_CMD_LDY0<<24) | (_ldy))
#define SCE_GE_SET_LDY0_FLOAT24(_ldy) ((SCE_GE_CMD_LDY0<<24) | SCE_GE_EXTRACT_FLOAT24(_ldy))

#define SCE_GE_SET_LDZ0(_ldz) ((SCE_GE_CMD_LDZ0<<24) | (_ldz))
#define SCE_GE_SET_LDZ0_FLOAT24(_ldz) ((SCE_GE_CMD_LDZ0<<24) | SCE_GE_EXTRACT_FLOAT24(_ldz))

#define SCE_GE_SET_LDX1(_ldx) ((SCE_GE_CMD_LDX1<<24) | (_ldx))
#define SCE_GE_SET_LDX1_FLOAT24(_ldx) ((SCE_GE_CMD_LDX1<<24) | SCE_GE_EXTRACT_FLOAT24(_ldx))

#define SCE_GE_SET_LDY1(_ldy) ((SCE_GE_CMD_LDY1<<24) | (_ldy))
#define SCE_GE_SET_LDY1_FLOAT24(_ldy) ((SCE_GE_CMD_LDY1<<24) | SCE_GE_EXTRACT_FLOAT24(_ldy))

#define SCE_GE_SET_LDZ1(_ldz) ((SCE_GE_CMD_LDZ1<<24) | (_ldz))
#define SCE_GE_SET_LDZ1_FLOAT24(_ldz) ((SCE_GE_CMD_LDZ1<<24) | SCE_GE_EXTRACT_FLOAT24(_ldz))

#define SCE_GE_SET_LDX2(_ldx) ((SCE_GE_CMD_LDX2<<24) | (_ldx))
#define SCE_GE_SET_LDX2_FLOAT24(_ldx) ((SCE_GE_CMD_LDX2<<24) | SCE_GE_EXTRACT_FLOAT24(_ldx))

#define SCE_GE_SET_LDY2(_ldy) ((SCE_GE_CMD_LDY2<<24) | (_ldy))
#define SCE_GE_SET_LDY2_FLOAT24(_ldy) ((SCE_GE_CMD_LDY2<<24) | SCE_GE_EXTRACT_FLOAT24(_ldy))

#define SCE_GE_SET_LDZ2(_ldz) ((SCE_GE_CMD_LDZ2<<24) | (_ldz))
#define SCE_GE_SET_LDZ2_FLOAT24(_ldz) ((SCE_GE_CMD_LDZ2<<24) | SCE_GE_EXTRACT_FLOAT24(_ldz))

#define SCE_GE_SET_LDX3(_ldx) ((SCE_GE_CMD_LDX3<<24) | (_ldx))
#define SCE_GE_SET_LDX3_FLOAT24(_ldx) ((SCE_GE_CMD_LDX3<<24) | SCE_GE_EXTRACT_FLOAT24(_ldx))

#define SCE_GE_SET_LDY3(_ldy) ((SCE_GE_CMD_LDY3<<24) | (_ldy))
#define SCE_GE_SET_LDY3_FLOAT24(_ldy) ((SCE_GE_CMD_LDY3<<24) | SCE_GE_EXTRACT_FLOAT24(_ldy))

#define SCE_GE_SET_LDZ3(_ldz) ((SCE_GE_CMD_LDZ3<<24) | (_ldz))
#define SCE_GE_SET_LDZ3_FLOAT24(_ldz) ((SCE_GE_CMD_LDZ3<<24) | SCE_GE_EXTRACT_FLOAT24(_ldz))

#define SCE_GE_SET_LDXn(_n,_ldx) (((SCE_GE_CMD_LDX0+(_n)*3)<<24) | (_ldx))
#define SCE_GE_SET_LDYn(_n,_ldy) (((SCE_GE_CMD_LDY0+(_n)*3)<<24) | (_ldy))
#define SCE_GE_SET_LDZn(_n,_ldz) (((SCE_GE_CMD_LDZ0+(_n)*3)<<24) | (_ldz))
#define SCE_GE_SET_LDXn_FLOAT24(_n,_ldx) (((SCE_GE_CMD_LDX0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_ldx))
#define SCE_GE_SET_LDYn_FLOAT24(_n,_ldy) (((SCE_GE_CMD_LDY0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_ldy))
#define SCE_GE_SET_LDZn_FLOAT24(_n,_ldz) (((SCE_GE_CMD_LDZ0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_ldz))

#define SCE_GE_SET_LKA0(_lka) ((SCE_GE_CMD_LKA0<<24) | (_lka))
#define SCE_GE_SET_LKA0_FLOAT24(_lka) ((SCE_GE_CMD_LKA0<<24) | SCE_GE_EXTRACT_FLOAT24(_lka))

#define SCE_GE_SET_LKB0(_lkb) ((SCE_GE_CMD_LKB0<<24) | (_lkb))
#define SCE_GE_SET_LKB0_FLOAT24(_lkb) ((SCE_GE_CMD_LKB0<<24) | SCE_GE_EXTRACT_FLOAT24(_lkb))

#define SCE_GE_SET_LKC0(_lkc) ((SCE_GE_CMD_LKC0<<24) | (_lkc))
#define SCE_GE_SET_LKC0_FLOAT24(_lkc) ((SCE_GE_CMD_LKC0<<24) | SCE_GE_EXTRACT_FLOAT24(_lkc))

#define SCE_GE_SET_LKA1(_lka) ((SCE_GE_CMD_LKA1<<24) | (_lka))
#define SCE_GE_SET_LKA1_FLOAT24(_lka) ((SCE_GE_CMD_LKA1<<24) | SCE_GE_EXTRACT_FLOAT24(_lka))

#define SCE_GE_SET_LKB1(_lkb) ((SCE_GE_CMD_LKB1<<24) | (_lkb))
#define SCE_GE_SET_LKB1_FLOAT24(_lkb) ((SCE_GE_CMD_LKB1<<24) | SCE_GE_EXTRACT_FLOAT24(_lkb))

#define SCE_GE_SET_LKC1(_lkc) ((SCE_GE_CMD_LKC1<<24) | (_lkc))
#define SCE_GE_SET_LKC1_FLOAT24(_lkc) ((SCE_GE_CMD_LKC1<<24) | SCE_GE_EXTRACT_FLOAT24(_lkc))

#define SCE_GE_SET_LKA2(_lka) ((SCE_GE_CMD_LKA2<<24) | (_lka))
#define SCE_GE_SET_LKA2_FLOAT24(_lka) ((SCE_GE_CMD_LKA2<<24) | SCE_GE_EXTRACT_FLOAT24(_lka))

#define SCE_GE_SET_LKB2(_lkb) ((SCE_GE_CMD_LKB2<<24) | (_lkb))
#define SCE_GE_SET_LKB2_FLOAT24(_lkb) ((SCE_GE_CMD_LKB2<<24) | SCE_GE_EXTRACT_FLOAT24(_lkb))

#define SCE_GE_SET_LKC2(_lkc) ((SCE_GE_CMD_LKC2<<24) | (_lkc))
#define SCE_GE_SET_LKC2_FLOAT24(_lkc) ((SCE_GE_CMD_LKC2<<24) | SCE_GE_EXTRACT_FLOAT24(_lkc))

#define SCE_GE_SET_LKA3(_lka) ((SCE_GE_CMD_LKA3<<24) | (_lka))
#define SCE_GE_SET_LKA3_FLOAT24(_lka) ((SCE_GE_CMD_LKA3<<24) | SCE_GE_EXTRACT_FLOAT24(_lka))

#define SCE_GE_SET_LKB3(_lkb) ((SCE_GE_CMD_LKB3<<24) | (_lkb))
#define SCE_GE_SET_LKB3_FLOAT24(_lkb) ((SCE_GE_CMD_LKB3<<24) | SCE_GE_EXTRACT_FLOAT24(_lkb))

#define SCE_GE_SET_LKC3(_lkc) ((SCE_GE_CMD_LKC3<<24) | (_lkc))
#define SCE_GE_SET_LKC3_FLOAT24(_lkc) ((SCE_GE_CMD_LKC3<<24) | SCE_GE_EXTRACT_FLOAT24(_lkc))

#define SCE_GE_SET_LKAn(_n,_lka) (((SCE_GE_CMD_LKA0+(_n)*3)<<24) | (_lka))
#define SCE_GE_SET_LKBn(_n,_lkb) (((SCE_GE_CMD_LKB0+(_n)*3)<<24) | (_lkb))
#define SCE_GE_SET_LKCn(_n,_lkc) (((SCE_GE_CMD_LKC0+(_n)*3)<<24) | (_lkc))
#define SCE_GE_SET_LKAn_FLOAT24(_n,_lka) (((SCE_GE_CMD_LKA0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_lka))
#define SCE_GE_SET_LKBn_FLOAT24(_n,_lkb) (((SCE_GE_CMD_LKB0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_lkb))
#define SCE_GE_SET_LKCn_FLOAT24(_n,_lkc) (((SCE_GE_CMD_LKC0+(_n)*3)<<24) | SCE_GE_EXTRACT_FLOAT24(_lkc))

#define SCE_GE_SET_LKS0(_lks) ((SCE_GE_CMD_LKS0<<24) | (_lks))
#define SCE_GE_SET_LKS0_FLOAT24(_lks) ((SCE_GE_CMD_LKS0<<24) | SCE_GE_EXTRACT_FLOAT24(_lks))

#define SCE_GE_SET_LKS1(_lks) ((SCE_GE_CMD_LKS1<<24) | (_lks))
#define SCE_GE_SET_LKS1_FLOAT24(_lks) ((SCE_GE_CMD_LKS1<<24) | SCE_GE_EXTRACT_FLOAT24(_lks))

#define SCE_GE_SET_LKS2(_lks) ((SCE_GE_CMD_LKS2<<24) | (_lks))
#define SCE_GE_SET_LKS2_FLOAT24(_lks) ((SCE_GE_CMD_LKS2<<24) | SCE_GE_EXTRACT_FLOAT24(_lks))

#define SCE_GE_SET_LKS3(_lks) ((SCE_GE_CMD_LKS3<<24) | (_lks))
#define SCE_GE_SET_LKS3_FLOAT24(_lks) ((SCE_GE_CMD_LKS3<<24) | SCE_GE_EXTRACT_FLOAT24(_lks))

#define SCE_GE_SET_LKSn(_n,_lks) (((SCE_GE_CMD_LKS0+(_n))<<24) | (_lks))
#define SCE_GE_SET_LKSn_FLOAT24(_n,_lks) (((SCE_GE_CMD_LKS0+(_n))<<24) | SCE_GE_EXTRACT_FLOAT24(_lks))

#define SCE_GE_SET_LKO0(_lko) ((SCE_GE_CMD_LKO0<<24) | (_lko))
#define SCE_GE_SET_LKO0_FLOAT24(_lko) ((SCE_GE_CMD_LKO0<<24) | SCE_GE_EXTRACT_FLOAT24(_lko))

#define SCE_GE_SET_LKO1(_lko) ((SCE_GE_CMD_LKO1<<24) | (_lko))
#define SCE_GE_SET_LKO1_FLOAT24(_lko) ((SCE_GE_CMD_LKO1<<24) | SCE_GE_EXTRACT_FLOAT24(_lko))

#define SCE_GE_SET_LKO2(_lko) ((SCE_GE_CMD_LKO2<<24) | (_lko))
#define SCE_GE_SET_LKO2_FLOAT24(_lko) ((SCE_GE_CMD_LKO2<<24) | SCE_GE_EXTRACT_FLOAT24(_lko))

#define SCE_GE_SET_LKO3(_lko) ((SCE_GE_CMD_LKO3<<24) | (_lko))
#define SCE_GE_SET_LKO3_FLOAT24(_lko) ((SCE_GE_CMD_LKO3<<24) | SCE_GE_EXTRACT_FLOAT24(_lko))

#define SCE_GE_SET_LKOn(_n,_lko) (((SCE_GE_CMD_LKO0+(_n))<<24) | (_lko))
#define SCE_GE_SET_LKOn_FLOAT24(_n,_lko) (((SCE_GE_CMD_LKO0+(_n))<<24) | SCE_GE_EXTRACT_FLOAT24(_lko))

#define SCE_GE_SET_LAC0(_r,_g,_b) ((SCE_GE_CMD_LAC0<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LAC0_RGB24(_rgb24) ((SCE_GE_CMD_LAC0<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LDC0(_r,_g,_b) ((SCE_GE_CMD_LDC0<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LDC0_RGB24(_rgb24) ((SCE_GE_CMD_LDC0<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LSC0(_r,_g,_b) ((SCE_GE_CMD_LSC0<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LSC0_RGB24(_rgb24) ((SCE_GE_CMD_LSC0<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LAC1(_r,_g,_b) ((SCE_GE_CMD_LAC1<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LAC1_RGB24(_rgb24) ((SCE_GE_CMD_LAC1<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LDC1(_r,_g,_b) ((SCE_GE_CMD_LDC1<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LDC1_RGB24(_rgb24) ((SCE_GE_CMD_LDC1<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LSC1(_r,_g,_b) ((SCE_GE_CMD_LSC1<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LSC1_RGB24(_rgb24) ((SCE_GE_CMD_LSC1<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LAC2(_r,_g,_b) ((SCE_GE_CMD_LAC2<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LAC2_RGB24(_rgb24) ((SCE_GE_CMD_LAC2<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LDC2(_r,_g,_b) ((SCE_GE_CMD_LDC2<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LDC2_RGB24(_rgb24) ((SCE_GE_CMD_LDC2<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LSC2(_r,_g,_b) ((SCE_GE_CMD_LSC2<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LSC2_RGB24(_rgb24) ((SCE_GE_CMD_LSC2<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LAC3(_r,_g,_b) ((SCE_GE_CMD_LAC3<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LAC3_RGB24(_rgb24) ((SCE_GE_CMD_LAC3<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LDC3(_r,_g,_b) ((SCE_GE_CMD_LDC3<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LDC3_RGB24(_rgb24) ((SCE_GE_CMD_LDC3<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LSC3(_r,_g,_b) ((SCE_GE_CMD_LSC3<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LSC3_RGB24(_rgb24) ((SCE_GE_CMD_LSC3<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_LACn(_n,_r,_g,_b) (((SCE_GE_CMD_LAC0+(_n)*3)<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LDCn(_n,_r,_g,_b) (((SCE_GE_CMD_LDC0+(_n)*3)<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LSCn(_n,_r,_g,_b) (((SCE_GE_CMD_LSC0+(_n)*3)<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_LACn_RGB24(_n,_rgb24) (((SCE_GE_CMD_LAC0+(_n)*3)<<24) | ((_rgb24) & 0x00FFFFFF))
#define SCE_GE_SET_LDCn_RGB24(_n,_rgb24) (((SCE_GE_CMD_LDC0+(_n)*3)<<24) | ((_rgb24) & 0x00FFFFFF))
#define SCE_GE_SET_LSCn_RGB24(_n,_rgb24) (((SCE_GE_CMD_LSC0+(_n)*3)<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_CULL(_cis) ((SCE_GE_CMD_CULL<<24) | (_cis))
#define SCE_GE_CULL_COUNTERCLOCKWISE 0
#define SCE_GE_CULL_CLOCKWISE 1
#define SCE_GE_CULL_CCW SCE_GE_CULL_COUNTERCLOCKWISE
#define SCE_GE_CULL_CW SCE_GE_CULL_CLOCKWISE

#define SCE_GE_SET_FBP(_fbp) ((SCE_GE_CMD_FBP<<24) | ((_fbp) & 0x00FFFFFF))
#define SCE_GE_SET_FBP_ADDR24(_fbp32) ((SCE_GE_CMD_FBP<<24) | SCE_GE_EXTRACT_ADDR24(_fbp32))

#define SCE_GE_SET_FBW(_fbw,_base) ((SCE_GE_CMD_FBW<<24) | (((_base) & 0xFF)<<16) | (_fbw))
#define SCE_GE_SET_FBW_BASE8(_fbw,_base32) ((SCE_GE_CMD_FBW<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_fbw))

#define SCE_GE_SET_ZBP(_zbp) ((SCE_GE_CMD_ZBP<<24) | ((_zbp) & 0x00FFFFFF))
#define SCE_GE_SET_ZBP_ADDR24(_zbp32) ((SCE_GE_CMD_ZBP<<24) | SCE_GE_EXTRACT_ADDR24(_zbp32))

#define SCE_GE_SET_ZBW(_zbw,_base) ((SCE_GE_CMD_ZBW<<24) | (((_base) & 0xFF)<<16) | (_zbw))
#define SCE_GE_SET_ZBW_BASE8(_zbw,_base32) ((SCE_GE_CMD_ZBW<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_zbw))

#define SCE_GE_SET_TBP0(_tbp) ((SCE_GE_CMD_TBP0<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP0_ADDR24(_tbp32) ((SCE_GE_CMD_TBP0<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP1(_tbp) ((SCE_GE_CMD_TBP1<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP1_ADDR24(_tbp32) ((SCE_GE_CMD_TBP1<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP2(_tbp) ((SCE_GE_CMD_TBP2<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP2_ADDR24(_tbp32) ((SCE_GE_CMD_TBP2<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP3(_tbp) ((SCE_GE_CMD_TBP3<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP3_ADDR24(_tbp32) ((SCE_GE_CMD_TBP3<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP4(_tbp) ((SCE_GE_CMD_TBP4<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP4_ADDR24(_tbp32) ((SCE_GE_CMD_TBP4<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP5(_tbp) ((SCE_GE_CMD_TBP5<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP5_ADDR24(_tbp32) ((SCE_GE_CMD_TBP5<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP6(_tbp) ((SCE_GE_CMD_TBP6<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP6_ADDR24(_tbp32) ((SCE_GE_CMD_TBP6<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBP7(_tbp) ((SCE_GE_CMD_TBP7<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBP7_ADDR24(_tbp32) ((SCE_GE_CMD_TBP7<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBPn(_n,_tbp) (((SCE_GE_CMD_TBP0+(_n))<<24) | ((_tbp) & 0x00FFFFFF))
#define SCE_GE_SET_TBPn_ADDR24(_n,_tbp32) (((SCE_GE_CMD_TBP0+(_n))<<24) | SCE_GE_EXTRACT_ADDR24(_tbp32))

#define SCE_GE_SET_TBW0(_tbw,_base) ((SCE_GE_CMD_TBW0<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW0_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW0<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW1(_tbw,_base) ((SCE_GE_CMD_TBW1<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW1_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW1<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW2(_tbw,_base) ((SCE_GE_CMD_TBW2<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW2_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW2<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW3(_tbw,_base) ((SCE_GE_CMD_TBW3<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW3_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW3<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW4(_tbw,_base) ((SCE_GE_CMD_TBW4<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW4_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW4<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW5(_tbw,_base) ((SCE_GE_CMD_TBW5<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW5_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW5<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW6(_tbw,_base) ((SCE_GE_CMD_TBW6<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW6_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW6<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBW7(_tbw,_base) ((SCE_GE_CMD_TBW7<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBW7_BASE8(_tbw,_base32) ((SCE_GE_CMD_TBW7<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_TBWn(_n,_tbw,_base) (((SCE_GE_CMD_TBW0+(_n))<<24) | (((_base) & 0xFF)<<16) | (_tbw))
#define SCE_GE_SET_TBWn_BASE8(_n,_tbw,_base32) (((SCE_GE_CMD_TBW0+(_n))<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_tbw))

#define SCE_GE_SET_CBP(_cbp) ((SCE_GE_CMD_CBP<<24) | ((_cbp) & 0x00FFFFFF))
#define SCE_GE_SET_CBP_ADDR24(_cbp32) ((SCE_GE_CMD_CBP<<24) | SCE_GE_EXTRACT_ADDR24(_cbp32))

#define SCE_GE_SET_CBW(_base) ((SCE_GE_CMD_CBW<<24) | (((_base) & 0xFF)<<16))
#define SCE_GE_SET_CBW_BASE8(_base32) ((SCE_GE_CMD_CBW<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16))

#define SCE_GE_SET_XBP1(_xbp) ((SCE_GE_CMD_XBP1<<24) | ((_xbp) & 0x00FFFFFF))
#define SCE_GE_SET_XBP1_ADDR24(_xbp32) ((SCE_GE_CMD_XBP1<<24) | SCE_GE_EXTRACT_ADDR24(_xbp32))

#define SCE_GE_SET_XBW1(_xbw,_base) ((SCE_GE_CMD_XBW1<<24) | (((_base) & 0xFF)<<16) | (_xbw))
#define SCE_GE_SET_XBW1_BASE8(_xbw,_base32) ((SCE_GE_CMD_XBW1<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_xbw))

#define SCE_GE_SET_XBP2(_xbp) ((SCE_GE_CMD_XBP2<<24) | ((_xbp) & 0x00FFFFFF))
#define SCE_GE_SET_XBP2_ADDR24(_xbp32) ((SCE_GE_CMD_XBP2<<24) | SCE_GE_EXTRACT_ADDR24(_xbp32))

#define SCE_GE_SET_XBW2(_xbw,_base) ((SCE_GE_CMD_XBW2<<24) | (((_base) & 0xFF)<<16) | (_xbw))
#define SCE_GE_SET_XBW2_BASE8(_xbw,_base32) ((SCE_GE_CMD_XBW2<<24) | (SCE_GE_EXTRACT_BASE8(_base32)<<16) | (_xbw))

#define SCE_GE_SET_TSIZE0(_tw,_th) ((SCE_GE_CMD_TSIZE0<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE1(_tw,_th) ((SCE_GE_CMD_TSIZE1<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE2(_tw,_th) ((SCE_GE_CMD_TSIZE2<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE3(_tw,_th) ((SCE_GE_CMD_TSIZE3<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE4(_tw,_th) ((SCE_GE_CMD_TSIZE4<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE5(_tw,_th) ((SCE_GE_CMD_TSIZE5<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE6(_tw,_th) ((SCE_GE_CMD_TSIZE6<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZE7(_tw,_th) ((SCE_GE_CMD_TSIZE7<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TSIZEn(_n,_tw,_th) (((SCE_GE_CMD_TSIZE0+(_n))<<24) | ((_th)<<8) | (_tw))

#define SCE_GE_SET_TMAP(_tmn,_tmi) ((SCE_GE_CMD_TMAP<<24) | ((_tmi)<<8) | (_tmn))
#define SCE_GE_TMAP_TMN_UV 0
#define SCE_GE_TMAP_TMN_PROJECTION 1
#define SCE_GE_TMAP_TMN_SHADE 2
#define SCE_GE_TMAP_TMI_XYZ 0
#define SCE_GE_TMAP_TMI_UV 1
#define SCE_GE_TMAP_TMI_NORMALIZED_NORMAL 2
#define SCE_GE_TMAP_TMI_NORMAL 3

#define SCE_GE_SET_TSHADE(_u,_v) ((SCE_GE_CMD_TSHADE<<24) | ((_v)<<8) | (_u))

#define SCE_GE_SET_TMODE(_hsm,_mc,_mxl) ((SCE_GE_CMD_TMODE<<24) | ((_mxl)<<16) | ((_mc)<<8) | ((_hsm)))
#define SCE_GE_TMODE_HSM_NORMAL 0
#define SCE_GE_TMODE_HSM_HIGHSPEED 1

#define SCE_GE_SET_TPF(_tpf,_ext) ((SCE_GE_CMD_TPF<<24) | ((_ext)<<8) | (_tpf))
#define SCE_GE_TPF_5650 0
#define SCE_GE_TPF_5551 1
#define SCE_GE_TPF_4444 2
#define SCE_GE_TPF_8888 3
#define SCE_GE_TPF_IDTEX4 4
#define SCE_GE_TPF_IDTEX8 5
#define SCE_GE_TPF_IDTEX16 6
#define SCE_GE_TPF_IDTEX32 7
#define SCE_GE_TPF_DXT1 8
#define SCE_GE_TPF_DXT3 9
#define SCE_GE_TPF_DXT5 10

#define SCE_GE_SET_CLOAD(_np) ((SCE_GE_CMD_CLOAD<<24) | (_np))

#define SCE_GE_SET_CLUT(_cpf,_sft,_msk,_csa) ((SCE_GE_CMD_CLUT<<24) | ((_csa)<<16) | ((_msk)<<8) | ((_sft)<<2) | (_cpf))

#define SCE_GE_CLUT_CPF_5650 0
#define SCE_GE_CLUT_CPF_5551 1
#define SCE_GE_CLUT_CPF_4444 2
#define SCE_GE_CLUT_CPF_8888 3

#define SCE_GE_SET_TFILTER(_min,_mag) ((SCE_GE_CMD_TFILTER<<24) | ((_mag)<<8) | (_min))
#define SCE_GE_TFILTER_NEAREST 0
#define SCE_GE_TFILTER_LINEAR 1
#define SCE_GE_TFILTER_NEAREST_MIPMAP_NEAREST 4
#define SCE_GE_TFILTER_LINEAR_MIPMAP_NEAREST 5
#define SCE_GE_TFILTER_NEAREST_MIPMAP_LINEAR 6
#define SCE_GE_TFILTER_LINEAR_MIPMAP_LINEAR 7

#define SCE_GE_SET_TWRAP(_wms,_wmt) ((SCE_GE_CMD_TWRAP<<24) | ((_wmt)<<8) | (_wms))
#define SCE_GE_TWRAP_REPEAT 0
#define SCE_GE_TWRAP_CLAMP 1

#define SCE_GE_SET_TLEVEL(_lcm,_offl) ((SCE_GE_CMD_TLEVEL<<24) | ((_offl)<<16) | (_lcm))
#define SCE_GE_TLEVEL_AUTO 0
#define SCE_GE_TLEVEL_CONSTANT 1
#define SCE_GE_TLEVEL_SLOPE 2
#define SCE_GE_TLEVEL_VARIABLE1 SCE_GE_TLEVEL_AUTO
#define SCE_GE_TLEVEL_FIX SCE_GE_TLEVEL_CONSTANT
#define SCE_GE_TLEVEL_VARIABLE2 SCE_GE_TLEVEL_SLOPE

#define SCE_GE_SET_TFUNC(_txf,_tcc,_cd) ((SCE_GE_CMD_TFUNC<<24) | ((_cd)<<16) | ((_tcc)<<8) | (_txf))
#define SCE_GE_TFUNC_MODULATE 0
#define SCE_GE_TFUNC_DECAL 1
#define SCE_GE_TFUNC_BLEND 2
#define SCE_GE_TFUNC_REPLACE 3
#define SCE_GE_TFUNC_ADD 4
#define SCE_GE_TFUNC_RGB 0
#define SCE_GE_TFUNC_RGBA 1

#define SCE_GE_SET_TEC(_r,_g,_b) ((SCE_GE_CMD_TEC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_TEC_RGB24(_rgb24) ((SCE_GE_CMD_TEC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_TFLUSH() (SCE_GE_CMD_TFLUSH<<24)

#define SCE_GE_SET_TSYNC() (SCE_GE_CMD_TSYNC<<24)

#define SCE_GE_SET_FOG1(_fog1) ((SCE_GE_CMD_FOG1<<24) | (_fog1))
#define SCE_GE_SET_FOG1_FLOAT24(_fog1) ((SCE_GE_CMD_FOG1<<24) | SCE_GE_EXTRACT_FLOAT24(_fog1))

#define SCE_GE_SET_FOG2(_fog2) ((SCE_GE_CMD_FOG2<<24) | (_fog2))
#define SCE_GE_SET_FOG2_FLOAT24(_fog2) ((SCE_GE_CMD_FOG2<<24) | SCE_GE_EXTRACT_FLOAT24(_fog2))

#define SCE_GE_SET_FC(_r,_g,_b) ((SCE_GE_CMD_FC<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_FC_RGB24(_rgb24) ((SCE_GE_CMD_FC<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_TSLOPE(_tslope) ((SCE_GE_CMD_TSLOPE<<24) | (_tslope))
#define SCE_GE_SET_TSLOPE_FLOAT24(_tslope) ((SCE_GE_CMD_TSLOPE<<24) | SCE_GE_EXTRACT_FLOAT24(_tslope))

#define SCE_GE_SET_FPF(_fpf) ((SCE_GE_CMD_FPF<<24) | (_fpf))
#define SCE_GE_FPF_5650 0
#define SCE_GE_FPF_5551 1
#define SCE_GE_FPF_4444 2
#define SCE_GE_FPF_8888 3

#define SCE_GE_SET_CMODE(_set,_cen,_aen,_zen) ((SCE_GE_CMD_CMODE<<24) | ((_zen)<<10) | ((_aen)<<9) | ((_cen)<<8) | (_set))

#define SCE_GE_CMODE_NORMAL 0
#define SCE_GE_CMODE_CLEAR 1
#define SCE_GE_CMODE_KEEP 0
#define SCE_GE_CMODE_UPDATE 1

#define SCE_GE_SET_SCISSOR1(_sx1,_sy1) ((SCE_GE_CMD_SCISSOR1<<24) | ((_sy1)<<10) | (_sx1))

#define SCE_GE_SET_SCISSOR2(_sx2,_sy2) ((SCE_GE_CMD_SCISSOR2<<24) | ((_sy2)<<10) | (_sx2))

#define SCE_GE_SET_MINZ(_minz) ((SCE_GE_CMD_MINZ<<24) | (_minz))

#define SCE_GE_SET_MAXZ(_maxz) ((SCE_GE_CMD_MAXZ<<24) | (_maxz))

#define SCE_GE_SET_CTEST(_ctf) ((SCE_GE_CMD_CTEST<<24) | (_ctf))
#define SCE_GE_CTEST_NEVER 0
#define SCE_GE_CTEST_ALWAYS 1
#define SCE_GE_CTEST_EQUAL 2
#define SCE_GE_CTEST_NOTEQUAL 3

#define SCE_GE_SET_CREF(_r,_g,_b) ((SCE_GE_CMD_CREF<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_CREF_RGB24(_rgb24) ((SCE_GE_CMD_CREF<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_CMSK(_r,_g,_b) ((SCE_GE_CMD_CMSK<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_CMSK_RGB24(_rgb24) ((SCE_GE_CMD_CMSK<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_ATEST(_atf,_aref,_amsk) ((SCE_GE_CMD_ATEST<<24) | ((_amsk)<<16) | ((_aref)<<8) | (_atf))
#define SCE_GE_ATEST_NEVER 0
#define SCE_GE_ATEST_ALWAYS 1
#define SCE_GE_ATEST_EQUAL 2
#define SCE_GE_ATEST_NOTEQUAL 3
#define SCE_GE_ATEST_LESS 4
#define SCE_GE_ATEST_LEQUAL 5
#define SCE_GE_ATEST_GREATER 6
#define SCE_GE_ATEST_GEQUAL 7

#define SCE_GE_SET_STEST(_stf,_sref,_smsk) ((SCE_GE_CMD_STEST<<24) | ((_smsk)<<16) | ((_sref)<<8) | (_stf))
#define SCE_GE_STEST_NEVER 0
#define SCE_GE_STEST_ALWAYS 1
#define SCE_GE_STEST_EQUAL 2
#define SCE_GE_STEST_NOTEQUAL 3
#define SCE_GE_STEST_LESS 4
#define SCE_GE_STEST_LEQUAL 5
#define SCE_GE_STEST_GREATER 6
#define SCE_GE_STEST_GEQUAL 7

#define SCE_GE_SET_SOP(_sfail,_zfail,_zpass) ((SCE_GE_CMD_SOP<<24) | ((_zpass)<<16) | ((_zfail)<<8) | (_sfail))

#define SCE_GE_SOP_KEEP 0
#define SCE_GE_SOP_ZERO 1
#define SCE_GE_SOP_REPLACE 2
#define SCE_GE_SOP_INVERT 3
#define SCE_GE_SOP_INCR 4
#define SCE_GE_SOP_DECR 5

#define SCE_GE_SET_ZTEST(_ztf) ((SCE_GE_CMD_ZTEST<<24) | (_ztf))
#define SCE_GE_ZTEST_NEVER 0
#define SCE_GE_ZTEST_ALWAYS 1
#define SCE_GE_ZTEST_EQUAL 2
#define SCE_GE_ZTEST_NOTEQUAL 3
#define SCE_GE_ZTEST_LESS 4
#define SCE_GE_ZTEST_LEQUAL 5
#define SCE_GE_ZTEST_GREATER 6
#define SCE_GE_ZTEST_GEQUAL 7

#define SCE_GE_SET_BLEND(_a,_b,_equ) ((SCE_GE_CMD_BLEND<<24) | ((_equ)<<8) | ((_b)<<4) | (_a))
#define SCE_GE_BLEND_A_CD 0
#define SCE_GE_BLEND_A_255_CD 1
#define SCE_GE_BLEND_A_AS 2
#define SCE_GE_BLEND_A_255_AS 3
#define SCE_GE_BLEND_A_AD 4
#define SCE_GE_BLEND_A_255_AD 5
#define SCE_GE_BLEND_A_2AS 6
#define SCE_GE_BLEND_A_255_2AS 7
#define SCE_GE_BLEND_A_2AD 8
#define SCE_GE_BLEND_A_255_2AD 9
#define SCE_GE_BLEND_A_FIXA 10
#define SCE_GE_BLEND_B_CS 0
#define SCE_GE_BLEND_B_255_CS 1
#define SCE_GE_BLEND_B_AS 2
#define SCE_GE_BLEND_B_255_AS 3
#define SCE_GE_BLEND_B_AD 4
#define SCE_GE_BLEND_B_255_AD 5
#define SCE_GE_BLEND_B_2AS 6
#define SCE_GE_BLEND_B_255_2AS 7
#define SCE_GE_BLEND_B_2AD 8
#define SCE_GE_BLEND_B_255_2AD 9
#define SCE_GE_BLEND_B_FIXB 10
#define SCE_GE_BLEND_CSA_PLUS_CDB 0
#define SCE_GE_BLEND_CSA_MINUS_CDB 1
#define SCE_GE_BLEND_CDB_MINUS_CSA 2
#define SCE_GE_BLEND_MIN_CS_CD 3
#define SCE_GE_BLEND_MAX_CS_CD 4
#define SCE_GE_BLEND_ABS_CS_CD 5

#define SCE_GE_SET_FIXA(_r,_g,_b) ((SCE_GE_CMD_FIXA<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_FIXA_RGB24(_rgb24) ((SCE_GE_CMD_FIXA<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_FIXB(_r,_g,_b) ((SCE_GE_CMD_FIXB<<24) | ((_b)<<16) | ((_g)<<8) | (_r))
#define SCE_GE_SET_FIXB_RGB24(_rgb24) ((SCE_GE_CMD_FIXB<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_DITH1(_dm00,_dm01,_dm02,_dm03) ((SCE_GE_CMD_DITH1<<24) | (((_dm03) & 0xF)<<12) | (((_dm02) & 0xF)<<8) | (((_dm01) & 0xF)<<4) | ((_dm00) & 0xF))

#define SCE_GE_SET_DITH2(_dm04,_dm05,_dm06,_dm07) ((SCE_GE_CMD_DITH2<<24) | (((_dm07) & 0xF)<<12) | (((_dm06) & 0xF)<<8) | (((_dm05) & 0xF)<<4) | ((_dm04) & 0xF))

#define SCE_GE_SET_DITH3(_dm08,_dm09,_dm10,_dm11) ((SCE_GE_CMD_DITH3<<24) | (((_dm11) & 0xF)<<12) | (((_dm10) & 0xF)<<8) | (((_dm09) & 0xF)<<4) | ((_dm08) & 0xF))

#define SCE_GE_SET_DITH4(_dm12,_dm13,_dm14,_dm15) ((SCE_GE_CMD_DITH4<<24) | (((_dm15) & 0xF)<<12) | (((_dm14) & 0xF)<<8) | (((_dm13) & 0xF)<<4) | ((_dm12) & 0xF))

#define SCE_GE_SET_LOP(_lop) ((SCE_GE_CMD_LOP<<24) | (_lop))
#define SCE_GE_LOP_CLEAR 0
#define SCE_GE_LOP_AND 1
#define SCE_GE_LOP_AND_REVERSE 2
#define SCE_GE_LOP_COPY 3
#define SCE_GE_LOP_AND_INVERTED 4
#define SCE_GE_LOP_NOOP 5
#define SCE_GE_LOP_XOR 6
#define SCE_GE_LOP_OR 7
#define SCE_GE_LOP_NOR 8
#define SCE_GE_LOP_EQUIV 9
#define SCE_GE_LOP_INVERT 10
#define SCE_GE_LOP_OR_REVERSE 11
#define SCE_GE_LOP_COPY_INVERTED 12
#define SCE_GE_LOP_OR_INVERTED 13
#define SCE_GE_LOP_NAND 14
#define SCE_GE_LOP_SET 15

#define SCE_GE_SET_ZMSK(_zmsk) ((SCE_GE_CMD_ZMSK<<24) | (_zmsk))

#define SCE_GE_SET_PMSK1(_rmsk,_gmsk,_bmsk) ((SCE_GE_CMD_PMSK1<<24) | ((_bmsk)<<16) | ((_gmsk)<<8) | (_rmsk))
#define SCE_GE_SET_PMSK1_RGB24(_rgb24) ((SCE_GE_CMD_PMSK1<<24) | ((_rgb24) & 0x00FFFFFF))

#define SCE_GE_SET_PMSK2(_pmsk) ((SCE_GE_CMD_PMSK2<<24) | (_pmsk))

#define SCE_GE_SET_XSTART(_xpf) ((SCE_GE_CMD_XSTART<<24) | (_xpf))
#define SCE_GE_XSTART_XPF_16BIT 0
#define SCE_GE_XSTART_XPF_32BIT 1

#define SCE_GE_SET_XPOS1(_sx1,_sy1) ((SCE_GE_CMD_XPOS1<<24) | ((_sy1)<<10) | (_sx1))

#define SCE_GE_SET_XPOS2(_sx2,_sy2) ((SCE_GE_CMD_XPOS2<<24) | ((_sy2)<<10) | (_sx2))

#define SCE_GE_SET_XSIZE(_width,_height) ((SCE_GE_CMD_XSIZE<<24) | ((_height)<<10) | (_width))

#define SCE_GE_SET_DUMMY() ((SCE_GE_CMD_DUMMY<<24))

#define SCE_GE_SET_FINISH_ID16(_id16) ((SCE_GE_CMD_FINISH<<24) | ((_id16) & 0xFFFF))

#define SCE_GE_SIGNAL_SIGNAL_WAIT 0x01

#define SCE_GE_SIGNAL_SIGNAL_NOWAIT 0x02

#define SCE_GE_SIGNAL_SIGNAL_PAUSE 0x03

#define SCE_GE_SIGNAL_DRAWSYNC 0x08

#define SCE_GE_SIGNAL_JUMP 0x10

#define SCE_GE_SIGNAL_CALL 0x11

#define SCE_GE_SIGNAL_RET 0x12

#define SCE_GE_SIGNAL_RJUMP 0x13

#define SCE_GE_SIGNAL_RCALL 0x14

#define SCE_GE_SIGNAL_OJUMP 0x15

#define SCE_GE_SIGNAL_OCALL 0x16

#define SCE_GE_SIGNAL_RTBP0 0x20

#define SCE_GE_SIGNAL_RTBP1 0x21

#define SCE_GE_SIGNAL_RTBP2 0x22

#define SCE_GE_SIGNAL_RTBP3 0x23

#define SCE_GE_SIGNAL_RTBP4 0x24

#define SCE_GE_SIGNAL_RTBP5 0x25

#define SCE_GE_SIGNAL_RTBP6 0x26

#define SCE_GE_SIGNAL_RTBP7 0x27

#define SCE_GE_SIGNAL_OTBP0 0x28

#define SCE_GE_SIGNAL_OTBP1 0x29

#define SCE_GE_SIGNAL_OTBP2 0x2A

#define SCE_GE_SIGNAL_OTBP3 0x2B

#define SCE_GE_SIGNAL_OTBP4 0x2C

#define SCE_GE_SIGNAL_OTBP5 0x2D

#define SCE_GE_SIGNAL_OTBP6 0x2E

#define SCE_GE_SIGNAL_OTBP7 0x2F

#define SCE_GE_SIGNAL_RCBP 0x30

#define SCE_GE_SIGNAL_OCBP 0x38

#define SCE_GE_SIGNAL_BREAK 0xFF
#define SCE_GE_EXTRACT_LO16(_adr32) (((SceUInt32)(_adr32)) & 0xFFFF)
#define SCE_GE_EXTRACT_HI16(_adr32) ((((SceUInt32)(_adr32))>>16) & 0x0FFF)

#define SCE_GE_SET_SIGNAL_SIGNAL_WAIT(_id) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_SIGNAL_WAIT<<16) | ((_id) & 0xFFFF))
#define SCE_GE_SET_END_SIGNAL_WAIT() SCE_GE_SET_END()

#define SCE_GE_SET_SIGNAL_SIGNAL_NOWAIT(_id) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_SIGNAL_NOWAIT<<16) | ((_id) & 0xFFFF))
#define SCE_GE_SET_END_SIGNAL_NOWAIT() SCE_GE_SET_END()

#define SCE_GE_SET_SIGNAL_SIGNAL_PAUSE(_id) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_SIGNAL_PAUSE<<16) | ((_id) & 0xFFFF))
#define SCE_GE_SET_END_SIGNAL_PAUSE() SCE_GE_SET_END()

#define SCE_GE_SET_SIGNAL_DRAWSYNC() ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_DRAWSYNC<<16))
#define SCE_GE_SET_END_DRAWSYNC() SCE_GE_SET_END()

#define SCE_GE_SET_SIGNAL_JUMP(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_JUMP<<16) | ((_hi16) & 0x0FFF))
#define SCE_GE_SET_SIGNAL_JUMP_ADDR16(_adr32) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_JUMP<<16) | SCE_GE_EXTRACT_HI16(_adr32))
#define SCE_GE_SET_END_JUMP(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))
#define SCE_GE_SET_END_JUMP_ADDR16(_adr32) ((SCE_GE_CMD_END<<24) | SCE_GE_EXTRACT_LO16(_adr32))

#define SCE_GE_SET_SIGNAL_CALL(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_CALL<<16) | ((_hi16) & 0x0FFF))
#define SCE_GE_SET_SIGNAL_CALL_ADDR16(_adr32) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_CALL<<16) | SCE_GE_EXTRACT_HI16(_adr32))
#define SCE_GE_SET_END_CALL(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))
#define SCE_GE_SET_END_CALL_ADDR16(_adr32) ((SCE_GE_CMD_END<<24) | SCE_GE_EXTRACT_LO16(_adr32))

#define SCE_GE_SET_SIGNAL_RET() ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_RET<<16))
#define SCE_GE_SET_END_RET() SCE_GE_SET_END()

#define SCE_GE_SET_SIGNAL_RJUMP(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_RJUMP<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_RJUMP(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_RCALL(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_RCALL<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_RCALL(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_OJUMP(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_OJUMP<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_OJUMP(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_OCALL(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_OCALL<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_OCALL(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_RTBPn(_n,_hi16) ((SCE_GE_CMD_SIGNAL<<24) | ((SCE_GE_SIGNAL_RTBP0 + (_n))<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_RTBPn(_n,_tbw,_lo16) ((SCE_GE_CMD_END<<24) | (((_tbw) & 0xFF)<<16) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_RTBP0(_hi16) SCE_GE_SET_SIGNAL_RTBPn(0,(_hi16))
#define SCE_GE_SET_END_RTBP0(_tbw,_lo16) SCE_GE_SET_END_RTBPn(0,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP1(_hi16) SCE_GE_SET_SIGNAL_RTBPn(1,(_hi16))
#define SCE_GE_SET_END_RTBP1(_tbw,_lo16) SCE_GE_SET_END_RTBPn(1,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP2(_hi16) SCE_GE_SET_SIGNAL_RTBPn(2,(_hi16))
#define SCE_GE_SET_END_RTBP2(_tbw,_lo16) SCE_GE_SET_END_RTBPn(2,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP3(_hi16) SCE_GE_SET_SIGNAL_RTBPn(3,(_hi16))
#define SCE_GE_SET_END_RTBP3(_tbw,_lo16) SCE_GE_SET_END_RTBPn(3,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP4(_hi16) SCE_GE_SET_SIGNAL_RTBPn(4,(_hi16))
#define SCE_GE_SET_END_RTBP4(_tbw,_lo16) SCE_GE_SET_END_RTBPn(4,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP5(_hi16) SCE_GE_SET_SIGNAL_RTBPn(5,(_hi16))
#define SCE_GE_SET_END_RTBP5(_tbw,_lo16) SCE_GE_SET_END_RTBPn(5,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP6(_hi16) SCE_GE_SET_SIGNAL_RTBPn(6,(_hi16))
#define SCE_GE_SET_END_RTBP6(_tbw,_lo16) SCE_GE_SET_END_RTBPn(6,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_RTBP7(_hi16) SCE_GE_SET_SIGNAL_RTBPn(7,(_hi16))
#define SCE_GE_SET_END_RTBP7(_tbw,_lo16) SCE_GE_SET_END_RTBPn(7,(_tbw),(_lo16))

#define SCE_GE_SET_SIGNAL_OTBPn(_n,_hi16) ((SCE_GE_CMD_SIGNAL<<24) | ((SCE_GE_SIGNAL_OTBP0 + (_n))<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_OTBPn(_n,_tbw,_lo16) ((SCE_GE_CMD_END<<24) | (((_tbw) & 0xFF)<<16) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_OTBP0(_hi16) SCE_GE_SET_SIGNAL_OTBPn(0,(_hi16))
#define SCE_GE_SET_END_OTBP0(_tbw,_lo16) SCE_GE_SET_END_OTBPn(0,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP1(_hi16) SCE_GE_SET_SIGNAL_OTBPn(1,(_hi16))
#define SCE_GE_SET_END_OTBP1(_tbw,_lo16) SCE_GE_SET_END_OTBPn(1,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP2(_hi16) SCE_GE_SET_SIGNAL_OTBPn(2,(_hi16))
#define SCE_GE_SET_END_OTBP2(_tbw,_lo16) SCE_GE_SET_END_OTBPn(2,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP3(_hi16) SCE_GE_SET_SIGNAL_OTBPn(3,(_hi16))
#define SCE_GE_SET_END_OTBP3(_tbw,_lo16) SCE_GE_SET_END_OTBPn(3,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP4(_hi16) SCE_GE_SET_SIGNAL_OTBPn(4,(_hi16))
#define SCE_GE_SET_END_OTBP4(_tbw,_lo16) SCE_GE_SET_END_OTBPn(4,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP5(_hi16) SCE_GE_SET_SIGNAL_OTBPn(5,(_hi16))
#define SCE_GE_SET_END_OTBP5(_tbw,_lo16) SCE_GE_SET_END_OTBPn(5,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP6(_hi16) SCE_GE_SET_SIGNAL_OTBPn(6,(_hi16))
#define SCE_GE_SET_END_OTBP6(_tbw,_lo16) SCE_GE_SET_END_OTBPn(6,(_tbw),(_lo16))
#define SCE_GE_SET_SIGNAL_OTBP7(_hi16) SCE_GE_SET_SIGNAL_OTBPn(7,(_hi16))
#define SCE_GE_SET_END_OTBP7(_tbw,_lo16) SCE_GE_SET_END_OTBPn(7,(_tbw),(_lo16))

#define SCE_GE_SET_SIGNAL_RCBP(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | ((SCE_GE_SIGNAL_RCBP)<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_RCBP(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_OCBP(_hi16) ((SCE_GE_CMD_SIGNAL<<24) | ((SCE_GE_SIGNAL_OCBP)<<16) | ((_hi16) & 0xFFFF))
#define SCE_GE_SET_END_OCBP(_lo16) ((SCE_GE_CMD_END<<24) | ((_lo16) & 0xFFFF))

#define SCE_GE_SET_SIGNAL_BREAK(_mark) ((SCE_GE_CMD_SIGNAL<<24) | (SCE_GE_SIGNAL_BREAK<<16) | ((_mark) & 0xFFFF))
#define SCE_GE_SET_END_BREAK() SCE_GE_SET_END()

unsigned int sceGeEdramGetSize(void);

void *sceGeEdramGetAddr(void);

int sceGeEdramSetAddrTranslation(int width);

unsigned int sceGeGetCmd(int cmdno);

#define SCE_GE_MTX_BONEA 0

#define SCE_GE_MTX_BONEB 1

#define SCE_GE_MTX_BONEC 2

#define SCE_GE_MTX_BONED 3

#define SCE_GE_MTX_BONEE 4

#define SCE_GE_MTX_BONEF 5

#define SCE_GE_MTX_BONEG 6

#define SCE_GE_MTX_BONEH 7

#define SCE_GE_MTX_WORLD 8

#define SCE_GE_MTX_VIEW 9

#define SCE_GE_MTX_PROJ 10

#define SCE_GE_MTX_TGEN 11

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

#define SCE_GE_LIST_COMPLETED 0

#define SCE_GE_LIST_QUEUED 1

#define SCE_GE_LIST_DRAWING 2

#define SCE_GE_LIST_STALLING 3

#define SCE_GE_LIST_PAUSED 4

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

#define _SCE_LIBGU_H 

#define SCEGU_DISPLAY_OFF 0
#define SCEGU_DISPLAY_ON 1

#define SCEGU_SCR_WIDTH 480
#define SCEGU_SCR_HEIGHT 272
#define SCEGU_SCR_ASPECT ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_SCR_OFFSETX ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY ((4096 - SCEGU_SCR_HEIGHT) / 2)

#define SCEGU_VRAM_TOP 0x00000000
#define SCEGU_VRAM_WIDTH 512

#define SCEGU_VRAM_BUFSIZE (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#define SCEGU_VRAM_BP_0 (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP_1 (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#define SCEGU_VRAM_BP_2 (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))

#define SCEGU_VRAM_BUFSIZE32 (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_BP32_0 (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP32_1 (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32)
#define SCEGU_VRAM_BP32_2 (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE32*2))

#define SCEGU_IMMEDIATE 0
#define SCEGU_CALL 1
#define SCEGU_LIST 2
#define SCEGU_CALL_CACHED 3
#define SCEGU_LIST_CACHED 4

#define SCEGU_NORMAL_CALL 0
#define SCEGU_SIGNAL_CALL 1

#define SCEGU_MATRIX_PROJECTION 0
#define SCEGU_MATRIX_VIEW 1
#define SCEGU_MATRIX_WORLD 2
#define SCEGU_MATRIX_TEXTURE 3

#define SCEGU_SYNC_FINISH 0
#define SCEGU_SYNC_SIGNAL 1
#define SCEGU_SYNC_END 2
#define SCEGU_SYNC_LIST 3
#define SCEGU_SYNC_SENDLIST 4

#define SCEGU_SYNC_WAIT 0
#define SCEGU_SYNC_NOWAIT 1

#define SCEGU_ALPHA_TEST 0
#define SCEGU_DEPTH_TEST 1
#define SCEGU_SCISSOR_TEST 2
#define SCEGU_STENCIL_TEST 3
#define SCEGU_BLEND 4
#define SCEGU_CULL_FACE 5
#define SCEGU_DITHER 6
#define SCEGU_FOG 7
#define SCEGU_CLIP_PLANE 8
#define SCEGU_TEXTURE 9
#define SCEGU_LIGHTING 10
#define SCEGU_LIGHT0 11
#define SCEGU_LIGHT1 12
#define SCEGU_LIGHT2 13
#define SCEGU_LIGHT3 14
#define SCEGU_AALINE 15
#define SCEGU_CULL_PATCH 16
#define SCEGU_COLOR_TEST 17
#define SCEGU_LOGICAL_OPERATION 18
#define SCEGU_NORMAL_REVERSE_PRIM 19
#define SCEGU_NORMAL_REVERSE_PATCH 20
#define SCEGU_COLOR_DOUBLE 21

#define SCEGU_NEVER 0
#define SCEGU_ALWAYS 1
#define SCEGU_EQUAL 2
#define SCEGU_NOTEQUAL 3
#define SCEGU_LESS 4
#define SCEGU_LEQUAL 5
#define SCEGU_GREATER 6
#define SCEGU_GEQUAL 7

#define SCEGU_KEEP 0
#define SCEGU_ZERO 1
#define SCEGU_REPLACE 2
#define SCEGU_INVERT 3
#define SCEGU_INCR 4
#define SCEGU_DECR 5

#define SCEGU_ADD 0
#define SCEGU_SUBTRACT 1
#define SCEGU_REVERSE_SUBTRACT 2
#define SCEGU_MIN 3
#define SCEGU_MAX 4
#define SCEGU_ABS 5

#define SCEGU_SRC_COLOR 0
#define SCEGU_ONE_MINUS_SRC_COLOR 1
#define SCEGU_DST_COLOR 0
#define SCEGU_ONE_MINUS_DST_COLOR 1
#define SCEGU_SRC_ALPHA 2
#define SCEGU_ONE_MINUS_SRC_ALPHA 3
#define SCEGU_DST_ALPHA 4
#define SCEGU_ONE_MINUS_DST_ALPHA 5
#define SCEGU_DOUBLE_SRC_ALPHA 6
#define SCEGU_ONE_MINUS_DOUBLE_SRC_ALPHA 7
#define SCEGU_DOUBLE_DST_ALPHA 8
#define SCEGU_ONE_MINUS_DOUBLE_DST_ALPHA 9
#define SCEGU_FIX_VALUE 10

#define SCEGU_LOP_CLEAR 0
#define SCEGU_LOP_AND 1
#define SCEGU_LOP_AND_REVERSE 2
#define SCEGU_LOP_COPY 3
#define SCEGU_LOP_AND_INVERTED 4
#define SCEGU_LOP_NOOP 5
#define SCEGU_LOP_XOR 6
#define SCEGU_LOP_OR 7
#define SCEGU_LOP_NOR 8
#define SCEGU_LOP_EQUIV 9
#define SCEGU_LOP_INVERT 10
#define SCEGU_LOP_OR_REVERSE 11
#define SCEGU_LOP_COPY_INVERTED 12
#define SCEGU_LOP_OR_INVERTED 13
#define SCEGU_LOP_NAND 14
#define SCEGU_LOP_SET 15

#define SCEGU_CW 0
#define SCEGU_CCW 1

#define SCEGU_FLAT 0
#define SCEGU_SMOOTH 1

#define SCEGU_AMBIENT 1
#define SCEGU_DIFFUSE 2
#define SCEGU_SPECULAR 4
#define SCEGU_AMBIENT_AND_DIFFUSE 3
#define SCEGU_DIFFUSE_AND_SPECULAR 6
#define SCEGU_POWERED_DIFFUSE 8

#define SCEGU_LIGHT_DIRECTION 0
#define SCEGU_LIGHT_POINT 1
#define SCEGU_LIGHT_SPOT 2

#define SCEGU_SINGLE_CLUT 0
#define SCEGU_MULTI_CLUT 1

#define SCEGU_PF5650 0
#define SCEGU_PF5551 1
#define SCEGU_PF4444 2
#define SCEGU_PF8888 3
#define SCEGU_PFIDX4 4
#define SCEGU_PFIDX8 5
#define SCEGU_PFIDX16 6
#define SCEGU_PFIDX32 7
#define SCEGU_PFDXT1 8
#define SCEGU_PFDXT3 9
#define SCEGU_PFDXT5 10
#define SCEGU_PFDXT1EXT 264
#define SCEGU_PFDXT3EXT 265
#define SCEGU_PFDXT5EXT 266

#define SCEGU_RGB 0
#define SCEGU_RGBA 1

#define SCEGU_TEX_MODULATE 0
#define SCEGU_TEX_DECAL 1
#define SCEGU_TEX_BLEND 2
#define SCEGU_TEX_REPLACE 3
#define SCEGU_TEX_ADD 4

#define SCEGU_NEAREST 0
#define SCEGU_LINEAR 1
#define SCEGU_NEAREST_MIPMAP_NEAREST 4
#define SCEGU_LINEAR_MIPMAP_NEAREST 5
#define SCEGU_NEAREST_MIPMAP_LINEAR 6
#define SCEGU_LINEAR_MIPMAP_LINEAR 7

#define SCEGU_REPEAT 0
#define SCEGU_CLAMP 1

#define SCEGU_UV_MAP 0
#define SCEGU_PROJECTION_MAP 1
#define SCEGU_SHADE_MAP 2

#define SCEGU_PROJ_XYZ 0
#define SCEGU_PROJ_UV 1
#define SCEGU_PROJ_NORMALIZE_NORMAL 2
#define SCEGU_PROJ_NORMAL 3

#define SCEGU_LOD_AUTO 0
#define SCEGU_LOD_CONSTANT 1
#define SCEGU_LOD_SLOPE 2

#define SCEGU_TEXBUF_NORMAL 0
#define SCEGU_TEXBUF_FAST 1

#define SCEGU_CLEAR_COLOR 0x0001
#define SCEGU_CLEAR_STENCIL 0x0002
#define SCEGU_CLEAR_DEPTH 0x0004
#define SCEGU_CLEAR_ALL 0x0007
#define SCEGU_CLEAR_FAST 0x0010
#define SCEGU_CLEAR_FASTALL (SCEGU_CLEAR_FAST|SCEGU_CLEAR_ALL)

#define SCEGU_PRIM_POINTS 0
#define SCEGU_PRIM_LINES 1
#define SCEGU_PRIM_LINE_STRIP 2
#define SCEGU_PRIM_TRIANGLES 3
#define SCEGU_PRIM_TRIANGLE_STRIP 4
#define SCEGU_PRIM_TRIANGLE_FAN 5
#define SCEGU_PRIM_RECTANGLES 6

#define SCEGU_CLOSE_CLOSE 0
#define SCEGU_OPEN_CLOSE 1
#define SCEGU_CLOSE_OPEN 2
#define SCEGU_OPEN_OPEN 3

#define SCEGU_NOFLIP 0
#define SCEGU_FLIP_U 1
#define SCEGU_FLIP_V 2
#define SCEGU_FLIP_UV 3
#define SCEGU_NOROTATE 0
#define SCEGU_ROTATE_90 1
#define SCEGU_ROTATE_180 2
#define SCEGU_ROTATE_270 3

#define SCEGU_TEXTURE_NONE ( 0 << 0 )
#define SCEGU_TEXTURE_UBYTE ( 1 << 0 )
#define SCEGU_TEXTURE_USHORT ( 2 << 0 )
#define SCEGU_TEXTURE_FLOAT ( 3 << 0 )

#define SCEGU_COLOR_NONE ( 0 << 2 )
#define SCEGU_COLOR_PF5650 ( 4 << 2 )
#define SCEGU_COLOR_PF5551 ( 5 << 2 )
#define SCEGU_COLOR_PF4444 ( 6 << 2 )
#define SCEGU_COLOR_PF8888 ( 7 << 2 )

#define SCEGU_NORMAL_NONE ( 0 << 5 )
#define SCEGU_NORMAL_BYTE ( 1 << 5 )
#define SCEGU_NORMAL_SHORT ( 2 << 5 )
#define SCEGU_NORMAL_FLOAT ( 3 << 5 )

#define SCEGU_VERTEX_NONE ( 0 << 7 )
#define SCEGU_VERTEX_BYTE ( 1 << 7 )
#define SCEGU_VERTEX_SHORT ( 2 << 7 )
#define SCEGU_VERTEX_FLOAT ( 3 << 7 )

#define SCEGU_WEIGHT_NONE ( 0 << 9 )
#define SCEGU_WEIGHT_UBYTE ( 1 << 9 )
#define SCEGU_WEIGHT_USHORT ( 2 << 9 )
#define SCEGU_WEIGHT_FLOAT ( 3 << 9 )

#define SCEGU_INDEX_NONE ( 0 << 11 )
#define SCEGU_INDEX_UBYTE ( 1 << 11 )
#define SCEGU_INDEX_USHORT ( 2 << 11 )

#define SCEGU_WEIGHT_1 ( 0 << 14 )
#define SCEGU_WEIGHT_2 ( 1 << 14 )
#define SCEGU_WEIGHT_3 ( 2 << 14 )
#define SCEGU_WEIGHT_4 ( 3 << 14 )
#define SCEGU_WEIGHT_5 ( 4 << 14 )
#define SCEGU_WEIGHT_6 ( 5 << 14 )
#define SCEGU_WEIGHT_7 ( 6 << 14 )
#define SCEGU_WEIGHT_8 ( 7 << 14 )

#define SCEGU_VERTEX_1 ( 0 << 18 )
#define SCEGU_VERTEX_2 ( 1 << 18 )
#define SCEGU_VERTEX_3 ( 2 << 18 )
#define SCEGU_VERTEX_4 ( 3 << 18 )
#define SCEGU_VERTEX_5 ( 4 << 18 )
#define SCEGU_VERTEX_6 ( 5 << 18 )
#define SCEGU_VERTEX_7 ( 6 << 18 )
#define SCEGU_VERTEX_8 ( 7 << 18 )

#define SCEGU_THROUGH ( 1 << 23 )

#define SCEGU_SINGLE_COLOR 0
#define SCEGU_SEPARATE_SPECULAR_COLOR 1
#define SCEGU_EYE_FIX 0
#define SCEGU_EYE_OBJECT 1

#define SCEGU_PI 3.1415926535897932384626433832f
#define SCEGU_RAD(a) ((a)*SCEGU_PI/180.0f)

#define SCEGU_SIGNAL_WAIT 1
#define SCEGU_SIGNAL_NOWAIT 2
#define SCEGU_SIGNAL_PAUSE 3

#define SCEGU_INT_SIGNAL 1
#define SCEGU_INT_END 2
#define SCEGU_INT_FINISH 4

#define SCEGU_QUEUE_TAIL 0
#define SCEGU_QUEUE_HEAD 1

#define SCEGU_BREAK_PAUSE 0
#define SCEGU_BREAK_CANCEL 1

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
#define _SCE_LIBGUM_H 

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

#define _MATH_H_ 

union __dmath
{
  __ULong i[2];
  double d;
};

extern const union __dmath __infinity[];

#define HUGE_VAL (__infinity[0].d)

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
#define FLT_EVAL_METHOD 0
typedef float float_t;
typedef double double_t;

#define FP_NAN 0
#define FP_INFINITE 1
#define FP_ZERO 2
#define FP_SUBNORMAL 3
#define FP_NORMAL 4

extern int __fpclassifyf (float x);
extern int __fpclassifyd (double x);
extern int __signbitf (float x);
extern int __signbitd (double x);

#define fpclassify(x) (__extension__ ({__typeof__(x) __x = (x); (sizeof (__x) == sizeof (float)) ? __fpclassifyf(__x) : __fpclassifyd(__x);}))

#define isfinite(x) (__extension__ ({__typeof__(x) __x = (x); fpclassify(__x) != FP_INFINITE && fpclassify(__x) != FP_NAN;}))

#define isnormal(x) (__extension__ ({__typeof__(x) __x = (x); fpclassify(__x) == FP_NORMAL;}))

#define signbit(x) (__extension__ ({__typeof__(x) __x = (x); (sizeof(__x) == sizeof(float)) ? __signbitf(__x) : __signbitd(__x);}))

#define isgreater(x,y) (__extension__ ({__typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered(__x,__y) && (__x > __y);}))

#define isgreaterequal(x,y) (__extension__ ({__typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered(__x,__y) && (__x >= __y);}))

#define isless(x,y) (__extension__ ({__typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered(__x,__y) && (__x < __y);}))

#define islessequal(x,y) (__extension__ ({__typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered(__x,__y) && (__x <= __y);}))

#define islessgreater(x,y) (__extension__ ({__typeof__(x) __x = (x); __typeof__(y) __y = (y); !isunordered(__x,__y) && (__x < __y || __x > __y);}))

#define isunordered(x,y) (__extension__ ({__typeof__(x) __x = (x); __typeof__(y) __y = (y); fpclassify(__x) == FP_NAN || fpclassify(__y) == FP_NAN;}))

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
#define log2(x) (log (x) / M_LOG2_E)

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
#define log2f(x) (logf (x) / (float) M_LOG2_E)
extern float hypotf (float, float);

extern float cabsf();
extern float dremf (float, float);

#define signgam (*__signgam())
extern int *__signgam (void);

#define __signgam_r(ptr) _REENT_SIGNGAM(ptr)

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

#define DOMAIN 1
#define SING 2
#define OVERFLOW 3
#define UNDERFLOW 4
#define TLOSS 5
#define PLOSS 6

#define MAXFLOAT 3.40282347e+38F

#define M_E 2.7182818284590452354
#define M_LOG2E 1.4426950408889634074
#define M_LOG10E 0.43429448190325182765
#define M_LN2 0.69314718055994530942
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_TWOPI (M_PI * 2.0)
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.78539816339744830962
#define M_3PI_4 2.3561944901923448370E0
#define M_SQRTPI 1.77245385090551602792981
#define M_1_PI 0.31830988618379067154
#define M_2_PI 0.63661977236758134308
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.70710678118654752440
#define M_LN2LO 1.9082149292705877000E-10
#define M_LN2HI 6.9314718036912381649E-1
#define M_SQRT3 1.73205080756887719000
#define M_IVLN10 0.43429448190325182765
#define M_LOG2_E 0.693147180559945309417
#define M_INVLN2 1.4426950408889633870E0

enum __fdlibm_version
{
  __fdlibm_ieee = -1,
  __fdlibm_svid,
  __fdlibm_xopen,
  __fdlibm_posix
};

#define _LIB_VERSION_TYPE enum __fdlibm_version
#define _LIB_VERSION __fdlib_version

extern const enum __fdlibm_version __fdlib_version;

#define _IEEE_ __fdlibm_ieee
#define _SVID_ __fdlibm_svid
#define _XOPEN_ __fdlibm_xopen
#define _POSIX_ __fdlibm_posix

#define USE_VFPU 0
#endif
