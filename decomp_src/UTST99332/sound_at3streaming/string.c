#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/sound_at3streaming/nonmatchings/string", InitString);

typedef struct {
	int start;
	int len;
	char *buf;
	char *cur;
} STRINFO;

extern STRINFO strinfo;
extern char word_buf[17]; /* static in the original string.c (bss is asm) */

char *ParseString(void)
{
	int i;

	for (i = 0; i < 16; i++) {
		word_buf[i] = 0;
	}

	while (*strinfo.cur == ' ') {
		strinfo.cur++;
	}

	for (i = 0; i < 16; i++) {
		if (*strinfo.cur == ' ') {
			strinfo.cur++;
			break;
		}

		if (*strinfo.cur == 0) {
			strinfo.cur = strinfo.buf;
			break;
		}

		word_buf[i] = *strinfo.cur++;
	}

	word_buf[i] = 0;

	return word_buf;
}
