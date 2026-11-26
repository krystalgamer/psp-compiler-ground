/* cflags: -O2 */
#include "common.h"

extern int evf;
extern int error_code;
extern int error_code_daialog;
extern char game_group_name[];
extern int D_0039AE60;
struct SceNetEtherAddr;
int sceNetAdhocMatchingSelectTarget(int id, struct SceNetEtherAddr *addr, int optlen, void *opt);
static int check_error_dialog_closed(void);

extern char *nametbl[];
extern char lobby_group_name[];
extern int D_0039AE54;
int sceNetAdhocctlGetParameter(void *param);
int sceNetEtherNtostr(void *mac, char *str);
int utility_net_connect(char *name);
void change_state(int state);
int utility_msgdialog(int err);
int utility_check_msgdialog_completed(int *res);

extern char *nametbl[];
extern char lobby_group_name[];
extern int D_0039AE54;
int sceNetAdhocctlGetParameter(void *param);
int sceNetEtherNtostr(void *mac, char *str);
int utility_net_connect(char *name);
void change_state(int state);
int utility_msgdialog(int err);
int utility_check_msgdialog_completed(int *res);
extern int _mrinfo;
extern int handlerId;
int rand(void);
int sceNetAdhocctlDelHandler(int id);
int sceNetAdhocctlTerm(void);
int sceNetAdhocTerm(void);
int sceNetTerm(void);
int sceNetAdhocctlScan(void);
int sceNetAdhocctlDisconnect(void);
int sceNetAdhocctlGetState(int *state);
int net_delete_ptp(void);
void matching_term(void);
int game_term(void);

typedef struct { int state; char pad[0x9c]; u8 local_addr[6]; } MRI_SN;
int game_init(void);
int matching_start(void);
int sceNetGetLocalEtherAddr(void *addr);
int utility_check_connect_completed(int *result);
extern char game_group_name[];
int net_gidget(int i);
char mac2a(int c);
void gu_init(void);
int net_pauseget(void);
void send_recv_game_data(void);
void net_update_multi_player(void);

extern u8 adhoc_id[];
extern u8 D_0039ADBC[];
int sceNetInit(int a, int b, int c, int d, int e);
int sceNetAdhocInit(void);
int sceNetAdhocctlInit(int stack, int prio, void *id);
int sceNetAdhocctlAddHandler(void *h, void *arg);
void *memset(void *, int, unsigned int);
int _net_term(void);

char mac2a(int n)
{
	return *nametbl[n % 62];
}

extern int _mrinfo;
extern int handlerId;
int rand(void);
int sceNetAdhocctlDelHandler(int id);
int sceNetAdhocctlTerm(void);
int sceNetAdhocTerm(void);
int sceNetTerm(void);
int sceNetAdhocctlScan(void);
int sceNetAdhocctlDisconnect(void);
int sceNetAdhocctlGetState(int *state);
int net_delete_ptp(void);
void matching_term(void);
int game_term(void);
static unsigned int get_random_num(unsigned int min, unsigned int max)
{
	unsigned int num;

	if (max == min)
		return min;
	num = rand();
	return num / (0x7fffffff / (max - min + 1) + 1) + min;
}

int get_bssid(char *str)
{
	struct { u8 pad[0x8C]; u8 bssid[6]; u8 pad2[10]; } param;
	int ret;

	ret = sceNetAdhocctlGetParameter(&param);
	if (ret >= 0)
		sceNetEtherNtostr(param.bssid, str);
	return ret;
}

extern u8 adhoc_id[];
extern u8 D_0039ADBC[];
int sceNetInit(int a, int b, int c, int d, int e);
int sceNetAdhocInit(void);
int sceNetAdhocctlInit(int stack, int prio, void *id);
int sceNetAdhocctlAddHandler(void *h, void *arg);
void *memset(void *, int, unsigned int);
int _net_term(void);
int randomize_group_name(char *group_name)
{
	unsigned int len;
	unsigned int i;
	char *ptr;

	len = get_random_num(1, 8);
	memset(group_name, 0, 8);
	ptr = group_name;
	for (i = 0; i < len; i++)
		ptr[i] = get_random_num('A', 'Z');
	return 0;
}

int sceNetAdhocMatchingSelectTarget(int id, struct SceNetEtherAddr *addr, int optlen, void *opt);
static int check_error_dialog_closed(void);
static void clear_evf(void)
{
	evf = 0;
	error_code = 0;
	error_code_daialog = 0;
}

int error_code_daialogget(void)
{
	return error_code_daialog;
}

static void adhocctl_handler(int event, int error, void *arg)
{
	if (event == 0) {
		error_code = error;
		error_code_daialog = 1;
		evf |= 0x01;
	} else if (event == 1) {
		error_code_daialog = 0;
		evf |= 0x02;
		error_code = 0;
	} else if (event == 2) {
		error_code_daialog = 0;
		evf |= 0x04;
		error_code = 0;
	} else if (event == 3) {
		error_code_daialog = 0;
		evf |= 0x08;
		error_code = 0;
	} else if (event == 4) {
		error_code_daialog = 0;
		evf |= 0x10;
		error_code = 0;
	}
}

static int polling_error(void)
{
	int ret;

	ret = 0;
	if (evf & 1) {
		evf &= ~1;
		ret = error_code;
	}
	return ret;
}

