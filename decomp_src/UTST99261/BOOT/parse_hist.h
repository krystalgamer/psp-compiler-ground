/* history (HST_*) types, recovered from the asm */
#ifndef PARSE_HIST_H
#define PARSE_HIST_H

typedef struct HstStr {
    char *p;
    int len;
} HstStr;

void freeFragmentIDs(void *f);
void *searchHistoryNodeInner(int type, void *a, void *b);

#endif
