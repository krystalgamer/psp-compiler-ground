#include "common.h"

void InitBall(void) {
}

void InitGame(void) {
}

void RunGame(void) {
}

void DrawBall(void) {
}

void DrawBG(void) {
}

void DrawGround(void) {
}

void DrawScore(void) {
}

void DrawMoon(void) {
}

void DrawScope(void) {
}

void DrawBeam(void) {
}

void DrawReady(void) {
}

void DrawMission(void) {
}

void DrawGame(void) {
}

void CheckShoot(void) {
}

void KeyGame(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_game", get_game_data);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_game", update_game_data);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/net/inv_s_game", check_peer_existence);
