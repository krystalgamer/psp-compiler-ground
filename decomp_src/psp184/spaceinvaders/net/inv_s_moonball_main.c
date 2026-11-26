/* cflags: -O2 -fno-merge-constants */
#include "common.h"

extern int _info;
int game_net_init(void);

void SpriteScale(void) {
}

void DrawSprite(void) {
}

void FadeSetup(void) {
}

extern int _info;
int game_net_init(void);
int FadeState(void)
{
	return 0;
}

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

int game_pad_read_top(void)
{
	return 1;
}

int game_pad_read(void)
{
	return 0;
}
