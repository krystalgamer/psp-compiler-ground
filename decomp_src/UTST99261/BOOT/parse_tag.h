/* HTML parser tag handling (parse*), recovered from the asm */
#ifndef PARSE_TAG_H
#define PARSE_TAG_H

typedef unsigned short DOMChar;

int parseTagCommon(void *ctx, const DOMChar **stop, int nstop, const DOMChar **tags, int ntags);

#endif
