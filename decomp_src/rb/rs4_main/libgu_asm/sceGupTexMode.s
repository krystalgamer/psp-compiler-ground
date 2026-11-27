.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

nonmatching sceGupTexMode, 0x44

glabel sceGupTexMode
    /* 9586C 000957AC 08008A8C */  lw         $10, 0x8($4)
    /* 95870 000957B0 00740600 */  sll        $14, $6, 16
    /* 95874 000957B4 007A0700 */  sll        $15, $7, 8
    /* 95878 000957B8 2568CF01 */  or         $13, $14, $15
    /* 9587C 000957BC 04004625 */  addiu      $6, $10, 0x4
    /* 95880 000957C0 2558A801 */  or         $11, $13, $8
    /* 95884 000957C4 00C20C3C */  lui        $12, (0xC2000000 >> 16)
    /* 95888 000957C8 00C3093C */  lui        $9, (0xC3000000 >> 16)
    /* 9588C 000957CC 25386C01 */  or         $7, $11, $12
    /* 95890 000957D0 2540A900 */  or         $8, $5, $9
    /* 95894 000957D4 0800C224 */  addiu      $2, $6, 0x8
    /* 95898 000957D8 00CB033C */  lui        $3, (0xCB000000 >> 16)
    /* 9589C 000957DC 000047AD */  sw         $7, 0x0($10)
    /* 958A0 000957E0 080082AC */  sw         $2, 0x8($4)
    /* 958A4 000957E4 0000C8AC */  sw         $8, 0x0($6)
    /* 958A8 000957E8 0800E003 */  jr         $31
    /* 958AC 000957EC 0400C3AC */   sw        $3, 0x4($6)
endlabel sceGupTexMode
