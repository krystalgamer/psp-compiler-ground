/* compiler from config/UTST99332/units.graphics_cube.txt */
#include "common.h"

struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
struct _anon1 { /* size 0x20 */
    float u;
    float v;
    float nx;
    float ny;
    float nz;
    float x;
    float y;
    float z;
};
typedef struct _anon1 CubeVertex;

extern CubeVertex cube_data[36];

#include "sdk/libgum.h"

void DrawCube(float scale)
{
	ScePspFVector3 vec;

	vec.x = scale;
	vec.y = scale;
	vec.z = scale;
	sceGumPushMatrix();
	sceGumScale(&vec);
	sceGumDrawArray(3, 0x1E3, 36, 0, cube_data);
	sceGumPopMatrix();
}
