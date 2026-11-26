/* SDK libfpu exp.o (1.9.2.internal -O4 (= -O3) -mext): the SDK 6.6.0 src/fpu/exp.c, preprocessed with the SDK headers */
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
float sceFpuExp(float x)
{
 union {
  float f;
  int i;
 } fi;
 float z, f;
 fi.f = x;
 fi.i &= 0x7fffffff;
 if (fi.i >= 0x42b00f34) {
  if (x != x) {
   return x;
  }
  if (x < 0.0f) {
   return 0.0f;
  }
  fi.i = 0x7f800000;
  return fi.f;
 }
 f = fi.f * (float)1.4426950408889634074;
 z = __builtin_allegrex_round_w_s(f);
 f = f-z;
 fi.i = z;
 if (x < 0) {
  fi.i = -fi.i;
  f = -f;
 }
 fi.i = (fi.i+127) << 23;
 f = (6.0f + (float)(4.0*0.69314718055994530942 * 0.25)*f
      + (float)(0.9996*0.69314718055994530942*0.25*0.69314718055994530942*0.25)*f*f)
     / (6.0f - (float)(2.0*0.69314718055994530942 * 0.25)*f);
 f *= f;
 fi.f *= f*f;
 return fi.f;
}
float sceFpuExp2(float x)
{
 return sceFpuPow(2.0f, x);
}
float sceFpuExp10(float x)
{
 return sceFpuPow(10.0f, x);
}
float sceFpuPow(float x, float y)
{
 float p;
 float ax;
 if (y==0.0f) {
  return 1.0f;
 }
 if (x==0.0f) {
  return 0.0f;
 }
 p = ax = __builtin_fabsf(x);
 if (ax!=1.0f) {
  p = sceFpuExp(y * sceFpuLog(ax));
 }
 if (x < 0) {
  if (__builtin_allegrex_ceil_w_s(y)==__builtin_allegrex_floor_w_s(y)) {
   if (((int)y) & 1) {
    p = -p;
   }
  } else {
   union {
    float f;
    int i;
   } fi;
   fi.i = 0xff80ffff;
   return fi.f;
  }
 }
 return p;
}