int _net_init(void)
{
	int ret;

	ret = sceNetInit(0x20000, 0x20, 0x1000, 0x20, 0x1000);
	if (ret < 0)
		goto error;
	ret = sceNetAdhocInit();
	if (ret < 0)
		goto error;
	ret = sceNetAdhocctlInit(0x2000, 0x30, adhoc_id);
	if (ret < 0)
		goto error;
	clear_evf();
	ret = sceNetAdhocctlAddHandler(adhocctl_handler, 0);
	if (ret < 0)
		goto error;
	handlerId = ret;
	memset(D_0039ADBC, 0, 0x8c);
	*(int *)(D_0039ADBC + 0x88) = 4;
	change_state(-1);
	return 0;

error:
	_net_term();
	return -1;
}

int _net_term(void)
{
	if (handlerId >= 0) {
		sceNetAdhocctlDelHandler(handlerId);
		handlerId = -1;
	}
	sceNetAdhocctlTerm();
	sceNetAdhocTerm();
	sceNetTerm();
}

static int net_scan(void)
{
	int ret;

	evf = 0;
	ret = sceNetAdhocctlScan();
	if (ret < 0) {
		change_state(0);
	} else if (_mrinfo == 1) {
		change_state(2);
	}
	return ret;
}

static int net_connect(void)
{
	int ret;

	ret = utility_net_connect(lobby_group_name);
	if (ret < 0) {
		change_state(0);
	} else {
		change_state(5);
	}
	return ret;
}

static int net_disconnect(void)
{
	int ret;

	net_delete_ptp();
	matching_term();
	game_term();
	ret = sceNetAdhocctlDisconnect();
	if (ret < 0) {
	} else if (_mrinfo == 16) {
		change_state(7);
	} else if (_mrinfo == 17) {
		change_state(9);
	}
	return 0;
}

static int check_adhocctl_scan_completed(void)
{
	int state;
	int ret;

	ret = 0;
	if (!(evf & 9))
		goto end;
	ret = sceNetAdhocctlGetState(&state);
	if (ret < 0)
		goto end;
	if (state == 2)
		goto end;
	ret = polling_error();
	if (ret < 0)
		change_state(0);
	else
		change_state(3);
end:
	return ret;
}

int game_init(void);
int matching_start(void);
int sceNetGetLocalEtherAddr(void *addr);
int utility_check_connect_completed(int *result);
extern char game_group_name[];
int net_gidget(int i);
char mac2a(int c);
void gu_init(void);
int net_pauseget(void);
void send_recv_game_data(void);
void net_update_multi_player(void);
static int check_adhocctl_connect_completed(void)
{
	int ret;
	int done_flag;

	ret = 0;
	done_flag = 0;
	utility_check_connect_completed(&done_flag);
	if (done_flag > 0) {
		switch (_mrinfo) {
		case 5:
			sceNetGetLocalEtherAddr(((MRI_SN *)&_mrinfo)->local_addr);
			ret = matching_start();
			if (ret < 0)
				change_state(17);
			else
				change_state(11);
			break;
		case 8:
			ret = game_init();
			if (ret < 0)
				change_state(17);
			else
				change_state(26);
			break;
		}
	} else if (done_flag < 0) {
		change_state(0);
		D_0039AE54 = 1;
	}
	return ret;
}

static int check_adhocctl_disconnect_completed(void)
{
	char buf[0x30];
	int adhocctl_state;
	int ret;

	ret = sceNetAdhocctlGetState(&adhocctl_state);
	if (ret < 0)
		return ret;
	if (adhocctl_state != 0)
		return ret;
	switch (_mrinfo) {
	case 7:
		game_group_name[0] = mac2a(net_gidget(0));
		game_group_name[1] = mac2a(net_gidget(1));
		game_group_name[2] = mac2a(net_gidget(2));
		game_group_name[3] = mac2a(net_gidget(3));
		game_group_name[4] = mac2a(net_gidget(4));
		game_group_name[5] = mac2a(net_gidget(5));
		game_group_name[6] = mac2a(net_gidget(6));
		game_group_name[7] = mac2a(net_gidget(7));
		ret = utility_net_connect(game_group_name);
		if (ret < 0)
			change_state(0);
		else
			change_state(8);
		break;
	case 9:
		gu_init();
		change_state(0);
		break;
	}
	return ret;
}

static int check_adhocctl_connected_error(void)
{
	int ret;

	ret = polling_error();
	if (ret == 0)
		goto end;
	ret = utility_msgdialog(ret);
	if (ret < 0)
		goto end;
	change_state(10);
end:
	return ret;
}

int utility_check_msgdialog_completed(int *result);
static int check_error_dialog_closed(void)
{
	int result;

	result = 0;
	utility_check_msgdialog_completed(&result);
	if (result) {
		change_state(17);
		D_0039AE54 = 1;
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", net_update);

int utility_update_shutdown(void)
{
	return check_error_dialog_closed();
}

extern int D_0039AE40;
int matching_get_established_num(void) {
    return D_0039AE40 - 1;
}

int matching_parent_select(struct SceNetEtherAddr *addr)
{
	return sceNetAdhocMatchingSelectTarget(D_0039AE60, addr, 8, game_group_name);
}

extern int D_0039AE60;
int matching_parent_cancel(struct SceNetEtherAddr *addr) {
    return sceNetAdhocMatchingCancelTarget(D_0039AE60, addr);
}
