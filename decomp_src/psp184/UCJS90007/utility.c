#include "common.h"

/* declarations recovered from DWARF */
enum _anon1 {
    SCE_UTILITY_NETCONF_TYPE_CONNECT_APNET = 0,
    SCE_UTILITY_NETCONF_TYPE_STATUS_APNET = 1,
    SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC = 2,
    SCE_UTILITY_NETCONF_TYPE_RECONNECT_APNET = 3,
    SCE_UTILITY_NETCONF_TYPE_CREATE_ADHOC = 4,
    SCE_UTILITY_NETCONF_TYPE_JOIN_ADHOC = 5,
};
typedef enum _anon1 SceUtilityNetconfType;
typedef short unsigned int SceWChar16;
typedef unsigned int SceUInt;
struct _info;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
enum connect_state {
    STATE_FIRST_INIT = 0,
    STATE_TOP = 1,
    STATE_CONFIG = 2,
    STATE_LOAD_LOGFILE = 3,
    STATE_LOAD_BOOT_BINARY = 4,
    STATE_LOADING = 5,
    STATE_NETINIT = 6,
    STATE_NETTERM = 7,
    STATE_CONNECT = 8,
    STATE_CONNECTING = 9,
    STATE_CONNECTED = 10,
    STATE_MPEG_START = 11,
    STATE_MPEG_INITIALIZING = 12,
    STATE_MPEG_PLAY_START = 13,
    STATE_MOVIE_SCENE = 14,
    STATE_STATUS_SCENE = 15,
    STATE_DISCONNECT = 16,
    STATE_DISCONNECTING = 17,
    STATE_DISPLAY_LOG_MS = 18,
    STATE_DISPLAY_LOG_NEXT = 19,
    STATE_DISPLAY_LOG_PREV = 20,
    STATE_DISPLAY_LOG = 21,
    STATE_ERROR_DIALOG_NET = 22,
    STATE_ERROR_DIALOG_FILEIO = 23,
    STATE_ERROR_DIALOG_MPEG_FILEIO = 24,
    STATE_OSK = 25,
    STATE_BINLIST = 26,
    STATE_MPEGLIST = 27,
    STATE_DISPLAY_PARAMSFO_TOP = 28,
    STATE_DISPLAY_PARAMSFO_BINLIST = 29,
    STATE_DISPLAY_PARAMSFO_CONNECTED = 30,
};
struct SceNetAdhocctlParameter;
struct SceNetAdhocctlGroupName;
typedef char SceChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceChar8 data[128];
};
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlParameter { /* size 0x94 */
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetAdhocctlBSSId bssid;
};
struct _info { /* size 0x58c */
    struct SceNetEtherAddr local_addr;
    enum connect_state prev_state;
    enum connect_state state;
    int blink_counter;
    int error_code;
    int actual_err_code;
    int actual_err_code_thr;
    int v_cursor_pos;
    int binlist_v_cursor_pos;
    int binlist_top_entry;
    int binlist_entry_num;
    int mpeglist_v_cursor_pos;
    int mpeglist_top_entry;
    int mpeglist_entry_num;
    char bin_filename[256];
    char movie_filename[1][256];
    char log_filename[256];
    int thread_num;
    unsigned int paramsfo_len;
    void *paramsfo;
    unsigned int datasize;
    void *databuf;
    struct SceNetAdhocctlParameter ibss_param;
    int peer_num;
    char paramsfo_filename[256];
    char paramsfo_title[128];
    unsigned int paramsfo_title_len;
    char paramsfo_discid[16];
    unsigned int paramsfo_discid_len;
    int paramsfo_parental;
    int lang;
    int ctrl_assign;
};
struct _anon2;
struct _anon3;
struct _anon3 { /* size 0x30 */
    unsigned int size;
    int message_lang;
    int ctrl_assign;
    int main_thread_priority;
    int sub_thread_priority;
    int font_thread_priority;
    int sound_thread_priority;
    int result;
    int reserved1;
    int reserved2;
    int reserved3;
    int reserved4;
};
typedef struct _anon3 SceUtilityParamBase;
struct _anon4;
struct _anon4 { /* size 0xc */
    unsigned char group_name[8];
    unsigned int timeout;
};
typedef struct _anon4 SceUtilityNetconfAdhocParam;
typedef unsigned int SceUInt32;
struct _anon2 { /* size 0x40 */
    SceUtilityParamBase base;
    int type;
    SceUtilityNetconfAdhocParam *adhoc_param;
    SceUInt32 browser_available;
    SceUInt32 browser_flag;
};
typedef struct _anon2 SceUtilityNetconfParam;
struct _anon5;
struct _anon5 { /* size 0x244 */
    SceUtilityParamBase base;
    int result;
    int type;
    unsigned int errorNum;
    char msgString[512];
    int optionType;
    int buttonResult;
};
typedef struct _anon5 SceUtilityMsgDialogParam;
struct _anon6;
struct _anon7;
enum _anon8 {
    SCE_UTILITY_OSK_BOOL_VALUE_FALSE = 0,
    SCE_UTILITY_OSK_BOOL_VALUE_TRUE = 1,
};
typedef enum _anon8 SceUtilityOskBoolValue;
enum _anon9 {
    SCE_UTILITY_OSK_INPUT_FIELD_RESULT_UNEDITED = 0,
    SCE_UTILITY_OSK_INPUT_FIELD_RESULT_CANCELED = 1,
    SCE_UTILITY_OSK_INPUT_FIELD_RESULT_EDITED = 2,
};
typedef enum _anon9 SceUtilityOskInputFieldResult;
struct _anon7 { /* size 0x34 */
    unsigned int input_method_type;
    unsigned int input_method_attributes;
    unsigned int writing_language_type;
    SceUtilityOskBoolValue hide_mode;
    int input_character_type;
    int num_lines;
    int kinsoku;
    SceWChar16 *message;
    SceWChar16 *init_text;
    int result_text_buffer_size;
    SceWChar16 *result_text_buffer;
    SceUtilityOskInputFieldResult result;
    int limit_length;
};
typedef struct _anon7 SceUtilityOskInputFieldInfo;
enum _anon10 {
    SCE_UTILITY_OSK_LOCAL_STATUS_NONE = 0,
    SCE_UTILITY_OSK_LOCAL_STATUS_INITIALIZING = 1,
    SCE_UTILITY_OSK_LOCAL_STATUS_INITIALIZED = 2,
    SCE_UTILITY_OSK_LOCAL_STATUS_OPENED = 3,
    SCE_UTILITY_OSK_LOCAL_STATUS_CLOSING = 4,
    SCE_UTILITY_OSK_LOCAL_STATUS_CLOSED = 5,
};
typedef enum _anon10 SceUtilityOskLocalStatus;
struct _anon6 { /* size 0x40 */
    SceUtilityParamBase base;
    unsigned int num_input_fields;
    SceUtilityOskInputFieldInfo *input_field_info;
    SceUtilityOskLocalStatus local_status;
    int error_code;
};
typedef struct _anon6 SceUtilityOskParam;

