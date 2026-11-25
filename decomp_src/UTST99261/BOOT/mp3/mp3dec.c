#include "common.h"
#include <string.h>
#include <math.h>
#include "mp3dec.h"

extern const int br_tbl[3][3][16];
extern const int fr_tbl[3][9];

extern MPEG_DECODE_OPTION m_option;
extern FRAME_PROC m_frame_proc;
extern int m_last_error;
extern int m_frequency;
extern int m_frame_size;
extern int m_pcm_size;
extern int m_enableEQ;
extern float m_equalizer[32];

void mp3DecodeInit()
{
	m_option.reduction = 0;
	m_option.convert = 0;
	m_option.freqLimit = 24000;
	L1table_init();
	L2table_init();
	L3table_init();
}

int mp3GetHeader(byte *buf, MPEG_HEADER *h)
{
	h->version = (buf[1] & 0x08) >> 3;
	h->layer = (buf[1] & 0x06) >> 1;
	h->error_prot = buf[1] & 0x01;
	h->br_index = buf[2] >> 4;
	h->fr_index = (buf[2] & 0x0C) >> 2;
	h->padding = (buf[2] & 0x02) >> 1;
	h->extension = buf[2] & 0x01;
	h->mode = buf[3] >> 6;
	h->mode_ext = (buf[3] & 0x30) >> 4;
	h->copyright = (buf[3] & 0x08) >> 3;
	h->original = (buf[3] & 0x04) >> 2;
	h->emphasis = buf[3] & 0x03;
	if (buf[0] != 0xFF) {
		m_last_error = 3;
		return 0;
	}
	if ((buf[1] & 0xF0) == 0xF0)
		h->version = h->version ? 1 : 2;
	else if ((buf[1] & 0xF0) == 0xE0)
		h->version = 3;
	else {
		m_last_error = 3;
		return 0;
	}
	if (h->fr_index >= 3) {
		m_last_error = 4;
		return 0;
	}
	if (h->br_index == 0) {
		m_last_error = 4;
		return 0;
	}
	if (h->br_index >= 15) {
		m_last_error = 4;
		return 0;
	}
	if (h->layer == 0) {
		m_last_error = 4;
		return 0;
	}
	if (h->layer >= 4) {
		m_last_error = 4;
		return 0;
	}
	h->layer = 4 - h->layer;
	h->error_prot = (h->error_prot == 0) ? 1 : 0;
	return 1;
}

int mp3GetLastError()
{
	return m_last_error;
}

int mp3FindSync(void *buftop, int size, int *sync)
{
	byte *buf;
	int i;

	buf = buftop;
	*sync = 0;
	size -= 3;
	if (size <= 0) {
		m_last_error = 5;
		return 0;
	}
	for (i = 0; i < size; i++) {
		if (buf[i] == 0xFF) {
			if ((buf[i + 1] & 0xF0) == 0xF0)
				break;
			if ((buf[i + 1] & 0xF0) == 0xE0)
				break;
		}
	}
	if (i == size) {
		m_last_error = 5;
		return 0;
	}
	*sync = i;
	return 1;
}

void mp3GetDecodeOption(MPEG_DECODE_OPTION *option)
{
	*option = m_option;
}

int mp3SetDecodeOption(MPEG_DECODE_OPTION *option)
{
	m_option = *option;
	return 1;
}

int mp3SetEqualizer(int *value)
{
	int i;

	if (value == NULL) {
		m_enableEQ = 0;
		return 1;
	}
	m_enableEQ = 1;
	for (i = 0; i < 6; i++)
		m_equalizer[i] = pow(10.0, value[i] / 200.0);
	m_equalizer[7] = m_equalizer[6] = pow(10.0, value[6] / 200.0);
	m_equalizer[11] = m_equalizer[10] = m_equalizer[9] = m_equalizer[8] = pow(10.0, value[7] / 200.0);
	m_equalizer[19] = m_equalizer[18] = m_equalizer[17] = m_equalizer[16] = m_equalizer[15] = m_equalizer[14] = m_equalizer[13] = m_equalizer[12] = pow(10.0, value[8] / 200.0);
	m_equalizer[31] = m_equalizer[30] = m_equalizer[29] = m_equalizer[28] = m_equalizer[27] = m_equalizer[26] = m_equalizer[25] = m_equalizer[24] = m_equalizer[23] = m_equalizer[22] = m_equalizer[21] = m_equalizer[20] = pow(10.0, value[9] / 200.0);
	return 1;
}

