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

bool CCmpr::CreateItemList()
{
    int i = 0;
    item_count = 0;
    items = malloc(input_size * sizeof(unsigned long));
    if (!items)
        return false;
    const unsigned char *in = (const unsigned char *)input;
    while (i < input_size) {
        unsigned char c = in[i];
        int n = 0;
        for (int j = 0; i + j < input_size; ) {
            if (in[i + j] != c)
                break;
            j++;
            n++;
            if (j > 0xFFFE)
                break;
        }
        ((unsigned long *)items)[item_count++] = n | (c << 24);
        i += n;
    }
    return true;
}

bool CCmpr::InitNodePool()
{
    pool = (PoolEntry *)malloc(item_count * 2 * sizeof(PoolEntry));
    if (!pool)
        return false;
    for (int i = 0; i < item_count * 2; i++) {
        pool[i].used = false;
        __builtin_memset(&pool[i].node, 0, sizeof(hc_node_t));
    }
    pool_size = 0;
    return true;
}

void CCmpr::FreeNodePool()
{
    if (pool) {
        free(pool);
        pool = 0;
    }
}

hc_node_t *CCmpr::AllocateNode()
{
    int found = -1;
    int i;
    for (i = 0; i < pool_size; i++) {
        if (!pool[i].used) {
            found = i;
            break;
        }
    }
    if (found < 0)
        pool_size++;
    pool[i].used = true;
    return &pool[i].node;
}

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

bool CCmpr::AnalyzeItems()
{
    for (int i = 0; i < item_count; i++) {
        hc_node_t *leaf = FindLeafByItem(((unsigned long *)items)[i]);
        if (leaf == 0) {
            hc_node_t *root = AllocateNode();
            root->type = 1;
            root->weight = 1;
            leaf = AllocateNode();
            leaf->type = 2;
            root->child[1] = 0;
            leaf->item = ((unsigned long *)items)[i];
            leaf->parent = root;
            root->child[0] = leaf;
        } else {
            hc_node_t *root = FindRootByLeaf(leaf);
            root->weight++;
        }
    }
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr17CreateHuffmanTreeEv);

void CCmpr::EncodeItem(hc_item_t *item, hc_node_t *node)
{
    int n = 0;
    unsigned long code = 0;
    for (hc_node_t *p = node->parent; p; p = p->parent) {
        if (node == p->child[0])
            ;
        else if (node == p->child[1])
            code |= 1 << n;
        if (p->type == 1)
            break;
        node = p;
        n++;
    }
    n++;
    item->code = 0;
    for (int i = 0; i < n; i++) {
        if (code & (1 << i))
            item->code |= 1 << (n - 1 - i);
    }
    item->nbits = n;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr13HuffmanEncodeEv);

bool CCmpr::Compress()
{
    if (!CreateItemList())
        return false;
    if (!HuffmanEncode())
        return false;
    free(items);
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CCmpr", _ZN5CCmpr10UncompressEv);
