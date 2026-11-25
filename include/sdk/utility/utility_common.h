#ifndef _UTILITY_COMMON_H
#define _UTILITY_COMMON_H
/* types recovered from DWARF */
typedef struct {
	unsigned int size;
	int message_lang;
	int ctrl_assign;
	int main_thread_priority;
	int sub_thread_priority;
	int font_thread_priority;
	int sound_thread_priority;
	int result;
	int reserved1;
	int reserved2;
	int reserved3;
	int reserved4;
} SceUtilityParamBase;
#endif
