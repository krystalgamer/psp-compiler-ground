#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
int sceKernelDcacheWritebackAll(void);

typedef struct ScePspFVector3 { float x, y, z; } ScePspFVector3;
#define SCEGU_PRIM_TRIANGLE_FAN            5
#define SCEGU_NORMAL_FLOAT       ( 3 <<  5 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )

void DrawCone(float *array, float r,float h)
{
	ScePspFVector3	vec;
	extern float	D_000133A8[34*6];
	int	i;

	for(i=0;i<(int)(sizeof(D_000133A8)/sizeof(float));i++) {
		array[i]=D_000133A8[i];
	}
	array[1]=-1.0f, array[4]=0.0f;
	sceKernelDcacheWritebackAll();

	sceGumPushMatrix();
	vec.x=vec.z=0.0f;
	vec.y=-0.5f;
	sceGumTranslate(&vec);
	vec.x=vec.z=r;
	vec.y=h;
	sceGumScale(&vec);

	sceGumDrawArray(SCEGU_PRIM_TRIANGLE_FAN,
					SCEGU_NORMAL_FLOAT|SCEGU_VERTEX_FLOAT,
					34, 0, D_000133A8);

	sceGumDrawArray(SCEGU_PRIM_TRIANGLE_FAN,
					SCEGU_NORMAL_FLOAT|SCEGU_VERTEX_FLOAT,
					34, 0, array);

	sceGumPopMatrix();
}
