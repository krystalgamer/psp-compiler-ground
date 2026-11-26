/* Sony's psp-newlib libc/sys/psp/modreent.c (not in newlib 1.12.0) */
/* cflags: -O2 -fno-builtin -falign-loops=64 */
#include "common.h"

/* declarations recovered from DWARF */
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
struct _modptr;
struct _modptr { /* size 0x104 */
    struct _modptr *_next;
    void *_modptrs[32];
    int _modids[32];
};

extern struct _reent *_impure_ptr;
extern struct _modptr _modptr;


int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int);
extern int sceKernelPrintf(const char *, ...) __attribute__((weak));

#define _NULL 0
#define _REENT_EMERGENCY_SIZE 25
#define _RAND48_SEED_0 (0x330e)
#define _RAND48_SEED_1 (0xabcd)
#define _RAND48_SEED_2 (0x1234)
#define _RAND48_MULT_0 (0xe66d)
#define _RAND48_MULT_1 (0xdeec)
#define _RAND48_MULT_2 (0x0005)
#define _RAND48_ADD (0x000b)
#define _REENT_INIT_PTR(var) \
  { int i; \
    char *tmp_ptr; \
    var->_errno = 0; \
    var->_stdin = &var->__sf[0]; \
    var->_stdout = &var->__sf[1]; \
    var->_stderr = &var->__sf[2]; \
    var->_inc = 0; \
    for (i = 0; i < _REENT_EMERGENCY_SIZE; ++i) \
      var->_emergency[i] = 0; \
    var->_current_category = 0; \
    var->_current_locale = "C"; \
    var->__sdidinit = 0; \
    var->__cleanup = _NULL; \
    var->_result = _NULL; \
    var->_result_k = 0; \
    var->_p5s = _NULL; \
    var->_freelist = _NULL; \
    var->_cvtlen = 0; \
    var->_cvtbuf = _NULL; \
    var->_new._reent._unused_rand = 0; \
    var->_new._reent._strtok_last = _NULL; \
    var->_new._reent._asctime_buf[0] = 0; \
    tmp_ptr = (char *)&var->_new._reent._localtime_buf; \
    for (i = 0; i < sizeof(struct __tm); ++i) \
      tmp_ptr[i] = 0; \
    var->_new._reent._gamma_signgam = 0; \
    var->_new._reent._rand_next = 1; \
    var->_new._reent._r48._seed[0] = _RAND48_SEED_0; \
    var->_new._reent._r48._seed[1] = _RAND48_SEED_1; \
    var->_new._reent._r48._seed[2] = _RAND48_SEED_2; \
    var->_new._reent._r48._mult[0] = _RAND48_MULT_0; \
    var->_new._reent._r48._mult[1] = _RAND48_MULT_1; \
    var->_new._reent._r48._mult[2] = _RAND48_MULT_2; \
    var->_new._reent._r48._add = _RAND48_ADD; \
    var->_new._reent._mblen_state.__count = 0; \
    var->_new._reent._mblen_state.__value.__wch = 0; \
    var->_new._reent._mbtowc_state.__count = 0; \
    var->_new._reent._mbtowc_state.__value.__wch = 0; \
    var->_new._reent._wctomb_state.__count = 0; \
    var->_new._reent._wctomb_state.__value.__wch = 0; \
    var->_new._reent._mbrlen_state.__count = 0; \
    var->_new._reent._mbrlen_state.__value.__wch = 0; \
    var->_new._reent._mbrtowc_state.__count = 0; \
    var->_new._reent._mbrtowc_state.__value.__wch = 0; \
    var->_new._reent._mbsrtowcs_state.__count = 0; \
    var->_new._reent._mbsrtowcs_state.__value.__wch = 0; \
    var->_new._reent._wcrtomb_state.__count = 0; \
    var->_new._reent._wcrtomb_state.__value.__wch = 0; \
    var->_new._reent._wcsrtombs_state.__count = 0; \
    var->_new._reent._wcsrtombs_state.__value.__wch = 0; \
    var->_new._reent._l64a_buf[0] = '\0'; \
    var->_new._reent._signal_buf[0] = '\0'; \
    var->_new._reent._getdate_err = 0; \
    var->_atexit = _NULL; \
    var->_atexit0._next = _NULL; \
    var->_atexit0._ind = 0; \
    var->_atexit0._fns[0] = _NULL; \
    var->_atexit0._on_exit_args._fntypes = 0; \
    var->_atexit0._on_exit_args._fnargs[0] = _NULL; \
    var->_sig_func = _NULL; \
    var->__sglue._next = _NULL; \
    var->__sglue._niobs = 0; \
    var->__sglue._iobs = _NULL; \
    memset(var->__sf,0,sizeof(var->__sf)); \
  }

struct _reent *
_getmodreent(void)
{
	register int *tsd __asm__("$26");
	struct _reent *reentp;
	struct _reent *ptr;
	struct _modptr *modp;
	int mid;
	int hash;
	int oldst;

	if (tsd == NULL || (reentp = (struct _reent *)tsd[1]) == NULL) {
		if (sceKernelPrintf)
			sceKernelPrintf("libc:%s: no reent structure\n", "_getmodreent");
		return _impure_ptr;
	}
	oldst = sceKernelCpuSuspendIntr();
	mid = reentp->_module_id;
	hash = mid % 32;
	for (modp = &_modptr; modp != NULL; modp = modp->_next) {
		if (modp->_modids[hash] == mid) {
			ptr = modp->_modptrs[hash];
			sceKernelCpuResumeIntr(oldst);
			return ptr;
		}
	}
	sceKernelCpuResumeIntr(oldst);
	if (sceKernelPrintf)
		sceKernelPrintf("libc:%s: no reent structure found\n", "_getmodreent");
	return _impure_ptr;
}

int
_setmodreent(int mid, struct _reent *reentp)
{
	struct _modptr *modp, *last;
	int hash;
	int oldst;

	oldst = sceKernelCpuSuspendIntr();
	reentp->_module_id = mid;
	hash = mid % 32;
	for (modp = &_modptr; modp != NULL; modp = modp->_next) {
		if (modp->_modids[hash] == 0) {
			modp->_modids[hash] = mid;
			modp->_modptrs[hash] = reentp;
			break;
		}
		if (modp->_modids[hash] == mid) {
			sceKernelCpuResumeIntr(oldst);
			return -1;
		}
		last = modp;
	}
	sceKernelCpuResumeIntr(oldst);
	if (modp == NULL) {
		struct _modptr *new;

		new = _malloc_r(_impure_ptr, sizeof(struct _modptr));
		memset(new, 0, sizeof(struct _modptr));
		new->_modids[hash] = mid;
		new->_modptrs[hash] = reentp;
		oldst = sceKernelCpuSuspendIntr();
		last->_next = new;
		sceKernelCpuResumeIntr(oldst);
	}
	return 0;
}

int
_clrmodreent(struct _reent *ptr)
{
	struct _modptr *modp;
	int hash;
	int oldst;
	int mid;

	mid = ptr->_module_id;
	oldst = sceKernelCpuSuspendIntr();
	hash = mid % 32;
	for (modp = &_modptr; modp != NULL; modp = modp->_next) {
		if (modp->_modids[hash] == mid) {
			modp->_modptrs[hash] = NULL;
			modp->_modids[hash] = 0;
			sceKernelCpuResumeIntr(oldst);
			return mid;
		}
	}
	sceKernelCpuResumeIntr(oldst);
	return -1;
}

void
_reent_init_ptr(struct _reent *ptr)
{
	_REENT_INIT_PTR(ptr);
	ptr->_module_id = 0;
}
