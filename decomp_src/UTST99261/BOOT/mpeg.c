#include "common.h"
#include <stdio.h>
#include <string.h>

extern int iPspBrowserApMode;
extern char mpegFilename[320];

int pspBrowserAddAnchor(const char *ext, int (*cb)(char *, char *));
void soundExit(void);
int soundInit(void);
int gInit(void);
int mpeg_main(char *filename);

int mpegCallback(char *filename, char *data);

int mpegInit(void)
{
	return 0;
}

void mpegExit(void)
{
}

int mepgAdd(void)
{
	pspBrowserAddAnchor("move", mpegCallback);
	return 0;
}

int mpegExec(void)
{
	puts("mpeg Exec");
	soundExit();
	mpeg_main(mpegFilename);
	puts("mpeg Exec End");
	soundInit();
	gInit();
	return 5;
}

int mpegEnd()
{
	return 0;
}

int mpegCallback(char *filename, char *data)
{
	strcpy(mpegFilename, filename);
	printf("mpeg file = { %s ][ %s\n", mpegFilename, data);
	iPspBrowserApMode = 0x12;
	return 0;
}
