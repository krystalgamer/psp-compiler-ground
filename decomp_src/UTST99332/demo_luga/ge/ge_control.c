/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char uchar;
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0x20 */
    int flag;
    int mode;
    int num_module;
    int exitflag;
    int pad_margin;
    u_int32 cont;
    u_int32 vcount;
    u_int32 rand_data;
};
typedef struct _anon1 gePROGRAM;

extern gePROGRAM *pProg;

float geAnalogDegree(int mode, uchar ax, uchar ay);
void geSetAnalogMargin(int m);


/* SDK prototypes (tools/sdk_protos.h) */
float sqrtf(float x);

float acosf(float x);
float geAnalogDegree(int mode, uchar ax, uchar ay)
{
	float x, y, deg, r;

	if (ax == 0x7f && ay == 0x7f)
		return -1.0f;
	x = ax - 127;
	y = 127 - ay;
	deg = acosf(x / sqrtf(x * x + y * y));
	deg = deg * 180.0f / 3.141592741f;
	if (y < 0.0f)
		deg = 360.0f - deg;
	switch (mode) {
	case 0:
		break;
	case 1:
		deg -= 90.0f;
		if (deg < 0.0f)
			deg += 360.0f;
		break;
	case 2:
		deg -= 180.0f;
		if (deg < 0.0f)
			deg += 360.0f;
		break;
	case 3:
		r = deg + 90.0f;
		if (r > 360.0f)
			r -= 360.0f;
		deg = r;
		break;
	}
	return deg;
}

void geSetAnalogMargin(int m) {
    pProg->pad_margin = m;
}
