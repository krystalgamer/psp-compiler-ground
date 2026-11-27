/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#pragma interface "rodata"
#include "common.h"

extern "C" void *memset(void *, int, unsigned int);
extern "C" int sceRtcGetCurrentTick(unsigned long long *tick);
extern "C" char *gameGetCntx(void);

namespace Net {
struct EtherAddress {
	unsigned char data[6];
	EtherAddress() { memset(data, 0, sizeof(data)); }
	void Reset() { memset(data, 0, sizeof(data)); }
};
}

namespace SaruNet {
struct Name8 {
	char c[8];
	void Reset() { memset(c, 0, sizeof(c)); }
};

class WaiWaiData {
public:
	char f0;
	Net::EtherAddress addr;
	char _p7;
	char f8[0x304];
	unsigned int f30C_0 : 1;
	unsigned int error_petit_game : 1;
	void Reset();
};

class GayaData {
public:
	void Reset();
};

class ResidentData {
public:
	Name8 name;
	Net::EtherAddress addr;
	signed char is_server;
	char _f;
	WaiWaiData waiwai;
	static ResidentData _instance;
	static ResidentData *Get_Instance_p();
	void Reset();
};

void WaiWaiData::Reset()
{
	addr.Reset();
	memset(f8, 0, sizeof(f8));
	*(int *)((char *)this + 0x30C) = 0;
}

void GayaData::Reset()
{
}

ResidentData *ResidentData::Get_Instance_p()
{
	return &_instance;
}

void ResidentData::Reset()
{
	unsigned long long tick;
	addr.Reset();
	name.Reset();
	is_server = *(int *)(gameGetCntx() + 0x74) == 0;
	waiwai.Reset();
	sceRtcGetCurrentTick(&tick);
}
}

extern "C" bool SaruNet_ResidentData__Is_Server(void)
{
	return SaruNet::ResidentData::Get_Instance_p()->is_server != 0;
}

extern "C" int SaruNet_ResidentData_WaiWai__Is_ErrorPetitGame(void)
{
	return SaruNet::ResidentData::Get_Instance_p()->waiwai.error_petit_game;
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_resident_data", _Z41__static_initialization_and_destruction_0ii_54B18);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_resident_data", _GLOBAL__I__ZN7SaruNet12ResidentData9_instanceE);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_resident_data", _ZN7SaruNet12ResidentDataC1Ev);
}
