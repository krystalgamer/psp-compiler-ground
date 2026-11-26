/* What psp-gcc's g++ driver and cc1plus predefine for C++ (cc1plus -dM -E,
   the specs' -D__GNUC__/__GNUC_MINOR__/__GNUC_PATCHLEVEL__, and -O):
   C++ units are preprocessed separately by the host cpp with -undef. */
#undef __GNUC_MINOR__
#define __GNUC_MINOR__ 3
#define __GNUC_PATCHLEVEL__ 3
#define __GNUG__ 3
#define __GXX_ABI_VERSION 102
#define __GXX_WEAK__ 1
#define __EXCEPTIONS 1
#define __DEPRECATED 1
#define __OPTIMIZE__ 1
#define __CHAR_BIT__ 8
#define __SCHAR_MAX__ 127
#define __SHRT_MAX__ 32767
#define __INT_MAX__ 2147483647
#define __LONG_MAX__ 2147483647L
#define __LONG_LONG_MAX__ 9223372036854775807LL
#define __WCHAR_MAX__ 2147483647
#define __SIZE_TYPE__ unsigned int
#define __PTRDIFF_TYPE__ int
#define __WCHAR_TYPE__ int
#define __WINT_TYPE__ unsigned int
#define __USER_LABEL_PREFIX__
#define __REGISTER_PREFIX__
#define __FLT_RADIX__ 2
#define __FLT_MANT_DIG__ 24
#define __FLT_DIG__ 6
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX_10_EXP__ 38
#define __FLT_MAX__ 3.40282347e+38F
#define __FLT_MIN__ 1.17549435e-38F
#define __FLT_EPSILON__ 1.19209290e-7F
#define __FLT_DENORM_MIN__ 1.40129846e-45F
#define __FLT_EVAL_METHOD__ 0
#define __DBL_MANT_DIG__ 53
#define __DBL_DIG__ 15
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX_10_EXP__ 308
#define __DBL_MAX__ 1.7976931348623157e+308
#define __DBL_MIN__ 2.2250738585072014e-308
#define __DBL_EPSILON__ 2.2204460492503131e-16
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
#define __LDBL_MANT_DIG__ 53
#define __LDBL_DIG__ 15
#define __LDBL_MIN_EXP__ (-1021)
#define __LDBL_MIN_10_EXP__ (-307)
#define __LDBL_MAX_EXP__ 1024
#define __LDBL_MAX_10_EXP__ 308
#define __LDBL_MAX__ 1.7976931348623157e+308L
#define __LDBL_MIN__ 2.2250738585072014e-308L
#define __LDBL_EPSILON__ 2.2204460492503131e-16L
#define __LDBL_DENORM_MIN__ 4.9406564584124654e-324L
#define __DECIMAL_DIG__ 17
#define __FINITE_MATH_ONLY__ 0
#define __LANGUAGE_C_PLUS_PLUS 1
#define __LANGUAGE_C_PLUS_PLUS__ 1
#define _LANGUAGE_C_PLUS_PLUS 1
#undef _LANGUAGE_C
#define __mips 2
#define _mips 1
#define mips 1
#define __mips_eabi 1
#define __mips_fpr 32
#define __mips_hard_float 1
#define __mips_single_float 1
#define __MIPSEL 1
#define __MIPSEL__ 1
#define _MIPSEL 1
#define MIPSEL 1
#define __R3000 1
#define __R3000__ 1
#define _R3000 1
#define R3000 1
#define _MIPS_ARCH "allegrex"
#define _MIPS_ARCH_ALLEGREX 1
#define _MIPS_TUNE "allegrex"
#define _MIPS_TUNE_ALLEGREX 1
#define _MIPS_ISA _MIPS_ISA_MIPS2
