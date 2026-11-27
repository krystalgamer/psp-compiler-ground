#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
int rand(void);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);

typedef struct {
	struct { float x, y, z; } rot;
	struct { float x, y, z; } pos;
	float speed;
} QPOS;

extern QPOS qpos[576];

extern int qcnt;
extern int rot_flag_3D804;
#define rot_flag rot_flag_3D804
void sceGumTranslate(const void *v);
void sceGumRotateZYX(const void *v);

static void draw_quad(int type, void *p)
{
	sceGumPushMatrix();
	sceGumTranslate(&qpos[qcnt].pos);
	if (rot_flag) {
		sceGumRotateZYX(&qpos[qcnt].rot);
	}
	sceGumDrawArray(4, type, 4, 0, p);
	sceGumPopMatrix();
	qcnt++;
}

void update_pos(void)
{
	int i;
	float tpi = 6.2831855f;

	for (i = 0; i < 576; i++) {
		qpos[i].rot.x += 0.1f;
		if (qpos[i].rot.x > tpi) {
			qpos[i].rot.x -= tpi;
		}

		qpos[i].rot.y += 0.1f;
		if (qpos[i].rot.y > tpi) {
			qpos[i].rot.y -= tpi;
		}

		qpos[i].rot.z += 0.1f;
		if (qpos[i].rot.z > tpi) {
			qpos[i].rot.z -= tpi;
		}

		qpos[i].pos.z += qpos[i].speed;
		if (qpos[i].pos.z > 0.0f) {
			qpos[i].pos.z = -300.0f;
		}
	}
}

void InitData(void)
{
	int		i;

	for (i = 0; i < 576; i++) {
		qpos[i].pos.x = (float)((rand() % 5000) - 2500) / 100.0f;
		qpos[i].pos.y = (float)((rand() % 5000) - 2500) / 100.0f;
		qpos[i].pos.z = (float)((rand() % 300) - 300);
		qpos[i].rot.x = (float)(rand() % 300) / 100.0f;
		qpos[i].rot.y = (float)(rand() % 300) / 100.0f;
		qpos[i].rot.z = (float)(rand() % 300) / 100.0f;
		qpos[i].speed = (float)((rand() % 100) + 100) / 100.0f;
	}
}

