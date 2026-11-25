#ifndef SAVEDATA_H
#define SAVEDATA_H

/* the game's save data (40 bytes); only the clamped counters are known */
typedef struct {
	int unk00[5];
	int unk14;
	int unk18;
	int unk1C;
	int unk20;
	int unk24;
} SaveData;

extern SaveData SaveDataBuf;

int set_savedata_param(const int type, SceUtilitySavedataParam *pParam);
void show_results(SceUtilitySavedataParam *pParam);
void set_param_save(SceUtilitySavedataParam *pParam);
void load_buf(void);

#endif
