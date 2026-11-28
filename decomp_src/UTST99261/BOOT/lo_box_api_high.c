/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nflayout.h"



#ifndef NULL
#define NULL ((void *)0)
#endif
#define CBPAD(s) ((s)->unk26 + (s)->unk36 + (s)->unk2E + (s)->unk2A + (s)->unk32 + (s)->unk22)
extern int D_0025B15C;
extern int D_0025B160;
extern int D_0025B164;
char *strchr(const char *s, int c);
int calcBoxMaxWidth(int ctx, BOX *root);
BOX *getBoxByContent(BOX *box, int content) {
    while (box != NULL && box->content != content) {
        box = box->parent;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *getRootBox(void) {
    HISTNODE *h;
    BOX *box;

    h = HST_getHeadHistoryNode();
    box = NULL;
    if (h != NULL) {
        box = h->body;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getBodyBox(BOX *box) {
    return getBoxByContent(box, 1);
}

BOX *getListBox(BOX *box) {
    while (box != NULL && box->content != 8) {
        if (box->content == 17) {
            return NULL;
        }
        box = box->parent;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getFramesetBox(BOX *box) {
    return getBoxByContent(box, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getTableBox(BOX *box) {
    return getBoxByContent(box, 4);
}

BOX *getTrBox(BOX *box) {
    while (box != NULL && box->content != 5) {
        if (box->content == 4) {
            box = NULL;
            break;
        }
        box = box->parent;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getTdBox(BOX *box) {
    return getBoxByContent(box->parent, 6);
}

BOX *getParentBlockBox(BOX *box) {
    BOX *b;

    b = box->parent;
    while (b != NULL && b->display != 0 && b->display != 3) {
        b = b->parent;
    }
    return b;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getBoxByHTML(BOX *box, int html) {
    while (box != NULL && box->html != html) {
        box = box->parent;
    }
    return box;
}

BOX *getBoxByHTML_intd(BOX *box, BOX *stop, int html) {
    while (box != NULL && box->html != html) {
        if (box == stop) {
            box = NULL;
            break;
        }
        box = box->parent;
    }
    return box;
}

void getBodyAbsolutePos(BOX *box, int *px, int *py) {
    int x;
    int y;
    BOX *b;

    x = box->geom->x;
    y = box->geom->y;
    for (b = box->parent; b != NULL; b = b->parent) {
        if (b->content == 1) {
            x += b->geom->x;
            y += b->geom->y;
        }
    }
    *px = x;
    *py = y;
}

int checkBoxValidity(BOX *box) {
    for (; box != NULL; box = box->parent) {
        if (box->content == 1 && box->geom->unk40 == 4) {
            return 0;
        }
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getContainingBlockWidth(BOX *box) {
    BOXSTYLE *s;

    s = box->style;
    return box->width - s->unk26 - s->unk36 - s->unk2E - s->unk2A - s->unk32 - s->unk22;
}

void *getPageRegion(BOX *box) {
    for (; box != NULL; box = box->parent) {
        if (box->region != NULL) {
            return box->region;
        }
    }
    return NULL;
}

int calcBoxMinWidth(int ctx, BOX *root)
{
    int w;
    int mx;
    int ofs;
    int cbw;
    int m;
    int p;
    BOX *n;
    BOX *body;
    BOXSTYLE *st;
    char *s;

    mx = 0;
    ofs = 0;
    body = getBodyBox(root);
    cbw = getContainingBlockWidth(getParentBlockBox(root));
    n = root->child;
    while (n != NULL && n != root) {
        w = 0;
        if (n->content == 9) {
            resizeTextSize(n);
            if (((int *)body->geom)[0x64 / 4] == 0) {
                if (*(char **)n->geom == NULL)
                    w = ofs;
                else {
                    s = strchr(*(char **)n->geom, ' ');
                    if (s != NULL) {
                        GUI_Graphics_getStringSize(n->style->unk64, *(char **)n->geom, s - *(char **)n->geom + 1, &w, &D_0025B164);
                        w = ofs + w;
                    } else
                        w = ofs + n->width;
                }
            } else if (n->style->unk64 == D_0025B15C)
                w = ofs + (D_0025B160 < n->width ? D_0025B160 : n->width);
            else {
                GUI_Graphics_getStringSize(n->style->unk64, "AA", 2, &D_0025B160, &D_0025B164);
                w = D_0025B160 < n->width ? D_0025B160 : n->width;
                D_0025B15C = n->style->unk64;
            }
        } else if (n->content == 4) {
            box_calcTableWidth(ctx, n, &w, 0, cbw);
            st = n->style;
            m = st->unk26 + st->unk22;
            if ((st->flags & 3) == 1 && w - m < st->width)
                w = m + st->width;
            w = ofs + w;
            if (mx < w)
                mx = w;
            goto next;
        } else if (n->content == 11) {
            if ((n->style->flags & 3) == 1)
                w = ofs + n->style->width;
        } else if (n->content != 0 && (n->html != 0x66 || getListBox(n) == NULL) && (unsigned short)(n->display - 1) < 2) {
            if (n->content == 10) {
                resizeImageSize(n);
                w = ofs + n->width;
            } else if (n->content == 0x10) {
                resizeButtonSize(n);
                w = ofs + n->width;
            } else if (n->content == 0xD) {
                resizeTextFieldSize(n);
                w = ofs + n->width;
            } else {
                if (n->content == 0x12)
                    resizeSelectSize(n);
                w = ofs + n->width;
            }
        } else if (n->display == 0) {
            st = n->style;
            p = CBPAD(st);
            ofs += p;
            if ((st->flags & 3) == 1)
                w = p + st->width;
        } else if (n->display == 1 && (s8)n->style->unk74 != 0) {
            w = calcBoxMaxWidth(ctx, n) + ofs;
            if (mx < w)
                mx = w;
            goto next;
        }
        mx = mx < w ? w : mx;
        if (n->child != NULL) {
            n = n->child;
            continue;
        }
    next:
        if (n->next != NULL) {
            n = n->next;
            continue;
        }
        for (n = n->parent; n != NULL && n != root; n = n->parent) {
            if (n->display == 0 && (n->content == 0 || n->content == 8))
                ofs -= CBPAD(n->style);
            if (n->next != NULL) {
                n = n->next;
                break;
            }
        }
    }
    mx += CBPAD(root->style);
    return mx;
}

int calcBoxMaxWidth(int ctx, BOX *root)
{
    int tw;
    int line;
    int mx;
    int ofs;
    int cbw;
    int m;
    int p;
    BOX *n;
    BOXSTYLE *st;

    line = 0;
    mx = 0;
    ofs = 0;
    cbw = getContainingBlockWidth(getParentBlockBox(root));
    n = root->child;
    while (n != NULL && n != root) {
        if (n->content == 4) {
            mx = mx < ofs + line ? ofs + line : mx;
            box_calcTableWidth(ctx, n, &tw, &line, cbw);
            st = n->style;
            m = st->unk26 + st->unk22;
            if ((st->flags & 3) == 1) {
                if (st->width >= tw - m)
                    line = m + st->width;
                else
                    line = tw;
            }
            mx = mx < ofs + line ? ofs + line : mx;
            line = 0;
            goto next;
        } else if (n->content == 11) {
            mx = mx < ofs + line ? ofs + line : mx;
            line = 0;
            if ((n->style->flags & 3) == 1 && mx < ofs + n->style->width)
                mx = ofs + n->style->width;
        } else if (n->display == 0) {
            mx = mx < ofs + line ? ofs + line : mx;
            line = 0;
            st = n->style;
            p = CBPAD(st);
            ofs += p;
            if ((st->flags & 3) == 1 && mx < p + st->width) {
                mx = n->width;
                goto next;
            }
        } else if (n->content == 10 && (n->html != 0x66 || getListBox(n) == NULL)) {
            resizeImageSize(n);
            line += n->width;
        } else if (n->content != 0) {
            if (n->content == 9) {
                resizeTextSize(n);
                line += n->width;
            } else if (n->content == 0x10) {
                resizeButtonSize(n);
                line += n->width;
            } else if (n->content == 0xD) {
                resizeTextFieldSize(n);
                line += n->width;
            } else {
                if (n->content == 0x12)
                    resizeSelectSize(n);
                line += n->width;
            }
        } else if (n->html == 0x10) {
            mx = mx < ofs + line ? ofs + line : mx;
            line = 0;
        }
        if (n->child != NULL) {
            n = n->child;
            continue;
        }
    next:
        if (n->next != NULL) {
            n = n->next;
            continue;
        }
        for (n = n->parent; n != NULL && n != root; n = n->parent) {
            if (n->content != 11 && n->content != 4 && n->display == 0) {
                mx = mx < ofs + line ? ofs + line : mx;
                line = 0;
                ofs -= CBPAD(n->style);
            }
            if (n->next != NULL) {
                n = n->next;
                break;
            }
        }
    }
    mx = mx < line ? line : mx;
    mx += CBPAD(root->style);
    return mx;
}

BOX *getFixedHeightBox(BOX *box) {
    BOX *b;

    for (b = box->parent; b != NULL; b = b->parent) {
        if (b->content == 4 || b->display == 3) {
            return NULL;
        }
        if (((b->style->flags & 0xC) >> 2) == 1 || b->content == 1) {
            return b;
        }
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_height);
