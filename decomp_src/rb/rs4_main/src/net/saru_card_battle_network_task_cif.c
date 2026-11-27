/* lang: c++ */
/* cflags: -Os */
#include "common.h"
extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask_CreateParam__Reset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask__Create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask__Destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask__Startup_Game);

void SaruNet_CardBattle_NetworkTask__Terminate_Game(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask__Is_Error_AtQuit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask__Get_PlayerContext_p);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task_cif", SaruNet_CardBattle_NetworkTask__Update);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
