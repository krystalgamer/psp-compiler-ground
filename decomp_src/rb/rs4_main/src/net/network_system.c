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
int sceNetAdhocctlTerm(void);
int sceNetAdhocctlDisconnect(void);
int sceNetAdhocTerm(void);
int sceNetTerm(void);
int sceKernelDelayThread(unsigned int us);
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

System::~System()
{
	int r;
	consPrintf("network : adhocctl terminated....\n");
	while ((r = sceNetAdhocctlTerm()) != 0) {
		if (r == (int)0x80410B01)
			sceNetAdhocctlDisconnect();
		sceKernelDelayThread(100000);
	}
	consPrintf("network : adhocctl terminated.\n");
	consPrintf("network : adhoc terminated....\n");
	while (sceNetAdhocTerm() != 0)
		sceKernelDelayThread(100000);
	consPrintf("network : adhoc terminated.\n");
	consPrintf("network : pspnet teminated....\n");
	while (sceNetTerm() != 0)
		sceKernelDelayThread(100000);
	consPrintf("network : pspnet terminated.\n");
}
}


