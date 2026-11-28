/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void *memset(void *, int, unsigned int);
extern "C" int NetSetDefaultInitializeParams(void *p);

enum NetConnectivityType { NetConnectivity_Default = 2 };

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace Net {
namespace Param {
class NetworkCreate {
public:
	int a;
	char params[0x60];
	NetConnectivityType type;
	void Reset();
	NetworkCreate();
	NetworkCreate(int a_, unsigned int b_, NetConnectivityType t);
};

void NetworkCreate::Reset()
{
	NetSetDefaultInitializeParams(params);
	type = NetConnectivity_Default;
}

NetworkCreate::NetworkCreate()
{
	Reset();
}

NetworkCreate::NetworkCreate(int a_, unsigned int b_, NetConnectivityType t)
{
	Reset();
	*(int *)(params + 0xC) = a_;
	a = b_;
	type = t;
}

class GameStartup : public Ys::Object {
public:
	int f0, f4, f8;
	int fC[8];
	char f2C;
	int f30, f34, f38, f3C, f40, f44, f48, f4C, f50, f54;
	char f58[12];
	char f64;
	char f65[8];
	void Reset();
	GameStartup *Clone();
};

void GameStartup::Reset()
{
	f0 = 250;
	f4 = 250;
	f8 = 2;
	f34 = 2;
	fC[0] = 0;
	fC[1] = 0;
	fC[2] = 0;
	fC[3] = 0;
	fC[4] = 0;
	fC[5] = 0;
	fC[6] = 0;
	fC[7] = 0;
	f2C = 0;
	f48 = 0;
	f4C = 0;
	f30 = 0;
	f38 = 0;
	f3C = 0;
	f40 = 0;
	f44 = 0;
	f50 = 0;
	f54 = 0;
	memset(f58, 0, sizeof(f58));
	f64 = 1;
	memset(f65, 0, sizeof(f65));
}

GameStartup *GameStartup::Clone()
{
	GameStartup *n = new GameStartup;
	n->Reset();
	*n = *this;
	return n;
}
}
}
