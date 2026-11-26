#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", get_minfo_id);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", clear_minfo);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", child_handler);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", parent_handler);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", game_net_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", game_net_term);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B014);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B020);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B030);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B040);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B060);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B074);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B08C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B0A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B0E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B128);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B190);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B1B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B1E0);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", send_recv_game_data);

void SpriteScale(void) {
}

void DrawSprite(void) {
}

void FadeSetup(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", FadeState);

void FadeDraw(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", game_init);

int game_term(void) {
    return game_net_term();
}

void draw_top_for_game(void) {
}

void draw_game(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", game_pad_read_top);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", game_pad_read);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", mac2a);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B290);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B294);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B298);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B29C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B2FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B300);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B304);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B308);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B30C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B310);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B314);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B318);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B31C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B320);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B324);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B328);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B32C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B330);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B334);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B338);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B33C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B340);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B344);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B348);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B34C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B350);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B354);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B358);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B35C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B360);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B364);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B368);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B36C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B370);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B374);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B378);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B37C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B380);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_matching_handler", D_0007B384);
