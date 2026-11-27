/* lang: c++ */
/* cflags: -Os */
#include "common.h"
namespace B2A {
class Manager {
public:
	float GetFrame();
	void SetFrame(float);
	float GetEndFrame();
	void SetEndFrame(float);
	int GetLoop();
	void SetLoop(int);
	int GetPause();
	void SetPause(int);
	float GetSpeed();
	void SetSpeed(float);
};
class B2aFile {
public:
	void ReAssign();
};
void Calc(Manager *);
}
void GpPrim_Init();
extern "C" {

extern unsigned char D_00108E74;
void consPrintf(const char *, ...);
void bxInit(void)
{
	consPrintf((const char *)&D_00108E74, __FUNCTION__);
	GpPrim_Init();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108E74);

void bxTerm(void)
{
	consPrintf((const char *)&D_00108E74, __FUNCTION__);
}

void bxCleanup(void)
{
	GpPrim_Init();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmInitEx);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108E98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108EA0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmInitAssign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmTerm);

int bxAnmExec(B2A::Manager *m)
{
	B2A::Calc(m);
	return *(int *)((char *)m + 0x5C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", bxAnmDraw);

void bxAnmSetFrame(B2A::Manager *m, float v)
{
	m->SetFrame(v);
}

float bxAnmGetFrame(B2A::Manager *m)
{
	return m->GetFrame();
}

void bxAnmSetLoop(B2A::Manager *m, int v)
{
	m->SetLoop(v);
}

int bxAnmGetLoop(B2A::Manager *m)
{
	return m->GetLoop();
}

void bxAnmSetPause(B2A::Manager *m, int v)
{
	m->SetPause(v);
}

int bxAnmGetPause(B2A::Manager *m)
{
	return m->GetPause();
}

void bxAnmSetSpeed(B2A::Manager *m, float v)
{
	m->SetSpeed(v);
}

float bxAnmGetSpeed(B2A::Manager *m)
{
	return m->GetSpeed();
}

float bxAnmGetEndFrame(B2A::Manager *m)
{
	return m->GetEndFrame();
}

void bxAnmSetEndFrame(B2A::Manager *m, float v)
{
	m->SetEndFrame(v);
}

void bxAnmTexReAssign(B2A::B2aFile **f)
{
	(*f)->ReAssign();
}

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
