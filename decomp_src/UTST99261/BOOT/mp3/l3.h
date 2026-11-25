#ifndef L3_H
#define L3_H
/* layer III types recovered from DWARF */
typedef struct {
	int l[23];		/* [cb] */
	int s[3][13];		/* [window][cb] */
} SCALE_FACTOR;

typedef struct {
	int cbtype;		/* long=0 short=1 */
	int cbmax;		/* max crit band */
	int lb_type;		/* long block type 0 1 3 */
	int cbs0;		/* short band start index 0 3 12 (12=no shorts */
	int ncbl;		/* number long cb's 0 8 21 */
	int cbmax_s[3];		/* cbmax by individual short blocks */
} CB_INFO;

typedef struct {
	int nr[3];
	int slen[3];
	int intensity_scale;
} IS_SF_INFO;

typedef float ARRAY2[2];

typedef struct {
	unsigned int part2_3_length;
	unsigned int big_values;
	unsigned int global_gain;
	unsigned int scalefac_compress;
	unsigned int window_switching_flag;
	unsigned int block_type;
	unsigned int mixed_block_flag;
	unsigned int table_select[3];
	unsigned int subblock_gain[3];
	unsigned int region0_count;
	unsigned int region1_count;
	unsigned int preflag;
	unsigned int scalefac_scale;
	unsigned int count1table_select;
} GR_INFO;

typedef struct {
	unsigned int main_data_begin;
	unsigned int private_bits;
	unsigned int scfsi[2];	/* 4 bit flags [ch] */
	GR_INFO gr[2][2];	/* [gran][ch] */
} SIDE_INFO;

int bitget(int n);
#endif
