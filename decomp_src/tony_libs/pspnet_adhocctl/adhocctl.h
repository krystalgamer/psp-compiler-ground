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
	unsigned char scan[0x690];	/* 0x30 */
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

struct bss_desc {
	struct SceNetEtherAddr bssid;
	unsigned short unk6;
	int unk8[0x12];
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
extern const char D_000066F4[];	/* "SceNetAdhocctl" */
extern const char D_00006704[];	/* "wlan" */
extern const char D_0000670C[];	/* "wlan" */

/* main */
int func_000017A8(SceSize stacksize, int prio, const struct SceNetAdhocctlAdhocId *adhoc_id);
int func_00001978(void);
int func_00001A38(int *buflen, void *buf);
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
int func_000014B4(struct adhocctl_ctx *p);

/* event */
int func_00002C84(struct adhocctl_ctx *p);
int func_00002D64(struct adhocctl_ctx *p);
int func_00002D84(struct adhocctl_ctx *p);
int func_00002E0C(struct adhocctl_ctx *p, int *event, int *data);

/* gamemode */
int func_00002F7C(struct adhocctl_ctx *p, struct gm_request *gm);
int func_0000378C(struct adhocctl_ctx *p, struct gm_request *gm);
int func_00004730(struct adhocctl_ctx *p, struct gm_request *gm);

/* imports */
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

static inline void notify(int event, int error)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int i;

	sceKernelWaitSema(p->sema, 1, NULL);
	for (i = 0; i < 2; i++) {
		if (D_00007048[i].func != NULL)
			D_00007048[i].func(event, error, D_00007048[i].arg);
	}
	if (D_00007060.func != NULL)
		D_00007060.func(event, error, D_00007060.arg);
	sceKernelSignalSema(p->sema, 1);
}

#endif
