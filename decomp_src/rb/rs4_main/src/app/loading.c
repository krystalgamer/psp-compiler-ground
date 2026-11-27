/* cflags: -Os -fno-strength-reduce */
#include "common.h"

void loadingInit(void) {
}

void loadingTerm(void) {
}

void loadingSetup(void) {
}

int mainGetThrBack(void);
int thrState(int);
int *gameGetCntx(void);
void drawXchg(int, int);
void scxUpdate(void);
void ctrlUpdate(void);
void loadingDraw(int n)
{
	int thr = mainGetThrBack();
	while (n || thrState(thr)) {
		drawXchg(1, gameGetCntx()[0x70 / 4]);
		scxUpdate();
		ctrlUpdate();
		n -= (n != 0);
	}
}
