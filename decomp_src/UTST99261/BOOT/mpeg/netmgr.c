#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdlib.h>
#include <string.h>
#include <libhttp.h>

typedef struct {
	int tmpl;
	int connection;
	int request;
	int length;
	int curofst;
	int buf_top;
	int buf_size;
	char *uri;
	unsigned char recv_buf[1500];
} HTTP_PARAM;

#define NetMgrHttpRewind NetMgrHttpRewind_84AC

SceSSize NetMgrHttpRead(SceUID fd, void *buff, SceSize size);

static int NetMgrHttpRewind(int fd)
{
	HTTP_PARAM *p;
	int status_code;
	int ret;
	int error_num;
	SceInt64 content_length;

	p = (HTTP_PARAM *)fd;
	if (fd <= 0)
		return -1;

	p->curofst = 0;
	p->length = 0;
	p->buf_top = 0;
	p->buf_size = 0;

	if (p->request > 0) {
		sceHttpAbortRequest(p->request);
		sceHttpDeleteRequest(p->request);
	}
	if (p->connection > 0)
		sceHttpDeleteConnection(p->connection);

	p->connection = sceHttpCreateConnectionWithURL(p->tmpl, p->uri, 1);
	if (p->connection < 0)
		return -1;
	p->request = sceHttpCreateRequestWithURL(p->connection, 0, p->uri, 0);
	if (p->request < 0)
		return -1;

	ret = sceHttpSendRequest(p->request, NULL, 0);
	if (ret < 0) {
		if (ret == 0x80431063)
			ret = sceHttpGetNetworkErrno(p->request, &error_num);
		return ret;
	}
	ret = sceHttpGetStatusCode(p->request, &status_code);
	if (ret < 0)
		return ret;
	if (status_code != 200)
		return -1;
	sceHttpGetContentLength(p->request, &content_length);
	p->length = content_length;
	return 0;
}

int NetMgrHttpOpen(const char *uri, int flag, SceMode mode)
{
	HTTP_PARAM *p;
	int ret;

	p = malloc(sizeof(HTTP_PARAM));
	if (p == NULL)
		return -1;
	memset(p, 0, sizeof(HTTP_PARAM));
	p->uri = strdup(uri);
	p->tmpl = ret = sceHttpCreateTemplate("PSPHTTP-Test/0.1 libhttp/0.9", 0, 1);
	if (ret < 0) {
		free(p->uri);
		free(p);
		return -1;
	}
	sceHttpDisableCache(p->tmpl);
	NetMgrHttpRewind((int)p);
	return (int)p;
}

SceSSize NetMgrHttpRead(SceUID fd, void *buff, SceSize size)
{
	int readsize;
	int error_num;
	int cursize;
	int i;
	int ret;
	HTTP_PARAM *p;
	char *dst;

	p = (HTTP_PARAM *)fd;
	if (fd <= 0)
		return -1;

	dst = buff;
	cursize = 0;
	while (size != 0 && p->curofst < p->length) {
		if (p->buf_top >= p->buf_size) {
			ret = sceHttpReadData(p->request, p->recv_buf, sizeof(p->recv_buf));
			if (ret < 0) {
				if (ret == 0x80431063)
					ret = sceHttpGetNetworkErrno(p->request, &error_num);
				return ret;
			}
			p->buf_top = 0;
			p->buf_size = ret;
			if (ret == 0)
				break;
		}
		readsize = p->buf_size - p->buf_top;
		if (size < readsize)
			readsize = size;
		if (dst != NULL) {
			for (i = 0; i < readsize; i++)
				*dst++ = p->recv_buf[p->buf_top + i];
		}
		p->buf_top += readsize;
		p->curofst += readsize;
		size -= readsize;
		cursize += readsize;
	}
	return cursize;
}

SceOff NetMgrHttpSeek(int fd, SceOff offset, SceInt32 whence)
{
	HTTP_PARAM *p;

	p = (HTTP_PARAM *)fd;
	if (fd <= 0)
		return -1;

	switch (whence) {
	case 1:
		offset += p->curofst;
		break;
	case 2:
		offset = p->length - offset;
		break;
	}
	if (offset < p->curofst)
		NetMgrHttpRewind(fd);
	if (offset < p->length) {
		NetMgrHttpRead(fd, NULL, offset - p->curofst);
	} else {
		p->curofst = p->length;
		p->buf_top = 0;
		p->buf_size = 0;
	}
	return p->curofst;
}

int NetMgrHttpClose(int fd)
{
	HTTP_PARAM *p;
	int ret = -1;

	p = (HTTP_PARAM *)fd;
	if (fd > 0) {
		if (p->request > 0)
			sceHttpDeleteRequest(p->request);
		if (p->connection > 0)
			sceHttpDeleteConnection(p->connection);
		if (p->tmpl > 0)
			sceHttpDeleteTemplate(p->tmpl);
		free(p->uri);
		free(p);
		ret = 0;
	}
	return ret;
}
