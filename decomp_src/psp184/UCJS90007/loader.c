#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int SceSize;
struct log_display;
struct _anon1;
struct _anon1 { /* size 0x8 */
    struct log_display *tqe_next;
    struct log_display **tqe_prev;
};
struct log_display { /* size 0x60 */
    struct _anon1 link;
    char peer_addr[20];
    char start_date[12];
    char finish_date[12];
    char start_time[12];
    char finish_time[12];
    char dist_time[8];
    char error_code[12];
};
struct SceIoStat;
typedef int SceMode;
typedef long long int SceOff;
typedef struct ScePspDateTime ScePspDateTime;
struct ScePspDateTime;
struct ScePspDateTime { /* size 0x10 */
    short unsigned int year;
    short unsigned int month;
    short unsigned int day;
    short unsigned int hour;
    short unsigned int minute;
    short unsigned int second;
    unsigned int microsecond;
};
struct SceIoStat { /* size 0x58 */
    SceMode st_mode;
    unsigned int st_attr;
    SceOff st_size;
    ScePspDateTime st_ctime;
    ScePspDateTime st_atime;
    ScePspDateTime st_mtime;
    unsigned int st_private[6];
};
typedef struct ScePSPBootPackageHeader ScePSPBootPackageHeader;
struct ScePSPBootPackageHeader;
struct ScePSPBootPackageHeader { /* size 0x28 */
    unsigned int magic;
    unsigned int version;
    unsigned int param_sfo_offset;
    unsigned int icon0_offset;
    unsigned int icon1_offset;
    unsigned int pic0_offset;
    unsigned int pic1_offset;
    unsigned int snd0_offset;
    unsigned int boot_pg_offset;
    unsigned int pg_data_offset;
};
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

extern struct _info _info;
extern int loader_tid;
extern int error_code;

static char *fdgets_local(char *buffer, int fd);
static char *skipnonsp(char *cp);
static void split(char *line, int *count, char **column, int maxcount);
static int load_logfile_thread(SceSize argsize, void *arg);
static int load_boot_binary_thread(SceSize argsize, void *arg);
static int start_load(int (*thread_func)(SceSize, void *));
static int check_load_completed(void);
static int check_loader_dialog_completed(void);
int loader_update(void);


INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", fdgets_local);

signed char *skipsp(signed char *cp) {
    signed char *var_a0;
    signed char temp_v0;
    signed char temp_v0_2;

    var_a0 = cp;
    temp_v0 = *var_a0;
    if (((temp_v0 == 0x2C) | (temp_v0 == 0xA)) != 0) {
        do {
            *var_a0 = 0;
            var_a0 += 1;
            temp_v0_2 = *var_a0;
        } while (((temp_v0_2 == 0x2C) | (temp_v0_2 == 0xA)) != 0);
    }
    return var_a0;
}

static char *skipnonsp(char *cp)
{
	while (*cp != '\0' && *cp != ',' && *cp != '\n')
		cp++;
	return cp;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", split);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", load_logfile_thread);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/loader", load_boot_binary_thread);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/loader", D_0002DDE8);

extern int error_code_8265C;
const char D_0002DDF0[] = "AdhocDistributeServerFileLoader";

static int start_load(int (*thread_func)(SceSize, void *))
{
	int ret;

	ret = sceKernelCreateThread(D_0002DDF0, thread_func, 0x30, 0x2000, 0, NULL);
	if (ret < 0)
		goto error;
	loader_tid = ret;
	ret = sceKernelStartThread(ret, 0, NULL);
	if (ret < 0)
		goto error;
	change_state(5, 0);
	return 0;

error:
	if (loader_tid >= 0) {
		sceKernelDeleteThread(loader_tid);
		loader_tid = -1;
	}
	error_code_8265C = ret;
	ret = utility_msgdialog_fileio(ret);
	if (ret < 0)
		change_state(1, 0);
	else
		change_state(0x17, 0);
	return ret;
}

int sceKernelDeleteThread(int thid);
extern int error_code_8265C;
static int check_load_completed(void)
{
	int ret;

	ret = sceKernelGetThreadExitStatus(loader_tid);
	if (ret == (int)0x800201A4)
		return 0;
	if (ret < 0) {
		if (utility_msgdialog_fileio(error_code_8265C) < 0)
			change_state(1, 0);
		else
			change_state(0x17, 0);
	} else {
		change_state(ret, 0);
	}
	sceKernelDeleteThread(loader_tid);
	loader_tid = -1;
	return 0;
}

extern int D_0008D338;
static int check_loader_dialog_completed(void)
{
	int ret;
	int done = 0;

	ret = utility_check_msgdialog_completed(&done);
	if (ret < 0 || done) {
		if (D_0008D338 == 0)
			change_state(0, 0);
		else
			change_state(1, 0);
	}
	return ret;
}

extern unsigned int D_0008D33C;
int loader_update(void)
{
	switch (D_0008D33C) {
	case 3:
		start_load(load_logfile_thread);
		break;
	case 4:
		start_load(load_boot_binary_thread);
		break;
	case 5:
		check_load_completed();
		break;
	case 0x17:
		check_loader_dialog_completed();
		break;
	}
	return 0;
}
