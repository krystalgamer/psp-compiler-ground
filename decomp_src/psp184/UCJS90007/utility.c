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


static int utility_init_netconf(SceUtilityNetconfType type)
{
	memset(&netconfParam, 0, sizeof(netconfParam));
	netconfParam.base.size = sizeof(netconfParam);
	netconfParam.base.message_lang = _info.lang;
	netconfParam.base.ctrl_assign = _info.ctrl_assign;
	netconfParam.base.main_thread_priority = 0x11;
	netconfParam.base.sub_thread_priority = 0x13;
	netconfParam.base.font_thread_priority = 0x12;
	netconfParam.base.sound_thread_priority = 0x10;
	netconfParam.type = type;
	netconfParam.adhoc_param = &adhocParam;
	return sceUtilityNetconfInitStart(&netconfParam);
}

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

int utility_check_net_completed(int *done_flag, int *error_code)
{
	int ret;

	ret = sceUtilityNetconfGetStatus();
	if (ret < 0)
		goto error;
	switch (ret) {
	case 0:
		if (netconfParam.base.result == 0) {
			*done_flag = 1;
		} else {
			*done_flag = -1;
			if (netconfParam.base.result < 0)
				*error_code = netconfParam.base.result;
		}
		break;
	case 3:
		ret = sceUtilityNetconfShutdownStart();
		break;
	}
error:
	return ret;
}

