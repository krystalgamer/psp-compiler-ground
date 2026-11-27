/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int js_setChildOfDocument(int a, int b, int c, int d, int type);
int js_setChildOfForm(int a, int b, int c, int d, int type);
int js_setChildOfWindow(int a, int b, int c, int type);
int JSObjSetEventHandler(int a, int b, int c);
typedef unsigned short UCSChar;
int mes_event_new();                                /* extern */
M2C_UNK mes_object_setup(void *, int, M2C_UNK *, int, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK JSPtrListAdd(void *);                       /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK OS_thread_mutex_lock(int);                  /* extern */
M2C_UNK OS_thread_mutex_unlock(int);                /* extern */
extern int jsapi_lock;
int SelectSetInternal();
int TextSetInternal();
int TextAreaSetInternal();
int HiddenSetInternal();
int PasswordSetInternal();
int FileUploadSetInternal();
int ButtonSetInternal();
int SubmitSetInternal();
int ResetSetInternal();
int CheckboxSetInternal();
int RadioSetInternal();
int ImageSetInternal();
int EventHandlerSetInternal();
int ASetInternal();
int FormSetInternal();

M2C_UNK js_setChildOfSelect();                      /* extern */


void *WindowSetInternal(int a, int b, void *hist);
int DocumentSetInternal(int a, int b, void *dom, int c);
void *HST_getDomObject(void *hist);
int JSObjGetCharsLength(const UCSChar *s)
{
    int n = 0;

    while (*s != 0) {
        s++;
        n++;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", JSObjSetEventHandler);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C880);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C888);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C890);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C89C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C8F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C900);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C90C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C918);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C924);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C930);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C938);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C940);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C94C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C958);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C964);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", D_0013C970);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", js_setChildOfWindow);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", js_setChildOfDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", js_setChildOfForm);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", js_setChildOfSelect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", WindowSetInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", DocumentSetInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", ASetInternal);

void *NavigatorSetInternal(void *arg0, int arg1)
{
    void *nav = mes_navigator_new(arg0);
    void *sp;

    mes_class_property_setup(arg0, arg1, "navigator", nav, 7);
    sp = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = (void *) ((char *)sp - 4);
    M2C_FIELD(sp, void **, -4) = nav;
    mes_object_setup(arg0, M2C_FIELD(arg0, int *, 0xC), "navigator", nav, 7, 0);
    M2C_FIELD(arg0, void **, 0x18) = (void *) ((char *)M2C_FIELD(arg0, void **, 0x18) + 4);
    return nav;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int EventSetInternal(void *arg0) {
    int temp_s1;
    void *temp_v1;

    temp_s1 = mes_event_new();
    temp_v1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (temp_v1 - 4);
    M2C_FIELD(temp_v1, int *, -4) = temp_s1;
    mes_object_setup(arg0, M2C_FIELD(arg0, int *, 0xC), "event", temp_s1, 7, 0);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (M2C_FIELD(arg0, void **, 0x18) + 4);
    return temp_s1;
}

int HistoryObjSetInternal(int a, int b)
{
    return js_setChildOfWindow(a, b, 0, 5);
}

int LocationSetInternal(int a, int b, int c)
{
    return js_setChildOfWindow(a, b, c, 6);
}

int ScreenSetInternal(int a, int b)
{
    return js_setChildOfWindow(a, b, 0, 7);
}

int EventHandlerSetInternal(int a, int b, int c, int d)
{
    JSObjSetEventHandler(a, b, d);
    return 0;
}

int AnchorSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 8);
}

int FormSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 9);
}

int ImageSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 10);
}

int LinkSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 11);
}

int ButtonSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 12);
}

int CheckboxSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 13);
}

int FileUploadSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 14);
}

int HiddenSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 15);
}

int PasswordSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 16);
}

int RadioSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 17);
}

int ResetSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 18);
}

int SelectSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 19);
}

int SubmitSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 20);
}

int TextSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 21);
}

int TextAreaSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 22);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void OptionSetInternal(void) {
    js_setChildOfSelect();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *JSObjectSetInternal(int (*arg0)(int, int, int, int), void *arg1, int arg2, int arg3) {
    int temp_v0_2;
    void *temp_v0;

    OS_thread_mutex_lock(jsapi_lock);
    temp_v0 = MEM_malloc(0, 0x10);
    if (temp_v0 != NULL) {
        temp_v0_2 = arg0(M2C_FIELD(arg1, int *, 0), M2C_FIELD(arg1, int *, 4), arg2, arg3);
        M2C_FIELD(temp_v0, int *, 0) = (int) M2C_FIELD(arg1, int *, 0);
        M2C_FIELD(temp_v0, int *, 4) = temp_v0_2;
        JSPtrListAdd(temp_v0);
    }
    OS_thread_mutex_unlock(jsapi_lock);
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SelectSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&SelectSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void TextSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&TextSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void TextAreaSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&TextAreaSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void HiddenSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&HiddenSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void PasswordSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&PasswordSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void FileUploadSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&FileUploadSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ButtonSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ButtonSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SubmitSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&SubmitSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ResetSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ResetSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CheckboxSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&CheckboxSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void RadioSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&RadioSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ImageSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ImageSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void EventHandlerSet(int arg0, int arg1) {
    JSObjectSetInternal(&EventHandlerSetInternal, arg0, 0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ASet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ASetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void FormSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&FormSetInternal, arg0, arg1, arg2);
}

void *OptionSet(int a, int b, int c)
{
    return JSObjectSetInternal(OptionSetInternal, a, b, c);
}

void *DocumentSet(int *win, void *hist, int c) {
    int *d;
    int *w;
    int a, b;

    OS_thread_mutex_lock(jsapi_lock);
    if (win != NULL)
        w = WindowSetInternal(win[0], win[1], hist);
    else
        w = WindowSetInternal(0, 0, hist);
    d = MEM_malloc(0, 0x10);
    d[0] = w[0];
    d[1] = DocumentSetInternal(w[0], w[1], HST_getDomObject(hist), c);
    JSPtrListAdd(w);
    JSPtrListAdd(d);
    OS_thread_mutex_unlock(jsapi_lock);
    return d;
}

UCSChar *UCS_strcpy(UCSChar *d, const UCSChar *s)
{
    UCSChar *r = d;

    while ((*d++ = *s++) != 0)
        ;
    return r;
}

UCSChar *UCS_strncpy(UCSChar *d, const UCSChar *s, int n)
{
    UCSChar *r = d;

    while (--n != -1 && (*d++ = *s++) != 0)
        ;
    return r;
}

short UCS_strcmp(const UCSChar *a, const UCSChar *b)
{
    short r;

    do {
        r = *a - *b++;
        if (r != 0)
            break;
    } while (*a++ != 0);
    return r;
}

short UCS_strncmp(const UCSChar *a, const UCSChar *b, int n)
{
    short r = 0;

    while (n != 0) {
        r = *a - *b++;
        if (r != 0)
            break;
        if (*a++ == 0)
            break;
        n--;
    }
    return r;
}

int UCS_strcasecmp(const UCSChar *a, const UCSChar *b)
{
    UCSChar c1, c2;

    do {
        c1 = *a++;
        c2 = *b++;
        if (c1 == 0 || c2 == 0)
            break;
        if (c1 == c2)
            continue;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 += 'a' - 'A';
        if (c2 >= 'A' && c2 <= 'Z')
            c2 += 'a' - 'A';
    } while (c1 == c2);
    return c1 - c2;
}

int UCS_strncasecmp(const UCSChar *a, const UCSChar *b, int n)
{
    UCSChar c1, c2;

    c2 = 0;
    c1 = 0;

    while (n != 0) {
        c1 = *a++;
        c2 = *b++;
        if (c1 == 0 || c2 == 0)
            break;
        if (c1 != c2) {
            if (c1 >= 'A' && c1 <= 'Z')
                c1 += 'a' - 'A';
            if (c2 >= 'A' && c2 <= 'Z')
                c2 += 'a' - 'A';
            if (c1 != c2)
                break;
        }
        n--;
    }
    return c1 - c2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int UCS_strdup(int arg0) {
    int temp_v0;
    int var_v1;

    temp_v0 = MEM_malloc(0, (UCS_strlen() * 2) + 2);
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = UCS_strcpy(temp_v0, arg0);
    }
    return var_v1;
}

UCSChar *UCS_strndup(const UCSChar *s, int n)
{
    UCSChar *p = MEM_malloc(0, n * 2 + 2);

    if (p == NULL)
        return NULL;
    UCS_strncpy(p, s, n);
    p[n] = 0;
    return p;
}

UCSChar *UCS_strstr(UCSChar *hay, const UCSChar *needle)
{
    int nl = UCS_strlen(needle);
    int hl;

    if (nl == 0)
        return hay;
    hl = UCS_strlen(hay);
    while (hl >= nl) {
        hl--;
        if (UCS_strncmp(hay, needle, nl) == 0)
            return hay;
        hay++;
    }
    return NULL;
}

int UCS_strlen(const UCSChar *s)
{
    const UCSChar *p = s;

    while (*p != 0)
        p++;
    return p - s;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", gDomiAttrVt);
