/* SDK libfpu fpu.o (1.9.2.internal -O4 -mext): the SDK 6.6.0 src/fpu/fpu.c, preprocessed with the SDK headers.  Built -O2 -frename-registers (what -O4 does here, nothing gets inlined) so that the functions are output in order before the constants below */
/* cflags: -O2 -frename-registers */
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
static const unsigned char __psp_libinfo__[24] __attribute__((used)) = { 0x5C, 0x79, 0x72, 0x3D, 0x60, 0x63, 0x60, 0x30, 0x7E, 0x7B, 0x74, 0x78, 0x82, 0x87, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x46, 0x4B, 0x45, 0x44 };
unsigned int sceFpuGetFCR31(void)
{
 unsigned int fcr;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "cfc1			%0, $31\n"
  ".set			pop\n"
  : "=r"(fcr)
 );
 return (fcr);
}
unsigned int sceFpuSetFCR31(unsigned int newfcr)
{
 unsigned int oldfcr;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "cfc1			%0, $31\n"
  "ctc1			$0, $31\n"
  "nop\n"
  "ctc1			%1, $31\n"
  ".set			pop\n"
  : "=&r"(oldfcr)
  : "r"(newfcr)
 );
 return (oldfcr);
}
float sceFpuAbs(float fs)
{
 register float fd;
 __asm__ (
  "abs.s			%0, %1\n"
  : "=f"(fd)
  : "f"(fs)
 );
 return (fd);
}
int sceFpuCeil(float fs)
{
 return (__builtin_allegrex_ceil_w_s(fs));
}
int sceFpuFloor(float fs)
{
 return (__builtin_allegrex_floor_w_s(fs));
}
float sceFpuMax(float fs1, float fs2)
{
 register float fd;
 fd = (fs1 > fs2) ? fs1 : fs2;
 return (fd);
}
float sceFpuMin(float fs1, float fs2)
{
 register float fd;
 fd = (fs1 < fs2) ? fs1 : fs2;
 return (fd);
}
float sceFpuNeg(float fs)
{
 register float fd;
 __asm__ (
  "neg.s			%0, %1\n"
  : "=f"(fd)
  : "f"(fs)
 );
 return (fd);
}
int sceFpuRound(float fs)
{
 return (__builtin_allegrex_round_w_s(fs));
}
float sceFpuRsqrt(float fs)
{
 return (1.0f / __builtin_allegrex_sqrt_s(fs));
}
float sceFpuSqrt(float fs)
{
 return (__builtin_allegrex_sqrt_s(fs));
}
int sceFpuTrunc(float fs)
{
 return (__builtin_allegrex_trunc_w_s(fs));
}
float sceFpuFmod(float fs, float fd)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "div.s			%0, %1, %2\n"
  "trunc.w.s		%0, %0\n"
  "cvt.s.w		%0, %0\n"
  "mul.s			%0, %0, %2\n"
  "sub.s			%0, %1, %0\n"
  ".set			pop\n"
  : "=&f"(v)
  : "f"(fs), "f"(fd)
 );
 return (v);
}
float sceFpuFrac(float fs)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "trunc.w.s		%0, %1\n"
  "cvt.s.w		%0, %0\n"
  "sub.s			%0, %1, %0\n"
  ".set			pop\n"
  : "=&f"(v)
  : "f"(fs)
 );
 return (v);
}
float sceFpuReinterpretFloat(unsigned int ui)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mtc1			%1, %0\n"
  ".set			pop\n"
  : "=f"(v)
  : "r"(ui)
 );
 return (v);
}
unsigned int sceFpuReinterpretUint(float fs)
{
 unsigned int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			%0, %1\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
 );
 return (v);
}
int sceFpuIsEqual(float fs1, float fs2)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "c.eq.s			%2, %1\n"
  "move			%0, $0\n"
  "bc1tl			0f\n"
  "addiu			%0, $0, 1\n"
 "0:\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs1), "f"(fs2)
 );
 return (v);
}
float sceFpuSignFloat(float fs)
{
 float fv;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			$8,  %1\n"
  "lui			$10, 0x3F80\n"
  "srl			$9,  $8,  23\n"
  "srl			$8,  $8,  31\n"
  "andi			$9,  $9,  0x00FF\n"
  "sll			$8,  $8,  31\n"
  "movz			$10, $0,  $9\n"
  "or				$10, $10, $8\n"
  "mtc1			$10, %0\n"
  ".set			pop\n"
  : "=f"(fv)
  : "f"(fs)
  : "$8", "$9", "$10"
 );
 return (fv);
}
int sceFpuSignInt(float fs)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			%0, %1\n"
  "lui			$8, 0x7F80\n"
  "and			$8, $8, %0\n"
  "sra			%0, %0, 30\n"
  "or				%0, %0, 1\n"
  "movz			%0, $0, $8\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(fs)
  : "$8"
 );
 return (v);
}
float sceFpuPositiveZero(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mtc1			$0, %0\n"
  ".set			pop\n"
  : "=f"(v)
 );
 return (v);
}
float sceFpuNegativeZero(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0x8000\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
  :
  : "$8"
 );
 return (v);
}
int sceFpuIsZero(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			$8, %1\n"
  "sra			%0, $8, 30\n"
  "sll			$8, $8, 1\n"
  "ori			%0, %0, 0x0001\n"
  "movn			%0, $0, $8\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8"
 );
 return (v);
}
int sceFpuIsPositiveZero(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			%0, %1\n"
  "sltiu			%0, %0, 1\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
 );
 return (v);
}
int sceFpuIsNegativeZero(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			%0, %1\n"
  "lui			$8, 0x8000\n"
  "xor			%0, %0, $8\n"
  "sltiu			%0, %0, 1\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8"
 );
 return (v);
}
int sceFpuIsDenormal(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			$8, %1\n"
  "lui			$9, 0x7F80\n"
  "or				%0, $8, $9\n"
  "and			$9, $8, $9\n"
  "sra			%0, %0, 30\n"
  "sll			$8, $8, 9\n"
  "movn			%0, $0, $9\n"
  "movz			%0, $0, $8\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8", "$9"
 );
 return (v);
}
int sceFpuIsZeroOrDenormal(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			$8, %1\n"
  "lui			$9, 0x7F80\n"
  "or				%0, $8, $9\n"
  "and			$9, $8, $9\n"
  "sra			%0, %0, 30\n"
  "movn			%0, $0, $9\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8", "$9"
 );
 return (v);
}
float sceFpuPositiveInf(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0x7F80\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
  :
  : "$8"
 );
 return (v);
}
float sceFpuNegativeInf(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0xFF80\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
 );
 return (v);
}
int sceFpuIsInf(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			$8, %1\n"
  "sll			$9, $8, 1\n"
  "sra			%0, $8, 30\n"
  "srl			$9, $9, 24\n"
  "sll			$8, $8, 9\n"
  "ori			%0, %0, 0x0001\n"
  "sltiu			$9, $9, 0x00FF\n"
  "movn			%0, $0, $8\n"
  "movn			%0, $0, $9\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8", "$9"
 );
 return (v);
}
float sceFpuPositiveNaN(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0x7F80\n"
  "ori			$8, $8, 0x0001\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
  :
  : "$8"
 );
 return (v);
}
float sceFpuNegativeNaN(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0xFF80\n"
  "ori			$8, $8, 0x0001\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
  :
  : "$8"
 );
 return (v);
}
float sceFpuPositiveQNaN(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0x7FC0\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
  :
  : "$8"
 );
 return (v);
}
float sceFpuNegativeQNaN(void)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			$8, 0xFFC0\n"
  "mtc1			$8, %0\n"
  ".set			pop\n"
  : "=f"(v)
  :
  : "$8"
 );
 return (v);
}
float sceFpuPositiveSNaN(unsigned int uiSignal)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "addiu			$9, $0, 1\n"
  "ext			$8, %1, 0, 22\n"
  "movn			$9, $8, $8\n"
  "lui			$8, 0x7F80\n"
  "or				$9, $9, $8\n"
  "mtc1			$9, %0\n"
  ".set			pop\n"
  : "=f"(v)
  : "r"(uiSignal)
  : "$8", "$9"
 );
 return (v);
}
float sceFpuNegativeSNaN(unsigned int uiSignal)
{
 float v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "addiu			$9, $0, 1\n"
  "ext			$8, %1, 0, 22\n"
  "movn			$9, $8, $8\n"
  "lui			$8, 0xFF80\n"
  "or				$9, $9, $8\n"
  "mtc1			$9, %0\n"
  ".set			pop\n"
  : "=f"(v)
  : "r"(uiSignal)
  : "$8", "$9"
 );
 return (v);
}
int sceFpuIsNaN(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "lui			%0, 0x807F\n"
  "mfc1			$8, %1\n"
  "ori			%0, %0, 0xFFFF\n"
  "sll			$9, $8, 1\n"
  "and			%0, %0, $8\n"
  "srl			$9, $9, 24\n"
  "sll			$8, $8, 9\n"
  "sltiu			$9, $9, 0x00FF\n"
  "movz			%0, $0, $8\n"
  "movn			%0, $0, $9\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8", "$9"
 );
 return (v);
}
int sceFpuIsInfOrNaN(float f)
{
 int v;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "mfc1			%0, %1\n"
  "sll			$8, %0, 1\n"
  "sra			%0, %0, 30\n"
  "srl			$8, $8, 24\n"
  "ori			%0, %0, 0x0001\n"
  "sltiu			$8, $8, 0x00FF\n"
  "movn			%0, $0, $8\n"
  ".set			pop\n"
  : "=r"(v)
  : "f"(f)
  : "$8"
 );
 return (v);
}
float sceFpuNormalizePhase(float fs)
{
 const float f2pi = (3.14159265358979323846 * 2.0);
 float fd;
 __asm__ (
  ".set			push\n"
  ".set			noreorder\n"
  "div.s			$f0, %1, %2\n"
  "round.w.s		$f0, $f0\n"
  "cvt.s.w		$f0, $f0\n"
  "mul.s			$f0, $f0, %2\n"
  "sub.s			%0,  %1,  $f0\n"
  ".set			pop\n"
  : "=&f"(fd)
  : "f"(fs), "f"(f2pi)
  : "$f0"
 );
 return (fd);
}

/* nine constants of the module's libfpu that no function here uses (an older
   fpu.c's), after the ones the functions load */
__asm__(".section .rodata.cst4,\"aM\",@progbits,4\n"
	"\t.word 0x40000002, 0x3F2A9E42, 0x3ED3F47F, 0x4038AA3E, 0x3F762668\n"
	"\t.word 0x3F18E4AC, 0x3F5E5BDC, 0x3E943274, 0x3E381A11\n"
	"\t.previous");
