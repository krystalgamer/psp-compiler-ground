#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/data", draw_quad);

typedef struct {
	struct { float x, y, z; } rot;
	struct { float x, y, z; } pos;
	float speed;
} QPOS;

extern QPOS qpos[576];

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/data", InitData);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/data", DrawData);
