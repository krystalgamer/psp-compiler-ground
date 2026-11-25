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
#endif
