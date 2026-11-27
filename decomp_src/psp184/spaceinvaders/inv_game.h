/* inv_game shared declarations */
#ifndef SPACEINVADERS_INV_GAME_H
#define SPACEINVADERS_INV_GAME_H
#include "gmain.h"

typedef struct {
	int f0, f4, f8, fc, f10, f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c;
	int f40, f44, f48, f4c, f50, f54, f58;
} INV_STATUS;
extern int inv_status;
#define IST (*(INV_STATUS *)&inv_status)
typedef struct {
	u8 _p0[0xCC];
	int fcc, fd0, fd4, fd8;
	u8 _pdc[0x100 - 0xDC];
	int f100, f104, f108, f10c, f110, f114, f118;
} SAVE_DATA;
extern SAVE_DATA save_data;

typedef struct { int f0, f4, u, v, w, h; } TEXPOS;
extern TEXPOS texpos_inv_effect[];

#endif
