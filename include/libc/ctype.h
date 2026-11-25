#ifndef _CTYPE_H_
#define _CTYPE_H_
/* the parts of newlib 1.12.0's <ctype.h> used by the decompiled code */
#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200

extern const char _ctype_[];

#define	isalpha(c)	((_ctype_+1)[(unsigned)(c)]&(_U|_L))
#define	isupper(c)	((_ctype_+1)[(unsigned)(c)]&_U)
#define	islower(c)	((_ctype_+1)[(unsigned)(c)]&_L)
#define	isdigit(c)	((_ctype_+1)[(unsigned)(c)]&_N)
#define	isxdigit(c)	((_ctype_+1)[(unsigned)(c)]&(_X|_N))
#define	isspace(c)	((_ctype_+1)[(unsigned)(c)]&_S)

#define toupper(c) __extension__ ({ int __x = (c); islower(__x) ? (__x - 'a' + 'A') : __x;})
#define tolower(c) __extension__ ({ int __x = (c); isupper(__x) ? (__x - 'A' + 'a') : __x;})
#endif
