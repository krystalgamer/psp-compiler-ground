/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct InstDat;
struct bxAnm;

extern "C" {
void _memFree(void *p, const char *file, int line);
InstDat *resGetDatLocal(int a, int b);
bxAnm *bxAnmInitEx(InstDat *d, int entry);
void bxAnmTerm(bxAnm *a);
int bxAnmExec(bxAnm *a);
void bxAnmDraw(bxAnm *a, void *m, void *attr);
int gameGetGameMode(void);
int gameGetEntry(void);
}

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

namespace Cop {
class DrawAttribute {
public:
	char _0[0x30];
	void Reset();
};
class Matrix4x4;
}

class Anim2D : public Object {
public:
	int _4[3];
	Cop::DrawAttribute attr;
	bxAnm *anm;
	signed char entry;
	signed char group;
	short id;
	signed char visible;
	Anim2D();
	virtual ~Anim2D();
	void Unload();
	void Load(int id_, int group_);
	void Reload();
	int Exec();
	void Draw(Cop::Matrix4x4 &m);
};

Anim2D::Anim2D()
{
	attr.Reset();
	anm = 0;
	entry = gameGetGameMode() == 1 ? gameGetEntry() : 0;
	visible = 1;
}

Anim2D::~Anim2D()
{
	Unload();
}

void Anim2D::Unload()
{
	if (anm) {
		bxAnmTerm(anm);
		anm = 0;
	}
}

void Anim2D::Load(int id_, int group_)
{
	Unload();
	group = group_;
	id = id_;
	InstDat *d = resGetDatLocal(group_, id_);
	if (d)
		anm = bxAnmInitEx(d, entry);
}

void Anim2D::Reload()
{
	if (anm)
		Load(id, group);
}

int Anim2D::Exec()
{
	int r = 0;
	if (anm)
		r = bxAnmExec(anm);
	return r;
}

void Anim2D::Draw(Cop::Matrix4x4 &m)
{
	bxAnm *a = anm;
	if (a && visible)
		bxAnmDraw(a, &m, &attr);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim", _ZTVN2Ys6Anim2DE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim", D_00104B10); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim", _ZTIN2Ys6Anim2DE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim", _ZTSN2Ys6Anim2DE); }
