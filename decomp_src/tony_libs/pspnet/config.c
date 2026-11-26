/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/config", sceNetConfig80211ScanJoinRequest);

unsigned int sceNetRand(void);
extern char D_0000A150[];

struct bssdesc {
	u_char bssid[6];
	u_char chan;
	u_char ssidlen;
	char ssid[32];
	int type;
	int bintval;
	char pad30[0x3E - 0x30];
	u_short capinfo;
	char pad40[0x50 - 0x40];
};

struct bsslist {
	struct bsslist *next;
	struct bssdesc d;
};

struct scanparam {
	int type;
	char pad4[6];
	u_char chan[14];
	u_char ssidlen;
	char pad19[3];
	char ssid[32];
	int unk3C;
	int unk40;
	int unk44;
	int unk48;
};

static inline int scan_req(const char *name, struct scanparam *a, int *b, void *c, int *d)
{
	struct ifreq_4 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = (int)a;
	req.v1 = *b;
	req.v2 = (int)c;
	ret = _sce_pspnet_ifioctl(NULL, 0xC02069D4, &req, (void *)1);
	if (ret != 0)
		goto out;
	*b = req.v1;
	*d = req.v3;
out:
	return ret;
}

static inline int create_req(const char *name, void *a, int *out)
{
	struct ifreq_2 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = (int)a;
	ret = _sce_pspnet_ifioctl(NULL, 0xC01869D5, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v1;
out:
	return ret;
}

static inline int join_req(const char *name, void *a, int *out)
{
	struct ifreq_2 req = { { 0 } };
	int ret;

	strncpy(req.name, name, 16);
	req.v0 = (int)a;
	ret = _sce_pspnet_ifioctl(NULL, 0xC01869D6, &req, (void *)1);
	if (ret != 0)
		goto out;
	*out = req.v1;
out:
	return ret;
}

static inline int bssid_cmp(const u_char *a, const u_char *b)
{
	u_int x, y;

	x = (a[0] << 16) | (a[1] << 8) | a[2];
	y = (b[0] << 16) | (b[1] << 8) | b[2];
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	x = (a[3] << 16) | (a[4] << 8) | a[5];
	y = (b[3] << 16) | (b[4] << 8) | b[5];
	if (x < y)
		return -1;
	if (x > y)
		return 1;
	return 0;
}

int sceNetConfig80211ScanCreateRequest(const char *name, const char *ssid, int ssidlen, int chan)
{
	struct scanparam sp;
	union { struct bssdesc d; char b[0x64]; } bss;
	struct bssdesc bd;
	char ssidbuf[32];
	struct bsslist *p, *q;
	u_char *best = NULL;
	unsigned int wait = 0;
	unsigned int elapsed;
	int len, ret, out, i;

	if (chan < 1 || chan > 14 || ssid == NULL || ssidlen == 0) {
		ret = 0x80410103;
		goto end;
	}
	memset(&sp, 0, sizeof(sp));
	memcpy(sp.ssid, ssid, ssidlen);
	p = (struct bsslist *)D_0000A150;
	sp.type = 2;
	sp.ssidlen = ssidlen;
	sp.chan[0] = chan;
	sp.chan[1] = 0;
	sp.unk3C = 1;
	sp.unk40 = 0;
	sp.unk44 = 6;
	sp.unk48 = 100;
	len = 0xA80;
	memset(p, 0, 0xA80);
	out = 0;
	elapsed = sceKernelGetSystemTimeLow();
	ret = scan_req(name, &sp, &len, p, &out);
	if (ret < 0)
		goto end;
	elapsed = sceKernelGetSystemTimeLow() - elapsed;
	if (len != 0) {
		__builtin_memset(ssidbuf, 0, sizeof(ssidbuf));
		memcpy(ssidbuf, ssid, ssidlen);
		for (q = p; q != NULL; q = q->next) {
			if (memcmp(q->d.ssid, ssidbuf, 32) != 0)
				continue;
			if (q->d.type != 2)
				continue;
			if (best == NULL)
				best = q->d.bssid;
			else if (bssid_cmp(q->d.bssid, best) < 0)
				best = q->d.bssid;
		}
	}
	if (best != NULL) {
		memset(&bss, 0, sizeof(bss));
		bss.d = *(struct bssdesc *)best;
		out = 0;
		ret = join_req(name, &bss, &out);
	} else {
		memset(&bss, 0, sizeof(bss));
		bss.d.ssidlen = ssidlen;
		memcpy(bss.d.ssid, ssid, ssidlen);
		bss.d.type = 2;
		bss.d.bintval = 100;
		bss.d.capinfo = 0x22;
		bss.d.chan = chan;
		ret = create_req(name, &bss, &out);
		if (ret == 0)
			sceKernelDelayThread(500000);
	}
	if (ret < 0)
		goto fail;
	for (i = 0; i < 3; i++) {
		if (elapsed < 1000000) {
			wait = sceNetRand() / (0xFFFFFFFF / (1000000 - elapsed) + 1);
			sceKernelDelayThread(wait);
		}
		ret = sceNetConfig80211GetBssDesc(name, (int)&bd);
		if (ret < 0)
			goto fail;
		memset(D_0000A150, 0, 0xA80);
		len = 0xA80;
		out = 0;
		ret = scan_req(name, &sp, &len, D_0000A150, &out);
		if (ret == 0x80410D11) {
			ret = 0;
			goto end;
		}
		if (ret < 0)
			goto fail;
		best = NULL;
		if (len != 0) {
			for (q = (struct bsslist *)D_0000A150; q != NULL; q = q->next) {
				if (memcmp(q->d.ssid, bd.ssid, 32) != 0)
					continue;
				if (q->d.type != 2)
					continue;
				if (best == NULL) {
					if (bssid_cmp(q->d.bssid, bd.bssid) < 0)
						best = q->d.bssid;
				} else if (bssid_cmp(q->d.bssid, best) < 0)
					best = q->d.bssid;
			}
		}
		if (best != NULL) {
			out = 0;
			ret = sceNetConfig80211LeaveRequest(name, &out);
			if (ret < 0)
				goto fail;
			sceKernelDelayThread(3000000);
			memset(&bss, 0, sizeof(bss));
			bss.d = *(struct bssdesc *)best;
			out = 0;
			ret = join_req(name, &bss, &out);
			if (ret < 0)
				goto fail;
		} else if (i < 2 && elapsed < 1000000)
			sceKernelDelayThread(1000000 - elapsed - wait);
	}
	return ret;
fail:
	out = 0;
	sceNetConfig80211LeaveRequest(name, &out);
end:
	return ret;
}

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
