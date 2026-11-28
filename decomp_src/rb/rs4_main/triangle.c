/* cflags: -O3 -fno-merge-constants */
#include "common.h"
/* SDK libfpu triangle.o (1.9.2.internal -O4 -mext), an older revision than SDK 6.6.0's src/fpu/triangle.c:
   NaN check, sign as +-1 multiplied in, its own polynomial constants; no sceFpuAtan2/sceFpuTan */
float sceFpuAtan(float x);

const float triPoly[] = {
	(float)(2.0*3.14159265358979323846),
	(float)(1.0),
	(float)(-0xAAAA98/(1024.0*1024*64)),
	(float)( 0x88801C/(1024.0*1024*1024)),
	(float)(-0xCB9F27/(1024.0*1024*1024*64)),
	(float)(-0xFFFFF9/(1024.0*1024*32)),
	(float)( 0xAAA6FB/(1024.0*1024*256)),
	(float)(-0xB3D431/(1024.0*1024*1024*8)),
	(float)(-0xAAAAAA/(1024.0*1024*32)),
	(float)( 0xCCCCCD/(1024.0*1024*64)),
	(float)(-0x8F5C29/(1024.0*1024*64)),
};


static float _sceFpuSinMain(float x)
{
	float y = x * x;
	return ((-0.0001941887749f * y + 0.008331324905f) * y + -0.1666663885f) * y * x + x;
}

static float _sceFpuCosMain(float x)
{
	float y = x * x;
	return ((-0.001371985418f * y + 0.04166315123f) * y + -0.4999997914f) * y + 1.0f;
}

static float _sceFpuAtanMain(float x)
{
	float y = x * x;
	return x * (((-0.14f * y + 0.2f) * y + -0.3333333135f) * y + 1.0f);
}

static float _atanf(float x)
{
	if (x < 0.1989f)
		return _sceFpuAtanMain(x);
	if (x < 0.6681060195f)
		return 0.3926990926f + _sceFpuAtanMain((x - 0.414213568f) / (x * 0.414213568f + 1.0f));
	return 0.7853981853f + _sceFpuAtanMain((x - 1.0f) / (x + 1.0f));
}

float sceFpuSin(float x)
{
	float pi2, y;
	int sign = 1;

	if (x != x) return x;
	pi2 = 6.283185482f;
	if (x < 0.0f) {
		x = -x;
		sign = -1;
	}
	if (x > pi2) {
		x -= (float)(int)(x / pi2) * pi2;
	}
	pi2 *= 0.5f;
	if (x > pi2) {
		x -= pi2;
		sign = -sign;
	}
	if (x > pi2 * 0.5f) x = pi2 - x;
	if (x > 0.917345047f)
		return _sceFpuCosMain(pi2 * 0.5f - x) * (float)sign;
	return _sceFpuSinMain(x) * (float)sign;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/triangle", sceFpuCos);

float sceFpuAtan(float x)
{
	int sign = 1;

	if (x != x) return x;
	if (x < 0.0f) {
		x = -x;
		sign = -1;
	}
	if (x >= 1.0f) {
		x = 1.0f / x;
		x = 1.570796371f - _atanf(x);
	} else {
		x = _atanf(x);
	}
	return x * (float)sign;
}

float sceFpuAsin(float x)
{
	float y = x * x;
	return sceFpuAtan(__builtin_allegrex_sqrt_s(y / (1.0f - y)));
}

float sceFpuAcos(float x)
{
	float y = x * x;
	return sceFpuAtan(__builtin_allegrex_sqrt_s((1.0f - y) / y));
}
