/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
                            /* extern */

void *resGetPtrLocal();                               /* extern */
int resGetSizeLocal(int, int);                      /* extern */
extern char *cus_buf;
extern int cus_size;
int find_section(char *section);
extern int cus_inst;
int get_key_count(char *section);
extern char *end_ptr;
extern char *src_ptr;

char *strstr(const char *, const char *);
long strtol(const char *, char **, int);
int atoi(const char *);

double atof(const char *);

extern unsigned char D_000FC3D8;
char *strtok(char *, const char *);
extern const char D_000FC368[];
void __assert(const char *, int, const char *);
void *memset(void *, int, unsigned int);
int strcmp(const char *, const char *);
void consPrintf(const char *, ...);
extern const char D_000FC398[];
extern char *l_pcDefSec;
extern char *l_pcDefKey;
extern const char D_000FC3DC[];
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, unsigned int);
int get_index_value(char *str, int idx, char *out);
int get_cus_value(char *section, char *key, char *value, int size);
int get_cus_value_fast(char *key, char *value, int size);
int is_section(char *line, char *out, int size);
int is_key(unsigned char *src, char *key, char *value, int value_size);
int get_line(char *buf, int size);

char *get_key_by_index(char *section, int idx, char *buf, int size);
char *get_key_by_index_fast(int idx, char *buf, int size);

int get_key_index(char *section, char *key);
int get_key_index_fast(char *key);

int iskanji1(unsigned char arg0) {
    int temp_v0;

    temp_v0 = arg0 & 0xFF;
    return ((unsigned int) ((temp_v0 + 0x7F) & 0xFF) < 0x1FU) | ((unsigned int) ((temp_v0 + 0x20) & 0xFF) < 0x1DU);
}

