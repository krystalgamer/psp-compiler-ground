/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

int func_000037D4(int unit, struct uio *uio)
{
	struct bpf_d *d = &bpf_dtab[unit];
	int error;
	int s;

	if (uio->uio_resid != d->bd_bufsize)
		return 22;
	s = _sce_pspnet_spllock();
	while (d->bd_hbuf == NULL) {
		if (d->bd_immediate) {
			if (d->bd_slen == 0) {
				_sce_pspnet_splunlock(s);
				return 11;
			}
			ROTATE_BUFFERS(d);
			break;
		}
		if (d->bd_rtout != -1)
			error = _sce_pspnet_tsleep(d, d->bd_rtout);
		else
			error = 11;
		if (error == 11) {
			if (d->bd_hbuf)
				break;
			if (d->bd_slen == 0) {
				_sce_pspnet_splunlock(s);
				return 0;
			}
			ROTATE_BUFFERS(d);
			break;
		}
		if (error != 0)
			goto done;
	}
	_sce_pspnet_splunlock(s);
	error = _sce_pspnet_uiomove(d->bd_hbuf, d->bd_hlen, uio);
	s = _sce_pspnet_spllock();
	d->bd_fbuf = d->bd_hbuf;
	d->bd_hbuf = NULL;
	d->bd_hlen = 0;
done:
	_sce_pspnet_splunlock(s);
	return error;
}

int func_00003940(int unit, struct uio *uio)
{
	struct bpf_d *d = &bpf_dtab[unit];
	struct ifnet *ifp;
	struct mbuf *m;
	int error, s;
	int len;

	if (d->bd_bif == NULL)
		return 6;
	ifp = d->bd_bif->bif_ifp;
	len = uio->uio_resid;
	if (len == 0)
		return 0;
	m = sceNetMallocInternal(MSIZE);
	if (m == NULL)
		return 105;
	m->m_type = 1;
	m->m_next = NULL;
	m->m_nextpkt = NULL;
	m->m_data = m->m_pktdat;
	m->m_flags = 2;
	m->m_pkthdr.aux = NULL;
	m->m_pkthdr.rcvif = NULL;
	m->m_pkthdr.len = len;
	if (len > MHLEN) {
		m->m_ext.ext_buf = sceNetMallocInternal(2048);
		if (m->m_ext.ext_buf == NULL)
			m->m_ext.ext_buf = sceNetMallocInternal(2048);
		if (m->m_ext.ext_buf != NULL) {
			m->m_data = m->m_ext.ext_buf;
			m->m_flags |= 9;
			m->m_ext.ext_size = 2048;
			m->m_ext.ext_free = NULL;
			m->m_ext.ext_arg = NULL;
			m->m_ext.ext_nextref = m->m_ext.ext_prevref = m;
		}
		if ((m->m_flags & 1) == 0) {
			error = 105;
			goto bad;
		}
	}
	error = _sce_pspnet_uiomove(m->m_data, len, uio);
	if (error)
		goto bad;
	m->m_len = len;
	s = _sce_pspnet_spllock();
	if (ifp->if_snd.ifq_len >= ifp->if_snd.ifq_maxlen) {
		error = 105;
		_sce_pspnet_splunlock(s);
		goto bad;
	}
	ifp->if_obytes += m->m_pkthdr.len;
	m->m_nextpkt = NULL;
	if (ifp->if_snd.ifq_tail == NULL)
		ifp->if_snd.ifq_head = m;
	else
		ifp->if_snd.ifq_tail->m_nextpkt = m;
	ifp->if_snd.ifq_tail = m;
	ifp->if_snd.ifq_len++;
	if ((ifp->if_flags & 0x400) == 0)
		(*ifp->if_start)(ifp);
	_sce_pspnet_splunlock(s);
	return 0;
bad:
	sceNetMFreem(m);
	return error;
}

