#ifndef ADHOCCTL_H
#define ADHOCCTL_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef int SceUID;
typedef unsigned int SceUInt;
typedef unsigned int SceSize;
typedef unsigned long long SceUInt64;

/* libc (static copies inside the module) */
#define toupper func_00004D64
#define tolower func_00004D90
#define __ctype_flags func_00004DBC
#define __ctype_ptr func_00004DD0
#define memchr func_00004DDC
#define memmove func_00004E14
#define memcmp func_00004E88

#define bcmp func_00004F28
#define bcopy func_00004F68
#define bzero func_00004F8C
#define strcmp func_00004FB4
#define index func_00005034
#define strrchr func_00005064
#define strncmp func_000050AC
#define strncpy func_00005144
#define strchr func_000051C0
#define strcpy func_000051F0
#define strlen func_00005228

extern const char D_00006810[];
#define _ctype_ D_00006810
#define _U 01
#define _L 02
#define _N 04
#define WLAN_ATTACH(p, ret, i, fail) \
	for (;;) { \
		(i)++; \
		(ret) = sceWlanDevAttach(); \
		if ((ret) == 0 || (ret) == 0x80410D0F) \
			break; \
		if ((ret) < 0 && (ret) != 0x80410D0E) \
			goto fail; \
		if ((i) >= (p)->unk20) { \
			(ret) = 0x80410B05; \
			goto fail; \
		} \
		sceKernelDelayThread(1000000); \
	}
#define WLAN_ATTACH_RET(p, ret, i) \
	for (;;) { \
		(i)++; \
		(ret) = sceWlanDevAttach(); \
		if ((ret) == 0 || (ret) == 0x80410D0F) \
			break; \
		if ((ret) < 0 && (ret) != 0x80410D0E) \
			return (ret); \
		if ((i) >= (p)->unk20) \
			return 0x80410B05; \
		sceKernelDelayThread(1000000); \
	}
#define ERROR_FACILITY(e) (((e) >> 16) & 0xFFF)
#define isalnum(c) ((_ctype_ + 1)[(unsigned char)(c)] & (_U | _L | _N))

void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *func_00004EC8(void *dst, const void *src, int n) __asm__("memcpy");
#define memcpy __builtin_memcpy
void *func_00004EFC(void *dst, int c, int n) __asm__("memset");
#define memset __builtin_memset
int bcmp(const void *a, const void *b, int n);
void bcopy(const void *src, void *dst, int n);
void bzero(void *p, int n);
int strcmp(const char *s1, const char *s2);
char *index(const char *s, char c);
char *strchr(const char *s, char c);
int strncmp(const char *s1, const char *s2, int n);
char *strncpy(char *dst, const char *src, int n);
char *strrchr(const char *s, char c);
char *strcpy(char *dst, const char *src);
int strlen(const char *s);
char toupper(char c);
char tolower(char c);
char __ctype_flags(int c);
const char *__ctype_ptr(void);


#define ERR_ALREADY_CONNECTED	0x80410B01
#define ERR_INVALID_ARG		0x80410B04
#define ERR_ID_NOT_FOUND	0x80410B06
#define ERR_ALREADY_INITIALIZED	0x80410B07
#define ERR_NOT_INITIALIZED	0x80410B08
#define ERR_DISCONNECTED	0x80410B09
#define ERR_NOT_ENTER_GAMEMODE	0x80410B0C
#define ERR_BUSY		0x80410B10
#define ERR_HANDLER_MAX		0x80410B80

struct SceNetEtherAddr {
	unsigned char data[6];
};

struct SceNetAdhocctlAdhocId {
	int type;
	unsigned char data[9];
	unsigned char padding[3];
};

struct SceNetAdhocctlGroupName {
	unsigned char data[8];
};

struct SceNetAdhocctlNickname {
	char data[128];
};

struct SceNetAdhocctlBSSId {
	unsigned char data[6];
	unsigned char padding[2];
};

struct SceNetAdhocctlScanInfo {
	struct SceNetAdhocctlScanInfo *next;
	int channel;
	struct SceNetAdhocctlGroupName group_name;
	struct SceNetEtherAddr bssid;
	unsigned char padding[2];
};

struct SceNetAdhocctlParameter {
	int channel;
	struct SceNetAdhocctlGroupName group_name;
	struct SceNetAdhocctlNickname nickname;
	struct SceNetEtherAddr bssid;
};

