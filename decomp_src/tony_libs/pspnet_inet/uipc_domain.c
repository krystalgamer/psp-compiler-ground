/* cflags: -O3 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "inetlib.h"
/* --- end declarations --- */

int func_00001E30(void)
{
	register struct domain *dp;
	register struct protosw *pr;
	int max_linkhdr, max_protohdr, max_hdr, max_datalen;

	D_0002F29C = 0;
	D_0002F2E8 = 0;
	domains = NULL;
	ADDDOMAIN(inetdomain);
	ADDDOMAIN(D_0002E59C);
	ADDDOMAIN(D_0002E50C);
	for (dp = domains; dp; dp = dp->dom_next) {
		if (dp->dom_init)
			(*dp->dom_init)();
		for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++)
			if (pr->pr_init)
				(*pr->pr_init)();
	}
	sceNetIfhandle_lib_5FB31C72(&max_linkhdr, &max_protohdr, &max_hdr, &max_datalen);
	if (max_linkhdr < 16)
		max_linkhdr = 16;
	max_hdr = max_linkhdr + max_protohdr;
	max_datalen = MHLEN - max_hdr;
	sceNetIfhandle_lib_62B20015(max_linkhdr, max_protohdr, max_hdr, max_datalen);
	callout_init(&D_0002F2A0);
	callout_init(&D_0002F2C4);
	callout_reset(&D_0002F2A0, 1, func_00002320, NULL);
	callout_reset(&D_0002F2C4, 1, func_0000227C, NULL);
	return 0;
}

void func_00001FA4(void) {
}

struct domain *func_00001FAC(int family)
{
	struct domain *dp;

	for (dp = domains; dp != NULL; dp = dp->dom_next)
		if (dp->dom_family == family)
			break;
	return (dp);
}

struct protosw *func_00001FDC(int family, int type)
{
	register struct domain *dp;
	register struct protosw *pr;

	dp = func_00001FAC(family);
	if (dp == NULL)
		return (NULL);
	for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++)
		if (pr->pr_type && pr->pr_type == type)
			return (pr);
	return (0);
}

struct protosw *func_00002058(int family, int protocol, int type)
{
	register struct domain *dp;
	register struct protosw *pr;
	struct protosw *maybe = 0;

	if (family == 0)
		return (0);
	dp = func_00001FAC(family);
	if (dp == NULL)
		return (NULL);
	for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++) {
		if ((pr->pr_protocol == protocol) && (pr->pr_type == type))
			return (pr);
		if (type == SOCK_RAW && pr->pr_type == SOCK_RAW &&
		    pr->pr_protocol == 0 && maybe == (struct protosw *)0)
			maybe = pr;
	}
	return (maybe);
}

int func_0000211C(int *name, u_int namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen)
{
	register struct domain *dp;
	register struct protosw *pr;
	int family, protocol;

	if (namelen < 2)
		return (EISDIR);
	family = name[0];
	if (family == 0)
		return (0);
	dp = func_00001FAC(family);
	if (dp == NULL)
		return (ENOPROTOOPT);
	if (namelen < 3)
		return (EISDIR);
	protocol = name[1];
	for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++)
		if (pr->pr_protocol == protocol && pr->pr_sysctl)
			return ((*pr->pr_sysctl)(name + 2, namelen - 2,
			    oldp, oldlenp, newp, newlen));
	return (ENOPROTOOPT);
}

void func_000021E0(int cmd, struct sockaddr *sa)
{
	register struct domain *dp;
	register struct protosw *pr;

	for (dp = domains; dp; dp = dp->dom_next)
		for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++)
			if (pr->pr_ctlinput)
				(*pr->pr_ctlinput)(cmd, sa, NULL);
}

void func_0000227C(void *arg)
{
	register struct domain *dp;
	register struct protosw *pr;

	D_0002F29C++;
	for (dp = domains; dp; dp = dp->dom_next)
		for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++)
			if (pr->pr_slowtimo)
				(*pr->pr_slowtimo)();
	callout_reset(&D_0002F2C4, hz / 2, func_0000227C, NULL);
}

void func_00002320(void *arg)
{
	register struct domain *dp;
	register struct protosw *pr;

	D_0002F2E8++;
	for (dp = domains; dp; dp = dp->dom_next)
		for (pr = dp->dom_protosw; pr < dp->dom_protoswNPROTOSW; pr++)
			if (pr->pr_fasttimo)
				(*pr->pr_fasttimo)();
	callout_reset(&D_0002F2A0, hz / 5, func_00002320, NULL);
}
