/* cflags: -O2 -frename-registers */
#include "common.h"
#include <psptypes.h>

typedef SceInt32 SceMpegStrType;
typedef SceUInt32 SceMpegStreamId;

typedef struct StreamID {
	SceUInt32 str_id;
	SceUInt32 str_mask;
} StreamID;

#define SCE_MPEG_ERROR_INVALID_VALUE 0x806101FE

static const StreamID _strmap[17] = {
	{ 0xE0000000, 0xFF000000 },
	{ 0xBD000000, 0xFFFF0000 },
	{ 0xBD100000, 0xFFFF0000 },
	{ 0xBD200000, 0xFFFF0000 },
	{ 0xC0000000, 0xFF000000 },
	{ 0xBD800000, 0xFFFF0000 },
	{ 0xBF01E000, 0xFFFFFF00 },
	{ 0xE0000000, 0xFF000000 },
	{ 0xBDFFC000, 0xFFFFFFFF },
	{ 0xBDFFA000, 0xFFFFFFFF },
	{ 0xBDFFA100, 0xFFFFFFFF },
	{ 0xBDFF9000, 0xFFFFFFFF },
	{ 0xC0000000, 0xFF000000 },
	{ 0xBD800000, 0xFFFF0000 },
	{ 0xBDA00000, 0xFFFF0000 },
	{ 0xBD880000, 0xFFFF0000 },
	{ 0xBD900000, 0xFFFF0000 },
};
static const SceInt32 STRTYPE_MAX = 16;

SceMpegStreamId _sceMpegType2id(SceMpegStrType type, SceInt32 ch)
{
	int sh = 0;

	if (type > STRTYPE_MAX)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	switch (_strmap[type].str_mask) {
	case 0xFF000000:
		sh = 24;
		break;
	case 0xFFFF0000:
		sh = 16;
		break;
	case 0xFFFFFF00:
		sh = 8;
		break;
	case 0xFFFFFFFF:
		break;
	default:
		return 0;
	}
	return _strmap[type].str_id | (ch << sh);
}

SceInt32 _sceMpegId2type(SceMpegStrType *type, SceInt32 *ch, SceUInt32 str_id)
{
	SceInt32 ret = 0;
	SceUInt32 str_id_base = 0;
	SceUInt32 str_id_ref;
	SceUInt32 mask = 0;
	SceInt32 i = 0;

	for (i = 0; i <= STRTYPE_MAX && ret == 0; i++) {
		switch (_strmap[i].str_mask) {
		case 0xFFFFFFFF:
			str_id_base = str_id & 0xFFFFFF00;
			if (str_id_base == _strmap[i].str_id) {
				*type = i;
				ret = 1;
				*ch = str_id & 0xFFFF;
			}
			break;
		case 0xFFFFFF00:
			str_id_ref = _strmap[i].str_id;
			if (str_id_ref == 0xBF01E000) {
				str_id_base = str_id & 0xFFFFE000;
				mask = 0x1F;
			}
			if (str_id_base == str_id_ref) {
				*type = i;
				*ch = (str_id >> 8) & mask;
				ret = 1;
			}
			break;
		case 0xFFFF0000:
			str_id_ref = _strmap[i].str_id;
			switch (str_id_ref) {
			case 0xBD800000:
				str_id_base = str_id & 0xFFE00000;
				mask = 0x1F;
				break;
			case 0xBD000000:
			case 0xBD100000:
			case 0xBD200000:
				str_id_base = str_id & 0xFFF00000;
				mask = 0xF;
				break;
			case 0xBD880000:
			case 0xBD900000:
			case 0xBDA00000:
				str_id_base = str_id & 0xFFF80000;
				mask = 0x7;
				break;
			default:
				str_id_base = str_id & 0xFFFF0000;
				mask = 0;
				break;
			}
			if (str_id_base == str_id_ref) {
				*type = i;
				*ch = (str_id >> 16) & mask;
				ret = 1;
			}
			break;
		case 0xFF000000:
			str_id_ref = _strmap[i].str_id;
			if (str_id_ref == 0xE0000000) {
				str_id_base = str_id & 0xF0000000;
				mask = 0xF;
			} else if (str_id_ref == 0xC0000000) {
				str_id_base = str_id & 0xE0000000;
				mask = 0x1F;
			} else {
				str_id_base = str_id & 0xFF000000;
				mask = 0;
			}
			if (str_id_base == str_id_ref) {
				*type = i;
				*ch = (str_id >> 24) & mask;
				ret = 1;
			}
			break;
		}
	}
	return ret;
}

SceMpegStreamId _sceMpegType2Mask(SceMpegStrType iStreamType)
{
	if (iStreamType > STRTYPE_MAX)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	return _strmap[iStreamType].str_mask;
}

SceUShort16 sceMpegSwap2(SceVoid *p)
{
	SceUChar8 *c = (SceUChar8 *)p;

	return (c[0] << 8) + c[1];
}

SceUInt32 sceMpegSwap3(SceVoid *p)
{
	SceUChar8 *c = (SceUChar8 *)p;

	return (c[0] << 16) + (c[1] << 8) + c[2];
}

SceUInt32 sceMpegSwap4(SceVoid *p)
{
	SceUChar8 *c = (SceUChar8 *)p;

	return (c[0] << 24) + (c[1] << 16) + (c[2] << 8) + c[3];
}