typedef void (*sceNetAdhocctlHandler)(int event, int error_code, void *arg);


struct bss_desc {
	struct SceNetEtherAddr bssid;	/* 0x00 */
	unsigned char channel;		/* 0x06 */
	unsigned char ssid_len;		/* 0x07 */
	union {
		char ssid[32];
		struct {
			char prefix[4];		/* "PSP_" */
			char id[10];		/* type + product id */
			char sep[3];		/* "_L_" */
			struct SceNetAdhocctlGroupName group_name;
			char rest[7];
		} s;
	} u;				/* 0x08 */
	int unk28;			/* 0x28 */
	int unk2C;			/* 0x2C */
	unsigned char unk30[0xE];	/* 0x30 */
	unsigned short unk3E;		/* 0x3E */
	unsigned char unk40[0x10];	/* 0x40 */
};

struct bss_req {
	struct bss_desc desc;
	unsigned char unk50[0x14];
};

struct scan_entry {
	struct scan_entry *next;
	struct bss_desc desc;
};

struct scan_req {
	int type;			/* 0x00 */
	unsigned char unk4[6];		/* 0x04 */
	unsigned char channels[14];	/* 0x0A */
	unsigned char unk18[0x24];	/* 0x18 */
	int unk3C;			/* 0x3C */
	int unk40;			/* 0x40 */
	int unk44;			/* 0x44 */
	int unk48;			/* 0x48 */
};

struct auth_param {
	int unk0;
	int unk4;
	int unk8;
	int unkC;
	int unk10;
};

struct wlan_conf {
	unsigned char unk0[0x11];
	unsigned char unk11;
	unsigned char unk12[2];
	int unk14;
};

struct gm_bss {
	struct gm_bss *next;		/* 0x00 */
	struct SceNetEtherAddr bssid;	/* 0x04 */
	unsigned char channel;		/* 0x0A */
	unsigned char unkB[0x21];	/* 0x0B */
	int unk2C;			/* 0x2C */
	unsigned char unk30[0x1E];	/* 0x30 */
	unsigned char unk4E;		/* 0x4E */
	unsigned char unk4F;		/* 0x4F */
	unsigned char unk50;		/* 0x50 */
	unsigned char unk51;		/* 0x51 */
	unsigned char unk52;		/* 0x52 */
};

struct gm_channel {
	int used;
	int count;
	unsigned int bits;
};

/* game mode parameters (0x50 bytes, byte aligned) */
struct gm_param {
	unsigned char data[0x44];
	unsigned char max;
	unsigned char data2[0xB];
};

struct adhocctl_ctx {
	SceUID evf;			/* 0x00 */
	SceUID thid;			/* 0x04 */
	SceUID sema;			/* 0x08 */
	int state;			/* 0x0C */
	int channel;			/* 0x10 */
	int unk14;			/* 0x14 */
	int unk18;			/* 0x18 */
	int busy;			/* 0x1C */
	int unk20;			/* 0x20 */
	int unk24;			/* 0x24 */
	struct SceNetAdhocctlGroupName group_name;	/* 0x28 */
	struct scan_entry scan[20];	/* 0x30 */
	struct SceNetAdhocctlScanInfo join_info;	/* 0x6C0 */
	struct SceNetAdhocctlAdhocId adhoc_id;	/* 0x6D8 */
};

struct gm_request {
	int num;			/* 0x00 */
	struct SceNetEtherAddr macs[16];	/* 0x04 */
	struct gm_param param;		/* 0x64 */
	int timeout;			/* 0xB4 */
	int flags;			/* 0xB8 */
};

struct gm_info {
	int num;
	struct SceNetEtherAddr macs[16];
};

struct handler {
	int id;
	sceNetAdhocctlHandler func;
	void *arg;
};

extern int D_000068A0;
extern struct adhocctl_ctx D_000068A4;
extern struct gm_request D_00006F8C;
extern struct handler D_00007048[2];
extern struct handler D_00007060;
extern const struct gm_param D_00006718[];
extern const char D_000066E8[];	/* "wlan" */
extern const char D_000066F0[];	/* "PSP" */
extern const char D_000066F4[];	/* "SceNetAdhocctl" */
extern const char D_00006704[];	/* "wlan" */
extern const char D_0000670C[];	/* "wlan" */
extern const char D_000067B8[];	/* "wlan" */
extern const unsigned char D_00006714[3];
extern int D_00007090;
extern struct gm_channel D_0000706C[3];
extern unsigned char D_00007494[0xA80];

