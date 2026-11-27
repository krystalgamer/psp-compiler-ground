/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int func_00008008(char *buf, const char *fmt, ...)
{
	va_list ap;
	char *p = buf;
	int ret;

	va_start(ap, fmt);
	ret = func_00008054(func_0000877C, &p, fmt, ap);
	va_end(ap);
	return ret;
}

#define	BUF		21
#define	PUTC(ch)	(*pf)(pfd, ch)
#define	ARG() \
	_ulong = flags&LONGINT ? __builtin_va_arg(argp, long) : __builtin_va_arg(argp, int);
#define	todigit(c)	((c) - '0')
#define	isascii(c)	((c) >= 0)
#define	isdigit(c)	(look_ctype_table(c) & 4)

#define	LONGINT		0x01
#define	LONGDBL		0x02
#define	SHORTINT	0x04
#define	ALT		0x08
#define	LADJUST		0x10
#define	ZEROPAD		0x20
#define	HEXPREFIX	0x40

int look_ctype_table(unsigned int c) __asm__("func_000087FC");

int func_00008054(void (*pf)(char **, int), char **pfd, const char *fmt0, va_list argp)
{
	const char *fmt;
	int ch;
	int cnt;
	int n;
	char *t;
	unsigned long _ulong;
	int base;
	int dprec;
	int fieldsz;
	int flags;
	int fpprec;
	int prec;
	int realsz;
	int size;
	int width;
	char sign;
	const char *digs;
	char buf[BUF];

	if (fmt0 == NULL)
		return 0;
	fmt = fmt0;
	digs = "0123456789abcdef";
	PUTC(0x200);
	for (cnt = 0;; ++fmt) {
		if ((ch = *fmt) == '\0') {
			PUTC(0x201);
			return cnt;
		}
		if (ch != '%') {
			PUTC(ch);
			cnt++;
			continue;
		}
		flags = 0; dprec = 0; fpprec = 0; width = 0;
		prec = -1;
		sign = '\0';

rflag:		switch (*++fmt) {
		case ' ':
			if (!sign)
				sign = ' ';
			goto rflag;
		case '#':
			flags |= ALT;
			goto rflag;
		case '*':
			if ((width = __builtin_va_arg(argp, int)) >= 0)
				goto rflag;
			width = -width;
			/* FALLTHROUGH */
		case '-':
			flags |= LADJUST;
			goto rflag;
		case '+':
			sign = '+';
			goto rflag;
		case '.':
			if (*++fmt == '*')
				n = __builtin_va_arg(argp, int);
			else {
				n = 0;
				while (isascii(*fmt) && isdigit(*fmt))
					n = 10 * n + todigit(*fmt++);
				--fmt;
			}
			prec = n < 0 ? -1 : n;
			goto rflag;
		case '0':
			flags |= ZEROPAD;
			goto rflag;
		case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			n = 0;
			do {
				n = 10 * n + todigit(*fmt);
			} while (isascii(*++fmt) && isdigit(*fmt));
			width = n;
			--fmt;
			goto rflag;
		case 'L':
			flags |= LONGDBL;
			goto rflag;
		case 'h':
			flags |= SHORTINT;
			goto rflag;
		case 'l':
			flags |= LONGINT;
			goto rflag;
		case 'c':
			*(t = buf) = __builtin_va_arg(argp, int);
			size = 1;
			sign = '\0';
			goto pforw;
		case 'D':
			flags |= LONGINT;
			/*FALLTHROUGH*/
		case 'd':
		case 'i':
			ARG();
			if ((long)_ulong < 0) {
				_ulong = -_ulong;
				sign = '-';
			}
			base = 10;
			goto number;
		case 'n':
			if (flags & LONGINT)
				*__builtin_va_arg(argp, long *) = cnt;
			else if (flags & SHORTINT)
				*__builtin_va_arg(argp, short *) = cnt;
			else
				*__builtin_va_arg(argp, int *) = cnt;
			break;
		case 'O':
			flags |= LONGINT;
			/*FALLTHROUGH*/
		case 'o':
			ARG();
			base = 8;
			goto nosign;
		case 'p':
			_ulong = (unsigned long)__builtin_va_arg(argp, void *);
			base = 16;
			goto nosign;
		case 's':
			if (!(t = __builtin_va_arg(argp, char *)))
				t = "(null)";
			if (prec >= 0) {
				char *p;

				if ((p = memchr(t, 0, prec))) {
					size = p - t;
					if (size > prec)
						size = prec;
				} else
					size = prec;
			} else
				size = strlen(t);
			sign = '\0';
			goto pforw;
		case 'U':
			flags |= LONGINT;
			/*FALLTHROUGH*/
		case 'u':
			ARG();
			base = 10;
			goto nosign;
		case 'X':
			digs = "0123456789ABCDEF";
			/* FALLTHROUGH */
		case 'x':
			ARG();
			base = 16;
			if (flags & ALT && _ulong != 0)
				flags |= HEXPREFIX;
nosign:			sign = '\0';
number:			if ((dprec = prec) >= 0)
				flags &= ~ZEROPAD;
			t = buf + BUF;
			if (_ulong != 0 || prec != 0) {
				do {
					*--t = digs[_ulong % base];
					_ulong /= base;
				} while (_ulong);
				digs = "0123456789abcdef";
				if (flags & ALT && base == 8 && *t != '0')
					*--t = '0';
			}
			size = buf + BUF - t;
pforw:
			fieldsz = size;
			if (sign)
				fieldsz++;
			if (flags & HEXPREFIX)
				fieldsz += 2;
			realsz = dprec > fieldsz ? dprec : fieldsz;
			if ((flags & (LADJUST|ZEROPAD)) == 0 && width)
				for (n = realsz; n < width; n++)
					PUTC(' ');
			if (sign)
				PUTC(sign);
			if (flags & HEXPREFIX) {
				PUTC('0');
				PUTC((char)*fmt);
			}
			if ((flags & (LADJUST|ZEROPAD)) == ZEROPAD)
				for (n = realsz; n < width; n++)
					PUTC('0');
			for (n = fieldsz; n < dprec; n++)
				PUTC('0');
			n = size;
			while (--n >= 0)
				PUTC(*t++);
			if (flags & LADJUST)
				for (n = realsz; n < width; n++)
					PUTC(' ');
			cnt += width > realsz ? width : realsz;
			break;
		case '\0':
			PUTC(0x201);
			return cnt;
		default:
			PUTC((char)*fmt);
			cnt++;
		}
	}
}

void func_0000877C(char **pp, int c)
{
	if (c < 0x100)
		*(*pp)++ = c;
	else
		**pp = '\0';
}

