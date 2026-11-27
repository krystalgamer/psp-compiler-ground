/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#pragma interface "rodata"
#include "common.h"

extern "C" {
int consPrintf(const char *fmt, ...);
int sceNetInit(int poolsize, int calloutprio, int calloutstack, int netintrprio, int netintrstack);
int sceNetAdhocInit(void);
int sceNetAdhocctlInit(int stacksize, int priority, void *adhoc_id);
extern int adhoc_id;
}

#define PSPNET_POOLSIZE 0x80000
#define PSPNET_CALLOUT_PRIORITY 0x11
#define PSPNET_CALLOUT_STACKSIZE 0x1000
#define PSPNET_NETINTR_PRIORITY 0x11
#define PSPNET_NETINTR_STACKSIZE 0x1000
#define PSPNET_ADHOCCTL_STACKSIZE 0x2000
#define PSPNET_ADHOCCTL_PRIORITY 0x30
#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/net/network_system.cc", __LINE__, __FUNCTION__, #e)

namespace Net {
class System {
public:
	System *Init();
	~System();
};

System *System::Init()
{
#line 77
	cassert(sceNetInit( PSPNET_POOLSIZE, PSPNET_CALLOUT_PRIORITY, PSPNET_CALLOUT_STACKSIZE, PSPNET_NETINTR_PRIORITY, PSPNET_NETINTR_STACKSIZE) == 0);
	consPrintf("network : pspnet initialized.\n");
#line 81
	cassert(sceNetAdhocInit() == 0);
	consPrintf("network : adhoc initialized.\n");
#line 86
	cassert(sceNetAdhocctlInit( PSPNET_ADHOCCTL_STACKSIZE, PSPNET_ADHOCCTL_PRIORITY, &adhoc_id) == 0);
	consPrintf("network : adhocctl initialized.\n");
	return this;
}
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", _ZN3Net6SystemD2Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", _ZN3Net6SystemD1Ev);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_001071E8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_0010720C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_0010722C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_0010724C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_0010726C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_0010728C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_system", D_001072AC);
}
