#include "common.h"

float cosf(float x);
int sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);

void DrawTorus(float *arry, float inner, float outer)
{
	int i;
	int cnt;
	float dist;
	static const float table[14] = {
		-1.0f, 0.0f, -1.0f, 1.3333333f, 1.0f, 1.3333333f, 1.0f,
		0.0f, 1.0f, -1.3333333f, -1.0f, -1.3333333f, -1.0f, 0.0f,
	};

	cnt = 0;
	for (i = 0; i < 7; i++) {
		float r;

		r = outer + inner * cosf(0.0f);
		dist = inner * 1.333333f;
		arry[cnt + 3] = table[i * 2] * r;
		arry[cnt + 0] = table[i * 2] * r;
		arry[cnt + 4] = table[i * 2 + 1] * r;
		arry[cnt + 1] = table[i * 2 + 1] * r;
		arry[cnt + 2] = 0.0f;
		arry[cnt + 5] = dist;
		r = outer + inner * cosf(3.14159265f);
		arry[cnt + 9] = table[i * 2] * r;
		arry[cnt + 6] = table[i * 2] * r;
		arry[cnt + 10] = table[i * 2 + 1] * r;
		arry[cnt + 7] = table[i * 2 + 1] * r;
		arry[cnt + 8] = dist;
		arry[cnt + 11] = 0.0f;
		arry[cnt + 12] = table[i * 2] * r;
		arry[cnt + 13] = table[i * 2 + 1] * r;
		arry[cnt + 14] = -dist;
		arry[cnt + 15] = arry[cnt + 3];
		arry[cnt + 16] = arry[cnt + 4];
		arry[cnt + 17] = -arry[cnt + 5];
		arry[cnt + 18] = arry[cnt + 0];
		arry[cnt + 19] = arry[cnt + 1];
		arry[cnt + 20] = arry[cnt + 2];
		cnt += 21;
	}
	sceKernelDcacheWritebackInvalidateRange(arry, 0x24c);
	sceGumDrawBezier(0x180, 7, 7, 0, arry);
}
