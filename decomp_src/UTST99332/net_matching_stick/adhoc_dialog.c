#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef unsigned int SceUInt;
enum SceNetAdhocDialogState {
    SCE_NET_ADHOC_DIALOG_STATE_DISCONNECTED = 0,
    SCE_NET_ADHOC_DIALOG_STATE_CONNECTED = 1,
    SCE_NET_ADHOC_DIALOG_STATE_GAMEMODE = 2,
    SCE_NET_ADHOC_DIALOG_STATE_OPENED = 3,
};
struct SceNetAdhocDialogInfo;
enum SceNetAdhocDialogInternalState {
    SCE_NET_ADHOC_DIALOG_INT_STATE_CLOSED = 0,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING = 1,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CREATING = 2,
    SCE_NET_ADHOC_DIALOG_INT_STATE_START_SCAN = 3,
    SCE_NET_ADHOC_DIALOG_INT_STATE_SCANNING = 4,
    SCE_NET_ADHOC_DIALOG_INT_STATE_JOINING = 5,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_CREATE = 6,
    SCE_NET_ADHOC_DIALOG_INT_STATE_CONNECTING_GAMEMODE_JOIN = 7,
    SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_SWITCH_OFF = 8,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE = 9,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_CREATE = 10,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_SCAN = 11,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_JOIN = 12,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_CREATE = 13,
    SCE_NET_ADHOC_DIALOG_INT_STATE_FAILURE_GAMEMODE_JOIN = 14,
    SCE_NET_ADHOC_DIALOG_INT_STATE_WLAN_ERROR = 15,
};
typedef int SceUID;
struct SceNetAdhocDialogInfo { /* size 0x88 */
    enum SceNetAdhocDialogInternalState state;
    SceUID tid;
    int error_code;
    int handler_id;
    struct SceNetAdhocctlGroupName group_name;
    int game_type;
    int num;
    struct SceNetEtherAddr members[16];
    int timeout;
    int scan_num;
};
struct SceNetAdhocctlScanInfo;
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlScanInfo { /* size 0x1c */
    struct SceNetAdhocctlScanInfo *next;
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlBSSId bssid;
    int mode;
};

extern struct SceNetAdhocDialogInfo info;
extern int inited;
extern struct SceNetAdhocctlScanInfo scaninfo[24];

int sceNetAdhocDialogConnect(struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDialogCreate(struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDialogCreateEnterGameMode(struct SceNetAdhocctlGroupName *group_name, int game_type, int num, struct SceNetEtherAddr *members, SceUInt timeout);
int sceNetAdhocDialogJoinEnterGameMode(struct SceNetAdhocctlGroupName *group_name, struct SceNetEtherAddr *gc, SceUInt timeout);
int sceNetAdhocDialogGetState(enum SceNetAdhocDialogState *state);
int sceNetAdhocDialogInit(void);
int sceNetAdhocDialogTerm(void);
int sceNetAdhocDialogJoin(struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDialogWlanError(int error_code);
int sceNetAdhocDialogUpdate(void);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogConnect);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogCreate);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogCreateEnterGameMode);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogJoinEnterGameMode);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogGetState);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogInit);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogTerm);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogJoin);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogWlanError);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_stick/nonmatchings/adhoc_dialog", sceNetAdhocDialogUpdate);
