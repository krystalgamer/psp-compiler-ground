#include "common.h"

/* declarations recovered from DWARF */
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
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef void *__gnuc_va_list;
typedef __gnuc_va_list va_list;
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
struct log_info;
struct log_info { /* size 0x24 */
    struct ScePspDateTime start;
    struct ScePspDateTime finish;
    int error_code;
};
typedef long int time_t;
struct _info;
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
struct _anon2 { /* size 0x8 */
    struct log_display *tqh_first;
    struct log_display **tqh_last;
};

extern struct _info _info;
extern struct _anon2 log_head;
extern int log_sema;
extern int log_color[16];
extern char log_line[16][80];
extern int display_logpage;
extern unsigned int count_success;
extern unsigned int count_failure;

int log_init(void);
int insert_log(struct log_display *log);
void draw_log(void);
void draw_log_ms(void);
void adhoc_distribute_log(int color, struct SceNetEtherAddr *peer, const char *fmt, ...);
int adhoc_distribute_log_ms(struct SceNetEtherAddr *peer, struct log_info *log_info);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelDeleteSema(int semid);
void free(void *p);


INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/log", log_init);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/log", insert_log);

void free_log(void) {
    struct log_display **temp_v0;
    struct log_display *temp_s0;
    struct log_display *var_a0;

    var_a0 = log_head.tqh_first;
    if (var_a0 != NULL) {
        do {
            temp_s0 = var_a0->link.tqe_next;
            temp_v0 = var_a0->link.tqe_prev;
            if (temp_s0 != NULL) {
                temp_s0->link.tqe_prev = temp_v0;
            } else {
                log_head.tqh_last = temp_v0;
            }
            *var_a0->link.tqe_prev = temp_s0;
            free(var_a0);
            var_a0 = temp_s0;
        } while (temp_s0 != NULL);
    }
    log_head.tqh_first = NULL;
    display_logpage = 1;
    log_head.tqh_last = &log_head.tqh_first;
    count_success = 0;
    count_failure = 0;
}

void log_term(void) {
    free_log();
    if (log_sema >= 0) {
        sceKernelDeleteSema(log_sema);
        log_sema = -1;
    }
}

void log_pageup(void) {
    if (display_logpage >= 2) {
        display_logpage -= 1;
    }
}

void log_pagedown(void) {
    if ((unsigned int) display_logpage < (unsigned int) ((count_success + count_failure + 5) / 6)) {
        display_logpage += 1;
    }
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/log", draw_log);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/log", draw_log_ms);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/log", adhoc_distribute_log);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/log", adhoc_distribute_log_ms);
