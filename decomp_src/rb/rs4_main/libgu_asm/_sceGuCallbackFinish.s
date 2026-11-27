.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching _sceGuCallbackFinish, 0x30

glabel _sceGuCallbackFinish
    /* 959D8 00095918 0400A28C */  lw         $2, 0x4($5)
    /* 959DC 0009591C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 959E0 00095920 0000BFAF */  sw         $31, 0x0($29)
    /* 959E4 00095924 04004014 */  bnez       $2, .L00095938
    /* 959E8 00095928 FFFF8430 */   andi      $4, $4, 0xFFFF
    /* 959EC 0009592C 0000BF8F */  lw         $31, 0x0($29)
  .L00095930:
    /* 959F0 00095930 0800E003 */  jr         $31
    /* 959F4 00095934 1000BD27 */   addiu     $29, $29, 0x10
  .L00095938:
    /* 959F8 00095938 09F84000 */  jalr       $2
    /* 959FC 0009593C 00000000 */   nop
    /* 95A00 00095940 4C560208 */  j          .L00095930
    /* 95A04 00095944 0000BF8F */   lw        $31, 0x0($29)
endlabel _sceGuCallbackFinish
