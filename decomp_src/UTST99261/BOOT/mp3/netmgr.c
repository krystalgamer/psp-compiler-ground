#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "netmgr_types.h"
#include <libhttp.h>

int sceHttpEnd(void);
int sceKernelGetThreadId(void);
int sceNetFreeThreadinfo(int thid);
int sceNetApctlDisconnect(void);
int sceNetApctlGetState(int *state);
int sceKernelDelayThread(unsigned int delay);
int sceNetApDialogDummyTerm(void);
int sceNetApctlDelHandler(int handlerId);
int sceNetApctlTerm(void);
int sceNetResolverTerm(void);
int sceNetInetTerm(void);
int sceNetTerm(void);
int sceNetInetClose(int s);

extern int handler_id_1EDF08;
#define handler_id handler_id_1EDF08

static void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg);
#define apctl_handler apctl_handler_A268
#define NetMgrHttpRewind NetMgrHttpRewind_A56C
#define SkipBlank SkipBlank_A7D8

static void apctl_handler(int prev_state, int new_state, int event, int error_code, void *arg)
{
	if (prev_state == 4 && new_state == 0 && event == 6)
		printf("Apctl error happened, error = 0x%x\n", error_code);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/netmgr", NetMgrInit);

void NetMgrTerm(void)
{
	int apctl_state;
	int ret;

	ret = sceHttpEnd();
	if (ret < 0)
		printf("sceHttpEnd() returns %x\n", ret);
	sceNetFreeThreadinfo(sceKernelGetThreadId());
	ret = sceNetApctlDisconnect();
	if (ret < 0) {
		puts("sceNetApctlDisconnect() failed.");
	} else {
		for (;;) {
			ret = sceNetApctlGetState(&apctl_state);
			if (ret == 0 && apctl_state == 0)
				break;
			sceKernelDelayThread(1000000);
		}
	}
	sceNetApDialogDummyTerm();
	if (handler_id >= 0)
		sceNetApctlDelHandler(handler_id);
	sceNetApctlTerm();
	sceNetResolverTerm();
	sceNetInetTerm();
	sceNetTerm();
}

static int NetMgrHttpRewind(int fd)
{
	HTTP_PARAM *p;
	int status_code;
	int ret;
	int error_num;
	SceInt64 content_length;

	p = (HTTP_PARAM *)fd;
	if (fd <= 0) {
		printf("NetMgrHttpClose: error illigal fd %08x\n", fd);
		return -1;
	}

	p->curofst = 0;
	p->length = 0;
	p->buf_top = 0;
	p->buf_size = 0;

	if (p->request > 0) {
		ret = sceHttpAbortRequest(p->request);
		if (ret < 0)
			printf("sceHttpAbortRequest() returns %x\n", ret);
		ret = sceHttpDeleteRequest(p->request);
		if (ret < 0)
			printf("sceHttpDeleteRequest() returns %x\n", ret);
	}
	if (p->connection > 0) {
		ret = sceHttpDeleteConnection(p->connection);
		if (ret < 0)
			printf("sceHttpDeleteConnection() returns %x\n", ret);
	}

	p->connection = sceHttpCreateConnectionWithURL(p->tmpl, p->uri, 1);
	if (p->connection < 0) {
		printf("sceHttpCreateConnectionWithURL() returns %x\n", p->connection);
		return -1;
	}
	p->request = sceHttpCreateRequestWithURL(p->connection, 0, p->uri, 0);
	if (p->request < 0) {
		printf("sceHttpCreateRequestWithURL() returns %x\n", p->request);
		return -1;
	}

	ret = sceHttpSendRequest(p->request, NULL, 0);
	if (ret < 0) {
		printf("sceHttpSendRequest() returns %x\n", ret);
		if (ret == 0x80431063) {
			ret = sceHttpGetNetworkErrno(p->request, &error_num);
			if (ret < 0)
				printf("sceHttpGetNetworkErrno() returns %x\n", ret);
			else
				printf("errno = %d\n", error_num);
		}
		return ret;
	}
	ret = sceHttpGetStatusCode(p->request, &status_code);
	if (ret < 0) {
		printf("sceHttpGetStatusCode() returns %x\n", ret);
		return ret;
	}
	printf("response code = %d\n", status_code);
	if (status_code != 200)
		return -1;
	ret = sceHttpGetContentLength(p->request, &content_length);
	if (ret < 0)
		printf("sceHttpGetContentLength() returns %x\n", ret);
	else
		printf("Content-Length = %lld\n", content_length);
	p->length = content_length;
	return 0;
}

static char *SearchBlank(char *p)
{
	while (*p != 0) {
		if (*p == ' ' || *p == '\t')
			break;
		p++;
	}
	return p;
}

static char *SkipBlank(char *p)
{
	while (*p != 0) {
		if (*p != ' ' && *p != '\t')
			break;
		p++;
	}
	return p;
}


static int StrGetInt(char *p)
{
	int result;
	int c;

	result = -1;
	p = SkipBlank(p);
	while (*p != 0) {
		c = *p;
		if (c < '0' || c > '9')
			break;
		p++;
		if (result < 0)
			result = 0;
		result = result * 10 + c - '0';
	}
	return result;
}

static char *StrStrLower(char *buf, char *tag)
{
	int taglen;
	int buflen;
	int i;
	int j;
	int c0;
	int c1;
	char *src;
	char *dst;

	taglen = strlen(tag);
	buflen = strlen(buf);
	if (buflen < taglen)
		return NULL;
	for (i = 0; i < buflen - taglen + 1; i++) {
		src = buf;
		dst = tag;
		for (j = 0; j < taglen; j++) {
			c0 = *src++;
			c0 = tolower(c0);
			c1 = *dst++;
			c1 = tolower(c1);
			if (c0 != c1)
				break;
		}
		if (j >= taglen)
			return buf;
		buf++;
	}
	return NULL;
}

static int StrScanInt(char *org, char *tag)
{
	int result;
	char *p;

	p = StrStrLower(org, tag);
	if (p == NULL)
		return -1;
	p += strlen(tag);
	result = StrGetInt(p);
	return result;
}

static int StrScanStr(char *org, char *tag, char *buf, int buflen)
{
	int result;
	int i;
	int c;
	char *p;

	p = StrStrLower(org, tag);
	*buf = 0;
	if (p == NULL)
		return -1;
	p += strlen(tag);
	p = SkipBlank(p);
	for (i = 0; i < buflen - 1; i++) {
		c = *p++;
		if (c == 0 || c == '\r')
			break;
		if (c == '\n')
			break;
		buf[i] = c;
	}
	buf[i] = 0;
	result = strlen(buf);
	return result;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/netmgr", NetMgrIcyOpenDirect);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/netmgr", NetMgrIcyOpen);

static int NetMgrIcyCloseDirect(ICY_PARAM *p)
{
	if (p->s > 0) {
		sceNetInetClose(p->s);
		p->s = -1;
	}
	return 0;
}

int NetMgrIcyClose(int fd)
{
	ICY_PARAM *p;

	p = (ICY_PARAM *)fd;
	if (fd <= 0) {
		printf("NetMgrIcyClose: error illigal fd %08x\n", fd);
		return -1;
	}
	NetMgrIcyCloseDirect(p);
	free(p->uri);
	free(p);
	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/netmgr", NetMgrIcyRead);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mp3/netmgr", NetMgrIcySeek);
