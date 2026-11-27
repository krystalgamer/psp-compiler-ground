/* lang: c++ */
/* cflags: -Os */
#include "common.h"
extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask_CreateParam__Reset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Startup_Game);

void SaruNet_PetitGame_NetworkTask__Terminate_Game(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Get_Instance_p);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Is_Error_AtQuit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Reset_LocalController);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Get_CardBattlePlayerContext_p);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task_cif", SaruNet_PetitGame_NetworkTask__Update);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
