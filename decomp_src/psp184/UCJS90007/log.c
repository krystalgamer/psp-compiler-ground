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


int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
void *memset(void *s, int c, unsigned int n);
char *strcpy(char *dst, const char *src);
int log_init(void)
{
	int ret;

	log_head.tqh_first = NULL;
	log_head.tqh_last = &log_head.tqh_first;
	display_logpage = 1;
	count_success = 0;
	count_failure = 0;
	ret = sceKernelCreateSema("AdhocDistributeServerLog", 0, 1, 1, NULL);
	if (ret < 0)
		goto error;
	log_sema = ret;
	memset(log_color, 0, sizeof(log_color));
	memset(log_line, 0, sizeof(log_line));
	strcpy(_info.log_filename, "GSSLOG.CSV");
error:
	return ret;
}

int atoi(const char *s);
int insert_log(struct log_display *log)
{
	log->link.tqe_next = NULL;
	log->link.tqe_prev = log_head.tqh_last;
	*log_head.tqh_last = log;
	log_head.tqh_last = &log->link.tqe_next;
	if (atoi(log->error_code) == 0)
		count_success++;
	else
		count_failure++;
	return 0;
}

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

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sprintf(char *buf, const char *fmt, ...);
void *memcpy(void *d, const void *s, unsigned int n);
int sceKernelWaitSema(int semaid, int signal, unsigned int *timeout);
int sceKernelSignalSema(int semaid, int signal);
int sceNetEtherNtostr(struct SceNetEtherAddr *mac, char *name);
int sceRtcGetCurrentClockLocalTime(struct ScePspDateTime *time);
int sprintf(char *buf, const char *fmt, ...);
int vsprintf(char *buf, const char *fmt, va_list ap);
void *memcpy(void *dst, const void *src, unsigned int n);
void adhoc_distribute_log(int color, struct SceNetEtherAddr *peer, const char *fmt, ...)
{
	va_list ap;
	struct ScePspDateTime time;
	char ether_buff[64];
	int i;
	int len;
	int ret;

	ret = sceKernelWaitSema(log_sema, 1, NULL);
	if (ret < 0)
		return;
	for (i = 0; i < 15; i++) {
		log_color[i] = log_color[i + 1];
		memcpy(log_line[i], log_line[i + 1], sizeof(log_line[i]));
	}
	log_color[15] = color;
	sceNetEtherNtostr(peer, ether_buff);
	sceRtcGetCurrentClockLocalTime(&time);
	len = sprintf(log_line[15], "%02d/%02d %02d:%02d:%02d %s ", time.month, time.day, time.hour, time.minute, time.second, ether_buff);
	__builtin_va_start(ap, fmt);
	vsprintf(log_line[15] + len, fmt, ap);
	__builtin_va_end(ap);
	sceKernelSignalSema(log_sema, 1);
}

int sceIoOpen(const char *name, int flag, int mode);
int sceIoClose(int fd);
int sceIoWrite(int fd, const void *buf, unsigned int nbyte);
unsigned int strlen(const char *s);
int sceNetEtherNtostr(struct SceNetEtherAddr *mac, char *name);
int sceRtcGetCurrentClockLocalTime(struct ScePspDateTime *time);
int sprintf(char *buf, const char *fmt, ...);
char *strncat(char *dst, const char *src, unsigned int n);
int sceIoOpen(const char *name, int flag, int mode);
int sceIoWrite(int fd, const void *data, unsigned int size);
int sceIoClose(int fd);
int sceRtcGetTime_t(const struct ScePspDateTime *date, unsigned int *time);
unsigned int strlen(const char *s);
int adhoc_distribute_log_ms(struct SceNetEtherAddr *peer, struct log_info *log_info)
{
	int fd;
	char filename[256];
	char src_buff[32];
	char dst_buff[32];
	char log_buff[256];
	unsigned int start_time;
	unsigned int finish_time;

	strcpy(filename, "ms0:/");
	strncat(filename, _info.log_filename, 128);
	fd = sceIoOpen(filename, 0x302, 0644);
	if (fd < 0)
		return -1;
	sceNetEtherNtostr(&_info.local_addr, src_buff);
	sceNetEtherNtostr(peer, dst_buff);
	sceRtcGetTime_t(&log_info->start, &start_time);
	sceRtcGetTime_t(&log_info->finish, &finish_time);
	sprintf(log_buff, "%s,%d,%s,%s,%04d/%02d/%02d,%02d:%02d:%02d,%04d/%02d/%02d,%02d:%02d:%02d,%ld,%x\n",
		_info.paramsfo_discid, _info.ibss_param.channel, src_buff, dst_buff,
		log_info->start.year, log_info->start.month, log_info->start.day,
		log_info->start.hour, log_info->start.minute, log_info->start.second,
		log_info->finish.year, log_info->finish.month, log_info->finish.day,
		log_info->finish.hour, log_info->finish.minute, log_info->finish.second,
		finish_time - start_time, log_info->error_code);
	sceIoWrite(fd, log_buff, strlen(log_buff));
	sceIoClose(fd);
	return 0;
}
