/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define sockargs func_000070E8
#define sceNet_ioctl sceNetInet_lib_AEE60F84
#define sceNet_sysctl sceNetInet_lib_B3FF98EB
int net_sysctl(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen);
#define sendit func_000063F0
#define recvit func_0000678C
struct msghdr {
	void *msg_name;
	socklen_t msg_namelen;
	struct iovec *msg_iov;
	int msg_iovlen;
	void *msg_control;
	socklen_t msg_controllen;
	int msg_flags;
};
typedef int ssize_t;
#define UIO_READ 0
#define UIO_WRITE 1
#define UIO_SMALLIOV 8
#define IOV_MAX 1024
#define SSIZE_MAX 0x7fffffff
#define ALIGN(p) (((u_int)(p) + 3) & ~3)
int sockargs(struct mbuf **mp, const void *buf, int buflen, int type);
void _sce_pspnet_inet_sabort(struct socket *so);
typedef unsigned long long u_int64_t;
u_int64_t sceKernelGetSystemTimeWide(void);
void *_sce_pspnet_get_selwait_addr(void);
int _sce_pspnet_tsleep_usec(void *chan, u_int usec);
typedef int32_t fd_mask;
#define NFDBITS 32
#define FD_SETSIZE 256
#define howmany(x, y) (((x) + ((y) - 1)) / (y))
typedef struct fd_set { fd_mask fds_bits[howmany(FD_SETSIZE, NFDBITS)]; } fd_set;
#define selscan func_00007554
#define selattach func_000076C4
#define seldetach func_000076E0
#define selthread func_00008588
#define selflag D_0002E484
extern int selflag[3];
int selscan(struct thread_info *ti, fd_mask *ibitp, fd_mask *obitp, int nfd, int *retval);
void selattach(struct thread_info *ti, fd_mask *ibitp, int nfd);
void seldetach(struct thread_info *ti, fd_mask *ibitp, int nfd);
void selthread(struct thread_info *ti, fd_mask *ibitp, int nfd, int op);
struct pollfd {
	int fd;
	short events;
	short revents;
};
#define POLLERR 0x0008
#define POLLHUP 0x0010
#define POLLNVAL 0x0020
#define INFTIM -1
#define pollscan func_00007964
#define pollattach func_00007A14
#define polldetach func_00007A8C
int pollscan(struct thread_info *ti, struct pollfd *fds, int nfd, int *retval);
void pollattach(struct thread_info *ti, struct pollfd *fds, int nfd);
void polldetach(struct thread_info *ti, struct pollfd *fds, int nfd);
#define IOCPARM_MASK 0x1fff
#define IOCPARM_LEN(x) (((x) >> 16) & IOCPARM_MASK)
#define IOC_VOID 0x20000000
#define IOC_OUT 0x40000000
#define IOC_IN 0x80000000
#define CTL_MAXNAME 12
#define CTL_NET 4

static __inline int
ffs(int mask)
{
	int bit;

	if (mask == 0)
		return (0);
	for (bit = 1; !(mask & 1); bit++)
		mask >>= 1;
	return (bit);
}
int sendit(struct thread_info *ti, int s, struct msghdr *mp, int flags, ssize_t *retsize);
int recvit(struct thread_info *ti, int s, struct msghdr *mp, caddr_t namelenp, ssize_t *retsize);

static __inline void
sothread_attach(struct thread_info *ti, struct socket *so)
{
	so->so_thread = ti;
	so->so_tnext = ti->socks;
	ti->socks = so;
}

static __inline void
sothread_detach(struct thread_info *ti, struct socket *so)
{
	struct socket *p;

	p = ti->socks;
	so->so_thread = NULL;
	if (p == so)
		ti->socks = p->so_tnext;
	else {
		for (; p != NULL && p->so_tnext != so; p = p->so_tnext)
			;
		if (p != NULL)
			p->so_tnext = so->so_tnext;
	}
}

static __inline void
sothread_detach2(struct thread_info *ti, struct socket *so)
{
	struct socket *p;

	so->so_thread = NULL;
	p = ti->socks;
	if (p == so)
		ti->socks = p->so_tnext;
	else {
		for (; p != NULL; p = p->so_tnext) {
			if (p->so_tnext == so) {
				p->so_tnext = so->so_tnext;
				break;
			}
		}
	}
}

