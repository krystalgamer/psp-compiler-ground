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
char mac2a(int n)
{
	return *nametbl[n % 62];
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", get_random_num);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", _net_term);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", net_scan);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", net_connect);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", net_disconnect);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_adhocctl_scan_completed);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_adhocctl_connect_completed);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_adhocctl_disconnect_completed);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_adhocctl_connected_error);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", check_error_dialog_closed);

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
