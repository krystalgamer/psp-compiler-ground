#include "common.h"

extern float wincoef[264];

void window(float *vbuf, int vb_ptr, short *pcm)
{
	int i;
	int j;
	int si;
	int bx;
	float *coef;
	float sum;
	int tmp;

	si = vb_ptr + 16;
	bx = (si + 32) & 511;
	coef = wincoef;

	/* first 16 */
	for (i = 0; i < 16; i++) {
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef++) * vbuf[si];
			si = (si + 64) & 511;
			sum -= (*coef++) * vbuf[bx];
			bx = (bx + 64) & 511;
		}
		si++;
		bx--;
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm++ = tmp;
	}
	/* special case */
	sum = 0.0F;
	for (j = 0; j < 8; j++) {
		sum += (*coef++) * vbuf[bx];
		bx = (bx + 64) & 511;
	}
	tmp = (int)sum;
	if (tmp > 32767)
		tmp = 32767;
	else if (tmp < -32768)
		tmp = -32768;
	*pcm++ = tmp;
	/* last 15 */
	coef = wincoef + 255;
	for (i = 0; i < 15; i++) {
		si--;
		bx++;
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef--) * vbuf[si];
			si = (si + 64) & 511;
			sum += (*coef--) * vbuf[bx];
			bx = (bx + 64) & 511;
		}
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm++ = tmp;
	}
}

void window_dual(float *vbuf, int vb_ptr, short *pcm)
{
	int i;
	int j;
	int si;
	int bx;
	float *coef;
	float sum;
	int tmp;

	si = vb_ptr + 16;
	bx = (si + 32) & 511;
	coef = wincoef;

	/* first 16 */
	for (i = 0; i < 16; i++) {
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef++) * vbuf[si];
			si = (si + 64) & 511;
			sum -= (*coef++) * vbuf[bx];
			bx = (bx + 64) & 511;
		}
		si++;
		bx--;
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm = tmp;
		pcm += 2;
	}
	/* special case */
	sum = 0.0F;
	for (j = 0; j < 8; j++) {
		sum += (*coef++) * vbuf[bx];
		bx = (bx + 64) & 511;
	}
	tmp = (int)sum;
	if (tmp > 32767)
		tmp = 32767;
	else if (tmp < -32768)
		tmp = -32768;
	*pcm = tmp;
	pcm += 2;
	/* last 15 */
	coef = wincoef + 255;
	for (i = 0; i < 15; i++) {
		si--;
		bx++;
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef--) * vbuf[si];
			si = (si + 64) & 511;
			sum += (*coef--) * vbuf[bx];
			bx = (bx + 64) & 511;
		}
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm = tmp;
		pcm += 2;
	}
}

void window16(float *vbuf, int vb_ptr, short *pcm)
{
	int i;
	int j;
	unsigned char si;
	unsigned char bx;
	float *coef;
	float sum;
	int tmp;

	si = vb_ptr + 8;
	bx = si + 16;
	coef = wincoef;

	/* first 8 */
	for (i = 0; i < 8; i++) {
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef++) * vbuf[si];
			si += 32;
			sum -= (*coef++) * vbuf[bx];
			bx += 32;
		}
		si++;
		bx--;
		coef += 16;
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm++ = tmp;
	}
	/* special case */
	sum = 0.0F;
	for (j = 0; j < 8; j++) {
		sum += (*coef++) * vbuf[bx];
		bx += 32;
	}
	tmp = (int)sum;
	if (tmp > 32767)
		tmp = 32767;
	else if (tmp < -32768)
		tmp = -32768;
	*pcm++ = tmp;
	/* last 7 */
	coef = wincoef + 255;
	for (i = 0; i < 7; i++) {
		coef -= 16;
		si--;
		bx++;
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef--) * vbuf[si];
			si += 32;
			sum += (*coef--) * vbuf[bx];
			bx += 32;
		}
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm++ = tmp;
	}
}

