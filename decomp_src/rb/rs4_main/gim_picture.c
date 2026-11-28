/* SDK libgim_picture gim_picture.o (1.9.2 -O2 -std=gnu9x): the SDK 6.6.0 src/gim_picture/gim_picture.c, preprocessed with the SDK headers and its Makefile's SCEGIM_SUPPORT_* defines; psp-gcc predefines __psp_gcc__, so allegrex.h and gim_picture.h use the clz builtin (Pow2 too) */
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
typedef int ptrdiff_t;
typedef struct __sFILE FILE;
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
extern struct _reent *_impure_ptr;
int fprintf(FILE *, const char *, ...);
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
int puts(const char *);
int putchar(int);
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
int vsprintf(char *, const char *, __gnuc_va_list);
void *malloc(size_t);
void free(void *);
void *memalign(size_t, size_t);
int atoi(const char *);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);
int memcmp(const void *, const void *, size_t);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
size_t strlen(const char *);
char *strdup(const char *);
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
enum {
 HAS_IMAGE_LEVELS = SCEGIM_PICTURE_HAS_IMAGE_LEVELS,
 HAS_IMAGE_FRAMES = SCEGIM_PICTURE_HAS_IMAGE_FRAMES,
 HAS_PALETTE_LEVELS = SCEGIM_PICTURE_HAS_PALETTE_LEVELS,
 HAS_PALETTE_FRAMES = SCEGIM_PICTURE_HAS_PALETTE_FRAMES,
 IS_ANIMATED = SCEGIM_PICTURE_IS_ANIMATED,
 IS_CROPPED = SCEGIM_PICTURE_IS_CROPPED,
 IS_NONPOW2 = SCEGIM_PICTURE_IS_NONPOW2,
 IS_NOREPEAT = SCEGIM_PICTURE_IS_NOREPEAT
} ;
enum {
 TM2_FORMAT_SIGNATURE = 0x324d4954,
 BMP_FORMAT_SIGNATURE = 0x4d42
} ;
SceGimPicture *sceGimPictureCreate( const SceGimChunk *chunk )
{
 SceGimPicture *picture = (SceGimPicture *)sceGimPictureAllocMemory( sizeof( SceGimPicture ) ) ;
 if ( picture == 0 ) {
  ;
  return 0 ;
 }
 picture->m_reference = 1 ;
 picture->m_flags = 0 ;
 picture->m_enable_bits = 0 ;
 picture->m_image = 0 ;
 picture->m_palette = 0 ;
 picture->m_texture_cache = 0 ;
 picture->m_pixel_cache = 0 ;
 picture->m_buf_width = 0 ;
 picture->m_clut_load = 0 ;
 picture->m_image_crop[ 0 ] = 0.0f ;
 picture->m_image_crop[ 1 ] = 0.0f ;
 picture->m_image_crop[ 2 ] = 1.0f ;
 picture->m_image_crop[ 3 ] = 1.0f ;
 picture->m_frame_loop[ 0 ] = -1000000.0f ;
 picture->m_frame_loop[ 1 ] = 1000000.0f ;
 picture->m_frame_rate = 12.0f ;
 picture->m_frame = 0.0f ;
 picture->m_dissolve = 0.0f ;
 picture->m_image_frame = 0 ;
 picture->m_image_frame2 = 0 ;
 picture->m_palette_frame = 0 ;
 picture->m_palette_frame2 = 0 ;
 picture->m_sequences = 0 ;
 picture->m_n_sequences = 0 ;
 picture->m_current_sequence = -1 ;
 picture->m_image_plane = 0 ;
 picture->m_palette_offset[ 0 ] = 0 ;
 picture->m_palette_offset[ 1 ] = 255 ;
 picture->m_palette_offset[ 2 ] = 0 ;
 picture->m_blend[ 0 ] = SCEGIM_BLEND_MIX ;
 picture->m_func[ 0 ] = SCEGIM_FUNC_MODULATE ;
 picture->m_func[ 1 ] = SCEGIM_FUNC_RGBA ;
 picture->m_filter[ 0 ] = SCEGIM_FILTER_LINEAR ;
 picture->m_filter[ 1 ] = SCEGIM_FILTER_LINEAR_MIPMAP_LINEAR ;
 picture->m_wrap[ 0 ] = SCEGIM_WRAP_REPEAT ;
 picture->m_wrap[ 1 ] = SCEGIM_WRAP_REPEAT ;
 if ( chunk != 0 && !sceGimPictureLoad( picture, chunk ) ) {
  sceGimPictureDelete( picture ) ;
  return 0 ;
 }
 return picture ;
}
void sceGimPictureDelete( SceGimPicture *picture )
{
 if ( picture == 0 ) return ;
 if ( -- picture->m_reference == 0 ) {
  sceGimPictureUnload( picture ) ;
  sceGimPictureFreeMemory( picture ) ;
 }
}
SceGimPicture *sceGimPictureDuplicate( SceGimPicture *picture, int flags )
{
 if ( picture == 0 ) return 0 ;
 if ( flags & SCEGIM_DUPLICATE_AUTOMATIC ) {
  flags &= ~SCEGIM_DUPLICATE_AUTOMATIC ;
  if ( sceGimPictureHasAnimation( picture ) ) {
   flags |= SCEGIM_DUPLICATE_STRUCTURE ;
  }
 }
 if ( flags == SCEGIM_DUPLICATE_REFERENCE ) {
  picture->m_reference ++ ;
  return picture ;
 }
 SceGimPicture *picture2 = sceGimPictureCreate( 0 ) ;
 if ( picture2 == 0 ) return 0 ;
 memcpy( picture2, picture, sizeof( SceGimPicture ) ) ;
 picture2->m_reference = 1 ;
 if ( picture2->m_image != 0 ) picture2->m_image->reference ++ ;
 if ( picture2->m_palette != 0 ) picture2->m_palette->reference ++ ;
 picture2->m_texture_cache = 0 ;
 picture2->m_pixel_cache = 0 ;
 if ( picture2->m_n_sequences > 0 ) {
  int size = sizeof( void * ) * picture2->m_n_sequences ;
  picture2->m_sequences = (SceGimSequenceHeader **)sceGimPictureAllocMemory( size ) ;
  if ( picture2->m_sequences == 0 ) {
   ;
   picture2->m_n_sequences = 0 ;
   sceGimPictureDelete( picture2 ) ;
   return 0 ;
  }
  for ( int i = 0 ; i < picture2->m_n_sequences ; i ++ ) {
   picture2->m_sequences[ i ] = picture->m_sequences[ i ] ;
   picture2->m_sequences[ i ]->reference ++ ;
  }
 }
 return picture2 ;
}
_Bool sceGimPictureLoadFile( SceGimPicture *picture, const void *buf, int size, int idx )
{
 if ( picture == 0 ) return 0 ;
 if ( buf == 0 ) return 0 ;
 if ( size > 0 && size < 4 ) return 0 ;
 int signature = *(int *)buf ;
 if ( signature == (0x2e47494d) ) {
  if ( !sceGimPictureCheckFileHeader( buf, size ) ) return 0 ;
  SceGimChunk *chunk = sceGimPictureGetChunk( buf, size, idx ) ;
  if ( chunk == 0 ) {
   ;
   return 0 ;
  }
  ;
  return sceGimPictureLoad( picture, chunk ) ;
 } else if ( signature == TM2_FORMAT_SIGNATURE ) {
  return sceGimPictureLoadTm2( picture, buf, size, idx ) ;
 } else if ( ( 0xffff & signature ) == BMP_FORMAT_SIGNATURE ) {
  return sceGimPictureLoadBmp( picture, buf, size ) ;
 } else {
  return sceGimPictureLoadTga( picture, buf, size ) ;
 }
 return 0 ;
}
_Bool sceGimPictureLoad( SceGimPicture *picture, const SceGimChunk *chunk )
{
 if ( picture == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;
 sceGimPictureUnload( picture ) ;
 int n_sequences = sceGimPictureCountChildChunk( chunk, SCEGIM_SEQUENCE ) ;
 if ( n_sequences > 0 ) {
  int size = sizeof( void * ) * n_sequences ;
  picture->m_sequences = (SceGimSequenceHeader **)sceGimPictureAllocMemory( size ) ;
  if ( picture->m_sequences == 0 ) {
   ;
   return 0 ;
  }
 }
 SceGimChunk *end = SCEGIM_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGIM_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGIM_CHUNK_NEXT( chunk ) ) {
  void *data = SCEGIM_CHUNK_DATA( chunk ) ;
  int size = SCEGIM_CHUNK_DATASIZE( chunk ) ;
  switch ( SCEGIM_CHUNK_TYPE( chunk ) ) {
      case SCEGIM_IMAGE : {
   if ( picture->m_image != 0 ) break ;
   SceGimImageHeader *img = (SceGimImageHeader *)sceGimPictureAllocMemory2( size ) ;
   if ( img == 0 ) {
    ;
    return 0 ;
   }
   picture->m_image = img ;
   memcpy( img, data, size ) ;
   img->reference = 1 ;
   int *offsets = (int *)( (char *)img + img->offsets ) ;
   for ( int i = img->level_count * img->frame_count ; i > 0 ; -- i ) {
    *( offsets ++ ) += (int)img ;
   }
   if ( img->width > 512 || img->height > 512 ) {
    ;
    return 0 ;
   }
   break ;
      }
      case SCEGIM_PALETTE : {
   if ( picture->m_palette != 0 ) break ;
   SceGimPaletteHeader *pal = (SceGimPaletteHeader *)sceGimPictureAllocMemory2( size ) ;
   if ( pal == 0 ) {
    ;
    return 0 ;
   }
   picture->m_palette = pal ;
   memcpy( pal, data, size ) ;
   pal->reference = 1 ;
   int *offsets = (int *)( (char *)pal + pal->offsets ) ;
   for ( int i = pal->level_count * pal->frame_count ; i > 0 ; -- i ) {
    *( offsets ++ ) += (int)pal ;
   }
   if ( pal->width > 256 ) {
    ;
    return 0 ;
   }
   break ;
      }
      case SCEGIM_SEQUENCE : {
   SceGimSequenceHeader *seq = (SceGimSequenceHeader *)sceGimPictureAllocMemory( size ) ;
   if ( seq == 0 ) {
    ;
    return 0 ;
   }
   picture->m_sequences[ picture->m_n_sequences ++ ] = seq ;
   memcpy( seq, data, size ) ;
   seq->reference = 1 ;
   break ;
      }
  }
 }
 sceKernelDcacheWritebackAll();
 sceGimPictureReconfigure( picture ) ;
 return 1 ;
}
void sceGimPictureUnload( SceGimPicture *picture )
{
 if ( picture == 0 ) return ;
 sceGimPictureUnloadCache( picture ) ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image != 0 ) {
  if ( -- image->reference == 0 ) sceGimPictureFreeMemory2( image ) ;
  picture->m_image = 0 ;
 }
 SceGimPaletteHeader *palette = picture->m_palette ;
 if ( palette != 0 ) {
  if ( -- palette->reference == 0 ) sceGimPictureFreeMemory2( palette ) ;
  picture->m_palette = 0 ;
 }
 for ( int i = 0 ; i < picture->m_n_sequences ; i ++ ) {
  SceGimSequenceHeader *sequence = picture->m_sequences[ i ] ;
  if ( -- sequence->reference == 0 ) sceGimPictureFreeMemory( sequence ) ;
 }
 sceGimPictureFreeMemory( picture->m_sequences ) ;
 picture->m_sequences = 0 ;
 picture->m_n_sequences = 0 ;
}
void sceGimPictureReconfigure( SceGimPicture *picture )
{
 picture->m_flags = 0 ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image != 0 ) {
  if ( image->level_count > 1 ) picture->m_flags |= HAS_IMAGE_LEVELS ;
  if ( image->frame_count > 1 ) picture->m_flags |= HAS_IMAGE_FRAMES ;
  int w = image->width ;
  int h = image->height ;
  int w2 = sceGimPicturePow2( w ) ;
  int h2 = sceGimPicturePow2( h ) ;
  if ( w != w2 || h != h2 ) {
   picture->m_flags |= ( IS_NONPOW2 | IS_CROPPED ) ;
   picture->m_image_crop[ 0 ] = 0.0f ;
   picture->m_image_crop[ 1 ] = 0.0f ;
   picture->m_image_crop[ 2 ] = (float)image->width / w2 ;
   picture->m_image_crop[ 3 ] = (float)image->height / h2 ;
  }
  int align = image->pitch_align * 8 / image->bpp - 1 ;
  picture->m_buf_width = ( w + align ) & ~align ;
 }
 SceGimPaletteHeader *palette = picture->m_palette ;
 if ( palette != 0 ) {
  if ( palette->level_count > 1 ) picture->m_flags |= HAS_PALETTE_LEVELS ;
  if ( palette->frame_count > 1 ) picture->m_flags |= HAS_PALETTE_FRAMES ;
  int count = ( palette->width / 16 ) * palette->level_count ;
  if ( palette->format == SCEGIM_FORMAT_RGBA8888 ) count *= 2 ;
  if ( count > 32 ) count = 32 ;
  picture->m_clut_load = count ;
 }
 if ( picture->m_flags & ( HAS_IMAGE_FRAMES | HAS_PALETTE_FRAMES ) ) {
  picture->m_flags |= IS_ANIMATED ;
 } else {
  for ( int i = 0 ; i < picture->m_n_sequences ; i ++ ) {
   SceGimSequenceHeader *sequence = picture->m_sequences[ i ] ;
   if ( sequence->n_functions > 0 ) {
    picture->m_flags |= IS_ANIMATED ;
    break ;
   }
  }
 }
 sceGimPictureSetImagePlane( picture, picture->m_image_plane ) ;
}