#define SCEGU_COLOR_PF5551 ( 5 <<  2 )
#define SCEGU_COLOR_PF8888 ( 7 <<  2 )
#define SCEGU_LIGHTING 10
#define SCEGU_NORMAL_BYTE ( 1 <<  5 )
#define SCEGU_NORMAL_FLOAT ( 3 <<  5 )
#define SCEGU_NORMAL_SHORT ( 2 <<  5 )
#define SCEGU_TEXTURE 9
#define SCEGU_TEXTURE_FLOAT ( 3 <<  0 )
#define SCEGU_TEXTURE_UBYTE ( 1 <<  0 )
#define SCEGU_TEXTURE_USHORT ( 2 <<  0 )
#define SCEGU_VERTEX_BYTE ( 1 <<  7 )
#define SCEGU_VERTEX_FLOAT ( 3 <<  7 )
#define SCEGU_VERTEX_SHORT ( 2 <<  7 )
#define SCEGU_WEIGHT_8 ( 7 << 14 )
#define SCEGU_WEIGHT_FLOAT ( 3 <<  9 )
#define SCEGU_WEIGHT_UBYTE ( 1 <<  9 )
#define SCEGU_WEIGHT_USHORT ( 2 <<  9 )
#define V_8 SCEGU_VERTEX_BYTE
#define V_16 SCEGU_VERTEX_SHORT
#define V_32 SCEGU_VERTEX_FLOAT
#define N_8 SCEGU_NORMAL_BYTE
#define N_16 SCEGU_NORMAL_SHORT
#define N_32 SCEGU_NORMAL_FLOAT
#define C_16 SCEGU_COLOR_PF5551
#define C_32 SCEGU_COLOR_PF8888
#define T_8 SCEGU_TEXTURE_UBYTE
#define T_16 SCEGU_TEXTURE_USHORT
#define T_32 SCEGU_TEXTURE_FLOAT
#define W_8 SCEGU_WEIGHT_UBYTE|SCEGU_WEIGHT_8
#define W_16 SCEGU_WEIGHT_USHORT|SCEGU_WEIGHT_8
#define W_32 SCEGU_WEIGHT_FLOAT|SCEGU_WEIGHT_8
#define QSCALE 0.2f
extern char v8[];
extern char v16[];
extern char v32[];
extern char n8v8[];
extern char n8v16[];
extern char n8v32[];
extern char n16v8[];
extern char n16v16[];
extern char n16v32[];
extern char n32v8[];
extern char n32v16[];
extern char n32v32[];
extern char c16v8[];
extern char c16v16[];
extern char c16v32[];
extern char c32v8[];
extern char c32v16[];
extern char c32v32[];
extern char t8v8[];
extern char t8v16[];
extern char t8v32[];
extern char t16v8[];
extern char t16v16[];
extern char t16v32[];
extern char t32v8[];
extern char t32v16[];
extern char t32v32[];
extern char w8v8[];
extern char w8v16[];
extern char w8v32[];
extern char w16v8[];
extern char w16v16[];
extern char w16v32[];
extern char w32v8[];
extern char w32v16[];
extern char w32v32[];
extern char c16n8v8[];
extern char c16n8v16[];
extern char c16n8v32[];
extern char c16n16v8[];
extern char c16n16v16[];
extern char c16n16v32[];
extern char c16n32v8[];
extern char c16n32v16[];
extern char c16n32v32[];
extern char c32n8v8[];
extern char c32n8v16[];
extern char c32n8v32[];
extern char c32n16v8[];
extern char c32n16v16[];
extern char c32n16v32[];
extern char c32n32v8[];
extern char c32n32v16[];
extern char c32n32v32[];
extern char t8n8v8[];
extern char t8n8v16[];
extern char t8n8v32[];
extern char t8n16v8[];
extern char t8n16v16[];
extern char t8n16v32[];
extern char t8n32v8[];
extern char t8n32v16[];
extern char t8n32v32[];
extern char t16n8v8[];
extern char t16n8v16[];
extern char t16n8v32[];
extern char t16n16v8[];
extern char t16n16v16[];
extern char t16n16v32[];
extern char t16n32v8[];
extern char t16n32v16[];
extern char t16n32v32[];
extern char t32n8v8[];
extern char t32n8v16[];
extern char t32n8v32[];
extern char t32n16v8[];
extern char t32n16v16[];
extern char t32n16v32[];
extern char t32n32v8[];
extern char t32n32v16[];
extern char t32n32v32[];
extern char t8c16v8[];
extern char t8c16v16[];
extern char t8c16v32[];
extern char t8c32v8[];
extern char t8c32v16[];
extern char t8c32v32[];
extern char t16c16v8[];
extern char t16c16v16[];
extern char t16c16v32[];
extern char t16c32v8[];
extern char t16c32v16[];
extern char t16c32v32[];
extern char t32c16v8[];
extern char t32c16v16[];
extern char t32c16v32[];
extern char t32c32v8[];
extern char t32c32v16[];
extern char t32c32v32[];
extern char w8n8v8[];
extern char w8n8v16[];
extern char w8n8v32[];
extern char w8n16v8[];
extern char w8n16v16[];
extern char w8n16v32[];
extern char w8n32v8[];
extern char w8n32v16[];
extern char w8n32v32[];
extern char w16n8v8[];
extern char w16n8v16[];
extern char w16n8v32[];
extern char w16n16v8[];
extern char w16n16v16[];
extern char w16n16v32[];
extern char w16n32v8[];
extern char w16n32v16[];
extern char w16n32v32[];
extern char w32n8v8[];
extern char w32n8v16[];
extern char w32n8v32[];
extern char w32n16v8[];
extern char w32n16v16[];
extern char w32n16v32[];
extern char w32n32v8[];
extern char w32n32v16[];
extern char w32n32v32[];
extern char w8c16v8[];
extern char w8c16v16[];
extern char w8c16v32[];
extern char w8c32v8[];
extern char w8c32v16[];
extern char w8c32v32[];
extern char w16c16v8[];
extern char w16c16v16[];
extern char w16c16v32[];
extern char w16c32v8[];
extern char w16c32v16[];
extern char w16c32v32[];
extern char w32c16v8[];
extern char w32c16v16[];
extern char w32c16v32[];
extern char w32c32v8[];
extern char w32c32v16[];
extern char w32c32v32[];
extern char w8t8v8[];
extern char w8t8v16[];
extern char w8t8v32[];
extern char w8t16v8[];
extern char w8t16v16[];
extern char w8t16v32[];
extern char w8t32v8[];
extern char w8t32v16[];
extern char w8t32v32[];
extern char w16t8v8[];
extern char w16t8v16[];
extern char w16t8v32[];
extern char w16t16v8[];
extern char w16t16v16[];
extern char w16t16v32[];
extern char w16t32v8[];
extern char w16t32v16[];
extern char w16t32v32[];
extern char w32t8v8[];
extern char w32t8v16[];
extern char w32t8v32[];
extern char w32t16v8[];
extern char w32t16v16[];
extern char w32t16v32[];
extern char w32t32v8[];
extern char w32t32v16[];
extern char w32t32v32[];
extern char t8c16n8v8[];
extern char t8c16n8v16[];
extern char t8c16n8v32[];
extern char t8c16n16v8[];
extern char t8c16n16v16[];
extern char t8c16n16v32[];
extern char t8c16n32v8[];
extern char t8c16n32v16[];
extern char t8c16n32v32[];
extern char t8c32n8v8[];
extern char t8c32n8v16[];
extern char t8c32n8v32[];
extern char t8c32n16v8[];
extern char t8c32n16v16[];
extern char t8c32n16v32[];
extern char t8c32n32v8[];
extern char t8c32n32v16[];
extern char t8c32n32v32[];
extern char t16c16n8v8[];
extern char t16c16n8v16[];
extern char t16c16n8v32[];
extern char t16c16n16v8[];
extern char t16c16n16v16[];
extern char t16c16n16v32[];
extern char t16c16n32v8[];
extern char t16c16n32v16[];
extern char t16c16n32v32[];
extern char t16c32n8v8[];
extern char t16c32n8v16[];
extern char t16c32n8v32[];
extern char t16c32n16v8[];
extern char t16c32n16v16[];
extern char t16c32n16v32[];
extern char t16c32n32v8[];
extern char t16c32n32v16[];
extern char t16c32n32v32[];
extern char t32c16n8v8[];
extern char t32c16n8v16[];
extern char t32c16n8v32[];
extern char t32c16n16v8[];
extern char t32c16n16v16[];
extern char t32c16n16v32[];
extern char t32c16n32v8[];
extern char t32c16n32v16[];
extern char t32c16n32v32[];
extern char t32c32n8v8[];
extern char t32c32n8v16[];
extern char t32c32n8v32[];
extern char t32c32n16v8[];
extern char t32c32n16v16[];
extern char t32c32n16v32[];
extern char t32c32n32v8[];
extern char t32c32n32v16[];
extern char t32c32n32v32[];
extern char w8c16n8v8[];
extern char w8c16n8v16[];
extern char w8c16n8v32[];
extern char w8c16n16v8[];
extern char w8c16n16v16[];
extern char w8c16n16v32[];
extern char w8c16n32v8[];
extern char w8c16n32v16[];
extern char w8c16n32v32[];
extern char w8c32n8v8[];
extern char w8c32n8v16[];
extern char w8c32n8v32[];
extern char w8c32n16v8[];
extern char w8c32n16v16[];
extern char w8c32n16v32[];
extern char w8c32n32v8[];
extern char w8c32n32v16[];
extern char w8c32n32v32[];
extern char w16c16n8v8[];
extern char w16c16n8v16[];
extern char w16c16n8v32[];
extern char w16c16n16v8[];
extern char w16c16n16v16[];
extern char w16c16n16v32[];
extern char w16c16n32v8[];
extern char w16c16n32v16[];
extern char w16c16n32v32[];
extern char w16c32n8v8[];
extern char w16c32n8v16[];
extern char w16c32n8v32[];
extern char w16c32n16v8[];
extern char w16c32n16v16[];
extern char w16c32n16v32[];
extern char w16c32n32v8[];
extern char w16c32n32v16[];
extern char w16c32n32v32[];
extern char w32c16n8v8[];
extern char w32c16n8v16[];
extern char w32c16n8v32[];
extern char w32c16n16v8[];
extern char w32c16n16v16[];
extern char w32c16n16v32[];
extern char w32c16n32v8[];
extern char w32c16n32v16[];
extern char w32c16n32v32[];
extern char w32c32n8v8[];
extern char w32c32n8v16[];
extern char w32c32n8v32[];
extern char w32c32n16v8[];
extern char w32c32n16v16[];
extern char w32c32n16v32[];
extern char w32c32n32v8[];
extern char w32c32n32v16[];
extern char w32c32n32v32[];
extern char w8t8n8v8[];
extern char w8t8n8v16[];
extern char w8t8n8v32[];
extern char w8t8n16v8[];
extern char w8t8n16v16[];
extern char w8t8n16v32[];
extern char w8t8n32v8[];
extern char w8t8n32v16[];
extern char w8t8n32v32[];
extern char w8t16n8v8[];
extern char w8t16n8v16[];
extern char w8t16n8v32[];
extern char w8t16n16v8[];
extern char w8t16n16v16[];
extern char w8t16n16v32[];
extern char w8t16n32v8[];
extern char w8t16n32v16[];
extern char w8t16n32v32[];
extern char w8t32n8v8[];
extern char w8t32n8v16[];
extern char w8t32n8v32[];
extern char w8t32n16v8[];
extern char w8t32n16v16[];
extern char w8t32n16v32[];
extern char w8t32n32v8[];
extern char w8t32n32v16[];
extern char w8t32n32v32[];
extern char w16t8n8v8[];
extern char w16t8n8v16[];
extern char w16t8n8v32[];
extern char w16t8n16v8[];
extern char w16t8n16v16[];
extern char w16t8n16v32[];
extern char w16t8n32v8[];
extern char w16t8n32v16[];
extern char w16t8n32v32[];
extern char w16t16n8v8[];
extern char w16t16n8v16[];
extern char w16t16n8v32[];
extern char w16t16n16v8[];
extern char w16t16n16v16[];
extern char w16t16n16v32[];
extern char w16t16n32v8[];
extern char w16t16n32v16[];
extern char w16t16n32v32[];
extern char w16t32n8v8[];
extern char w16t32n8v16[];
extern char w16t32n8v32[];
extern char w16t32n16v8[];
extern char w16t32n16v16[];
extern char w16t32n16v32[];
extern char w16t32n32v8[];
extern char w16t32n32v16[];
extern char w16t32n32v32[];
extern char w32t8n8v8[];
extern char w32t8n8v16[];
extern char w32t8n8v32[];
extern char w32t8n16v8[];
extern char w32t8n16v16[];
extern char w32t8n16v32[];
extern char w32t8n32v8[];
extern char w32t8n32v16[];
extern char w32t8n32v32[];
extern char w32t16n8v8[];
extern char w32t16n8v16[];
extern char w32t16n8v32[];
extern char w32t16n16v8[];
extern char w32t16n16v16[];
extern char w32t16n16v32[];
extern char w32t16n32v8[];
extern char w32t16n32v16[];
extern char w32t16n32v32[];
extern char w32t32n8v8[];
extern char w32t32n8v16[];
extern char w32t32n8v32[];
extern char w32t32n16v8[];
extern char w32t32n16v16[];
extern char w32t32n16v32[];
extern char w32t32n32v8[];
extern char w32t32n32v16[];
extern char w32t32n32v32[];
extern char w8t8c16v8[];
extern char w8t8c16v16[];
extern char w8t8c16v32[];
extern char w8t8c32v8[];
extern char w8t8c32v16[];
extern char w8t8c32v32[];
extern char w8t16c16v8[];
extern char w8t16c16v16[];
extern char w8t16c16v32[];
extern char w8t16c32v8[];
extern char w8t16c32v16[];
extern char w8t16c32v32[];
extern char w8t32c16v8[];
extern char w8t32c16v16[];
extern char w8t32c16v32[];
extern char w8t32c32v8[];
extern char w8t32c32v16[];
extern char w8t32c32v32[];
extern char w16t8c16v8[];
extern char w16t8c16v16[];
extern char w16t8c16v32[];
extern char w16t8c32v8[];
extern char w16t8c32v16[];
extern char w16t8c32v32[];
extern char w16t16c16v8[];
extern char w16t16c16v16[];
extern char w16t16c16v32[];
extern char w16t16c32v8[];
extern char w16t16c32v16[];
extern char w16t16c32v32[];
extern char w16t32c16v8[];
extern char w16t32c16v16[];
extern char w16t32c16v32[];
extern char w16t32c32v8[];
extern char w16t32c32v16[];
extern char w16t32c32v32[];
extern char w32t8c16v8[];
extern char w32t8c16v16[];
extern char w32t8c16v32[];
extern char w32t8c32v8[];
extern char w32t8c32v16[];
extern char w32t8c32v32[];
extern char w32t16c16v8[];
extern char w32t16c16v16[];
extern char w32t16c16v32[];
extern char w32t16c32v8[];
extern char w32t16c32v16[];
extern char w32t16c32v32[];
extern char w32t32c16v8[];
extern char w32t32c16v16[];
extern char w32t32c16v32[];
extern char w32t32c32v8[];
extern char w32t32c32v16[];
extern char w32t32c32v32[];
extern char w8t8c16n8v8[];
extern char w8t8c16n8v16[];
extern char w8t8c16n8v32[];
extern char w8t8c16n16v8[];
extern char w8t8c16n16v16[];
extern char w8t8c16n16v32[];
extern char w8t8c16n32v8[];
extern char w8t8c16n32v16[];
extern char w8t8c16n32v32[];
extern char w8t8c32n8v8[];
extern char w8t8c32n8v16[];
extern char w8t8c32n8v32[];
extern char w8t8c32n16v8[];
extern char w8t8c32n16v16[];
extern char w8t8c32n16v32[];
extern char w8t8c32n32v8[];
extern char w8t8c32n32v16[];
extern char w8t8c32n32v32[];
extern char w8t16c16n8v8[];
extern char w8t16c16n8v16[];
extern char w8t16c16n8v32[];
extern char w8t16c16n16v8[];
extern char w8t16c16n16v16[];
extern char w8t16c16n16v32[];
extern char w8t16c16n32v8[];
extern char w8t16c16n32v16[];
extern char w8t16c16n32v32[];
extern char w8t16c32n8v8[];
extern char w8t16c32n8v16[];
extern char w8t16c32n8v32[];
extern char w8t16c32n16v8[];
extern char w8t16c32n16v16[];
extern char w8t16c32n16v32[];
extern char w8t16c32n32v8[];
extern char w8t16c32n32v16[];
extern char w8t16c32n32v32[];
extern char w8t32c16n8v8[];
extern char w8t32c16n8v16[];
extern char w8t32c16n8v32[];
extern char w8t32c16n16v8[];
extern char w8t32c16n16v16[];
extern char w8t32c16n16v32[];
extern char w8t32c16n32v8[];
extern char w8t32c16n32v16[];
extern char w8t32c16n32v32[];
extern char w8t32c32n8v8[];
extern char w8t32c32n8v16[];
extern char w8t32c32n8v32[];
extern char w8t32c32n16v8[];
extern char w8t32c32n16v16[];
extern char w8t32c32n16v32[];
extern char w8t32c32n32v8[];
extern char w8t32c32n32v16[];
extern char w8t32c32n32v32[];
extern char w16t8c16n8v8[];
extern char w16t8c16n8v16[];
extern char w16t8c16n8v32[];
extern char w16t8c16n16v8[];
extern char w16t8c16n16v16[];
extern char w16t8c16n16v32[];
extern char w16t8c16n32v8[];
extern char w16t8c16n32v16[];
extern char w16t8c16n32v32[];
extern char w16t8c32n8v8[];
extern char w16t8c32n8v16[];
extern char w16t8c32n8v32[];
extern char w16t8c32n16v8[];
extern char w16t8c32n16v16[];
extern char w16t8c32n16v32[];
extern char w16t8c32n32v8[];
extern char w16t8c32n32v16[];
extern char w16t8c32n32v32[];
extern char w16t16c16n8v8[];
extern char w16t16c16n8v16[];
extern char w16t16c16n8v32[];
extern char w16t16c16n16v8[];
extern char w16t16c16n16v16[];
extern char w16t16c16n16v32[];
extern char w16t16c16n32v8[];
extern char w16t16c16n32v16[];
extern char w16t16c16n32v32[];
extern char w16t16c32n8v8[];
extern char w16t16c32n8v16[];
extern char w16t16c32n8v32[];
extern char w16t16c32n16v8[];
extern char w16t16c32n16v16[];
extern char w16t16c32n16v32[];
extern char w16t16c32n32v8[];
extern char w16t16c32n32v16[];
extern char w16t16c32n32v32[];
extern char w16t32c16n8v8[];
extern char w16t32c16n8v16[];
extern char w16t32c16n8v32[];
extern char w16t32c16n16v8[];
extern char w16t32c16n16v16[];
extern char w16t32c16n16v32[];
extern char w16t32c16n32v8[];
extern char w16t32c16n32v16[];
extern char w16t32c16n32v32[];
extern char w16t32c32n8v8[];
extern char w16t32c32n8v16[];
extern char w16t32c32n8v32[];
extern char w16t32c32n16v8[];
extern char w16t32c32n16v16[];
extern char w16t32c32n16v32[];
extern char w16t32c32n32v8[];
extern char w16t32c32n32v16[];
extern char w16t32c32n32v32[];
extern char w32t8c16n8v8[];
extern char w32t8c16n8v16[];
extern char w32t8c16n8v32[];
extern char w32t8c16n16v8[];
extern char w32t8c16n16v16[];
extern char w32t8c16n16v32[];
extern char w32t8c16n32v8[];
extern char w32t8c16n32v16[];
extern char w32t8c16n32v32[];
extern char w32t8c32n8v8[];
extern char w32t8c32n8v16[];
extern char w32t8c32n8v32[];
extern char w32t8c32n16v8[];
extern char w32t8c32n16v16[];
extern char w32t8c32n16v32[];
extern char w32t8c32n32v8[];
extern char w32t8c32n32v16[];
extern char w32t8c32n32v32[];
extern char w32t16c16n8v8[];
extern char w32t16c16n8v16[];
extern char w32t16c16n8v32[];
extern char w32t16c16n16v8[];
extern char w32t16c16n16v16[];
extern char w32t16c16n16v32[];
extern char w32t16c16n32v8[];
extern char w32t16c16n32v16[];
extern char w32t16c16n32v32[];
extern char w32t16c32n8v8[];
extern char w32t16c32n8v16[];
extern char w32t16c32n8v32[];
extern char w32t16c32n16v8[];
extern char w32t16c32n16v16[];
extern char w32t16c32n16v32[];
extern char w32t16c32n32v8[];
extern char w32t16c32n32v16[];
extern char w32t16c32n32v32[];
extern char w32t32c16n8v8[];
extern char w32t32c16n8v16[];
extern char w32t32c16n8v32[];
extern char w32t32c16n16v8[];
extern char w32t32c16n16v16[];
extern char w32t32c16n16v32[];
extern char w32t32c16n32v8[];
extern char w32t32c16n32v16[];
extern char w32t32c16n32v32[];
extern char w32t32c32n8v8[];
extern char w32t32c32n8v16[];
extern char w32t32c32n8v32[];
extern char w32t32c32n16v8[];
extern char w32t32c32n16v16[];
extern char w32t32c32n16v32[];
extern char w32t32c32n32v8[];
extern char w32t32c32n32v16[];
extern char w32t32c32n32v32[];
extern int qcnt;
void sceGumScale(const void *v);