static int extractInt4(byte *buf)
{
	return buf[3] | (buf[2] << 8) | (buf[1] << 16) | (buf[0] << 24);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", br_tbl);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", fr_tbl);

#ifdef NON_MATCHING
/* same code; p gets its own register in the original */
int mp3GetDecodeInfo(void *mpegtop, int size, MPEG_DECODE_INFO *info, int decFlag)
{
	byte *mpeg;
	MPEG_HEADER *h;
	byte *p;
	int vbr;
	uint minBitRate;
	uint maxBitRate;
	uint i;
	uint j;
	uint flags;

	vbr = 0;
	minBitRate = 0;
	maxBitRate = 0;
	mpeg = mpegtop;
	h = &info->header;
	if (size < 156) {
		m_last_error = 5;
		return 0;
	}
	if (!mp3GetHeader(mpeg, h))
		return 0;
	p = mpeg + 4;
	if (h->error_prot)
		p = mpeg + 6;
	if (h->layer == 3) {
		if (h->version == 1)
			p += (h->mode != 3) ? 32 : 17;
		else
			p += (h->mode != 3) ? 17 : 9;
	}
	info->bitRate = br_tbl[h->version - 1][h->layer - 1][h->br_index] * 1000;
	info->frequency = fr_tbl[h->version - 1][h->fr_index];
	if (memcmp(p, "Xing", 4) == 0) {
		p += 4;
		flags = extractInt4(p);
		p += 4;
		if (!(flags & 3)) {
			m_last_error = 4;
			return 0;
		}
		info->frames = extractInt4(p);
		p += 4;
		info->dataSize = extractInt4(p);
		vbr = 1;
		minBitRate = 0xFFFFFFFF;
		maxBitRate = 0;
		for (i = 1; i < 15; i++) {
			j = br_tbl[h->version - 1][h->layer - 1][i] * 1000;
			if (j < minBitRate)
				minBitRate = j;
			if (j > maxBitRate)
				maxBitRate = j;
		}
	} else if (memcmp(p, "VBRI", 4) == 0) {
		p += 10;
		info->dataSize = extractInt4(p);
		p += 4;
		info->frames = extractInt4(p);
		vbr = 1;
		minBitRate = 0xFFFFFFFF;
		maxBitRate = 0;
		for (i = 1; i < 15; i++) {
			j = br_tbl[h->version - 1][h->layer - 1][i] * 1000;
			if (j < minBitRate)
				minBitRate = j;
			if (j > maxBitRate)
				maxBitRate = j;
		}
	} else {
		vbr = 0;
		info->frames = 0;
		info->dataSize = 0;
	}
	switch (h->layer) {
	case 1:
		info->outputSize = 384 >> m_option.reduction;
		if (vbr) {
			info->skipSize = (12 * info->bitRate / info->frequency + h->padding) * 4;
			info->minInputSize = (12 * minBitRate / info->frequency) * 4;
			info->maxInputSize = (12 * maxBitRate / info->frequency) * 4 + 4;
		} else {
			info->skipSize = 0;
			info->minInputSize = (12 * info->bitRate / info->frequency) * 4;
			info->maxInputSize = info->minInputSize + 4;
		}
		break;
	case 2:
		info->outputSize = 1152 >> m_option.reduction;
		if (vbr) {
			info->skipSize = 144 * info->bitRate / info->frequency + h->padding;
			info->minInputSize = 144 * minBitRate / info->frequency;
			info->maxInputSize = 144 * maxBitRate / info->frequency + 1;
		} else {
			info->skipSize = 0;
			info->minInputSize = 144 * info->bitRate / info->frequency;
			info->maxInputSize = info->minInputSize + 1;
		}
		break;
	case 3:
		i = (h->version == 1) ? 1 : 2;
		info->outputSize = (1152 >> m_option.reduction) / i;
		if (vbr) {
			info->skipSize = 144 * info->bitRate / info->frequency / i + h->padding;
			info->minInputSize = 144 * minBitRate / info->frequency / i;
			info->maxInputSize = 144 * maxBitRate / info->frequency / i + 1;
		} else {
			info->skipSize = 0;
			info->minInputSize = 144 * info->bitRate / info->frequency / i;
			info->maxInputSize = info->minInputSize + 1;
		}
		break;
	}
	if (h->mode == 3)
		info->channels = 1;
	else if (m_option.convert & 3)
		info->channels = 1;
	else
		info->channels = 2;
	if (m_option.convert & 8) {
		info->bitsPerSample = 8;
		info->outputSize = info->outputSize * info->channels;
	} else {
		info->bitsPerSample = 16;
		info->outputSize = info->outputSize * info->channels * 2;
	}
	if (decFlag == 1) {
		m_frequency = info->frequency;
		m_pcm_size = info->outputSize;
	}
	info->frequency = info->frequency >> m_option.reduction;
	if (vbr)
		info->bitRate = 0;
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3GetDecodeInfo);
#endif

