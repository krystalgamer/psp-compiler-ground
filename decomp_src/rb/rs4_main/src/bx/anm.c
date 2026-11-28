/* lang: c++ */
/* cflags: -Os -fno-exceptions */
#include "common.h"
struct InstDat;
struct TBxAnmInitAssign;
namespace B2A {
class B2aFile;
class Manager {
public:
	B2aFile *file;
	~Manager();
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
	B2aFile(InstDat *, int, int, TBxAnmInitAssign **);
	void *data;
	int size;
	~B2aFile();
	void ReAssign();
};
void Calc(Manager *);
Manager *CreateB2A(B2aFile *);
void Start(Manager *);
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

int sceKernelGetGPI(void);
B2A::Manager *bxAnmInitEx(void *, int);
B2A::Manager *bxAnmInit(void *p)
{
	if (sceKernelGetGPI() & 1)
		consPrintf((const char *)&D_00108E74, __FUNCTION__);
	return bxAnmInitEx(p, 0);
}

extern unsigned char D_00108E98, D_00108EA0;
B2A::Manager *bxAnmInitEx(void *p, int n)
{
	B2A::Manager *m;
	if (sceKernelGetGPI() & 1)
		consPrintf((const char *)&D_00108E98, __FUNCTION__);
	m = B2A::CreateB2A(new B2A::B2aFile((InstDat *)p, n, 0, 0));
	B2A::Start(m);
	if (sceKernelGetGPI() & 1)
		consPrintf((const char *)&D_00108EA0);
	return m;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108E98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/anm", D_00108EA0);

B2A::Manager *bxAnmInitAssign(void *p, int n, int c, TBxAnmInitAssign **a)
{
	B2A::Manager *m;
	if (sceKernelGetGPI() & 1)
		consPrintf((const char *)&D_00108E98, __FUNCTION__);
	m = B2A::CreateB2A(new B2A::B2aFile((InstDat *)p, n, c, a));
	B2A::Start(m);
	if (sceKernelGetGPI() & 1)
		consPrintf((const char *)&D_00108EA0);
	return m;
}

}
template <class T> inline void SafeDelete(T *&p) { delete p; }
extern "C" {
void bxAnmTerm(B2A::Manager *m)
{
	SafeDelete(m->file);
	SafeDelete(m);
}

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
