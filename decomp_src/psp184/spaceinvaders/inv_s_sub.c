/* cflags: -O2 */
#include "common.h"

int Sys_AssertMes(char *a, char *b, int c, char *d);
void Sys_Assert(void *a, int b, void *c)
{
	Sys_AssertMes(a, b, c, 0);
}

int sprintf(char *s, const char *fmt, ...);
void debug_text(int x, int y, char *s);
void psp_loopstart(void);
void psp_loopend(void);
int pad_tr(void);
int pad_sw(void);
int Sys_AssertMes(char *expr, char *file, int line, char *mes)
{
	volatile int loop = 1;
	char buf[512];

	while (loop) {
		psp_loopstart();
		if (mes) {
			sprintf(buf, "assert(%s) !!\n Line:[%d] : %s\nMESEAGE : %s\n, ", expr, line, file, mes);
			debug_text(0, 32, buf);
		} else {
			debug_text(0, 0, "ASSERT:");
			sprintf(buf, "File:%s:", file);
			debug_text(0, 8, buf);
			sprintf(buf, "Line:%d:", line);
			debug_text(0, 16, buf);
			sprintf(buf, "%s:", expr);
			debug_text(0, 24, buf);
		}
		if (pad_tr() & 1) {
			if (pad_sw() & 8)
				loop = 0;
		}
		psp_loopend();
	}
	return 0;
}
