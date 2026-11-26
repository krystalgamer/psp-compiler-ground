/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

CCmpr::CCmpr() {
}

CCmpr::~CCmpr() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12SetInputDataEPKvi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr13GetOutputDataEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr13GetOutputSizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr14CreateItemListEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12InitNodePoolEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12FreeNodePoolEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12AllocateNodeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr8FreeNodeEP9hc_node_t);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr14FindLeafByItemEm);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr14FindRootByLeafEP9hc_node_t);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr22FindLeastImportantRootEP9hc_node_t);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr10CountRootsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr11CountLeavesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12AnalyzeItemsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr17CreateHuffmanTreeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr10EncodeItemEP9hc_item_tP9hc_node_t);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr13HuffmanEncodeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr8CompressEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr10UncompressEv);
