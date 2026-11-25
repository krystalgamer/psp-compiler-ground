#include "common.h"

int SystemInit(void);
int SystemTerm(void);
int MovieInit(void);
int MovieStart(void);
int MovieMain(void);
int MovieEnd(void);
int MovieTerm(void);

int main(void)
{
	SystemInit();
	MovieInit();
	for (;;) {
		MovieStart();
		MovieMain();
		MovieEnd();
	}
	MovieTerm();
	SystemTerm();
	return 0;
}
