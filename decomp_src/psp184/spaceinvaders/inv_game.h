/* inv_game work structures living inside gmain (layouts from accesses) */
#ifndef SPACEINVADERS_INV_GAME_H
#define SPACEINVADERS_INV_GAME_H
#include "gmain.h"

typedef struct {
	u8 _p0[0x10];
	int f10;
	u8 _p14[0x4];
	int f18;
	int f1c;
	u8 _p20[0xD8 - 0x20];
} ENEMY;

/* enemy groups at gmain + 0xEBD98 (count at gmain + 0xEBD94) */
typedef struct {
	int active;
	u8 _p4[0x40];
	ENEMY e[4][11];
	u8 _p2564[0x2564 - 0x44 - 0x2520];
} EGROUP;
#define egroup ((EGROUP *)&gmain.b[0xEBD98])

#endif
