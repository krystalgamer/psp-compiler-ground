#include "common.h"
/* cflags: -O2 -frename-registers */

/* declarations recovered from DWARF */
/* struct _reent from the newlib units' DWARF */
struct _reent;
typedef struct __sFILE __FILE;
struct __sFILE;
struct __sbuf;
struct __sbuf { /* size 0x8 */
    unsigned char *_base;
    int _size;
};
typedef long int _fpos_t;
typedef int _LOCK_RECURSIVE_T;
typedef _LOCK_RECURSIVE_T _flock_t;
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
    int _module_id;
};



extern const unsigned char __psp_libinfo__[24];
extern const int _sce_module_startthpara[4];
extern const int _sce_module_stopthpara[4];
extern int sce_newlib_stack_kb_size;
extern int sce_newlib_priority;
extern unsigned int sce_newlib_attribute;
extern void (*sce_newlib_stop_func)(void);

int _start(int args, char *argp);
int _main(int args, char *argp);
int _stop(void);


INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", __psp_libinfo___2D620);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _sce_module_startthpara);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/crt0", _sce_module_stopthpara);

int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
extern void _init(void);
extern void _fini(void);
int main(int argc, char *argv[]);
int atexit(void (*func)(void));
void exit(int status);
void _reent_init_ptr(struct _reent *) __attribute__((weak));
int _setmodreent(int, struct _reent *) __attribute__((weak));
int sceKernelSetCompiledSdkVersion(unsigned int ver);
int sceKernelSetCompilerVersion(unsigned int ver);
int sceKernelExitThread(int status);
int sceKernelGetModuleIdByAddress(const void *addr);
extern int sce_newlib_stack_kb_size __attribute__((weak));
extern int sce_newlib_priority __attribute__((weak));
extern unsigned int sce_newlib_attribute __attribute__((weak));
extern void (*sce_newlib_stop_func)(void) __attribute__((weak));
int _start(int args, char *argp)
{
	int thid;
	int res;

	sceKernelSetCompiledSdkVersion(0x2050010);
	sceKernelSetCompilerVersion(0x30303);
	{
		unsigned int realsize;
		int priority;
		unsigned int attribute;

		realsize = (&sce_newlib_stack_kb_size != NULL) ? sce_newlib_stack_kb_size << 10 : 0x40000;
		priority = (&sce_newlib_priority != NULL) ? sce_newlib_priority : 0x20;
		attribute = (&sce_newlib_attribute != NULL) ? (sce_newlib_attribute | 0x80000000) : 0x80000000;
		thid = sceKernelCreateThread("user_main", (void *)_main, priority, realsize, attribute, NULL);
		res = sceKernelStartThread(thid, args, argp);
	}
	return 0;
}

