/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"


void psp_init(void);
void autoload(void);
void autosave(void);
int inv_title_main(void);
void main_classicinv(void);
void inv_matchup_main(void);
void maingame_loop(int mode);
void net_labo(void);

void psp_init(void);
void autoload(void);
void autosave(void);
int inv_title_main(void);
void main_classicinv(void);
void inv_matchup_main(void);
void maingame_loop(int mode);
void net_labo(void);
int main(void)
{
	int r;

	psp_init();
	autoload();
	for (;;) {
		r = inv_title_main();
		if (r == 0)
			main_classicinv();
		else if (r == 1)
			inv_matchup_main();
		else if (r == 2)
			maingame_loop(0);
		else if (r == 3)
			net_labo();
		autosave();
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MoriyaHatoMove(int *arg0, int arg1, int arg2) {
    int temp_v0;
    int temp_v1;

    temp_v1 = *arg0;
    temp_v0 = (int) (arg1 - temp_v1) >> arg2;
    if (temp_v0 == 0) {
        if (temp_v1 != arg1) {
            *arg0 = temp_v1 + 1;
        } else {
            *arg0 = arg1;
        }
    } else {
        *arg0 = temp_v1 + temp_v0;
    }
    return *arg0 - arg1;
}