void sceGimPictureSetEnableBits( SceGimPicture *picture, int bits, int value )
{
 if ( picture == 0 ) return ;
 picture->m_enable_bits &= ~bits ;
 picture->m_enable_bits |= ( bits & value ) ;
}
int sceGimPictureGetEnableBits( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_enable_bits ;
}
void sceGimPictureSetImageCrop( SceGimPicture *picture, const float *crop )
{
 if ( picture == 0 ) return ;
 if ( crop == 0 ) {
  picture->m_flags &= ~IS_CROPPED ;
 } else {
  memcpy( picture->m_image_crop, crop, sizeof( float ) * 4 ) ;
  picture->m_flags |= IS_CROPPED ;
 }
}
const float *sceGimPictureGetImageCrop( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 if ( !( picture->m_flags & IS_CROPPED ) ) return 0 ;
 return picture->m_image_crop ;
}
SceGimImageHeader *sceGimPictureGetImage( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image ;
}
SceGimPaletteHeader *sceGimPictureGetPalette( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette ;
}
void *sceGimPictureGetImagePixels( SceGimPicture *picture, int level, int frame )
{
 if ( picture == 0 ) return 0 ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image == 0 ) return 0 ;
 int n_levels = image->level_count ;
 int n_frames = image->frame_count ;
 if ( level < 0 || level >= n_levels ) return 0 ;
 frame %= n_frames ;
 if ( frame < 0 ) frame += n_frames ;
 void **offsets = (void **)( (char *)image + image->offsets ) ;
 return offsets[ n_levels * frame + level ] ;
}
void *sceGimPictureGetPalettePixels( SceGimPicture *picture, int level, int frame )
{
 if ( picture == 0 ) return 0 ;
 SceGimPaletteHeader *palette = picture->m_palette ;
 if ( palette == 0 ) return 0 ;
 int n_levels = palette->level_count ;
 int n_frames = palette->frame_count ;
 if ( level < 0 || level >= n_levels ) return 0 ;
 frame %= n_frames ;
 if ( frame < 0 ) frame += n_frames ;
 void **offsets = (void **)( (char *)palette + palette->offsets ) ;
 return offsets[ n_levels * frame + level ] ;
}
void sceGimPictureSetImagePixels( SceGimPicture *picture, int level, int frame, void *pixels )
{
 if ( picture == 0 ) return ;
 if ( pixels == 0 ) return ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image == 0 ) return ;
 int n_levels = image->level_count ;
 int n_frames = image->frame_count ;
 if ( level < 0 || level >= n_levels ) return ;
 frame %= n_frames ;
 if ( frame < 0 ) frame += n_frames ;
 void **offsets = (void **)( (char *)image + image->offsets ) ;
 offsets[ n_levels * frame + level ] = pixels ;
}
void sceGimPictureSetPalettePixels( SceGimPicture *picture, int level, int frame, void *pixels )
{
 if ( picture == 0 ) return ;
 if ( pixels == 0 ) return ;
 SceGimPaletteHeader *palette = picture->m_palette ;
 if ( palette == 0 ) return ;
 int n_levels = palette->level_count ;
 int n_frames = palette->frame_count ;
 if ( level < 0 || level >= n_levels ) return ;
 frame %= n_frames ;
 if ( frame < 0 ) frame += n_frames ;
 void **offsets = (void **)( (char *)palette + palette->offsets ) ;
 offsets[ n_levels * frame + level ] = pixels ;
}
_Bool sceGimPictureHasAnimation( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return ( ( picture->m_flags & IS_ANIMATED ) != 0 ) ;
}
void sceGimPictureSetFrameLoop( SceGimPicture *picture, float start, float end )
{
 if ( picture == 0 ) return ;
 picture->m_frame_loop[ 0 ] = start ;
 picture->m_frame_loop[ 1 ] = end ;
}
const float *sceGimPictureGetFrameLoop( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_frame_loop ;
}
void sceGimPictureSetFrameRate( SceGimPicture *picture, float fps )
{
 if ( picture == 0 ) return ;
 picture->m_frame_rate = fps ;
}
float sceGimPictureGetFrameRate( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0.0f ;
 return picture->m_frame_rate ;
}
void sceGimPictureSetFrameRepeat( SceGimPicture *picture, int mode )
{
 if ( picture == 0 ) return ;
 if ( mode == SCEGIM_REPEAT_HOLD ) {
  picture->m_flags |= IS_NOREPEAT ;
 } else {
  picture->m_flags &= ~IS_NOREPEAT ;
 }
}
int sceGimPictureGetFrameRepeat( SceGimPicture *picture )
{
 if ( picture == 0 ) return SCEGIM_REPEAT_HOLD ;
 return ( picture->m_flags & IS_NOREPEAT ) ? SCEGIM_REPEAT_HOLD : SCEGIM_REPEAT_CYCLE ;
}
void sceGimPictureSetFrame( SceGimPicture *picture, float frame )
{
 if ( picture == 0 ) return ;
 picture->m_frame = frame ;
}
float sceGimPictureGetFrame( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0.0f ;
 return picture->m_frame ;
}
void sceGimPictureSetImageFrame( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_image_frame = frame ;
}
int sceGimPictureGetImageFrame( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image_frame ;
}
void sceGimPictureSetImageFrame2( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_image_frame2 = frame ;
}
int sceGimPictureGetImageFrame2( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image_frame2 ;
}
void sceGimPictureSetPaletteFrame( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_palette_frame = frame ;
}
int sceGimPictureGetPaletteFrame( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette_frame ;
}
void sceGimPictureSetPaletteFrame2( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_palette_frame = frame ;
}