void *memset(void *s, int c, unsigned int n);
unsigned int strlen(const char *s);
extern void _init(void);
extern void _fini(void);
int main(int argc, char *argv[]);
int atexit(void (*func)(void));
void exit(int status);
unsigned int strlen(const char *s);
void *memset(void *s, int c, unsigned int n);
void _reent_init_ptr(struct _reent *) __attribute__((weak));
int _setmodreent(int, struct _reent *) __attribute__((weak));
int sceKernelExitThread(int status);
int sceKernelGetModuleIdByAddress(const void *addr);
void sceGprofCountStart(void) __attribute__((weak));
void sceGprofCountEnd(void) __attribute__((weak));
int _main(int args, char *argp)
{
	int rtn;
	char *argv[20], *ap;
	int argc;
	int mid;
	struct _reent reent, *reentp = &reent;

	for (argc = 0, ap = argp; argc < 20 && ap - argp < args; argc++) {
		argv[argc] = ap;
		ap += strlen(ap) + 1;
	}
	argv[argc] = NULL;

	if (_reent_init_ptr) {
		_reent_init_ptr(reentp);
		mid = sceKernelGetModuleIdByAddress((const void *)_start);
		if (_setmodreent(mid, reentp) < 0) {
			sceKernelExitThread(1);
			return 1;
		}
	} else {
		int i;
		char *tmp_ptr;
		reentp->_errno = 0;
		reentp->_stdin = &reentp->__sf[0];
		reentp->_stdout = &reentp->__sf[1];
		reentp->_stderr = &reentp->__sf[2];
		reentp->_inc = 0;
		for (i = 0; i < 25; ++i)
			reentp->_emergency[i] = 0;
		reentp->_current_category = 0;
		reentp->_current_locale = "C";
		reentp->__sdidinit = 0;
		reentp->__cleanup = NULL;
		reentp->_result = NULL;
		reentp->_result_k = 0;
		reentp->_p5s = NULL;
		reentp->_freelist = NULL;
		reentp->_cvtlen = 0;
		reentp->_cvtbuf = NULL;
		reentp->_new._reent._unused_rand = 0;
		reentp->_new._reent._strtok_last = NULL;
		reentp->_new._reent._asctime_buf[0] = 0;
		tmp_ptr = (char *)&reentp->_new._reent._localtime_buf;
		for (i = 0; i < sizeof(struct __tm); ++i)
			tmp_ptr[i] = 0;
		reentp->_new._reent._gamma_signgam = 0;
		reentp->_new._reent._rand_next = 1;
		reentp->_new._reent._r48._seed[0] = 0x330e;
		reentp->_new._reent._r48._seed[1] = 0xabcd;
		reentp->_new._reent._r48._seed[2] = 0x1234;
		reentp->_new._reent._r48._mult[0] = 0xe66d;
		reentp->_new._reent._r48._mult[1] = 0xdeec;
		reentp->_new._reent._r48._mult[2] = 0x0005;
		reentp->_new._reent._r48._add = 0x000b;
		reentp->_new._reent._mblen_state.__count = 0;
		reentp->_new._reent._mblen_state.__value.__wch = 0;
		reentp->_new._reent._mbtowc_state.__count = 0;
		reentp->_new._reent._mbtowc_state.__value.__wch = 0;
		reentp->_new._reent._wctomb_state.__count = 0;
		reentp->_new._reent._wctomb_state.__value.__wch = 0;
		reentp->_new._reent._mbrlen_state.__count = 0;
		reentp->_new._reent._mbrlen_state.__value.__wch = 0;
		reentp->_new._reent._mbrtowc_state.__count = 0;
		reentp->_new._reent._mbrtowc_state.__value.__wch = 0;
		reentp->_new._reent._mbsrtowcs_state.__count = 0;
		reentp->_new._reent._mbsrtowcs_state.__value.__wch = 0;
		reentp->_new._reent._wcrtomb_state.__count = 0;
		reentp->_new._reent._wcrtomb_state.__value.__wch = 0;
		reentp->_new._reent._wcsrtombs_state.__count = 0;
		reentp->_new._reent._wcsrtombs_state.__value.__wch = 0;
		reentp->_new._reent._l64a_buf[0] = 0;
		reentp->_new._reent._signal_buf[0] = 0;
		reentp->_new._reent._getdate_err = 0;
		reentp->_atexit = NULL;
		reentp->_atexit0._next = NULL;
		reentp->_atexit0._ind = 0;
		reentp->_atexit0._fns[0] = NULL;
		reentp->_atexit0._on_exit_args._fntypes = 0;
		reentp->_atexit0._on_exit_args._fnargs[0] = NULL;
		reentp->_sig_func = NULL;
		reentp->__sglue._next = NULL;
		reentp->__sglue._niobs = 0;
		reentp->__sglue._iobs = NULL;
		memset(&reentp->__sf, 0, sizeof(reentp->__sf));
		reentp->_module_id = 0;
	}
	asm volatile ("sw %0, 4($26)" : : "r" (reentp) : "memory");

	atexit(&_fini);
	_init();
	if (sceGprofCountStart && sceGprofCountEnd) {
		atexit(sceGprofCountEnd);
		sceGprofCountStart();
	}
	rtn = main(argc, argv);
	exit(rtn);
}

int _stop(void)
{
	if (&sce_newlib_stop_func)
		(*sce_newlib_stop_func)();
	return 0;
}
