/* lang: c++ */
/* cflags: -Os */
#include "common.h"

struct ScePspFMatrix4;
struct InstDat;
struct tagGpTEXDESC { int _[14]; };

extern "C" int GpSetGIM(tagGpTEXDESC *tex, void *gim, int size);
extern "C" int consPrintf(const char *fmt, ...);
void GpPrim_SetTex(tagGpTEXDESC *tex);
void GpPrim_SetMatrix(ScePspFMatrix4 *m);
void GpPrim_SetCenter(float x, float y);
void GpPrim_SetWH(int w, int h);
void GpPrim_SetCol(int col);
void GpPrim_SetNext();

extern const char D_0010900C[], D_00109028[], D_0010903C[], D_00109058[];

namespace B2A {
struct TM2Parts {
	float x, y;			/* 0x00 */
	int _08[2];
	float w, h;			/* 0x10 */
	int _18[8];
	tagGpTEXDESC tex;		/* 0x38 */
	void *gim;			/* 0x70 */
	int gimSize;			/* 0x74 */

	TM2Parts();
	~TM2Parts();
	void Assign(InstDat *inst, int a, int b, const char *name, int c);
	void ReAssign();
	void Draw(ScePspFMatrix4 *m, int col);
};

TM2Parts::TM2Parts()
{
	w = 0;
	h = 0;
}

TM2Parts::~TM2Parts()
{
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", _ZN3B2A8TM2Parts6AssignEP7InstDatiiPKci);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", D_0010900C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", D_00109028);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", D_0010903C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", D_00109058);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", D_00109060);

void TM2Parts::ReAssign()
{
	if (!GpSetGIM(&tex, gim, gimSize)) {
		consPrintf(D_0010900C);
		consPrintf(D_0010903C, D_00109028, 62, __FUNCTION__, D_00109058);
	}
}

void TM2Parts::Draw(ScePspFMatrix4 *m, int col)
{
	GpPrim_SetTex(&tex);
	GpPrim_SetMatrix(m);
	GpPrim_SetCenter(-x, -y);
	GpPrim_SetWH((int)w, (int)h);
	GpPrim_SetCol(col);
	GpPrim_SetNext();
}
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/tm2parts", D_00109088);
