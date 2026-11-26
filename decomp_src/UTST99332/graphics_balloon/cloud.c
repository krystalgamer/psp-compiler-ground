#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", set_texture);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", set_vram_texture);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", init_cloud);

void init_cloud(int i);
void set_vram_texture(void);

void init_clouds(void)
{
	int i;

	for (i = 0; i < 10; i++) {
		init_cloud(i);
	}

	set_vram_texture();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", check_clouds);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", sort_cloud);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", draw_clouds);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", proc_clouds);
