/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 net_matching_moonball draw_net) */
struct SceNetAdhocctlScanInfo;
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
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
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct SceNetAdhocctlPeerInfo;
struct SceNetAdhocctlPeerInfo { /* size 0x8c */
    struct SceNetAdhocctlPeerInfo *next;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetEtherAddr mac_addr;
    SceUChar8 padding[2];
};
struct SceNetAdhocMatchingMember;
struct SceNetAdhocMatchingMember { /* size 0xc */
    struct SceNetAdhocMatchingMember *next;
    struct SceNetEtherAddr addr;
    SceUChar8 padding[2];
};
struct matching_room_info;
enum matching_room_state {
    MATCHING_ROOM_TOP = 0,
    MATCHING_ROOM_SCAN = 1,
    MATCHING_ROOM_SCANNING = 2,
    MATCHING_ROOM_SCAN_RESULT = 3,
    MATCHING_ROOM_CONNECT_ROOM = 4,
    MATCHING_ROOM_CONNECTING_ROOM = 5,
    MATCHING_ROOM_DISCONNECT_ROOM = 6,
    MATCHING_ROOM_DISCONNECTING_ROOM = 7,
    MATCHING_ROOM_CONNECTING_GAME = 8,
    MATCHING_ROOM_DISCONNECTING = 9,
    MATCHING_ROOM_ERROR_DIALOG = 10,
    MATCHING_ROOM_ROOM_LIST = 11,
    MATCHING_ROOM_NEIGHBORS = 12,
    MATCHING_ROOM_REQUESTING = 13,
    MATCHING_ROOM_CANCELED = 14,
    MATCHING_ROOM_DENIED = 15,
    MATCHING_ROOM_START_GAME = 16,
    MATCHING_ROOM_DISCONNECT = 17,
    MATCHING_ROOM_CHILD_ENTER_ROOM = 18,
    MATCHING_ROOM_CHILD_WAIT = 19,
    MATCHING_ROOM_CREATE_ROOM = 20,
    MATCHING_ROOM_PARENT_WAIT = 21,
    MATCHING_ROOM_PARENT_START_INFORM = 22,
    MATCHING_ROOM_PARENT_INFORM_CONNECT = 23,
    MATCHING_ROOM_PARENT_INFORM_SEND = 24,
    MATCHING_ROOM_PARENT_INFORM_FLUSH = 25,
    MATCHING_ROOM_GAME = 26,
};
struct p2p_hello_opt;
struct p2p_hello_opt_game_param;
struct p2p_hello_opt_game_param { /* size 0x0 */

};
enum game_type {
    GAME_TYPE_CHILD = 0,
    GAME_TYPE_PARENT = 1,
};
struct p2p_hello_opt { /* size 0x8c */
    struct SceNetAdhocctlNickname nickname;
    struct p2p_hello_opt_game_param game_param;
    enum game_type game_type;
    int cur_player_num;
    int req_player_num;
};
typedef long long unsigned int SceULong64;
struct matching_room_info { /* size 0xd8 */
    enum matching_room_state state;
    struct p2p_hello_opt hello_opt;
    struct p2p_hello_opt *agreed_hello_opt;
    int requesting_minfo_id;
    int v_cursor_pos;
    int ignore_pad_input;
    struct SceNetEtherAddr local_addr;
    int ctx_id;
    struct SceNetEtherAddr members[4];
    struct SceNetEtherAddr parent_addr;
    int informing_minfo_id;
    SceULong64 ptp_start_time;
};
struct minfo;
struct minfo { /* size 0x98 */
    int status;
    struct SceNetEtherAddr addr;
    struct p2p_hello_opt hello_opt;
};

extern struct matching_room_info _mrinfo;
extern int minfo_sid;
extern struct minfo minfo[16];
extern struct SceNetAdhocctlPeerInfo peerinfo[16];
extern struct SceNetAdhocctlScanInfo scaninfo[32];
extern struct SceNetAdhocMatchingMember mmember[17];

void draw_net_scan_result_list(int x, int y);
void draw_net_hello_list(int x, int y);
void draw_net_established_list(int *x_ptr, int *y_ptr);
static int get_nickname(int buflen, struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname **n);
void draw_net_member_list(int *x_ptr, int *y_ptr);
void draw_net_neighbors(int x, int y);

extern int net_error;
extern int net_gid[];
extern int net_num;
extern int net_pause;
extern int net_timeerror;
int pad_sw(void);
int net_update(void);
int net_gamecomm_packinit(void);