int sceGimPictureGetPaletteFrame2( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette_frame ;
}

void sceGimPictureSetDissolve( SceGimPicture *picture, float dissolve )
{
 if ( picture == 0 ) return ;
 picture->m_dissolve = dissolve ;
}
float sceGimPictureGetDissolve( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0.0f ;
 return picture->m_dissolve ;
}
int sceGimPictureGetSequenceCount( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_n_sequences ;
}
SceGimSequenceHeader *sceGimPictureGetSequence( SceGimPicture *picture, int idx )
{
 if ( picture == 0 ) return 0 ;
 if ( idx < 0 || idx >= picture->m_n_sequences ) return 0 ;
 return picture->m_sequences[ idx ] ;
}
void sceGimPictureSetCurrentSequence( SceGimPicture *picture, int idx )
{
 if ( picture == 0 ) return ;
 picture->m_current_sequence = idx ;
 picture->m_frame = 0.0f ;
 if ( idx < 0 || idx >= picture->m_n_sequences ) return ;
 SceGimSequenceHeader *sequence = picture->m_sequences[ idx ] ;
 sceGimPictureSetFrameLoop( picture, sequence->frame_start, sequence->frame_end ) ;
 sceGimPictureSetFrameRate( picture, sequence->frame_rate ) ;
 sceGimPictureSetFrameRepeat( picture, sequence->frame_repeat ) ;
 SceGimConstant *cp = (SceGimConstant *)( (char *)sequence + sequence->constants ) ;
 for ( int i = 0 ; i < sequence->n_constants ; i ++ ) {
  sceGimPictureControl( picture, cp->param, (float)cp->value ) ;
  cp ++ ;
 }
}
int sceGimPictureGetCurrentSequence( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_current_sequence ;
}
int sceGimPictureGetImagePlaneCount( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image == 0 ) return 0 ;
 unsigned int mask = image->plane_mask ;
 if ( mask == 0 ) return 0 ;
 mask ^= mask >> 1 ;
 mask = ( mask & 0x55555555 ) + ( mask >> 1 & 0x55555555 ) ;
 mask = ( mask & 0x33333333 ) + ( mask >> 2 & 0x33333333 ) ;
 mask = ( mask + ( mask >> 4 ) ) & 0x0f0f0f0f ;
 mask += mask >> 8 ;
 mask += mask >> 16 ;
 return mask & 0xff ;
}
void sceGimPictureSetImagePlane( SceGimPicture *picture, int plane )
{
 if ( picture == 0 ) return ;
 picture->m_image_plane = plane ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image == 0 ) return ;
 unsigned int mask = image->plane_mask ;
 if ( mask == 0 ) {
  sceGimPictureSetPaletteOffset( picture, 0, 255, 0 ) ;
  return ;
 }
 mask ^= mask >> 1 ;
 unsigned int bits = 1 ;
 while ( -- plane >= 0 ) bits += ( mask - bits ) ^ mask ;
 bits = ( mask - bits ) ^ mask ;
 int shift = sceGimPictureCTZ( bits ) ;
 sceGimPictureSetPaletteOffset( picture, shift, bits >> shift, 0 ) ;
}

