#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
int sceKernelDcacheWritebackAll(void);

typedef struct ScePspFVector3 { float x, y, z; } ScePspFVector3;
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )

void DrawPole(ScePspFVector3 *array,float r)
{
	ScePspFVector3	scal;
	ScePspFVector3	pole[28] = {
	{ 1.000000f,	 3.000000f,	 0.000000f, },
	{ 1.003333f,	 3.000000f,	 1.300000f, },
	{-1.003333f,	 3.000000f,	 1.300000f, },
	{-1.000000f,	 3.000000f,	 0.000000f, },
	{-1.003333f,	 3.000000f,	-1.300000f, },
	{ 1.003333f,	 3.000000f,	-1.300000f, },
	{ 1.000000f,	 3.000000f,	 0.000000f, },
	{ 1.000000f,	 1.000000f,	 0.000000f, },
	{ 1.003333f,	 1.000000f,	 1.300000f, },
	{-1.003333f,	 1.000000f,	 1.300000f, },
	{-1.000000f,	 1.000000f,	 0.000000f, },
	{-1.003333f,	 1.000000f,	-1.300000f, },
	{ 1.003333f,	 1.000000f,	-1.300000f, },
	{ 1.000000f,	 1.000000f,	 0.000000f, },
	{ 1.000000f,	-1.000000f,	 0.000000f, },
	{ 1.003333f,	-1.000000f,	 1.300000f, },
	{-1.003333f,	-1.000000f,	 1.300000f, },
	{-1.000000f,	-1.000000f,	 0.000000f, },
	{-1.003333f,	-1.000000f,	-1.300000f, },
	{ 1.003333f,	-1.000000f,	-1.300000f, },
	{ 1.000000f,	-1.000000f,	 0.000000f, },
	{ 1.000000f,	-3.000000f,	 0.000000f, },
	{ 1.003333f,	-3.000000f,	 1.300000f, },
	{-1.003333f,	-3.000000f,	 1.300000f, },
	{-1.000000f,	-3.000000f,	 0.000000f, },
	{-1.003333f,	-3.000000f,	-1.300000f, },
	{ 1.003333f,	-3.000000f,	-1.300000f, },
	{ 1.000000f,	-3.000000f,	 0.000000f, },
	};
	int	i;

	for(i=0;i<(int)(sizeof(pole)/sizeof(ScePspFVector3));i++) {
		array[i].x=pole[i].x;
		array[i].y=pole[i].y;
		array[i].z=pole[i].z;
	}
	sceKernelDcacheWritebackAll();

	sceGumPushMatrix();
	scal.x=scal.y=scal.z=r;
	sceGumScale(&scal);

	sceGumDrawBezier(SCEGU_VERTEX_FLOAT, 7, 4, 0, array);

	sceGumPopMatrix();
}