extern struct _info _info;
extern char *no_memory_stick_string[6];
extern char *no_game_file_string[6];
extern char *invalid_pbp_foramt[6];
extern char *no_movie_file_string[6];
extern char *invalid_psmf_foramt_string[6];
extern char *movie_play_error_string[6];
extern char *internal_error_string[6];
extern char *reboot_string1[6];
extern char *reboot_string2[6];
extern char ctrl_assign_string[2][4];
extern SceUtilityNetconfParam netconfParam;
extern SceUtilityNetconfAdhocParam adhocParam;
extern SceUtilityMsgDialogParam msgdialogParam;
extern SceUtilityOskParam osk_param;
extern SceWChar16 init_string[256];
extern SceWChar16 result_string[256];
extern SceUtilityOskInputFieldInfo oskInputFieldInfo;
extern SceWChar16 bin_filename_string[256];

static int utility_init_netconf(SceUtilityNetconfType type);
int utility_update_netconf(void);
int utility_check_net_completed(int *done_flag, int *error_code);
int utility_msgdialog_net(int error_code);
int utility_msgdialog_fileio(int error_code);
int utility_msgdialog_mpeg_fileio(int error_code);
int utility_msgdialog_paramsfo(int error_code);
int utility_update_msgdialog(void);
int utility_check_msgdialog_completed(int *done_flag);
int utility_osk(void);
int utility_update_osk(void);
int utility_check_osk_completed(int *done_flag, int *error_code);
int utility_get_osk_result(char *ptr, SceUInt size);


INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_init_netconf);

int utility_update_netconf(void)
{
	int ret = 0;

	if (sceUtilityNetconfGetStatus() == 2)
		ret = sceUtilityNetconfUpdate(1);
	return ret;
}

int utility_net_connect(void) {
    return utility_init_netconf(SCE_UTILITY_NETCONF_TYPE_CONNECT_ADHOC);
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_check_net_completed);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_msgdialog_net);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_msgdialog_fileio);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002DF40);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002DF7C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002DF98);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002DFB4);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002DFD0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E000);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E020);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E0BC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E128);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E1B0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E220);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E2AC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E314);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E39C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E3EC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E450);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E4AC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E510);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E564);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E600);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E66C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E6FC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E768);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E7F4);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E854);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E8DC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E92C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E998);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002E9F4);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EA58);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EAA4);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EADC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EB0C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EB44);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EB80);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EBC0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EBFC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EC20);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EC38);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EC54);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EC70);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EC90);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ECAC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ECB0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ECBC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ECD4);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ECE4);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ECFC);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ED10);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ED44);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ED70);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002ED94);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EDC0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EDF0);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EE18);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EE20);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EE2C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/utility", D_0002EE30);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_msgdialog_mpeg_fileio);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_msgdialog_paramsfo);

int utility_update_msgdialog(void)
{
	int ret = 0;

	if (sceUtilityMsgDialogGetStatus() == 2)
		ret = sceUtilityMsgDialogUpdate(1);
	return ret;
}

extern int D_00082D0C;
int utility_check_msgdialog_completed(int *done_flag)
{
	int ret;

	ret = sceUtilityMsgDialogGetStatus();
	if (ret < 0)
		return ret;
	switch (ret) {
	case 0:
		if (D_00082D0C == 0)
			*done_flag = 1;
		else
			*done_flag = -1;
		break;
	case 3:
		ret = sceUtilityMsgDialogShutdownStart();
		break;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_osk);

int utility_update_osk(void)
{
	int ret = 0;

	if (sceUtilityOskGetStatus() == 2)
		ret = sceUtilityOskUpdate(1);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_check_osk_completed);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/utility", utility_get_osk_result);
