/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"


int putchar(int);
void PrintIndent(int n)
{
	while (n-- > 0)
		putchar('\t');
}

int printf(const char *, ...);
void PrintVector(const char *name, const float *v, int indent)
{
	PrintIndent(indent);
	printf("%s = { %f %f %f %f }\n", name, v[0], v[1], v[2], v[3]);
}

int puts(const char *);
extern const char D_00109944[];
void PrintTri(unsigned short *t, int indent)
{
	PrintIndent(indent++);
	puts("Triangle {");
	PrintIndent(indent);
	printf("iAttr = %d\n", t[3]);
	PrintIndent(indent);
	printf("aiPoint = { %d %d %d }\n", t[0], t[1], t[2]);
	PrintIndent(--indent);
	puts(D_00109944);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_dump_i3c", D_00109944);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_dump_i3c", PrintNode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_dump_i3c", PrintTree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_dump_i3c", I3cRoot__TextDump);

int I3dParser__PackSub(int *p, int base, int a, int b, int mode)
{
	int v = *p;
	if (v != 0) {
		switch (mode) {
		case 1: v += base; break;
		case 0: v -= base; break;
		default: return 0;
		}
		*p = v;
	}
	return 0;
}

int I3dParser__PackSub_ap(int *pp, int n, int base, int c, int d, int e, int mode)
{
	int *arr = 0;
	int i;
	if (mode == 0) arr = (int *)*pp;
	I3dParser__PackSub(pp, base, c, d, mode);
	if (mode == 1) arr = (int *)*pp;
	for (i = 0; i < n; i++)
		I3dParser__PackSub(&arr[i], base, c, e, mode);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int strcmp(const char *a, const char *b);
int I3sRoot__CheckIdString(signed char *arg0) {
    int var_a0;

    var_a0 = 0;
    if ((strcmp(arg0, "I3D_BIN") != 0) || (__builtin_allegrex_ext(M2C_FIELD(arg0, int *, 0x14), 0x18, 7) != 0x21)) {
        var_a0 = 3;
    }
    return var_a0;
}