int iskanji2(unsigned char arg0) {
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

int get_line(char *buf, int size)
{
	int n = 0;
	unsigned char c;
	memset(buf, 0, size);
	if (!cus_buf) __assert(D_000FC368, 0x77, "cus_buf");
	for (;;) {
		if (src_ptr >= end_ptr) break;
		c = *src_ptr;
		if ((char)c == '\r') { src_ptr++; continue; }
		if ((char)c == '\n') {
			src_ptr++;
			if (n) break; continue;
		}
		if ((char)c == '#') {
			for (;;) { if (src_ptr == end_ptr) break; src_ptr++; if (*src_ptr == '\n') break; }
			if (n) break; continue;
		}
		if ((char)c == '\t') { src_ptr++; continue; }
		if ((char)c == 0x1A) { src_ptr++; continue; }
		if ((char)c == ' ') { src_ptr++; continue; }
		src_ptr++;
		n++;
		*buf++ = c;
	}
	*buf = 0;
	return n;
}

int is_section(char *line, char *out, int size)
{
	int state = 0;
	int i;
	char c;
	for (i = 0; line[i]; i++) {
		c = line[i];
		if (c == '[') {
			if (i < 2 || !iskanji1(line[i - 1]) || !iskanji2(line[i])) {
				state = 1;
				continue;
			}
		} else if (c == ']') {
			if (i < 2 || !iskanji1(line[i - 1]) || !iskanji2(line[i])) {
				if (state == 1) {
					state = 2;
					break;
				}
			}
		}
		if (state == 1) {
			*out++ = line[i];
			if (!(size--)) __assert(D_000FC368, 0xD8, "size--");
		}
	}
	*out = 0;
	if (state == 2) return 0;
	return -1;
}

int is_key(unsigned char *src, char *key, char *value, int value_size)
{
	char buf[512];
	char *d = buf;
	int n = 0;
	int found = 0;
	unsigned char c;
	c = *src;
	while (c) {
		if ((char)c == '=') {
			if (n > 0) found = 1;
			src++;
			break;
		}
		*d = c;
		src++;
		d++;
		c = *src;
		n++;
	}
	*d = 0;
	if (!found) return -1;
	if (key != NULL && strcmp(buf, key) != 0) return -1;
	memset(value, 0, value_size);
	d = value;
	while (*src) {
		*d = *src;
		if (!(value_size--)) __assert(D_000FC368, 0x11F, "value_size--");
		src++;
		d++;
	}
	return 0;
}

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

int get_cus_value(char *section, char *key, char *value, int size)
{
	char line[512];
	char name[32];
	int ret = -1;
	seek_top();
	while (get_line(line, 512) > 0) {
		if (is_section(line, name, 32) != -1 && strcmp(name, section) == 0) {
		while (get_line(line, 512) > 0) {
			if (is_key((unsigned char *)line, key, value, size) == 0) { ret = 0; goto end; }
			if (is_section(line, name, 32) != -1) goto end;
		}
		}
	}
end:
	return ret;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC398);

int get_cus_value_fast(char *key, char *value, int size)
{
	char line[512];
	char name[32];
	int ret = -1;
	src_ptr = l_pcDefSec;
	if (key == NULL) {
		if (!l_pcDefKey) consPrintf(D_000FC398, D_000FC368, 0x189, "get_cus_value_fast", "l_pcDefKey");
		src_ptr = l_pcDefKey;
	} else {
		l_pcDefKey = 0;
	}
	while (get_line(line, 512) > 0) {
		if (is_section(line, name, 32) == 0) break;
		if (is_key((unsigned char *)line, key, value, size) == 0) { ret = 0; break; }
		if (is_section(line, name, 32) != -1) break;
	}
	return ret;
}

int get_key_count(char *section)
{
	char line[512];
	char name[32];
	int n = 0;
	seek_top();
	while (get_line(line, 512) > 0) {
		if (is_section(line, name, 32) != -1 && strcmp(name, section) == 0) {
		while (get_line(line, 512) > 0) {
			if (is_section(line, name, 32) != -1) goto end;
			n++;
		}
		}
	}
end:
	return n;
}

char *get_key_by_index(char *section, int idx, char *buf, int size)
{
	char line[512];
	char name[32];
	int i = 0;
	int found = 0;
	seek_top();
	while (get_line(line, 512) > 0) {
		if (is_section(line, name, 32) != -1) {
			if (strcmp(name, section) == 0) {
				while (get_line(line, 512) > 0) {
					if (i == idx) { extract_key((unsigned char *)line, buf, size); found = 1; goto end; }
					i++;
					if (is_section(line, name, 32) != -1) goto end;
				}
			}
		}
	}
end:
	if (!found) return NULL;
	return buf;
}

char *get_key_by_index_fast(int idx, char *buf, int size)
{
	char line[512];
	char name[32];
	int i = 0;
	int found = 0;
	char *pos;
	src_ptr = l_pcDefSec;
	pos = l_pcDefSec;
	while (get_line(line, 512) > 0) {
		if (i == idx) { extract_key((unsigned char *)line, buf, size); found = 1; goto end; }
		pos = src_ptr;
		i++;
		if (is_section(line, name, 32) == 0) goto end;
		if (is_section(line, name, 32) != -1) goto end;
	}
end:
	if (!found) return NULL;
	l_pcDefKey = pos;
	return buf;
}

int get_key_index(char *section, char *key)
{
	char line[512];
	char name[32];
	char kname[32];
	int i = 0;
	int found = 0;
	seek_top();
	while (get_line(line, 512) > 0) {
		if (is_section(line, name, 32) != -1) {
			if (strcmp(name, section) == 0) {
				while (get_line(line, 512) > 0) {
					extract_key((unsigned char *)line, kname, 32);
					if (strcmp(key, kname) == 0) { found = 1; goto end; }
					i++;
					if (is_section(line, name, 32) != -1) goto end;
				}
			}
		}
	}
end:
	if (!found) return -1;
	return i;
}

int get_key_index_fast(char *key)
{
	char line[512];
	char name[32];
	char kname[32];
	int i = 0;
	int found = 0;
	src_ptr = l_pcDefSec;
	while (get_line(line, 512) > 0) {
		extract_key((unsigned char *)line, kname, 32);
		if (strcmp(key, kname) == 0) { found = 1; goto end; }
		i++;
		if (is_section(line, name, 32) == 0) goto end;
		if (is_section(line, name, 32) != -1) goto end;
	}
end:
	if (!found) return -1;
	return i;
}

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

int find_section(char *section)
{
	char line[512];
	char name[32];
	seek_top();
	l_pcDefSec = 0;
	while (get_line(line, 512) > 0) {
		if (is_section(line, name, 32) == -1) continue;
		if (strcmp(name, section) != 0) continue;
		l_pcDefSec = src_ptr;
		return 1;
	}
	return -1;
}

int get_index_value(char *str, int idx, char *out)
{
	int ret = -1;
	char *p;
	int i;
	p = strtok(str, (char *)&D_000FC3D8);
	if (p == NULL) return -1;
	if (idx == 0) {
		strcpy(out, p);
		ret = 0;
	} else {
		for (i = 1; (p = strtok(NULL, (char *)&D_000FC3D8)) != NULL; i++) {
			if (i == idx) { strcpy(out, p); ret = 0; break; }
		}
	}
	return ret;
}

int get_index_num(char *str) {
    int n;
    if (strtok(str, (char *)&D_000FC3D8) == NULL) {
        return 0;
    }
    for (n = 1; strtok(NULL, (char *)&D_000FC3D8) != NULL; n++) {
    }
    return n;
}

char *cusGetString(int name, char *section, char *key, char *out, int size, char *def)
{
	char buf[512];
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) strncpy(out, buf, size - 1);
		else strncpy(out, def, size - 1);
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) __assert(D_000FC368, 0x37A, D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) strncpy(out, buf, size - 1);
		else strncpy(out, def, size - 1);
	}
	return out;
}

