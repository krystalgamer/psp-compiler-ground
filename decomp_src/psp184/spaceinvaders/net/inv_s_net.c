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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", randomize_group_name);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", adhocctl_handler);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", _net_init);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_adhocctl_connect_completed);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_adhocctl_disconnect_completed);

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