int sceGimPictureGetImagePlane( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image_plane ;
}
void sceGimPictureSetPaletteOffset( SceGimPicture *picture, int shift, int mask, int offs )
{
 if ( picture == 0 ) return ;
 picture->m_palette_offset[ 0 ] = shift ;
 picture->m_palette_offset[ 1 ] = mask ;
 picture->m_palette_offset[ 2 ] = offs ;
}
const int *sceGimPictureGetPaletteOffset( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette_offset ;
}
void sceGimPictureSetBlend( SceGimPicture *picture, int mode )
{
 if ( picture == 0 ) return ;
 picture->m_blend[ 0 ] = mode ;
}
const int *sceGimPictureGetBlend( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_blend ;
}
void sceGimPictureSetFunc( SceGimPicture *picture, int mode, int comp )
{
 if ( picture == 0 ) return ;
 picture->m_func[ 0 ] = mode ;
 picture->m_func[ 1 ] = comp ;
}
const int *sceGimPictureGetFunc( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_func ;
}
void sceGimPictureSetFilter( SceGimPicture *picture, int mag, int min )
{
 if ( picture == 0 ) return ;
 picture->m_filter[ 0 ] = mag ;
 picture->m_filter[ 1 ] = min ;
}
const int *sceGimPictureGetFilter( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_filter ;
}
void sceGimPictureSetWrap( SceGimPicture *picture, int u, int v )
{
 if ( picture == 0 ) return ;
 picture->m_wrap[ 0 ] = u ;
 picture->m_wrap[ 1 ] = v ;
}
const int *sceGimPictureGetWrap( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_wrap ;
}

/* in gim_animate.c in SDK 6.6.0 */
void sceGimPictureAnimate( SceGimPicture *picture, float step )
{
 sceGimPictureAnimateEx( picture, step, SCEGIM_ANIMATE_ALL ) ;
}
