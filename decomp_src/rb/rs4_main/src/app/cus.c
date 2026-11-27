/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
                            /* extern */

int resGetPtrLocal();                               /* extern */
int resGetSizeLocal(int, int);                      /* extern */
extern int cus_buf;
extern int cus_size;
M2C_UNK find_section(int);                          /* extern */
extern int cus_inst;
M2C_UNK get_key_count(int);
extern int end_ptr;
extern int src_ptr;

char *strstr(const char *, const char *);
long strtol(const char *, char **, int);
int atoi(const char *);

double atof(const char *);

extern unsigned char D_000FC3D8;
char *strtok(char *, const char *);

int get_key_by_index();
int get_key_by_index_fast();

int get_key_index();
int get_key_index_fast();

int iskanji1(int arg0) {
    int temp_v0;

    temp_v0 = arg0 & 0xFF;
    return ((unsigned int) ((temp_v0 + 0x7F) & 0xFF) < 0x1FU) | ((unsigned int) ((temp_v0 + 0x20) & 0xFF) < 0x1DU);
}

int iskanji2(int arg0) {
    int temp_a0;

    temp_a0 = arg0 & 0xFF;
    return ((unsigned int) ((temp_a0 - 0x40) & 0xFF) < 0xBDU) & (temp_a0 != 0x7F);
}

void seek_top(void) {
    end_ptr = cus_buf + cus_size;
    src_ptr = cus_buf;
}

void load_cus(int arg0, int arg1) {
    cus_buf = resGetPtrLocal();
    cus_size = resGetSizeLocal(arg0, arg1);
    seek_top();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC368);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_line);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", is_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", is_key);

char *extract_key(unsigned char *src, char *dst, int max) {
    char *d = dst;
    int n = 0;
    unsigned char c = *src;
    while (c != 0) {
        src++;
        n++;
        if ((char)c == '=') break;
        *d++ = c;
        if (n >= max) break;
        c = *src;
    }
    *d = 0;
    return dst;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_cus_value);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC398);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_cus_value_fast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_count);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_by_index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_by_index_fast);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_index);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_key_index_fast);

int to_int(char *s)
{
	char *e;
	if (strstr(s, "0x"))
		return strtol(s, &e, 16);
	return atoi(s);
}

float to_float(const char *s)
{
	return atof(s);
}

void trim(char *s)
{
	char *d = s;
	do {
		if (*s != ' ' && *s != '\t')
			*d++ = *s;
	} while (*s++);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", find_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", get_index_value);

int get_index_num(char *str) {
    int n;
    if (strtok(str, (char *)&D_000FC3D8) == NULL) {
        return 0;
    }
    for (n = 1; strtok(NULL, (char *)&D_000FC3D8) != NULL; n++) {
    }
    return n;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetString);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetInt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetFloat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetStringIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetIntIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetFloatIndex);

void cusSetSection(int arg0, int arg1) {
    load_cus(cus_inst, arg0);
    find_section(arg1);
}

void cusSetInst(int arg0) {
    cus_inst = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3DC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", cusGetIndexNum);

void cusGetKeyNum(int arg0, int arg1) {
    load_cus(cus_inst, arg0);
    get_key_count(arg1);
}

int cusGetKeyName(int name, char *section, int idx, char *buf, int size) {
    load_cus(cus_inst, name);
    if (section == NULL) {
        return get_key_by_index_fast(idx, buf, size);
    }
    return get_key_by_index(section, idx, buf, size);
}

int cusGetKeyIndex(int name, char *section, int key) {
    load_cus(cus_inst, name);
    if (section == NULL) {
        return get_key_index_fast(key);
    }
    return get_key_index(section, key);
}
