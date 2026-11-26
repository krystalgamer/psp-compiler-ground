#include "common.h"

typedef struct {
	int start;
	int len;
	char *buf;
	char *cur;
} STRINFO;

extern STRINFO strinfo;
extern char word_buf[17]; /* static in the original string.c (bss is asm) */

extern char string_buf[1024]; /* static in the original string.c (bss is asm) */
int sceIoOpen(const char *file, int flags, int mode);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);

void InitString(void)
{
	int fd;
	int i;

	strinfo.start = 0;
	strinfo.len = 0;
	strinfo.buf = string_buf;
	strinfo.cur = string_buf;

	for (i = 0; i < 1024; i++) {
		strinfo.buf[i] = 0;
	}

	fd = sceIoOpen("disc0:/PSP_GAME/USRDIR/DATA/text/sample.txt", 1, 0777);
	if (fd >= 0) {
		strinfo.len = sceIoRead(fd, strinfo.buf, 1024);
		sceIoClose(fd);
	}

	if (strinfo.len == 0) {
		for (i = 0; i < 26; i++) {
			strinfo.buf[i * 2] = 'A' + i;
			strinfo.buf[i * 2 + 1] = ' ';
		}

		strinfo.len = 52;
	} else {
		for (i = 0; i < strinfo.len; i++) {
			if (strinfo.buf[i] >= 'A' && strinfo.buf[i] <= 'Z') {
				continue;
			}
			if (strinfo.buf[i] >= 'a' && strinfo.buf[i] <= 'z') {
				strinfo.buf[i] -= 0x20;
			} else {
				strinfo.buf[i] = ' ';
			}
		}

		strinfo.buf[i] = 0;
	}
}

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
