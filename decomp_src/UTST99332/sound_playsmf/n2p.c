#include "common.h"

extern unsigned short D_000185CC[]; /* note pitch table */
extern unsigned short D_000185E4[]; /* D_000185CC + 12 */

#ifdef NON_MATCHING
/* logic matches; register choice differs (original looks like -frename-registers output from another compiler build) */
unsigned short sceSsNote2Pitch(unsigned short center_note, unsigned short center_fine, unsigned short note, short fine)
{
	int _fine;
	int _fine2;
	short _note;
	short offset1;
	int offset2;
	short val2;
	unsigned int ret;

	_fine = fine + center_fine;
	_fine2 = _fine / 128;
	_note = _fine2 + note - center_note;
	offset1 = _note % 12;
	val2 = _note / 12 - 2;
	offset2 = _fine % 128;

	if (offset1 < 0 || (offset1 == 0 && offset2 < 0)) {
		offset1 += 12;
		val2--;
	}

	if (offset2 < 0) {
		offset1 = offset1 + _fine2 - 1;
		offset2 = offset2 + (_fine2 + 1) * 128;
	}

	ret = (D_000185CC[offset1] * D_000185E4[offset2]) >> 16;

	if (val2 < 0)
		ret = (ret + (1 << (-val2 - 1))) >> -val2;

	return ret;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/n2p", sceSsNote2Pitch);
#endif

INCLUDE_ASM("tmp/asm/UTST99332/sound_playsmf/nonmatchings/n2p", sceSsPitch2Note);
