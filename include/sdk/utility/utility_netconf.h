#ifndef _UTILITY_NETCONF_H
#define _UTILITY_NETCONF_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
#include <utility/utility_common.h>
typedef struct {
	unsigned char group_name[8];
} SceUtilityNetconfAdhocParam;
typedef struct {
	SceUtilityParamBase base;
	int type;
	SceUtilityNetconfAdhocParam *adhoc_param;
} SceUtilityNetconfParam;
int sceUtilityNetconfInitStart(SceUtilityNetconfParam *param);
int sceUtilityNetconfShutdownStart(void);
int sceUtilityNetconfUpdate(int animation_speed);
int sceUtilityNetconfGetStatus(void);
#endif
