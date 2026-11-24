#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/decode", decode_setStreamData);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/decode", decode_pcmDemux);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/decode", decode_videoDecode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/decode", decode_videoDecodeEnd);