/* main */
int func_000017A8(SceSize stacksize, int prio, const struct SceNetAdhocctlAdhocId *adhoc_id);
int func_00001978(void);
int func_00001A38(int *buflen, struct SceNetAdhocctlScanInfo *buf);
int func_00001C68(const struct SceNetAdhocctlGroupName *group_name);
int func_00001CDC(const struct SceNetAdhocctlGroupName *group_name);
int func_00001D50(const struct SceNetAdhocctlScanInfo *scan_info);
int func_00001E04(const struct SceNetAdhocctlGroupName *group_name, int num, const struct SceNetEtherAddr *macs, const struct gm_param *param, int timeout, int flags);
int func_00001F78(const struct SceNetAdhocctlGroupName *group_name, const struct SceNetEtherAddr *host, const struct gm_param *param, int timeout, int flags);
int func_000020C8(void);
int func_00002128(void);
int func_00002184(void);
int func_000021DC(sceNetAdhocctlHandler handler, void *arg, int *id);
int func_000022B0(int id);
int func_00002334(int *state);
int func_00002348(struct SceNetAdhocctlAdhocId *adhoc_id);
int func_00002378(struct SceNetAdhocctlParameter *param);
int func_00002408(struct gm_info *info);
int func_0000247C(sceNetAdhocctlHandler handler, void *arg);
int func_00002520(void);
int func_00002590(int event, int error);
int func_00002614(SceSize args, void *argp);

/* connect */
int func_000008C0(struct adhocctl_ctx *p);
int func_00000B40(struct adhocctl_ctx *p);
int func_00000D58(struct adhocctl_ctx *p);
int func_00000E50(struct adhocctl_ctx *p);
int func_00001154(struct adhocctl_ctx *p);
void func_000014B4(struct adhocctl_ctx *p);
int func_00001520(struct adhocctl_ctx *p, char *ssid, int *channel);
int func_000015E4(struct adhocctl_ctx *p, char *ssid);
int func_00001634(struct adhocctl_ctx *p, char *ssid, int mode, const unsigned char *group_name);

/* event */
int func_00002C84(struct adhocctl_ctx *p);
int func_00002D64(struct adhocctl_ctx *p);
int func_00002D84(struct adhocctl_ctx *p);
int func_00002E0C(struct adhocctl_ctx *p, int *event, int *data);

/* gamemode */
int func_00002F7C(struct adhocctl_ctx *p, struct gm_request *gm);
int func_0000378C(struct adhocctl_ctx *p, struct gm_request *gm);
void func_00004730(struct adhocctl_ctx *p, struct gm_request *gm);
int func_000046B0(int value);
int func_000042A0(struct gm_request *gm, unsigned char *channel, unsigned char *slot);

/* ptp */
int func_000047FC(struct gm_request *gm, SceUInt64 start, int id, void *data, int len);
int func_00004BB4(struct gm_request *gm, SceUInt64 start, int id, unsigned char *buf, int len);
unsigned char *func_00004CC4(int type, unsigned char *buf, int len, int *outlen);

