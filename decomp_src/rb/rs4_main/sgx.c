/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_00109C00;
extern unsigned char D_00109C50;
M2C_UNK sgxTickProc(float);                           /* extern */
extern int gSgxMallocFunc;
extern int gSgxFreeFunc;
extern int gSgxPrintFunc;
extern int gSgxDebugFlags;
extern int D_0011FBE4;
extern int D_0011FBE8;
extern int D_0011FBF0;
extern int D_0011FC00;

#include <stdarg.h>
int vsprintf(char *, const char *, va_list);
char *sgxNextLine(char *, char *);
void sgxCbCallMode(int);
void sgxMutexLock(int);
void sgxMutexUnlock(int);
void sgxSndFlush(void);
void *sgxStackMemAlloc(void *, int, int);
extern int gWork_11FBE0[];
typedef void (*SgxFreeFn)(void *);
typedef void (*SgxPrintFn)(const char *);
static inline char *SgxListFirst(char *l) { char *n = *(char **)(l + 4); return (*(int *)(n + 8) < 0) ? NULL : n; }
static inline char *SgxListNext(char *e) { char *n = *(char **)(e + 4); return (*(int *)(n + 8) < 0) ? NULL : n; }

void sgxDI();
void sgxEI();
char *sgxConfReadStr();
int atoi(const char *);
void *memset(void *, int, unsigned int);
char *sgxNextToken(char *, char *, const char *, const char *);

int sprintf(char *, const char *, ...);
void sgxPrintfPref(const char *a, const char *b, int line, const char *fmt, ...)
{
	char f[0x400];
	char buf[0x400];
	va_list ap;
	sprintf(f, "%s %s(%d) : %s", a, b, line, fmt);
	va_start(ap, fmt);
	vsprintf(buf, f, ap);
	sgxPrintf(buf);
}

