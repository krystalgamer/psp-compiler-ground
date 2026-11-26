#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteProcPost);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NotePause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteRel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveCalcBufAlign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveCheckReq);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteCheckReq);
