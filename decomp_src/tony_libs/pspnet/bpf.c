/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf", func_000037D4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf", func_00003940);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf", func_00003B20);

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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf", func_00003FA4);

void func_000040D8(struct bpf_d *d, struct bpf_stat4 *out)
{
	*out = *(struct bpf_stat4 *)&d->bd_hlen;
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

	for (i = 0, d = D_0000B8E4; i < 8; ++i, ++d) {
		if (d != d->bd_next && d->bd_bif != NULL && d->bd_bif->bif_ifp == ifp) {
			s = _sce_pspnet_spllock();
			bpf_detachd(d);
			_sce_pspnet_splunlock(s);
		}
	}
	for (bp = D_0000B8E0, pbp = &D_0000B8E0; bp != NULL; pbp = &bp->bif_next, bp = bp->bif_next) {
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

	D_0000A0A8 = 0x2000;
	D_0000B8E0 = NULL;
	for (i = 0; i < 8; i++)
		D_0000B8E4[i].bd_next = &D_0000B8E4[i];
}

int func_000042AC(u_int unit)
{
	struct bpf_d *d;

	if (unit >= 8)
		return 6;
	d = &D_0000B8E4[unit];
	if (d != d->bd_next)
		return 16;
	memset(d, 0, sizeof(*d));
	d->bd_bufsize = D_0000A0A8;
	return 0;
}

int func_00004318(int unit)
{
	struct bpf_d *d = &D_0000B8E4[unit];
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
	struct bpf_d *d = &D_0000B8E4[unit];
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
	bp->bif_next = D_0000B8E0;
	D_0000B8E0 = bp;
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
