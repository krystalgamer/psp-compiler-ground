/* cflags: -O1 */
#include "common.h"
#include "css_types.h"
#include "m2c_macros.h"
extern void *CSSPropertyNames[];
extern u16 CSSSTR_important[];
void *MEM_calloc();
void *CSSStyleDeclaration_getPropertyDeclaration(); /* extern */
int CSSValue_getCssText(int);                       /* extern */
M2C_UNK CSS_freePoolBuf(void *);                    /* extern */
int CSS_getPoolBuf(void *);                         /* extern */
M2C_UNK CSS_putSPoolBuf(void *, M2C_UNK *);         /* extern */
M2C_UNK CSS_putsPoolBuf(void *, int);               /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK newCSSRule(M2C_UNK, M2C_UNK, int, int);     /* extern */

M2C_UNK addCSSRule();                               /* extern */
M2C_UNK addCSSNode();                               /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSStyleDeclaration_getPropertyDeclaration);

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSStyleDeclaration_getPropertyValue(void) {
    int var_v1;
    void *temp_v0;

    temp_v0 = CSSStyleDeclaration_getPropertyDeclaration();
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = CSSValue_getCssText(M2C_FIELD(temp_v0, int *, 0xC));
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSStyleDeclaration_getPropertyCSSValue(void) {
    int var_v1;
    void *temp_v0;

    temp_v0 = CSSStyleDeclaration_getPropertyDeclaration();
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, int *, 0xC);
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSStyleDeclaration_removeProperty(void) {
    int var_s1;
    void *temp_v0;

    var_s1 = 0;
    temp_v0 = CSSStyleDeclaration_getPropertyDeclaration();
    if (temp_v0 != NULL) {
        var_s1 = CSSValue_getCssText(M2C_FIELD(temp_v0, int *, 0xC));
        freeCSSStyleDeclaration(temp_v0);
    }
    return var_s1;
}

u16 *CSSStyleDeclaration_getPropertyPriority(void *a0, void *a1) {
    CSSVALUE *d = CSSStyleDeclaration_getPropertyDeclaration(a0, a1);
    if (d == NULL) {
        return NULL;
    }
    return d->unk1E == 1 ? CSSSTR_important : NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleDeclaration_getLength(void *arg0) {
    void *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = M2C_FIELD(arg0, void **, 4);
        if (temp_v0 != NULL) {
            return M2C_FIELD(temp_v0, int *, 8);
        }
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSStyleDeclaration_item);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleDeclaration_getParentRule(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 4);
    }
    return var_v0;
}

void *CSSStyleDeclaration_getName(CSSVALUE *d) {
    if (d == NULL) {
        return NULL;
    }
    return CSSPropertyNames[d->type * 2];
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleDeclaration_getValue(void *arg0) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, int *, 8) != 0)) {
        return M2C_FIELD(arg0, int *, 0xC);
    }
    return 0;
}

