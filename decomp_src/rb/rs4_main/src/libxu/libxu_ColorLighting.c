#include "common.h"

/* libxu helpers (xu.h): inline asm ins, as the line table shows two lines each */
union _anon1;
union _anon1 { /* size 0x4 */
    void *vp;
    int *ip;
};
typedef union _anon1 xuPtr;
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};



void *xuAmbient(void *pkt, unsigned int col);
static int xuSetD0(int rt, int rs);
void *xuColor(void *pkt, unsigned int col);
void *xuColorMaterial(void *pkt, int type);
void *xuMaterial(void *pkt, int type, unsigned int col);
static int xuSetC0(int rt, int rs);
void *xuSpecular(void *pkt, float power);
static int xuSetF0(int rt, int rs);
static int f2i(float rs);
void *xuFrontFace(void *pkt, int mode);
void *xuShadeModel(void *pkt, int model);
void *xuLight(void *pkt, int n, int type, int comp, const ScePspFVector3 *vec);
static int xuSetC1(int rt, int rs);
void *xuLightMode(void *pkt, int ssc);
void *xuLightAtt(void *pkt, int n, float a, float b, float c);
void *xuLightSpot(void *pkt, int n, float s, float c, const ScePspFVector3 *vec);
void *xuLightColor(void *pkt, int n, int type, unsigned int col);

static inline int xuSetD0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 24" : "+r"(rt) : "r"(rs) : "memory");
	return rt;
}
static inline int xuSetC0(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 0, 8" : "+r"(rt) : "r"(rs) : "memory");
	return rt;
}
static inline int xuSetC1(int rt, int rs)
{
	__asm__ __volatile__ ("ins %0, %1, 8, 8" : "+r"(rt) : "r"(rs) : "memory");
	return rt;
}
static inline int xuSetF0(int rt, int rs)
{
	__asm__ __volatile__ ("srl %1, %1, 8\n\tins %0, %1, 0, 24" : "+r"(rt), "+r"(rs) : : "memory");
	return rt;
}
static inline int f2i(float rs) { union { float f; int i; } u; u.f = rs; return u.i; }


void *xuAmbient(void *pkt, unsigned int col)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x5C000000, col);
	pCmd.ip++;
	*pCmd.ip = xuSetD0(0x5D000000, col >> 24);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuColor(void *pkt, unsigned int col)
{
	return xuMaterial(pkt, 7, col);
}

void *xuColorMaterial(void *pkt, int type)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x53000000, type);
	pCmd.ip++;
	return pCmd.vp;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_ColorLighting", xuMaterial);

void *xuSpecular(void *pkt, float power)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetF0(0x5B000000, f2i(power));
	pCmd.ip++;
	return pCmd.vp;
}

void *xuFrontFace(void *pkt, int mode)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x52000000, mode);
	pCmd.ip++;
	return pCmd.vp;
}

void *xuShadeModel(void *pkt, int model)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x50000000, model);
	pCmd.ip++;
	return pCmd.vp;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_ColorLighting", xuLight);

void *xuLightMode(void *pkt, int ssc)
{
	xuPtr pCmd;
	pCmd.vp = pkt;
	*pCmd.ip = xuSetD0(0x5E000000, ssc);
	pCmd.ip++;
	return pCmd.vp;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_ColorLighting", xuLightAtt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_ColorLighting", xuLightSpot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/libxu/libxu_ColorLighting", xuLightColor);
