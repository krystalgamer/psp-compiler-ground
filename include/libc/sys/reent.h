#ifndef _SYS_REENT_H_
#define _SYS_REENT_H_
/* newlib's struct _reent as recovered from DWARF (sampler crt0) */
#include <stddef.h>

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

#define _REENT_EMERGENCY_SIZE 25
#define _RAND48_SEED_0  (0x330e)
#define _RAND48_SEED_1  (0xabcd)
#define _RAND48_SEED_2  (0x1234)
#define _RAND48_MULT_0  (0xe66d)
#define _RAND48_MULT_1  (0xdeec)
#define _RAND48_MULT_2  (0x0005)
#define _RAND48_ADD     (0x000b)

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
    var->__cleanup = NULL; \
    var->_result = NULL; \
    var->_result_k = 0; \
    var->_p5s = NULL; \
    var->_freelist = NULL; \
    var->_cvtlen = 0; \
    var->_cvtbuf = NULL; \
    var->_new._reent._unused_rand = 0; \
    var->_new._reent._strtok_last = NULL; \
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
    var->_new._reent._l64a_buf[0] = 0; \
    var->_new._reent._signal_buf[0] = 0; \
    var->_new._reent._getdate_err = 0; \
    var->_atexit = NULL; \
    var->_atexit0._ind = 0; \
    var->_atexit0._fns[0] = NULL; \
    var->_atexit0._on_exit_args._fntypes = 0; \
    var->_atexit0._on_exit_args._fnargs[0] = NULL; \
    var->_sig_func = NULL; \
    var->__sglue._next = NULL; \
    var->__sglue._niobs = 0; \
    var->__sglue._iobs = NULL; \
    memset(&var->__sf, 0, sizeof(var->__sf)); \
  }

#endif