void DrawData(int pause, int rot)
{
	struct { float x, y, z; } vec;

	if (pause == 0) {
		update_pos();
	}
	rot_flag = rot;
	qcnt = 0;

	sceGumPushMatrix();
	vec.x = QSCALE;
	vec.y = QSCALE;
	vec.z = QSCALE;
	sceGumScale(&vec);

	/*=====================================================
	   Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(V_8, v8);
	draw_quad(V_16, v16);
	draw_quad(V_32, v32);

	/*=====================================================
	   Normal + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(N_8|V_8, n8v8);
	draw_quad(N_8|V_16, n8v16);
	draw_quad(N_8|V_32, n8v32);
	draw_quad(N_16|V_8, n16v8);
	draw_quad(N_16|V_16, n16v16);
	draw_quad(N_16|V_32, n16v32);
	draw_quad(N_32|V_8, n32v8);
	draw_quad(N_32|V_16, n32v16);
	draw_quad(N_32|V_32, n32v32);

	/*=====================================================
	   Color + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(C_16|V_8, c16v8);
	draw_quad(C_16|V_16, c16v16);
	draw_quad(C_16|V_32, c16v32);
	draw_quad(C_32|V_8, c32v8);
	draw_quad(C_32|V_16, c32v16);
	draw_quad(C_32|V_32, c32v32);

	/*=====================================================
	   Texture + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(T_8|V_8, t8v8);
	draw_quad(T_8|V_16, t8v16);
	draw_quad(T_8|V_32, t8v32);
	draw_quad(T_16|V_8, t16v8);
	draw_quad(T_16|V_16, t16v16);
	draw_quad(T_16|V_32, t16v32);
	draw_quad(T_32|V_8, t32v8);
	draw_quad(T_32|V_16, t32v16);
	draw_quad(T_32|V_32, t32v32);

	/*=====================================================
	   Weight(8) + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(W_8|V_8, w8v8);
	draw_quad(W_8|V_16, w8v16);
	draw_quad(W_8|V_32, w8v32);
	draw_quad(W_16|V_8, w16v8);
	draw_quad(W_16|V_16, w16v16);
	draw_quad(W_16|V_32, w16v32);
	draw_quad(W_32|V_8, w32v8);
	draw_quad(W_32|V_16, w32v16);
	draw_quad(W_32|V_32, w32v32);

	/*=====================================================
	   Color + Normal + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(C_16|N_8|V_8, c16n8v8);
	draw_quad(C_16|N_8|V_16, c16n8v16);
	draw_quad(C_16|N_8|V_32, c16n8v32);
	draw_quad(C_16|N_16|V_8, c16n16v8);
	draw_quad(C_16|N_16|V_16, c16n16v16);
	draw_quad(C_16|N_16|V_32, c16n16v32);
	draw_quad(C_16|N_32|V_8, c16n32v8);
	draw_quad(C_16|N_32|V_16, c16n32v16);
	draw_quad(C_16|N_32|V_32, c16n32v32);
	draw_quad(C_32|N_8|V_8, c32n8v8);
	draw_quad(C_32|N_8|V_16, c32n8v16);
	draw_quad(C_32|N_8|V_32, c32n8v32);
	draw_quad(C_32|N_16|V_8, c32n16v8);
	draw_quad(C_32|N_16|V_16, c32n16v16);
	draw_quad(C_32|N_16|V_32, c32n16v32);
	draw_quad(C_32|N_32|V_8, c32n32v8);
	draw_quad(C_32|N_32|V_16, c32n32v16);
	draw_quad(C_32|N_32|V_32, c32n32v32);

	/*=====================================================
	   Texture + Normal + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(T_8|N_8|V_8, t8n8v8);
	draw_quad(T_8|N_8|V_16, t8n8v16);
	draw_quad(T_8|N_8|V_32, t8n8v32);
	draw_quad(T_8|N_16|V_8, t8n16v8);
	draw_quad(T_8|N_16|V_16, t8n16v16);
	draw_quad(T_8|N_16|V_32, t8n16v32);
	draw_quad(T_8|N_32|V_8, t8n32v8);
	draw_quad(T_8|N_32|V_16, t8n32v16);
	draw_quad(T_8|N_32|V_32, t8n32v32);
	draw_quad(T_16|N_8|V_8, t16n8v8);
	draw_quad(T_16|N_8|V_16, t16n8v16);
	draw_quad(T_16|N_8|V_32, t16n8v32);
	draw_quad(T_16|N_16|V_8, t16n16v8);
	draw_quad(T_16|N_16|V_16, t16n16v16);
	draw_quad(T_16|N_16|V_32, t16n16v32);
	draw_quad(T_16|N_32|V_8, t16n32v8);
	draw_quad(T_16|N_32|V_16, t16n32v16);
	draw_quad(T_16|N_32|V_32, t16n32v32);
	draw_quad(T_32|N_8|V_8, t32n8v8);
	draw_quad(T_32|N_8|V_16, t32n8v16);
	draw_quad(T_32|N_8|V_32, t32n8v32);
	draw_quad(T_32|N_16|V_8, t32n16v8);
	draw_quad(T_32|N_16|V_16, t32n16v16);
	draw_quad(T_32|N_16|V_32, t32n16v32);
	draw_quad(T_32|N_32|V_8, t32n32v8);
	draw_quad(T_32|N_32|V_16, t32n32v16);
	draw_quad(T_32|N_32|V_32, t32n32v32);

	/*=====================================================
	   Texture + Color + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(T_8|C_16|V_8, t8c16v8);
	draw_quad(T_8|C_16|V_16, t8c16v16);
	draw_quad(T_8|C_16|V_32, t8c16v32);
	draw_quad(T_8|C_32|V_8, t8c32v8);
	draw_quad(T_8|C_32|V_16, t8c32v16);
	draw_quad(T_8|C_32|V_32, t8c32v32);
	draw_quad(T_16|C_16|V_8, t16c16v8);
	draw_quad(T_16|C_16|V_16, t16c16v16);
	draw_quad(T_16|C_16|V_32, t16c16v32);
	draw_quad(T_16|C_32|V_8, t16c32v8);
	draw_quad(T_16|C_32|V_16, t16c32v16);
	draw_quad(T_16|C_32|V_32, t16c32v32);
	draw_quad(T_32|C_16|V_8, t32c16v8);
	draw_quad(T_32|C_16|V_16, t32c16v16);
	draw_quad(T_32|C_16|V_32, t32c16v32);
	draw_quad(T_32|C_32|V_8, t32c32v8);
	draw_quad(T_32|C_32|V_16, t32c32v16);
	draw_quad(T_32|C_32|V_32, t32c32v32);

	/*=====================================================
	   Weight(8) + Normal + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(W_8|N_8|V_8, w8n8v8);
	draw_quad(W_8|N_8|V_16, w8n8v16);
	draw_quad(W_8|N_8|V_32, w8n8v32);
	draw_quad(W_8|N_16|V_8, w8n16v8);
	draw_quad(W_8|N_16|V_16, w8n16v16);
	draw_quad(W_8|N_16|V_32, w8n16v32);
	draw_quad(W_8|N_32|V_8, w8n32v8);
	draw_quad(W_8|N_32|V_16, w8n32v16);
	draw_quad(W_8|N_32|V_32, w8n32v32);
	draw_quad(W_16|N_8|V_8, w16n8v8);
	draw_quad(W_16|N_8|V_16, w16n8v16);
	draw_quad(W_16|N_8|V_32, w16n8v32);
	draw_quad(W_16|N_16|V_8, w16n16v8);
	draw_quad(W_16|N_16|V_16, w16n16v16);
	draw_quad(W_16|N_16|V_32, w16n16v32);
	draw_quad(W_16|N_32|V_8, w16n32v8);
	draw_quad(W_16|N_32|V_16, w16n32v16);
	draw_quad(W_16|N_32|V_32, w16n32v32);
	draw_quad(W_32|N_8|V_8, w32n8v8);
	draw_quad(W_32|N_8|V_16, w32n8v16);
	draw_quad(W_32|N_8|V_32, w32n8v32);
	draw_quad(W_32|N_16|V_8, w32n16v8);
	draw_quad(W_32|N_16|V_16, w32n16v16);
	draw_quad(W_32|N_16|V_32, w32n16v32);
	draw_quad(W_32|N_32|V_8, w32n32v8);
	draw_quad(W_32|N_32|V_16, w32n32v16);
	draw_quad(W_32|N_32|V_32, w32n32v32);

	/*=====================================================
	   Weight(8) + Color + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(W_8|C_16|V_8, w8c16v8);
	draw_quad(W_8|C_16|V_16, w8c16v16);
	draw_quad(W_8|C_16|V_32, w8c16v32);
	draw_quad(W_8|C_32|V_8, w8c32v8);
	draw_quad(W_8|C_32|V_16, w8c32v16);
	draw_quad(W_8|C_32|V_32, w8c32v32);
	draw_quad(W_16|C_16|V_8, w16c16v8);
	draw_quad(W_16|C_16|V_16, w16c16v16);
	draw_quad(W_16|C_16|V_32, w16c16v32);
	draw_quad(W_16|C_32|V_8, w16c32v8);
	draw_quad(W_16|C_32|V_16, w16c32v16);
	draw_quad(W_16|C_32|V_32, w16c32v32);
	draw_quad(W_32|C_16|V_8, w32c16v8);
	draw_quad(W_32|C_16|V_16, w32c16v16);
	draw_quad(W_32|C_16|V_32, w32c16v32);
	draw_quad(W_32|C_32|V_8, w32c32v8);
	draw_quad(W_32|C_32|V_16, w32c32v16);
	draw_quad(W_32|C_32|V_32, w32c32v32);

	/*=====================================================
	   Weight(8) + Texture + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(W_8|T_8|V_8, w8t8v8);
	draw_quad(W_8|T_8|V_16, w8t8v16);
	draw_quad(W_8|T_8|V_32, w8t8v32);
	draw_quad(W_8|T_16|V_8, w8t16v8);
	draw_quad(W_8|T_16|V_16, w8t16v16);
	draw_quad(W_8|T_16|V_32, w8t16v32);
	draw_quad(W_8|T_32|V_8, w8t32v8);
	draw_quad(W_8|T_32|V_16, w8t32v16);
	draw_quad(W_8|T_32|V_32, w8t32v32);
	draw_quad(W_16|T_8|V_8, w16t8v8);
	draw_quad(W_16|T_8|V_16, w16t8v16);
	draw_quad(W_16|T_8|V_32, w16t8v32);
	draw_quad(W_16|T_16|V_8, w16t16v8);
	draw_quad(W_16|T_16|V_16, w16t16v16);
	draw_quad(W_16|T_16|V_32, w16t16v32);
	draw_quad(W_16|T_32|V_8, w16t32v8);
	draw_quad(W_16|T_32|V_16, w16t32v16);
	draw_quad(W_16|T_32|V_32, w16t32v32);
	draw_quad(W_32|T_8|V_8, w32t8v8);
	draw_quad(W_32|T_8|V_16, w32t8v16);
	draw_quad(W_32|T_8|V_32, w32t8v32);
	draw_quad(W_32|T_16|V_8, w32t16v8);
	draw_quad(W_32|T_16|V_16, w32t16v16);
	draw_quad(W_32|T_16|V_32, w32t16v32);
	draw_quad(W_32|T_32|V_8, w32t32v8);
	draw_quad(W_32|T_32|V_16, w32t32v16);
	draw_quad(W_32|T_32|V_32, w32t32v32);

	/*=====================================================
	   Texture + Color + Normal + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(T_8|C_16|N_8|V_8, t8c16n8v8);
	draw_quad(T_8|C_16|N_8|V_16, t8c16n8v16);
	draw_quad(T_8|C_16|N_8|V_32, t8c16n8v32);
	draw_quad(T_8|C_16|N_16|V_8, t8c16n16v8);
	draw_quad(T_8|C_16|N_16|V_16, t8c16n16v16);
	draw_quad(T_8|C_16|N_16|V_32, t8c16n16v32);
	draw_quad(T_8|C_16|N_32|V_8, t8c16n32v8);
	draw_quad(T_8|C_16|N_32|V_16, t8c16n32v16);
	draw_quad(T_8|C_16|N_32|V_32, t8c16n32v32);
	draw_quad(T_8|C_32|N_8|V_8, t8c32n8v8);
	draw_quad(T_8|C_32|N_8|V_16, t8c32n8v16);
	draw_quad(T_8|C_32|N_8|V_32, t8c32n8v32);
	draw_quad(T_8|C_32|N_16|V_8, t8c32n16v8);
	draw_quad(T_8|C_32|N_16|V_16, t8c32n16v16);
	draw_quad(T_8|C_32|N_16|V_32, t8c32n16v32);
	draw_quad(T_8|C_32|N_32|V_8, t8c32n32v8);
	draw_quad(T_8|C_32|N_32|V_16, t8c32n32v16);
	draw_quad(T_8|C_32|N_32|V_32, t8c32n32v32);
	draw_quad(T_16|C_16|N_8|V_8, t16c16n8v8);
	draw_quad(T_16|C_16|N_8|V_16, t16c16n8v16);
	draw_quad(T_16|C_16|N_8|V_32, t16c16n8v32);
	draw_quad(T_16|C_16|N_16|V_8, t16c16n16v8);
	draw_quad(T_16|C_16|N_16|V_16, t16c16n16v16);
	draw_quad(T_16|C_16|N_16|V_32, t16c16n16v32);
	draw_quad(T_16|C_16|N_32|V_8, t16c16n32v8);
	draw_quad(T_16|C_16|N_32|V_16, t16c16n32v16);
	draw_quad(T_16|C_16|N_32|V_32, t16c16n32v32);
	draw_quad(T_16|C_32|N_8|V_8, t16c32n8v8);
	draw_quad(T_16|C_32|N_8|V_16, t16c32n8v16);
	draw_quad(T_16|C_32|N_8|V_32, t16c32n8v32);
	draw_quad(T_16|C_32|N_16|V_8, t16c32n16v8);
	draw_quad(T_16|C_32|N_16|V_16, t16c32n16v16);
	draw_quad(T_16|C_32|N_16|V_32, t16c32n16v32);
	draw_quad(T_16|C_32|N_32|V_8, t16c32n32v8);
	draw_quad(T_16|C_32|N_32|V_16, t16c32n32v16);
	draw_quad(T_16|C_32|N_32|V_32, t16c32n32v32);
	draw_quad(T_32|C_16|N_8|V_8, t32c16n8v8);
	draw_quad(T_32|C_16|N_8|V_16, t32c16n8v16);
	draw_quad(T_32|C_16|N_8|V_32, t32c16n8v32);
	draw_quad(T_32|C_16|N_16|V_8, t32c16n16v8);
	draw_quad(T_32|C_16|N_16|V_16, t32c16n16v16);
	draw_quad(T_32|C_16|N_16|V_32, t32c16n16v32);
	draw_quad(T_32|C_16|N_32|V_8, t32c16n32v8);
	draw_quad(T_32|C_16|N_32|V_16, t32c16n32v16);
	draw_quad(T_32|C_16|N_32|V_32, t32c16n32v32);
	draw_quad(T_32|C_32|N_8|V_8, t32c32n8v8);
	draw_quad(T_32|C_32|N_8|V_16, t32c32n8v16);
	draw_quad(T_32|C_32|N_8|V_32, t32c32n8v32);
	draw_quad(T_32|C_32|N_16|V_8, t32c32n16v8);
	draw_quad(T_32|C_32|N_16|V_16, t32c32n16v16);
	draw_quad(T_32|C_32|N_16|V_32, t32c32n16v32);
	draw_quad(T_32|C_32|N_32|V_8, t32c32n32v8);
	draw_quad(T_32|C_32|N_32|V_16, t32c32n32v16);
	draw_quad(T_32|C_32|N_32|V_32, t32c32n32v32);

	/*=====================================================
	   Weight(8) + Color + Normal + Vertex
	=====================================================*/
	sceGuDisable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(W_8|C_16|N_8|V_8, w8c16n8v8);
	draw_quad(W_8|C_16|N_8|V_16, w8c16n8v16);
	draw_quad(W_8|C_16|N_8|V_32, w8c16n8v32);
	draw_quad(W_8|C_16|N_16|V_8, w8c16n16v8);
	draw_quad(W_8|C_16|N_16|V_16, w8c16n16v16);
	draw_quad(W_8|C_16|N_16|V_32, w8c16n16v32);
	draw_quad(W_8|C_16|N_32|V_8, w8c16n32v8);
	draw_quad(W_8|C_16|N_32|V_16, w8c16n32v16);
	draw_quad(W_8|C_16|N_32|V_32, w8c16n32v32);
	draw_quad(W_8|C_32|N_8|V_8, w8c32n8v8);
	draw_quad(W_8|C_32|N_8|V_16, w8c32n8v16);
	draw_quad(W_8|C_32|N_8|V_32, w8c32n8v32);
	draw_quad(W_8|C_32|N_16|V_8, w8c32n16v8);
	draw_quad(W_8|C_32|N_16|V_16, w8c32n16v16);
	draw_quad(W_8|C_32|N_16|V_32, w8c32n16v32);
	draw_quad(W_8|C_32|N_32|V_8, w8c32n32v8);
	draw_quad(W_8|C_32|N_32|V_16, w8c32n32v16);
	draw_quad(W_8|C_32|N_32|V_32, w8c32n32v32);
	draw_quad(W_16|C_16|N_8|V_8, w16c16n8v8);
	draw_quad(W_16|C_16|N_8|V_16, w16c16n8v16);
	draw_quad(W_16|C_16|N_8|V_32, w16c16n8v32);
	draw_quad(W_16|C_16|N_16|V_8, w16c16n16v8);
	draw_quad(W_16|C_16|N_16|V_16, w16c16n16v16);
	draw_quad(W_16|C_16|N_16|V_32, w16c16n16v32);
	draw_quad(W_16|C_16|N_32|V_8, w16c16n32v8);
	draw_quad(W_16|C_16|N_32|V_16, w16c16n32v16);
	draw_quad(W_16|C_16|N_32|V_32, w16c16n32v32);
	draw_quad(W_16|C_32|N_8|V_8, w16c32n8v8);
	draw_quad(W_16|C_32|N_8|V_16, w16c32n8v16);
	draw_quad(W_16|C_32|N_8|V_32, w16c32n8v32);
	draw_quad(W_16|C_32|N_16|V_8, w16c32n16v8);
	draw_quad(W_16|C_32|N_16|V_16, w16c32n16v16);
	draw_quad(W_16|C_32|N_16|V_32, w16c32n16v32);
	draw_quad(W_16|C_32|N_32|V_8, w16c32n32v8);
	draw_quad(W_16|C_32|N_32|V_16, w16c32n32v16);
	draw_quad(W_16|C_32|N_32|V_32, w16c32n32v32);
	draw_quad(W_32|C_16|N_8|V_8, w32c16n8v8);
	draw_quad(W_32|C_16|N_8|V_16, w32c16n8v16);
	draw_quad(W_32|C_16|N_8|V_32, w32c16n8v32);
	draw_quad(W_32|C_16|N_16|V_8, w32c16n16v8);
	draw_quad(W_32|C_16|N_16|V_16, w32c16n16v16);
	draw_quad(W_32|C_16|N_16|V_32, w32c16n16v32);
	draw_quad(W_32|C_16|N_32|V_8, w32c16n32v8);
	draw_quad(W_32|C_16|N_32|V_16, w32c16n32v16);
	draw_quad(W_32|C_16|N_32|V_32, w32c16n32v32);
	draw_quad(W_32|C_32|N_8|V_8, w32c32n8v8);
	draw_quad(W_32|C_32|N_8|V_16, w32c32n8v16);
	draw_quad(W_32|C_32|N_8|V_32, w32c32n8v32);
	draw_quad(W_32|C_32|N_16|V_8, w32c32n16v8);
	draw_quad(W_32|C_32|N_16|V_16, w32c32n16v16);
	draw_quad(W_32|C_32|N_16|V_32, w32c32n16v32);
	draw_quad(W_32|C_32|N_32|V_8, w32c32n32v8);
	draw_quad(W_32|C_32|N_32|V_16, w32c32n32v16);
	draw_quad(W_32|C_32|N_32|V_32, w32c32n32v32);

	/*=====================================================
	   Weight(8) + Texture + Normal + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(W_8|T_8|N_8|V_8, w8t8n8v8);
	draw_quad(W_8|T_8|N_8|V_16, w8t8n8v16);
	draw_quad(W_8|T_8|N_8|V_32, w8t8n8v32);
	draw_quad(W_8|T_8|N_16|V_8, w8t8n16v8);
	draw_quad(W_8|T_8|N_16|V_16, w8t8n16v16);
	draw_quad(W_8|T_8|N_16|V_32, w8t8n16v32);
	draw_quad(W_8|T_8|N_32|V_8, w8t8n32v8);
	draw_quad(W_8|T_8|N_32|V_16, w8t8n32v16);
	draw_quad(W_8|T_8|N_32|V_32, w8t8n32v32);
	draw_quad(W_8|T_16|N_8|V_8, w8t16n8v8);
	draw_quad(W_8|T_16|N_8|V_16, w8t16n8v16);
	draw_quad(W_8|T_16|N_8|V_32, w8t16n8v32);
	draw_quad(W_8|T_16|N_16|V_8, w8t16n16v8);
	draw_quad(W_8|T_16|N_16|V_16, w8t16n16v16);
	draw_quad(W_8|T_16|N_16|V_32, w8t16n16v32);
	draw_quad(W_8|T_16|N_32|V_8, w8t16n32v8);
	draw_quad(W_8|T_16|N_32|V_16, w8t16n32v16);
	draw_quad(W_8|T_16|N_32|V_32, w8t16n32v32);
	draw_quad(W_8|T_32|N_8|V_8, w8t32n8v8);
	draw_quad(W_8|T_32|N_8|V_16, w8t32n8v16);
	draw_quad(W_8|T_32|N_8|V_32, w8t32n8v32);
	draw_quad(W_8|T_32|N_16|V_8, w8t32n16v8);
	draw_quad(W_8|T_32|N_16|V_16, w8t32n16v16);
	draw_quad(W_8|T_32|N_16|V_32, w8t32n16v32);
	draw_quad(W_8|T_32|N_32|V_8, w8t32n32v8);
	draw_quad(W_8|T_32|N_32|V_16, w8t32n32v16);
	draw_quad(W_8|T_32|N_32|V_32, w8t32n32v32);
	draw_quad(W_16|T_8|N_8|V_8, w16t8n8v8);
	draw_quad(W_16|T_8|N_8|V_16, w16t8n8v16);
	draw_quad(W_16|T_8|N_8|V_32, w16t8n8v32);
	draw_quad(W_16|T_8|N_16|V_8, w16t8n16v8);
	draw_quad(W_16|T_8|N_16|V_16, w16t8n16v16);
	draw_quad(W_16|T_8|N_16|V_32, w16t8n16v32);
	draw_quad(W_16|T_8|N_32|V_8, w16t8n32v8);
	draw_quad(W_16|T_8|N_32|V_16, w16t8n32v16);
	draw_quad(W_16|T_8|N_32|V_32, w16t8n32v32);
	draw_quad(W_16|T_16|N_8|V_8, w16t16n8v8);
	draw_quad(W_16|T_16|N_8|V_16, w16t16n8v16);
	draw_quad(W_16|T_16|N_8|V_32, w16t16n8v32);
	draw_quad(W_16|T_16|N_16|V_8, w16t16n16v8);
	draw_quad(W_16|T_16|N_16|V_16, w16t16n16v16);
	draw_quad(W_16|T_16|N_16|V_32, w16t16n16v32);
	draw_quad(W_16|T_16|N_32|V_8, w16t16n32v8);
	draw_quad(W_16|T_16|N_32|V_16, w16t16n32v16);
	draw_quad(W_16|T_16|N_32|V_32, w16t16n32v32);
	draw_quad(W_16|T_32|N_8|V_8, w16t32n8v8);
	draw_quad(W_16|T_32|N_8|V_16, w16t32n8v16);
	draw_quad(W_16|T_32|N_8|V_32, w16t32n8v32);
	draw_quad(W_16|T_32|N_16|V_8, w16t32n16v8);
	draw_quad(W_16|T_32|N_16|V_16, w16t32n16v16);
	draw_quad(W_16|T_32|N_16|V_32, w16t32n16v32);
	draw_quad(W_16|T_32|N_32|V_8, w16t32n32v8);
	draw_quad(W_16|T_32|N_32|V_16, w16t32n32v16);
	draw_quad(W_16|T_32|N_32|V_32, w16t32n32v32);
	draw_quad(W_32|T_8|N_8|V_8, w32t8n8v8);
	draw_quad(W_32|T_8|N_8|V_16, w32t8n8v16);
	draw_quad(W_32|T_8|N_8|V_32, w32t8n8v32);
	draw_quad(W_32|T_8|N_16|V_8, w32t8n16v8);
	draw_quad(W_32|T_8|N_16|V_16, w32t8n16v16);
	draw_quad(W_32|T_8|N_16|V_32, w32t8n16v32);
	draw_quad(W_32|T_8|N_32|V_8, w32t8n32v8);
	draw_quad(W_32|T_8|N_32|V_16, w32t8n32v16);
	draw_quad(W_32|T_8|N_32|V_32, w32t8n32v32);
	draw_quad(W_32|T_16|N_8|V_8, w32t16n8v8);
	draw_quad(W_32|T_16|N_8|V_16, w32t16n8v16);
	draw_quad(W_32|T_16|N_8|V_32, w32t16n8v32);
	draw_quad(W_32|T_16|N_16|V_8, w32t16n16v8);
	draw_quad(W_32|T_16|N_16|V_16, w32t16n16v16);
	draw_quad(W_32|T_16|N_16|V_32, w32t16n16v32);
	draw_quad(W_32|T_16|N_32|V_8, w32t16n32v8);
	draw_quad(W_32|T_16|N_32|V_16, w32t16n32v16);
	draw_quad(W_32|T_16|N_32|V_32, w32t16n32v32);
	draw_quad(W_32|T_32|N_8|V_8, w32t32n8v8);
	draw_quad(W_32|T_32|N_8|V_16, w32t32n8v16);
	draw_quad(W_32|T_32|N_8|V_32, w32t32n8v32);
	draw_quad(W_32|T_32|N_16|V_8, w32t32n16v8);
	draw_quad(W_32|T_32|N_16|V_16, w32t32n16v16);
	draw_quad(W_32|T_32|N_16|V_32, w32t32n16v32);
	draw_quad(W_32|T_32|N_32|V_8, w32t32n32v8);
	draw_quad(W_32|T_32|N_32|V_16, w32t32n32v16);
	draw_quad(W_32|T_32|N_32|V_32, w32t32n32v32);

	/*=====================================================
	   Weight(8) + Texture + Color + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuDisable(SCEGU_LIGHTING);
	draw_quad(W_8|T_8|C_16|V_8, w8t8c16v8);
	draw_quad(W_8|T_8|C_16|V_16, w8t8c16v16);
	draw_quad(W_8|T_8|C_16|V_32, w8t8c16v32);
	draw_quad(W_8|T_8|C_32|V_8, w8t8c32v8);
	draw_quad(W_8|T_8|C_32|V_16, w8t8c32v16);
	draw_quad(W_8|T_8|C_32|V_32, w8t8c32v32);
	draw_quad(W_8|T_16|C_16|V_8, w8t16c16v8);
	draw_quad(W_8|T_16|C_16|V_16, w8t16c16v16);
	draw_quad(W_8|T_16|C_16|V_32, w8t16c16v32);
	draw_quad(W_8|T_16|C_32|V_8, w8t16c32v8);
	draw_quad(W_8|T_16|C_32|V_16, w8t16c32v16);
	draw_quad(W_8|T_16|C_32|V_32, w8t16c32v32);
	draw_quad(W_8|T_32|C_16|V_8, w8t32c16v8);
	draw_quad(W_8|T_32|C_16|V_16, w8t32c16v16);
	draw_quad(W_8|T_32|C_16|V_32, w8t32c16v32);
	draw_quad(W_8|T_32|C_32|V_8, w8t32c32v8);
	draw_quad(W_8|T_32|C_32|V_16, w8t32c32v16);
	draw_quad(W_8|T_32|C_32|V_32, w8t32c32v32);
	draw_quad(W_16|T_8|C_16|V_8, w16t8c16v8);
	draw_quad(W_16|T_8|C_16|V_16, w16t8c16v16);
	draw_quad(W_16|T_8|C_16|V_32, w16t8c16v32);
	draw_quad(W_16|T_8|C_32|V_8, w16t8c32v8);
	draw_quad(W_16|T_8|C_32|V_16, w16t8c32v16);
	draw_quad(W_16|T_8|C_32|V_32, w16t8c32v32);
	draw_quad(W_16|T_16|C_16|V_8, w16t16c16v8);
	draw_quad(W_16|T_16|C_16|V_16, w16t16c16v16);
	draw_quad(W_16|T_16|C_16|V_32, w16t16c16v32);
	draw_quad(W_16|T_16|C_32|V_8, w16t16c32v8);
	draw_quad(W_16|T_16|C_32|V_16, w16t16c32v16);
	draw_quad(W_16|T_16|C_32|V_32, w16t16c32v32);
	draw_quad(W_16|T_32|C_16|V_8, w16t32c16v8);
	draw_quad(W_16|T_32|C_16|V_16, w16t32c16v16);
	draw_quad(W_16|T_32|C_16|V_32, w16t32c16v32);
	draw_quad(W_16|T_32|C_32|V_8, w16t32c32v8);
	draw_quad(W_16|T_32|C_32|V_16, w16t32c32v16);
	draw_quad(W_16|T_32|C_32|V_32, w16t32c32v32);
	draw_quad(W_32|T_8|C_16|V_8, w32t8c16v8);
	draw_quad(W_32|T_8|C_16|V_16, w32t8c16v16);
	draw_quad(W_32|T_8|C_16|V_32, w32t8c16v32);
	draw_quad(W_32|T_8|C_32|V_8, w32t8c32v8);
	draw_quad(W_32|T_8|C_32|V_16, w32t8c32v16);
	draw_quad(W_32|T_8|C_32|V_32, w32t8c32v32);
	draw_quad(W_32|T_16|C_16|V_8, w32t16c16v8);
	draw_quad(W_32|T_16|C_16|V_16, w32t16c16v16);
	draw_quad(W_32|T_16|C_16|V_32, w32t16c16v32);
	draw_quad(W_32|T_16|C_32|V_8, w32t16c32v8);
	draw_quad(W_32|T_16|C_32|V_16, w32t16c32v16);
	draw_quad(W_32|T_16|C_32|V_32, w32t16c32v32);
	draw_quad(W_32|T_32|C_16|V_8, w32t32c16v8);
	draw_quad(W_32|T_32|C_16|V_16, w32t32c16v16);
	draw_quad(W_32|T_32|C_16|V_32, w32t32c16v32);
	draw_quad(W_32|T_32|C_32|V_8, w32t32c32v8);
	draw_quad(W_32|T_32|C_32|V_16, w32t32c32v16);
	draw_quad(W_32|T_32|C_32|V_32, w32t32c32v32);

	/*=====================================================
	   Weight(8) + Texture + Color + Normal + Vertex
	=====================================================*/
	sceGuEnable(SCEGU_TEXTURE);
	sceGuEnable(SCEGU_LIGHTING);
	draw_quad(W_8|T_8|C_16|N_8|V_8, w8t8c16n8v8);
	draw_quad(W_8|T_8|C_16|N_8|V_16, w8t8c16n8v16);
	draw_quad(W_8|T_8|C_16|N_8|V_32, w8t8c16n8v32);
	draw_quad(W_8|T_8|C_16|N_16|V_8, w8t8c16n16v8);
	draw_quad(W_8|T_8|C_16|N_16|V_16, w8t8c16n16v16);
	draw_quad(W_8|T_8|C_16|N_16|V_32, w8t8c16n16v32);
	draw_quad(W_8|T_8|C_16|N_32|V_8, w8t8c16n32v8);
	draw_quad(W_8|T_8|C_16|N_32|V_16, w8t8c16n32v16);
	draw_quad(W_8|T_8|C_16|N_32|V_32, w8t8c16n32v32);
	draw_quad(W_8|T_8|C_32|N_8|V_8, w8t8c32n8v8);
	draw_quad(W_8|T_8|C_32|N_8|V_16, w8t8c32n8v16);
	draw_quad(W_8|T_8|C_32|N_8|V_32, w8t8c32n8v32);
	draw_quad(W_8|T_8|C_32|N_16|V_8, w8t8c32n16v8);
	draw_quad(W_8|T_8|C_32|N_16|V_16, w8t8c32n16v16);
	draw_quad(W_8|T_8|C_32|N_16|V_32, w8t8c32n16v32);
	draw_quad(W_8|T_8|C_32|N_32|V_8, w8t8c32n32v8);
	draw_quad(W_8|T_8|C_32|N_32|V_16, w8t8c32n32v16);
	draw_quad(W_8|T_8|C_32|N_32|V_32, w8t8c32n32v32);
	draw_quad(W_8|T_16|C_16|N_8|V_8, w8t16c16n8v8);
	draw_quad(W_8|T_16|C_16|N_8|V_16, w8t16c16n8v16);
	draw_quad(W_8|T_16|C_16|N_8|V_32, w8t16c16n8v32);
	draw_quad(W_8|T_16|C_16|N_16|V_8, w8t16c16n16v8);
	draw_quad(W_8|T_16|C_16|N_16|V_16, w8t16c16n16v16);
	draw_quad(W_8|T_16|C_16|N_16|V_32, w8t16c16n16v32);
	draw_quad(W_8|T_16|C_16|N_32|V_8, w8t16c16n32v8);
	draw_quad(W_8|T_16|C_16|N_32|V_16, w8t16c16n32v16);
	draw_quad(W_8|T_16|C_16|N_32|V_32, w8t16c16n32v32);
	draw_quad(W_8|T_16|C_32|N_8|V_8, w8t16c32n8v8);
	draw_quad(W_8|T_16|C_32|N_8|V_16, w8t16c32n8v16);
	draw_quad(W_8|T_16|C_32|N_8|V_32, w8t16c32n8v32);
	draw_quad(W_8|T_16|C_32|N_16|V_8, w8t16c32n16v8);
	draw_quad(W_8|T_16|C_32|N_16|V_16, w8t16c32n16v16);
	draw_quad(W_8|T_16|C_32|N_16|V_32, w8t16c32n16v32);
	draw_quad(W_8|T_16|C_32|N_32|V_8, w8t16c32n32v8);
	draw_quad(W_8|T_16|C_32|N_32|V_16, w8t16c32n32v16);
	draw_quad(W_8|T_16|C_32|N_32|V_32, w8t16c32n32v32);
	draw_quad(W_8|T_32|C_16|N_8|V_8, w8t32c16n8v8);
	draw_quad(W_8|T_32|C_16|N_8|V_16, w8t32c16n8v16);
	draw_quad(W_8|T_32|C_16|N_8|V_32, w8t32c16n8v32);
	draw_quad(W_8|T_32|C_16|N_16|V_8, w8t32c16n16v8);
	draw_quad(W_8|T_32|C_16|N_16|V_16, w8t32c16n16v16);
	draw_quad(W_8|T_32|C_16|N_16|V_32, w8t32c16n16v32);
	draw_quad(W_8|T_32|C_16|N_32|V_8, w8t32c16n32v8);
	draw_quad(W_8|T_32|C_16|N_32|V_16, w8t32c16n32v16);
	draw_quad(W_8|T_32|C_16|N_32|V_32, w8t32c16n32v32);
	draw_quad(W_8|T_32|C_32|N_8|V_8, w8t32c32n8v8);
	draw_quad(W_8|T_32|C_32|N_8|V_16, w8t32c32n8v16);
	draw_quad(W_8|T_32|C_32|N_8|V_32, w8t32c32n8v32);
	draw_quad(W_8|T_32|C_32|N_16|V_8, w8t32c32n16v8);
	draw_quad(W_8|T_32|C_32|N_16|V_16, w8t32c32n16v16);
	draw_quad(W_8|T_32|C_32|N_16|V_32, w8t32c32n16v32);
	draw_quad(W_8|T_32|C_32|N_32|V_8, w8t32c32n32v8);
	draw_quad(W_8|T_32|C_32|N_32|V_16, w8t32c32n32v16);
	draw_quad(W_8|T_32|C_32|N_32|V_32, w8t32c32n32v32);
	draw_quad(W_16|T_8|C_16|N_8|V_8, w16t8c16n8v8);
	draw_quad(W_16|T_8|C_16|N_8|V_16, w16t8c16n8v16);
	draw_quad(W_16|T_8|C_16|N_8|V_32, w16t8c16n8v32);
	draw_quad(W_16|T_8|C_16|N_16|V_8, w16t8c16n16v8);
	draw_quad(W_16|T_8|C_16|N_16|V_16, w16t8c16n16v16);
	draw_quad(W_16|T_8|C_16|N_16|V_32, w16t8c16n16v32);
	draw_quad(W_16|T_8|C_16|N_32|V_8, w16t8c16n32v8);
	draw_quad(W_16|T_8|C_16|N_32|V_16, w16t8c16n32v16);
	draw_quad(W_16|T_8|C_16|N_32|V_32, w16t8c16n32v32);
	draw_quad(W_16|T_8|C_32|N_8|V_8, w16t8c32n8v8);
	draw_quad(W_16|T_8|C_32|N_8|V_16, w16t8c32n8v16);
	draw_quad(W_16|T_8|C_32|N_8|V_32, w16t8c32n8v32);
	draw_quad(W_16|T_8|C_32|N_16|V_8, w16t8c32n16v8);
	draw_quad(W_16|T_8|C_32|N_16|V_16, w16t8c32n16v16);
	draw_quad(W_16|T_8|C_32|N_16|V_32, w16t8c32n16v32);
	draw_quad(W_16|T_8|C_32|N_32|V_8, w16t8c32n32v8);
	draw_quad(W_16|T_8|C_32|N_32|V_16, w16t8c32n32v16);
	draw_quad(W_16|T_8|C_32|N_32|V_32, w16t8c32n32v32);
	draw_quad(W_16|T_16|C_16|N_8|V_8, w16t16c16n8v8);
	draw_quad(W_16|T_16|C_16|N_8|V_16, w16t16c16n8v16);
	draw_quad(W_16|T_16|C_16|N_8|V_32, w16t16c16n8v32);
	draw_quad(W_16|T_16|C_16|N_16|V_8, w16t16c16n16v8);
	draw_quad(W_16|T_16|C_16|N_16|V_16, w16t16c16n16v16);
	draw_quad(W_16|T_16|C_16|N_16|V_32, w16t16c16n16v32);
	draw_quad(W_16|T_16|C_16|N_32|V_8, w16t16c16n32v8);
	draw_quad(W_16|T_16|C_16|N_32|V_16, w16t16c16n32v16);
	draw_quad(W_16|T_16|C_16|N_32|V_32, w16t16c16n32v32);
	draw_quad(W_16|T_16|C_32|N_8|V_8, w16t16c32n8v8);
	draw_quad(W_16|T_16|C_32|N_8|V_16, w16t16c32n8v16);
	draw_quad(W_16|T_16|C_32|N_8|V_32, w16t16c32n8v32);
	draw_quad(W_16|T_16|C_32|N_16|V_8, w16t16c32n16v8);
	draw_quad(W_16|T_16|C_32|N_16|V_16, w16t16c32n16v16);
	draw_quad(W_16|T_16|C_32|N_16|V_32, w16t16c32n16v32);
	draw_quad(W_16|T_16|C_32|N_32|V_8, w16t16c32n32v8);
	draw_quad(W_16|T_16|C_32|N_32|V_16, w16t16c32n32v16);
	draw_quad(W_16|T_16|C_32|N_32|V_32, w16t16c32n32v32);
	draw_quad(W_16|T_32|C_16|N_8|V_8, w16t32c16n8v8);
	draw_quad(W_16|T_32|C_16|N_8|V_16, w16t32c16n8v16);
	draw_quad(W_16|T_32|C_16|N_8|V_32, w16t32c16n8v32);
	draw_quad(W_16|T_32|C_16|N_16|V_8, w16t32c16n16v8);
	draw_quad(W_16|T_32|C_16|N_16|V_16, w16t32c16n16v16);
	draw_quad(W_16|T_32|C_16|N_16|V_32, w16t32c16n16v32);
	draw_quad(W_16|T_32|C_16|N_32|V_8, w16t32c16n32v8);
	draw_quad(W_16|T_32|C_16|N_32|V_16, w16t32c16n32v16);
	draw_quad(W_16|T_32|C_16|N_32|V_32, w16t32c16n32v32);
	draw_quad(W_16|T_32|C_32|N_8|V_8, w16t32c32n8v8);
	draw_quad(W_16|T_32|C_32|N_8|V_16, w16t32c32n8v16);
	draw_quad(W_16|T_32|C_32|N_8|V_32, w16t32c32n8v32);
	draw_quad(W_16|T_32|C_32|N_16|V_8, w16t32c32n16v8);
	draw_quad(W_16|T_32|C_32|N_16|V_16, w16t32c32n16v16);
	draw_quad(W_16|T_32|C_32|N_16|V_32, w16t32c32n16v32);
	draw_quad(W_16|T_32|C_32|N_32|V_8, w16t32c32n32v8);
	draw_quad(W_16|T_32|C_32|N_32|V_16, w16t32c32n32v16);
	draw_quad(W_16|T_32|C_32|N_32|V_32, w16t32c32n32v32);
	draw_quad(W_32|T_8|C_16|N_8|V_8, w32t8c16n8v8);
	draw_quad(W_32|T_8|C_16|N_8|V_16, w32t8c16n8v16);
	draw_quad(W_32|T_8|C_16|N_8|V_32, w32t8c16n8v32);
	draw_quad(W_32|T_8|C_16|N_16|V_8, w32t8c16n16v8);
	draw_quad(W_32|T_8|C_16|N_16|V_16, w32t8c16n16v16);
	draw_quad(W_32|T_8|C_16|N_16|V_32, w32t8c16n16v32);
	draw_quad(W_32|T_8|C_16|N_32|V_8, w32t8c16n32v8);
	draw_quad(W_32|T_8|C_16|N_32|V_16, w32t8c16n32v16);
	draw_quad(W_32|T_8|C_16|N_32|V_32, w32t8c16n32v32);
	draw_quad(W_32|T_8|C_32|N_8|V_8, w32t8c32n8v8);
	draw_quad(W_32|T_8|C_32|N_8|V_16, w32t8c32n8v16);
	draw_quad(W_32|T_8|C_32|N_8|V_32, w32t8c32n8v32);
	draw_quad(W_32|T_8|C_32|N_16|V_8, w32t8c32n16v8);
	draw_quad(W_32|T_8|C_32|N_16|V_16, w32t8c32n16v16);
	draw_quad(W_32|T_8|C_32|N_16|V_32, w32t8c32n16v32);
	draw_quad(W_32|T_8|C_32|N_32|V_8, w32t8c32n32v8);
	draw_quad(W_32|T_8|C_32|N_32|V_16, w32t8c32n32v16);
	draw_quad(W_32|T_8|C_32|N_32|V_32, w32t8c32n32v32);
	draw_quad(W_32|T_16|C_16|N_8|V_8, w32t16c16n8v8);
	draw_quad(W_32|T_16|C_16|N_8|V_16, w32t16c16n8v16);
	draw_quad(W_32|T_16|C_16|N_8|V_32, w32t16c16n8v32);
	draw_quad(W_32|T_16|C_16|N_16|V_8, w32t16c16n16v8);
	draw_quad(W_32|T_16|C_16|N_16|V_16, w32t16c16n16v16);
	draw_quad(W_32|T_16|C_16|N_16|V_32, w32t16c16n16v32);
	draw_quad(W_32|T_16|C_16|N_32|V_8, w32t16c16n32v8);
	draw_quad(W_32|T_16|C_16|N_32|V_16, w32t16c16n32v16);
	draw_quad(W_32|T_16|C_16|N_32|V_32, w32t16c16n32v32);
	draw_quad(W_32|T_16|C_32|N_8|V_8, w32t16c32n8v8);
	draw_quad(W_32|T_16|C_32|N_8|V_16, w32t16c32n8v16);
	draw_quad(W_32|T_16|C_32|N_8|V_32, w32t16c32n8v32);
	draw_quad(W_32|T_16|C_32|N_16|V_8, w32t16c32n16v8);
	draw_quad(W_32|T_16|C_32|N_16|V_16, w32t16c32n16v16);
	draw_quad(W_32|T_16|C_32|N_16|V_32, w32t16c32n16v32);
	draw_quad(W_32|T_16|C_32|N_32|V_8, w32t16c32n32v8);
	draw_quad(W_32|T_16|C_32|N_32|V_16, w32t16c32n32v16);
	draw_quad(W_32|T_16|C_32|N_32|V_32, w32t16c32n32v32);
	draw_quad(W_32|T_32|C_16|N_8|V_8, w32t32c16n8v8);
	draw_quad(W_32|T_32|C_16|N_8|V_16, w32t32c16n8v16);
	draw_quad(W_32|T_32|C_16|N_8|V_32, w32t32c16n8v32);
	draw_quad(W_32|T_32|C_16|N_16|V_8, w32t32c16n16v8);
	draw_quad(W_32|T_32|C_16|N_16|V_16, w32t32c16n16v16);
	draw_quad(W_32|T_32|C_16|N_16|V_32, w32t32c16n16v32);
	draw_quad(W_32|T_32|C_16|N_32|V_8, w32t32c16n32v8);
	draw_quad(W_32|T_32|C_16|N_32|V_16, w32t32c16n32v16);
	draw_quad(W_32|T_32|C_16|N_32|V_32, w32t32c16n32v32);
	draw_quad(W_32|T_32|C_32|N_8|V_8, w32t32c32n8v8);
	draw_quad(W_32|T_32|C_32|N_8|V_16, w32t32c32n8v16);
	draw_quad(W_32|T_32|C_32|N_8|V_32, w32t32c32n8v32);
	draw_quad(W_32|T_32|C_32|N_16|V_8, w32t32c32n16v8);
	draw_quad(W_32|T_32|C_32|N_16|V_16, w32t32c32n16v16);
	draw_quad(W_32|T_32|C_32|N_16|V_32, w32t32c32n16v32);
	draw_quad(W_32|T_32|C_32|N_32|V_8, w32t32c32n32v8);
	draw_quad(W_32|T_32|C_32|N_32|V_16, w32t32c32n32v16);
	draw_quad(W_32|T_32|C_32|N_32|V_32, w32t32c32n32v32);

	sceGumPopMatrix();
}
