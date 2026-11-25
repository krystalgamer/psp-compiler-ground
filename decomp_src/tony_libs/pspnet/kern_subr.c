/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

void _sce_pspnet_microtime(struct timeval *tv)
{
	SceUInt64 t = sceKernelGetSystemTimeWide();

	tv->tv_sec = t / 1000000;
	tv->tv_usec = t % 1000000;
}

int _sce_pspnet_uiomove(char *cp, int n, struct uio *uio)
{
	struct iovec *iov;
	unsigned int cnt;

	while (n > 0 && uio->uio_resid) {
		iov = uio->uio_iov;
		cnt = iov->iov_len;
		if (cnt == 0) {
			uio->uio_iov++;
			uio->uio_iovcnt--;
			continue;
		}
		if (cnt > n)
			cnt = n;
		if (uio->uio_rw == 0)
			bcopy(cp, iov->iov_base, cnt);
		else
			bcopy(iov->iov_base, cp, cnt);
		iov->iov_base += cnt;
		iov->iov_len -= cnt;
		uio->uio_resid -= cnt;
		uio->uio_offset += cnt;
		n -= cnt;
		cp += cnt;
	}
	return 0;
}

void *_sce_pspnet_hashinit(int elements, unsigned int *hashmask)
{
	int hashsize;
	void **hashtbl;
	int i;

	for (hashsize = 1; hashsize < elements; hashsize <<= 1)
		;
	hashtbl = sceNetMallocInternal(hashsize * sizeof(*hashtbl));
	if (hashtbl == NULL)
		return NULL;
	for (i = 0; i < hashsize; i++)
		hashtbl[i] = NULL;
	*hashmask = hashsize - 1;
	return hashtbl;
}

void _sce_pspnet_hashdone(void *hashtbl)
{
	sceNetFreeInternal(hashtbl);
}

void _sce_pspnet_selrecord(struct thread_info *selector, struct selinfo *sip)
{
	sip->si_pid = selector->thid;
}

void _sce_pspnet_selwakeup(struct selinfo *sip)
{
	if (sip->si_pid == 0)
		return;
	_sce_pspnet_tiwakeup(sip->si_pid, &D_0000B8DC);
	sip->si_pid = 0;
}

int *_sce_pspnet_get_selwait_addr(void)
{
	return &D_0000B8DC;
}
