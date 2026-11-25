#include "common.h"
#include "m2c_macros.h"
M2C_UNK __checkUpdate();                            /* extern */


INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", __mulMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", __setMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", __checkUpdate);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumSetMatrixStack);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumSetCurMatrix);

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGumUpdateMatrix(void);

void sceGumUpdateMatrix(void) {
    __checkUpdate();
}

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumLoadContext);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumStoreContext);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_demo_duck);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_demo_duck);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_demo_harmonic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_demo_harmonic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_demo_luga);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_demo_luga);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_demo_mars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_demo_mars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_balloon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_balloon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_break);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_break);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_callmode);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_callmode);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_cube);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_cube);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_depthblur);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_depthblur);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_dragon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_dragon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_editbone);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_editbone);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_editgrid);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_editgrid);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_editspline);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_editspline);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_fileio);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_fileio);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_fountain);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_fountain);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_gears);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_gears);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_map);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_map);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_material);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_material);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_mipmap);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_mipmap);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_model);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_model);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_model2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_model2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_morph);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_morph);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_orizuru);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_orizuru);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_picture);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_picture);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_picture2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_picture2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_pot);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_pot);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_simple);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_simple);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_spots);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_spots);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_stainglass);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_stainglass);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_stars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_stars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_string);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_string);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_structure);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_structure);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_tamatama);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_tamatama);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_texcomp);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_texcomp);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_texmat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_texmat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_torus);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_torus);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_graphics_vtxformat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_graphics_vtxformat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_ezmpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_ezmpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_mpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_mpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_mpegstr_gu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_mpegstr_gu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_mpegstr_pcm);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_mpegstr_pcm);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_seamless_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_seamless_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_stream_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_stream_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_mpeg_timecode_jump);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_mpeg_timecode_jump);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_net_matching_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_net_matching_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_net_matching_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_net_matching_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_net_network_flow);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_net_network_flow);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_at3doubleplay);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_at3doubleplay);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_at3mix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_at3mix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_at3streaming);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_at3streaming);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_playsmf);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_playsmf);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_ryukyu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_ryukyu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_starmix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_starmix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_starsas);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_starsas);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_starsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_starsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_sound_stringsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_sound_stringsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_utility_font_basho);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_utility_font_basho);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut4_utility_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix4_utility_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_demo_duck);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_demo_duck);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_demo_harmonic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_demo_harmonic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_demo_luga);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_demo_luga);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_demo_mars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_demo_mars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_balloon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_balloon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_break);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_break);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_callmode);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_callmode);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_cube);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_cube);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_depthblur);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_depthblur);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_dragon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_dragon);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_editbone);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_editbone);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_editgrid);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_editgrid);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_editspline);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_editspline);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_fileio);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_fileio);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_fountain);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_fountain);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_gears);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_gears);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_map);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_map);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_material);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_material);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_mipmap);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_mipmap);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_model);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_model);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_model2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_model2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_morph);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_morph);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_orizuru);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_orizuru);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_picture);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_picture);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_picture2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_picture2);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_pot);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_pot);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_simple);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_simple);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_spots);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_spots);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_stainglass);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_stainglass);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_stars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_stars);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_string);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_string);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_structure);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_structure);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_tamatama);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_tamatama);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_texcomp);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_texcomp);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_texmat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_texmat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_torus);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_torus);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_graphics_vtxformat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_graphics_vtxformat);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_ezmpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_ezmpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_mpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_mpegstr);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_mpegstr_gu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_mpegstr_gu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_mpegstr_pcm);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_mpegstr_pcm);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_seamless_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_seamless_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_stream_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_stream_change);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_mpeg_timecode_jump);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_mpeg_timecode_jump);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_net_matching_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_net_matching_moonball);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_net_matching_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_net_matching_stick);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_net_network_flow);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_net_network_flow);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_at3doubleplay);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_at3doubleplay);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_at3mix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_at3mix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_at3streaming);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_at3streaming);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_playsmf);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_playsmf);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_ryukyu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_ryukyu);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_starmix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_starmix);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_starsas);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_starsas);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_starsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_starsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_sound_stringsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_sound_stringsound);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_utility_font_basho);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_utility_font_basho);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", clut8_utility_basic);

INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/libgum", pix8_utility_basic);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumLoadIdentity);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumRotateX);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumRotateY);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumRotateZ);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumRotateXYZ);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumRotateZYX);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumTranslate);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumScale);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumPerspective);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumOrtho);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumLookAt);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumMatrixMode);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumPushMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumPopMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumLoadMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumStoreMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumDrawArray);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumDrawArrayN);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumDrawBezier);

INCLUDE_ASM("tmp/asm/UTST99332/menu/nonmatchings/libgum", sceGumDrawSpline);
