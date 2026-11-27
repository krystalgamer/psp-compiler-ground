/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

CCmpr::CCmpr() {
}

CCmpr::~CCmpr() {
}

void CCmpr::SetInputData(const void *p, int n)
{
    input_size = n;
    input = p;
}

void *CCmpr::GetOutputData()
{
    return output;
}

int CCmpr::GetOutputSize()
{
    return output_size;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr14CreateItemListEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12InitNodePoolEv);

void CCmpr::FreeNodePool()
{
    if (pool) {
        free(pool);
        pool = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12AllocateNodeEv);

void CCmpr::FreeNode(hc_node_t *n)
{
    for (int i = 0; i < pool_size; i++) {
        if (pool[i].used && &pool[i].node == n) {
            __builtin_memset(&pool[i].node, 0, sizeof(hc_node_t));
            pool[i].used = false;
            if (i == pool_size - 1)
                pool_size = i;
            return;
        }
    }
}

hc_node_t *CCmpr::FindLeafByItem(unsigned long item)
{
    for (int i = 0; i < pool_size; i++) {
        if (pool[i].used && pool[i].node.type == 2 && pool[i].node.item == item)
            return &pool[i].node;
    }
    return 0;
}

hc_node_t *CCmpr::FindRootByLeaf(hc_node_t *leaf)
{
    for (hc_node_t *n = leaf->parent; n; n = n->parent) {
        if (n->type == 1)
            return n;
    }
    return 0;
}

hc_node_t *CCmpr::FindLeastImportantRoot(hc_node_t *exclude)
{
    int weight = 0;
    hc_node_t *root = 0;
    for (int i = 0; i < pool_size; i++) {
        if (pool[i].used && pool[i].node.type == 1 && exclude != &pool[i].node) {
            if (weight == 0 || pool[i].node.weight < weight) {
                weight = pool[i].node.weight;
                root = &pool[i].node;
            }
        }
    }
    return root;
}

int CCmpr::CountRoots()
{
    int n = 0;
    for (int i = 0; i < pool_size; i++) {
        if (pool[i].used && pool[i].node.type == 1)
            n++;
    }
    return n;
}

int CCmpr::CountLeaves()
{
    int n = 0;
    for (int i = 0; i < pool_size; i++) {
        if (pool[i].used && pool[i].node.type == 2)
            n++;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr12AnalyzeItemsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr17CreateHuffmanTreeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr10EncodeItemEP9hc_item_tP9hc_node_t);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr13HuffmanEncodeEv);

bool CCmpr::Compress()
{
    if (!CreateItemList())
        return false;
    if (!HuffmanEncode())
        return false;
    free(items);
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CCmpr", _ZN5CCmpr10UncompressEv);