int func_00003B20(int unit, u_long cmd, void *addr)
{
	struct bpf_d *d = &bpf_dtab[unit];
	int s, error = 0;

	switch (cmd) {
	default:
		error = 22;
		break;
	case 0x4004667F: {
		int n;

		s = _sce_pspnet_spllock();
		n = d->bd_slen;
		if (d->bd_hbuf)
			n += d->bd_hlen;
		_sce_pspnet_splunlock(s);
		*(int *)addr = n;
		break;
	}
	case 0x40044266:
		*(u_int *)addr = d->bd_bufsize;
		break;
	case 0xC0044266:
		if (d->bd_bif != NULL)
			error = 22;
		else {
			u_int size = *(u_int *)addr;

			if (size > 0x8000)
				*(u_int *)addr = size = 0x8000;
			else if (size < 32)
				*(u_int *)addr = size = 32;
			d->bd_bufsize = size;
		}
		break;
	case 0x80084267:
		error = func_00003E80(d, (struct bpf_program *)addr);
		break;
	case 0x20004268:
		s = _sce_pspnet_spllock();
		bpf_reset_d(d);
		_sce_pspnet_splunlock(s);
		break;
	case 0x4004426A:
		if (d->bd_bif == NULL)
			error = 22;
		else
			*(u_int *)addr = d->bd_bif->bif_dlt;
		break;
	case 0x4020426B:
		if (d->bd_bif == NULL)
			error = 22;
		else
			func_000040D8(d->bd_bif->bif_ifp, (struct ifreq *)addr);
		break;
	case 0x8020426C:
		error = func_00003FA4(d, (struct ifreq *)addr);
		break;
	case 0x8008426D: {
		struct timeval *tv = (struct timeval *)addr;

		d->bd_rtout = tv->tv_sec * 100 + tv->tv_usec / 10000U;
		if ((d->bd_rtout == 0) && (tv->tv_usec != 0))
			d->bd_rtout = 1;
		break;
	}
	case 0x4008426E: {
		struct timeval *tv = (struct timeval *)addr;

		tv->tv_sec = d->bd_rtout / 100;
		tv->tv_usec = (d->bd_rtout % 100) * 10000;
		break;
	}
	case 0x4008426F: {
		struct bpf_stat *bs = (struct bpf_stat *)addr;

		bs->bs_recv = d->bd_rcount;
		bs->bs_drop = d->bd_dcount;
		break;
	}
	case 0x80044270:
		d->bd_immediate = *(u_int *)addr;
		break;
	case 0x40044271: {
		struct bpf_version *bv = (struct bpf_version *)addr;

		bv->bv_major = 1;
		bv->bv_minor = 1;
		break;
	}
	case 0x40044274:
		*(u_int *)addr = d->bd_hdrcmplt;
		break;
	case 0x80044275:
		d->bd_hdrcmplt = *(u_int *)addr ? 1 : 0;
		break;
	case 0x8004667E:
		if (*(int *)addr)
			d->bd_rtout = -1;
		else
			d->bd_rtout = 0;
		break;
	}
	return error;
}

int func_00003E80(struct bpf_d *d, struct bpf_program *fp)
{
	void *fcode, *old;
	u_int flen, size;
	int s;

	old = d->bd_filter;
	if (fp->bf_insns == NULL) {
		if (fp->bf_len != 0)
			return 22;
		s = _sce_pspnet_spllock();
		d->bd_filter = NULL;
		bpf_reset_d(d);
		_sce_pspnet_splunlock(s);
		if (old != NULL)
			sceNetFreeInternal(old);
		return 0;
	}
	flen = fp->bf_len;
	if (flen > 512)
		return 22;
	size = flen * 8;
	fcode = sceNetMallocInternal(size);
	if (fcode == NULL)
		return 12;
	bcopy(fp->bf_insns, fcode, size);
	if (func_00004CC8(fcode, (int)flen)) {
		s = _sce_pspnet_spllock();
		d->bd_filter = fcode;
		bpf_reset_d(d);
		_sce_pspnet_splunlock(s);
		if (old != NULL)
			sceNetFreeInternal(old);
		return 0;
	}
	sceNetFreeInternal(fcode);
	return 22;
}

int func_00003FA4(struct bpf_d *d, struct ifreq *ifr)
{
	struct bpf_if *bp;
	struct ifnet *ifp;
	int s, error;

	for (bp = bpf_iflist; bp != NULL; bp = bp->bif_next) {
		ifp = bp->bif_ifp;
		if (ifp == NULL || strcmp(ifp->if_xname, ifr->ifr_name) != 0)
			continue;
		if (d->bd_sbuf == NULL) {
			error = func_000040FC(d);
			if (error != 0)
				return error;
		}
		s = _sce_pspnet_spllock();
		if (bp != d->bd_bif) {
			if (d->bd_bif)
				bpf_detachd(d);
			d->bd_bif = bp;
			d->bd_next = bp->bif_dlist;
			bp->bif_dlist = d;
			*bp->bif_driverp = bp;
		}
		bpf_reset_d(d);
		_sce_pspnet_splunlock(s);
		return 0;
	}
	return 6;
}

void func_000040D8(struct ifnet *ifp, struct ifreq *ifr)
{
	memcpy(ifr->ifr_name, ifp->if_xname, 16);
}

