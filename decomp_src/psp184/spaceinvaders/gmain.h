/* gmain (0x4B4FE8, size 0x1467CC): field offsets recovered from the module's
   accesses (scan of all asm); names are offsets, types from load/store widths.
   Labels D_005xxxxx inside gmain are gmain + (addr - 0x4B4FE8). */
#ifndef SPACEINVADERS_GMAIN_H
#define SPACEINVADERS_GMAIN_H
typedef struct GMAIN_FIELDS {
	int f0; /* game_control */
	int f4; /* game_cnt_ending, game_cnt_game, game_cnt_hiscore_3B97C */
	int f8; /* game_cnt_game, game_cnt_hiscore_3B97C, game_cnt_nameentry */
	int fc; /* bg_init, game_cnt_ending, maingame_all_init */
	int f10; /* bufo_enemy_start, bufo_move, timer_control */
	int f14; /* game_cnt_title, maingame_all_init, maingame_init */
	int f18; /* maingame_all_init, maingame_init */
	int f1c; /* bg_init, game_cnt_game, game_cnt_pause */
	int f20; /* inv_netgame_linkcheck, inv_netgame_linkcheck2, inv_netgame_loop */
	int f24; /* netgame_ufo_pos_set */
	int f28; /* inv_netgame_member_max */
	int f2c; /* game_cnt_result, status_net_score_disp */
	int f30; /* inv_netgame_init, inv_netgame_linkcheck, inv_netgame_linkcheck2 */
	int f34; /* netgame_ufo_pos_set */
	u8 _pad38[0x14];
	int f4c; /* netgame_ufo_pos_set */
	u8 _pad50[0xe54];
	int fea4; /* inv_netgame_init, netgame_ufo_damage_get, netgame_zako_damage_get */
	int fea8; /* inv_netgame_init, netgame_ufo_damage_get, netgame_zako_damage_get */
	u8 _padeac[0x7c];
	int ff28; /* boss_ufo_control, boss_ufo_disp, boss_ufo_init */
	int ff2c; /* maingame_init */
	int ff30; /* bgm_init, maingame_init, ziki_control */
	int ff34; /* bgm_init, maingame_init */
	int ff38; /* game_cnt_ending, maingame_all_init, maingame_movie */
	int ff3c; /* bg_free, bg_init, maingame_init */
	int ff40; /* bg_free */
	u8 _padf44[0xc];
	int ff50; /* bg_free, bg_init, maingame_init */
	u8 _padf54[0x10];
	int ff64; /* maingame_all_free, maingame_all_init */
	int ff68; /* maingame_all_free, maingame_all_init */
	int ff6c; /* status_disp */
	int ff70; /* bufo_dead_anime, efc_bom2_start, efc_bom_start */
	int ff74; /* ziki_disp */
	int ff78; /* maingame_movie */
	int ff7c; /* end_result_font_disp */
	u8 _padf80[0x50];
	int ffd0; /* ufo_init */
	u8 _padfd4[0x24];
	int fff8; /* shield_init */
	u8 _padffc[0x1c];
	int f1018; /* maingame_init */
	u8 _pad101c[0x30];
	int f104c; /* ufo_init */
	u8 _pad1050[0x4];
	int f1054; /* shield_init */
	int f1058; /* boss_laser_start, deb_status_disp, game_cnt_game */
	int f105c; /* game_cnt_ending */
	int f1060; /* game_cnt_ending, game_cnt_hiscore_3B97C, maingame_all_init */
	int f1064; /* bg_init, maingame_all_init, maingame_init */
	int f1068; /* game_cnt_game, game_cnt_netdead, game_cnt_pause */
	int f106c; /* maingame_init, status_disp, status_disp_cnt */
	int f1070; /* cam_control, game_cnt_netdead, game_cnt_stageclear */
	int f1074; /* maingame_init, maingame_main */
	u8 _pad1078[0x8];
	int f1080; /* inv_polydisp_clear, inv_polydisp_clear2, maingame_init */
	int f1084; /* inv_polydisp_clear, inv_polydisp_clear2, maingame_init */
	int f1088; /* boss_ufo_control, boss_ufo_disp, boss_ufo_init */
	int f108c; /* maingame_free, maingame_init */
	int f1090; /* game_cnt_game, maingame_init */
	int f1094; /* game_cnt_game, maingame_init */
	int f1098; /* game_cnt_game, maingame_init */
	int f109c; /* game_cnt_game, maingame_init, zako_death */
	int f10a0; /* maingame_init, ziki_control */
	int f10a4; /* maingame_init, ziki_control */
	int f10a8; /* maingame_init */
	int f10ac; /* maingame_main, se_play_3d, ziki_control */
	int f10b0; /* maingame_main, se_play_3d, ziki_control */
	int f10b4; /* maingame_main, se_play_3d, ziki_control */
	float f10b8; /* cam_control, shield_control, status_disp_cnt */
	float f10bc; /* boss_ufo_disp, bufo_move, cam_control */
	u8 _pad10c0[0xe2ffc];
	int fe40bc; /* game_cnt_pause */
	u8 _pade40c0[0x2288];
	int fe6348; /* cam_control */
	u8 _pade634c[0x8];
	int fe6354; /* cam_control */
	int fe6358; /* cam_control */
	float fe635c; /* cam_control */
	int fe6360; /* cam_control */
	float fe6364; /* cam_control */
	float fe6368; /* cam_control */
	float fe636c; /* cam_control */
	float fe6370; /* cam_control */
	float fe6374; /* cam_control */
	float fe6378; /* cam_control */
	float fe637c; /* cam_control */
	int fe6380; /* cam_control */
	s8 fe6384; /* cam_control */
	u8 _pade6385[0x3];
	float fe6388; /* cam_control */
	float fe638c; /* cam_control */
	float fe6390; /* cam_control */
	float fe6394; /* cam_control */
	float fe6398; /* cam_control */
	float fe639c; /* cam_control */
	float fe63a0; /* cam_control */
	float fe63a4; /* cam_control */
	u8 _pade63a8[0xbc];
	int fe6464; /* status_disp_cnt */
	int fe6468; /* status_disp_cnt */
	int fe646c; /* status_disp_cnt */
	int fe6470; /* status_disp_cnt */
	u8 _pade6474[0x4];
	int fe6478; /* status_disp_cnt */
	int fe647c; /* status_disp_cnt */
	int fe6480; /* status_disp_cnt */
	u8 _pade6484[0x4];
	int fe6488; /* status_disp_cnt */
	int fe648c; /* status_disp_cnt */
	u8 _pade6490[0x8];
	int fe6498; /* status_disp_cnt */
	int fe649c; /* status_disp_cnt */
	u8 _pade64a0[0x4];
	int fe64a4; /* status_disp_cnt */
	int fe64a8; /* status_disp_cnt */
	int fe64ac; /* status_disp_cnt */
	int fe64b0; /* status_disp_cnt */
	u8 _pade64b4[0x4];
	int fe64b8; /* status_disp_cnt */
	u8 _pade64bc[0x10];
	int fe64cc; /* status_disp_cnt */
	int fe64d0; /* status_disp_cnt */
	int fe64d4; /* status_disp_cnt */
	short fe64d8; /* status_disp_cnt */
	u8 _pade64da[0x6];
	short fe64e0; /* status_disp_cnt */
	short fe64e2; /* status_disp_cnt */
	short fe64e4; /* status_disp_cnt */
	short fe64e6; /* status_disp_cnt */
	short fe64e8; /* status_disp_cnt */
	u8 _pade64ea[0x40];
	short fe652a; /* status_disp_cnt */
	u8 _pade652c[0xbe];
	short fe65ea; /* status_disp_cnt */
	s8 fe65ec; /* status_disp_cnt */
	u8 _pade65ed[0x43];
	int fe6630; /* status_disp_cnt */
	u8 _pade6634[0xf8];
	int fe672c; /* timer_control */
	int fe6730; /* timer_control */
	u8 _pade6734[0x4];
	int fe6738; /* timer_control */
	int fe673c; /* timer_control */
	int fe6740; /* timer_control */
	u8 _pade6744[0x4];
	int fe6748; /* timer_control */
	int fe674c; /* timer_control */
	int fe6750; /* timer_control */
	int fe6754; /* timer_control */
	int fe6758; /* timer_control */
	int fe675c; /* timer_control */
	int fe6760; /* timer_control */
	int fe6764; /* timer_control */
	u8 _pade6768[0x4];
	int fe676c; /* timer_control */
	int fe6770; /* timer_control */
	int fe6774; /* timer_control */
	int fe6778; /* timer_control */
	int fe677c; /* timer_control */
	int fe6780; /* timer_control */
	u8 _pade6784[0x1882];
	short fe8006; /* status_disp_cnt */
	u8 _pade8008[0x36b8];
	int feb6c0; /* bg_control, bg_free, bg_init */
	int feb6c4; /* bg_control, inv_polydisp_clear_off */
	int feb6c8; /* inv_polydisp_clear_off */
	u8 _padeb6cc[0xc];
	float feb6d8; /* bg_control */
	u8 _padeb6dc[0x14];
	int feb6f0; /* ziki_init */
	int feb6f4; /* ziki_control, ziki_init */
	int feb6f8; /* ziki_control, ziki_init */
	int feb6fc; /* ziki_control, ziki_init */
	int feb700; /* ziki_control, ziki_init */
	int feb704; /* game_cnt_dead, game_cnt_gameover, game_cnt_netdead */
	int feb708; /* ziki_control, ziki_init */
	int feb70c; /* game_cnt_game, status_disp_cnt, ziki_control */
	int feb710; /* laser2_control, ziki_control, ziki_disp */
	int feb714; /* inv_polydisp_clear, inv_polydisp_clear2, ziki_disp */
	u8 _padeb718[0x4];
	int feb71c; /* ziki_control, ziki_init */
	int feb720; /* ziki_beat_check, ziki_beat_miss_check, ziki_control */
	int feb724; /* ziki_control, ziki_init */
	float feb728; /* zako_attack_anime, zako_normal_anime, zako_shot */
	float feb72c; /* ziki_control, ziki_init */
	float feb730; /* ziki_control, ziki_init */
	int feb734; /* ziki_control, ziki_init */
	int feb738; /* ziki_control, ziki_init */
	int feb73c; /* status_disp_cnt, ziki_break_success_check, ziki_control */
	int feb740; /* game_cnt_game, game_cnt_pause, status_disp_cnt */
	int feb744; /* status_disp_cnt, ziki_beat_check, ziki_beat_check2 */
	int feb748; /* status_disp_cnt, ziki_beat_check, ziki_beat_check2 */
	int feb74c; /* status_disp_cnt, ziki_beat_check, ziki_beat_check2 */
	int feb750; /* status_disp_cnt, ziki_beat_check, ziki_beat_check2 */
	int feb754; /* laser_hit_check, ziki_control, ziki_init */
	int feb758; /* timer_control, ziki_control, ziki_init */
	float feb75c; /* hit_check_player, ziki_control, ziki_disp */
	float feb760; /* cam_control, hit_check_player, ziki_control */
	float feb764; /* hit_check_player, ziki_control, ziki_disp */
	int feb768; /* ziki_disp, ziki_init */
	int feb76c; /* ziki_disp, ziki_init */
	int feb770; /* ziki_disp, ziki_init */
	int feb774; /* ziki_init */
	int feb778; /* ziki_init */
	int feb77c; /* ziki_init */
	u8 _padeb780[0xc];
	int feb78c; /* inv_polydisp_clear, inv_polydisp_clear2, zako_disp */
	u8 _padeb790[0xc];
	float feb79c; /* zako_control_once, zako_disp */
	float feb7a0; /* zako_control_once, zako_disp */
	int feb7a4; /* zako_control_once, zako_disp */
	u8 _padeb7a8[0x210];
	int feb9b8; /* ufo_disp, ufo_disp_once */
	float feb9bc; /* boss_ufo_disp, ufo_disp, ufo_disp_once */
	float feb9c0; /* boss_ufo_disp, ufo_disp, ufo_disp_once */
	int feb9c4; /* boss_ufo_disp, ufo_disp, ufo_disp_once */
	int feb9c8; /* inv_polydisp_clear, inv_polydisp_clear2, ufo_disp */
	int feb9cc; /* inv_polydisp_clear, inv_polydisp_clear2, ufo_disp */
	int feb9d0; /* deb_status_disp, hit_check_ufo, laser2_hit_check_ufo */
	u8 _padeb9d4[0x4];
	int feb9d8; /* hit_check_ufo, laser2_hit_check_ufo, status_disp */
	int feb9dc; /* laser2_hit_check_ufo, status_disp, ufo_all_dead_check */
	int feb9e0; /* deb_status_disp */
	u8 _padeb9e4[0x14];
	int feb9f8; /* netgame_ufo_life_get, ufo_control */
	u8 _padeb9fc[0x4];
	int feba00; /* status_disp */
	u8 _padeba04[0x14];
	float feba18; /* netgame_ufo_pos_get, ufo_control, ufo_init */
	u8 _padeba1c[0x4];
	float feba20; /* netgame_ufo_pos_get */
	float feba24; /* netgame_ufo_pos_get */
	u8 _padeba28[0x94];
	float febabc; /* deb_status_disp */
	u8 _padebac0[0x4];
	float febac4; /* netgame_ufo_pos_get */
	float febac8; /* netgame_ufo_pos_get */
	u8 _padebacc[0x23c];
	int febd08; /* boss_ufo_disp, boss_ufo_init, inv_polydisp_clear */
	int febd0c; /* boss_ufo_disp, boss_ufo_init, hit_check_ufo */
	int febd10; /* boss_ufo_control, boss_ufo_disp, boss_ufo_init */
	int febd14; /* boss_ufo_init, hit_check_ufo, laser2_hit_check_ufo */
	u8 _padebd18[0x4];
	int febd1c; /* boss_ufo_disp, boss_ufo_init */
	int febd20; /* boss_ufo_init */
	int febd24; /* boss_ufo_control, boss_ufo_init */
	int febd28; /* boss_ufo_init */
	int febd2c; /* boss_ufo_control, boss_ufo_init, hit_check_ufo */
	int febd30; /* boss_ufo_init */
	int febd34; /* boss_ufo_init */
	u8 _padebd38[0x4];
	int febd3c; /* boss_ufo_control, boss_ufo_init, hit_check_ufo */
	int febd40; /* boss_ufo_init */
	u8 _padebd44[0x8];
	int febd4c; /* boss_ufo_init */
	int febd50; /* boss_ufo_init */
	float febd54; /* boss_ufo_control, boss_ufo_disp, boss_ufo_init */
	int febd58; /* boss_ufo_init */
	float febd5c; /* boss_ufo_init */
	int febd60; /* boss_ufo_init */
	int febd64; /* boss_ufo_init */
	float febd68; /* boss_ufo_init */
	float febd6c; /* boss_ufo_disp, boss_ufo_init */
	int febd70; /* boss_ufo_disp, boss_ufo_init, hit_check_ufo */
	int febd74; /* boss_ufo_disp, boss_ufo_init, hit_check_ufo */
	int febd78; /* boss_ufo_disp, boss_ufo_init, hit_check_ufo */
	int febd7c; /* boss_ufo_disp, boss_ufo_init */
	float febd80; /* boss_ufo_disp, boss_ufo_init */
	int febd84; /* boss_ufo_disp, boss_ufo_init */
	int febd88; /* boss_ufo_init */
	int febd8c; /* boss_ufo_init */
	int febd90; /* boss_ufo_init */
	int febd94; /* enemy_gp_control, enemy_gp_dead, enemy_gp_disp */
	int febd98; /* enemy_gp_dead, enemy_gp_disp, enemy_gp_end */
	int febd9c; /* enemy_gp_disp */
	float febda0; /* ufo_normal_anime */
	float febda4; /* ufo_normal_anime */
	u8 _padebda8[0x44];
	int febdec; /* enemy_gp_end */
	u8 _padebdf0[0x4];
	int febdf4; /* enemy_gp_end */
	int febdf8; /* enemy_gp_end */
	u8 _padebdfc[0x2500];
	int fee2fc; /* enemy_gp_init */
	u8 _padee300[0x4];
	float fee304; /* ufo_normal_anime */
	u8 _padee308[0x6cc];
	s8 fee9d4; /* efc_laser_start */
	u8 _padee9d5[0x162b];
	int ff0000; /* game_cnt_pause */
	int ff0004; /* game_cnt_stageclear */
	u8 _padf0008[0x8];
	float ff0010; /* ufo_normal_anime, zako_attack_anime */
	u8 _padf0014[0x8];
	int ff001c; /* game_cnt_pause, ufo_normal_anime */
	u8 _padf0020[0xf08];
	int ff0f28; /* boss_ufo_init, inv_polydisp_clear, inv_polydisp_clear2 */
	u8 _padf0f2c[0x4];
	int ff0f30; /* game_cnt_pause */
	int ff0f34; /* game_cnt_pause */
	u8 _padf0f38[0x48];
	int ff0f80; /* ziki_init */
	u8 _padf0f84[0x94];
	int ff1018; /* ziki_init */
	u8 _padf101c[0x6c];
	int ff1088; /* enemy_gp_init */
	u8 _padf108c[0x2c];
	float ff10b8; /* deb_status_disp */
	float ff10bc; /* deb_status_disp, status_target_set, ufo_disp */
	u8 _padf10c0[0x3ef50];
	float f130010; /* laser_control */
	u8 _pad130014[0xf14];
	int f130f28; /* shield_init */
	u8 _pad130f2c[0x1024];
	int f131f50; /* inv_polydisp_clear, inv_polydisp_clear2, shield_disp */
	int f131f54; /* inv_polydisp_clear, inv_polydisp_clear2, shield_disp */
	u8 _pad131f58[0x38];
	float f131f90; /* shield_control, shield_init, shield_update */
	int f131f94; /* deb_status_disp, shield_init, shield_update */
	int f131f98; /* shield_init, shield_update */
	int f131f9c; /* shield_init, shield_update */
	float f131fa0; /* shield_control, shield_init, shield_update */
	int f131fa4; /* hit_check_shield, shield_control, shield_disp */
	int f131fa8; /* shield_disp, shield_init */
	int f131fac; /* shield_init */
	int f131fb0; /* shield_init */
	int f131fb4; /* shield_init */
	float f131fb8; /* shield_init */
	u8 _pad131fbc[0xc];
	int f131fc8; /* shield_init */
	int f131fcc; /* shield_init */
	int f131fd0; /* shield_init */
	int f131fd4; /* shield_update */
	int f131fd8; /* shield_update */
	int f131fdc; /* shield_update */
	int f131fe0; /* shield_disp, shield_update */
	int f131fe4; /* shield_update */
	float f131fe8; /* shield_update */
	int f131fec; /* shield_disp */
	int f131ff0; /* shield_disp */
	int f131ff4; /* shield_disp */
	int f131ff8; /* shield_disp */
	int f131ffc; /* shield_disp */
	int f132000; /* shield_disp */
	u8 _pad132004[0x2a0];
	int f1322a4; /* hit_check_laser, laser_init */
	u8 _pad1322a8[0x4];
	int f1322ac; /* hit_check_laser */
	u8 _pad1322b0[0x90];
	int f132340; /* hit_check_laser, laser_init */
	u8 _pad132344[0x12e0];
	int f133624; /* laser2_control, laser2_end_check, laser2_init */
	u8 _pad133628[0x8];
	int f133630; /* laser2_control, laser2_end_check, laser2_start */
	int f133634; /* laser2_control, laser2_end_check, laser2_start */
	u8 _pad133638[0x4];
	float f13363c; /* laser2_c_set, laser2_start */
	float f133640; /* laser2_c_set, laser2_control, laser2_start */
	float f133644; /* laser2_c_set, laser2_control, laser2_start */
	float f133648; /* laser2_c_set, laser2_control, laser2_start */
	int f13364c; /* laser2_c_set, laser2_start */
	int f133650; /* laser2_c_set, laser2_start */
	int f133654; /* laser2_c_set, laser2_start */
	u8 _pad133658[0x70];
	int f1336c8; /* boss_laser_init */
	u8 _pad1336cc[0x87c];
	int f133f48; /* item_init */
	u8 _pad133f4c[0x1bfc];
	int f135b48; /* particle_control, particle_init, particle_set */
	int f135b4c; /* particle_set */
	int f135b50; /* particle_set */
	int f135b54; /* particle_set */
	int f135b58; /* particle_init */
	int f135b5c; /* particle_control, particle_set */
	int f135b60; /* particle_set */
	int f135b64; /* particle_set */
	int f135b68; /* particle_set */
	int f135b6c; /* particle_set */
	int f135b70; /* particle_set */
	float f135b74; /* particle_set */
	int f135b78; /* particle_set */
	int f135b7c; /* particle_set */
	int f135b80; /* particle_set */
	int f135b84; /* particle_set */
	u8 _pad135b88[0x4];
	int f135b8c; /* particle_set */
	int f135b90; /* particle_set */
	int f135b94; /* particle_set */
	int f135b98; /* particle_set */
	int f135b9c; /* particle_set */
	int f135ba0; /* particle_set */
	float f135ba4; /* particle_set */
	float f135ba8; /* particle_set */
	int f135bac; /* particle_set */
	int f135bb0; /* particle_set */
	int f135bb4; /* particle_set */
	int f135bb8; /* particle_set */
	int f135bbc; /* particle_set */
	int f135bc0; /* particle_set */
	int f135bc4; /* particle_set */
	int f135bc8; /* particle_set */
	int f135bcc; /* particle_control, particle_set */
	int f135bd0; /* particle_control */
	u8 _pad135bd4[0xc];
	int f135be0; /* particle_control */
	u8 _pad135be4[0x14];
	float f135bf8; /* particle_control */
	float f135bfc; /* particle_control */
	u8 _pad135c00[0x10];
	float f135c10; /* particle_control */
	float f135c14; /* particle_control */
	float f135c18; /* particle_control */
	float f135c1c; /* particle_control */
	float f135c20; /* particle_control */
	float f135c24; /* particle_control */
	float f135c28; /* particle_control */
	float f135c2c; /* particle_control */
	float f135c30; /* particle_control */
	float f135c34; /* particle_control */
	float f135c38; /* particle_control */
	float f135c3c; /* particle_control */
	float f135c40; /* particle_control */
	float f135c44; /* particle_control */
	float f135c48; /* particle_control */
	float f135c4c; /* particle_control */
	u8 _pad135c50[0x60bc];
	int f13bd0c; /* status_disp_cnt */
	u8 _pad13bd10[0x5260];
	int f140f70; /* efc_bom_start, efc_shot_del, ufo_warpin_anime */
	u8 _pad140f74[0x30f4];
	int f144068; /* game_cnt_title */
	u8 _pad14406c[0x28];
	int f144094; /* game_cnt_option2 */
	u8 _pad144098[0x24];
	int f1440bc; /* game_cnt_pause */
	u8 _pad1440c0[0xb4];
	int f144174; /* game_cnt_nameentry */
	int f144178; /* game_cnt_nameentry */
	u8 _pad14417c[0x1d34];
	int f145eb0; /* classic_inv_score */
	u8 _pad145eb4[0x494];
	int f146348; /* cam_init, game_cnt_option2, game_cnt_option_3559C */
	u8 _pad14634c[0x4];
	int f146350; /* cam_init, risarju_control */
	int f146354; /* cam_init */
	u8 _pad146358[0x4];
	float f14635c; /* cam_init, ziki_control */
	int f146360; /* cam_init */
	int f146364; /* cam_init */
	int f146368; /* cam_init */
	float f14636c; /* cam_init, df_quake_disp */
	float f146370; /* cam_init, df_quake_disp */
	float f146374; /* cam_init, df_quake_disp */
	int f146378; /* cam_init */
	int f14637c; /* cam_init */
	int f146380; /* cam_init */
	int f146384; /* cam_init */
	int f146388; /* cam_init */
	int f14638c; /* cam_init */
	int f146390; /* cam_init */
	float f146394; /* boss_ufo_disp, cam_init, clippint_check */
	float f146398; /* cam_init */
	float f14639c; /* cam_init */
	float f1463a0; /* cam_init */
	float f1463a4; /* cam_init */
	u8 _pad1463a8[0x20];
	int f1463c8; /* df_cap_disp, df_cap_start, dispeffect_all_free */
	int f1463cc; /* df_quake_start, dispeffect_init */
	int f1463d0; /* df_quake_control, df_quake_start, dispeffect_init */
	int f1463d4; /* df_quake_control, df_quake_start, dispeffect_init */
	int f1463d8; /* df_quake_control, df_quake_disp, dispeffect_init */
	int f1463dc; /* df_quake_control, df_quake_disp, dispeffect_init */
	int f1463e0; /* df_quake_control, df_quake_disp, dispeffect_init */
	int f1463e4; /* df_blur_disp, df_blur_scrpos_set, df_blur_start */
	int f1463e8; /* df_blur_disp, df_blur_scrpos_set, df_blur_start */
	int f1463ec; /* df_blur_disp, df_blur_scrpos_set, df_blur_start */
	int f1463f0; /* df_blur_disp, df_blur_scrpos_set, df_blur_start */
	int f1463f4; /* df_blur_disp, df_blur_start, dispeffect_init */
	int f1463f8; /* df_blur_disp, df_blur_start, dispeffect_init */
	int f1463fc; /* df_blur_disp, df_blur_start, dispeffect_init */
	int f146400; /* df_blur_disp, df_blur_start, dispeffect_init */
	int f146404; /* df_blur_disp, df_blur_start, dispeffect_init */
	int f146408; /* df_blur_control, df_blur_disp, df_blur_end */
	int f14640c; /* df_blur_control, df_blur_disp, df_blur_end */
	int f146410; /* df_cap_disp, df_cap_start, dispeffect_init */
	int f146414; /* df_cap_disp, df_cap_start, dispeffect_init */
	int f146418; /* df_cap_disp, df_cap_start, dispeffect_init */
	int f14641c; /* df_cap_disp, df_cap_start, dispeffect_init */
	int f146420; /* df_cap_disp, df_cap_start, dispeffect_init */
	int f146424; /* df_cap_control, df_cap_disp, df_cap_start */
	int f146428; /* df_cap_control, df_cap_disp, df_cap_start */
	int f14642c; /* df_flash_disp, df_flash_start, dispeffect_init */
	int f146430; /* df_flash_disp, df_flash_start, dispeffect_init */
	int f146434; /* df_flash_disp, df_flash_start, dispeffect_init */
	int f146438; /* df_flash_disp, df_flash_start, dispeffect_init */
	int f14643c; /* df_flash_disp, df_flash_start, dispeffect_init */
	int f146440; /* df_flash_control, df_flash_disp, df_flash_start */
	int f146444; /* df_flash_control, df_flash_disp, df_flash_start */
	int f146448; /* df_fade_disp, df_fade_start, dispeffect_init */
	int f14644c; /* df_fade_disp, df_fade_start, dispeffect_init */
	int f146450; /* df_fade_disp, df_fade_start, dispeffect_init */
	int f146454; /* df_fade_disp, df_fade_start, dispeffect_init */
	int f146458; /* df_fade_control, df_fade_disp, df_fade_start */
	int f14645c; /* df_fade_check, df_fade_control, df_fade_disp */
	int f146460; /* df_fade_check, df_fade_control, df_fade_disp */
	int f146464; /* status_disp, status_disp_init */
	int f146468; /* status_disp_init */
	int f14646c; /* status_disp, status_disp_init */
	u8 _pad146470[0x4];
	int f146474; /* status_disp_init */
	u8 _pad146478[0x4];
	int f14647c; /* status_disp_init */
	u8 _pad146480[0x4];
	int f146484; /* status_disp_init */
	u8 _pad146488[0x4];
	int f14648c; /* status_disp_init */
	u8 _pad146490[0x4];
	int f146494; /* status_disp */
	u8 _pad146498[0x4];
	int f14649c; /* status_disp */
	u8 _pad1464a0[0x4];
	int f1464a4; /* status_disp_init */
	int f1464a8; /* status_disp_init */
	int f1464ac; /* status_disp, status_disp_init */
	int f1464b0; /* status_disp, status_disp_init */
	float f1464b4; /* status_disp, status_disp_init */
	int f1464b8; /* status_disp, status_disp_init */
	u8 _pad1464bc[0x10];
	int f1464cc; /* status_disp, status_disp_init, status_net_score_disp */
	int f1464d0; /* status_disp, status_disp_init, status_net_score_disp */
	int f1464d4; /* status_disp, status_disp_init, status_net_score_disp */
	short f1464d8; /* status_disp, status_disp_init */
	short f1464da; /* status_disp, status_disp_init */
	short f1464dc; /* status_disp_init */
	short f1464de; /* status_disp_init */
	short f1464e0; /* status_disp */
	short f1464e2; /* status_disp, status_disp_init, status_net_score_disp */
	short f1464e4; /* status_disp, status_disp_init */
	short f1464e6; /* status_disp, status_disp_init */
	short f1464e8; /* status_disp, status_disp_init */
	short f1464ea; /* status_disp, status_disp_init */
	u8 _pad1464ec[0x3e];
	short f14652a; /* status_disp, status_disp_init */
	u8 _pad14652c[0x3e];
	short f14656a; /* status_disp, status_disp_init */
	u8 _pad14656c[0x3e];
	short f1465aa; /* status_disp, status_disp_init */
	u8 _pad1465ac[0x3e];
	short f1465ea; /* status_disp */
	s8 f1465ec; /* status_disp, status_disp_init, status_target_clear */
	s8 f1465ed; /* status_target_set */
	u8 _pad1465ee[0x1e];
	s8 f14660c; /* status_disp_init, status_target_clear */
	u8 _pad14660d[0x1f];
	int f14662c; /* status_disp_init, status_target_clear */
	u8 _pad146630[0x7c];
	int f1466ac; /* status_disp_init, status_target_clear */
	u8 _pad1466b0[0x7c];
	int f14672c; /* timer_init, timer_play */
	int f146730; /* timer_init, timer_play, timer_stop */
	int f146734; /* timer_init */
	int f146738; /* timer_init */
	int f14673c; /* timer_init */
	int f146740; /* timer_init */
	int f146744; /* timer_init */
	int f146748; /* timer_init, ziki_control */
	int f14674c; /* game_cnt_game, timer_init, zako_mov_count */
	int f146750; /* game_cnt_game, game_cnt_stagestart, status_disp_cnt */
	int f146754; /* timer_init */
	int f146758; /* timer_play */
	int f14675c; /* timer_play, timer_stop */
	int f146760; /* timer_play */
	int f146764; /* timer_play */
	int f146768; /* timer_play */
	float f14676c; /* status_disp_cnt */
	u8 _pad146770[0x8];
	int f146778; /* deb_status_disp, status_disp_cnt */
	u8 _pad14677c[0x8];
	int f146784; /* bgm_control, bgm_init, bgm_rank_max_check */
	int f146788; /* bgm_init, bgm_rank_max, bgm_rank_max_check */
	int f14678c; /* bgm_control, bgm_init, bgm_rank_start */
	int f146790; /* bgm_control, bgm_init, bgm_rank_start */
	int f146794; /* bgm_control, bgm_init, bgm_rank */
	int f146798; /* bgm_control, bgm_init, bgm_rankup */
	int f14679c; /* bgm_clear_play, bgm_control, bgm_init */
	int f1467a0; /* debprint_init, debprint_set */
	int f1467a4; /* risarju_init */
	int f1467a8; /* risarju_init */
	float f1467ac; /* risarju_init */
	float f1467b0; /* risarju_init */
	int f1467b4; /* risarju_init */
	int f1467b8; /* risarju_init */
	int f1467bc; /* risarju_init */
	int f1467c0; /* beat_help_init, beat_help_off, beat_help_set */
	int f1467c4; /* beat_help_init, beat_help_set */
	int f1467c8; /* beat_help_init, beat_help_set, beat_help_sync_disp */
	u8 _pad1467cc[0x0];
} GMAIN_FIELDS;

typedef union { u8 b[0x1467cc]; GMAIN_FIELDS f; } GMAIN;
extern GMAIN gmain;
/* field at byte offset OFF; with a variable index this is the array-member
   form (address = gmain + OFF + i * size, not a folded symbol+OFF) */
#define GM_INT(off) (*(int *)&gmain.b[off])
#define GM_FLT(off) (*(float *)&gmain.b[off])
#endif
