/* cflags: -O2 */
#include "common.h"

extern int _info;
int game_net_init(void);

typedef struct { int a; int b; int c; int d; } INFO_T;
#define INFO (*(INFO_T *)&_info)

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

#define INFO (*(INFO_T *)&_info)
int game_init(void)
{
	INFO.a = 0;
	INFO.b = 0;
	INFO.c = 0;
	INFO.d = 0;
	return game_net_init();
}

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
