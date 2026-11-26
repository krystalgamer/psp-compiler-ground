#include "common.h"

void SpriteScale(void) {
}

void DrawSprite(void) {
}

void FadeSetup(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_moonball_main", FadeState);

void FadeDraw(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_moonball_main", game_init);

int game_term(void) {
    return game_net_term();
}

void draw_top_for_game(void) {
}

void draw_game(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_moonball_main", game_pad_read_top);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_moonball_main", game_pad_read);
