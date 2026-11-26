#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
int sceKernelDcacheWritebackAll(void);

typedef struct ScePspFVector3 { float x, y, z; } ScePspFVector3;
void sceGumScale(const ScePspFVector3 *v);
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )

void DrawSphere(ScePspFVector3 *array,float r)
{
	ScePspFVector3	scal;
	ScePspFVector3	sphere[28] = {
	{ 0.000000f,  1.000000f,  0.000000f, },
	{ 1.333333f,  1.000000f,  0.000000f, },
	{ 1.333333f, -1.000000f,  0.000000f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	{ 0.000000f,  1.000000f,  0.000000f, },
	{ 1.333333f,  1.000000f, -1.777777f, },
	{ 1.333333f, -1.000000f, -1.777777f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	{ 0.000000f,  1.000000f,  0.000000f, },
	{-1.333333f,  1.000000f, -1.777777f, },
	{-1.333333f, -1.000000f, -1.777777f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	{ 0.000000f,  1.000000f,  0.000000f, },
	{-1.333333f,  1.000000f,  0.000000f, },
	{-1.333333f, -1.000000f,  0.000000f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	{ 0.000000f,  1.000000f,  0.000000f, },
	{-1.333333f,  1.000000f,  1.777777f, },
	{-1.333333f, -1.000000f,  1.777777f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	{ 0.000000f,  1.000000f,  0.000000f, },
	{ 1.333333f,  1.000000f,  1.777777f, },
	{ 1.333333f, -1.000000f,  1.777777f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	{ 0.000000f,  1.000000f,  0.000000f, },
	{ 1.333333f,  1.000000f,  0.000000f, },
	{ 1.333333f, -1.000000f,  0.000000f, },
	{ 0.000000f, -1.000000f,  0.000000f, },
	};
	int	i;

	for(i=0;i<(int)(sizeof(sphere)/sizeof(ScePspFVector3));i++) {
		array[i].x=sphere[i].x;
		array[i].y=sphere[i].y;
		array[i].z=sphere[i].z;
	}
	sceKernelDcacheWritebackAll();

	sceGumPushMatrix();
	scal.x=scal.y=scal.z=r;
	sceGumScale(&scal);

	sceGumDrawBezier(SCEGU_VERTEX_FLOAT, 4, 7, 0, array);

	sceGumPopMatrix();
}

