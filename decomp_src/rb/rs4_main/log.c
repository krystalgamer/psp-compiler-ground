/* SDK libfpu log.o (1.9.2.internal -O4 (= -O3) -mext): the SDK 6.6.0 src/fpu/log.c, preprocessed with the SDK headers */
/* cflags: -O3 */
unsigned int sceFpuGetFCR31(void);
unsigned int sceFpuSetFCR31(unsigned int fcr);
float sceFpuAbs(float fs);
int sceFpuCeil(float fs);
int sceFpuFloor(float fs);
float sceFpuMax(float fs1, float fs2);
float sceFpuMin(float fs1, float fs2);
float sceFpuNeg(float fs);
int sceFpuRound(float fs);
float sceFpuRsqrt(float fs);
float sceFpuSqrt(float fs);
int sceFpuTrunc(float fs);
float sceFpuFmod(float fs, float fd);
float sceFpuFrac(float fs);
float sceFpuReinterpretFloat(unsigned int ui);
unsigned int sceFpuReinterpretUint(float fs);
int sceFpuIsEqual(float fs1, float fs2);
float sceFpuSignFloat(float fs);
int sceFpuSignInt(float fs);
float sceFpuPositiveZero(void);
float sceFpuNegativeZero(void);
int sceFpuIsZero(float f);
int sceFpuIsPositiveZero(float f);
int sceFpuIsNegativeZero(float f);
int sceFpuIsDenormal(float f);
int sceFpuIsZeroOrDenormal(float f);
float sceFpuPositiveInf(void);
float sceFpuNegativeInf(void);
int sceFpuIsInf(float f);
float sceFpuPositiveNaN(void);
float sceFpuNegativeNaN(void);
float sceFpuPositiveQNaN(void);
float sceFpuNegativeQNaN(void);
float sceFpuPositiveSNaN(unsigned int uiSignal);
float sceFpuNegativeSNaN(unsigned int uiSignal);
int sceFpuIsNaN(float f);
int sceFpuIsInfOrNaN(float f);
float sceFpuNormalizePhase(float fs);
float sceFpuSin(float x);
float sceFpuCos(float x);
float sceFpuTan(float x);
float sceFpuAtan(float x);
float sceFpuAtan2(float y, float x);
float sceFpuAsin(float x);
float sceFpuAcos(float x);
float sceFpuLog(float x);
float sceFpuLog2(float fs);
float sceFpuLog10(float fs);
float sceFpuExp(float x);
float sceFpuExp2(float x);
float sceFpuExp10(float x);
float sceFpuPow(float x, float y);
double sceFpuFloatToDouble(float a);
float sceFpuDoubleToFloat(double a);
float sceFpuLog(float x)
{
 union {
  float f;
  int i;
 } fi;
 int a, b, exponent;
 float y, z;
 fi.f = x;
 if (fi.i <= 0) {
  if ((fi.i & 0x7fffffff) == 0) {
   fi.i = 0xff800000;
   return fi.f;
  }
  fi.i = 0xff80ffff;
  return fi.f;
 }
 b = (fi.i & 0x007fffff);
 a = b - (1<<23);
 exponent = fi.i;
 if (b <= 0x3504F3) {
  a = b;
  b = b - (1 << 23);
  exponent -= (1<<23);
 }
 b = b - (1 << 23) + (1<<25);
 x = (float)(a) / (float)(b);
 z = (((exponent>>23)-126) * 0xB17218) * (float)(1.0/(1<<24));
 y = x * x;
 return z + x * ((((float)(13890687.0 / (1024.0 * 1024.0 * 32.0)) * y
       + (float) (5590817.0 / (1024.0 * 1024.0 * 8.0))) * y)
     + (float) (4194305.0 / (1024.0 * 1024.0 * 2.0)));
}
float sceFpuLog2(float x)
{
 union {
  float f;
  int i;
 } fi;
 int a, b, exponent;
 float y, z;
 fi.f = x;
 if (fi.i <= 0) {
  if ((fi.i & 0x7fffffff) == 0) {
   fi.i = 0xff800000;
   return fi.f;
  }
  fi.i = 0xff80ffff;
  return fi.f;
 }
 b = (fi.i & 0x007fffff);
 a = b - (1<<23);
 exponent = fi.i;
 if (b <= 0x3504F3) {
  a = b;
  b = b - (1 << 23);
  exponent -= (1<<23);
 }
 b = b - (1 << 23) + (1<<25);
 x = (float)(a) / (float)(b);
 z = ((exponent>>23)-126);
 y = x * x;
 return z + x * ((((float)(20040025.0 / (1024.0 * 1024.0 * 32.0)) * y
       + (float)( 8065844.0 / (1024.0 * 1024.0 * 8.0))) * y)
     + (float)( 6051103.0 / (1024.0 * 1024.0 * 2.0)));
}
float sceFpuLog10(float x)
{
 union {
  float f;
  int i;
 } fi;
 int a, b, exponent;
 float y, z;
 fi.f = x;
 if (fi.i <= 0) {
  if ((fi.i & 0x7fffffff) == 0) {
   fi.i = 0xff800000;
   return fi.f;
  }
  fi.i = 0xff80ffff;
  return fi.f;
 }
 b = (fi.i & 0x007fffff);
 a = b - (1<<23);
 exponent = fi.i;
 if (b <= 0x3504F3) {
  a = b;
  b = b - (1 << 23);
  exponent -= (1<<23);
 }
 b = b - (1 << 23) + (1<<25);
 x = (float)(a) / (float)(b);
 z = (((exponent>>23)-126) * 0x4D104D) * (float)(1.0/(1<<24));
 y = x * x;
 return z + x * ((((float)(6032648.7 / (1024.0 * 1024.0 * 32.0)) * y
       + (float)(2428061.0 / (1024.0 * 1024.0 * 8.0))) * y)
     + (float)(1821563.5 / (1024.0 * 1024.0 * 2.0)));
}
