#include "common.h"
#include "mp3dec.h"

typedef void (*SBT_PROC)(float *, void *, int);

extern float m_sample[2304];
extern int m_nsb_limit;
extern SBT_PROC m_sbt_proc;
extern int m_bit_skip;

/* defined here in the original; the data stays in asm */
extern int m_stereo_sb;
extern int m_max_sb;
extern float m_look_c_valueL2[18];
extern int m_nbat[4];
extern int m_bat[4][16];
extern int m_ballo[64];
extern unsigned int m_samp_dispatch[66];
extern float m_c_value[64];
extern unsigned int m_sf_dispatch[66];

/* static const in the original; the tables stay in asm */
#define look_joint look_joint_10FA80
extern const int look_joint[16];
extern const int bat_bit_masterL2[18];

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2dec", look_joint_10FA80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2dec", bat_bit_masterL2);

void bitget_init(unsigned char *buf);
void bitget_check(int n);
int mac_bitget(int n);

void unpack_ba();
void unpack_sfs();
void unpack_sf();
void unpack_samp();

void L2decode_frame(MPEG_HEADER *h, byte *mpeg, byte *pcm)
{
	int crc_size;

	crc_size = (h->error_prot) ? 2 : 0;
	bitget_init(mpeg + crc_size + 4);
	m_stereo_sb = look_joint[(h->mode << 2) + h->mode_ext];
	unpack_ba();		/* unpack bit allocation */
	unpack_sfs();		/* unpack scale factor selectors */
	unpack_sf();		/* unpack scale factor */
	unpack_samp();		/* unpack samples */
	m_sbt_proc(m_sample, pcm, 36);
}

void unpack_ba()
{
	int i, j, k;
	int nstereo;
	int nbit[4] = {4, 4, 3, 2};

	m_bit_skip = 0;
	nstereo = m_stereo_sb;
	k = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < m_nbat[i]; j++, k++) {
			bitget_check(4);
			m_ballo[k] = m_samp_dispatch[k] = m_bat[i][mac_bitget(nbit[i])];
			if (k >= m_nsb_limit)
				m_bit_skip += bat_bit_masterL2[m_samp_dispatch[k]];
			m_c_value[k] = m_look_c_valueL2[m_samp_dispatch[k]];
			if (--nstereo < 0) {
				m_ballo[k + 1] = m_ballo[k];
				m_samp_dispatch[k] += 18;	/* flag as joint */
				m_samp_dispatch[k + 1] = m_samp_dispatch[k];	/* flag for sf */
				m_c_value[k + 1] = m_c_value[k];
				k++;
				j++;
			}
		}
	}
	m_samp_dispatch[m_nsb_limit] = 37;	/* terminate the dispatcher with skip */
	m_samp_dispatch[k] = 36;	/* terminate the dispatcher */
}

void unpack_sfs()	/* unpack scale factor selectors */
{
	int i;

	for (i = 0; i < m_max_sb; i++) {
		bitget_check(2);
		if (m_ballo[i])
			m_sf_dispatch[i] = mac_bitget(2);
		else
			m_sf_dispatch[i] = 4;	/* no allo */
	}
	m_sf_dispatch[i] = 5;	/* terminate dispatcher */
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2dec", unpack_sf);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/l2dec", unpack_samp);
