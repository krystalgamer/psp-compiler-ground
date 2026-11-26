#include "common.h"

/* declarations recovered from DWARF */
struct SceIoDirent;
typedef struct SceIoStat SceIoStat;
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
struct SceIoDirent { /* size 0x160 */
    SceIoStat d_stat;
    char d_name[256];
    void *d_private;
    int dummy;
};
struct binlist_entry;
struct _anon1;
struct _anon1 { /* size 0x8 */
    struct binlist_entry *tqe_next;
    struct binlist_entry **tqe_prev;
};
struct binlist_entry { /* size 0x110 */
    struct _anon1 link;
    char name[256];
    SceOff size;
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
struct _anon2;
struct _anon2 { /* size 0x8 */
    struct binlist_entry *tqh_first;
    struct binlist_entry **tqh_last;
};

extern struct _info _info;
extern struct _anon2 binlist_head;

void binlist_init(void);
int get_binlist(void);
void free_binlist(void);
void draw_binlist(void);
void set_filename(void);
int get_filename(char *bin_filename);


extern const int D_0002EE88[3];
void binlist_init(void)
{
	binlist_head.tqh_first = NULL;
	binlist_head.tqh_last = &binlist_head.tqh_first;
	if (get_binlist() > 0) {
		set_filename();
		free_binlist();
	}
	__builtin_memcpy(_info.bin_filename, D_0002EE88, 12);
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/binlist", D_0002EE88);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/binlist", get_binlist);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/binlist", free_binlist);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/binlist", draw_binlist);

char *strcpy(char *d, const char *s);
char *strcpy(char *d, const char *s);
void set_filename(void)
{
	struct binlist_entry *entry;
	int i = 0;

	for (entry = binlist_head.tqh_first; entry != NULL; entry = entry->link.tqe_next) {
		if (i == _info.binlist_v_cursor_pos) {
			strcpy(_info.bin_filename, entry->name);
			break;
		}
		i++;
	}
}

char *strcpy(char *d, const char *s);
int get_filename(char *bin_filename)
{
	struct binlist_entry *entry;
	int i = 0;

	for (entry = binlist_head.tqh_first; entry != NULL; entry = entry->link.tqe_next) {
		if (i == _info.binlist_v_cursor_pos) {
			strcpy(bin_filename, entry->name);
			return 0;
		}
		i++;
	}
	return 0x80410C81;
}