void *memset(void *s, int c, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int utility_msgdialog_net(int error_code)
{
	memset(&msgdialogParam, 0, sizeof(msgdialogParam));
	msgdialogParam.base.size = sizeof(msgdialogParam);
	msgdialogParam.base.message_lang = _info.lang;
	msgdialogParam.base.ctrl_assign = _info.ctrl_assign;
	msgdialogParam.base.main_thread_priority = 0x11;
	msgdialogParam.base.sub_thread_priority = 0x13;
	msgdialogParam.base.font_thread_priority = 0x12;
	msgdialogParam.base.sound_thread_priority = 0x10;
	msgdialogParam.type = 0;
	msgdialogParam.errorNum = error_code;
	return sceUtilityMsgDialogInitStart(&msgdialogParam);
}

int snprintf(char *str, unsigned int size, const char *format, ...);
extern const char D_0002EE18[];
extern const char D_0002EE20[];
extern const char D_0002EE2C[];
extern const char D_0002EE30[];
int utility_msgdialog_fileio(int error_code)
{
	char buf[512];
	char *msg;
	int show_code = 0;

	switch (error_code) {
	case 0x80020321:
	case 0x80010013:
	case 0x80410C8A:
		msg = no_memory_stick_string[_info.lang];
		break;
	case 0x80010002:
	case 0x80410C81:
		msg = no_game_file_string[_info.lang];
		break;
	case 0x80410C82:
		msg = invalid_pbp_foramt[_info.lang];
		break;
	default:
		if (_info.lang == 0)
			snprintf(buf, sizeof(buf), D_0002EE18, internal_error_string[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		else
			snprintf(buf, sizeof(buf), D_0002EE30, internal_error_string[_info.lang], reboot_string1[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		msg = buf;
		show_code = 1;
		break;
	}
	memset(&msgdialogParam, 0, sizeof(msgdialogParam));
	msgdialogParam.base.size = sizeof(msgdialogParam);
	msgdialogParam.base.message_lang = _info.lang;
	msgdialogParam.base.ctrl_assign = _info.ctrl_assign;
	msgdialogParam.base.main_thread_priority = 0x11;
	msgdialogParam.base.sub_thread_priority = 0x13;
	msgdialogParam.base.font_thread_priority = 0x12;
	msgdialogParam.base.sound_thread_priority = 0x10;
	if (show_code)
		snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE20, msg, error_code);
	else
		snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE2C, msg);
	msgdialogParam.type = 1;
	msgdialogParam.optionType = 0;
	return sceUtilityMsgDialogInitStart(&msgdialogParam);
}

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

const char D_0002EE18[] = "%s\n%s%s";
const char D_0002EE20[] = "%s\n(%08x)";
const char D_0002EE2C[] = "%s";
const char D_0002EE30[] = "%s %s%s%s";
const char D_0002EE3C[] = "%s\n(%08x, %08x)";
const char D_0002EE4C[] = "%s\n%s%s%s";

int snprintf(char *str, unsigned int size, const char *format, ...);
extern const char D_0002EE18[];
extern const char D_0002EE20[];
extern const char D_0002EE2C[];
extern const char D_0002EE30[];
extern const char D_0002EE3C[];
extern const char D_0002EE4C[];
int utility_msgdialog_mpeg_fileio(int error_code)
{
	char buf[512];
	char *msg;
	int show_code = 0;

	switch (error_code) {
	case 0x80020321:
	case 0x80010013:
	case 0x80410C8A:
		if (_info.lang == 0)
			snprintf(buf, sizeof(buf), D_0002EE18, no_memory_stick_string[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		else
			snprintf(buf, sizeof(buf), D_0002EE4C, no_memory_stick_string[_info.lang], reboot_string1[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		msg = buf;
		break;
	case 0x80010002:
	case 0x80410C81:
		msg = no_movie_file_string[_info.lang];
		break;
	case 0x80410C84:
		msg = invalid_psmf_foramt_string[_info.lang];
		break;
	case 0x80410C85:
	case 0x80410C86:
	case 0x80410C87:
	case 0x80410C88:
	case 0x80410C89:
		if (_info.lang == 0)
			snprintf(buf, sizeof(buf), D_0002EE18, movie_play_error_string[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		else
			snprintf(buf, sizeof(buf), D_0002EE30, movie_play_error_string[_info.lang], reboot_string1[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		msg = buf;
		show_code = 1;
		break;
	case 0x80410C83:
	default:
		if (_info.lang == 0)
			snprintf(buf, sizeof(buf), D_0002EE18, internal_error_string[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		else
			snprintf(buf, sizeof(buf), D_0002EE30, internal_error_string[_info.lang], reboot_string1[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
		msg = buf;
		show_code = 1;
		break;
	}
	memset(&msgdialogParam, 0, sizeof(msgdialogParam));
	msgdialogParam.base.size = sizeof(msgdialogParam);
	msgdialogParam.base.message_lang = _info.lang;
	msgdialogParam.base.ctrl_assign = _info.ctrl_assign;
	msgdialogParam.base.main_thread_priority = 0x11;
	msgdialogParam.base.sub_thread_priority = 0x13;
	msgdialogParam.base.font_thread_priority = 0x12;
	msgdialogParam.base.sound_thread_priority = 0x10;
	if (show_code) {
		if (error_code == 0x80410C85)
			snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE20, msg, _info.actual_err_code);
		else if (error_code >= 0x80410C86 && error_code <= 0x80410C89)
			snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE3C, msg, error_code, _info.actual_err_code_thr);
		else
			snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE20, msg, error_code);
	} else
		snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE2C, msg);
	msgdialogParam.type = 1;
	msgdialogParam.optionType = 0;
	return sceUtilityMsgDialogInitStart(&msgdialogParam);
}

const char D_0002EE58[] = "\"%s\"\n\nTITLE: %s\nDISC_ID: %s\nPARENTAL_LEVEL: %d";
int snprintf(char *str, unsigned int size, const char *format, ...);
extern const char D_0002EE18[];
extern const char D_0002EE20[];
extern const char D_0002EE2C[];
extern const char D_0002EE30[];
extern const char D_0002EE58[];
int utility_msgdialog_paramsfo(int error_code)
{
	char buf[512];
	char *msg = NULL;
	int show_code = 0;

	if (error_code < 0) {
		switch (error_code) {
		case 0x80020321:
		case 0x80010013:
		case 0x80410C8A:
			msg = no_memory_stick_string[_info.lang];
			break;
		case 0x80010002:
		case 0x80410C81:
			msg = no_game_file_string[_info.lang];
			break;
		case 0x80410C82:
			msg = invalid_pbp_foramt[_info.lang];
			break;
		default:
			if (_info.lang == 0)
				snprintf(buf, sizeof(buf), D_0002EE18, internal_error_string[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
			else
				snprintf(buf, sizeof(buf), D_0002EE30, internal_error_string[_info.lang], reboot_string1[_info.lang], ctrl_assign_string[_info.ctrl_assign], reboot_string2[_info.lang]);
			msg = buf;
			show_code = 1;
			break;
		}
	}
	memset(&msgdialogParam, 0, sizeof(msgdialogParam));
	msgdialogParam.base.size = sizeof(msgdialogParam);
	msgdialogParam.base.message_lang = _info.lang;
	msgdialogParam.base.ctrl_assign = _info.ctrl_assign;
	msgdialogParam.base.main_thread_priority = 0x11;
	msgdialogParam.base.sub_thread_priority = 0x13;
	msgdialogParam.base.font_thread_priority = 0x12;
	msgdialogParam.base.sound_thread_priority = 0x10;
	msgdialogParam.type = 1;
	msgdialogParam.optionType = 0;
	if (msg == NULL)
		snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE58, _info.paramsfo_filename, _info.paramsfo_title, _info.paramsfo_discid, _info.paramsfo_parental);
	else if (show_code)
		snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE20, msg, error_code);
	else
		snprintf(msgdialogParam.msgString, sizeof(msgdialogParam.msgString), D_0002EE2C, msg);
	return sceUtilityMsgDialogInitStart(&msgdialogParam);
}

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

int sceUtilityOskInitStart(SceUtilityOskParam *param);
int utility_osk(void)
{
	int i;
	SceWChar16 *message = NULL;

	memset(&osk_param, 0, sizeof(osk_param));
	osk_param.base.size = sizeof(osk_param);
	osk_param.base.main_thread_priority = 0x11;
	osk_param.base.sub_thread_priority = 0x13;
	osk_param.base.font_thread_priority = 0x12;
	osk_param.base.sound_thread_priority = 0x10;
	osk_param.base.reserved1 = 0;
	osk_param.base.reserved2 = 0;
	if (_info.v_cursor_pos == 1) {
		for (i = 0; _info.bin_filename[i] != '\0'; i++)
			init_string[i] = _info.bin_filename[i];
		init_string[i] = 0;
		osk_param.num_input_fields = 1;
		message = bin_filename_string;
	}
	oskInputFieldInfo.input_method_type = 0;
	oskInputFieldInfo.input_method_attributes = 0;
	oskInputFieldInfo.writing_language_type = 0;
	oskInputFieldInfo.hide_mode = 0;
	oskInputFieldInfo.input_character_type = 0xF;
	oskInputFieldInfo.num_lines = 1;
	oskInputFieldInfo.kinsoku = 1;
	oskInputFieldInfo.message = message;
	oskInputFieldInfo.init_text = init_string;
	oskInputFieldInfo.result_text_buffer_size = 0x100;
	oskInputFieldInfo.result_text_buffer = result_string;
	oskInputFieldInfo.result = 0;
	oskInputFieldInfo.limit_length = 0;
	osk_param.input_field_info = &oskInputFieldInfo;
	return sceUtilityOskInitStart(&osk_param);
}

int utility_update_osk(void)
{
	int ret = 0;

	if (sceUtilityOskGetStatus() == 2)
		ret = sceUtilityOskUpdate(1);
	return ret;
}

int utility_check_osk_completed(int *done_flag, int *error_code)
{
	int ret;

	ret = sceUtilityOskGetStatus();
	if (ret < 0)
		goto error;
	switch (ret) {
	case 0:
		if (osk_param.base.result == 0) {
			if (osk_param.input_field_info->result == 2)
				*done_flag = 1;
			else
				*done_flag = -1;
		} else {
			*done_flag = -1;
			if (osk_param.base.result < 0)
				*error_code = osk_param.base.result;
		}
		break;
	case 3:
		ret = sceUtilityOskShutdownStart();
		break;
	}
error:
	return ret;
}

int utility_get_osk_result(char *ptr, SceUInt size)
{
	SceUInt i = 0;

	if (size != 0) {
		while (result_string[i] != 0) {
			ptr[i] = (char)result_string[i];
			i++;
			if (i >= size)
				break;
		}
	}
	if (i == size)
		ptr[i - 1] = '\0';
	else
		ptr[i] = '\0';
	return 0;
}