u16 *CSSStyleDeclaration_getPriority(CSSVALUE *d) {
    if (d != NULL) {
        if (d->unk1E == 1) {
            return CSSSTR_important;
        }
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_Percent);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_deg);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_rad);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_grad);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_s);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_ms);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_Hz);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_kHz);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_azimuth);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_background);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_background_attachment);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_background_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_background_image);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_background_position);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_background_repeat);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_bottom);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_bottom_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_bottom_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_bottom_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_collapse);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_left);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_left_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_left_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_left_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_right);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_right_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_right_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_right_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_spacing);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_top);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_top_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_top_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_top_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_border_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_bottom);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_caption_side);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_clear);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_clip);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_content);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_counter_increment);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_counter_reset);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cue);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cue_after);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cue_before);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cursor);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_direction);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_display);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_elevation);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_empty_cells);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_float);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_family);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_size);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_size_adjust);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_stretch);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_variant);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_font_weight);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_height);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_left);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_letter_spacing);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_line_hight);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_list_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_list_style_image);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_list_style_position);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_list_style_type);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_margin);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_margin_bottom);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_margin_left);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_margin_right);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_margin_top);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_marker_offset);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_marks);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_max_height);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_max_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_min_height);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_min_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_orphans);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_outline);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_outline_color);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_outline_style);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_outline_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_overflow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_padding);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_padding_bottom);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_padding_left);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_padding_right);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_padding_top);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_page_break_after);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_page_break_before);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_page_break_inside);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pause);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pause_after);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pause_before);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pitch);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pitch_range);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_play_during);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_position);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_quotes);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_richness);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_right);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_size);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_speak);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_speak_header);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_speak_numeral);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_speak_punctuation);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_speech_rate);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_stress);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_layout);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_align);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_decoration);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_indent);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_shadow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_transform);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_top);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_unicode_bidi);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_vertical_align);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_visibility);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_voice_family);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_volume);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_white_space);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_widows);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_word_spacing);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_z_index);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_100);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_200);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_300);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_400);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_500);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_600);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_700);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_800);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_900);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_above);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_absolute);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_always);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_armenian);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_attr);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_auto);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_avoid);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_baseline);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_behind);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_below);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_bidi_override);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_blink);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_block);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_bold);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_bolder);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_both);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_capitalize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_caption);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_center);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_center_left);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_center_right);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_child);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_circle);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cjk_ideographic);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_close_quote);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_code);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_collapse);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_compact);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_condensed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_continuous);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_counter);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_counters);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_crop);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cross);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_crosshair);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_cursive);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_dashed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_decimal);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_decimal_leading_zero);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_default);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_digits);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_disc);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_dotted);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_double);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_e_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_embed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_expanded);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_extra_condensed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_extra_expanded);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_fantasy);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_far_left);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_far_right);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_fast);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_faster);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_female);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_fixed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_georgian);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_groove);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_hebrew);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_help);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_hidden);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_hide);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_high);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_higher);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_hiragana);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_hiragana_iroha);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_icon);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_inherit);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_inline);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_inline_table);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_inset);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_inside);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_invert);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_italic);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_justify);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_katakana);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_katakana_iroha);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_landscape);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_large);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_larger);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_left_side);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_leftwards);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_level);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lighter);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_line_through);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_list_item);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_loud);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_low);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lower);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lower_alpha);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lower_greek);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lower_latin);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lower_roman);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_lowercase);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_ltr);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_male);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_marker);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_medium);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_menu);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_message_box);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_middle);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_mix);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_monospace);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_move);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_n_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_narrower);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_ne_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_no_close_quote);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_no_open_quote);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_no_repeat);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_none);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_normal);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_nowrap);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_nw_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_oblique);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_once);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_open_quote);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_outset);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_outside);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_overline);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pointer);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_portrait);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_pre);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_rect);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_relative);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_repeat);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_repeat_x);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_repeat_y);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_rgb);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_ridge);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_right_side);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_rightwards);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_rtl);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_run_in);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_s_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_sans_serif);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_scroll);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_se_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_semi_condensed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_semi_expanded);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_separate);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_serif);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_show);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_silent);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_slow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_slower);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_small);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_small_caps);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_small_caption);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_smaller);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_soft);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_solid);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_spell_out);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_square);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_static);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_status_bar);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_sub);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_super);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_sw_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_caption);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_cell);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_column);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_column_group);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_footer_group);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_header_group);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_row);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_table_row_group);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_bottom);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_text_top);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_thick);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_thin);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_transparent);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_ultra_condensed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_ultra_expanded);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_underline);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_upper_alpha);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_upper_latin);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_upper_roman);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_uppercase);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_url);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_visible);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_w_resize);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_wait);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_wider);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_fast);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_high);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_large);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_loud);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_low);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_slow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_small);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_x_soft);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_xx_large);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSSTR_xx_small);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013ED48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013ED4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013ED50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013ED54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013ED58);

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSStyleDeclaration_toString(short *arg0) {
    int temp_s0;
    int temp_v0_2;
    int temp_v0_3;
    int var_v0;
    void *temp_v0;

    if ((arg0 == NULL) || (*arg0 != 0xA)) {
        return 0;
    }
    temp_v0 = CSS_newPoolBuf();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        CSS_putsPoolBuf(temp_v0, CSSStyleDeclaration_getName(arg0));
        CSS_putSPoolBuf(temp_v0, " : ");
        temp_v0_2 = CSSValue_getCssText(CSSStyleDeclaration_getValue(arg0));
        CSS_putsPoolBuf(temp_v0, temp_v0_2);
        MEM_free(0, temp_v0_2);
        temp_v0_3 = CSSStyleDeclaration_getPriority(arg0);
        if (temp_v0_3 != 0) {
            CSS_putSPoolBuf(temp_v0, " !");
            CSS_putsPoolBuf(temp_v0, temp_v0_3);
        }
        temp_s0 = CSS_getPoolBuf(temp_v0);
        CSS_freePoolBuf(temp_v0);
        var_v0 = temp_s0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", newCSSStyleRule);

#ifndef NULL
#define NULL ((void *)0)
#endif
void freeCSSStyleRule(void *arg0) {
    void *temp_s0;
    void *var_a0;

    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 7)) {
        var_a0 = M2C_FIELD(arg0, void **, 0xC);
        if (var_a0 != NULL) {
            do {
                temp_s0 = M2C_FIELD(var_a0, void **, 0x18);
                if (M2C_FIELD(var_a0, short *, 0) == 8) {
                    freeCSSSelectorList(var_a0);
                }
                var_a0 = temp_s0;
            } while (temp_s0 != NULL);
        }
        freeCSSNode((int) arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSStyleRule(void) {
    addCSSRule();
}

int CSSStyleRule_getType(s16 *r) {
    if (r != NULL) {
        if (*r == 7) {
            return *r;
        }
    }
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSStyleRule_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSStyleRule_setCssText);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleRule_getCssSelectorLists(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 7)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleRule_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 7)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSStyleRule_getParentRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 7)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSStyleRule_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 7)) {
        M2C_FIELD(arg0, int *, 0x1C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSStyleRule_setParentRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 7)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void newCSSUnknownRule(int arg0, int arg1) {
    newCSSRule(1, 0x28, arg0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void freeCSSUnknownRule(void *arg0) {
    int temp_a1;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, short *, 0) == 1) {
            temp_a1 = M2C_FIELD(arg0, int *, 0x24);
            if (temp_a1 != 0) {
                MEM_free(0, temp_a1);
            }
            freeCSSNode((int) arg0);
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", addCSSUnknownRule);

int CSSUnknownRule_getType(s16 *r) {
    if (r != NULL) {
        if (*r == 1) {
            return *r;
        }
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSUnknownRule_getCssText(void *arg0) {
    int temp_s0;
    int var_v0;
    void *temp_v0;

    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 1)) {
        return 0;
    }
    temp_v0 = CSS_newPoolBuf();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        CSS_putsPoolBuf(temp_v0, M2C_FIELD(arg0, int *, 0x24));
        CSS_putSPoolBuf(temp_v0, "\n");
        temp_s0 = CSS_getPoolBuf(temp_v0);
        CSS_freePoolBuf(temp_v0);
        var_v0 = temp_s0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSUnknownRule_setCssText);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSUnknownRule_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 1)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSUnknownRule_getParentRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 1)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSUnknownRule_setText(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 1)) {
        M2C_FIELD(arg0, int *, 0x24) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSUnknownRule_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 1)) {
        M2C_FIELD(arg0, int *, 0x1C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSUnknownRule_setParentRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 1)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void newCSSValue(void) {
    newCSSNode(0xB, 0x38);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", freeCSSValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", duplicateCSSValue);

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSValue(void) {
    addCSSNode();
}

s16 *newCSSPrimitiveValue(int type) {
    s16 *v = MEM_calloc(0, 0x18);
    if (v != NULL) {
        *v = type;
    }
    return v;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", freeCSSPrimitiveValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", duplicateCSSPrimitiveValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSValue_getCssText);

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSValue_getValueType(void *arg0) {
    return M2C_FIELD(arg0, short *, 0x1C);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSPrimitiveValue_getCssText);

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSPrimitiveValue_getPrimitiveType(short *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSPrimitiveValue_setFloatValue(void *arg0, short arg1, int arg2, int arg3) {
    if (arg1 < 0x13) {
        M2C_FIELD(arg0, short *, 0) = arg1;
        M2C_FIELD(arg0, int *, 8) = arg2;
        M2C_FIELD(arg0, int *, 0xC) = arg3;
    }
}

double CSSPrimitiveValue_getFloatValue(s16 *v, s16 type) {
    return *v == type ? *(double *)(v + 4) : 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSPrimitiveValue_setStringValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSPrimitiveValue_getStringValue);

void *CSSPrimitiveValue_getCounterValue(s16 *v) {
    return *v == 0x17 ? (void *)(v + 4) : NULL;
}

void *CSSPrimitiveValue_getRectValue(s16 *v) {
    return *v == 0x18 ? (void *)(v + 4) : NULL;
}

void *CSSPrimitiveValue_getRGBColorValue(s16 *v) {
    return *v == 0x19 ? (void *)(v + 4) : NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSValueList_getLength(void *arg0) {
    int var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = M2C_FIELD(arg0, int *, 8);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", CSSValueList_item);

#ifndef NULL
#define NULL ((void *)0)
#endif
int Counter_getIdentifier(int *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int Counter_getListStyle(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int Counter_getSeparator(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int Rect_getTop(int *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int Rect_getRight(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int Rect_getBottom(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int Rect_getLeft(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int RGBColor_getRed(int *arg0) {
    return *arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int RGBColor_getGreen(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int RGBColor_getBlue(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EDF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EDFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EE98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EEA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EEC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EECC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EED8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EEE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EEF0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", collectFormData);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EEF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EEFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EF00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", D_0013EF04);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_StyleDeclaration", resetFormData);
