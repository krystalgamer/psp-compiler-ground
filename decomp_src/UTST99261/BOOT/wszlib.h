#ifndef WSZLIB_H
#define WSZLIB_H
/* wszlib: the browser's own inflate (not zlib's code) */

typedef struct ZCHUNK {
    struct ZCHUNK *next;
    u8 *data;
    int size;
} ZCHUNK;

typedef struct { /* size 0x2C */
    ZCHUNK *head;       /* list of added data; the struct starts like a ZCHUNK */
    u8 *data;
    int size;
    unsigned int total; /* 0xC */
    ZCHUNK *cur;        /* 0x10 */
    int pos;            /* 0x14 */
    unsigned int bit;   /* 0x18 */
    u8 *ptr;            /* 0x1C */
    u8 *out;            /* 0x20 */
    unsigned int outLen;    /* 0x24 */
    unsigned int outSize;   /* 0x28 */
} ZBUF;

void *ESP_malloc(unsigned int size);
void ESP_free(void *p);
void *memcpy(void *d, const void *s, unsigned int n);
void *memset(void *p, int c, unsigned int n);

typedef struct { /* Huffman code entry, 0xC */
    unsigned int code;
    int len;
    int sym;
} HCODE;

void quick_sort(HCODE *t, int lo, int hi);
ZBUF *newZBuf(u8 *data, int size);
int addData(ZBUF *zb, u8 *data, int size);
void freeZBuf(ZBUF *zb);

/* form element of the layout engine (only what these wrappers use) */
typedef struct {
    int kind;           /* 1: textarea */
} FORMINFO;

typedef struct {
    u8 unk0[0x20];
    FORMINFO *info;     /* 0x20 */
    u8 unk24[0x8];
    void *widget;       /* 0x2C */
} FORMELEM;

void GUI_TextArea_setText(void *w, char *s);
void GUI_TextField_setText(void *w, char *s);
char *rnd_gdrawGetTextboxString(void *w);
char *rnd_gdrawGetTextlineString(void *w);
int rnd_gdrawReplaceTextboxString(void *w, char *s, int start, int end);
int GUI_TextField_insert(void *w, char *s, int start, int end);
int GUI_TextArea_getSelection(void *w, int *start, int *end);
int GUI_TextField_getSelection(void *w, int *start, int *end);
char *rnd_gdrawGetTextboxSelectionString(void *w);
char *rnd_gdrawGetTextlineSelectionString(void *w);
void rnd_gdrawSelectTextbox(void *w, int on);
void GUI_TextField_selectAll(void *w);
void GUI_Checkbox_setState(void *w, int state);
int GUI_Checkbox_getState(void *w);
void GUI_RadioButton_setState(void *w, int state);
int GUI_RadioButton_getState(void *w);
void GUI_Choice_select(void *w, int index);
int GUI_Choice_getSelectedItem(void *w);
void rnd_gdrawSetListState(void *w, int index, int state, int redraw);
int GUI_List_isIndexSelected(void *w, int index);

typedef struct {
    int bits;           /* extra bits */
    int base;
} ZEXTRA;

extern const ZEXTRA length_tab[29];     /* codes 257..285 */
extern const ZEXTRA distance_tab[30];

int readBits(ZBUF *zb, int n, int msbFirst, unsigned int *out);
int writeBytes(ZBUF *zb, u8 *src, int len);
void skipBits(ZBUF *zb, int n);
void skipCurByte(ZBUF *zb);
int do_nocomp(ZBUF *zb);
int do_fixed(ZBUF *zb);
int do_dynamic(ZBUF *zb);

#endif
