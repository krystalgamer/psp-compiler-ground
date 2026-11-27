.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching _sceGuUpdateStallAddr, 0x58

glabel _sceGuUpdateStallAddr
    /* 95B14 00095A54 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 95B18 00095A58 0000BFAF */  sw         $31, 0x0($29)
    /* 95B1C 00095A5C 0100033C */  lui        $3, %hi(g_Libgu)
    /* 95B20 00095A60 804E6424 */  addiu      $4, $3, %lo(g_Libgu)
    /* 95B24 00095A64 0C00828C */  lw         $2, 0xC($4)
    /* 95B28 00095A68 06004014 */  bnez       $2, .L00095A84
    /* 95B2C 00095A6C 21180000 */   addu      $3, $0, $0
    /* 95B30 00095A70 4800838C */  lw         $3, 0x48($4)
    /* 95B34 00095A74 7400658C */  lw         $5, 0x74($3)
    /* 95B38 00095A78 0600A050 */  beql       $5, $0, .L00095A94
    /* 95B3C 00095A7C 0800658C */   lw        $5, 0x8($3)
  .L00095A80:
    /* 95B40 00095A80 21180000 */  addu       $3, $0, $0
  .L00095A84:
    /* 95B44 00095A84 0000BF8F */  lw         $31, 0x0($29)
  .L00095A88:
    /* 95B48 00095A88 21106000 */  addu       $2, $3, $0
    /* 95B4C 00095A8C 0800E003 */  jr         $31
    /* 95B50 00095A90 1000BD27 */   addiu     $29, $29, 0x10
  .L00095A94:
    /* 95B54 00095A94 C4A6030C */  jal        sceGeListUpdateStallAddr
    /* 95B58 00095A98 1800848C */   lw        $4, 0x18($4)
    /* 95B5C 00095A9C F8FF4104 */  bgez       $2, .L00095A80
    /* 95B60 00095AA0 21184000 */   addu      $3, $2, $0
    /* 95B64 00095AA4 A2560208 */  j          .L00095A88
    /* 95B68 00095AA8 0000BF8F */   lw        $31, 0x0($29)
endlabel _sceGuUpdateStallAddr
