/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#pragma interface "rodata"
#include "common.h"

extern "C" char *strncpy(char *, const char *, unsigned int);

namespace SaruNet {
struct Name8 {
	char c[8];
};
class ResidentData {
public:
	Name8 name;
	char addr[6];
	signed char is_server;
	static ResidentData *Get_Instance_p();
};
}

namespace Net {
namespace Param {
class GameStartup {
public:
	int f0, f4, f8;
	int fC[8];
	char f2C;
	int f30, f34, f38, f3C, f40, f44, f48, f4C, f50, f54;
	char f58[12];
	char f64;
	SaruNet::Name8 f65;
	void Reset();
};
}
}

namespace SaruNet {
namespace Param {
class GameStartup : public Net::Param::GameStartup {
public:
	void Reset();
};

void GameStartup::Reset()
{
	ResidentData *rd;
	Net::Param::GameStartup::Reset();
	f8 = 2;
	f0 = 16;
	f4 = 16;
	f30 = 10;
	strncpy(f58, "PipoSaru", 11);
	f2C = 1;
	rd = ResidentData::Get_Instance_p();
	f64 = rd->is_server != 0;
	f65 = rd->name;
}
}
}
