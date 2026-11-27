.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching sceGupShadeModel, 0x2C

glabel sceGupShadeModel
    /* 95930 00095870 0050023C */  lui        $2, (0x50000001 >> 16)
    /* 95934 00095874 0700A014 */  bnez       $5, .L00095894
    /* 95938 00095878 01004334 */   ori       $3, $2, (0x50000001 & 0xFFFF)
    /* 9593C 0009587C 0800828C */  lw         $2, 0x8($4)
    /* 95940 00095880 0050033C */  lui        $3, (0x50000000 >> 16)
  .L00095884:
    /* 95944 00095884 000043AC */  sw         $3, 0x0($2)
    /* 95948 00095888 04004324 */  addiu      $3, $2, 0x4
    /* 9594C 0009588C 0800E003 */  jr         $31
    /* 95950 00095890 080083AC */   sw        $3, 0x8($4)
  .L00095894:
    /* 95954 00095894 21560208 */  j          .L00095884
    /* 95958 00095898 0800828C */   lw        $2, 0x8($4)
endlabel sceGupShadeModel