int func_000040FC(struct bpf_d *d)
{
	d->bd_fbuf = sceNetMallocInternal(d->bd_bufsize);
	if (d->bd_fbuf == NULL)
		return 12;
	d->bd_sbuf = sceNetMallocInternal(d->bd_bufsize);
	if (d->bd_sbuf == NULL) {
		sceNetFreeInternal(d->bd_fbuf);
		return 12;
	}
	d->bd_slen = 0;
	d->bd_hlen = 0;
	return 0;
}

void func_00004160(struct ifnet *ifp)
{
	struct bpf_if *bp, **pbp;
	struct bpf_d *d;
	int i, s;

	for (i = 0, d = bpf_dtab; i < 8; ++i, ++d) {
		if (d != d->bd_next && d->bd_bif != NULL && d->bd_bif->bif_ifp == ifp) {
			s = _sce_pspnet_spllock();
			bpf_detachd(d);
			_sce_pspnet_splunlock(s);
		}
	}
	for (bp = bpf_iflist, pbp = &bpf_iflist; bp != NULL; pbp = &bp->bif_next, bp = bp->bif_next) {
		if (bp->bif_ifp == ifp) {
			*pbp = bp->bif_next;
			sceNetFreeInternal(bp);
			break;
		}
	}
}

void func_0000426C(int n)
{
	int i;

	bpf_bufsize = 0x2000;
	bpf_iflist = NULL;
	for (i = 0; i < 8; i++)
		bpf_dtab[i].bd_next = &bpf_dtab[i];
}

int func_000042AC(u_int unit)
{
	struct bpf_d *d;

	if (unit >= 8)
		return 6;
	d = &bpf_dtab[unit];
	if (d != d->bd_next)
		return 16;
	memset(d, 0, sizeof(*d));
	d->bd_bufsize = bpf_bufsize;
	return 0;
}

int func_00004318(int unit)
{
	struct bpf_d *d = &bpf_dtab[unit];
	int s;

	s = _sce_pspnet_spllock();
	if (d->bd_bif)
		bpf_detachd(d);
	_sce_pspnet_splunlock(s);
	if (d->bd_sbuf != NULL) {
		sceNetFreeInternal(d->bd_sbuf);
		if (d->bd_hbuf != NULL)
			sceNetFreeInternal(d->bd_hbuf);
		if (d->bd_fbuf != NULL)
			sceNetFreeInternal(d->bd_fbuf);
	}
	if (d->bd_filter)
		sceNetFreeInternal(d->bd_filter);
	d->bd_next = d;
	return 0;
}

int func_00004410(int unit, int events, struct thread_info *p)
{
	struct bpf_d *d = &bpf_dtab[unit];
	int revents = 0;
	int s;

	s = _sce_pspnet_spllock();
	if (events & 0x41) {
		if (d->bd_hlen != 0 || (d->bd_immediate && d->bd_slen != 0))
			revents |= events & 0x41;
		else
			_sce_pspnet_selrecord(p, &d->bd_sel);
	}
	_sce_pspnet_splunlock(s);
	return revents;
}

void func_000044C0(struct bpf_if *bp, struct mbuf *m)
{
	struct bpf_d *d;
	u_int pktlen, slen;
	struct mbuf *m0;
	int s;

	pktlen = 0;
	for (m0 = m; m0 != NULL; m0 = m0->m_next)
		pktlen += m0->m_len;
	s = _sce_pspnet_spllock();
	for (d = bp->bif_dlist; d != NULL; d = d->bd_next) {
		++d->bd_rcount;
		slen = func_000047EC(d->bd_filter, (u_char *)m, pktlen, 0);
		if (slen != 0)
			func_000046A0(d, (u_char *)m, pktlen, slen, func_00004618);
	}
	_sce_pspnet_splunlock(s);
}

void func_00004594(struct bpf_if **driverp, struct ifnet *ifp, u_int dlt, u_int hdrlen)
{
	struct bpf_if *bp;

	bp = sceNetMallocInternal(sizeof(*bp));
	bp->bif_dlist = NULL;
	bp->bif_driverp = driverp;
	bp->bif_ifp = ifp;
	bp->bif_dlt = dlt;
	bp->bif_next = bpf_iflist;
	bpf_iflist = bp;
	*bp->bif_driverp = NULL;
	bp->bif_hdrlen = ((hdrlen + 0x14 + 3) & ~3) - hdrlen;
}

void *func_00004618(void *dst_arg, const void *src_arg, u_int len)
{
	const struct mbuf *m;
	u_int count;
	u_char *dst;

	m = src_arg;
	dst = dst_arg;
	while (len > 0) {
		count = umin(m->m_len, len);
		memcpy(dst, m->m_data, count);
		m = m->m_next;
		dst += count;
		len -= count;
	}
	return dst_arg;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf", func_000046A0);
