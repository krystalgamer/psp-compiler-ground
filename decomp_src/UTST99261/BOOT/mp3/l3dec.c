#include "common.h"
#include "mp3dec.h"
#include "l3.h"

typedef union {
	int s;
	float x;
} SAMPLE;

typedef void (*SBT_PROC)(float *, void *, int);
typedef void (*XFORM_PROC)(void *, int);

/* defined here in the original; the data stays in asm */
extern SAMPLE m_sample[2][2][576];	/* [ch][gr][576] */
extern SBT_PROC m_sbt_proc;
extern int m_channels;
extern int m_sfBandIndex[2][22];
extern int m_band_limit;
extern int m_ncbl_mixed;
extern SIDE_INFO m_side_info;
extern int m_buf_ptr0;
extern int m_buf_ptr1;
extern int m_nsamp[2][2];	/* must start = 0, for m_nsamp[igr_prev] */
extern float m_yout[576];
extern int m_frame_size;
extern int m_pcm_size;
extern int m_ms_mode;
extern int m_is_mode;
extern int m_gr;
extern int m_main_pos_bit;
extern byte m_buf[8192];

#define NBUF (8 * 1024)
#define BUF_TRIGGER (NBUF - 1500)

void bitget_init(unsigned char *buf);
int L3get_side_info1();
int L3get_side_info2(int gr);
void L3decode_main(MPEG_HEADER *h, byte *pcm, int gr);
void *memmove(void *, const void *, unsigned int);

int hybrid(float xin[], float xprev[], float y[18][32], int btype, int nlong, int ntot, int nprev);
int hybrid_sum(float xin[], float xin_left[], float y[18][32], int btype, int nlong, int ntot);
void sum_f_bands(float a[], float b[], int n);
void freq_invert(float y[18][32], int n);

void L3decode_reset()
{
	m_buf_ptr0 = m_buf_ptr1 = 0;
}

