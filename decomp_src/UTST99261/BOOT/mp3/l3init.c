#include "common.h"
#include "mp3dec.h"
#include "l3.h"

typedef union {
	int s;
	float x;
} SAMPLE;

typedef struct {
	int l[23];
	int s[14];
} SFBT;

typedef void (*SBT_PROC)(float *, void *, int);
typedef void (*XFORM_PROC)(void *, int);

extern MPEG_DECODE_OPTION m_option;
extern SAMPLE m_sample[2][2][576];
extern int m_frequency;
extern SBT_PROC m_sbt_proc;
extern XFORM_PROC m_xform_proc;
extern int m_channels;
extern int m_sfBandIndex[2][22];	/* [long/short][cb] */
extern int m_nBand[2][22];
extern int m_band_limit;
extern int m_band_limit21;	/* limit for sf band 21 */
extern int m_band_limit12;	/* limit for sf band 12 short */
extern int m_band_limit_nsb;
extern int m_ncbl_mixed;
extern int m_nsb_limit;
extern int m_gr;
extern int m_buf_ptr0;
extern int m_buf_ptr1;
extern float m_yout[576];

/* static const in the original; the tables stay in asm */
#define sbt_table sbt_table_10F24C
extern const SBT_PROC sbt_table[2][3][2];
extern const XFORM_PROC xform_table[5];
extern const SFBT sfBandTable[3][3];

void quant_init();
void alias_init();
void msis_init();
void fdct_init();
void imdct_init();
void hwin_init();

void L3table_init()
{
	quant_init();
	alias_init();
	msis_init();
	fdct_init();
	imdct_init();
	hwin_init();
}

#ifdef NON_MATCHING
/* one instruction longer; registers allocated one off from the start */
int L3decode_start(MPEG_HEADER *h)
{
	int i, j, k, v;
	int channels;
	int limit;
	int bit_code;

	m_buf_ptr0 = 0;
	m_buf_ptr1 = 0;
	m_gr = 0;
	v = h->version - 1;
	if (h->version == 1)
		m_ncbl_mixed = 8;	/* mpeg-1 */
	else
		m_ncbl_mixed = 6;	/* mpeg-2 */

	/*----- compute nsb_limit --------*/
	m_nsb_limit = (m_option.freqLimit * 64 + m_frequency / 2) / m_frequency;
	/*- caller limit -*/
	limit = (32 >> m_option.reduction);
	if (limit > 8)
		limit--;
	if (m_nsb_limit > limit)
		m_nsb_limit = limit;
	limit = 18 * m_nsb_limit;

	if (h->version == 1) {
		m_band_limit12 = 3 * sfBandTable[v][h->fr_index].s[13];
		m_band_limit = m_band_limit21 = sfBandTable[v][h->fr_index].l[22];
	} else {
		m_band_limit12 = 3 * sfBandTable[v][h->fr_index].s[12];
		m_band_limit = m_band_limit21 = sfBandTable[v][h->fr_index].l[21];
	}
	m_band_limit += 8;	/* allow for antialias */
	if (m_band_limit > limit)
		m_band_limit = limit;

	if (m_band_limit21 > m_band_limit)
		m_band_limit21 = m_band_limit;
	if (m_band_limit12 > m_band_limit)
		m_band_limit12 = m_band_limit;

	m_band_limit_nsb = (m_band_limit + 17) / 18;	/* limit in sb's */

	bit_code = (m_option.convert & 8) ? 1 : 0;
	j = 1;
	channels = 2;
	if (h->mode == 3)
		channels = 1;
	if (m_option.convert == 0)
		j = channels;
	m_sbt_proc = sbt_table[bit_code][m_option.reduction][j - 1];
	k = 1 + m_option.convert;
	if (h->mode == 3)
		k = 0;
	m_xform_proc = xform_table[k];
	m_channels = channels;

	/* init band tables */
	for (i = 0; i < 22; i++)
		m_sfBandIndex[0][i] = sfBandTable[v][h->fr_index].l[i + 1];
	for (i = 0; i < 13; i++)
		m_sfBandIndex[1][i] = 3 * sfBandTable[v][h->fr_index].s[i + 1];
	for (i = 0; i < 22; i++)
		m_nBand[0][i] = sfBandTable[v][h->fr_index].l[i + 1] - sfBandTable[v][h->fr_index].l[i];
	for (i = 0; i < 13; i++)
		m_nBand[1][i] = sfBandTable[v][h->fr_index].s[i + 1] - sfBandTable[v][h->fr_index].s[i];

	/* clear buffers */
	for (i = 0; i < 576; i++)
		m_yout[i] = 0.0f;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 576; k++)
				m_sample[i][j][k].x = 0.0f;
		}
	}
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l3init", L3decode_start);
#endif

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l3init", sbt_table_10F24C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l3init", xform_table);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l3init", sfBandTable);
