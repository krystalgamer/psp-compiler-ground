/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

enum NetConnectivityType { NetConnectivity0, NetConnectivity1, NetConnectivity2 };

extern "C" {
void _memFree(void *p, const char *file, int line);
}

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace Net {
namespace Param {
class NetworkCreate {
public:
	char _0[0x70];
	NetworkCreate(int a, unsigned int port, NetConnectivityType type);
};
}

class Network : public Ys::Object {
public:
	virtual ~Network();
	Network *Init(const Param::NetworkCreate &p, int client);
};
}

namespace SaruNet {
class ResidentData {
public:
	char _0[0xE];
	signed char is_server;
	static ResidentData *Get_Instance_p();
};

class Network : public Net::Network {
public:
	virtual ~Network();
	Network *Init(int a);
};

Network *Network::Init(int a)
{
	int client = ResidentData::Get_Instance_p()->is_server == 0;
	Net::Param::NetworkCreate param(a, 0x8AE, NetConnectivity2);
	Net::Network::Init(param, client);
	return this;
}

Network::~Network()
{
}

}

extern "C" const char D_00107ABC[] = "";


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", _ZTVN7SaruNet7NetworkE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107AC8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", _ZTIN7SaruNet7NetworkE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", _ZTSN7SaruNet7NetworkE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107B00); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107B2C); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107B48); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107B60); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107B8C); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107BB0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107BD8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107BFC); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107C24); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107C40); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107C6C); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107C90); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107CB8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107CD8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", _ZTVN7SaruNet4GameE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", D_00107CF8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", _ZTIN7SaruNet4GameE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network", _ZTSN7SaruNet4GameE); }
