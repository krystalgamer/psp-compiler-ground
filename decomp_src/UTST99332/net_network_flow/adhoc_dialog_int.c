#include "common.h"

/* declarations recovered from DWARF */
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
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
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
typedef unsigned int u_int32;

extern char disp_list[327680];
extern short int board[2][3];
extern u_int32 cont;
extern int evf;

void _sce_pspnet_adhoc_dialog_adhocctl_handler(int event, int error, void *arg);
int _sce_pspnet_adhoc_dialog_set_error_state(struct SceNetAdhocDialogInfo *info, int error_code);
void _sce_pspnet_adhoc_dialog_clear_evf(struct SceNetAdhocDialogInfo *info);
int _sce_pspnet_adhoc_dialog_get_evf(struct SceNetAdhocDialogInfo *info, int *evf_ptr);
static void draw_frame(struct SceNetAdhocDialogInfo *info);
static void print_connecting_message(void);
static void print_wlan_off_message(void);
static void print_failure_message(void);
static void print_wlan_error_message(struct SceNetAdhocDialogInfo *info);
static void pad_read(struct SceNetAdhocDialogInfo *info);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
int sceGuFinish(void);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
int sprintf(char *buf, const char *fmt, ...);
unsigned int strlen(const char *s);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/adhoc_dialog_int", _sce_pspnet_adhoc_dialog_adhocctl_handler);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/adhoc_dialog_int", _sce_pspnet_adhoc_dialog_set_error_state);

int _sce_pspnet_adhoc_dialog_update(struct SceNetAdhocDialogInfo *info) {
    pad_read_A0BC();
    draw_frame_9DF0(info);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/adhoc_dialog_int", _sce_pspnet_adhoc_dialog_clear_evf);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/adhoc_dialog_int", _sce_pspnet_adhoc_dialog_get_evf);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/adhoc_dialog_int", draw_frame_9DF0);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/adhoc_dialog_int", pad_read_A0BC);
