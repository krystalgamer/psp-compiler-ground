#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", get_random_num);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", get_bssid);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", randomize_group_name);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", clear_evf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", error_code_daialogget);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", adhocctl_handler);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", polling_error);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", utility_update_shutdown);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", matching_get_established_num);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", matching_parent_select);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_net", matching_parent_cancel);
