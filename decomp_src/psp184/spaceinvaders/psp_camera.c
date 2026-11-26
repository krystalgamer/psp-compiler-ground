/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern float D_00353AC0;


typedef struct { float x, y, z; } CVEC;
typedef struct {
	int mode;
	float fovy;
	CVEC pos;
	CVEC rot;
	CVEC hist[8];
	float far;
	int f84;
	int f88;
	int f8C;
	int f90;
	float f94;
	int f98;
} CAMERA;
extern CAMERA camera;
void *memset(void *, int, unsigned int);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumTranslate(const CVEC *v);
void sceGumRotateX(float a);
void sceGumRotateY(float a);
void sceGumRotateZ(float a);

extern CAMERA camera;
void *memset(void *, int, unsigned int);
void sceGumMatrixMode(int mode);
void sceGumLoadIdentity(void);
void sceGumTranslate(const CVEC *v);
void sceGumRotateX(float a);
void sceGumRotateY(float a);
void sceGumRotateZ(float a);
void camera_init(void)
{
	memset(&camera, 0, sizeof(camera));
	camera.fovy = 0.52333337f;
	camera.f90 = 0;
	camera.f98 = 0;
	camera.f94 = 1.0f;
	camera.far = 10000.0f;
}

void camera_control(void)
{
	int i;

	sceGumMatrixMode(2);
	sceGumLoadIdentity();
	if (camera.mode == 0) {
		sceGumTranslate(&camera.pos);
		sceGumRotateX(camera.rot.x * 3.1415927f / 180.0f);
		sceGumRotateY(camera.rot.y * 3.1415927f / 180.0f);
		sceGumRotateZ(camera.rot.z * 3.1415927f / 180.0f);
	}
	for (i = 7; i > 0; i--)
		camera.hist[i] = camera.hist[i - 1];
	camera.hist[0] = camera.rot;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void camera_fovy_set(float fparg0) {
    D_00353AC0 = (fparg0 * 3.14f) / 180.0f;
}