typedef struct { int f[10]; } WIN_T;
extern WIN_T win[4];
extern int D_0039AE3C;
void utility_update_netconf(void);
void utility_update_msgdialog(void);
void psp_loopstart(void);
void psp_loopend(void);
int sceGuSync(int mode, int what);
void game_net_term(void);
int _net_term(void);
int sceNetAdhocctlGetState(int *state);
int net_lobbysub(void);
int matching_get_established_num(void);

extern WIN_T win[4];
extern int D_0039AE3C;
void utility_update_netconf(void);
void utility_update_msgdialog(void);
void psp_loopstart(void);
void psp_loopend(void);
int sceGuSync(int mode, int what);
void game_net_term(void);
int _net_term(void);
int sceNetAdhocctlGetState(int *state);
int net_lobbysub(void);
int matching_get_established_num(void);
void win_init(void)
{
	int i;

	for (i = 0; i < 4; i++) {

		win[i].f[0] = 0;
		win[i].f[6] = 0;
		win[i].f[9] = 0;
		win[i].f[1] = 0;
		win[i].f[2] = 0;
		win[i].f[5] = 1;
		win[i].f[8] = 0;
		win[i].f[7] = 1;
		win[i].f[3] = 0;
		win[i].f[4] = 0;

	}
}

void gu_init(void) {
}

void utility_update(void)
{
	switch ((int)_mrinfo.state) {
	case 5:
	case 8:
		utility_update_netconf();
		break;
	case 10:
		utility_update_msgdialog();
		break;
	}
}

void change_state(enum matching_room_state state) {
    if (state != MATCHING_ROOM_ROOM_LIST) {

    } else {
        net_delete_ptp();
    }
    _mrinfo.state = state;
    _mrinfo.v_cursor_pos = 0;
}

int memcmp(const void *a, const void *b, unsigned int n);
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
static int get_nickname(int buflen, struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname **n)
{
	struct SceNetAdhocctlPeerInfo *p;
	char buf[32];
	int ret = 0;

	if (buflen == 0) {
		ret = 2;
		goto end;
	}
	if (memcmp(&_mrinfo.local_addr, addr, 6) == 0) {
		if (_mrinfo.hello_opt.nickname.data[0] != 0) {
			*n = &_mrinfo.hello_opt.nickname;
			ret = 1;
		}
		goto end;
	}
	for (p = peerinfo; p != NULL; p = p->next) {
		if (memcmp(&p->mac_addr, addr, 6) != 0)
			continue;
		if (p->nickname.data[0] != 0) {
			*n = &p->nickname;
			ret = 1;
		} else {
			sceNetEtherNtostr(&p->mac_addr, buf);
		}
		break;
	}
end:
	return ret;
}

