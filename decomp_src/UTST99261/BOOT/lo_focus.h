#ifndef LO_FOCUS_H
#define LO_FOCUS_H
/* browser focus lists (lo_focus) */

typedef struct FOCUSAREA {
    s8 shape;                   /* 0x0 */
    int x;                      /* 0x4 */
    int y;
    int w;
    int h;
    void *link;                 /* 0x14 */
} FOCUSAREA;

typedef struct FOCUSLIST {
    struct FOCUSLIST *prev;     /* 0x0 */
    struct FOCUSLIST *next;     /* 0x4 */
    s8 type;                    /* 0x8: 0 box, 1 image map area */
    void *obj;                  /* 0xC: box */
    s16 tabindex;               /* 0x10 */
    s16 x12;
    FOCUSAREA *area;            /* 0x14 */
    void *x18;
} FOCUSLIST;

typedef struct FOCUSFRAME {
    u8 unk0[0x68];
    FOCUSLIST *head;            /* 0x68 */
    FOCUSLIST *tail;            /* 0x6C */
    FOCUSLIST *cur;             /* 0x70 */
} FOCUSFRAME;

/* frame box -> its frame data (box + 0x20) */
#define FFRAME(fr) (*(FOCUSFRAME **)((char *)(fr) + 0x20))

void *getNextTerminalFrame(void *frame, int dir);
int getRealPositionOfAnchor();
int setFocusBoxnode(void *box, void *arg);
int setFocusImageMap(void *frame, void *box, int shape, FOCUSAREA *area, void *arg);
void drawFocusObject(void *box);
void drawObjectWithArea(void *box, int x, int y, int w, int h);
void getViewPort();
void getViewClientSize();
FOCUSLIST *actFrameFocusDown(void *frame);
void scrollToCurrentFocusPosition(void *frame, FOCUSLIST *l);
void *getFocusTargetContentContext(void *g);
void *make_msg_LP22(void *a, void *b);
void putLLIST(void *list, void *msg);
void actSetFocusByFocusList(void *frame, FOCUSLIST *l, int draw);
void drawScroll(void *frame, int dx, int dy);
extern int REQUEST_LLIST;

#endif
