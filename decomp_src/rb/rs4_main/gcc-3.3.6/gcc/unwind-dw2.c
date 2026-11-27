/* upstream: libgcc unwind-dw2.c (unwind-dw2.o), tree: 1.9.2 */
/* cflags: -O2 -fexceptions */
/* psp-gcc 1.9.2 has 210 hard registers (FIRST_PSEUDO_REGISTER; the 1.9.2 tree
   only has the 176 of 1.7.1): the original's _Unwind_Context has reg[211] and
   __builtin_init_dwarf_reg_size_table stores 4 for each of them, in the
   order of the hard registers (DWARF column 64 for $31). */
#define DWARF_FRAME_REGISTERS 210
static inline __attribute__((always_inline)) void init_reg_size_table_210(unsigned char *t)
{
	t[0] = 4; t[1] = 4; t[2] = 4; t[3] = 4; t[4] = 4; t[5] = 4; t[6] = 4; t[7] = 4; t[8] = 4; t[9] = 4;
	t[10] = 4; t[11] = 4; t[12] = 4; t[13] = 4; t[14] = 4; t[15] = 4; t[16] = 4; t[17] = 4; t[18] = 4; t[19] = 4;
	t[20] = 4; t[21] = 4; t[22] = 4; t[23] = 4; t[24] = 4; t[25] = 4; t[26] = 4; t[27] = 4; t[28] = 4; t[29] = 4;
	t[30] = 4; t[64] = 4; t[32] = 4; t[33] = 4; t[34] = 4; t[35] = 4; t[36] = 4; t[37] = 4; t[38] = 4; t[39] = 4;
	t[40] = 4; t[41] = 4; t[42] = 4; t[43] = 4; t[44] = 4; t[45] = 4; t[46] = 4; t[47] = 4; t[48] = 4; t[49] = 4;
	t[50] = 4; t[51] = 4; t[52] = 4; t[53] = 4; t[54] = 4; t[55] = 4; t[56] = 4; t[57] = 4; t[58] = 4; t[59] = 4;
	t[60] = 4; t[61] = 4; t[62] = 4; t[63] = 4; t[64] = 4; t[65] = 4; t[66] = 4; t[67] = 4; t[68] = 4; t[69] = 4;
	t[70] = 4; t[71] = 4; t[72] = 4; t[73] = 4; t[74] = 4; t[75] = 4; t[76] = 4; t[77] = 4; t[78] = 4; t[79] = 4;
	t[80] = 4; t[81] = 4; t[82] = 4; t[83] = 4; t[84] = 4; t[85] = 4; t[86] = 4; t[87] = 4; t[88] = 4; t[89] = 4;
	t[90] = 4; t[91] = 4; t[92] = 4; t[93] = 4; t[94] = 4; t[95] = 4; t[96] = 4; t[97] = 4; t[98] = 4; t[99] = 4;
	t[100] = 4; t[101] = 4; t[102] = 4; t[103] = 4; t[104] = 4; t[105] = 4; t[106] = 4; t[107] = 4; t[108] = 4; t[109] = 4;
	t[110] = 4; t[111] = 4; t[112] = 4; t[113] = 4; t[114] = 4; t[115] = 4; t[116] = 4; t[117] = 4; t[118] = 4; t[119] = 4;
	t[120] = 4; t[121] = 4; t[122] = 4; t[123] = 4; t[124] = 4; t[125] = 4; t[126] = 4; t[127] = 4; t[128] = 4; t[129] = 4;
	t[130] = 4; t[131] = 4; t[132] = 4; t[133] = 4; t[134] = 4; t[135] = 4; t[136] = 4; t[137] = 4; t[138] = 4; t[139] = 4;
	t[140] = 4; t[141] = 4; t[142] = 4; t[143] = 4; t[144] = 4; t[145] = 4; t[146] = 4; t[147] = 4; t[148] = 4; t[149] = 4;
	t[150] = 4; t[151] = 4; t[152] = 4; t[153] = 4; t[154] = 4; t[155] = 4; t[156] = 4; t[157] = 4; t[158] = 4; t[159] = 4;
	t[160] = 4; t[161] = 4; t[162] = 4; t[163] = 4; t[164] = 4; t[165] = 4; t[166] = 4; t[167] = 4; t[168] = 4; t[169] = 4;
	t[170] = 4; t[171] = 4; t[172] = 4; t[173] = 4; t[174] = 4; t[175] = 4; t[176] = 4; t[177] = 4; t[178] = 4; t[179] = 4;
	t[180] = 4; t[181] = 4; t[182] = 4; t[183] = 4; t[184] = 4; t[185] = 4; t[186] = 4; t[187] = 4; t[188] = 4; t[189] = 4;
	t[190] = 4; t[191] = 4; t[192] = 4; t[193] = 4; t[194] = 4; t[195] = 4; t[196] = 4; t[197] = 4; t[198] = 4; t[199] = 4;
	t[200] = 4; t[201] = 4; t[202] = 4; t[203] = 4; t[204] = 4; t[205] = 4; t[206] = 4; t[207] = 4; t[208] = 4; t[209] = 4;
}
#define __builtin_init_dwarf_reg_size_table(t) init_reg_size_table_210(t)
#include <unwind-dw2.c>  /* the tree's, not this file */

/* the module's asm .eh_frame refers to these static functions by name */
__asm__(".globl _Unwind_ForcedUnwind_Phase2\n.globl _Unwind_RaiseException_Phase2\n.globl base_of_encoded_value\n.globl execute_cfa_program\n.globl extract_cie_info\n.globl uw_frame_state_for\n.globl uw_init_context_1\n.globl uw_install_context_1");
