/* SDK libgim_picture gim_activate.o (1.9.2 -O2 -std=gnu9x): the SDK 6.6.0 src/gim_picture/gim_activate.c, preprocessed with the SDK headers and its Makefile's SCEGIM_SUPPORT_* defines, without sceGimPictureGetActiveImage/Palette; psp-gcc predefines __psp_gcc__, so allegrex.h uses the clz builtin (SCE_ALLEGREX_USE_BUILTIN) and gim_picture.h the builtin Pow2/CLZ/CTZ, and its gecmd.h the older address-of SCE_GE_EXTRACT_FLOAT24 macro */
/* cflags: -O2 -std=gnu9x */
#include "common.h"
static __inline__ int sceAllegrexClz(int x);
static __inline__ int sceAllegrexClo(int x);
static __inline__ int sceAllegrexCtz(int x);
static __inline__ int sceAllegrexCto(int x);
static __inline__ int sceAllegrexMax(int val1, int val2);
static __inline__ int sceAllegrexMin(int val1, int val2);
static __inline__ int sceAllegrexSeb(char val);
static __inline__ int sceAllegrexSeh(short val);
static __inline__ unsigned int sceAllegrexWsbw(unsigned int x);
static __inline__ unsigned int sceAllegrexWsbh(unsigned int x);
static __inline__ unsigned int sceAllegrexBitrev(unsigned int val);
static __inline__ unsigned int sceAllegrexRotl(unsigned int val, int n);
static __inline__ unsigned int sceAllegrexRotr(unsigned int val, int n);
static __inline__ unsigned int sceAllegrexExt(unsigned int x, unsigned int pos, unsigned int size);
static __inline__ unsigned int sceAllegrexIns(unsigned int val1, unsigned int val2, unsigned int pos, unsigned int size);
static __inline__ void sceAllegrexCache(int code, void *p);
static __inline__ void sceAllegrexSync(void);
static __inline__ int sceAllegrexCeil(float fs);
static __inline__ int sceAllegrexFloor(float fs);
static __inline__ int sceAllegrexRound(float fs);
static __inline__ int sceAllegrexTrunc(float fs);
static __inline__ float sceAllegrexSqrt(float fs);
static __inline__ int sceAllegrexClz(int x)
{
 return __builtin_allegrex_clz(x);
}
static __inline__ int sceAllegrexClo(int x)
{
 return (sceAllegrexClz(~x));
}
static __inline__ int sceAllegrexCtz(int x)
{
 int n = 1;
 unsigned int ui;
 ui = (unsigned int)x;
 if (ui==0) return (32);
 if ((ui & 0x0000FFFF)==0) { n = n + 16; ui = ui>>16; }
 if ((ui & 0x000000FF)==0) { n = n + 8; ui = ui>> 8; }
 if ((ui & 0x0000000F)==0) { n = n + 4; ui = ui>> 4; }
 if ((ui & 0x00000003)==0) { n = n + 2; ui = ui>> 2; }
 n = n - (ui & 1);
 return (n);
}
static __inline__ int sceAllegrexCto(int x)
{
 return (sceAllegrexCtz(~x));
}
static __inline__ int sceAllegrexMax(int val1, int val2)
{
 if (val1 > val2) {
  return (val1);
 } else {
  return (val2);
 }
}
static __inline__ int sceAllegrexMin(int val1, int val2)
{
 if (val1 < val2) {
  return (val1);
 } else {
  return (val2);
 }
}
static __inline__ int sceAllegrexSeb(char val)
{
 return val;
}
static __inline__ int sceAllegrexSeh(short val)
{
 return val;
}
static __inline__ unsigned int sceAllegrexWsbw(unsigned int x)
{
 return (((x & 0xFF)<<24) | ((x & 0xFF00)<<8) | ((x>>8) & 0xFF00) | ((x>>24) & 0xFF));
}
static __inline__ unsigned int sceAllegrexWsbh(unsigned int x)
{
 return (((x<<8) & 0xFF00FF00) | ((x>>8) & 0x00FF00FF));
}
static __inline__ unsigned int sceAllegrexBitrev(unsigned int val)
{
 int i;
 unsigned int n = 0;
 for (i=0; i<32; i++) {
  n |= ((val>>i) & 1)<<(31 - i);
 }
 return (n);
}
static __inline__ unsigned int sceAllegrexRotl(unsigned int val, int n)
{
 return ((val<<n) | (val>>(32 -n)));
}
static __inline__ unsigned int sceAllegrexRotr(unsigned int val, int n)
{
 return ((val<<(32 - n)) | (val>>n));
}
static __inline__ unsigned int sceAllegrexExt(unsigned int x, unsigned int pos, unsigned int size)
{
 return ((((x>>pos)<<(32 - size)))>>(32 - size));
}
static __inline__ unsigned int sceAllegrexIns(unsigned int val1, unsigned int val2, unsigned int pos, unsigned int size)
{
 unsigned int mask = 0xFFFFFFFF;
 mask = (mask<<(32 - (pos + size)))>>(32 - (pos + size));
 mask = (mask>>pos)<<pos;
 return ((val1 & (~mask)) | ((val2<<pos) & mask));
}
static __inline__ void sceAllegrexCache(int code, void *p)
{
 switch (code) {
  case 0x04:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x04), "r"(p) : "memory" );
   break;
  case 0x06:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x06), "r"(p) : "memory" );
   break;
  case 0x08:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x08), "r"(p) : "memory" );
   break;
  case 0x0A:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x0A), "r"(p) : "memory" );
   break;
  case 0x0B:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x0B), "r"(p) : "memory" );
   break;
  case 0x14:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x14), "r"(p) : "memory" );
   break;
  case 0x16:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x16), "r"(p) : "memory" );
   break;
  case 0x18:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x18), "r"(p) : "memory" );
   break;
  case 0x19:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x19), "r"(p) : "memory" );
   break;
  case 0x1A:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1A), "r"(p) : "memory" );
   break;
  case 0x1B:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1B), "r"(p) : "memory" );
   break;
  case 0x1C:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1C), "r"(p) : "memory" );
   break;
  case 0x1E:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1E), "r"(p) : "memory" );
   break;
  case 0x1F:
   __asm__ volatile ( "cache			%0, 0(%1)" : : "n"(0x1F), "r"(p) : "memory" );
   break;
  default:
   break;
 }
 return;
}
static __inline__ void sceAllegrexSync(void)
{
 __asm__ volatile (
  ".set			push\n"
  ".set			noreorder\n"
  "sync"
  ".set			pop\n"
  :
  :
  : "memory"
 );
 return;
}
static __inline__ int sceAllegrexCeil(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "ceil.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ int sceAllegrexFloor(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "floor.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ int sceAllegrexRound(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "round.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ int sceAllegrexTrunc(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "trunc.w.s		$f2, %1\n"
  "mfc1			%0, $f2\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$f2"
 );
 return (v);
}
static __inline__ float sceAllegrexSqrt(float fs)
{
 float fd;
 __asm__ (
  "sqrt.s			%0, %1\n"
  : "=f"(fd)
  : "f"(fs)
 );
 return (fd);
}
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
typedef float SceFloat;
typedef float SceFloat32;
typedef signed char SceSByte;
typedef signed char SceSByte8;
typedef unsigned char SceByte;
typedef unsigned char SceByte8;
typedef unsigned short SceWChar16;
typedef unsigned int SceWChar32;
typedef int SceBool;
typedef int SceIntPtr;
typedef unsigned int SceUIntPtr;
typedef void SceVoid;
typedef void * ScePVoid;
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
typedef unsigned int ScePspRGBA8888;
typedef unsigned short ScePspRGBA4444;
typedef unsigned short ScePspRGBA5551;
typedef unsigned short ScePspRGB565;
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
typedef int SceUID;
typedef unsigned int SceSize;
typedef unsigned char SceUChar;
typedef unsigned int SceUInt;
typedef int SceSSize;
typedef int SceMode;
__extension__ typedef long long SceOff;
__extension__ typedef long long SceIores;
static __inline__ int sceKernelIsCachedAddr(const void *v);
static __inline__ int sceKernelIsUncachedAddr(const void *v);
static __inline__ int sceKernelIsCachedAddr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 30, 1)==0U);
}
static __inline__ int sceKernelIsUncachedAddr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 30, 1)!=0U);
}
static __inline__ unsigned int sceKernelMakeCachedAddrUIntPtr(const void *v);
static __inline__ unsigned int sceKernelMakeUncachedAddrUIntPtr(const void *v);
static __inline__ unsigned int sceKernelMakePhysicalAddrUIntPtr(const void *v);
static __inline__ void *sceKernelMakeCachedAddr(const void *v);
static __inline__ void *sceKernelMakeUncachedAddr(const void *v);
static __inline__ void *sceKernelMakePhysicalAddr(const void *v);
static __inline__ unsigned int sceKernelMakeCachedAddrUIntPtr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakeCachedAddr(const void *_p)
{
 ScePspUnion32 u;
 u.ui = sceKernelMakeCachedAddrUIntPtr(_p);
 return u.p;
}
static __inline__ unsigned int sceKernelMakeUncachedAddrUIntPtr(const void *v)
{
 return (__builtin_allegrex_ins(0x40000000U, (unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakeUncachedAddr(const void *_p)
{
 ScePspUnion32 u;
 u.ui = sceKernelMakeUncachedAddrUIntPtr(_p);
 return u.p;
}
static __inline__ unsigned int sceKernelMakePhysicalAddrUIntPtr(const void *v)
{
 return (__builtin_allegrex_ext((unsigned int)v, 0, 29));
}
static __inline__ void *sceKernelMakePhysicalAddr(const void *_p)
{
 ScePspUnion32 u;
 u.ui = sceKernelMakePhysicalAddrUIntPtr(_p);
 return u.p;
}
void sceKernelDcacheWritebackAll(void);
void sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelDcacheWritebackRange(const void *start, unsigned int size);
int sceKernelDcacheWritebackInvalidateRange(const void *start, unsigned int size);
int sceKernelDcacheInvalidateRange(void *start, unsigned int size);
int sceKernelDcacheProbe(const void *addr);
int sceKernelDcacheProbeRange(const void *start, unsigned int size);
void sceKernelIcacheInvalidateAll(void);
int sceKernelIcacheInvalidateRange(const void *start, unsigned int size);
int sceKernelIcacheProbe(const void *addr);
static __inline__ void sceKernelDcacheFillRange(const void *start, unsigned int size);
static __inline__ void sceKernelDcacheCreateDirtyExclusiveRange(void *start, unsigned int size);
static __inline__ void sceKernelDcacheFillRange(const void *start, unsigned int size)
{
 unsigned int uiStart, uiEnd;
 unsigned int ui;
 uiStart = (unsigned int)start;
 if (__builtin_allegrex_ext(uiStart, 30, 1)!=0U) {
  return;
 }
 uiEnd = uiStart + size;
 for (ui=uiStart; ui<uiEnd; ui+=64) {
  __builtin_allegrex_cache(0x1E, (void *)ui);
 }
 return;
}
static __inline__ void sceKernelDcacheCreateDirtyExclusiveRange(void *start, unsigned int size)
{
 unsigned int uiStart, uiEnd;
 unsigned int ui;
 uiStart = (unsigned int)start;
 if (__builtin_allegrex_ext(uiStart, 30, 1)!=0U) {
  return;
 }
 uiEnd = (((uiStart + size - 64) | (64 - 1)) ^ (64 - 1));
 ui = (((uiStart + 64 - 1) | (64 - 1)) ^ (64 - 1));
 while (ui <= uiEnd) {
  __builtin_allegrex_cache(0x18, (void *)ui);
  ui += 64;
 }
 return;
}
void *sceKernelMemcpy(void *dest, const void *src, unsigned int size);
void *sceKernelMemset(void *start, int c, unsigned int size);
static __inline__ void sceKernelDcacheMemsetInline(void *start, int c, unsigned int size);
static __inline__ void sceKernelDcacheMemcpyInline(void *dest, const void *src, unsigned int size);
static __inline__ void sceKernelDcacheMemsetInline(void *start, int c, unsigned int size)
{
 __asm__ volatile (
  ".set			push\n"
  ".set			noreorder\n"
  ".set			noat\n"
  "ext			$1,  %0,  30,  1\n"
  "bne			$1,  $0,  3f\n"
  "addu			%2,  %0,  %2\n"
  "ins			%1,  %1,   8,  8\n"
  "ins			%1,  %1,  16, 16\n"
 "0:\n"
  "beq			%0,  %2,  9f\n"
  "andi			$1,  %0,  0x003F\n"
  "beq			$1,  $0,  1f\n"
  "sb				%1,  0(%0)\n"
  "j				0b\n"
  "addiu			%0,  %0,  1\n"
 "1:\n"
  "move			$1,  %2\n"
  "ins			$1,  $0,   0,  6\n"
  "beq			%0,  $1, 3f\n"
  "nop\n"
 "2:\n"
  "cache			0x18, 0(%0)\n"
  "sw				%1,   0(%0)\n"
  "sw				%1,   4(%0)\n"
  "sw				%1,   8(%0)\n"
  "sw				%1,  12(%0)\n"
  "sw				%1,  16(%0)\n"
  "sw				%1,  20(%0)\n"
  "sw				%1,  24(%0)\n"
  "sw				%1,  28(%0)\n"
  "sw				%1,  32(%0)\n"
  "sw				%1,  36(%0)\n"
  "sw				%1,  40(%0)\n"
  "sw				%1,  44(%0)\n"
  "sw				%1,  48(%0)\n"
  "sw				%1,  52(%0)\n"
  "sw				%1,  56(%0)\n"
  "addiu			%0,  %0,  64\n"
  "bne			%0,  $1,  2b\n"
  "sw				%1,  -4(%0)\n"
 "3:\n"
  "beq			%0,  %2,  9f\n"
  "addiu			%0,  %0,  1\n"
  "j				3b\n"
  "sb				%1,  -1(%0)\n"
 "9:\n"
  ".set			pop\n"
  : "+r"(start), "+r"(c), "+r"(size)
  :
  : "memory", "$1"
 );
 return;
}
static __inline__ void sceKernelDcacheMemcpyInline(void *dest, const void *src, unsigned int size)
{
 unsigned int dend;
 __asm__ volatile (
  ".set			push\n"
  ".set			noreorder\n"
  ".set			noat\n"
  "or				%3,  %0,  %1\n"
  "ext			%3,  %0,  30,  1\n"
  "bne			%3,  $0,  3f\n"
  "addu			%3,  %0,  %2\n"
  "sltu			$1,  %2,  128\n"
  "bnez			$1,  2f\n"
  "xor			$1,  %0,  %1\n"
  "andi			$1,  $1,  0x0003\n"
  "bne			$1,  $0,  3f\n"
  "addiu			%2,  %0,  63\n"
  "ins			%2,  $0,  0, 6\n"
 "0:\n"
  "beq			%2,  %0,  8f\n"
  "lbu			$1,   0(%1)\n"
  "addiu			%0,  %0,  1\n"
  "addiu			%1,  %1,  1\n"
  "j				0b\n"
  "sb				$1,  -1(%0)\n"
 "8:\n"
  "move			$1,  %3\n"
  "ins			$1,  $0,  0,  6\n"
 "1:\n"
  "cache			0x18, 0(%0)\n"
  "lw				%2,   0(%1)\n"
  "sw				%2,   0(%0)\n"
  "lw				%2,   4(%1)\n"
  "sw				%2,   4(%0)\n"
  "lw				%2,   8(%1)\n"
  "sw				%2,   8(%0)\n"
  "lw				%2,  12(%1)\n"
  "sw				%2,  12(%0)\n"
  "lw				%2,  16(%1)\n"
  "sw				%2,  16(%0)\n"
  "lw				%2,  20(%1)\n"
  "sw				%2,  20(%0)\n"
  "lw				%2,  24(%1)\n"
  "sw				%2,  24(%0)\n"
  "lw				%2,  28(%1)\n"
  "sw				%2,  28(%0)\n"
  "lw				%2,  32(%1)\n"
  "sw				%2,  32(%0)\n"
  "lw				%2,  36(%1)\n"
  "sw				%2,  36(%0)\n"
  "lw				%2,  40(%1)\n"
  "sw				%2,  40(%0)\n"
  "lw				%2,  44(%1)\n"
  "sw				%2,  44(%0)\n"
  "lw				%2,  48(%1)\n"
  "sw				%2,  48(%0)\n"
  "lw				%2,  52(%1)\n"
  "sw				%2,  52(%0)\n"
  "lw				%2,  56(%1)\n"
  "sw				%2,  56(%0)\n"
  "addiu			%0,  %0,  64\n"
  "lw				%2,  60(%1)\n"
  "addiu			%1,  %1,  64\n"
  "bne			%0,  $1,  1b\n"
  "sw				%2,  60-64(%0)\n"
 "2:\n"
  "beq			%0,  %3,  9f\n"
  "nop\n"
 "3:\n"
  "addiu			%0,  %0,  1\n"
  "lbu			%2,   0(%1)\n"
  "addiu			%1,  %1,  1\n"
  "bne			%0,  %3,  3b\n"
  "sb				%2,  -1(%0)\n"
 "9:\n"
  ".set			pop\n"
  : "+r"(dest), "+r"(src), "+r"(size), "=&r"(dend)
  :
  : "memory", "$1"
 );
 return;
}
typedef struct SceKernelUtilsMd5Context {
 unsigned int h[4];
 unsigned int pad;
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long int ullTotalLen;
 unsigned char buf[64];
} SceKernelUtilsMd5Context;
int sceKernelUtilsMd5Digest(const void *plain, unsigned int uiLen, unsigned char *digest);
int sceKernelUtilsMd5BlockInit(SceKernelUtilsMd5Context *pContext);
int sceKernelUtilsMd5BlockUpdate(SceKernelUtilsMd5Context *pContext, const void *plain, unsigned int uiLen);
int sceKernelUtilsMd5BlockResult(SceKernelUtilsMd5Context *pContext, unsigned char *digest);
typedef struct SceKernelUtilsSha1Context {
 unsigned int h[5];
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long int ullTotalLen;
 unsigned char buf[64];
} SceKernelUtilsSha1Context;
int sceKernelUtilsSha1Digest(const void *plain, unsigned int len, unsigned char *digest);
int sceKernelUtilsSha1BlockInit(SceKernelUtilsSha1Context *pContext);
int sceKernelUtilsSha1BlockUpdate(SceKernelUtilsSha1Context *pContext, const void *plain, unsigned int uiLen);
int sceKernelUtilsSha1BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);
typedef struct SceKernelUtilsMt19937Context {
 unsigned int count;
 unsigned int state[624];
} SceKernelUtilsMt19937Context;
int sceKernelUtilsMt19937Init(SceKernelUtilsMt19937Context *pCtx, unsigned int seed);
unsigned int sceKernelUtilsMt19937UInt(SceKernelUtilsMt19937Context *pCtx);
int sceKernelPowerLock(int locktype);
int sceKernelPowerUnlock(int locktype);
int sceKernelVolatileMemLock(int arg, void **ppAdr, unsigned int *puiSize);
int sceKernelVolatileMemTryLock(int arg, void **ppAdr, unsigned int *puiSize);
int sceKernelVolatileMemUnlock(int arg);
int sceKernelPowerTick(int ticktype);
unsigned char sceKernelGetGPI(void);
void sceKernelSetGPO(unsigned char gpo);
void sceKernelPutUserLog(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
SceUID sceKernelDeci2pOpen(const char *protoname, unsigned short protonum, SceSize bufsize, SceUInt attr, const void *optParam);
int sceKernelDeci2pClose(SceUID socketid);
int sceKernelDeci2pRead(SceUID socketid, void *buf, SceSize nbyte);
int sceKernelDeci2pWrite(SceUID socketid, const void *buf, SceSize nbyte);
int sceKernelDeci2pRegisterCallback(SceUID socketid, SceUID cbid);
int sceKernelRegisterStdoutPipe(SceUID uid);
int sceKernelRegisterStderrPipe(SceUID uid);
int sceDmacMemcpy(void *pDst, const void *pSrc, unsigned int uiSize);
typedef unsigned int size_t;
typedef __builtin_va_list __gnuc_va_list;
typedef long _off_t;
__extension__ typedef long long _off64_t;
typedef int _ssize_t;
typedef unsigned int wint_t;
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
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;
};
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
extern struct _reent *_impure_ptr ;
void _reclaim_reent (struct _reent *);
typedef short int __int16_t;
typedef unsigned short int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
__extension__ typedef long long __int64_t;
__extension__ typedef unsigned long long __uint64_t;
typedef int ptrdiff_t;
typedef int wchar_t;
typedef long int __off_t;
typedef int __pid_t;
__extension__ typedef long long int __loff_t;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long clock_t;
typedef long time_t;
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
typedef long fd_mask;
typedef struct _types_fd_set {
 fd_mask fds_bits[(((64)+(((sizeof (fd_mask) * 8))-1))/((sizeof (fd_mask) * 8)))];
} _types_fd_set;

typedef __FILE FILE;
typedef _fpos_t fpos_t;
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


typedef struct
{
  int quot;
  int rem;
} div_t;
typedef struct
{
  long quot;
  long rem;
} ldiv_t;
typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;
extern int __mb_cur_max;
void abort (void) __attribute__ ((noreturn));
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);
float atoff (const char *__nptr);
int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, int (* _compar) (const void *, const void *));
void * calloc (size_t __nmemb, size_t __size);
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((noreturn));
void free (void *);
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);
char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);
long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size);
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *, const char *, size_t);
int _mbtowc_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *, const char *, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *, const char *, size_t, _mbstate_t *);
size_t wcstombs (char *, const wchar_t *, size_t);
size_t _wcstombs_r (struct _reent *, char *, const wchar_t *, size_t, _mbstate_t *);
int mkstemp (char *);
char * mktemp (char *);
void qsort (void * __base, size_t __nmemb, size_t __size, int(*_compar)(const void *, const void *));
int rand (void);
void * realloc (void * __r, size_t __size);
void srand (unsigned __seed);
double strtod (const char *__n, char **__end_PTR);
double _strtod_r (struct _reent *,const char *__n, char **__end_PTR);
float strtof (const char *__n, char **__end_PTR);
long strtol (const char *__n, char **__end_PTR, int __base);
long _strtol_r (struct _reent *,const char *__n, char **__end_PTR, int __base);
unsigned long strtoul (const char *__n, char **__end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *__n, char **__end_PTR, int __base);
int system (const char *__string);
long a64l (const char *__input);
char * l64a (long __input);
char * _l64a_r (struct _reent *,long __input);
int on_exit (void (*__func)(int, void *),void * __arg);
void _Exit (int __status) __attribute__ ((noreturn));
int putenv (const char *__string);
int _putenv_r (struct _reent *, const char *__string);
int setenv (const char *__string, const char *__value, int __overwrite);
int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);
char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);
double drand48 (void);
double _drand48_r (struct _reent *);
double erand48 (unsigned short [3]);
double _erand48_r (struct _reent *, unsigned short [3]);
long jrand48 (unsigned short [3]);
long _jrand48_r (struct _reent *, unsigned short [3]);
void lcong48 (unsigned short [7]);
void _lcong48_r (struct _reent *, unsigned short [7]);
long lrand48 (void);
long _lrand48_r (struct _reent *);
long mrand48 (void);
long _mrand48_r (struct _reent *);
long nrand48 (unsigned short [3]);
long _nrand48_r (struct _reent *, unsigned short [3]);
unsigned short *
       seed48 (unsigned short [3]);
