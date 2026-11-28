/* SDK libsha1.o (1.9.2.internal -O4 (= -O3) -mext): the SDK 6.6.0 src/sha1/libsha1.c, preprocessed with the SDK headers; this revision byte-swaps 8 words of h[] in sceSha1BlockResult (6.6.0: 5) */
/* cflags: -O3 */
#include "common.h"
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
typedef struct SceSha1Context {
 unsigned int h[5];
 unsigned short usRemains;
 unsigned short usComputed;
 __extension__ unsigned long long ulTotalLen;
 unsigned char buf[64];
} SceSha1Context;
int sceSha1Digest(const void *plain, unsigned int len, unsigned char *digest);
int sceSha1BlockInit(SceSha1Context *pContext);
int sceSha1BlockUpdate(SceSha1Context *pContext, const void *plain, unsigned int len);
int sceSha1BlockResult(SceSha1Context *pContext, unsigned char *digest);
extern void _sceSha1Core(unsigned int *blk, unsigned int *h);
static __inline__ void _sceSha1SwapEndian(unsigned int *dst, const unsigned int *src, unsigned int len);
static __inline__ void _sceSha1Memcpy(void *pDst, const void *pSrc, unsigned int uiSize);
static __inline__ void _sceSha1SwapEndian(unsigned int *dst, const unsigned int *src, unsigned int len)
{
 unsigned int i;
 for (i=0; i<len; i++) {
  dst[i] = __builtin_allegrex_wsbw(src[i]);
 }
 return;
}
static __inline__ void _sceSha1Memcpy(void *pDst, const void *pSrc, unsigned int uiSize)
{
 unsigned char *pd = (unsigned char *)pDst;
 const unsigned char *ps = (const unsigned char *)pSrc;
 unsigned int i;
 for (i=0; i<uiSize; i++) {
  *pd++ = *ps++;
 }
 return;
}
int sceSha1BlockInit(SceSha1Context *pContext)
{
 if (!pContext) {
  return (0x80000103);
 }
 pContext->h[0] = 0x67452301U;
 pContext->h[1] = 0xEFCDAB89U;
 pContext->h[2] = 0x98BADCFEU;
 pContext->h[3] = 0x10325476U;
 pContext->h[4] = 0xC3D2E1F0U;
 pContext->usRemains = 0;
 pContext->usComputed = 0;
 pContext->ulTotalLen = 0;
 return (0);
}
int sceSha1BlockUpdate(SceSha1Context *pContext, const void *plain, unsigned int uiLen)
{
 union {
  unsigned char b[64];
  unsigned int ui[64 / 4];
 } blk;
 unsigned int n;
 if (!pContext || !plain) {
  return (0x80000103);
 } else if (pContext->usComputed!=0) {
  return (0x80000021);
 }
 pContext->ulTotalLen += uiLen;
 n = pContext->usRemains + uiLen;
 while (n >= 64) {
  if (pContext->usRemains > 0) {
   unsigned int cont = 64 - pContext->usRemains;
   _sceSha1Memcpy(blk.b, pContext->buf, pContext->usRemains);
   _sceSha1Memcpy(&blk.b[pContext->usRemains], plain, cont);
   pContext->usRemains = 0;
   plain = (const unsigned char *)plain + cont;
  } else {
   _sceSha1Memcpy(blk.b, plain, 64);
   plain = (const unsigned char *)plain + 64;
  }
  _sceSha1SwapEndian(blk.ui, blk.ui, (64 / 4));
  _sceSha1Core(blk.ui, pContext->h);
  n -= 64;
 }
 if (n > 0) {
  _sceSha1Memcpy(&pContext->buf[pContext->usRemains], plain, (n - pContext->usRemains));
 }
 pContext->usRemains = n;
 return (0);
}
int sceSha1BlockResult(SceSha1Context *pContext, unsigned char *digest)
{
 if (!pContext || !digest) {
  return (0x80000103);
 }
 if (pContext->usComputed==0) {
  union {
   unsigned char b[64];
   unsigned int ui[64 / 4];
  } blk;
  unsigned int n;
  int i;
  n = pContext->usRemains;
  for (i=0; i<(64 / 4); i++) {
   blk.ui[i] = 0;
  }
  _sceSha1Memcpy(blk.b, pContext->buf, n);
  blk.b[n] = 0x80;
  if (n >= (64 - 8)) {
   _sceSha1SwapEndian(blk.ui, blk.ui, (64 / 4));
   _sceSha1Core(blk.ui, pContext->h);
   for (i=0; i<(64 / 4); i++) {
    blk.ui[i] = 0;
   }
  }
  for (i=0; i<8; i++) {
   blk.b[56 + i] = (pContext->ulTotalLen<<3) >> ((7 - i)*8);
  }
  _sceSha1SwapEndian(blk.ui, blk.ui, (64 / 4));
  _sceSha1Core(blk.ui, pContext->h);
  _sceSha1SwapEndian(pContext->h, pContext->h, 8);
  pContext->usComputed = 1;
  for (i=0; i<64; i++) {
   pContext->buf[i] = 0;
  }
 }
 _sceSha1Memcpy(digest, pContext->h, 20);
 return (0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/libsha1", __psp_libinfo___10C138);