#ifdef NON_MATCHING
/* v0/v1 swapped for the frame_proc stores; the first case branch has an empty delay slot */
int mp3DecodeStart(void *mpegtop, int size)
{
	byte *mpeg;
	MPEG_DECODE_INFO info;
	MPEG_HEADER *h;

	mpeg = mpegtop;
	h = &info.header;
	if (!mp3GetDecodeInfo(mpeg, size, &info, 1))
		return 0;
	sbt_init();
	switch (h->layer) {
	case 1:
		L1decode_start(h);
		m_frame_proc = L1decode_frame;
		break;
	case 2:
		L2decode_start(h);
		m_frame_proc = L2decode_frame;
		break;
	case 3:
		L3decode_start(h);
		m_frame_proc = L3decode_frame;
		break;
	}
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/mp3dec", mp3DecodeStart);
#endif

int mp3DecodeFrame(MPEG_DECODE_PARAM *param)
{
	MPEG_HEADER *h;

	h = &param->header;
	if (param->inputSize <= 4) {
		m_last_error = 5;
		return 0;
	}
	if (!mp3GetHeader(param->inputBuf, h))
		return 0;
	param->bitRate = br_tbl[h->version - 1][h->layer - 1][h->br_index] * 1000;
	switch (h->layer) {
	case 1:
		m_frame_size = (12 * param->bitRate / m_frequency + h->padding) * 4;
		break;
	case 2:
		m_frame_size = 144 * param->bitRate / m_frequency + h->padding;
		break;
	case 3:
		if (h->version == 1)
			m_frame_size = 144 * param->bitRate / m_frequency + h->padding;
		else
			m_frame_size = 72 * param->bitRate / m_frequency + h->padding;
		break;
	}
	if (param->inputSize < m_frame_size) {
		m_last_error = 5;
		return 0;
	}
	m_frame_proc(h, param->inputBuf, param->outputBuf);
	param->inputSize = m_frame_size;
	param->outputSize = m_pcm_size;
	return 1;
}

void null_frame_proc(MPEG_HEADER *h, byte *mpeg, byte *pcm)
{
}

void mp3MuteStart(MPEG_DECODE_PARAM *param)
{
	m_frame_proc = null_frame_proc;
}

void mp3MuteEnd(MPEG_DECODE_PARAM *param)
{
	MPEG_HEADER *h;

	h = &param->header;
	switch (h->layer) {
	case 1:
		m_frame_proc = L1decode_frame;
		break;
	case 2:
		m_frame_proc = L2decode_frame;
		break;
	case 3:
		L3decode_reset();
		m_frame_proc = L3decode_frame;
		break;
	}
}