void ASC_SetStringRGBA(int font, char *str, int x, int y, int r, int g, int b, int a);
int sprintf(char *buf, const char *fmt, ...);
void draw_p2p_game_parameter(int index, int color, int x, int y)
{
	char mess_buff[128];

	if (D_0039AE3C != 0)
		return;
	sprintf(mess_buff, "PlayerNum: %d/%d", minfo[index].hello_opt.cur_player_num, minfo[index].hello_opt.req_player_num);
	if (color == 0xffffff)
		ASC_SetStringRGBA(2, mess_buff, x, y, 255, 255, 255, 255);
	else if (color == 0xff)
		ASC_SetStringRGBA(2, mess_buff, x, y, 255, 0, 0, 255);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", D_0007B554);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_established_list);

int sceNetAdhocctlGetScanInfo(int *buflen, struct SceNetAdhocctlScanInfo *buf);
int snprintf(char *buf, unsigned int size, const char *fmt, ...);
void *memcpy(void *d, const void *s, unsigned int n);
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
void inv_font_ascii(char *str, int x, int y, int w, int h, int r, int g, int b, int a);
void draw_net_scan_result_list(int x, int y)
{
	char group_name_str[9];
	struct SceNetAdhocctlScanInfo *sinfo;
	char mess_buff[128];
	int ret, buflen;

	buflen = sizeof(scaninfo);
	ret = sceNetAdhocctlGetScanInfo(&buflen, scaninfo);
	if (ret < 0)
		return;
	if (buflen != 0) {
		for (sinfo = scaninfo; sinfo != NULL; sinfo = sinfo->next) {
			ret = snprintf(mess_buff, sizeof(mess_buff), "ch: %d  BSSID: ", sinfo->channel);
			sceNetEtherNtostr((struct SceNetEtherAddr *)&sinfo->bssid, mess_buff + ret);
			memcpy(group_name_str, sinfo->group_name.data, 8);
			group_name_str[8] = '\0';
			inv_font_ascii(mess_buff, x, y, 100, 100, 255, 255, 255, 255);
			y += 0x18;
		}
	}
}

extern char D_0007B554[];
int sceNetAdhocMatchingGetMembers(int id, int *buflen, struct SceNetAdhocMatchingMember *buf);
int sceNetAdhocctlGetPeerList(int *buflen, struct SceNetAdhocctlPeerInfo *buf);
int sceNetEtherStrton(const char *str, unsigned char *mac);
char mac2a(int c);
unsigned int strlen(const char *s);
void *memset(void *s, int c, unsigned int n);
void ASC_Init(int a, int tex);
void ASC_Reset(void);
void ASC_SetStringRGBALEN(int mode, char *s, int x, int y, int r, int g, int b, int a, int len);
int sprite_set(int tex, int x, int y, int w, int h, int u, int v, int sw, int sh, int a9, int a10, int r, int g, int b, int a, int pri, int mode, int a17, int alpha);
extern int gp_tex[4], lfont_tex, font_tex_28DDA0;
extern int gppostbl[][2];
void draw_net_member_list(int *x_ptr, int *y_ptr)
{
	char etherstr[32];
	unsigned char mac[16];
	char mess_buff[128];
	char str[64];
	int buflen;
	struct SceNetAdhocctlNickname *nickname;
	struct SceNetAdhocMatchingMember *m;
	int ret, n, len;

	buflen = sizeof(mmember);
	ret = sceNetAdhocMatchingGetMembers(_mrinfo.ctx_id, &buflen, mmember);
	if (ret < 0)
		goto error;
	if (buflen == 0)
		goto error;
	buflen = sizeof(peerinfo);
	ret = sceNetAdhocctlGetPeerList(&buflen, peerinfo);
	if (ret < 0)
		goto error;
	n = 0;
	for (m = &mmember[0]; m != NULL; m = m->next) {
		sceNetEtherNtostr(&m->addr, etherstr);
		ret = get_nickname(buflen, &m->addr, &nickname);
		memset(mess_buff, 0, sizeof(mess_buff));
		if (ret == 2)
			goto error;
		if (0 < ret) {
			sceNetEtherStrton(etherstr, mac);
			str[0] = mac2a(mac[0]);
			str[1] = mac2a(mac[1]);
			str[2] = mac2a(mac[2]);
			str[3] = mac2a(mac[3]);
			str[4] = mac2a(mac[4]);
			str[5] = mac2a(mac[5]);
			str[6] = 0;
			sprintf(mess_buff, D_0007B554, etherstr);
		} else
			sprintf(mess_buff, "# NO NICKNAME\n");
		len = strlen(mess_buff) - 1;
		if (len != win[n].f[8]) {
			ASC_Init(0, font_tex_28DDA0);
			ASC_Reset();
			win[n].f[1] = gppostbl[n][0] + 16;
			win[n].f[2] = gppostbl[n][1];
			win[n].f[4] = gppostbl[n][1];
			win[n].f[5] = 1;
			win[n].f[3] = gppostbl[n][0] + 16;
			win[n].f[7] = 2;
			win[n].f[9] = 0;
		}
		if (win[n].f[0] == 0) {
			win[n].f[1] = gppostbl[n][0] + 16;
			win[n].f[3] = gppostbl[n][0] + 16;
			win[n].f[0] = 1;
			win[n].f[2] = gppostbl[n][1];
			win[n].f[4] = gppostbl[n][1];
			win[n].f[5] = 1;
			win[n].f[7] = 2;
		}
		win[n].f[8] = len;
		ASC_SetStringRGBALEN(2, mess_buff, gppostbl[n][0] + 16, gppostbl[n][1], 0x40, 255, 255, 255, win[n].f[5]);
		if (win[n].f[9] % win[n].f[7] == 0) {
			win[n].f[6] = (win[n].f[6] + 1) & 1;
			win[n].f[3] += 8;
			win[n].f[5]++;
			if (len < win[n].f[5]) {
				win[n].f[5] = len;
				win[n].f[3] = gppostbl[n][0] + len * 8 + 16;
				win[n].f[7] = 20;
			}
		}
		win[n].f[9]++;
		if (win[n].f[6])
			sprite_set(lfont_tex, win[n].f[3], gppostbl[n][1], 8, 8, 8, 0x1C8, 100, 100, 0, 0, 0x40, 255, 255, 255, 100, 2, 1, 255);
		sprite_set(gp_tex[n], gppostbl[n][0], gppostbl[n][1], 16, 16, 0, 0, 100, 100, 0, 0, 255, 255, 255, 255, 100, 2, 1, 255);
		n++;
	}
error:
	return;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", draw_net_hello_list);

extern char D_0007B5A8[];
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
int sceNetAdhocctlGetPeerList(int *buflen, struct SceNetAdhocctlPeerInfo *buf);
int sprintf(char *buf, const char *fmt, ...);
void inv_font_ascii(char *str, int x, int y, int w, int h, int r, int g, int b, int a);
void draw_net_neighbors(int x, int y)
{
	char etherstr[32];
	struct SceNetAdhocctlPeerInfo *peer;
	char mess_buff[128];
	int ret, buflen;

	buflen = sizeof(peerinfo);
	ret = sceNetAdhocctlGetPeerList(&buflen, peerinfo);
	if (ret < 0)
		return;
	if (buflen == 0)
		return;
	for (peer = peerinfo; peer != NULL; peer = peer->next) {
		sceNetEtherNtostr(&peer->mac_addr, etherstr);
		if (peer->nickname.data[0] != 0)
			sprintf(mess_buff, "# \"%s\" (%s)", peer->nickname.data, etherstr);
		else
			sprintf(mess_buff, D_0007B5A8, etherstr);
		inv_font_ascii(mess_buff, x, y, 100, 100, 255, 255, 255, 255);
		y += 0x18;
	}
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", D_0007B5A8);

extern char D_0007B5A8[];
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
int sceNetAdhocctlGetPeerList(int *buflen, struct SceNetAdhocctlPeerInfo *buf);
int sprintf(char *buf, const char *fmt, ...);
void debug_text(int x, int y, char *s);
void draw_net_scan(void)
{
	char etherstr[32];
	struct SceNetAdhocctlPeerInfo *peer;
	char mess_buff[128];
	int ret, y, buflen;

	buflen = sizeof(peerinfo);
	ret = sceNetAdhocctlGetPeerList(&buflen, peerinfo);
	if (ret < 0)
		return;
	y = 0x60;
	for (peer = peerinfo; peer != NULL; peer = peer->next) {
		sceNetEtherNtostr(&peer->mac_addr, etherstr);
		if (peer->nickname.data[0] != 0)
			sprintf(mess_buff, "#%s", etherstr);
		else
			sprintf(mess_buff, D_0007B5A8, etherstr);
		debug_text(0, y, mess_buff);
		y += 8;
	}
}

int sprintf(char *s, const char *fmt, ...);
void inv_font_ascii(char *str, int x, int y, int w, int h, int r, int g, int b, int a);
int inv_font_ascii_check_w(char *s, int size);
void draw_canceled(void)
{
	char buf[128];
	int w;

	sprintf(buf, "Request is Canceled by peer");
	inv_font_ascii(buf, 0x45, 0x6A, 0x64, 0x64, 0xFF, 0xFF, 0xFF, 0xFF);
	w = inv_font_ascii_check_w("x: Close", 0x50);
	sprintf(buf, "x: Close");
	inv_font_ascii(buf, (480 - w) / 2, 0xF8, 0x50, 0x50, 0xFF, 0xFF, 0xFF, 0xFF);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", drawpic);

extern unsigned char netdata[];
void *memset(void *s, int c, unsigned int n);
void net_init(void)
{
	memset(netdata, 0, 0xfc0);
	memset(&_mrinfo.hello_opt, 0, sizeof(_mrinfo.hello_opt));
	_mrinfo.hello_opt.req_player_num = 4;
	change_state(-1);
	memset(net_gid, 0, 18);
	net_num = 0;
	net_pause = 0;
	net_error = 1;
	net_timeerror = 1;
}

extern int net_error;
extern int net_gid[];
extern int net_num;
extern int net_pause;
extern int net_timeerror;
int pad_sw(void);
int net_update(void);
int net_gamecomm_packinit(void);
void net_core(void)
{
	utility_update();
	net_update();
}

void net_term(void)
{
	int state;

	sceNetAdhocctlGetState(&state);
	change_state(17);
	do {
		psp_loopstart();
		psp_loopend();
		net_gamecomm_pack();
	} while (_mrinfo.state != 0);
	game_net_term();
	_net_term();
}

extern int lobby_tex, gp_tex[4], lfont_tex, font_tex_28DDA0, lfont_tex2[25], loop_28DD30, old_state, moji_a, game_cpu_disp;
int bmp_file_load16(char *name);
int bmp_file_load(char *name);
unsigned char *LoadFile(char *name, int *size);
int bmp_addr_load16(void *addr);
void bmp_file_unload(int tex);
void psp_free(void *p);
void ASC_Init(int a, int tex);
void ASC_Disp(void *a, int b);
void ASC_Reset(void);
void poly_set(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7,
	int s0, int s1, int s2, int s3, int s4, int s5, int s6, int s7,
	int s8, int s9, int s10, int s11, int s12, int s13, int s14, int s15, int s16);
void drawpic(void);
int Lobby_pad_read(void);
void net_core(void);
int net_lobbysub(void)
{
	int size;
	int ret;
	unsigned char *buf, *p;
	int i, y, cnt;

	lobby_tex = bmp_file_load16("lobby.bmp");
	gp_tex[0] = bmp_file_load16("gp.bmp");
	gp_tex[1] = bmp_file_load16("gp1.bmp");
	gp_tex[2] = bmp_file_load16("gp2.bmp");
	gp_tex[3] = bmp_file_load16("gp3.bmp");
	lfont_tex = bmp_file_load16("lfont.bmp");
	font_tex_28DDA0 = bmp_file_load("tex_asc.bmp");
	buf = LoadFile("lfont.dat", &size);
	p = buf + 8;
	for (i = 0; i < 25; i++) {
		lfont_tex2[i] = bmp_addr_load16(buf + ((p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3]));
		p += 8;
	}
	psp_free(buf);
	ASC_Init(0, font_tex_28DDA0);
	game_cpu_disp = 0;
	loop_28DD30 = 1;
	net_error = 1;
	old_state = 0;
	moji_a = 0;
	net_num = 0;
	net_pause = 0;
	change_state(0);
	y = 0x120;
	while (loop_28DD30) {
		psp_loopstart();
		drawpic();
		switch (Lobby_pad_read()) {
		case 1:
			ret = 1;
			loop_28DD30 = 0;
			break;
		case 2:
			ret = 2;
			loop_28DD30 = 0;
			break;
		}
		ASC_Disp(0, 1);
		ASC_Reset();
		poly_set(0, y, 480, 64, 0, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 255, 2, 1, 255);
		y--;
		if (y < -16)
			y = 0x120;
		sceGuSync(0, 0);
		net_core();
		psp_loopend();
	}
	loop_28DD30 = 1;
	cnt = 2;
	while (loop_28DD30) {
		cnt--;
		psp_loopstart();
		psp_loopend();
		if (cnt == 0)
			loop_28DD30 = 0;
	}
	game_cpu_disp = 1;
	for (i = 0; i < 25; i++)
		bmp_file_unload(lfont_tex2[i]);
	bmp_file_unload(font_tex_28DDA0);
	bmp_file_unload(lfont_tex);
	bmp_file_unload(lobby_tex);
	bmp_file_unload(gp_tex[0]);
	bmp_file_unload(gp_tex[1]);
	bmp_file_unload(gp_tex[2]);
	bmp_file_unload(gp_tex[3]);
	return ret;
}

int net_lobby(void)
{
	int ret;

	ret = net_lobbysub();
	if (ret == 1)
		return 1;
	if (ret == 2)
		return 2;
	return 1;
}

int net_gamecomm_pack(void)
{
	net_core();
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_netmain", net_gamecomm_packinit);

int net_gamecomm_packend(void)
{
	if (net_errorget() == 2) {
		do {
			psp_loopstart();
			sceGuSync(0, 0);
			net_gamecomm_pack();
			psp_loopend();
		} while (_mrinfo.state != 0);
		return 1;
	}
	return _mrinfo.state == 0;
}

int net_mynumget(void)
{
	return net_num;
}

void net_mynumset(int num)
{
	net_num = num;
}

int net_errorget(void)
{
	return net_error;
}

void net_errorset(int err)
{
	net_error = err;
}

int net_gidget(int i)
{
	return net_gid[i];
}

int *net_gidgetadd(void)
{
	return net_gid;
}

void net_gidset(int gid, int i)
{
	net_gid[i] = gid;
}

void net_pauseset(void)
{
	net_pause = (net_pause + 1) & 1;
}

void net_pausewait(void)
{
	net_timeerror = 0;
	net_gamecomm_packinit();
	net_timeerror = 1;
}

int net_pauseget(void)
{
	return net_pause;
}

int net_entryget(void)
{
	if (D_0039AE3C)
		return matching_get_established_num();
	return 0;
}

int net_timeerrorget(void)
{
	return net_timeerror;
}

int net_user_cancel(void)
{
	if (pad_sw() & 8)
		return 1;
	return 0;
}
