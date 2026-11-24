#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", get_random_num);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", get_bssid);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", randomize_group_name);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", clear_evf);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", adhocctl_handler);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", polling_error);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_init);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_term);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_scan);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_connect);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", D_00019974);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_disconnect);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_scan_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_connect_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_disconnect_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_adhocctl_connected_error);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", check_error_dialog_closed);

INCLUDE_ASM("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/net", net_update);
