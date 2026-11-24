#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", matching_start);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", net_init);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", net_create_pdp);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", net_stop);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", net_term);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", send_position);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", recv_allpacket);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", disconnect_ibss);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", check_disconnect_completed);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", disconnect_check);

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", D_000152E4);