void window16_dual(float *vbuf, int vb_ptr, short *pcm)
{
	int i;
	int j;
	unsigned char si;
	unsigned char bx;
	float *coef;
	float sum;
	int tmp;

	si = vb_ptr + 8;
	bx = si + 16;
	coef = wincoef;

	/* first 8 */
	for (i = 0; i < 8; i++) {
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef++) * vbuf[si];
			si += 32;
			sum -= (*coef++) * vbuf[bx];
			bx += 32;
		}
		si++;
		bx--;
		coef += 16;
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm = tmp;
		pcm += 2;
	}
	/* special case */
	sum = 0.0F;
	for (j = 0; j < 8; j++) {
		sum += (*coef++) * vbuf[bx];
		bx += 32;
	}
	tmp = (int)sum;
	if (tmp > 32767)
		tmp = 32767;
	else if (tmp < -32768)
		tmp = -32768;
	*pcm = tmp;
	pcm += 2;
	/* last 7 */
	coef = wincoef + 255;
	for (i = 0; i < 7; i++) {
		coef -= 16;
		si--;
		bx++;
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef--) * vbuf[si];
			si += 32;
			sum += (*coef--) * vbuf[bx];
			bx += 32;
		}
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm = tmp;
		pcm += 2;
	}
}

void window8(float *vbuf, int vb_ptr, short *pcm)
{
	int i;
	int j;
	int si;
	int bx;
	float *coef;
	float sum;
	int tmp;

	si = vb_ptr + 4;
	bx = (si + 8) & 127;
	coef = wincoef;

	/* first 4 */
	for (i = 0; i < 4; i++) {
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef++) * vbuf[si];
			si = (si + 16) & 127;
			sum -= (*coef++) * vbuf[bx];
			bx = (bx + 16) & 127;
		}
		si++;
		bx--;
		coef += 48;
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm++ = tmp;
	}
	/* special case */
	sum = 0.0F;
	for (j = 0; j < 8; j++) {
		sum += (*coef++) * vbuf[bx];
		bx = (bx + 16) & 127;
	}
	tmp = (int)sum;
	if (tmp > 32767)
		tmp = 32767;
	else if (tmp < -32768)
		tmp = -32768;
	*pcm++ = tmp;
	/* last 3 */
	coef = wincoef + 255;
	for (i = 0; i < 3; i++) {
		coef -= 48;
		si--;
		bx++;
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef--) * vbuf[si];
			si = (si + 16) & 127;
			sum += (*coef--) * vbuf[bx];
			bx = (bx + 16) & 127;
		}
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm++ = tmp;
	}
}

void window8_dual(float *vbuf, int vb_ptr, short *pcm)
{
	int i;
	int j;
	int si;
	int bx;
	float *coef;
	float sum;
	int tmp;

	si = vb_ptr + 4;
	bx = (si + 8) & 127;
	coef = wincoef;

	/* first 4 */
	for (i = 0; i < 4; i++) {
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef++) * vbuf[si];
			si = (si + 16) & 127;
			sum -= (*coef++) * vbuf[bx];
			bx = (bx + 16) & 127;
		}
		si++;
		bx--;
		coef += 48;
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm = tmp;
		pcm += 2;
	}
	/* special case */
	sum = 0.0F;
	for (j = 0; j < 8; j++) {
		sum += (*coef++) * vbuf[bx];
		bx = (bx + 16) & 127;
	}
	tmp = (int)sum;
	if (tmp > 32767)
		tmp = 32767;
	else if (tmp < -32768)
		tmp = -32768;
	*pcm = tmp;
	pcm += 2;
	/* last 3 */
	coef = wincoef + 255;
	for (i = 0; i < 3; i++) {
		coef -= 48;
		si--;
		bx++;
		sum = 0.0F;
		for (j = 0; j < 8; j++) {
			sum += (*coef--) * vbuf[si];
			si = (si + 16) & 127;
			sum += (*coef--) * vbuf[bx];
			bx = (bx + 16) & 127;
		}
		tmp = (int)sum;
		if (tmp > 32767)
			tmp = 32767;
		else if (tmp < -32768)
			tmp = -32768;
		*pcm = tmp;
		pcm += 2;
	}
}