__attribute__((noinline)) int
sceNetInetSocket(int domain, int type, int protocol)
{
	struct thread_info *ti;
	struct socket *so;
	int s, fd, error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	s = _sce_pspnet_spllock();
	error = EMFILE;
	if ((fd = sofdalloc()) < 0)
		goto out;
	error = socreate(domain, &so, type, protocol);
	if (error)
		goto out;
	so->so_fd = fd;
out:
	_sce_pspnet_splunlock(s);
	if (_sce_pspnet_thread_leave(ti, error) < 0)
		return -1;
	return so->so_fd;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_syscalls", sceNetInetAccept);

int
sceNetInetConnect(int s, const struct sockaddr *name, socklen_t namelen)
{
	struct thread_info *ti;
	struct socket *so;
	struct mbuf *nam;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	if ((so->so_state & SS_NBIO) && (so->so_state & SS_ISCONNECTING)) {
		error = EALREADY;
		goto detach;
	}
	error = sockargs(&nam, name, namelen, MT_SONAME);
	if (error)
		goto detach;
	error = soconnect(so, nam);
	if (error)
		goto bad;
	if ((so->so_state & SS_NBIO) && (so->so_state & SS_ISCONNECTING)) {
		m_freem(nam);
		error = EINPROGRESS;
		goto detach;
	}
	s = _sce_pspnet_spllock();
	while ((so->so_state & SS_ISCONNECTING) && so->so_error == 0)
		if ((error = _sce_pspnet_tsleep((caddr_t)&so->so_timeo, 0)) != 0)
			break;
	if (error == 0) {
		error = so->so_error;
		so->so_error = 0;
	}
	_sce_pspnet_splunlock(s);
bad:
	so->so_state &= ~SS_ISCONNECTING;
	m_freem(nam);
detach:
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

ssize_t
sceNetInetSendmsg(int s, const struct msghdr *mp, int flags)
{
	struct thread_info *ti;
	struct msghdr msg;
	struct iovec aiov[UIO_SMALLIOV], *iov;
	ssize_t retsize;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	msg = *mp;
	if ((u_int)msg.msg_iovlen > UIO_SMALLIOV) {
		if ((u_int)msg.msg_iovlen > IOV_MAX) {
			error = EMSGSIZE;
			goto done;
		}
		iov = sceNetMallocInternal(sizeof(struct iovec) * msg.msg_iovlen);
		if (iov == NULL) {
			error = ENOMEM;
			goto done;
		}
	} else
		iov = aiov;
	if (msg.msg_iovlen)
		memcpy(iov, msg.msg_iov,
		    (unsigned)(msg.msg_iovlen * sizeof(struct iovec)));
	msg.msg_iov = iov;
	error = sendit(ti, s, &msg, flags, &retsize);
	if (iov != aiov)
		sceNetFreeInternal(iov);
done:
	if (_sce_pspnet_thread_leave(ti, error) < 0)
		return -1;
	return retsize;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_syscalls", func_000063F0);

ssize_t
sceNetInetRecvmsg(int s, struct msghdr *mp, int flags)
{
	struct thread_info *ti;
	struct msghdr msg;
	struct iovec aiov[UIO_SMALLIOV], *uiov, *iov;
	ssize_t retsize;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	msg = *mp;
	if ((u_int)msg.msg_iovlen > UIO_SMALLIOV) {
		if ((u_int)msg.msg_iovlen > IOV_MAX) {
			error = EMSGSIZE;
			goto done;
		}
		iov = sceNetMallocInternal(sizeof(struct iovec) * msg.msg_iovlen);
		if (iov == NULL) {
			error = ENOMEM;
			goto done;
		}
	} else
		iov = aiov;
	if (msg.msg_iovlen)
		memcpy(iov, msg.msg_iov,
		    (unsigned)(msg.msg_iovlen * sizeof(struct iovec)));
	msg.msg_flags = flags;
	uiov = msg.msg_iov;
	msg.msg_iov = iov;
	if ((error = recvit(ti, s, &msg, (caddr_t)0, &retsize)) == 0) {
		msg.msg_iov = uiov;
		*mp = msg;
	}
	if (iov != aiov)
		sceNetFreeInternal(iov);
done:
	if (_sce_pspnet_thread_leave(ti, error) < 0)
		return -1;
	return retsize;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_syscalls", func_0000678C);

int
sceNetInetSetsockopt(int s, int level, int name, const void *val, socklen_t valsize)
{
	struct thread_info *ti;
	struct socket *so;
	struct mbuf *m = NULL;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	if (valsize > MLEN) {
		error = EINVAL;
		goto detach;
	}
	if (val) {
		m = m_get(M_WAIT, MT_SOOPTS);
		if (m == NULL) {
			error = ENOMEM;
			goto detach;
		}
		bcopy(val, mtod(m, caddr_t), valsize);
		m->m_len = valsize;
	}
	error = sosetopt(so, level, name, m);
detach:
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

int
sceNetInetGetsockopt(int s, int level, int name, void *val, socklen_t *avalsize)
{
	struct thread_info *ti;
	struct socket *so;
	struct mbuf *m = NULL, *m0;
	unsigned int op, i, valsize;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	if (val)
		valsize = *avalsize;
	else
		valsize = 0;
	if ((error = sogetopt(so, level, name, &m)) == 0 && val && valsize &&
	    m != NULL) {
		op = 0;
		while (m && op < valsize) {
			i = min(m->m_len, (valsize - op));
			bcopy(mtod(m, caddr_t), val, i);
			op += i;
			val = ((u_int8_t *)val) + i;
			m0 = m;
			MFREE(m0, m);
		}
		valsize = op;
		if (error == 0)
			*avalsize = valsize;
	}
	if (m != NULL)
		(void) m_free(m);
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

int
sceNetInetGetsockname(int s, struct sockaddr *asa, socklen_t *alen)
{
	struct thread_info *ti;
	struct socket *so;
	struct mbuf *m;
	unsigned int len;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	len = *alen;
	error = ENOMEM;
	m = m_getclr(M_WAIT, MT_SONAME);
	if (m == NULL)
		goto detach;
	error = (*so->so_proto->pr_usrreq)(so, PRU_SOCKADDR, (struct mbuf *)0,
	    m, (struct mbuf *)0);
	if (error)
		goto bad;
	if (len > m->m_len)
		len = m->m_len;
	bcopy(mtod(m, caddr_t), (caddr_t)asa, len);
	*alen = len;
bad:
	m_freem(m);
detach:
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

int
sceNetInetGetpeername(int s, struct sockaddr *asa, socklen_t *alen)
{
	struct thread_info *ti;
	struct socket *so;
	struct mbuf *m;
	unsigned int len;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	if ((so->so_state & (SS_ISCONNECTED|SS_ISCONFIRMING)) == 0) {
		error = ENOTCONN;
		goto detach;
	}
	len = *alen;
	error = ENOMEM;
	m = m_getclr(M_WAIT, MT_SONAME);
	if (m == NULL)
		goto detach;
	error = (*so->so_proto->pr_usrreq)(so, PRU_PEERADDR, (struct mbuf *)0,
	    m, (struct mbuf *)0);
	if (error == 0) {
		if (len > m->m_len)
			len = m->m_len;
		bcopy(mtod(m, caddr_t), (caddr_t)asa, len);
		*alen = len;
	}
	m_freem(m);
detach:
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

int
sockargs(struct mbuf **mp, const void *buf, int buflen, int type)
{
	struct sockaddr *sa;
	struct mbuf *m;

	if (type == MT_SONAME && (u_int)buflen > 255)
		return (EINVAL);
	m = m_get(M_WAIT, type);
	if (m == NULL)
		return (ENOMEM);
	if ((u_int)buflen > MLEN) {
		MEXTMALLOC(m, buflen, M_WAITOK);
		if ((m->m_flags & M_EXT) == 0) {
			m_free(m);
			return (ENOMEM);
		}
	}
	m->m_len = buflen;
	bcopy(buf, mtod(m, caddr_t), buflen);
	*mp = m;
	if (type == MT_SONAME) {
		sa = mtod(m, struct sockaddr *);
		sa->sa_len = buflen;
	}
	return (0);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_syscalls", sceNetInetSelect);

int
selscan(struct thread_info *ti, fd_mask *ibitp, fd_mask *obitp, int nfd, int *retval)
{
	int msk, i, j, fd;
	fd_mask ibits, obits;
	struct socket *so;
	int n = 0;

	for (msk = 0; msk < 3; msk++) {
		for (i = 0; i < nfd; i += NFDBITS) {
			ibits = *ibitp++;
			obits = 0;
			while ((j = ffs(ibits)) && (fd = i + --j) < nfd) {
				ibits &= ~(1 << j);
				so = getsock(fd);
				if (so == NULL)
					return (EBADF);
				if (sopoll(so, selflag[msk], ti)) {
					obits |= (1 << j);
					n++;
				}
			}
			*obitp++ = obits;
		}
	}
	*retval = n;
	return (0);
}

__attribute__((noinline)) void
selattach(struct thread_info *ti, fd_mask *ibitp, int nfd)
{
	selthread(ti, ibitp, nfd, 0);
}

__attribute__((noinline)) void
seldetach(struct thread_info *ti, fd_mask *ibitp, int nfd)
{
	selthread(ti, ibitp, nfd, 1);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_syscalls", sceNetInetPoll);

__attribute__((noinline)) int
pollscan(struct thread_info *ti, struct pollfd *fds, int nfd, int *retval)
{
	int i, n = 0;
	struct socket *so;

	for (i = 0; i < nfd; i++, fds++) {
		so = getsock(fds->fd);
		if (so == NULL) {
			fds->revents = POLLNVAL;
			n++;
		} else {
			fds->revents = sopoll(so, fds->events | POLLERR | POLLHUP, ti);
			if (fds->revents != 0)
				n++;
		}
	}
	*retval = n;
	return (0);
}

__attribute__((noinline)) void
pollattach(struct thread_info *ti, struct pollfd *fds, int nfd)
{
	int i;
	struct socket *so;

	for (i = 0; i < nfd; i++, fds++) {
		so = getsock(fds->fd);
		if (so != NULL && so->so_thread == NULL)
			sothread_attach(ti, so);
	}
}

static __inline void
pollthread(struct thread_info *ti, struct pollfd *fds, int nfd, int op)
{
	int i;
	struct socket *so;

	for (i = 0; i < nfd; i++, fds++) {
		so = getsock(fds->fd);
		if (so == NULL)
			continue;
		if (op == 0) {
			if (so->so_thread == NULL)
				sothread_attach(ti, so);
		} else if (op == 1) {
			if (so->so_thread == ti)
				sothread_detach(ti, so);
		}
	}
}

__attribute__((noinline)) void
polldetach(struct thread_info *ti, struct pollfd *fds, int nfd)
{
	pollthread(ti, fds, nfd, 1);
}

int
sceNet_ioctl(int s, u_long com, caddr_t data)
{
	struct thread_info *ti;
	struct socket *so;
	u_int size;
	caddr_t data2, memp;
	int error;
	char stkbuf[128];

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	size = IOCPARM_LEN(com);
	memp = NULL;
	data2 = stkbuf;
	if (size > sizeof(stkbuf)) {
		memp = sceNetMallocInternal(size);
		if (memp == NULL) {
			error = ENOMEM;
			goto detach;
		}
		data2 = memp;
	}
	if (com & IOC_IN) {
		if (size)
			bcopy(data, data2, size);
		else
			*(caddr_t *)data2 = data;
	} else if ((com & IOC_OUT) && size)
		memset(data2, 0, size);
	else if (com & IOC_VOID)
		*(caddr_t *)data2 = data;
	error = soioctl(so, com, data2);
	if (error == 0 && (com & IOC_OUT) && size)
		bcopy(data2, data, size);
	if (memp)
		sceNetFreeInternal(memp);
detach:
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

int
sceNetInet_lib_B3FF98EB(int *uname, u_int namelen, void *old, size_t *uoldlenp, void *new, size_t newlen)
{
	struct thread_info *ti;
	int error;
	size_t oldlen = 0;
	int (*fn)(int *, u_int, void *, size_t *, void *, size_t);
	int name[CTL_MAXNAME];
	size_t *oldlenp;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	if (namelen > CTL_MAXNAME || namelen < 2) {
		error = EINVAL;
		goto out;
	}
	bcopy(uname, name, namelen * sizeof(int));
	switch (name[0]) {
	case CTL_NET:
		fn = net_sysctl;
		break;
	default:
		error = EOPNOTSUPP;
		goto out;
	}
	oldlenp = uoldlenp;
	if (oldlenp) {
		bcopy(oldlenp, &oldlen, sizeof(oldlen));
		oldlenp = &oldlen;
	}
	error = (*fn)(name + 1, namelen - 1, old, oldlenp, new, newlen);
	if (error)
		goto out;
	if (uoldlenp)
		bcopy(&oldlen, uoldlenp, sizeof(oldlen));
out:
	return _sce_pspnet_thread_leave(ti, error);
}


__attribute__((noinline)) int
sceNetInetBind(int s, const struct sockaddr *name, socklen_t namelen)
{
	struct thread_info *ti;
	struct socket *so;
	struct mbuf *nam;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	error = sockargs(&nam, name, namelen, MT_SONAME);
	if (error)
		goto detach;
	error = sobind(so, nam);
	m_freem(nam);
detach:
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

__attribute__((noinline)) int
sceNetInetListen(int s, int backlog)
{
	struct thread_info *ti;
	struct socket *so;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	error = solisten(so, backlog);
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

__attribute__((noinline)) ssize_t
sceNetInetSend(int s, const void *buf, size_t len, int flags)
{
	struct thread_info *ti;
	struct msghdr msg;
	struct iovec aiov;
	ssize_t retsize;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	msg.msg_name = 0;
	msg.msg_namelen = 0;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
	msg.msg_control = 0;
	aiov.iov_base = (char *)buf;
	aiov.iov_len = len;
	if (_sce_pspnet_thread_leave(ti, sendit(ti, s, &msg, flags, &retsize)) < 0)
		return -1;
	return retsize;
}

__attribute__((noinline)) ssize_t
sceNetInetSendto(int s, const void *buf, size_t len, int flags,
    const struct sockaddr *to, socklen_t tolen)
{
	struct thread_info *ti;
	struct msghdr msg;
	struct iovec aiov;
	ssize_t retsize;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	msg.msg_name = (void *)to;
	msg.msg_namelen = tolen;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
	msg.msg_control = 0;
	aiov.iov_base = (char *)buf;
	aiov.iov_len = len;
	if (_sce_pspnet_thread_leave(ti, sendit(ti, s, &msg, flags, &retsize)) < 0)
		return -1;
	return retsize;
}

__attribute__((noinline)) ssize_t
sceNetInetRecv(int s, void *buf, size_t len, int flags)
{
	struct thread_info *ti;
	struct msghdr msg;
	struct iovec aiov;
	ssize_t retsize;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	msg.msg_name = 0;
	msg.msg_namelen = 0;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
	aiov.iov_base = buf;
	aiov.iov_len = len;
	msg.msg_control = 0;
	msg.msg_flags = flags;
	if (_sce_pspnet_thread_leave(ti, recvit(ti, s, &msg, (caddr_t)0, &retsize)) < 0)
		return -1;
	return retsize;
}

__attribute__((noinline)) ssize_t
sceNetInetRecvfrom(int s, void *buf, size_t len, int flags,
    struct sockaddr *from, socklen_t *fromlenaddr)
{
	struct thread_info *ti;
	struct msghdr msg;
	struct iovec aiov;
	ssize_t retsize;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	if (fromlenaddr)
		msg.msg_namelen = *fromlenaddr;
	else
		msg.msg_namelen = 0;
	msg.msg_name = (caddr_t)from;
	msg.msg_iov = &aiov;
	msg.msg_iovlen = 1;
	aiov.iov_base = buf;
	aiov.iov_len = len;
	msg.msg_control = 0;
	msg.msg_flags = flags;
	if (_sce_pspnet_thread_leave(ti, recvit(ti, s, &msg, (caddr_t)fromlenaddr, &retsize)) < 0)
		return -1;
	return retsize;
}

__attribute__((noinline)) int
sceNetInetShutdown(int s, int how)
{
	struct thread_info *ti;
	struct socket *so;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL) {
		error = EBADF;
		goto out;
	}
	sothread_attach(ti, so);
	error = soshutdown(so, how);
	sothread_detach(ti, so);
out:
	return _sce_pspnet_thread_leave(ti, error);
}

__attribute__((noinline)) int
sceNetInetClose(int s)
{
	struct thread_info *ti;
	struct socket *so;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL)
		error = EBADF;
	else
		error = soclose(so);
	return _sce_pspnet_thread_leave(ti, error);
}

__attribute__((noinline)) int
sceNetInetCloseWithRST(int s)
{
	struct thread_info *ti;
	struct socket *so;
	int error;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	so = getsock(s);
	if (so == NULL)
		error = EBADF;
	else {
		soabort(so);
		error = soclose(so);
	}
	return _sce_pspnet_thread_leave(ti, error);
}

__attribute__((noinline)) int
sceNetInetSocketAbort(int s)
{
	struct thread_info *ti;
	struct socket *so;
	int error = 0, spl;

	ti = _sce_pspnet_thread_enter();
	if (ti == NULL)
		return -1;
	spl = _sce_pspnet_spllock();
	so = getsock(s);
	if (so == NULL)
		error = EBADF;
	else
		_sce_pspnet_inet_sabort(so);
	_sce_pspnet_splunlock(spl);
	return _sce_pspnet_thread_leave(ti, error);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_inet/nonmatchings/uipc_syscalls", func_00008588);
