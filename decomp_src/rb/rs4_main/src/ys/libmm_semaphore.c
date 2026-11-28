/* lang: c++ */
/* cflags: -Os */
#include "common.h"

struct SceKernelSemaInfo { int size; char _[0x34]; };
extern "C" int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
extern "C" int sceKernelDeleteSema(int id);
extern "C" int sceKernelReferSemaStatus(int id, SceKernelSemaInfo *info);
extern "C" void consPrintf(const char *fmt, ...);
extern "C" void _memFree(void *p, const char *file, int line);

#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/ys/libmm_semaphore.cc", __LINE__, __FUNCTION__, #e)

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace MetaMagic {
class Semaphore : public Ys::Object {
	int id;
public:
	Semaphore(const char *name, int init, int max, unsigned int attr);
	virtual ~Semaphore();
	void Get_Status(SceKernelSemaInfo &info) const;
};

Semaphore::Semaphore(const char *name, int init, int max, unsigned int attr)
{
	id = sceKernelCreateSema(name, attr, init, max, 0);
#line 34
	cassert(id >= 0);
}

Semaphore::~Semaphore()
{
	if (id >= 0)
		sceKernelDeleteSema(id);
}

void Semaphore::Get_Status(SceKernelSemaInfo &info) const
{
	info.size = sizeof(SceKernelSemaInfo);
	int tid = id;
	sceKernelReferSemaStatus(tid, &info);
}
}

