#ifndef RS4_MINMAX_H
#define RS4_MINMAX_H
/* The game code's Allegrex max/min are volatile inline asm, not ternaries
   (which 1.9.2 also turns into max/min): the originals never schedule
   anything across them (profileGetRankingTtrStr keeps its prologue above the
   clamp; gameChkChange).  The exact original spelling is unknown. */
static __inline__ int amax(int a, int b)
{
	int r;
	__asm__ volatile("max %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
	return r;
}

static __inline__ int amin(int a, int b)
{
	int r;
	__asm__ volatile("min %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
	return r;
}
#endif
