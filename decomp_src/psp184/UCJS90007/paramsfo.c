#include "common.h"

/* declarations recovered from DWARF */
typedef void *SceSystemFileFormat;
typedef void *SceSystemFileIndex;
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

int parse_paramsfo(void *paramsfo);
int get_paramsfo(char *bin_filename);


void *memset(void *s, int c, unsigned int n);
int sceSystemFileLoadAll(void *buf, void **phandle);
int sceSystemFileGetIndex(void *handle, const char *name, void **pindex);
int sceSystemFileGetValue(void *handle, void *index, void *buf);
int sceSystemFileGetIndexInfo(void *handle, void *index, char **pname, unsigned int *plen, unsigned int *pmaxlen);
int sceSystemFileFree(void *handle);
void *memset(void *s, int c, unsigned int n);
int parse_paramsfo(void *paramsfo)
{
	int ret;
	SceSystemFileFormat sysformat = NULL;
	SceSystemFileIndex index;
	char *tmp_char;
	unsigned int tmp_uint;

	ret = sceSystemFileLoadAll(paramsfo, &sysformat);
	if (ret < 0)
		goto error;
	ret = sceSystemFileGetIndex(sysformat, "TITLE", &index);
	if (ret < 0)
		goto error;
	memset(_info.paramsfo_title, 0, sizeof(_info.paramsfo_title));
	ret = sceSystemFileGetValue(sysformat, index, _info.paramsfo_title);
	if (ret < 0)
		goto error;
	ret = sceSystemFileGetIndexInfo(sysformat, index, &tmp_char, &_info.paramsfo_title_len, &tmp_uint);
	if (ret < 0)
		goto error;
	ret = sceSystemFileGetIndex(sysformat, "DISC_ID", &index);
	if (ret < 0)
		goto error;
	memset(_info.paramsfo_discid, 0, sizeof(_info.paramsfo_discid));
	ret = sceSystemFileGetValue(sysformat, index, _info.paramsfo_discid);
	if (ret < 0)
		goto error;
	ret = sceSystemFileGetIndexInfo(sysformat, index, &tmp_char, &_info.paramsfo_discid_len, &tmp_uint);
	if (ret < 0)
		goto error;
	ret = sceSystemFileGetIndex(sysformat, "PARENTAL_LEVEL", &index);
	if (ret < 0)
		goto error;
	ret = sceSystemFileGetValue(sysformat, index, &_info.paramsfo_parental);
error:
	if (sysformat != NULL)
		sceSystemFileFree(sysformat);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/paramsfo", get_paramsfo);