/* imports */
int sceNetAdhocPtpAccept(int id, struct SceNetEtherAddr *mac, unsigned short *port, unsigned int timeout, int flag);
int sceNetAdhocPtpSend(int id, const void *data, int *len, unsigned int timeout, int flag);
int sceNetAdhocPtpFlush(int id, unsigned int timeout, int flag);
int sceNetAdhocPtpClose(int id, int flag);
int sceNetConfig80211GetConf(const char *ifname, struct wlan_conf *conf);
int sceNetConfig80211SetConf(const char *ifname, struct wlan_conf *conf);
int sceWlanDrv_lib_5BAA1FE5(int);
int sceNetAdhocPtpRecv(int id, void *buf, int *len, unsigned int timeout, int flag);
int sceWlanGetSwitchState(void);
int sceWlanDevAttach(void);
int sceWlanDevDetach(void);
int sceNetConfigUpInterface(const char *ifname);
int sceNetConfigDownInterface(const char *ifname);
int sceNetConfigSetIfEventFlag(const char *ifname, SceUID evf, unsigned int bits);
int sceNetConfig80211ScanRequest(const char *ifname, struct scan_req *req, int *size, struct scan_entry *buf, int *unk);
int sceNetConfig80211ScanCreateRequest(const char *ifname, const char *ssid, int ssid_len, int channel);
int sceNetConfig80211CreateRequest(const char *ifname, struct bss_req *req, int *unk);
int sceNetConfig80211JoinRequest(const char *ifname, struct bss_req *req, int *unk);
int sceNetConfig80211LeaveRequest(const char *ifname, int *unk);
int sceNetAdhocAuth_lib_89F2A732(const char *ifname, int a1, int a2, struct auth_param *param, int a4, const char *nickname);
int sceNetAdhocAuth_lib_2E6AA271(void);
int sceNetConfigGetIfEvent(const char *ifname, int *event, int *data);
int sceNetAdhocAuthInit(void);
int sceNetAdhocAuthTerm(void);
int sceNetAdhocAuth_lib_BD144DA6(int *buflen, void *buf);
int sceNetAdhocAuth_lib_1F9A90B8(const struct SceNetAdhocctlNickname *nickname, int *buflen, void *buf);
int sceNetAdhocAuth_lib_76F26AB0(const struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname *nickname);
SceUID sceKernelCreateThread(const char *name, void *entry, int prio, int stack, SceUInt attr, void *opt);
int sceKernelDeleteThread(SceUID thid);
int sceKernelStartThread(SceUID thid, SceSize arglen, void *argp);
int sceKernelTerminateThread(SceUID thid);
int sceKernelDelayThread(SceUInt delay);
SceUID sceKernelCreateSema(const char *name, SceUInt attr, int init, int max, void *opt);
int sceKernelDeleteSema(SceUID semaid);
int sceKernelSignalSema(SceUID semaid, int signal);
int sceKernelWaitSema(SceUID semaid, int signal, SceUInt *timeout);
SceUID sceKernelCreateEventFlag(const char *name, int attr, int bits, void *opt);
int sceKernelDeleteEventFlag(int evid);
int sceKernelSetEventFlag(SceUID evid, unsigned int bits);
int sceKernelClearEventFlag(SceUID evid, unsigned int bits);
int sceKernelPollEventFlag(int evid, unsigned int bits, unsigned int wait, unsigned int *outBits);
int sceKernelWaitEventFlag(int evid, unsigned int bits, unsigned int wait, unsigned int *outBits, SceUInt *timeout);
SceUInt64 sceKernelGetSystemTimeWide(void);
int sceNetConfig80211GetBssDesc(const char *ifname, struct bss_desc *desc);
int sceUtilityGetSystemParamString(int id, char *str, int len);
int sceUtilityGetSystemParamInt(int id, int *value);

/* STAND-IN: gcse hashes SYMBOL_REF names (gcse.c hash_expr_1), so the stripped original's real
 * symbol names decide the order of the PRE-created address pseudos and with it a global-alloc
 * tie in func_00002614 (%hi(D_00007060) vs %hi(D_000068A4) in s6/s7).  This alias only changes
 * the hashed string ("*D_00007060"); the object still references D_00007060.  Renaming the
 * symbol for the whole unit breaks func_000021DC, so the real name is still unknown. */
extern struct handler notify_handler __asm__("D_00007060");

static inline void notify(int event, int error)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int i;

	sceKernelWaitSema(p->sema, 1, NULL);
	for (i = 0; i < 2; i++) {
		if (D_00007048[i].func != NULL)
			D_00007048[i].func(event, error, D_00007048[i].arg);
	}
	if (notify_handler.func != NULL)
		notify_handler.func(event, error, notify_handler.arg);
	sceKernelSignalSema(p->sema, 1);
}

static inline int find_bss(struct adhocctl_ctx *p, const struct SceNetEtherAddr *bssid)
{
	int i;

	if (p == NULL || bssid == NULL)
		return 0x80410B0A;
	for (i = 0; i < 20; i++) {
		if (memcmp(&p->scan[i].desc.bssid, bssid, sizeof(*bssid)) == 0)
			return i;
	}
	return 0x80410B0A;
}

static inline int get_timeout(struct gm_request *gm, SceUInt64 start, unsigned int *tmo)
{
	SceUInt64 now;

	if (gm->timeout == 0) {
		*tmo = 0;
		return 0;
	}
	now = sceKernelGetSystemTimeWide();
	if (now - start < (unsigned int)gm->timeout) {
		*tmo = gm->timeout - (now - start);
		return 0;
	}
	return 0x80410B05;
}

static inline unsigned short ntohs16(unsigned short x)
{
	return __builtin_allegrex_wsbh(x);
}

#endif