unsigned short *
       _seed48_r (struct _reent *, unsigned short [3]);
void srand48 (long);
void _srand48_r (struct _reent *, long);
long long atoll (const char *__nptr);
long long _atoll_r (struct _reent *, const char *__nptr);
long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *__n, char **__end_PTR, int __base);
long long _strtoll_r (struct _reent *, const char *__n, char **__end_PTR, int __base);
unsigned long long strtoull (const char *__n, char **__end_PTR, int __base);
unsigned long long _strtoull_r (struct _reent *, const char *__n, char **__end_PTR, int __base);
void cfree (void *);
char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);
void * _malloc_r (struct _reent *, size_t);
void * _calloc_r (struct _reent *, size_t, size_t);
void _free_r (struct _reent *, void *);
void * _realloc_r (struct _reent *, void *, size_t);
void _mstats_r (struct _reent *, char *);
int _system_r (struct _reent *, const char *);
void __eprintf (const char *, const char *, unsigned int, const char *);


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

static __inline__ unsigned int sceGeExtractFloat24(float _float32);
static __inline__ unsigned int sceGeExtractFloat24(float _float32)
{
 ScePspUnion32 u;
 u.f = _float32;
 return (u.ui>>8);
}
unsigned int sceGeEdramGetSize(void);
void *sceGeEdramGetAddr(void);
int sceGeEdramSetAddrTranslation(int width);
unsigned int sceGeGetCmd(int cmdno);
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
enum {
 SCEGIM_BASE_RESERVED = 0x0000,
 SCEGIM_BASE_PRIVATE = 0x1000,
 SCEGIM_BASE_PUBLIC = 0x4000,
 SCEGIM_BLOCK = 0x0001,
 SCEGIM_FILE = 0x0002,
 SCEGIM_PICTURE = 0x0003,
 SCEGIM_IMAGE = 0x0004,
 SCEGIM_PALETTE = 0x0005,
 SCEGIM_SEQUENCE = 0x0006,
 SCEGIM_FILE_INFO = 0x00ff
} ;
enum {
 SCEGIM_FORMAT_RGBA5650 = 0,
 SCEGIM_FORMAT_RGBA5551 = 1,
 SCEGIM_FORMAT_RGBA4444 = 2,
 SCEGIM_FORMAT_RGBA8888 = 3,
 SCEGIM_FORMAT_INDEX4 = 4,
 SCEGIM_FORMAT_INDEX8 = 5,
 SCEGIM_FORMAT_INDEX16 = 6,
 SCEGIM_FORMAT_INDEX32 = 7,
 SCEGIM_FORMAT_DXT1 = 8,
 SCEGIM_FORMAT_DXT3 = 9,
 SCEGIM_FORMAT_DXT5 = 10,
 SCEGIM_FORMAT_DXT1EXT = 264,
 SCEGIM_FORMAT_DXT3EXT = 265,
 SCEGIM_FORMAT_DXT5EXT = 266
} ;
enum {
 SCEGIM_ORDER_NORMAL = 0,
 SCEGIM_ORDER_PSPIMAGE = 1
} ;
enum {
 SCEGIM_TYPE_GENERIC = 0,
 SCEGIM_TYPE_MIPMAP = 1,
 SCEGIM_TYPE_MIPMAP2 = 2,
 SCEGIM_TYPE_SEQUENCE = 3
} ;
enum {
 SCEGIM_INTERP_TYPEMASK = 0x0f,
 SCEGIM_INTERP_DISSOLVE = 0x80,
 SCEGIM_INTERP_EVENT = 0x40,
 SCEGIM_INTERP_CONSTANT = 0,
 SCEGIM_INTERP_LINEAR = 1
} ;
enum {
 SCEGIM_REPEAT_HOLD = 0,
 SCEGIM_REPEAT_CYCLE = 1
} ;
enum {
 SCEGIM_PARAM_IMAGE_INDEX = 0,
 SCEGIM_PARAM_IMAGE_PLANE = 1,
 SCEGIM_PARAM_IMAGE_LEVEL = 2,
 SCEGIM_PARAM_IMAGE_FRAME = 3,
 SCEGIM_PARAM_PALETTE_INDEX = 8,
 SCEGIM_PARAM_PALETTE_LEVEL = 10,
 SCEGIM_PARAM_PALETTE_FRAME = 11,
 SCEGIM_PARAM_CROP_U = 16,
 SCEGIM_PARAM_CROP_V = 17,
 SCEGIM_PARAM_CROP_W = 18,
 SCEGIM_PARAM_CROP_H = 19,
 SCEGIM_PARAM_BLEND_MODE = 32,
 SCEGIM_PARAM_FUNC_MODE = 34,
 SCEGIM_PARAM_FUNC_COMP = 35,
 SCEGIM_PARAM_FILTER_MAG = 36,
 SCEGIM_PARAM_FILTER_MIN = 37,
 SCEGIM_PARAM_WRAP_U = 38,
 SCEGIM_PARAM_WRAP_V = 39
} ;
enum {
 SCEGIM_BLEND_OFF = 0,
 SCEGIM_BLEND_MIX = 1,
 SCEGIM_BLEND_ADD = 2,
 SCEGIM_BLEND_SUB = 3,
 SCEGIM_BLEND_MIN = 4,
 SCEGIM_BLEND_MAX = 5,
 SCEGIM_BLEND_ABS = 6
} ;
enum {
 SCEGIM_FUNC_MODULATE = 0,
 SCEGIM_FUNC_DECAL = 1,
 SCEGIM_FUNC_RGB = 0,
 SCEGIM_FUNC_RGBA = 1
} ;
enum {
 SCEGIM_FILTER_NEAREST = 0,
 SCEGIM_FILTER_LINEAR = 1,
 SCEGIM_FILTER_NEAREST_MIPMAP_NEAREST = 4,
 SCEGIM_FILTER_LINEAR_MIPMAP_NEAREST = 5,
 SCEGIM_FILTER_NEAREST_MIPMAP_LINEAR = 6,
 SCEGIM_FILTER_LINEAR_MIPMAP_LINEAR = 7
} ;
enum {
 SCEGIM_WRAP_REPEAT = 0,
 SCEGIM_WRAP_CLAMP = 1
} ;
typedef struct {
 unsigned int signature ;
 unsigned int version ;
 unsigned int style ;
 unsigned int option ;
} SceGimHeader ;
typedef struct {
 unsigned short type ;
 unsigned short unused ;
 unsigned int next_offs ;
 unsigned int child_offs ;
 unsigned int data_offs ;
} SceGimChunk ;
static __inline__ int SCEGIM_CHUNK_TYPE( const SceGimChunk *chunk )
{
 return chunk->type ;
}
static __inline__ SceGimChunk *SCEGIM_CHUNK_NEXT( const SceGimChunk *chunk )
{
 return (SceGimChunk *)( (char *)chunk + chunk->next_offs ) ;
}
static __inline__ SceGimChunk *SCEGIM_CHUNK_CHILD( const SceGimChunk *chunk )
{
 return (SceGimChunk *)( (char *)chunk + chunk->child_offs ) ;
}
static __inline__ void *SCEGIM_CHUNK_DATA( const SceGimChunk *chunk )
{
 return (char *)chunk + chunk->data_offs ;
}
static __inline__ int SCEGIM_CHUNK_SIZE( const SceGimChunk *chunk )
{
 return chunk->next_offs ;
}
static __inline__ int SCEGIM_CHUNK_TAGSIZE( const SceGimChunk *chunk )
{
 (void)chunk ;
 return 16 ;
}
static __inline__ int SCEGIM_CHUNK_DATASIZE( const SceGimChunk *chunk )
{
 return chunk->child_offs - chunk->data_offs ;
}
static __inline__ int SCEGIM_CHUNK_CHILDSIZE( const SceGimChunk *chunk )
{
 return chunk->next_offs - chunk->child_offs ;
}
static __inline__ void *SCEGIM_CHUNK_SKIPSTRING( const char *str, int align )
{
 str += strlen( str ) + 1 ;
 align -= 1 ;
 return (void *)( ( (int)str + align ) & ~align ) ;
}
typedef struct {
 unsigned short header_size ;
 unsigned short reference ;
 unsigned short format ;
 unsigned short order ;
 unsigned short width ;
 unsigned short height ;
 unsigned short bpp ;
 unsigned short pitch_align ;
 unsigned short height_align ;
 unsigned short dim_count ;
 unsigned short reserved ;
 unsigned short reserved2 ;
 unsigned int offsets ;
 unsigned int images ;
 unsigned int total ;
 unsigned int plane_mask ;
 unsigned short level_type ;
 unsigned short level_count ;
 unsigned short frame_type ;
 unsigned short frame_count ;
} SceGimImageHeader ;
typedef SceGimImageHeader SceGimPaletteHeader ;
typedef struct {
 unsigned short header_size ;
 unsigned short reference ;
 unsigned short frame_start ;
 unsigned short frame_end ;
 unsigned short frame_rate ;
 unsigned short frame_repeat ;
 unsigned short n_constants ;
 unsigned short n_functions ;
 unsigned int constants ;
 unsigned int functions ;
 unsigned int keyframes ;
 unsigned int total ;
} SceGimSequenceHeader ;
typedef struct {
 unsigned short param ;
 short value ;
} SceGimConstant ;
typedef struct {
 unsigned short param ;
 unsigned short interp ;
 unsigned int keyframes ;
} SceGimFunction ;
typedef struct {
 short count ;
 short values[ 1 ] ;
} SceGimKeyframe ;
typedef struct {
 char project_name[ 1 ] ;
} SceGimFileInfo ;
typedef struct SceGimMetrics SceGimMetrics ;
struct SceGimMetrics {
 int memory_size ;
 int memory_size2 ;
 int picture_count ;
 int picture_size ;
 int image_count ;
 int image_size ;
 int palette_count ;
 int palette_size ;
 int sequence_count ;
 int sequence_size ;
} ;
int sceGimPictureGetMetrics( SceGimMetrics *buf, int size, const SceGimChunk *chunk ) ;
int sceGimPictureAddMetrics( SceGimMetrics *buf, int size, const SceGimChunk *chunk ) ;
int sceGimPictureGetMemoryClusterSize( const SceGimMetrics *buf, int size, int align ) ;
int sceGimPictureGetMemoryClusterSizeEx( const SceGimMetrics *buf, int size, int align, int dup_flags ) ;
int sceGimPictureGetMemoryClusterSize2( const SceGimMetrics *buf, int size, int align ) ;
int sceGimPictureGetMemoryClusterSize2Ex( const SceGimMetrics *buf, int size, int align, int dup_flags ) ;
static __inline__ void sceGimPictureGetMemoryClusterSizes( int *sizes, const int *aligns, const SceGimChunk *chunk )
{
 SceGimMetrics pm ;
 if ( sizes == 0 || aligns == 0 ) return ;
 sceGimPictureGetMetrics( &pm, sizeof( pm ), chunk ) ;
 sizes[ 0 ] = sceGimPictureGetMemoryClusterSize( &pm, sizeof( pm ), aligns[ 0 ] ) ;
 sizes[ 1 ] = sceGimPictureGetMemoryClusterSize2( &pm, sizeof( pm ), aligns[ 1 ] ) ;
}
enum {
 SCEGIM_DUPLICATE_REFERENCE = 0x0000,
 SCEGIM_DUPLICATE_STRUCTURE = 0x0001,
 SCEGIM_DUPLICATE_AUTOMATIC = 0x0002,
 SCEGIM_DUPLICATE_ALL = 0xffff,
 SCEGIM_DUPLICATE_PICTURE = 0x0008,
 SCEGIM_DUPLICATE_IMAGE = 0x0010,
 SCEGIM_DUPLICATE_PALETTE = 0x0020,
 SCEGIM_DUPLICATE_SEQUENCE = 0x0040
} ;
enum {
 SCEGIM_ENABLE_ALL = 0xffff,
 SCEGIM_ENABLE_DISSOLVE = 0x0001,
 SCEGIM_ENABLE_FACTOR = 0x0002,
 SCEGIM_ENABLE_CROP = 0x0004,
 SCEGIM_ENABLE_BLEND = 0x0100,
 SCEGIM_ENABLE_FUNC = 0x0200,
 SCEGIM_ENABLE_FILTER = 0x0400,
 SCEGIM_ENABLE_WRAP = 0x0800
} ;
enum {
 SCEGIM_ANIMATE_ALL = 0xffff,
 SCEGIM_ANIMATE_FRAME = 0x0001,
 SCEGIM_ANIMATE_PARAM = 0x0002
} ;
enum {
 SCEGIM_ACTIVATE_ALL = 0xffff,
 SCEGIM_ACTIVATE_TEXTURE = 0x0001,
 SCEGIM_ACTIVATE_RENDERSTATE = 0x0002
} ;
enum {
 SCEGIM_CACHE_ALL = 0xffff,
 SCEGIM_CACHE_TEXTURE = 0x0001,
 SCEGIM_CACHE_PIXEL = 0x0002
} ;
typedef struct SceGimPicture SceGimPicture ;
void sceGimPictureSetMemoryManager( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGimPictureSetMemoryManager2( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGimPictureSetMemoryManager3( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void *sceGimPictureOpenMemoryCluster( size_t size, size_t align ) ;
void *sceGimPictureOpenMemoryCluster2( size_t size, size_t align ) ;
void *sceGimPictureOpenMemoryCluster3( size_t size, size_t align ) ;
int sceGimPictureCloseMemoryCluster( void ) ;
int sceGimPictureCloseMemoryCluster2( void ) ;
int sceGimPictureCloseMemoryCluster3( void ) ;
void *sceGimPictureAllocMemory( size_t size ) ;
void sceGimPictureFreeMemory( void *addr ) ;
void *sceGimPictureAllocMemory2( size_t size ) ;
void sceGimPictureFreeMemory2( void *addr ) ;
void *sceGimPictureAllocMemory3( size_t size ) ;
void sceGimPictureFreeMemory3( void *addr ) ;
_Bool sceGimPictureCheckFileHeader( const void *buf, int size ) ;
int sceGimPictureGetChunkCount( const void *buf, int size ) ;
SceGimChunk *sceGimPictureGetChunk( const void *buf, int size, int idx ) ;
SceGimChunk *sceGimPictureGetRootChunk( const void *buf, int size ) ;
int sceGimPictureCountChildChunk( const SceGimChunk *chunk, int type ) ;
SceGimChunk *sceGimPictureFindChildChunk( const SceGimChunk *chunk, int type, int idx ) ;
SceGimPicture *sceGimPictureCreate( const SceGimChunk *chunk ) ;
void sceGimPictureDelete( SceGimPicture *picture ) ;
SceGimPicture *sceGimPictureDuplicate( SceGimPicture *picture, int flags ) ;
_Bool sceGimPictureLoadFile( SceGimPicture *picture, const void *buf, int size, int idx ) ;
_Bool sceGimPictureLoadTm2( SceGimPicture *picture, const void *buf, int size, int idx ) ;
_Bool sceGimPictureLoadTga( SceGimPicture *picture, const void *buf, int size ) ;
_Bool sceGimPictureLoadBmp( SceGimPicture *picture, const void *buf, int size ) ;
_Bool sceGimPictureLoad( SceGimPicture *picture, const SceGimChunk *chunk ) ;
void sceGimPictureUnload( SceGimPicture *picture ) ;
void sceGimPictureReconfigure( SceGimPicture *picture ) ;
void sceGimPictureAnimate( SceGimPicture *picture, float step ) ;
void sceGimPictureAnimateEx( SceGimPicture *picture, float step, int flags ) ;
void sceGimPictureControl( SceGimPicture *picture, int param, float value ) ;
_Bool sceGimPictureActivate( SceGimPicture *picture ) ;
_Bool sceGimPictureActivateEx( SceGimPicture *picture, unsigned int **pkt, unsigned int *size, int flags ) ;
_Bool sceGimPictureActivateTexture( SceGimPicture *picture ) ;
_Bool sceGimPictureActivateRenderState( SceGimPicture *picture ) ;
_Bool sceGimPictureLoadCache( SceGimPicture *picture ) ;
_Bool sceGimPictureLoadCacheEx( SceGimPicture *picture, int flags ) ;
void sceGimPictureUnloadCache( SceGimPicture *picture ) ;
void sceGimPictureUnloadCacheEx( SceGimPicture *picture, int flags ) ;
void sceGimPictureSetEnableBits( SceGimPicture *picture, int bits, int value ) ;
int sceGimPictureGetEnableBits( SceGimPicture *picture ) ;
void sceGimPictureSetImageCrop( SceGimPicture *picture, const float *crop ) ;
const float *sceGimPictureGetImageCrop( SceGimPicture *picture ) ;
SceGimImageHeader *sceGimPictureGetImage( SceGimPicture *picture ) ;
SceGimPaletteHeader *sceGimPictureGetPalette( SceGimPicture *picture ) ;
SceGimImageHeader *sceGimPictureGetActiveImage( SceGimPicture *picture ) ;
SceGimPaletteHeader *sceGimPictureGetActivePalette( SceGimPicture *picture ) ;
void *sceGimPictureGetImagePixels( SceGimPicture *picture, int level, int frame ) ;
void *sceGimPictureGetPalettePixels( SceGimPicture *picture, int level, int frame ) ;
void sceGimPictureSetImagePixels( SceGimPicture *picture, int level, int frame, void *pixels ) ;
void sceGimPictureSetPalettePixels( SceGimPicture *picture, int level, int frame, void *pixels ) ;
_Bool sceGimPictureReallocImage( SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels ) ;
_Bool sceGimPictureReallocImageEx( SceGimPicture *picture, int format, int order, int w, int h, int level, int frame, void *pixels ) ;
_Bool sceGimPictureReallocPalette( SceGimPicture *picture, int format, int w, int level, int frame, void *pixels ) ;
_Bool sceGimPictureHasAnimation( SceGimPicture *picture ) ;
void sceGimPictureSetFrameLoop( SceGimPicture *picture, float start, float end ) ;
const float *sceGimPictureGetFrameLoop( SceGimPicture *picture ) ;
void sceGimPictureSetFrameRate( SceGimPicture *picture, float fps ) ;
float sceGimPictureGetFrameRate( SceGimPicture *picture ) ;
void sceGimPictureSetFrameRepeat( SceGimPicture *picture, int mode ) ;
int sceGimPictureGetFrameRepeat( SceGimPicture *picture ) ;
void sceGimPictureSetFrame( SceGimPicture *picture, float frame ) ;
float sceGimPictureGetFrame( SceGimPicture *picture ) ;
void sceGimPictureSetImageFrame( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetImageFrame( SceGimPicture *picture ) ;
void sceGimPictureSetImageFrame2( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetImageFrame2( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteFrame( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetPaletteFrame( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteFrame2( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetPaletteFrame2( SceGimPicture *picture ) ;
void sceGimPictureSetDissolve( SceGimPicture *picture, float dissolve ) ;
float sceGimPictureGetDissolve( SceGimPicture *picture ) ;
int sceGimPictureGetSequenceCount( SceGimPicture *picture ) ;
SceGimSequenceHeader *sceGimPictureGetSequence( SceGimPicture *picture, int idx ) ;
void sceGimPictureSetCurrentSequence( SceGimPicture *picture, int idx ) ;
int sceGimPictureGetCurrentSequence( SceGimPicture *picture ) ;
int sceGimPictureGetImagePlaneCount( SceGimPicture *picture ) ;
void sceGimPictureSetImagePlane( SceGimPicture *picture, int plane ) ;
int sceGimPictureGetImagePlane( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteOffset( SceGimPicture *picture, int shift, int mask, int offs ) ;
const int *sceGimPictureGetPaletteOffset( SceGimPicture *picture ) ;
void sceGimPictureSetBlend( SceGimPicture *picture, int mode ) ;
const int *sceGimPictureGetBlend( SceGimPicture *picture ) ;
void sceGimPictureSetFunc( SceGimPicture *picture, int mode, int comp ) ;
const int *sceGimPictureGetFunc( SceGimPicture *picture ) ;
void sceGimPictureSetFilter( SceGimPicture *picture, int mag, int min ) ;
const int *sceGimPictureGetFilter( SceGimPicture *picture ) ;
void sceGimPictureSetWrap( SceGimPicture *picture, int u, int v ) ;
const int *sceGimPictureGetWrap( SceGimPicture *picture ) ;
void sceGimPictureInitDevice( void *device, int flags ) ;
void sceGimPictureTermDevice( void ) ;
static __inline__ int sceGimPicturePow2( int num )
{
 return 1 << ( 32 - __builtin_allegrex_clz( num - 1 ) ) ;
}
static __inline__ int sceGimPictureCLZ( int num )
{
 return __builtin_allegrex_clz( num ) ;
}
static __inline__ int sceGimPictureCTZ( int num )
{
 return __builtin_allegrex_ctz( num ) ;
}
static __inline__ int sceGimImageGetFormat( const SceGimImageHeader *image )
{
 return image->format ;
}
static __inline__ int sceGimImageGetOrder( const SceGimImageHeader *image )
{
 return image->order ;
}
static __inline__ int sceGimImageGetBPP( const SceGimImageHeader *image )
{
 return image->bpp ;
}
static __inline__ int sceGimImageGetWidth( const SceGimImageHeader *image, int level )
{
 int width = image->width ;
 if ( level > 0 && image->level_type == SCEGIM_TYPE_MIPMAP ) {
  while ( -- level >= 0 ) width = ( width + 1 ) / 2 ;
 }
 return width ;
}
static __inline__ int sceGimImageGetHeight( const SceGimImageHeader *image, int level )
{
 int height = image->height ;
 if ( level > 0 && image->level_type == SCEGIM_TYPE_MIPMAP ) {
  while ( -- level >= 0 ) height = ( height + 1 ) / 2 ;
 }
 return height ;
}
static __inline__ int sceGimImageGetPitch( const SceGimImageHeader *image, int width )
{
 int align = image->pitch_align * 8 - 1 ;
 return ( ( image->bpp * width + align ) & ~align ) / 8 ;
}
static __inline__ int sceGimImageGetBufWidth( const SceGimImageHeader *image, int width )
{
 int align = image->pitch_align * 8 / image->bpp - 1 ;
 return ( width + align ) & ~align ;
}
static __inline__ int sceGimImageGetBufHeight( const SceGimImageHeader *image, int height )
{
 int align = image->height_align - 1 ;
 return ( height + align ) & ~align ;
}
static __inline__ int sceGimImageGetTexWidth( const SceGimImageHeader *image, int width )
{
 (void)image ;
 return sceGimPicturePow2( width ) ;
}
static __inline__ int sceGimImageGetTexHeight( const SceGimImageHeader *image, int height )
{
 (void)image ;
 return sceGimPicturePow2( height ) ;
}
static __inline__ int sceGimImageGetPlaneMask( const SceGimImageHeader *image )
{
 return image->plane_mask ;
}
static __inline__ int sceGimImageGetLevelCount( const SceGimImageHeader *image )
{
 return image->level_count ;
}
static __inline__ int sceGimImageGetFrameCount( const SceGimImageHeader *image )
{
 return image->frame_count ;
}
static __inline__ void *sceGimImageGetUserData( const SceGimImageHeader *image )
{
 if ( image->offsets <= image->header_size ) return 0 ;
 return (char *)image + image->header_size ;
}
static __inline__ int sceGimImageGetUserDataSize( const SceGimImageHeader *image )
{
 return image->offsets - image->header_size ;
}
static __inline__ void *sceGimImageGetPixels( const SceGimImageHeader *image, int level, int frame )
{
 void **offsets = (void **)( (char *)image + image->offsets ) ;
 int n_levels = image->level_count ;
 int n_frames = image->frame_count ;
 if ( level < 0 || level >= n_levels ) return 0 ;
 frame %= n_frames ;
 if ( frame < 0 ) frame += n_frames ;
 return offsets[ n_levels * frame + level ] ;
}
enum {
 SCEGIM_PICTURE_HAS_IMAGE_LEVELS = 0x0001,
 SCEGIM_PICTURE_HAS_IMAGE_FRAMES = 0x0002,
 SCEGIM_PICTURE_HAS_PALETTE_LEVELS = 0x0004,
 SCEGIM_PICTURE_HAS_PALETTE_FRAMES = 0x0008,
 SCEGIM_PICTURE_IS_ANIMATED = 0x0010,
 SCEGIM_PICTURE_IS_CROPPED = 0x0020,
 SCEGIM_PICTURE_IS_NONPOW2 = 0x0040,
 SCEGIM_PICTURE_IS_NOREPEAT = 0x0080
} ;
struct SceGimPicture {
 int m_reference ;
 int m_flags ;
 int m_enable_bits ;
 SceGimImageHeader *m_image ;
 SceGimPaletteHeader *m_palette ;
 struct SceGimTextureCache *m_texture_cache ;
 struct SceGimPixelCache *m_pixel_cache ;
 short m_buf_width ;
 short m_clut_load ;
 float __attribute__((aligned(16))) m_image_crop[ 4 ] ;
 float m_frame_loop[ 2 ] ;
 float m_frame_rate ;
 float m_frame ;
 float m_dissolve ;
 int m_image_frame ;
 int m_image_frame2 ;
 int m_palette_frame ;
 int m_palette_frame2 ;
 SceGimSequenceHeader **m_sequences ;
 int m_n_sequences ;
 int m_current_sequence ;
 int m_image_plane ;
 int m_palette_offset[ 3 ] ;
 int m_blend[ 1 ] ;
 int m_func[ 2 ] ;
 int m_filter[ 2 ] ;
 int m_wrap[ 2 ] ;
} ;
static __inline__ void sceGimPutCommand( unsigned int **pkt, unsigned int cmd ) ;
static __inline__ void sceGimPutJump( unsigned int **pkt, const unsigned *p ) ;
static __inline__ void sceGimPutCall( unsigned int **pkt, const unsigned *p ) ;
static __inline__ void sceGimPutRet( unsigned int **pkt ) ;
static __inline__ void sceGimPutTexMode( unsigned int **pkt, int tpf, int maxlod, int mc, int hsm ) ;
static __inline__ void sceGimPutTexImage( unsigned int **pkt, int level, int width, int height, int tbw, const void *tbp ) ;
static __inline__ void sceGimPutTexFlush( unsigned int **pkt ) ;
static __inline__ void sceGimPutClutMode( unsigned int **pkt, int cpf, int shift, int mask, int csa ) ;
static __inline__ void sceGimPutClutLoad( unsigned int **pkt, int np, const void *cbp ) ;
static __inline__ void sceGimPutTexLevelMode( unsigned int **pkt, int calc, float offset ) ;
static __inline__ void sceGimPutTexOffset( unsigned int **pkt, float tu, float tv ) ;
static __inline__ void sceGimPutTexScale( unsigned int **pkt, float su, float sv ) ;
static __inline__ void sceGimPutBlendFunc( unsigned int **pkt, int equ, int asel, int bsel, int afix, int bfix ) ;
static __inline__ void sceGimPutTexFunc( unsigned int **pkt, int func, int component ) ;
static __inline__ void sceGimPutTexFilter( unsigned int **pkt, int min, int mag ) ;
static __inline__ void sceGimPutTexWrap( unsigned int **pkt, int uwrap, int vwrap ) ;
static __inline__ void sceGimPutCommand( unsigned int **pkt, unsigned int cmd )
{
 *( ( *pkt ) ++ ) = cmd ;
}
static __inline__ void sceGimPutJump( unsigned int **pkt, const unsigned *p )
{
 sceGimPutCommand( pkt, (((0x10U)<<24) | (((((SceUInt32)(p))>>24) & 0x0FU)<<16)) ) ;
 sceGimPutCommand( pkt, (((0x08U)<<24) | (((SceUInt32)(p)) & 0x00FFFFFFU)) ) ;
}
static __inline__ void sceGimPutCall( unsigned int **pkt, const unsigned *p )
{
 sceGimPutCommand( pkt, (((0x10U)<<24) | (((((SceUInt32)(p))>>24) & 0x0FU)<<16)) ) ;
 sceGimPutCommand( pkt, (((0x0AU)<<24) | (((SceUInt32)(p)) & 0x00FFFFFFU)) ) ;
}
static __inline__ void sceGimPutRet( unsigned int **pkt )
{
 sceGimPutCommand( pkt, (((0x0BU)<<24)) ) ;
}
static __inline__ void sceGimPutTexMode( unsigned int **pkt, int tpf, int maxlod, int mc, int hsm )
{
 sceGimPutCommand( pkt, (((0xC2U)<<24) | ((maxlod)<<16) | ((mc)<<8) | ((hsm))) ) ;
 sceGimPutCommand( pkt, (((0xC3U)<<24) | ((0)<<8) | (tpf)) ) ;
}
static __inline__ void sceGimPutTexImage( unsigned int **pkt, int level, int width, int height, int tbw, const void *tbp )
{
 int tw = 31 - sceAllegrexClz( width ) ;
 int th = 31 - sceAllegrexClz( height ) ;
 sceGimPutCommand( pkt, ((((0xA0U)+(level))<<24) | (((SceUInt32)(tbp)) & 0x00FFFFFFU)) ) ;
 sceGimPutCommand( pkt, ((((0xA8U)+(level))<<24) | (((((SceUInt32)(tbp))>>24) & 0x0FU)<<16) | (tbw)) ) ;
 sceGimPutCommand( pkt, ((((0xB8U)+(level))<<24) | ((th)<<8) | (tw)) ) ;
}
static __inline__ void sceGimPutTexFlush( unsigned int **pkt )
{
 sceGimPutCommand( pkt, ((0xCBU)<<24) ) ;
}
static __inline__ void sceGimPutClutMode( unsigned int **pkt, int cpf, int shift, int mask, int csa )
{
 sceGimPutCommand( pkt, (((0xC5U)<<24) | ((csa)<<16) | ((mask)<<8) | ((shift)<<2) | (cpf)) ) ;
}
static __inline__ void sceGimPutClutLoad( unsigned int **pkt, int np, const void *cbp )
{
 sceGimPutCommand( pkt, (((0xB0U)<<24) | (((SceUInt32)(cbp)) & 0x00FFFFFFU)) ) ;
 sceGimPutCommand( pkt, (((0xB1U)<<24) | (((((SceUInt32)(cbp))>>24) & 0x0FU)<<16)) ) ;
 sceGimPutCommand( pkt, (((0xC4U)<<24) | (np)) ) ;
}
static __inline__ void sceGimPutTexLevelMode( unsigned int **pkt, int calc, float offset )
{
 int offl = (int)( offset * 16.0f ) ;
 if ( offl > 127 ) offl = 127 ;
 if ( offl < -128 ) offl = -128 ;
 offl &= 0xff ;
 sceGimPutCommand( pkt, (((0xC8U)<<24) | ((offl)<<16) | (calc)) ) ;
}
static __inline__ void sceGimPutTexOffset( unsigned int **pkt, float tu, float tv )
{
 sceGimPutCommand( pkt, (((0x4AU)<<24) | ((((const ScePspUnion32 *)&(tu))->ui)>>8)) ) ;
 sceGimPutCommand( pkt, (((0x4BU)<<24) | ((((const ScePspUnion32 *)&(tv))->ui)>>8)) ) ;
}
static __inline__ void sceGimPutTexScale( unsigned int **pkt, float su, float sv )
{
 sceGimPutCommand( pkt, (((0x48U)<<24) | ((((const ScePspUnion32 *)&(su))->ui)>>8)) ) ;
 sceGimPutCommand( pkt, (((0x49U)<<24) | ((((const ScePspUnion32 *)&(sv))->ui)>>8)) ) ;
}
static __inline__ void sceGimPutBlendFunc( unsigned int **pkt, int equ, int asel, int bsel, int afix, int bfix )
{
 sceGimPutCommand( pkt, (((0xDFU)<<24) | ((equ)<<8) | ((bsel)<<4) | (asel)) ) ;
 sceGimPutCommand( pkt, (((0xE0U)<<24) | ((afix) & 0x00FFFFFF)) ) ;
 sceGimPutCommand( pkt, (((0xE1U)<<24) | ((bfix) & 0x00FFFFFF)) ) ;
}
static __inline__ void sceGimPutTexFunc( unsigned int **pkt, int func, int component )
{
 sceGimPutCommand( pkt, (((0xC9U)<<24) | ((0)<<16) | ((component)<<8) | (func)) ) ;
}
static __inline__ void sceGimPutTexFilter( unsigned int **pkt, int min, int mag )
{
 sceGimPutCommand( pkt, (((0xC6U)<<24) | ((mag)<<8) | (min)) ) ;
}
static __inline__ void sceGimPutTexWrap( unsigned int **pkt, int uwrap, int vwrap )
{
 sceGimPutCommand( pkt, (((0xC7U)<<24) | ((vwrap)<<8) | (uwrap)) ) ;
}
typedef struct SceGimTextureCache SceGimTextureCache ;
typedef struct SceGimPixelCache SceGimPixelCache ;
struct SceGimTextureCache {
 unsigned int m_packet[ 1 ] ;
} ;
struct SceGimPixelCache {
 SceGimImageHeader *m_image ;
 SceGimPaletteHeader *m_palette ;
 int pad[ 2 ] ;
} ;
static _Bool set_null( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags ) ;
static _Bool set_texture( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags ) ;
static _Bool set_renderstate( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags ) ;
static SceGimImageHeader *copy_image( SceGimImageHeader *dst, const SceGimImageHeader *src ) ;
_Bool sceGimPictureLoadCache( SceGimPicture *picture )
{
 return sceGimPictureLoadCacheEx( picture, SCEGIM_CACHE_ALL ) ;
}
_Bool sceGimPictureLoadCacheEx( SceGimPicture *picture, int flags )
{
 if ( picture == 0 ) return 0 ;
 _Bool res = 1 ;
 if ( flags & SCEGIM_CACHE_PIXEL ) {
  if ( picture->m_pixel_cache == 0 ) {
   SceGimImageHeader *image = picture->m_image ;
   SceGimPaletteHeader *palette = picture->m_palette ;
   int size1 = ( image == 0 ) ? 0 : image->total ;
   int size2 = ( palette == 0 ) ? 0 : palette->total ;
   int size = sizeof( SceGimPixelCache ) + size1 + size2 ;
   SceGimPixelCache *buf = (SceGimPixelCache *)sceGimPictureAllocMemory3( size ) ;
   if ( buf == 0 ) {
    res = 0 ;
   } else {
    SceGimImageHeader *ptr = (SceGimImageHeader *)( buf + 1 ) ;
    buf->m_image = copy_image( ptr, image ) ;
    ptr = (SceGimImageHeader *)( (char *)ptr + size1 ) ;
    buf->m_palette = copy_image( ptr, palette ) ;
    if ( sceKernelIsCachedAddr( buf ) ) {
     sceKernelDcacheWritebackRange( buf, size ) ;
    }
    picture->m_pixel_cache = buf ;
   }
  }
 }
 if ( flags & SCEGIM_CACHE_TEXTURE ) {
  if ( picture->m_texture_cache == 0
   && !( picture->m_flags & SCEGIM_PICTURE_IS_ANIMATED ) ) {
   unsigned int tmp[ (34) + 1 ] ;
   unsigned int *ptr = tmp ;
   unsigned int *end = tmp + sizeof( tmp ) / 4 ;
   set_texture( picture, &ptr, end, SCEGIM_ACTIVATE_ALL ) ;
   sceGimPutRet( &ptr ) ;
   int size = (char *)ptr - (char *)tmp ;
   SceGimTextureCache *buf = (SceGimTextureCache *)sceGimPictureAllocMemory2( size ) ;
   if ( buf == 0 ) {
    res = 0 ;
   } else {
    memcpy( buf, tmp, size ) ;
    if ( sceKernelIsCachedAddr( buf ) ) {
     sceKernelDcacheWritebackRange( buf, size ) ;
    }
    picture->m_texture_cache = buf ;
   }
  }
 }
 return res ;
}
void sceGimPictureUnloadCache( SceGimPicture *picture )
{
 sceGimPictureUnloadCacheEx( picture, SCEGIM_CACHE_ALL ) ;
}
void sceGimPictureUnloadCacheEx( SceGimPicture *picture, int flags )
{
 if ( picture == 0 ) return ;
 if ( flags & SCEGIM_CACHE_PIXEL ) {
  if ( picture->m_pixel_cache != 0 ) flags |= SCEGIM_CACHE_TEXTURE ;
  sceGimPictureFreeMemory3( picture->m_pixel_cache ) ;
  picture->m_pixel_cache = 0 ;
 }
 if ( flags & ( SCEGIM_CACHE_TEXTURE ) ) {
  sceGimPictureFreeMemory2( picture->m_texture_cache ) ;
  picture->m_texture_cache = 0 ;
 }
}
_Bool sceGimPictureActivateEx( SceGimPicture *picture, unsigned int **pkt, unsigned int *size, int flags )
{
 unsigned int *ptr = *pkt ;
 unsigned int *end = ( size == 0 ) ? (unsigned int *)0xfffffffc : ptr + *size / 4 ;
 if ( picture == 0 ) {
  if ( !set_null( picture, &ptr, end, flags ) ) return 0 ;
  flags = 0 ;
 }
 if ( flags & SCEGIM_ACTIVATE_TEXTURE ) {
  SceGimTextureCache *cache = picture->m_texture_cache ;
  if ( cache != 0 ) {
   if ( ptr + 2 > end ) return 0 ;
   sceGimPutCall( &ptr, cache->m_packet ) ;
  } else {
   if ( !set_texture( picture, &ptr, end, flags ) ) return 0 ;
  }
 }
 if ( flags & SCEGIM_ACTIVATE_RENDERSTATE ) {
  if ( !set_renderstate( picture, &ptr, end, flags ) ) return 0 ;
 }
 *pkt = ptr ;
 if ( size != 0 ) *size = (char *)end - (char *)ptr ;
 return 1 ;
}
/* the module's SDK keeps these tables in .data (still asm) */
extern unsigned short D_001148D0[];
#define NullTexture D_001148D0
_Bool set_null( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags )
{
	if ( *pkt + 6 > end ) return 0 ;
	sceGimPutTexMode( pkt, 0, 0, 0, 0 ) ;
	sceGimPutTexImage( pkt, 0, 1, 1, 8, NullTexture ) ;
	sceGimPutTexFlush( pkt ) ;
	return 1 ;
}

_Bool set_texture( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags )
{
 if ( picture == 0 ) return 0 ;
 if ( *pkt + (34) > end ) return 0 ;
 SceGimPixelCache *cache = picture->m_pixel_cache ;
 SceGimImageHeader *img = ( cache != 0 ) ? cache->m_image : picture->m_image ;
 SceGimPaletteHeader *pal = ( cache != 0 ) ? cache->m_palette : picture->m_palette ;
 if ( picture->m_flags == 0 ) {
  if ( img != 0 ) {
   sceGimPutTexMode( pkt, img->format, 0, 0, img->order ) ;
   void **offsets = (void **)( (char *)img + img->offsets ) ;
   sceGimPutTexImage( pkt, 0, img->width, img->height, picture->m_buf_width, *offsets ) ;
  }
  sceGimPutTexFlush( pkt ) ;
  if ( pal != 0 ) {
   sceGimPutClutMode( pkt, pal->format,
    picture->m_palette_offset[ 0 ],
    picture->m_palette_offset[ 1 ],
    picture->m_palette_offset[ 2 ] ) ;
   void **offsets = (void **)( (char *)pal + pal->offsets ) ;
   sceGimPutClutLoad( pkt, picture->m_clut_load, *offsets ) ;
  }
  return 1 ;
 }
 if ( img != 0 ) {
  int w = img->width ;
  int h = img->height ;
  int w2 = sceGimPicturePow2( w ) ;
  int h2 = sceGimPicturePow2( h ) ;
  int align = img->pitch_align * 8 / img->bpp - 1 ;
  int n_levels = img->level_count ;
  void **offsets = (void **)( (char *)img + img->offsets ) ;
  int n_frames = img->frame_count ;
  int frame = picture->m_image_frame % n_frames ;
  if ( frame < 0 ) frame += n_frames ;
  if ( picture->m_enable_bits & SCEGIM_ENABLE_DISSOLVE ) {
   int clut = 0 ;
   if ( picture->m_flags & SCEGIM_PICTURE_HAS_PALETTE_FRAMES ) {
    clut = 1 ;
   }
   sceGimPutTexMode( pkt, img->format, 1, clut, img->order ) ;
   w = ( w + align ) & ~align ;
   void *buf = offsets[ frame * n_levels ] ;
   sceGimPutTexImage( pkt, 0, w2, h2, w, buf ) ;
   frame = picture->m_image_frame2 % n_frames ;
   if ( frame < 0 ) frame = frame + n_frames ;
   buf = offsets[ frame * n_levels ] ;
   sceGimPutTexImage( pkt, 1, w2, h2, w, buf ) ;
  } else {
   offsets += frame * n_levels ;
   int clut = 0 ;
   if ( picture->m_flags & SCEGIM_PICTURE_HAS_PALETTE_LEVELS ) {
    clut = 1 ;
   }
   sceGimPutTexMode( pkt, img->format, n_levels - 1, clut, img->order ) ;
   for ( int i = 0 ; i < n_levels ; i ++ ) {
    void *buf = *( offsets ++ ) ;
    sceGimPutTexImage( pkt, i, w2, h2, ( w + align ) & ~align, buf ) ;
    if ( img->level_type == SCEGIM_TYPE_MIPMAP ) {
     w = ( w + 1 ) / 2 ;
     w2 = ( w2 + 1 ) / 2 ;
     h2 = ( h2 + 1 ) / 2 ;
    }
   }
  }
  sceGimPutTexFlush( pkt ) ;
 }
 if ( pal != 0 ) {
  sceGimPutClutMode( pkt, pal->format,
   picture->m_palette_offset[ 0 ],
   picture->m_palette_offset[ 1 ],
   picture->m_palette_offset[ 2 ] ) ;
  void **offsets = (void **)( (char *)pal + pal->offsets ) ;
  int n_levels = pal->level_count ;
  int n_frames = pal->frame_count ;
  int frame = picture->m_palette_frame % n_frames ;
  if ( frame < 0 ) frame = frame + n_frames ;
  if ( !( picture->m_enable_bits & SCEGIM_ENABLE_DISSOLVE ) ) {
   sceGimPutClutLoad( pkt, picture->m_clut_load, offsets[ frame * n_levels ] ) ;
  } else {
   int count = pal->width / 16 ;
   if ( pal->format == 3 ) count *= 2 ;
   int frame2 = picture->m_palette_frame2 % n_frames ;
   if ( frame2 < 0 ) frame2 = frame2 + n_frames ;
   if ( frame2 == frame + 1 && n_levels == 1 && count <= 16 ) {
    sceGimPutClutLoad( pkt, count * 2, offsets[ frame * n_levels ] ) ;
   } else {
    sceGimPutClutLoad( pkt, count * 2, (char *)offsets[ frame2 * n_levels ]
        - count * 32 ) ;
    sceGimPutClutLoad( pkt, count, offsets[ frame * n_levels ] ) ;
   }
  }
 }
 return 1 ;
}

extern float D_001148E0[];
extern int D_001148F0[][4];
#define NoCrop D_001148E0
#define BlendFuncModes D_001148F0
_Bool set_renderstate( SceGimPicture *picture, unsigned int **pkt, unsigned int *end, int flags )
{
 if ( picture == 0 ) return 0 ;
 int enable = picture->m_enable_bits ;
 if ( enable == 0 ) return 1 ;
 if ( *pkt + (11) > end ) return 0 ;
 if ( enable & SCEGIM_ENABLE_FACTOR ) {
  if ( enable & SCEGIM_ENABLE_DISSOLVE ) {
   sceGimPutTexLevelMode( pkt, 1, picture->m_dissolve ) ;
  } else {
   sceGimPutTexLevelMode( pkt, 0, 0 ) ;
  }
 }
 if ( enable & SCEGIM_ENABLE_CROP ) {
  const float *crop = picture->m_image_crop ;
  if ( !( picture->m_flags & SCEGIM_PICTURE_IS_CROPPED ) ) crop = NoCrop ;
  sceGimPutTexOffset( pkt, crop[ 0 ], crop[ 1 ] ) ;
  sceGimPutTexScale( pkt, crop[ 2 ], crop[ 3 ] ) ;
 }
 if ( enable & SCEGIM_ENABLE_BLEND ) {
  const int *modes = BlendFuncModes[ picture->m_blend[ 0 ] ] ;
  sceGimPutBlendFunc( pkt, modes[ 0 ], modes[ 1 ], modes[ 2 ], 0xffffffff, modes[ 3 ] ) ;
 }
 if ( enable & SCEGIM_ENABLE_FUNC ) {
  sceGimPutTexFunc( pkt, picture->m_func[ 0 ], picture->m_func[ 1 ] ) ;
 }
 if ( enable & SCEGIM_ENABLE_FILTER ) {
  sceGimPutTexFilter( pkt, picture->m_filter[ 1 ], picture->m_filter[ 0 ] ) ;
 }
 if ( enable & SCEGIM_ENABLE_WRAP ) {
  sceGimPutTexWrap( pkt, picture->m_wrap[ 0 ], picture->m_wrap[ 1 ] ) ;
 }
 return 1 ;
}

SceGimImageHeader *copy_image( SceGimImageHeader *dst, const SceGimImageHeader *src )
{
 if ( src == 0 ) return 0 ;
 memcpy( dst, src, src->total ) ;
 int begin = (int)src ;
 int end = begin + src->total ;
 int offset = (int)dst - (int)src ;
 int *offsets = (int *)( (char *)dst + dst->offsets ) ;
 for ( int i = src->level_count * src->frame_count ; i > 0 ; -- i ) {
  int ptr = *( offsets ++ ) ;
  if ( ptr >= begin && ptr < end ) offsets[ -1 ] = ptr + offset ;
 }
 return dst ;
}