int cusGetInt(int name, char *section, char *key, int def)
{
	char buf[512];
	int ret;
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) ret = to_int(buf); else ret = def;
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) __assert(D_000FC368, 0x3A8, D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) ret = to_int(buf); else ret = def;
	}
	return ret;
}

float cusGetFloat(int name, char *section, char *key, float def)
{
	char buf[512];
	float ret;
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) ret = to_float(buf); else ret = def;
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) __assert(D_000FC368, 0x3D5, D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) ret = to_float(buf); else ret = def;
	}
	return ret;
}

char *cusGetStringIndex(int name, char *section, char *key, int idx, char *out, int size, char *def)
{
	char buf[512];
	char tmp[512];
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) { if (get_index_value(buf, idx, tmp) == 0) strncpy(out, tmp, size - 1); else strncpy(out, def, size - 1); } else strncpy(out, def, size - 1);
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) __assert(D_000FC368, 0x40F, D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) { if (get_index_value(buf, idx, tmp) == 0) strncpy(out, tmp, size - 1); else strncpy(out, def, size - 1); } else strncpy(out, def, size - 1);
	}
	return out;
}

int cusGetIntIndex(int name, char *section, char *key, int idx, int def)
{
	char buf[512];
	char tmp[512];
	int ret;
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) { if (get_index_value(buf, idx, tmp) == 0) ret = to_int(tmp); else ret = def; } else ret = def;
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) __assert(D_000FC368, 0x450, D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) { if (get_index_value(buf, idx, tmp) == 0) ret = to_int(tmp); else ret = def; } else ret = def;
	}
	return ret;
}

float cusGetFloatIndex(int name, char *section, char *key, int idx, float def)
{
	char buf[512];
	char tmp[512];
	float ret;
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) { if (get_index_value(buf, idx, tmp) == 0) ret = to_float(tmp); else ret = def; } else ret = def;
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) __assert(D_000FC368, 0x490, D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) { if (get_index_value(buf, idx, tmp) == 0) ret = to_float(tmp); else ret = def; } else ret = def;
	}
	return ret;
}

void cusSetSection(int arg0, int arg1) {
    load_cus(cus_inst, arg0);
    find_section(arg1);
}

void cusSetInst(int arg0) {
    cus_inst = arg0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/cus", D_000FC3DC);

int cusGetIndexNum(int name, char *section, char *key)
{
	char buf[512];
	int ret;
	load_cus(cus_inst, name);
	if (section != NULL) {
		if (get_cus_value(section, key, buf, 512) == 0) ret = get_index_num(buf); else ret = 0;
		l_pcDefSec = 0;
	} else {
		if (!l_pcDefSec) consPrintf(D_000FC398, D_000FC368, 0x4E1, "cusGetIndexNum", D_000FC3DC);
		if (get_cus_value_fast(key, buf, 512) == 0) ret = get_index_num(buf); else ret = 0;
	}
	return ret;
}

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
