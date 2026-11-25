#include "common.h"
#include <math.h>
#include "mp3dec.h"

typedef void (*SBT_PROC)(float *, void *, int);

extern MPEG_DECODE_OPTION m_option;
extern int m_frequency;
extern float m_sample[2304];
extern int m_nsb_limit;
extern int m_max_sb;
extern SBT_PROC m_sbt_proc;
extern float m_sf_table[64];
extern float m_look_c_valueL2[18];
extern char m_group3_table[32][3];
extern char m_group5_table[128][3];
extern short m_group9_table[1024][3];
extern int m_nbat[4];
extern int m_bat[4][16];

/* static const in the original; the tables stay in asm */
#define sbt_table sbt_table_10FDDC
extern const char lookqt[4][3][16];
extern const unsigned char look_bat[5][4][16];
extern const unsigned char look_nbat[5][4];
extern const SBT_PROC sbt_table[2][3][2];

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2init", lookqt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2init", look_bat);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2init", look_nbat);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2init", sbt_table_10FDDC);

void L2table_init()
{
	int i, j;
	int code;
	int stepL2[18] = {
		0, 3, 5, 7, 9, 15, 31, 63, 127,
		255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535
	};

	/*--  c_values (dequant) --*/
	for (i = 1; i < 18; i++)
		m_look_c_valueL2[i] = 2.0F / stepL2[i];

	/*--  scale factor table, scale by 32768 for 16 pcm output  --*/
	for (i = 0; i < 64; i++)
		m_sf_table[i] = (float)(32768.0 * 2.0 * pow(2.0, -i / 3.0));

	/*--  grouped 3 level lookup table 5 bit token --*/
	for (i = 0; i < 32; i++) {
		code = i;
		for (j = 0; j < 3; j++) {
			m_group3_table[i][j] = (char)((code % 3) - 1);
			code /= 3;
		}
	}
	/*--  grouped 5 level lookup table 7 bit token --*/
	for (i = 0; i < 128; i++) {
		code = i;
		for (j = 0; j < 3; j++) {
			m_group5_table[i][j] = (char)((code % 5) - 2);
			code /= 5;
		}
	}
	/*--  grouped 9 level lookup table 10 bit token --*/
	for (i = 0; i < 1024; i++) {
		code = i;
		for (j = 0; j < 3; j++) {
			m_group9_table[i][j] = (short)((code % 9) - 4);
			code /= 9;
		}
	}
}

#ifdef NON_MATCHING
/* the original keeps %hi(m_option) live for the sbt selection (one lui less) */
int L2decode_start(MPEG_HEADER *h)
{
	int i, j, k;
	int bit_code;
	int limit;
	int abcd_index;

	/* compute abcd index for bit allo table selection */
	if (h->version == 1)	/* mpeg 1 */
		abcd_index = lookqt[h->mode][h->fr_index][h->br_index];
	else
		abcd_index = 4;	/* mpeg 2 */

	if (abcd_index < 0)
		return 0;	/* fail invalid Layer II bit rate index */

	for (i = 0; i < 4; i++) {
		m_nbat[i] = look_nbat[abcd_index][i];
		for (j = 0; j < 16; j++)
			m_bat[i][j] = look_bat[abcd_index][i][j];
	}
	m_max_sb = m_nbat[0] + m_nbat[1] + m_nbat[2] + m_nbat[3];
	/*----- compute nsb_limit --------*/
	m_nsb_limit = (m_option.freqLimit * 64 + m_frequency / 2) / m_frequency;
	/*- caller limit -*/
	limit = (32 >> m_option.reduction);
	if (limit > 8)
		limit--;
	if (m_nsb_limit > limit)
		m_nsb_limit = limit;
	if (m_nsb_limit > m_max_sb)
		m_nsb_limit = m_max_sb;

	if (h->mode != 3) {	/* adjust for 2 channel modes */
		for (i = 0; i < 4; i++)
			m_nbat[i] *= 2;
		m_max_sb *= 2;
		m_nsb_limit *= 2;
	}

	/* set sbt function */
	bit_code = (m_option.convert & 8) ? 1 : 0;
	k = 1 + m_option.convert;
	if (h->mode == 3)
		k = 0;
	m_sbt_proc = sbt_table[bit_code][m_option.reduction][k];

	/* clear sample buffer, unused sub bands must be 0 */
	for (i = 0; i < 2304; i++)
		m_sample[i] = 0.0F;

	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2init", L2decode_start);
#endif
