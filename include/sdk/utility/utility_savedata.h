#ifndef _UTILITY_SAVEDATA_H
#define _UTILITY_SAVEDATA_H
/* types recovered from DWARF (UTST99332 utility_basic) */
#include "utility_common.h"

typedef struct {
	char title[128];
	char savedataTitle[128];
	char detail[1024];
	unsigned char parentalLev;
	unsigned char reserved[3];
} SceUtilitySDSystemFileParam;

typedef struct {
	void *pDataBuf;
	unsigned int dataBufSize;
	unsigned int dataFileSize;
	char *pFilePath;
} SceUtilitySDExtFile;

typedef struct {
	SceUtilitySDExtFile icon0;
	char *pTitle;
} SceUtilitySavedataListSaveNewData;

typedef struct {
	unsigned int msClusterSizeByte;
	unsigned int msFreeCluster;
	unsigned int msFreeSizeKB;
	char msFreeSizeStr[8];
} SceUtilitySavedataMsFreeSize;

typedef struct {
	char titleId[13];
	char reserved[3];
	char userId[20];
	unsigned int cluster;
	unsigned int sizeKB;
	char sizeStr[8];
	unsigned int size32KB;
	char size32Str[8];
} SceUtilitySavedataMsDataSize;

typedef struct {
	unsigned int cluster;
	unsigned int sizeKB;
	char sizeStr[8];
	unsigned int size32KB;
	char size32Str[8];
} SceUtilitySavedataUtilityDataSize;

typedef struct {
	SceUtilityParamBase base;
	int type;
	unsigned int bind;
	unsigned int overWriteMode;
	char titleId[13];
	char reserved[3];
	char userId[20];
	char (*pUserIds)[20];
	char fileName[13];
	char reserved1[3];
	void *pDataBuf;
	unsigned int dataBufSize;
	unsigned int dataFileSize;
	SceUtilitySDSystemFileParam systemFile;
	SceUtilitySDExtFile icon0;
	SceUtilitySDExtFile icon1;
	SceUtilitySDExtFile pic1;
	SceUtilitySDExtFile snd0;
	SceUtilitySavedataListSaveNewData *pNewData;
	unsigned int initFocus;
	int abortedStatus;
	SceUtilitySavedataMsFreeSize *pMs;
	SceUtilitySavedataMsDataSize *pMsData;
	SceUtilitySavedataUtilityDataSize *pUtilityData;
} SceUtilitySavedataParam;

#endif
