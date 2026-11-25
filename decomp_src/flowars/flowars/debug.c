#include "common.h"

typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef struct _GRAPHICS Graphics;
struct _GRAPHICS;
typedef long long int long64;
struct _GRAPHICS { /* size 0xb4 */
    void (*init)(void);
    void (*load)(void);
    void (*draw_pae)(int, int, int, float, int);
    void (*draw_pae2)(int, int, int, float, int);
    void (*draw_pae_mark)(int, int, int);
    void (*draw_ox)(int, int, int);
    void (*draw_flying_pae)(int, int, int, float, int);
    void (*draw_flying_pae2)(int, int, int, float, float, int);
    void (*draw_back_pae)(int, int, float, int);
    void (*draw_checked_pae)(int, int, int, float);
    void (*draw_cursor)(int);
    void (*draw_loading)(int);
    void (*draw_my_hand)(void);
    void (*draw_my_collection)(void);
    void (*draw_opp_hand)(void);
    void (*draw_opp_collection)(void);
    void (*draw_dialog_box)(int, int *);
    void (*printDebugMsg)(int, int, const char *);
    void (*printDebugMsg2)(int, int, int, const char *);
    void (*init_sprite)();
    void (*sync_sprite)();
    void (*destroy)();
    void (*swap_buffers)();
    void (*show_gostop_info)();
    void (*show_result_dialog)();
    void (*draw_number)(long64, int, int, int, int, int);
    void (*draw_number2)(char *, int, int, int, int, int);
    int (*draw_animation)(int, int, int, int);
    void (*init_animation)(int);
    void (*draw_timer)(int);
    void (*draw_win_lose)(int, int, unsigned int, unsigned int);
    void (*draw_vs_menu)(void);
    void (*stop_vs_menu)(void);
    void (*draw_collect_paes)(int);
    void (*draw_pause)(void);
    void (*fade_out)(unsigned int);
    void (*draw_char_name)(int, int, const char *);
    void (*draw_all_in)(int);
    void (*draw_save)(void);
    void (*show_warning)(const char *, unsigned int);
    int (*get_img_loaded)(void);
    void (*draw_button)(int, int, int);
    void (*draw_error)(const char *);
    void (*draw_sprite)(int, int, int, int, int);
    void (*draw_sprite2)(int, int, int, int, int, int, int);
};
struct _anon1;
struct _anon1 { /* size 0x10 */
    void (*debugMsg)(const char *, ...);
    void (*debugMsg2)(const char *, ...);
    void (*printMsg)(int, int);
    void (*printMsg2)(int, int);
};
typedef struct _anon1 DebugManager;

extern Graphics graphics;

extern char strMsg[20][1024];
extern char strMsg2[1024];
extern int dbgpos;
extern int linecnt;


#define va_start(v, l)	__builtin_stdarg_start((v), l)
#define va_end(v)	__builtin_va_end(v)
void *memset(void *s, int c, unsigned int n);
char *strcpy(char *dst, const char *src);
int vsprintf(char *buf, const char *fmt, va_list ap);

static void debugMsg(const char *str, ...)
{
	char buff[1024] = "";
	va_list argptr;

	va_start(argptr, str);
	vsprintf(buff, str, argptr);
	va_end(argptr);
	memset(strMsg[dbgpos], 0, 1024);
	strcpy(strMsg[dbgpos++], buff);
	linecnt++;
	if (dbgpos >= 20)
		dbgpos = 0;
}

__asm__(".globl debugMsg");

static void debugMsg2(const char *str, ...)
{
	va_list argptr;

	memset(strMsg2, 0, 1024);
	va_start(argptr, str);
	vsprintf(strMsg2, str, argptr);
	va_end(argptr);
}

__asm__(".globl debugMsg2");

static void printMsg(int x, int y)
{
	int i;
	int p;

	if (linecnt > 20)
		p = dbgpos;
	else
		p = 0;
	for (i = 0; i < linecnt && i < 20; i++) {
		graphics.printDebugMsg2(x, y + i * 10, 0xFF000000, strMsg[p]);
		p++;
		if (p >= 20)
			p = 0;
	}
}

__asm__(".globl printMsg");

static void printMsg2(int x, int y)
{
	graphics.printDebugMsg2(x, y, 0xFF000000, strMsg2);
}

__asm__(".globl printMsg2");
