/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

int sceNetAdhocPtpOpen(struct SceNetEtherAddr *saddr, u_short sport, struct SceNetEtherAddr *daddr, u_short dport, unsigned int bufsize, unsigned int rexmt_int, int rexmt_cnt, int flag)
{
	struct adhoc_socket *so;
	int s;
	int ret;

	if (saddr == NULL || daddr == NULL)
		return 0x80410711;
	ret = 0x80410712;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0)
		goto out;
	if ((ret = func_000038C4(saddr, sport, bufsize, bufsize, rexmt_int, rexmt_cnt, &so)) < 0)
		goto out;
	if ((ret = func_0000556C(so->pcb, daddr, dport)) < 0) {
		func_000039FC(so);
		goto out;
	}
	ret = so->id;
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocPtpConnect(int id, unsigned int timeout, int flag)
{
	struct thread_info *ti;
	struct adhoc_socket *so;
	int s;
	int ret;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(2, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	POLL_LINK(so, ti);
	ret = func_00003A34(so, timeout, flag);
	POLL_UNLINK(so, ti);
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00004B18(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}

int sceNetAdhocPtpListen(struct SceNetEtherAddr *saddr, u_short sport, unsigned int bufsize, unsigned int rexmt_int, int rexmt_cnt, int backlog, int flag)
{
	struct adhoc_socket *so;
	int s;
	int ret;

	if (saddr == NULL)
		return 0x80410711;
	ret = 0x80410712;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0)
		goto out;
	if ((ret = func_000038C4(saddr, sport, bufsize, bufsize, rexmt_int, rexmt_cnt, &so)) < 0)
		goto out;
	if ((ret = func_000056B0(so->pcb, backlog)) < 0) {
		func_000039FC(so);
		goto out;
	}
	ret = so->id;
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocPtpAccept(int id, struct SceNetEtherAddr *addr, u_short *port, unsigned int timeout, int flag)
{
	struct thread_info *ti;
	struct adhoc_socket *so;
	int s;
	int ret;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(2, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	POLL_LINK(so, ti);
	ret = func_00003C00(so, addr, port, timeout, flag);
	POLL_UNLINK(so, ti);
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00004B18(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}

int sceNetAdhocPtpSend(int id, void *data, int *len, unsigned int timeout, int flag)
{
	struct thread_info *ti;
	struct adhoc_socket *so;
	int s;
	int ret;

	if (len == NULL)
		return 0x80410711;
	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(2, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	ret = 0x8041070B;
	if (!(so->flags & 0xC000))
		goto out;
	POLL_LINK(so, ti);
	ret = func_00003EF4(so, data, len, timeout, flag);
	POLL_UNLINK(so, ti);
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00004B18(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}

int sceNetAdhocPtpRecv(int id, void *buf, int *len, unsigned int timeout, int flag)
{
	struct thread_info *ti;
	struct adhoc_socket *so;
	int s;
	int ret;

	if (buf == NULL || len == NULL)
		return 0x80410711;
	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(2, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	ret = 0x8041070B;
	if (!(so->flags & 0xC000))
		goto out;
	POLL_LINK(so, ti);
	ret = func_000042B0(so, buf, len, timeout, flag);
	POLL_UNLINK(so, ti);
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00004B18(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}

int sceNetAdhocPtpFlush(int id, unsigned int timeout, int flag)
{
	struct thread_info *ti;
	struct adhoc_socket *so;
	int s;
	int ret;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return 0x80410002;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	so = func_00000DFC(2, id);
	ret = 0x80410701;
	if (so == NULL)
		goto out;
	ret = 0x8041070B;
	if (!(so->flags & 0xC000))
		goto out;
	POLL_LINK(so, ti);
	ret = func_000045E4(so, timeout, flag);
	POLL_UNLINK(so, ti);
	if (so->flags & 1) {
		if (so->pollq == NULL) {
			func_00004B18(so);
			func_00000F74(so);
		}
		ret = 0x80410707;
	}
out:
	_sce_pspnet_splunlock(s);
	_sce_pspnet_thread_leave(ti, 0);
	return ret;
}

int sceNetAdhocPtpClose(int id, int flag)
{
	struct adhoc_socket *so;
	int s;
	int ret;

	ret = 0;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0) {
		ret = 0x80410712;
		goto out;
	}
	so = func_00000DFC(2, id);
	if (so == NULL) {
		ret = 0x80410701;
		goto out;
	}
	func_00004F50(so->pcb);
	func_000056D4(so->pcb);
	so->flags |= 1;
	so->id = -1;
	if (so->pollq == NULL) {
		func_00004B18(so);
		func_00000F74(so);
	}
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int func_000038C4(struct SceNetEtherAddr *saddr, u_short sport, u_int sndbuf, u_int rcvbuf, u_int rexmt_int, int rexmt_cnt, struct adhoc_socket **sop)
{
	struct adhoc_socket *so;
	int id;
	int ret;

	id = func_00000E44();
	if (id < 0)
		return 0x8041070F;
	if ((ret = func_00000ED0(2, &so)) < 0)
		return ret;
	if ((ret = func_0000548C(so)) < 0)
		goto err1;
	if ((ret = func_00005544(so->pcb, sndbuf, rcvbuf)) < 0)
		goto err2;
	if ((ret = func_00004918(so->pcb, saddr, sport)) < 0)
		goto err3;
	func_00005560(so->pcb, rexmt_int, rexmt_cnt);
	so->id = id;
	*sop = so;
	return 0;
err3:
	func_00004B64(so->pcb);
err2:
	func_00004B18(so);
err1:
	func_00000F74(so);
	return ret;
}

void func_000039FC(struct adhoc_socket *so)
{
	func_00004B64(so->pcb);
	func_00004B18(so);
	func_00000F74(so);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp_api", func_00003A34);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp_api", func_00003C00);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp_api", func_00003EF4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/ptp_api", func_000042B0);

int func_000045E4(struct adhoc_socket *so, unsigned int timeout, int flag)
{
	struct ptpcb *pcb;
	SceUInt64 start, now;
	unsigned int usec;
	int error;
	int ret;

	pcb = so->pcb;
	start = 0;
	while (pcb->snd.sb_cc != 0) {
		ret = 0x8041070C;
		if (so->flags & 0x8000)
			goto out;
		ret = 0x80410708;
		if (so->flags & 0x200)
			goto out;
		ret = 0x80410709;
		if (flag & 1)
			goto out;
		usec = 0;
		if (timeout != 0) {
			if (start == 0)
				start = sceKernelGetSystemTimeWide();
			now = sceKernelGetSystemTimeWide();
			if (now - start >= timeout) {
				ret = 0x80410715;
				goto out;
			}
			usec = timeout - (now - start);
		}
		pcb->snd.sb_flags |= 1;
		error = _sce_pspnet_tsleep_usec(&pcb->snd, usec);
		if (so->flags & 0x200)
			error = 5;
		if (so->flags & 1)
			error = 0x20;
		if (error != 0) {
			switch (error) {
			case 11:
				error = 0x80410715;
				break;
			case 4:
				error = 0x80410719;
				break;
			case 5:
				error = 0x80410708;
				break;
			case 0x20:
				error = 0x80410707;
				break;
			default:
				error = 0x80410002;
				break;
			}
			ret = error;
			goto out;
		}
	}
	ret = 0;
out:
	return ret;
}

void sceNetAdhoc_lib_62B875A8(void)
{
	memset(&D_00007450, 0, sizeof(D_00007450));
}

int sceNetAdhoc_lib_2CA12790(struct ptpstat *st)
{
	if (st == NULL)
		return 0x80410711;
	*st = D_00007450;
	return 0;
}
