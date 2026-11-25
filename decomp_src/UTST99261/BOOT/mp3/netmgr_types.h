/* types recovered from DWARF */
#ifndef NETMGR_TYPES_H
#define NETMGR_TYPES_H
struct SceNetApDialogDummyStateInfo;
struct SceNetApDialogDummyStateInfo { 
    int state;
    int error_code;
};
struct SceNetApDialogDummyParam;
union ip_opt;
struct static_ip;
struct static_ip { 
    char ip_address[16];
    char netmask[16];
    char default_route[16];
};
struct pppoe;
struct pppoe { 
    char auth_name[128];
    char auth_key[128];
};
union ip_opt { 
    struct static_ip static_ip;
    struct pppoe pppoe;
};
typedef short unsigned int SceUShort16;
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
union SceNetApctlInfo;
typedef char SceChar8;
typedef unsigned char SceUChar8;
typedef unsigned int SceSize;
typedef unsigned int SceUInt32;
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
struct _anon1;
struct _anon1 { 
    int tmpl;
    int connection;
    int request;
    int length;
    int curofst;
    int buf_top;
    int buf_size;
    char *uri;
    unsigned char recv_buf[1500];
};
typedef struct _anon1 HTTP_PARAM;
typedef long long int SceInt64;
struct _anon2;
struct SceNetInetSockaddrIn;
struct SceNetInetInAddr;
struct SceNetInetInAddr { 
    SceUInt32 s_addr;
};
struct SceNetInetSockaddrIn { 
    SceUChar8 sin_len;
    SceUChar8 sin_family;
    SceUShort16 sin_port;
    struct SceNetInetInAddr sin_addr;
    SceChar8 sin_zero[8];
};
struct _anon2 { 
    char *uri;
    char server_name[256];
    char path_name[256];
    int port_number;
    int s;
    struct SceNetInetSockaddrIn sin;
    int meta_int;
    int meta_count;
    int meta_tagint;
    int meta_tagcount;
    int meta_buf_index;
    char meta_buf[2][4096];
    int header_skip;
    int header_count;
    char header_buf[1024];
    int buf_top;
    int buf_size;
    unsigned char recv_buf[1460];
};
typedef struct _anon2 ICY_PARAM;
typedef int SceMode;
typedef int SceUID;
typedef int SceSSize;
typedef long long int SceOff;
typedef int SceInt32;

#endif
