#include "common.h"
#include "mp3dec.h"

typedef void (*SBT_PROC)(float *, void *, int);

extern float m_sample[2304];
extern int m_nsb_limit;
extern SBT_PROC m_sbt_proc;
extern int m_stereo_sb;
extern int m_ballo[64];		/* set by unpack_ba */
extern unsigned int m_samp_dispatch[66];	/* set by unpack_ba */
extern float m_c_value[64];	/* set by unpack_ba */
extern float m_sf_table[64];
extern float m_cs_factor[3][64];

/* defined here in the original; the data stays in asm */
extern float m_look_c_valueL1[18];
extern float *m_cs_factorL1;
extern int m_nbatL1;
extern int m_bit_skip;

/* static const in the original; the tables stay in asm */
#define look_joint look_joint_10FE70
extern const int look_joint[16];
extern const int bat_bit_masterL1[16];

void bitget_init(unsigned char *buf);
void bitget_check(int n);
int mac_bitget(int n);

void unpack_baL1();
void unpack_sfL1();
void unpack_sampL1();

void L1decode_frame(MPEG_HEADER *h, byte *mpeg, byte *pcm)
{
	int crc_size;

	crc_size = (h->error_prot) ? 2 : 0;
	bitget_init(mpeg + crc_size + 4);
	m_stereo_sb = look_joint[(h->mode << 2) + h->mode_ext];
	unpack_baL1();		/* unpack bit allocation */
	unpack_sfL1();		/* unpack scale factor */
	unpack_sampL1();	/* unpack samples */
	m_sbt_proc(m_sample, pcm, 12);
}

void unpack_baL1()
{
	int j;
	int nstereo;

	m_bit_skip = 0;
	nstereo = m_stereo_sb;

	for (j = 0; j < m_nbatL1; j++) {
		bitget_check(4);
		m_ballo[j] = m_samp_dispatch[j] = mac_bitget(4);
		if (j >= m_nsb_limit)
			m_bit_skip += bat_bit_masterL1[m_samp_dispatch[j]];
		m_c_value[j] = m_look_c_valueL1[m_samp_dispatch[j]];
		if (--nstereo < 0) {
			m_ballo[j + 1] = m_ballo[j];
			m_samp_dispatch[j] += 15;	/* flag as joint */
			m_samp_dispatch[j + 1] = m_samp_dispatch[j];	/* flag for sf */
			m_c_value[j + 1] = m_c_value[j];
			j++;
		}
	}
	/*-- terminate with bit skip and end --*/
	m_samp_dispatch[m_nsb_limit] = 31;
	m_samp_dispatch[j] = 30;
}

void unpack_sfL1()	/* unpack scale factor */
{			/* combine dequant and scale factors */
	int i;

	for (i = 0; i < m_nbatL1; i++) {
		if (m_ballo[i]) {
			bitget_check(6);
			m_cs_factorL1[i] = m_c_value[i] * m_sf_table[mac_bitget(6)];
		}
	}
	/*-- done --*/
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l1dec", look_joint_10FE70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l1dec", bat_bit_masterL1);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l1dec", unpack_sampL1);
