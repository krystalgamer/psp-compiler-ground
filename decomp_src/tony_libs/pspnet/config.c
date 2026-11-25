/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/config", sceNetConfig80211ScanJoinRequest);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/config", sceNetConfig80211ScanCreateRequest);

int sceNetConfig80211LeaveRequest(const char *name, int *out)
{
	struct ifreq_1 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	ret = _sce_pspnet_ifioctl(NULL, 0xC01469D8, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v0;
out:
	return ret;
}

int sceNetConfig80211SetAuth(const char *name, int auth)
{
	struct ifreq_1 req = { { 0 } };

	strncpy(req.name, name, 16);
	req.v0 = auth;
	return _sce_pspnet_ifioctl(NULL, 0x801469DD, &req, (void *)1);
}

int sceNetConfig80211SetPowerSave(const char *name, int a)
{
	struct ifreq_1 req = { { 0 } };

	strncpy(req.name, name, 16);
	req.v0 = a;
	return _sce_pspnet_ifioctl(NULL, 0x801469DF, &req, (void *)1);
}

int sceNetConfig80211GetIfInfo(const char *name, int type, void *out)
{
	int ret;

	if (type < 6) {
		struct ifinfo_req req;
		struct ifinfo_req *p = &req;

		__builtin_memset(p, 0, sizeof(*p));
		strncpy(req.name, name, 16);
		ret = _sce_pspnet_ifioctl(NULL, 0x401869D9, &req, (void *)1);
		if (ret < 0)
			goto out;
		switch (type) {
		case 1:
			*(u_char *)out = req.a;
			break;
		case 2:
			*(u_char *)out = req.b;
			break;
		case 3:
			*(u_short *)out = req.c;
			break;
		case 4:
			*(u_short *)out = req.d;
			break;
		case 5:
			*(u_char *)out = req.e;
			break;
		default:
			ret = 0x80410103;
			goto out;
		}
	} else {
		struct ifreq_1 req = { { 0 } };

		strncpy(req.name, name, 16);
		ret = _sce_pspnet_ifioctl(NULL, 0x401469DA, &req, (void *)1);
		if (ret < 0)
			goto out;
		*(int *)out = req.v0;
	}
out:
	return ret;
}

int sceNetConfig80211GetBssDesc(const char *name, int a)
{
	struct ifreq_1 req = { { 0 } };

	strncpy(req.name, name, 16);
	req.v0 = a;
	return _sce_pspnet_ifioctl(NULL, 0xC01469D7, &req, (void *)1);
}

int sceNetConfig80211ScanRequest(const char *name, int a, int *b, int c, int *d)
{
	struct ifreq_4 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = a;
	req.v1 = *b;
	req.v2 = c;
	ret = _sce_pspnet_ifioctl(NULL, 0xC02069D4, &req, (void *)1);
	if (ret != 0)
		goto out;
	*b = req.v1;
	*d = req.v3;
out:
	return ret;
}

int sceNetConfig80211CreateRequest(const char *name, int a, int *out)
{
	struct ifreq_2 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = a;
	ret = _sce_pspnet_ifioctl(NULL, 0xC01869D5, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v1;
out:
	return ret;
}

int sceNetConfig80211JoinRequest(const char *name, int a, int *out)
{
	struct ifreq_2 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = a;
	ret = _sce_pspnet_ifioctl(NULL, 0xC01869D6, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v1;
out:
	return ret;
}

int sceNetConfig80211SetConf(const char *name, int a)
{
	struct ifreq_1 req = { { 0 } };

	strncpy(req.name, name, 16);
	req.v0 = a;
	return _sce_pspnet_ifioctl(NULL, 0x801469D2, &req, (void *)1);
}

int sceNetConfig80211GetConf(const char *name, int a)
{
	struct ifreq_1 req = { { 0 } };

	strncpy(req.name, name, 16);
	req.v0 = a;
	return _sce_pspnet_ifioctl(NULL, 0x401469D3, &req, (void *)1);
}

int sceNetConfig80211GetAuth(const char *name, int a)
{
	struct ifreq_1 req = { { 0 } };

	strncpy(req.name, name, 16);
	req.v0 = a;
	return _sce_pspnet_ifioctl(NULL, 0x401469DE, &req, (void *)1);
}

int sceNetConfig80211GetPowerSave(const char *name, int *out)
{
	struct ifreq_1 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	ret = _sce_pspnet_ifioctl(NULL, 0x401469E0, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v0;
out:
	return ret;
}

int sceNetConfig80211EnterGameMode(const char *name, int a, int b, int *out)
{
	struct ifreq_3 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = a;
	req.v1 = b;
	ret = _sce_pspnet_ifioctl(NULL, 0xC01C69E1, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v2;
out:
	return ret;
}

int sceNetConfigUpInterface(const char *name)
{
	struct ifreq ifr = { { 0 } };
	int ret;

	strncpy(ifr.ifr_name, name, 16);
	ret = _sce_pspnet_ifioctl(NULL, 0xC0206911, &ifr, (void *)1);
	if (ret != 0)
		goto out;
	ifr.ifr_ifru.ifru_flags |= 1;
	ret = _sce_pspnet_ifioctl(NULL, 0x80206910, &ifr, (void *)1);
out:
	return ret;
}

int sceNetConfigDownInterface(const char *name)
{
	struct ifreq ifr = { { 0 } };
	int ret;

	strncpy(ifr.ifr_name, name, 16);
	ret = _sce_pspnet_ifioctl(NULL, 0xC0206911, &ifr, (void *)1);
	if (ret != 0)
		goto out;
	ifr.ifr_ifru.ifru_flags &= ~1;
	ret = _sce_pspnet_ifioctl(NULL, 0x80206910, &ifr, (void *)1);
out:
	return ret;
}

int sceNetConfigGetEtherAddr(const char *name, u_char *mac)
{
	struct ifnet *ifp;
	char *lla;

	int ret = 0;

	ifp = _sce_pspnet_ifunit(name);
	if (ifp == NULL) {
		ret = 0x80410180;
		goto out;
	}
	lla = (char *)ifp->if_sadl + 8 + ((u_char *)ifp->if_sadl)[5];
	__builtin_memcpy(mac, lla, 6);
out:
	return ret;
}

int sceNetGetLocalEtherAddr(u_char *mac)
{
	struct ifnet *ifp;
	char *lla;
	int ret = 0;

	ifp = _sce_pspnet_ifunit("wlan");
	if (ifp == NULL) {
		ret = 0x80410180;
		goto out;
	}
	lla = (char *)ifp->if_sadl + 8 + ((u_char *)ifp->if_sadl)[5];
	__builtin_memcpy(mac, lla, 6);
out:
	return ret;
}

int sceNetConfigGetIfEvent(const char *name, int *a, int *b)
{
	struct ifreq ifr = { { 0 } };
	struct ifevreq ev;
	int ret;

	strncpy(ifr.ifr_name, name, 16);
	ifr.ifr_ifru.ifru_data = &ev;
	ev.a = 0;
	ev.b = 0;
	ret = _sce_pspnet_ifioctl(NULL, 0xC020693D, &ifr, (void *)1);
	if (ret != 0)
		goto out;
	*a = ev.a;
	*b = ev.b;
out:
	return ret;
}

int sceNetConfigSetIfEventFlag(const char *name, int a, int b)
{
	struct ifreq ifr = { { 0 } };
	struct ifevreq ev;

	strncpy(ifr.ifr_name, name, 16);
	ev.a = a;
	ev.b = b;
	ifr.ifr_ifru.ifru_data = &ev;
	return _sce_pspnet_ifioctl(NULL, 0x8020693E, &ifr, (void *)1);
}

int sceNetConfigGetIfEventFlag(const char *name, int *a, int *b)
{
	struct ifreq ifr = { { 0 } };
	struct ifevreq ev;
	int ret;

	strncpy(ifr.ifr_name, name, 16);
	ifr.ifr_ifru.ifru_data = &ev;
	ev.a = 0;
	ev.b = 0;
	ret = _sce_pspnet_ifioctl(NULL, 0xC020693E, &ifr, (void *)1);
	if (ret != 0)
		goto out;
	*a = ev.a;
	*b = ev.b;
out:
	return ret;
}
