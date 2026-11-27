/* cflags: -Os -fno-strength-reduce */
#include "common.h"
/* declarations recovered from DWARF */
typedef struct ScePspFMatrix4 ScePspFMatrix4 __attribute__((aligned(16)));
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4 __attribute__((aligned(16)));
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
union _anon1;
union _anon1 { /* size 0x4 */
    void *vp;
    int *ip;
};
typedef union _anon1 xuPtr;



void *xuBoneMatrix(void *pkt, int n, const ScePspFMatrix4 *m);
static int xuSetC0(int rt, int rs);
static int xuSetF0(int rt, int rs);
void *xuMorphWeight(void *pkt, int n, float f);
static int f2i(float rs);

/* libxu's xu.h helpers: inline asm ins (two source lines each in the line table) */
static inline int xuSetD0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 24" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetS0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 16" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetC0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 8" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetC1(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 8, 8" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetC2(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 16, 8" : "+r"(rt) : "r"(rs));
	return rt;
}
static inline int xuSetF0(int rt, int rs)
{
	__asm__ __volatile__ ("srl %1, %1, 8\n\tins %0, %1, 0, 24" : "+r"(rt), "+r"(rs));
	return rt;
}
static inline int f2i(float rs)
{
	union { float f; int i; } u;
	u.f = rs;
	return u.i;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_DeformParameter", xuBoneMatrix);

void *xuMorphWeight(void *pkt, int n, float f)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetF0(0x2C000000 + (n << 24), f2i(f));
	pCmd.ip++;
	return pCmd.vp;
}

