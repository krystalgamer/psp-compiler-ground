#ifndef _PSPNET_APCTL_H
#define _PSPNET_APCTL_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
#include <psptypes.h>
#include <kerneltypes.h>
union SceNetApctlInfo {
	SceChar8 cnf_name[64];
	SceUChar8 bssid[6];
	SceUChar8 ssid[32];
	SceSize ssidlen;
	SceUInt32 auth_proto;
	SceUChar8 rssi;
	SceUChar8 channel;
	SceUChar8 pwrsave;
	SceChar8 ip_address[16];
	SceChar8 netmask[16];
	SceChar8 default_route[16];
	SceChar8 primary_dns[16];
	SceChar8 secondary_dns[16];
	SceUInt32 http_proxy_flag;
	SceChar8 http_proxy_server[128];
	SceUShort16 http_proxy_port;
};
typedef void (*sceNetApctlHandler)(int prev_state, int new_state, int event, int error_code, void *arg);
int sceNetApctlInit(int stack_size, int init_priority);
int sceNetApctlTerm(void);
int sceNetApctlAddHandler(sceNetApctlHandler handler, void *arg);
int sceNetApctlDelHandler(int handler_id);
int sceNetApctlGetInfo(int code, union SceNetApctlInfo *info);
int sceNetApctlGetState(int *state);
int sceNetApctlDisconnect(void);
#endif
