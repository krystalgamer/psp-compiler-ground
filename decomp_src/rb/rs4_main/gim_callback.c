#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureSetMemoryManager);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureSetMemoryManager2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureSetMemoryManager3);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureOpenMemoryCluster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureOpenMemoryCluster2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureOpenMemoryCluster3);

int sceGimPictureCloseMemoryCluster()
{
		return close_cluster( 0 ) ;
	}

int sceGimPictureCloseMemoryCluster2()
{
		return close_cluster( 1 ) ;
	}

int sceGimPictureCloseMemoryCluster3()
{
		return close_cluster( 2 ) ;
	}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureAllocMemory);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureAllocMemory2);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", sceGimPictureAllocMemory3);

void sceGimPictureFreeMemory( void *addr )
{
		{if ( addr != 0 ) {free_from_cluster( 0, addr ) ;}}
	}

void sceGimPictureFreeMemory2( void *addr )
{
		{if ( addr != 0 ) {free_from_cluster( 1, addr ) ;}}
	}

void sceGimPictureFreeMemory3( void *addr )
{
		{if ( addr != 0 ) {free_from_cluster( 2, addr ) ;}}
	}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", open_cluster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", close_cluster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", alloc_from_cluster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", free_from_cluster);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gim_callback", dummy_malloc);

void dummy_free(void) {
}
