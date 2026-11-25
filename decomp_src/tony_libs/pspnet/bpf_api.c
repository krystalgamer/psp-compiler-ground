/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf_api", sceNetBpfPoll);

int sceNetBpfOpen(void)
{
	struct thread_info *ti;
	int error;
	int fd = 0;
	int i = 0;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
again:
	error = func_000042AC(i);
	if (error == 0)
		fd = i;
	else if (error == 16) {
		i++;
		goto again;
	}
	if (_sce_pspnet_thread_leave(ti, error) < 0)
		return -1;
	return fd;
}

int sceNetBpfClose(int fd)
{
	struct thread_info *ti;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	return _sce_pspnet_thread_leave(ti, func_00004318(fd));
}

int sceNetBpfRead(int fd, void *buf, int len)
{
	struct thread_info *ti;
	struct uio uio;
	struct iovec iov;
	int error, ret;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	uio.uio_iov = &iov;
	uio.uio_iovcnt = 1;
	iov.iov_base = buf;
	uio.uio_rw = 0;
	uio.uio_offset = 0;
	uio.uio_resid = len;
	iov.iov_len = len;
	error = func_000037D4(fd, &uio);
	ret = len - uio.uio_resid;
	if (_sce_pspnet_thread_leave(ti, error) < 0)
		return -1;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf_api", sceNetBpfWrite);

int sceNetBpfIoctl(int fd, unsigned int cmd, void *data)
{
	struct thread_info *ti;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	return _sce_pspnet_thread_leave(ti, func_00003B20(fd, cmd, data));
}
