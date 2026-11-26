#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
struct _anon1 { /* size 0x3c */
    int mode;
    ScePspFVector3 pos;
    ScePspFVector3 sbuf[3];
    int scnt;
    float t;
};
typedef struct _anon1 BALLOONDAT;

extern BALLOONDAT balloon;
extern ScePspFVector3 sphere[28];
extern ScePspFVector3 pole[28];

void init_balloon(void);
void draw_balloon(void);
static void ctrl_spline(int mode);
int proc_balloon(void);


/* SDK prototypes (tools/sdk_protos.h) */
int rand(void);
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuSpecular(float power);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);

#define MODE_IN (0)
#define RANGERAND(b,u,r)	(b+u*(float)(rand()%r))
#define SIGN				((rand()%2)?-1.0f:1.0f)

void init_balloon(void)
{
	int		i;

	balloon.mode=MODE_IN;
	balloon.pos.x= 0.0f;
	balloon.pos.y=-8.0f;
	balloon.pos.z= 0.0f;
	balloon.t=0.0f;
	balloon.scnt=2;

	for (i=0; i<3; i++) {
		balloon.sbuf[i].x=RANGERAND(0.0f, 0.02f, 200)*SIGN;
		balloon.sbuf[i].y=RANGERAND(0.0f, 0.01f, 200)*SIGN;
		balloon.sbuf[i].z=RANGERAND(0.0f, 0.01f, 20)*SIGN;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/balloon", draw_balloon);

float spline(float t, float pos0, float pos1, float pos2) {
    float temp_f13;
    float temp_f15;
    float temp_f1;

    temp_f13 = (pos1 + pos0) * 0.5f;
    temp_f15 = (pos2 + pos1) * 0.5f;
    temp_f1 = ((temp_f13 + temp_f15 + pos1) / 3.0f) * 4.0f;
    return ((((2.0f * temp_f15) + (2.0f * temp_f13)) - temp_f1) * t * t) + (((temp_f1 - temp_f15) - (temp_f13 * 3.0f)) * t) + temp_f13;
}

#define SPLINE_X (0x01)
#define SPLINE_Y (0x02)
#define SPLINE_Z (0x04)
#define RING2(p)	(p==0?1:p==1?2:0)
#define RING3(p)	(p==0?2:p==1?0:1)

static void ctrl_spline(int mode)
{
	float	p[3];
	int		cnt=balloon.scnt;

	if (mode&SPLINE_X) {
		p[0]=balloon.sbuf[cnt       ].x;
		p[1]=balloon.sbuf[RING2(cnt)].x;
		p[2]=balloon.sbuf[RING3(cnt)].x;
		balloon.pos.x=spline(balloon.t, p[0], p[1], p[2]);
	}
	if (mode&SPLINE_Y) {
		p[0]=balloon.sbuf[cnt       ].y;
		p[1]=balloon.sbuf[RING2(cnt)].y;
		p[2]=balloon.sbuf[RING3(cnt)].y;
		balloon.pos.y=spline(balloon.t, p[0], p[1], p[2]);
	}
	if (mode&SPLINE_Z) {
		p[0]=balloon.sbuf[cnt       ].z;
		p[1]=balloon.sbuf[RING2(cnt)].z;
		p[2]=balloon.sbuf[RING3(cnt)].z;
		balloon.pos.z=spline(balloon.t, p[0], p[1], p[2]);
	}

	balloon.t+=0.02f;
	if (balloon.t>=1.0f) {
		balloon.t=0.0f;

		balloon.sbuf[balloon.scnt].x=RANGERAND(0.0f, 0.02f, 200)*SIGN;
		balloon.sbuf[balloon.scnt].y=RANGERAND(0.0f, 0.01f, 200)*SIGN;
		balloon.sbuf[balloon.scnt].z=RANGERAND(0.0f, 0.01f, 20)*SIGN;
		balloon.scnt=(balloon.scnt+1>=3?0:balloon.scnt+1);
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/balloon", proc_balloon);

void set_balloon(int mode) {
    balloon.mode = mode;
}

int get_balloon(void) {
    return balloon.mode;
}
