#include "common.h"
#include "mp3dec.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef void (*SBT_PROC)(float *, void *, int);

extern MPEG_DECODE_OPTION m_option;
extern int m_frequency;
extern float m_sample[2304];
extern int m_nsb_limit;
extern int m_max_sb;
extern SBT_PROC m_sbt_proc;
extern float m_look_c_valueL1[18];
extern int m_nbatL1;
extern const SBT_PROC sbt_table_10FF70[2][3][2];
#define sbt_table sbt_table_10FF70

void L1table_init()
{
	int i;
	int stepL1;

	stepL1 = 4;
	for (i = 1; i < 16; i++) {
		m_look_c_valueL1[i] = (float)(2.0 / (stepL1 - 1));
		stepL1 <<= 1;
	}
}

#ifdef NON_MATCHING
/* same operations, different register allocation and scheduling */
int L1decode_start(MPEG_HEADER *h)
{
	int i;
	int k;
	int bit_code;
	int limit;

	limit = (m_option.freqLimit * 64 + m_frequency / 2) / m_frequency;
	m_nbatL1 = 32;
	m_max_sb = 32;
	k = 32 >> m_option.reduction;
	if (k >= 9)
		k--;
	m_nsb_limit = MIN(MIN(k, limit), 32);
	if (h->mode != 3) {
		m_nbatL1 = 64;
		m_max_sb = 64;
		m_nsb_limit *= 2;
	}
	bit_code = (m_option.convert & 8) ? 1 : 0;
	if (h->mode == 3)
		k = 0;
	else
		k = 1 + m_option.convert;
	m_sbt_proc = sbt_table[bit_code][m_option.reduction][k];
	for (i = 0; i < 768; i++)
		m_sample[i] = 0.0f;
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l1init", L1decode_start);
#endif

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l1init", sbt_table_10FF70);
