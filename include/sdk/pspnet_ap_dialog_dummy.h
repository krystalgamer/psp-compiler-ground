#ifndef _PSPNET_AP_DIALOG_DUMMY_H
#define _PSPNET_AP_DIALOG_DUMMY_H
/* types recovered from DWARF */
#include <psptypes.h>
struct SceNetApDialogDummyStateInfo {
	int state;
	int error_code;
};
union ip_opt {
	struct static_ip {
		char ip_address[16];
		char netmask[16];
		char default_route[16];
	} static_ip;
	struct pppoe {
		char auth_name[128];
		char auth_key[128];
	} pppoe;
};
struct SceNetApDialogDummyParam {
	char ssid[33];
	unsigned int auth_proto;
	char wep_key[13];
	unsigned int how_to_set_ip;
	union ip_opt ip_opt;
	unsigned int dns_flag;
	char primary_dns[16];
	char secondary_dns[16];
	unsigned int http_proxy_flag;
	char http_proxy_server[128];
	SceUShort16 http_proxy_port;
};
#endif
