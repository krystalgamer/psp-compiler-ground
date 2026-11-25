#ifndef _UTILITY_OSK_H
#define _UTILITY_OSK_H
/* types recovered from DWARF; prototypes as used by the decompiled code */
#include <psptypes.h>
#include <utility/utility_common.h>
typedef enum {
	SCE_UTILITY_OSK_BOOL_VALUE_FALSE = 0,
	SCE_UTILITY_OSK_BOOL_VALUE_TRUE = 1,
} SceUtilityOskBoolValue;
typedef enum {
	SCE_UTILITY_OSK_INPUT_FIELD_RESULT_UNEDITED = 0,
	SCE_UTILITY_OSK_INPUT_FIELD_RESULT_CANCELED = 1,
	SCE_UTILITY_OSK_INPUT_FIELD_RESULT_EDITED = 2,
} SceUtilityOskInputFieldResult;
typedef struct {
	unsigned int input_method_type;
	unsigned int input_method_attributes;
	unsigned int writing_language_type;
	SceUtilityOskBoolValue hide_mode;
	int input_character_type;
	int num_lines;
	int kinsoku;
	SceWChar16 *message;
	SceWChar16 *init_text;
	int result_text_buffer_size;
	SceWChar16 *result_text_buffer;
	SceUtilityOskInputFieldResult result;
	int limit_length;
} SceUtilityOskInputFieldInfo;
typedef enum {
	SCE_UTILITY_OSK_LOCAL_STATUS_NONE = 0,
	SCE_UTILITY_OSK_LOCAL_STATUS_INITIALIZING = 1,
	SCE_UTILITY_OSK_LOCAL_STATUS_INITIALIZED = 2,
	SCE_UTILITY_OSK_LOCAL_STATUS_OPENED = 3,
	SCE_UTILITY_OSK_LOCAL_STATUS_CLOSING = 4,
	SCE_UTILITY_OSK_LOCAL_STATUS_CLOSED = 5,
} SceUtilityOskLocalStatus;
typedef struct {
	SceUtilityParamBase base;
	unsigned int num_input_fields;
	SceUtilityOskInputFieldInfo *input_field_info;
	SceUtilityOskLocalStatus local_status;
	int error_code;
} SceUtilityOskParam;
int sceUtilityOskInitStart(SceUtilityOskParam *param);
int sceUtilityOskShutdownStart(void);
int sceUtilityOskUpdate(int animation_speed);
int sceUtilityOskGetStatus(void);
#endif
