#ifndef GAME_H
#define GAME_H
/* puzzle_bobble's own functions used across files (no DWARF: prototypes
   follow the calls) */

/* wrap_sprite.c */
void release_gims(int no);
int get_gims(int no);
int LoadGimFile(int no, int file);
void SetSpriteColorRGBA(int r, int g, int b, int a);
void DrawSpriteEz(int no, float x, float y, float u, float v, float w, float h, float z);

/* game_main.c */
int GetKeyHit(void);
int ret_GameStat(void);

/* sound.c */
void se_play(int no);

/* file_sub.c */
void wait_umd(void);
int file_sub_init(void);
void load_pak(void);
int load_file(const char *name, void **buf, int *size);
int LoadPak(void);
void GetPakInfo(int no, char **addr, int *size);
int MsLoad(void);
int MsLoad2(void);
int save_confirm(void);
int MsSave(void);
int MsSave2(void);
int utility_update_savedata(void);
void set_ms_dialog(int no);
void disp_ms_dialog(void);
void save_data_init(void);
unsigned int get_free_ms(void);

extern int NowSaveFlag;
extern int MsAccessFlag;
extern int UtilityFlag;
extern int MsType;
extern int MsWait;
extern int OldError;
extern int MsGim;
extern int MsSkip;

#endif