void sgxPrintf(const char *fmt, ...)
{
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    vsprintf(buf, fmt, ap);
    ((SgxPrintFn)gSgxPrintFunc)(buf);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgx", D_00109CA8);

extern const char *gSgxPrefErr;
extern const char D_00109CA8[];
typedef void *(*SgxMallocFn)(unsigned int);
void *sgxMalloc(unsigned int size, int clear)
{
    void *p = ((SgxMallocFn)gSgxMallocFunc)(size);
    if (p == NULL) {
        if (gSgxDebugFlags & 1)
            sgxPrintfPref(gSgxPrefErr, D_00109CA8, 0x96, "can't allocate memory (%d)\n", size);
        return NULL;
    }
    if (clear) memset(p, 0, size);
    gWork_11FBE0[3] += size;
    return p;
}

void sgxFree(void *p)
{
    if (p != NULL) ((SgxFreeFn)gSgxFreeFunc)(p);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxNextToken);

char *sgxNextLine(char *s, char *buf)
{
    do {
        s = sgxNextToken(s, buf, ";\n", "\r\t ");
        if (*s == 0) break;
    } while (buf[0] == 0);
    return s;
}

int sgxGetLineCount(char *s)
{
    char buf[0x400];
    int n = 0;
    while (s = sgxNextLine(s, buf), *s != 0 || buf[0] != 0)
        n++;
    return n;
}

char *strcpy(char *, const char *);
int strcmp(const char *, const char *);
char *sgxConfReadStr(char *conf, const char *key, char *out, const char *def)
{
	char line[0x400];
	char tok[0x400];
	char *s, *p;
	if (conf != NULL) {
		s = conf;
		for (;;) {
			s = sgxNextLine(s, line);
			if (*s == 0 && line[0] == 0) break;
			p = sgxNextToken(line, tok, "=", "\t ");
			if (strcmp(tok, key) == 0) {
				sgxNextToken(p, out, "=", "\t ");
				return out;
			}
		}
	}
	strcpy(out, def);
	return out;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxConfReadInt);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sgxStrCpyN(unsigned char *arg0, unsigned char *arg1, int arg2) {
    int temp_a2;
    int var_a3;
    unsigned char *var_a0;
    unsigned char *var_a1;
    unsigned char var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = *var_a1;
    var_a3 = 0;
    if (var_v0 != 0) {
        temp_a2 = arg2 - 1;
        if (temp_a2 > 0) {
loop_2:
            *var_a0 = var_v0;
            var_a1 += 1;
            var_a3 += 1;
            var_v0 = *var_a1;
            var_a0 += 1;
            if (var_v0 != 0) {
                if (var_a3 < temp_a2) {
                    goto loop_2;
                }
            }
        }
    }
    *var_a0 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void sgxStrCatN(signed char *arg0, int arg1, int arg2) {
    unsigned int temp_v0;

    temp_v0 = strlen(arg0);
    sgxStrCpyN(&arg0[temp_v0], arg1, arg2 - temp_v0);
}

int sgxIsStrMatch(const char *a, const char *b)
{
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return *a == 0 && *b == 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxIsStrMatchWC);

int sgxIsStrIncWC(const char *s)
{
    while (*s != 0) {
        if (*s == '*' || *s == '?') return 1;
        s++;
    }
    return 0;
}

typedef struct SgxL { struct SgxL *next, *prev; int idx; int f; } SgxL;
void sgxListArrayInit(SgxL *head, SgxL *e, int n, int size)
{
	int i;
	for (i = 0; i < n; i++) {
		e->prev = e;
		e->idx = i;
		e->prev = head->prev;
		head->prev = e;
		e->next = head;
		e->f = 0;
		e->prev->next = e;
		e = (SgxL *)((char *)e + size);
	}
}

int sgxListEnumID(char *l, int *out)
{
    char *e;
    int n = 0;
    for (e = SgxListFirst(l); e != NULL; e = SgxListNext(e)) {
        if (out != NULL) out[n] = *(int *)(e + 8);
        n++;
    }
    return n;
}

void sgxAttrSetValueSafe(short *a, int idx, int v)
{
    if (idx >= 2 && idx < 13) {
        if (!((a[1] >> idx) & 1) || a[idx] != v) {
            int t0, t1;
            sgxDI();
            a[idx] = v;
            t1 = a[1];
            t0 = a[0];
            a[1] = t1 | (1 << idx);
            a[0] = t0 | (1 << idx);
            sgxEI();
        }
    }
}

void sgxAttrSetUpdateSafe(short *a, int bit)
{
	if ((unsigned int)(bit - 2) < 11) {
		int v;
		sgxDI();
		v = *a;
		*a = v | (1 << bit);
		sgxEI();
	}
}

void sgxAttrCopyUpdate(short *d, short *s)
{
	int i;
	int up = s[0];
	int en;
	if (up != 0) {
		en = s[1];
		for (i = 2; i < 13; i++) {
			if ((up >> i) & 1 && (en >> i) & 1)
				d[i] = s[i];
		}
		{
			int t0 = d[0], t1 = d[1];
			d[0] = t0 | up;
			d[1] = t1 | en;
		}
	}
}

void sgxAttrCopyEnable(short *d, short *s)
{
	int i;
	int en = s[1];
	if (en != 0) {
		for (i = 2; i < 13; i++) {
			if ((en >> i) & 1)
				d[i] = s[i];
		}
		{
			int t1 = d[1];
			d[1] = t1 | en;
		}
	}
	{
		int t0 = s[0], t1 = d[0];
		d[0] = t1 | t0;
	}
}

void sgxAttrMergeEnable(short *d, short *s)
{
    int i;
    int es = s[1];
    if (es != 0) {
        int ed = d[1];
        for (i = 2; i < 13; i++) {
            if ((es >> i) & 1) {
                if (!((ed >> i) & 1)) {
                    d[i] = s[i];
                } else {
                    switch (i) {
                    case 5: d[5] = ((d[5] + s[5] - 0x1000) & 0x1FFF) + 0x1000; break;
                    case 11: d[11] += s[11]; break;
                    default: d[i] = (d[i] * s[i]) >> 12; break;
                    }
                }
            }
        }
        { int t = d[1]; d[1] = t | es; }
    }
    { int t0 = s[0], t1 = d[0]; d[0] = t1 | t0; }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxStackMemOpen);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sgxStackMemClose(void *arg0) {
    return M2C_FIELD(arg0, int *, 4) + M2C_FIELD(arg0, int *, 8);
}

void *sgxStackMemAlloc(void *mv, int outv, int size)
{
    int *m = mv;
    void **out = (void **)outv;
    if (m[0] != 0 && out != NULL) {
        *out = (char *)m[0] + m[1];
        memset(*out, 0, size);
    }
    return (void *)(m[1] += size);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxStackMemAllocStr);

void *sgxStackMemAlign(int *m, int align)
{
    int cur = m[1];
    return sgxStackMemAlloc(m, 0, ((cur + align - 1) & -align) - cur);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgx", D_00109CE0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxTerm);

void sgxFlush(void)
{
    sgxCbCallMode(0);
    sgxMutexLock(gWork_11FBE0[9]);
    sgxSndFlush();
    sgxMutexUnlock(gWork_11FBE0[9]);
    sgxCbCallMode(1);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxTickProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
void sgxProc(float fparg0) {
    sgxFlush();
    sgxTickProc(fparg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetMallocFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxMallocFunc;
    gSgxMallocFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetFreeFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxFreeFunc;
    gSgxFreeFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetPrintFunc(int arg0) {
    int temp_v0;

    temp_v0 = gSgxPrintFunc;
    gSgxPrintFunc = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxSetDebugFlags(int arg0) {
    int temp_v0;

    temp_v0 = gSgxDebugFlags;
    gSgxDebugFlags = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetDebugFlags(void) {
    return gSgxDebugFlags;
}

int sgxSetMainThreadID(int id)
{
    int old = gWork_11FBE0[1];
    gWork_11FBE0[1] = id;
    return old;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetMainThreadID(void) {
    return D_0011FBE4;
}

int sgxSetSyncMode(unsigned int mode)
{
    int old = gWork_11FBE0[2];
    if (mode >= 2) return -1;
    gWork_11FBE0[2] = mode;
    return old;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetSyncMode(void) {
    return D_0011FBE8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxSetOutputMode);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxGetOutputMode(void) {
    return D_0011FBF0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxIsOutputSurround(void) {
    return D_0011FC00;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgx", sgxCent128ToPitch);
