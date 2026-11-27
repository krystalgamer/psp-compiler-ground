/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct ListNode { struct ListNode *next; } ListNode;
typedef struct { unsigned char type; char pad[3]; ListNode *head; ListNode *tail; } List;

void *_memAlloc();
List *listInit(int type, List *l, int alloc, int Num, int Size)
{
	int i;
	if (l == NULL)
		l = _memAlloc(0xC, "src/lib/list.c", 0x16);
	l->type = type;
	if (alloc) {
		if (!Num)
			consPrintf("cassert : %s %d : %s : %s\n", "src/lib/list.c", 0x1B, "listInit", "Num");
		if (!Size)
			consPrintf("cassert : %s %d : %s : %s\n", "src/lib/list.c", 0x1C, "listInit", "Size");
		if (l->type == 0) {
			for (i = Num; i; i--)
				;
		}
	}
	return l;
}

int listTerm(void) {
    return 1;
}

int listAddHead(List *l, ListNode *n)
{
	ListNode *h;
	switch (l->type) {
	case 0:
		h = l->head;
		l->head = n;
		n->next = h;
		break;
	case 1:
		h = l->head;
		l->head = n;
		h->next = n;
		n->next = NULL;
		break;
	case 2:
		break;
	}
	return 0;
}

int listAddTail(List *l, ListNode *n)
{
	ListNode *t;
	switch (l->type) {
	case 0:
		t = l->tail;
		l->tail = n;
		t->next = n;
		n->next = NULL;
		break;
	case 1:
		t = l->tail;
		l->tail = n;
		n->next = t;
		break;
	case 2:
		break;
	}
	return 0;
}