void L3decode_frame(MPEG_HEADER *h, byte *mpeg, byte *pcm)
{
	int crc_size, side_size;
	int copy_size;

	if (h->mode == 1) {
		m_ms_mode = h->mode_ext >> 1;
		m_is_mode = h->mode_ext & 1;
	} else {
		m_ms_mode = 0;
		m_is_mode = 0;
	}

	crc_size = (h->error_prot) ? 2 : 0;
	bitget_init(mpeg + 4 + crc_size);
	if (h->version == 1)
		side_size = L3get_side_info1();
	else
		side_size = L3get_side_info2(m_gr);

	m_buf_ptr0 = m_buf_ptr1 - m_side_info.main_data_begin;	/* decode start point */
	if (m_buf_ptr1 > BUF_TRIGGER) {	/* shift buffer */
		memmove(m_buf, m_buf + m_buf_ptr0, m_side_info.main_data_begin);
		m_buf_ptr0 = 0;
		m_buf_ptr1 = m_side_info.main_data_begin;
	}
	copy_size = m_frame_size - (4 + crc_size + side_size);
	memmove(m_buf + m_buf_ptr1, mpeg + (4 + crc_size + side_size), copy_size);
	m_buf_ptr1 += copy_size;

	if (m_buf_ptr0 >= 0) {
		m_main_pos_bit = m_buf_ptr0 << 3;
		if (h->version == 1) {
			L3decode_main(h, pcm, 0);
			L3decode_main(h, pcm + (m_pcm_size / 2), 1);
		} else {
			L3decode_main(h, pcm, m_gr);
			m_gr = m_gr ^ 1;
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l3dec", L3decode_main);

void xform_mono(void *pcm, int igr)
{
	int igr_prev, n1, n2;

	/*--- hybrid + sbt ---*/
	n1 = n2 = m_nsamp[igr][0];	/* total number bands */
	if (m_side_info.gr[igr][0].block_type == 2) {	/* long bands */
		n1 = 0;
		if (m_side_info.gr[igr][0].mixed_block_flag)
			n1 = m_sfBandIndex[0][m_ncbl_mixed - 1];
	}
	if (n1 > m_band_limit)
		n1 = m_band_limit;
	if (n2 > m_band_limit)
		n2 = m_band_limit;
	igr_prev = igr ^ 1;

	m_nsamp[igr][0] = hybrid((float *)m_sample[0][igr], (float *)m_sample[0][igr_prev],
	    (float (*)[32])m_yout, m_side_info.gr[igr][0].block_type, n1, n2, m_nsamp[igr_prev][0]);
	freq_invert((float (*)[32])m_yout, m_nsamp[igr][0]);
	m_sbt_proc(m_yout, pcm, 0);
}

void xform_dual_right(void *pcm, int igr)
{
	int igr_prev, n1, n2;

	/*--- hybrid + sbt ---*/
	n1 = n2 = m_nsamp[igr][1];	/* total number bands */
	if (m_side_info.gr[igr][1].block_type == 2) {	/* long bands */
		n1 = 0;
		if (m_side_info.gr[igr][1].mixed_block_flag)
			n1 = m_sfBandIndex[0][m_ncbl_mixed - 1];
	}
	if (n1 > m_band_limit)
		n1 = m_band_limit;
	if (n2 > m_band_limit)
		n2 = m_band_limit;
	igr_prev = igr ^ 1;
	m_nsamp[igr][1] = hybrid((float *)m_sample[1][igr], (float *)m_sample[1][igr_prev],
	    (float (*)[32])m_yout, m_side_info.gr[igr][1].block_type, n1, n2, m_nsamp[igr_prev][1]);
	freq_invert((float (*)[32])m_yout, m_nsamp[igr][1]);
	m_sbt_proc(m_yout, pcm, 0);
}

void xform_dual(void *pcm, int igr)
{
	int ch;
	int igr_prev, n1, n2;

	/*--- hybrid + sbt ---*/
	igr_prev = igr ^ 1;
	for (ch = 0; ch < m_channels; ch++) {
		n1 = n2 = m_nsamp[igr][ch];	/* total number bands */
		if (m_side_info.gr[igr][ch].block_type == 2) {	/* long bands */
			n1 = 0;
			if (m_side_info.gr[igr][ch].mixed_block_flag)
				n1 = m_sfBandIndex[0][m_ncbl_mixed - 1];
		}
		if (n1 > m_band_limit)
			n1 = m_band_limit;
		if (n2 > m_band_limit)
			n2 = m_band_limit;
		m_nsamp[igr][ch] = hybrid((float *)m_sample[ch][igr], (float *)m_sample[ch][igr_prev],
		    (float (*)[32])m_yout, m_side_info.gr[igr][ch].block_type, n1, n2, m_nsamp[igr_prev][ch]);
		freq_invert((float (*)[32])m_yout, m_nsamp[igr][ch]);
		m_sbt_proc(m_yout, pcm, ch);
	}
}

#ifdef NON_MATCHING
/* the original spills more (frame 0x50 vs 0x40) */
void xform_dual_mono(void *pcm, int igr)
{
	int igr_prev, n1, n2, n3;

	/*--- hybrid + sbt ---*/
	igr_prev = igr ^ 1;
	if ((m_side_info.gr[igr][0].block_type == m_side_info.gr[igr][1].block_type)
	    && (m_side_info.gr[igr][0].mixed_block_flag == 0)
	    && (m_side_info.gr[igr][1].mixed_block_flag == 0)) {
		n2 = m_nsamp[igr][0];	/* total number bands max of L R */
		if (n2 < m_nsamp[igr][1])
			n2 = m_nsamp[igr][1];
		if (n2 > m_band_limit)
			n2 = m_band_limit;
		n1 = n2;	/* n1 = number long bands */
		if (m_side_info.gr[igr][0].block_type == 2)
			n1 = 0;
		sum_f_bands((float *)m_sample[0][igr], (float *)m_sample[1][igr], n2);
		n3 = m_nsamp[igr][0] = hybrid((float *)m_sample[0][igr], (float *)m_sample[0][igr_prev],
		    (float (*)[32])m_yout, m_side_info.gr[igr][0].block_type, n1, n2, m_nsamp[igr_prev][0]);
	} else {	/* transform and then sum (not tested - never happens in test) */
		/*-- left chan --*/
		n1 = n2 = m_nsamp[igr][0];	/* total number bands */
		if (m_side_info.gr[igr][0].block_type == 2) {
			n1 = 0;	/* long bands */
			if (m_side_info.gr[igr][0].mixed_block_flag)
				n1 = m_sfBandIndex[0][m_ncbl_mixed - 1];
		}
		n3 = m_nsamp[igr][0] = hybrid((float *)m_sample[0][igr], (float *)m_sample[0][igr_prev],
		    (float (*)[32])m_yout, m_side_info.gr[igr][0].block_type, n1, n2, m_nsamp[igr_prev][0]);
		/*-- right chan --*/
		n1 = n2 = m_nsamp[igr][1];	/* total number bands */
		if (m_side_info.gr[igr][1].block_type == 2) {
			n1 = 0;	/* long bands */
			if (m_side_info.gr[igr][1].mixed_block_flag)
				n1 = m_sfBandIndex[0][m_ncbl_mixed - 1];
		}
		m_nsamp[igr][1] = hybrid_sum((float *)m_sample[1][igr], (float *)m_sample[0][igr],
		    (float (*)[32])m_yout, m_side_info.gr[igr][1].block_type, n1, n2);
		if (n3 < m_nsamp[igr][1])
			n1 = m_nsamp[igr][1];
	}

	/*--------*/
	freq_invert((float (*)[32])m_yout, n3);
	m_sbt_proc(m_yout, pcm, 0);
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l3dec", xform_dual_mono);
#endif
