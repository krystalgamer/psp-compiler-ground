.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching sceGupFrontFace, 0x2C

glabel sceGupFrontFace
    /* 9569C 000955DC 009B023C */  lui        $2, (0x9B000001 >> 16)
    /* 956A0 000955E0 0600A014 */  bnez       $5, .L000955FC
    /* 956A4 000955E4 01004334 */   ori       $3, $2, (0x9B000001 & 0xFFFF)
    /* 956A8 000955E8 0800828C */  lw         $2, 0x8($4)
  .L000955EC:
    /* 956AC 000955EC 000043AC */  sw         $3, 0x0($2)
    /* 956B0 000955F0 04004324 */  addiu      $3, $2, 0x4
    /* 956B4 000955F4 0800E003 */  jr         $31
    /* 956B8 000955F8 080083AC */   sw        $3, 0x8($4)
  .L000955FC:
    /* 956BC 000955FC 0800828C */  lw         $2, 0x8($4)
    /* 956C0 00095600 7B550208 */  j          .L000955EC
    /* 956C4 00095604 009B033C */   lui       $3, (0x9B000000 >> 16)
endlabel sceGupFrontFace
