/* SDK gmo_model declarations (gmo_private.h, preprocessed) */
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
 int n = 1;
 unsigned int ui;
 ui = (unsigned int)x;
 if (ui==0) return (32);
 if ((ui>>16)==0) { n = n + 16; ui = ui<<16; }
 if ((ui>>24)==0) { n = n + 8; ui = ui<< 8; }
 if ((ui>>28)==0) { n = n + 4; ui = ui<< 4; }
 if ((ui>>30)==0) { n = n + 2; ui = ui<< 2; }
 n = n - (ui>>31);
 return (n);
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
double sin(double);
double cos(double);
double sqrt(double);
double atan(double);
double atan2(double, double);
float sinf(float);
float cosf(float);
float sqrtf(float);
double pow(double, double);
double fabs(double);
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
 union { float f ; int i ; } u ;
 u.f = (float)num - 0.5f ;
 return 1 << ( ( u.i >> 23 ) - 126 ) ;
}
static __inline__ int sceGimPictureCLZ( int num )
{
 int i ;
 for ( i = 31 ; i >= 0 ; -- i ) if ( ( 1 << i ) & num ) return 31 - i ;
 return 32 ;
}
static __inline__ int sceGimPictureCTZ( int num )
{
 int i ;
 for ( i = 0 ; i <= 31 ; i ++ ) if ( ( 1 << i ) & num ) return i ;
 return 32 ;
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
typedef ScePspFVector2 SceGmoVec2F ;
typedef ScePspFVector3 SceGmoVec3F ;
typedef ScePspFVector4Unaligned SceGmoVec4F ;
typedef ScePspFMatrix4Unaligned SceGmoMat4F ;
typedef ScePspFQuaternionUnaligned SceGmoQuatF ;
typedef ScePspFRect SceGmoRectF ;
typedef ScePspFColorUnaligned SceGmoCol4F ;
enum {
 SCEGMO_BASE_RESERVED = 0x0000,
 SCEGMO_BASE_PRIVATE = 0x1000,
 SCEGMO_BASE_PUBLIC = 0x4000,
 SCEGMO_HALF_CHUNK = 0x8000,
 SCEGMO_BLOCK = 0x0001,
 SCEGMO_FILE = 0x0002,
 SCEGMO_MODEL = 0x0003,
 SCEGMO_BONE = 0x0004,
 SCEGMO_PART = 0x0005,
 SCEGMO_MESH = 0x0006,
 SCEGMO_ARRAYS = 0x0007,
 SCEGMO_MATERIAL = 0x0008,
 SCEGMO_LAYER = 0x0009,
 SCEGMO_TEXTURE = 0x000a,
 SCEGMO_MOTION = 0x000b,
 SCEGMO_FCURVE = 0x000c,
 SCEGMO_BLIND_BLOCK = 0x000f,
 SCEGMO_COMMAND = 0x0011,
 SCEGMO_FILE_NAME = 0x0012,
 SCEGMO_FILE_IMAGE = 0x0013,
 SCEGMO_BOUNDING_BOX = 0x0014,
 SCEGMO_BOUNDING_POINTS = 0x0016,
 SCEGMO_VERTEX_OFFSET = 0x0015,
 SCEGMO_DEFINE_ENUM = 0x0021,
 SCEGMO_DEFINE_BLOCK = 0x0022,
 SCEGMO_DEFINE_COMMAND = 0x0023,
 SCEGMO_PARENT_BONE = 0x0041,
 SCEGMO_VISIBILITY = 0x0042,
 SCEGMO_MORPH_WEIGHTS = 0x0043,
 SCEGMO_MORPH_INDEX = 0x004f,
 SCEGMO_BLEND_BONES = 0x0044,
 SCEGMO_BLEND_OFFSETS = 0x0045,
 SCEGMO_PIVOT = 0x0046,
 SCEGMO_MULT_MATRIX = 0x0047,
 SCEGMO_TRANSLATE = 0x0048,
 SCEGMO_ROTATE_ZYX = 0x0049,
 SCEGMO_ROTATE_YXZ = 0x004a,
 SCEGMO_ROTATE_Q = 0x004b,
 SCEGMO_SCALE = 0x004c,
 SCEGMO_SCALE_2 = 0x004d,
 SCEGMO_SCALE_3 = 0x00e1,
 SCEGMO_DRAW_PART = 0x004e,
 SCEGMO_BONE_STATE = 0x00e2,
 SCEGMO_SET_MATERIAL = 0x0061,
 SCEGMO_BLEND_SUBSET = 0x0062,
 SCEGMO_SUBDIVISION = 0x0063,
 SCEGMO_KNOT_VECTOR_U = 0x0064,
 SCEGMO_KNOT_VECTOR_V = 0x0065,
 SCEGMO_DRAW_ARRAYS = 0x0066,
 SCEGMO_DRAW_PARTICLE = 0x0067,
 SCEGMO_DRAW_B_SPLINE = 0x0068,
 SCEGMO_DRAW_RECT_MESH = 0x0069,
 SCEGMO_DRAW_RECT_PATCH = 0x006a,
 SCEGMO_MESH_TYPE = 0x006b,
 SCEGMO_MESH_LEVEL = 0x006c,
 SCEGMO_EDGE_FLAGS = 0x006d,
 SCEGMO_EDGE_FACES = 0x006e,
 SCEGMO_RENDER_STATE = 0x0081,
 SCEGMO_DIFFUSE = 0x0082,
 SCEGMO_SPECULAR = 0x0083,
 SCEGMO_EMISSION = 0x0084,
 SCEGMO_AMBIENT = 0x0085,
 SCEGMO_REFLECTION = 0x0086,
 SCEGMO_REFRACTION = 0x0087,
 SCEGMO_BUMP = 0x0088,
 SCEGMO_SET_TEXTURE = 0x0091,
 SCEGMO_MAP_TYPE = 0x0092,
 SCEGMO_MAP_FACTOR = 0x0093,
 SCEGMO_BLEND_FUNC = 0x0094,
 SCEGMO_TEX_FUNC = 0x0095,
 SCEGMO_TEX_FILTER = 0x0096,
 SCEGMO_TEX_WRAP = 0x0097,
 SCEGMO_TEX_CROP = 0x0098,
 SCEGMO_TEX_GEN = 0x0099,
 SCEGMO_TEX_MATRIX = 0x009a,
 SCEGMO_FRAME_LOOP = 0x00b1,
 SCEGMO_FRAME_RATE = 0x00b2,
 SCEGMO_FRAME_REPEAT = 0x00b4,
 SCEGMO_ANIMATE = 0x00b3,
 SCEGMO_BLIND_DATA = 0x00f1,
 SCEGMO_FILE_INFO = 0x00ff
} ;
enum {
 SCEGMO_FCURVE_FLOAT16 = 0x0080,
 SCEGMO_FCURVE_INTERP_MASK = 0x000f,
 SCEGMO_FCURVE_CONSTANT = 0x0000,
 SCEGMO_FCURVE_LINEAR = 0x0001,
 SCEGMO_FCURVE_HERMITE = 0x0002,
 SCEGMO_FCURVE_CUBIC = 0x0003,
 SCEGMO_FCURVE_SPHERICAL = 0x0004,
 SCEGMO_FCURVE_EXTRAP_MASK = 0xff00,
 SCEGMO_FCURVE_HOLD = 0x0000,
 SCEGMO_FCURVE_CYCLE = 0x1100,
 SCEGMO_FCURVE_SHUTTLE = 0x2200,
 SCEGMO_FCURVE_REPEAT = 0x3300,
 SCEGMO_FCURVE_EXTEND = 0x4400,
 SCEGMO_FCURVE_EXTRAP_LEFT_MASK = 0x0f00,
 SCEGMO_FCURVE_HOLD_LEFT = 0x0000,
 SCEGMO_FCURVE_CYCLE_LEFT = 0x0100,
 SCEGMO_FCURVE_SHUTTLE_LEFT = 0x0200,
 SCEGMO_FCURVE_REPEAT_LEFT = 0x0300,
 SCEGMO_FCURVE_EXTEND_LEFT = 0x0400,
 SCEGMO_FCURVE_EXTRAP_RIGHT_MASK = 0xf000,
 SCEGMO_FCURVE_HOLD_RIGHT = 0x0000,
 SCEGMO_FCURVE_CYCLE_RIGHT = 0x1000,
 SCEGMO_FCURVE_SHUTTLE_RIGHT = 0x2000,
 SCEGMO_FCURVE_REPEAT_RIGHT = 0x3000,
 SCEGMO_FCURVE_EXTEND_RIGHT = 0x4000
} ;
enum {
 SCEGMO_PRIM_SEQUENTIAL = 0x0100,
 SCEGMO_PRIM_TYPE_MASK = 0x000f,
 SCEGMO_PRIM_POINTS = 0x0000,
 SCEGMO_PRIM_LINES = 0x0001,
 SCEGMO_PRIM_LINE_STRIP = 0x0002,
 SCEGMO_PRIM_TRIANGLES = 0x0003,
 SCEGMO_PRIM_TRIANGLE_STRIP = 0x0004,
 SCEGMO_PRIM_TRIANGLE_FAN = 0x0005,
 SCEGMO_PRIM_RECTANGLES = 0x0006,
 SCEGMO_PRIM_SPLINE_MASK = 0xf000,
 SCEGMO_PRIM_OPEN_U = 0x3000,
 SCEGMO_PRIM_OPEN_V = 0xc000,
 SCEGMO_PRIM_OPEN_U_IN = 0x1000,
 SCEGMO_PRIM_OPEN_U_OUT = 0x2000,
 SCEGMO_PRIM_OPEN_V_IN = 0x4000,
 SCEGMO_PRIM_OPEN_V_OUT = 0x8000
} ;
enum {
 SCEGMO_REPEAT_HOLD = 0,
 SCEGMO_REPEAT_CYCLE = 1
} ;
enum {
 SCEGMO_STATE_LIGHTING = 0,
 SCEGMO_STATE_FOG = 1,
 SCEGMO_STATE_TEXTURE = 2,
 SCEGMO_STATE_CULL_FACE = 3,
 SCEGMO_STATE_DEPTH_TEST = 4,
 SCEGMO_STATE_DEPTH_MASK = 5,
 SCEGMO_STATE_ALPHA_TEST = 6,
 SCEGMO_STATE_ALPHA_MASK = 7,
 SCEGMO_STATE_FLIP_FACE = 8,
 SCEGMO_STATE_FLIP_NORMAL = 9
} ;
enum {
 SCEGMO_BLEND_ADD = 0,
 SCEGMO_BLEND_SUB = 1,
 SCEGMO_BLEND_REV = 2,
 SCEGMO_BLEND_MIN = 3,
 SCEGMO_BLEND_MAX = 4,
 SCEGMO_BLEND_DIFF = 5,
 SCEGMO_BLEND_ZERO = 0,
 SCEGMO_BLEND_ONE = 1,
 SCEGMO_BLEND_SRC_COLOR = 2,
 SCEGMO_BLEND_INV_SRC_COLOR = 3,
 SCEGMO_BLEND_DST_COLOR = 4,
 SCEGMO_BLEND_INV_DST_COLOR = 5,
 SCEGMO_BLEND_SRC_ALPHA = 6,
 SCEGMO_BLEND_INV_SRC_ALPHA = 7,
 SCEGMO_BLEND_DST_ALPHA = 8,
 SCEGMO_BLEND_INV_DST_ALPHA = 9
} ;
enum {
 SCEGMO_FUNC_MODULATE = 0,
 SCEGMO_FUNC_DECAL = 1,
 SCEGMO_FUNC_RGB = 0,
 SCEGMO_FUNC_RGBA = 1
} ;
enum {
 SCEGMO_FILTER_NEAREST = 0,
 SCEGMO_FILTER_LINEAR = 1,
 SCEGMO_FILTER_NEAREST_MIPMAP_NEAREST = 2,
 SCEGMO_FILTER_LINEAR_MIPMAP_NEAREST = 3,
 SCEGMO_FILTER_NEAREST_MIPMAP_LINEAR = 4,
 SCEGMO_FILTER_LINEAR_MIPMAP_LINEAR = 5
} ;
enum {
 SCEGMO_WRAP_REPEAT = 0,
 SCEGMO_WRAP_CLAMP = 1
} ;
enum {
 SCEGMO_GEN_MATRIX_MASK = 0x0f00,
 SCEGMO_GEN_MATRIX_ROT = 0x8000,
 SCEGMO_GEN_LOCAL = 0x0000,
 SCEGMO_GEN_MODEL = 0x0100,
 SCEGMO_GEN_WORLD = 0x0200,
 SCEGMO_GEN_MODEL_ROT = 0x8100,
 SCEGMO_GEN_WORLD_ROT = 0x8200,
 SCEGMO_GEN_VECTOR_MASK = 0x000f,
 SCEGMO_GEN_TEXCOORD = 0x0000,
 SCEGMO_GEN_NORMAL = 0x0001,
 SCEGMO_GEN_VERTEX = 0x0002
} ;
enum {
 SCEGMO_BONE_STATE_Z_SORT = 0
} ;
enum {
 SCEGMO_MESH_TYPE_FACE = 0x0001,
 SCEGMO_MESH_TYPE_EDGE = 0x0002
} ;
enum {
 SCEGMO_EDGE_ALL = 0x0f,
 SCEGMO_EDGE_VERGE = 0x01,
 SCEGMO_EDGE_RIDGE = 0x02,
 SCEGMO_EDGE_HARD = 0x04,
 SCEGMO_EDGE_SEAM = 0x08,
 SCEGMO_EDGE_BACK_FACE = 0x80,
 SCEGMO_EDGE_PRIM_START = 0x40,
 SCEGMO_EDGE_PRIM_PIVOT = 0x20
} ;
typedef struct SceGmoHeader {
 unsigned int signature ;
 unsigned int version ;
 unsigned int style ;
 unsigned int option ;
} SceGmoHeader ;
typedef struct SceGmoChunk {
 unsigned short type ;
 unsigned short args_offs ;
 unsigned int next_offs ;
 unsigned int child_offs ;
 unsigned int data_offs ;
} SceGmoChunk ;
static __inline__ _Bool SCEGMO_CHUNK_ISHALF( const SceGmoChunk *chunk )
{
 return ( ( SCEGMO_HALF_CHUNK & chunk->type ) != 0 ) ;
}
static __inline__ int SCEGMO_CHUNK_TYPE( const SceGmoChunk *chunk )
{
 return ( ~SCEGMO_HALF_CHUNK & chunk->type ) ;
}
static __inline__ SceGmoChunk *SCEGMO_CHUNK_NEXT( const SceGmoChunk *chunk )
{
 return (SceGmoChunk *)( (char *)chunk + chunk->next_offs ) ;
}
static __inline__ SceGmoChunk *SCEGMO_CHUNK_CHILD( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return SCEGMO_CHUNK_NEXT( chunk ) ;
 return (SceGmoChunk *)( (char *)chunk + chunk->child_offs ) ;
}
static __inline__ char *SCEGMO_CHUNK_NAME( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return "" ;
 return (char *)( chunk + 1 ) ;
}
static __inline__ void *SCEGMO_CHUNK_ARGS( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return (char *)chunk + 8 ;
 return (char *)chunk + chunk->args_offs ;
}
static __inline__ void *SCEGMO_CHUNK_DATA( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return SCEGMO_CHUNK_ARGS( chunk ) ;
 return (char *)chunk + chunk->data_offs ;
}
static __inline__ int SCEGMO_CHUNK_SIZE( const SceGmoChunk *chunk )
{
 return chunk->next_offs ;
}
static __inline__ int SCEGMO_CHUNK_TAGSIZE( const SceGmoChunk *chunk )
{
 return ( SCEGMO_HALF_CHUNK & chunk->type ) ? 8 : 16 ;
}
static __inline__ int SCEGMO_CHUNK_NAMESIZE( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
 return chunk->args_offs - 16 ;
}
static __inline__ int SCEGMO_CHUNK_ARGSSIZE( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return chunk->next_offs - 8 ;
 return chunk->data_offs - chunk->args_offs ;
}
static __inline__ int SCEGMO_CHUNK_DATASIZE( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
 return chunk->child_offs - chunk->data_offs ;
}
static __inline__ int SCEGMO_CHUNK_CHILDSIZE( const SceGmoChunk *chunk )
{
 if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
 return chunk->next_offs - chunk->child_offs ;
}
static __inline__ void *SCEGMO_CHUNK_SKIPSTRING( const char *str, int align )
{
 str += strlen( str ) + 1 ;
 align -= 1 ;
 return (void *)( ( (int)str + align ) & ~align ) ;
}
typedef struct {
 int format ;
 int n_verts ;
 int n_morphs ;
 int format2 ;
} SceGmoArraysHeader ;
typedef struct {
 int format ;
 int n_dims ;
 int n_keys ;
 int reserved ;
} SceGmoFCurveHeader ;
typedef struct {
 char name[ 1 ] ;
} SceGmoFileName ;
typedef struct {
 int size ;
 int data[ 1 ] ;
} SceGmoFileImage ;
typedef struct {
 SceGmoVec3F lower ;
 SceGmoVec3F upper ;
} SceGmoBoundingBox ;
typedef struct {
 int n_points ;
 SceGmoVec3F points[ 1 ] ;
} SceGmoBoundingPoints ;
typedef struct {
 int format ;
 float offset[ 1 ] ;
} SceGmoVertexOffset ;
typedef struct {
 int bone ;
} SceGmoParentBone ;
typedef struct {
 int visibility ;
} SceGmoVisibility ;
typedef struct {
 int n_weights ;
 float weights[ 1 ] ;
} SceGmoMorphWeights ;
typedef struct {
 float index ;
} SceGmoMorphIndex ;
typedef struct {
 int n_bones ;
 int bones[ 1 ] ;
} SceGmoBlendBones ;
typedef struct {
 int n_offsets ;
 SceGmoMat4F offsets[ 1 ] ;
} SceGmoBlendOffsets ;
typedef struct {
 SceGmoVec3F pivot ;
} SceGmoPivot ;
typedef struct {
 SceGmoMat4F matrix ;
} SceGmoMultMatrix ;
typedef struct {
 SceGmoVec3F translate ;
} SceGmoTranslate ;
typedef struct {
 SceGmoVec3F rotate ;
} SceGmoRotateZYX ;
typedef struct {
 SceGmoVec3F rotate ;
} SceGmoRotateYXZ ;
typedef struct {
 SceGmoQuatF rotate ;
} SceGmoRotateQ ;
typedef struct {
 SceGmoVec3F scale ;
} SceGmoScale ;
typedef struct {
 SceGmoVec3F scale ;
} SceGmoScale2 ;
typedef struct {
 SceGmoVec3F scale ;
} SceGmoScale3 ;
typedef struct {
 int part ;
} SceGmoDrawPart ;
typedef struct {
 int state ;
 int value ;
} SceGmoBoneState ;
typedef struct {
 int material ;
} SceGmoSetMaterial ;
typedef struct {
 int n_indices ;
 int indices[ 1 ] ;
} SceGmoBlendSubset ;
typedef struct {
 float div_u ;
 float div_v ;
} SceGmoSubdivision ;
typedef struct {
 int arrays ;
 int mode ;
 int n_verts ;
 int n_prims ;
 unsigned short indices[ 1 ] ;
} SceGmoDrawArrays ;
typedef struct {
 int arrays ;
 int mode ;
 int n_verts ;
 int n_prims ;
 unsigned short indices[ 1 ] ;
} SceGmoDrawParticle ;
typedef struct {
 int arrays ;
 int mode ;
 int width ;
 int height ;
 unsigned short indices[ 1 ] ;
} SceGmoDrawBSpline ;
typedef struct {
 int arrays ;
 int mode ;
 int width ;
 int height ;
 unsigned short indices[ 1 ] ;
} SceGmoDrawRectMesh ;
typedef struct {
 int arrays ;
 int mode ;
 int width ;
 int height ;
 unsigned short indices[ 1 ] ;
} SceGmoDrawRectPatch ;
typedef struct {
 int type ;
} SceGmoMeshType ;
typedef struct {
 int min ;
 int max ;
} SceGmoMeshLevel ;
typedef struct {
 int n_flags ;
 unsigned char flags[ 1 ] ;
} SceGmoEdgeFlags ;
typedef struct {
 int n_faces ;
 unsigned short faces[ 1 ] ;
} SceGmoEdgeFaces ;
typedef struct {
 int state ;
 int value ;
} SceGmoRenderState ;
typedef struct {
 SceGmoCol4F color ;
} SceGmoDiffuse ;
typedef struct {
 SceGmoCol4F color ;
 float shininess ;
} SceGmoSpecular ;
typedef struct {
 SceGmoCol4F color ;
} SceGmoEmission ;
typedef struct {
 SceGmoCol4F color ;
} SceGmoAmbient ;
typedef struct {
 float reflection ;
} SceGmoReflection ;
typedef struct {
 float refraction ;
} SceGmoRefraction ;
typedef struct {
 float bump ;
} SceGmoBump ;
typedef struct {
 int texture ;
} SceGmoSetTexture ;
typedef struct {
 int type ;
} SceGmoMapType ;
typedef struct {
 float factor ;
} SceGmoMapFactor ;
typedef struct {
 int mode ;
 int src ;
 int dst ;
} SceGmoBlendFunc ;
typedef struct {
 int func ;
 int comp ;
} SceGmoTexFunc ;
typedef struct {
 int mag ;
 int min ;
} SceGmoTexFilter ;
typedef struct {
 int wrap_u ;
 int wrap_v ;
} SceGmoTexWrap ;
typedef struct {
 SceGmoRectF crop ;
} SceGmoTexCrop ;
typedef struct {
 int mode ;
} SceGmoTexGen ;
typedef struct {
 SceGmoMat4F matrix ;
} SceGmoTexMatrix ;
typedef struct {
 float start ;
 float end ;
} SceGmoFrameLoop ;
typedef struct {
 float fps ;
} SceGmoFrameRate ;
typedef struct {
 int mode ;
} SceGmoFrameRepeat ;
typedef struct {
 int block ;
 int cmd ;
 int index ;
 int fcurve ;
} SceGmoAnimate ;
typedef struct {
 char name[ 1 ] ;
} SceGmoBlindData ;
typedef struct {
 char project_name[ 1 ] ;
} SceGmoFileInfo ;
typedef struct SceGmoMetrics SceGmoMetrics ;
struct SceGmoMetrics {
 int memory_size ;
 int memory_size2 ;
 int model_count ;
 int model_size ;
 int bone_count ;
 int bone_size ;
 int bone_morph_count ;
 int bone_blend_count ;
 int bone_part_count ;
 int part_count ;
 int part_size ;
 int mesh_count ;
 int mesh_size ;
 int mesh_material_count ;
 int mesh_blend_count ;
 int mesh_draw_count ;
 int mesh_prim_count ;
 int mesh_vertex_count ;
 int mesh_index_count ;
 int mesh_point_count ;
 int mesh_line_count ;
 int mesh_tri_count ;
 int mesh_rect_count ;
 int mesh_patch_count ;
 int arrays_count ;
 int arrays_size ;
 int arrays_morph_count ;
 int arrays_vertex_count ;
 int material_count ;
 int material_size ;
 int layer_count ;
 int layer_size ;
 int layer_texture_count ;
 int texture_count ;
 int texture_size ;
 int motion_count ;
 int motion_size ;
 int motion_anim_count ;
 int fcurve_count ;
 int fcurve_size ;
 int fcurve_key_count ;
} ;
int sceGmoModelGetMetrics( SceGmoMetrics *buf, int size, const SceGmoChunk *chunk ) ;
int sceGmoModelAddMetrics( SceGmoMetrics *buf, int size, const SceGmoChunk *chunk ) ;
int sceGmoModelGetPictureMetrics( SceGimMetrics *buf, int size, const SceGmoChunk *chunk ) ;
int sceGmoModelAddPictureMetrics( SceGimMetrics *buf, int size, const SceGmoChunk *chunk ) ;
int sceGmoModelGetMemoryClusterSize( const SceGmoMetrics *m, int size, int align ) ;
int sceGmoModelGetMemoryClusterSizeEx( const SceGmoMetrics *m, int size, int align, int dup_flags ) ;
int sceGmoModelGetMemoryClusterSize2( const SceGmoMetrics *m, int size, int align ) ;
int sceGmoModelGetMemoryClusterSize2Ex( const SceGmoMetrics *m, int size, int align, int dup_flags ) ;
static __inline__ void sceGmoModelGetMemoryClusterSizes( int *sizes, const int *aligns, const SceGmoChunk *chunk )
{
 SceGmoMetrics mm ;
 SceGimMetrics pm ;
 if ( sizes == 0 || aligns == 0 ) return ;
 sceGmoModelGetMetrics( &mm, sizeof( mm ), chunk ) ;
 sceGmoModelGetPictureMetrics( &pm, sizeof( pm ), chunk ) ;
 sizes[ 0 ] = sceGmoModelGetMemoryClusterSize( &mm, sizeof( mm ), aligns[ 0 ] ) ;
 sizes[ 1 ] = sceGmoModelGetMemoryClusterSize2( &mm, sizeof( mm ), aligns[ 1 ] ) ;
 sizes[ 2 ] = sceGimPictureGetMemoryClusterSize( &pm, sizeof( pm ), aligns[ 2 ] ) ;
 sizes[ 3 ] = sceGimPictureGetMemoryClusterSize2( &pm, sizeof( pm ), aligns[ 3 ] ) ;
}
typedef ScePspFVector4 SceGmoVec2 ;
typedef ScePspFVector4 SceGmoVec3 ;
typedef ScePspFVector4 SceGmoVec4 ;
typedef ScePspFMatrix4 SceGmoMat4 ;
typedef ScePspFQuaternion SceGmoQuat ;
typedef ScePspFRect __attribute__((aligned(16))) SceGmoRect ;
typedef unsigned int SceGmoCol4 ;
enum {
 SCEGMO_DUPLICATE_REFERENCE = 0x0000,
 SCEGMO_DUPLICATE_STRUCTURE = 0x0001,
 SCEGMO_DUPLICATE_AUTOMATIC = 0x0002,
 SCEGMO_DUPLICATE_ALL = 0xffff,
 SCEGMO_DUPLICATE_MODEL = 0x0008,
 SCEGMO_DUPLICATE_BONE = 0x0010,
 SCEGMO_DUPLICATE_PART = 0x0020,
 SCEGMO_DUPLICATE_MESH = 0x0040,
 SCEGMO_DUPLICATE_ARRAYS = 0x0080,
 SCEGMO_DUPLICATE_MATERIAL = 0x0100,
 SCEGMO_DUPLICATE_LAYER = 0x0200,
 SCEGMO_DUPLICATE_TEXTURE = 0x0400,
 SCEGMO_DUPLICATE_MOTION = 0x0800,
 SCEGMO_DUPLICATE_FCURVE = 0x1000
} ;
enum {
 SCEGMO_ANIMATE_ALL = 0xffff,
 SCEGMO_ANIMATE_FRAME = 0x0001,
 SCEGMO_ANIMATE_PARAM = 0x0002
} ;
enum {
 SCEGMO_UPDATE_ALL = 0xffff,
 SCEGMO_UPDATE_PARAM = 0x0001,
 SCEGMO_UPDATE_MATRIX = 0x0002
} ;
enum {
 SCEGMO_DRAW_ALL = 0xffff,
 SCEGMO_DRAW_PRIMITIVE = 0x0001,
 SCEGMO_DRAW_TRANSFORM = 0x0002,
 SCEGMO_DRAW_MATERIAL = 0x0004,
 SCEGMO_DRAW_TEXTURE = 0x0008
} ;
enum {
 SCEGMO_CACHE_ALL = 0xffff,
 SCEGMO_CACHE_PRIMITIVE = 0x0001,
 SCEGMO_CACHE_TEXTURE = 0x0002,
 SCEGMO_CACHE_VERTEX = 0x0004,
 SCEGMO_CACHE_PIXEL = 0x0008
} ;
enum {
 SCEGMO_ENABLE_ALL = 0xffff,
 SCEGMO_ENABLE_DEFAULT = 0xfcff,
 SCEGMO_ENABLE_LIGHTING = 0x0001,
 SCEGMO_ENABLE_FOG = 0x0002,
 SCEGMO_ENABLE_TEXTURE = 0x0004,
 SCEGMO_ENABLE_CULL_FACE = 0x0008,
 SCEGMO_ENABLE_DEPTH_TEST = 0x0010,
 SCEGMO_ENABLE_DEPTH_MASK = 0x0020,
 SCEGMO_ENABLE_ALPHA_TEST = 0x0040,
 SCEGMO_ENABLE_ALPHA_MASK = 0x0080,
 SCEGMO_ENABLE_FLIP_FACE = 0x0100,
 SCEGMO_ENABLE_FLIP_NORMAL = 0x0200,
 SCEGMO_ENABLE_TEX_FUNC = 0x0c00,
 SCEGMO_ENABLE_TEX_MODULATE = 0x0400,
 SCEGMO_ENABLE_TEX_RGBA = 0x0800,
 SCEGMO_ENABLE_TEX_FILTER = 0x3000,
 SCEGMO_ENABLE_TEX_BILINEAR = 0x1000,
 SCEGMO_ENABLE_TEX_TRILINEAR = 0x2000,
 SCEGMO_ENABLE_TEX_WRAP = 0xc000,
 SCEGMO_ENABLE_TEX_WRAP_U = 0x4000,
 SCEGMO_ENABLE_TEX_WRAP_V = 0x8000
} ;
enum {
 SCEGMO_OUTPUT_ALL = 0xffffffff,
 SCEGMO_OUTPUT_DEFAULT = 0xffffffff,
 SCEGMO_OUTPUT_TRANSFORM = 0x000f0000,
 SCEGMO_OUTPUT_MATERIAL = 0x0ff0ffff,
 SCEGMO_OUTPUT_TEXTURE = 0x80000000,
 SCEGMO_OUTPUT_WORLD_MATRIX = 0x00010000,
 SCEGMO_OUTPUT_BONE_MATRIX = 0x00020000,
 SCEGMO_OUTPUT_MORPH_WEIGHT = 0x00040000,
 SCEGMO_OUTPUT_SUBDIVISION = 0x00080000,
 SCEGMO_OUTPUT_MATERIAL_COLOR = 0x00100000,
 SCEGMO_OUTPUT_BLEND_FUNC = 0x00200000,
 SCEGMO_OUTPUT_LIGHT_MODEL = 0x00400000,
 SCEGMO_OUTPUT_TEX_CROP = 0x00800000,
 SCEGMO_OUTPUT_TEX_GEN = 0x01000000,
 SCEGMO_OUTPUT_TEX_MATRIX = 0x02000000,
 SCEGMO_OUTPUT_ENABLE_BITS = SCEGMO_ENABLE_ALL,
 SCEGMO_OUTPUT_ENABLE_LIGHTING = SCEGMO_ENABLE_LIGHTING,
 SCEGMO_OUTPUT_ENABLE_FOG = SCEGMO_ENABLE_FOG,
 SCEGMO_OUTPUT_ENABLE_TEXTURE = SCEGMO_ENABLE_TEXTURE,
 SCEGMO_OUTPUT_ENABLE_CULL_FACE = SCEGMO_ENABLE_CULL_FACE,
 SCEGMO_OUTPUT_ENABLE_DEPTH_TEST = SCEGMO_ENABLE_DEPTH_TEST,
 SCEGMO_OUTPUT_ENABLE_DEPTH_MASK = SCEGMO_ENABLE_DEPTH_MASK,
 SCEGMO_OUTPUT_ENABLE_ALPHA_TEST = SCEGMO_ENABLE_ALPHA_TEST,
 SCEGMO_OUTPUT_ENABLE_ALPHA_MASK = SCEGMO_ENABLE_ALPHA_MASK,
 SCEGMO_OUTPUT_ENABLE_FLIP_FACE = SCEGMO_ENABLE_FLIP_FACE,
 SCEGMO_OUTPUT_ENABLE_FLIP_NORMAL = SCEGMO_ENABLE_FLIP_NORMAL,
 SCEGMO_OUTPUT_ENABLE_TEX_FUNC = SCEGMO_ENABLE_TEX_FUNC,
 SCEGMO_OUTPUT_ENABLE_TEX_FILTER = SCEGMO_ENABLE_TEX_FILTER,
 SCEGMO_OUTPUT_ENABLE_TEX_WRAP = SCEGMO_ENABLE_TEX_WRAP
} ;
enum {
 SCEGMO_OPTION_ALL = 0xffff,
 SCEGMO_OPTION_DEFAULT = 0x00ff,
 SCEGMO_OPTION_MULTIPLY_WORLD = 0x0001,
 SCEGMO_OPTION_RESTORE_STATE = 0x0002,
 SCEGMO_OPTION_SUBFRAME_INTERP = 0x0004,
 SCEGMO_OPTION_SOFTWARE_CLIPPING = 0x0100
} ;
enum {
 SCEGMO_MESH_TYPE_ALL = 0x0000ffff,
 SCEGMO_MESH_TYPE_MASK = 0x0000ffff,
 SCEGMO_MESH_TYPE_DEFAULT = 0x00000001,
 SCEGMO_MESH_LEVEL_ALL = 0xffff0000,
 SCEGMO_MESH_LEVEL_MASK = 0xffff0000,
 SCEGMO_MESH_LEVEL_DEFAULT = 0x00010000
} ;
typedef struct SceGmoModel SceGmoModel ;
typedef struct SceGmoBone SceGmoBone ;
typedef struct SceGmoPart SceGmoPart ;
typedef struct SceGmoMesh SceGmoMesh ;
typedef struct SceGmoMaterial SceGmoMaterial ;
typedef struct SceGmoLayer SceGmoLayer ;
typedef struct SceGmoTexture SceGmoTexture ;
typedef struct SceGmoMotion SceGmoMotion ;
void sceGmoModelSetMemoryManager( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetMemoryManager2( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetMemoryManager3( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetPictureManager( SceGimPicture *(*get_func)( const char *filename ), void (*set_func)( const char *filename, SceGimPicture *picture ) ) ;
void sceGmoModelSetPictureManager2( SceGimPicture *(*get_func)( int type ), void (*set_func)( int type, SceGimPicture *picture ) ) ;
void *sceGmoModelOpenMemoryCluster( size_t size, size_t align ) ;
void *sceGmoModelOpenMemoryCluster2( size_t size, size_t align ) ;
void *sceGmoModelOpenMemoryCluster3( size_t size, size_t align ) ;
int sceGmoModelCloseMemoryCluster( void ) ;
int sceGmoModelCloseMemoryCluster2( void ) ;
int sceGmoModelCloseMemoryCluster3( void ) ;
void *sceGmoModelAllocMemory( size_t size ) ;
void *sceGmoModelAllocMemory2( size_t size ) ;
void *sceGmoModelAllocMemory3( size_t size ) ;
void sceGmoModelFreeMemory( void *addr ) ;
void sceGmoModelFreeMemory2( void *addr ) ;
void sceGmoModelFreeMemory3( void *addr ) ;
SceGimPicture *sceGmoModelImportPicture( const char *filename ) ;
SceGimPicture *sceGmoModelImportPicture2( int type ) ;
void sceGmoModelExportPicture( const char *filename, SceGimPicture *picture ) ;
void sceGmoModelExportPicture2( int type, SceGimPicture *picture ) ;
_Bool sceGmoModelCheckFileHeader( const void *buf, int size ) ;
int sceGmoModelGetChunkCount( const void *buf, int size ) ;
SceGmoChunk *sceGmoModelGetChunk( const void *buf, int size, int idx ) ;
SceGmoChunk *sceGmoModelGetRootChunk( const void *buf, int size ) ;
int sceGmoModelCountChildChunk( const SceGmoChunk *chunk, int type ) ;
SceGmoChunk *sceGmoModelFindChildChunk( const SceGmoChunk *chunk, int type, int idx ) ;
SceGmoModel *sceGmoModelCreate( const SceGmoChunk *chunk ) ;
void sceGmoModelDelete( SceGmoModel *model ) ;
SceGmoModel *sceGmoModelDuplicate( SceGmoModel *model, int flags ) ;
_Bool sceGmoModelLoadFile( SceGmoModel *model, const void *buf, int size, int idx ) ;
_Bool sceGmoModelLoad( SceGmoModel *model, const SceGmoChunk *chunk ) ;
void sceGmoModelUnload( SceGmoModel *model ) ;
_Bool sceGmoModelLoadCache( SceGmoModel *model ) ;
_Bool sceGmoModelLoadCacheEx( SceGmoModel *model, int flags ) ;
void sceGmoModelUnloadCache( SceGmoModel *model ) ;
void sceGmoModelUnloadCacheEx( SceGmoModel *model, int flags ) ;
void sceGmoModelAnimate( SceGmoModel *model, float step ) ;
void sceGmoModelAnimateEx( SceGmoModel *model, float step, int flags ) ;
void sceGmoModelUpdate( SceGmoModel *model ) ;
void sceGmoModelUpdateEx( SceGmoModel *model, int flags ) ;
_Bool sceGmoModelDraw( SceGmoModel *model ) ;
_Bool sceGmoModelDrawEx( SceGmoModel *model, unsigned int **pkt, unsigned int *size, int flags ) ;
void sceGmoModelSetWorldMatrix( SceGmoModel *model, const SceGmoMat4 *matrix ) ;
const SceGmoMat4 *sceGmoModelGetWorldMatrix( SceGmoModel *model ) ;
void sceGmoModelSetCurrentMotion( SceGmoModel *model, int idx, float delay ) ;
int sceGmoModelGetCurrentMotion( SceGmoModel *model ) ;
void sceGmoModelSetColor( SceGmoModel *model, SceGmoCol4 color ) ;
SceGmoCol4 sceGmoModelGetColor( SceGmoModel *model ) ;
void sceGmoModelSetSubdivision( SceGmoModel *model, float subdiv ) ;
float sceGmoModelGetSubdivision( SceGmoModel *model ) ;
void sceGmoModelSetGlobalTexGen( int mode, const SceGmoMat4 *matrix ) ;
void sceGmoModelGetGlobalTexGen( int *mode, const SceGmoMat4 **matrix ) ;
void sceGmoModelSetClippingMatrix( const SceGmoMat4 *matrix, const SceGmoVec4 *margin ) ;
void sceGmoModelGetClippingMatrix( const SceGmoMat4 **matrix, const SceGmoVec4 **margin ) ;
void sceGmoModelSetEnableBits( SceGmoModel *model, int bits, int value ) ;
int sceGmoModelGetEnableBits( SceGmoModel *model ) ;
void sceGmoModelSetEnableMask( SceGmoModel *model, int mask, int value ) ;
int sceGmoModelGetEnableMask( SceGmoModel *model ) ;
void sceGmoModelSetOutputMask( SceGmoModel *model, int mask, int value ) ;
int sceGmoModelGetOutputMask( SceGmoModel *model ) ;
void sceGmoModelSetOptionFlags( SceGmoModel *model, int flags, int value ) ;
int sceGmoModelGetOptionFlags( SceGmoModel *model ) ;
void sceGmoModelSetMeshType( SceGmoModel *model, int type ) ;
int sceGmoModelGetMeshType( SceGmoModel *model ) ;
void sceGmoModelSetMeshLevel( SceGmoModel *model, int level ) ;
int sceGmoModelGetMeshLevel( SceGmoModel *model ) ;
_Bool sceGmoModelHasAnimation( SceGmoModel *model ) ;
const SceGmoVec3 *sceGmoModelGetBoundingBox( SceGmoModel *model ) ;
const SceGmoMat4 *sceGmoModelGetVertexOffset( SceGmoModel *model ) ;
const SceGmoRect *sceGmoModelGetTexcoordOffset( SceGmoModel *model ) ;
const SceGmoVec3F *sceGmoModelGetBoundingPoints( SceGmoModel *model ) ;
int sceGmoModelGetBoundingPointsCount( SceGmoModel *model ) ;
int sceGmoModelGetBoneCount( SceGmoModel *model ) ;
int sceGmoModelGetPartCount( SceGmoModel *model ) ;
int sceGmoModelGetMaterialCount( SceGmoModel *model ) ;
int sceGmoModelGetTextureCount( SceGmoModel *model ) ;
int sceGmoModelGetMotionCount( SceGmoModel *model ) ;
SceGmoBone *sceGmoModelGetBone( SceGmoModel *model, int idx ) ;
SceGmoPart *sceGmoModelGetPart( SceGmoModel *model, int idx ) ;
SceGmoMaterial *sceGmoModelGetMaterial( SceGmoModel *model, int idx ) ;
SceGmoTexture *sceGmoModelGetTexture( SceGmoModel *model, int idx ) ;
SceGmoMotion *sceGmoModelGetMotion( SceGmoModel *model, int idx ) ;
_Bool sceGmoModelSetBoneCount( SceGmoModel *model, int count ) ;
_Bool sceGmoModelSetPartCount( SceGmoModel *model, int count ) ;
_Bool sceGmoModelSetMaterialCount( SceGmoModel *model, int count ) ;
_Bool sceGmoModelSetTextureCount( SceGmoModel *model, int count ) ;
_Bool sceGmoModelSetMotionCount( SceGmoModel *model, int count ) ;
SceGmoBone *sceGmoModelSetBone( SceGmoModel *model, int idx, SceGmoBone *bone, int flags ) ;
SceGmoPart *sceGmoModelSetPart( SceGmoModel *model, int idx, SceGmoPart *part, int flags ) ;
SceGmoMaterial *sceGmoModelSetMaterial( SceGmoModel *model, int idx, SceGmoMaterial *material, int flags ) ;
SceGmoTexture *sceGmoModelSetTexture( SceGmoModel *model, int idx, SceGmoTexture *texture, int flags ) ;
SceGmoMotion *sceGmoModelSetMotion( SceGmoModel *model, int idx, SceGmoMotion *motion, int flags ) ;
SceGmoBone *sceGmoBoneCreate( const SceGmoChunk *chunk ) ;
void sceGmoBoneDelete( SceGmoBone *bone ) ;
SceGmoBone *sceGmoBoneDuplicate( SceGmoBone *bone, int flags ) ;
_Bool sceGmoBoneLoad( SceGmoBone *bone, const SceGmoChunk *chunk ) ;
void sceGmoBoneUnload( SceGmoBone *bone ) ;
void sceGmoBoneUpdate( SceGmoBone *bone, SceGmoModel *model, int flags ) ;
void sceGmoBoneDraw( SceGmoBone *bone, SceGmoModel *model, int flags ) ;
void sceGmoBoneActivate( SceGmoBone *bone, SceGmoModel *model, const int *idxs, int n_idxs ) ;
void sceGmoBoneControl( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoBoneSetParent( SceGmoBone *bone, SceGmoModel *parent ) ;
SceGmoModel *sceGmoBoneGetParent( SceGmoBone *bone ) ;
SceGmoBone *sceGmoBoneGetInitialState( SceGmoBone *bone ) ;
void sceGmoBoneSetParentBone( SceGmoBone *bone, int idx ) ;
int sceGmoBoneGetParentBone( SceGmoBone *bone ) ;
void sceGmoBoneSetVisibility( SceGmoBone *bone, int visibility ) ;
int sceGmoBoneGetVisibility( SceGmoBone *bone ) ;
void sceGmoBoneSetMorphWeights( SceGmoBone *bone, const float *weights, int n_weights ) ;
int sceGmoBoneGetMorphWeightsCount( SceGmoBone *bone ) ;
const float *sceGmoBoneGetMorphWeights( SceGmoBone *bone ) ;
void sceGmoBoneSetMorphIndex( SceGmoBone *bone, float idx ) ;
float sceGmoBoneGetMorphIndex( SceGmoBone *bone ) ;
int sceGmoBoneGetBlendBonesCount( SceGmoBone *bone ) ;
const int *sceGmoBoneGetBlendBones( SceGmoBone *bone ) ;
int sceGmoBoneGetBlendOffsetsCount( SceGmoBone *bone ) ;
const SceGmoMat4 *sceGmoBoneGetBlendOffsets( SceGmoBone *bone ) ;
void sceGmoBoneSetPivot( SceGmoBone *bone, const SceGmoVec3 *pivot ) ;
const SceGmoVec3 *sceGmoBoneGetPivot( SceGmoBone *bone ) ;
void sceGmoBoneSetTranslate( SceGmoBone *bone, const SceGmoVec3 *translate ) ;
const SceGmoVec3 *sceGmoBoneGetTranslate( SceGmoBone *bone ) ;
void sceGmoBoneSetRotate( SceGmoBone *bone, const SceGmoQuat *rotate ) ;
const SceGmoQuat *sceGmoBoneGetRotate( SceGmoBone *bone ) ;
void sceGmoBoneSetScale( SceGmoBone *bone, const SceGmoVec3 *scale ) ;
const SceGmoVec3 *sceGmoBoneGetScale( SceGmoBone *bone ) ;
void sceGmoBoneSetRotateYXZ( SceGmoBone *bone, const SceGmoVec3 *rotate ) ;
void sceGmoBoneSetRotateZYX( SceGmoBone *bone, const SceGmoVec3 *rotate ) ;
void sceGmoBoneSetScale2( SceGmoBone *bone, const SceGmoVec3 *scale ) ;
void sceGmoBoneSetScale3( SceGmoBone *bone, const SceGmoVec3 *scale ) ;
void sceGmoBoneSetWorldMatrix( SceGmoBone *bone, const SceGmoMat4 *matrix ) ;
const SceGmoMat4 *sceGmoBoneGetWorldMatrix( SceGmoBone *bone ) ;
void sceGmoBoneSetColor( SceGmoBone *bone, SceGmoCol4 color ) ;
SceGmoCol4 sceGmoBoneGetColor( SceGmoBone *bone ) ;
void sceGmoBoneSetZSortMode( SceGmoBone *bone, int mode ) ;
int sceGmoBoneGetZSortMode( SceGmoBone *bone ) ;
SceGmoPart *sceGmoPartCreate( const SceGmoChunk *chunk ) ;
void sceGmoPartDelete( SceGmoPart *part ) ;
SceGmoPart *sceGmoPartDuplicate( SceGmoPart *part, int flags ) ;
_Bool sceGmoPartLoad( SceGmoPart *part, const SceGmoChunk *chunk ) ;
void sceGmoPartUnload( SceGmoPart *part ) ;
_Bool sceGmoPartLoadCache( SceGmoPart *part, int flags ) ;
void sceGmoPartUnloadCache( SceGmoPart *part, int flags ) ;
void sceGmoPartDraw( SceGmoPart *part, SceGmoModel *model, SceGmoBone *bone, int flags ) ;
void sceGmoPartSetParent( SceGmoPart *part, SceGmoModel *parent ) ;
SceGmoModel *sceGmoPartGetParent( SceGmoPart *part ) ;
int sceGmoPartGetMeshCount( SceGmoPart *part ) ;
int sceGmoPartGetArraysCount( SceGmoPart *part ) ;
SceGmoMesh *sceGmoPartGetMesh( SceGmoPart *part, int idx ) ;
SceGmoChunk *sceGmoPartGetArrays( SceGmoPart *part, int idx ) ;
SceGmoMesh *sceGmoMeshCreate( SceGmoChunk *chunk ) ;
void sceGmoMeshDelete( SceGmoMesh *mesh ) ;
SceGmoMesh *sceGmoMeshDuplicate( SceGmoMesh *mesh, int flags ) ;
_Bool sceGmoMeshLoad( SceGmoMesh *mesh, SceGmoChunk *chunk ) ;
void sceGmoMeshUnload( SceGmoMesh *mesh ) ;
_Bool sceGmoMeshLoadCache( SceGmoMesh *mesh, SceGmoPart *part, int flags ) ;
void sceGmoMeshUnloadCache( SceGmoMesh *mesh, int flags ) ;
void sceGmoMeshDraw( SceGmoMesh *mesh, SceGmoModel *model, SceGmoBone *bone, SceGmoPart *part, int flags ) ;
void sceGmoMeshDrawGeometry( SceGmoMesh *mesh, SceGmoPart *part ) ;
void sceGmoMeshSetMaterial( SceGmoMesh *mesh, int material ) ;
int sceGmoMeshGetMaterial( SceGmoMesh *mesh ) ;
void sceGmoMeshSetSubdivision( SceGmoMesh *mesh, const SceGmoVec2 *subdiv ) ;
const SceGmoVec2 *sceGmoMeshGetSubdivision( SceGmoMesh *mesh ) ;
int sceGmoMeshGetBlendSubsetCount( SceGmoMesh *mesh ) ;
const int *sceGmoMeshGetBlendSubset( SceGmoMesh *mesh ) ;
int sceGmoMeshGetBoundingPointsCount( SceGmoMesh *mesh ) ;
const SceGmoVec3F *sceGmoMeshGetBoundingPoints( SceGmoMesh *mesh ) ;
void sceGmoMeshSetEnableBits( SceGmoMesh *mesh, int bits, int value ) ;
int sceGmoMeshGetEnableBits( SceGmoMesh *mesh ) ;
void sceGmoMeshSetEnableMask( SceGmoMesh *mesh, int mask, int value ) ;
int sceGmoMeshGetEnableMask( SceGmoMesh *mesh ) ;
void sceGmoMeshSetMeshMask( SceGmoMesh *mesh, int mask, int value ) ;
int sceGmoMeshGetMeshMask( SceGmoMesh *mesh ) ;
void sceGmoMeshSetClippingHandler( void (*clip_func)( SceGmoMesh *mesh, SceGmoPart *part ) ) ;
SceGmoMaterial *sceGmoMaterialCreate( const SceGmoChunk *chunk ) ;
void sceGmoMaterialDelete( SceGmoMaterial *material ) ;
SceGmoMaterial *sceGmoMaterialDuplicate( SceGmoMaterial *material, int flags ) ;
_Bool sceGmoMaterialLoad( SceGmoMaterial *material, const SceGmoChunk *chunk ) ;
void sceGmoMaterialUnload( SceGmoMaterial *material ) ;
void sceGmoMaterialUpdate( SceGmoMaterial *material, SceGmoModel *model, int flags ) ;
int sceGmoMaterialActivate( SceGmoMaterial *material, SceGmoModel *model, int idx ) ;
void sceGmoMaterialControl( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoMaterialSetParent( SceGmoMaterial *material, SceGmoModel *parent ) ;
SceGmoModel *sceGmoMaterialGetParent( SceGmoMaterial *material ) ;
int sceGmoMaterialGetLayerCount( SceGmoMaterial *material ) ;
SceGmoLayer *sceGmoMaterialGetLayer( SceGmoMaterial *material, int idx ) ;
int sceGmoMaterialGetPassCount( SceGmoMaterial *material ) ;
SceGmoMaterial *sceGmoMaterialGetInitialState( SceGmoMaterial *material ) ;
void sceGmoMaterialSetDiffuse( SceGmoMaterial *material, SceGmoCol4 color ) ;
SceGmoCol4 sceGmoMaterialGetDiffuse( SceGmoMaterial *material ) ;
void sceGmoMaterialSetSpecular( SceGmoMaterial *material, SceGmoCol4 color, float shininess ) ;
SceGmoCol4 sceGmoMaterialGetSpecular( SceGmoMaterial *material ) ;
float sceGmoMaterialGetShininess( SceGmoMaterial *material ) ;
void sceGmoMaterialSetEmission( SceGmoMaterial *material, SceGmoCol4 color ) ;
SceGmoCol4 sceGmoMaterialGetEmission( SceGmoMaterial *material ) ;
void sceGmoMaterialSetAmbient( SceGmoMaterial *material, SceGmoCol4 color ) ;
SceGmoCol4 sceGmoMaterialGetAmbient( SceGmoMaterial *material ) ;
void sceGmoMaterialSetReflection( SceGmoMaterial *material, float reflection ) ;
float sceGmoMaterialGetReflection( SceGmoMaterial *material ) ;
void sceGmoMaterialSetRefraction( SceGmoMaterial *material, float refraction ) ;
float sceGmoMaterialGetRefraction( SceGmoMaterial *material ) ;
void sceGmoMaterialSetBump( SceGmoMaterial *material, float bump ) ;
float sceGmoMaterialGetBump( SceGmoMaterial *material ) ;
void sceGmoMaterialSetLayerTexCrop( SceGmoMaterial *material, int idx, const SceGmoRect *crop ) ;
const SceGmoRect *sceGmoMaterialGetLayerTexCrop( SceGmoMaterial *material, int idx ) ;
void sceGmoMaterialSetEnableBits( SceGmoMaterial *material, int bits, int value ) ;
int sceGmoMaterialGetEnableBits( SceGmoMaterial *material ) ;
void sceGmoMaterialSetEnableMask( SceGmoMaterial *material, int mask, int value ) ;
int sceGmoMaterialGetEnableMask( SceGmoMaterial *material ) ;
SceGmoLayer *sceGmoLayerCreate( const SceGmoChunk *chunk ) ;
void sceGmoLayerDelete( SceGmoLayer *layer ) ;
SceGmoLayer *sceGmoLayerDuplicate( SceGmoLayer *layer, int flags ) ;
_Bool sceGmoLayerLoad( SceGmoLayer *layer, const SceGmoChunk *chunk ) ;
void sceGmoLayerUnload( SceGmoLayer *layer ) ;
int sceGmoLayerActivate( SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material ) ;
void sceGmoLayerSetTexture( SceGmoLayer *layer, int texture ) ;
int sceGmoLayerGetTexture( SceGmoLayer *layer ) ;
void sceGmoLayerSetMapType( SceGmoLayer *layer, int type ) ;
int sceGmoLayerGetMapType( SceGmoLayer *layer ) ;
void sceGmoLayerSetMapFactor( SceGmoLayer *layer, float factor ) ;
float sceGmoLayerGetMapFactor( SceGmoLayer *layer ) ;
void sceGmoLayerSetBlendFunc( SceGmoLayer *layer, int mode, int src, int dst ) ;
const int *sceGmoLayerGetBlendFunc( SceGmoLayer *layer ) ;
void sceGmoLayerSetTexCrop( SceGmoLayer *layer, const SceGmoRect *crop ) ;
const SceGmoRect *sceGmoLayerGetTexCrop( SceGmoLayer *layer ) ;
void sceGmoLayerSetTexGen( SceGmoLayer *layer, int mode ) ;
int sceGmoLayerGetTexGen( SceGmoLayer *layer ) ;
void sceGmoLayerSetTexMatrix( SceGmoLayer *layer, const SceGmoMat4 *matrix ) ;
const SceGmoMat4 *sceGmoLayerGetTexMatrix( SceGmoLayer *layer ) ;
void sceGmoLayerSetEnableBits( SceGmoLayer *layer, int bits, int value ) ;
int sceGmoLayerGetEnableBits( SceGmoLayer *layer ) ;
void sceGmoLayerSetEnableMask( SceGmoLayer *layer, int mask, int value ) ;
int sceGmoLayerGetEnableMask( SceGmoLayer *layer ) ;
SceGmoTexture *sceGmoTextureCreate( const SceGmoChunk *chunk ) ;
void sceGmoTextureDelete( SceGmoTexture *texture ) ;
SceGmoTexture *sceGmoTextureDuplicate( SceGmoTexture *texture, int flags ) ;
_Bool sceGmoTextureLoad( SceGmoTexture *texture, const SceGmoChunk *chunk ) ;
void sceGmoTextureUnload( SceGmoTexture *texture ) ;
_Bool sceGmoTextureLoadCache( SceGmoTexture *texture, int flags ) ;
void sceGmoTextureUnloadCache( SceGmoTexture *texture, int flags ) ;
void sceGmoTextureAnimate( SceGmoTexture *texture, SceGmoModel *model, float step, int flags ) ;
void sceGmoTextureActivate( SceGmoTexture *texture, int type ) ;
void sceGmoTextureSetParent( SceGmoTexture *texture, SceGmoModel *parent ) ;
SceGmoModel *sceGmoTextureGetParent( SceGmoTexture *texture ) ;
void sceGmoTextureSetPicture( SceGmoTexture *texture, SceGimPicture *picture, int flags ) ;
SceGimPicture *sceGmoTextureGetPicture( SceGmoTexture *texture ) ;
_Bool sceGmoTextureHasAnimation( SceGmoTexture *texture ) ;
SceGmoMotion *sceGmoMotionCreate( const SceGmoChunk *chunk ) ;
void sceGmoMotionDelete( SceGmoMotion *motion ) ;
SceGmoMotion *sceGmoMotionDuplicate( SceGmoMotion *motion, int flags ) ;
_Bool sceGmoMotionLoad( SceGmoMotion *motion, const SceGmoChunk *chunk ) ;
void sceGmoMotionUnload( SceGmoMotion *motion ) ;
void sceGmoMotionAnimate( SceGmoMotion *motion, SceGmoModel *model, float step, int flags ) ;
void sceGmoMotionSetParent( SceGmoMotion *motion, SceGmoModel *parent ) ;
SceGmoModel *sceGmoMotionGetParent( SceGmoMotion *motion ) ;
int sceGmoMotionGetAnimationCount( SceGmoMotion *motion ) ;
int sceGmoMotionGetFCurveCount( SceGmoMotion *motion ) ;
SceGmoChunk *sceGmoMotionGetAnimation( SceGmoMotion *motion, int idx ) ;
SceGmoChunk *sceGmoMotionGetFCurve( SceGmoMotion *motion, int idx ) ;
void sceGmoMotionSetFrameLoop( SceGmoMotion *motion, float start, float end ) ;
const float *sceGmoMotionGetFrameLoop( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameRate( SceGmoMotion *motion, float fps ) ;
float sceGmoMotionGetFrameRate( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameRepeat( SceGmoMotion *motion, int mode ) ;
int sceGmoMotionGetFrameRepeat( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrame( SceGmoMotion *motion, float frame ) ;
float sceGmoMotionGetFrame( SceGmoMotion *motion ) ;
void sceGmoMotionSetWeight( SceGmoMotion *motion, float weight ) ;
float sceGmoMotionGetWeight( SceGmoMotion *motion ) ;
void sceGmoModelInitDevice( void *device, int flags ) ;
void sceGmoModelTermDevice( void ) ;
extern const SceGmoVec2 sceGmoVec2_One ;
extern const SceGmoVec3 sceGmoVec3_One ;
extern const SceGmoVec4 sceGmoVec4_One ;
extern const SceGmoMat4 sceGmoMat4_One ;
extern const SceGmoQuat sceGmoQuat_One ;
extern const SceGmoRect sceGmoRect_One ;
extern const SceGmoCol4 sceGmoCol4_One ;
SceGmoVec2 *sceGmoVec2Set( SceGmoVec2 *dst, float x, float y ) ;
