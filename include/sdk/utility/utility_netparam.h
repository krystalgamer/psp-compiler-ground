#ifndef _UTILITY_NETPARAM_H
#define _UTILITY_NETPARAM_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
#include <psptypes.h>
union SceUtilityNetParamEntry {
	SceChar8 cnf_name[64];
	SceChar8 ssid[33];
	SceUInt32 auth_proto;
	SceChar8 wep_key[13];
	SceUInt32 how_to_set_ip;
	SceChar8 ip_address[16];
	SceChar8 netmask[16];
	SceChar8 default_route[16];
	SceUInt32 dns_flag;
	SceChar8 primary_dns[16];
	SceChar8 secondary_dns[16];
	SceChar8 auth_name[128];
	SceChar8 auth_key[128];
	SceUInt32 http_proxy_flag;
	SceChar8 http_proxy_server[128];
	SceUInt32 http_proxy_port;
};
int sceUtilitySetNetParam(int id, union SceUtilityNetParamEntry *param);
#endif
