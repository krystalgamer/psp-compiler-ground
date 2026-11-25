#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <string.h>
#include <iofilemgr.h>
#include <modulemgr.h>

typedef struct {
	char *name;
	int type;
	char *arg;
} MODMGR_LOAD_PARAM;

extern int m_initflag;
extern SceUID m_pid[2];
extern char m_device[16];
extern char m_path[2][128];
extern SceUID m_moduleid[64];

void ModMgrUnloadAllModules(void);
int ModMgrUnloadModule(SceUID id);

#define LoadModule LoadModule_7D18

static SceUID LoadModule(char *path, SceUID mpid, int args, char *argp)
{
	SceInt32 ret;
	SceInt32 mresult;
	SceKernelLMOption opt;
	SceUID fd;
	SceUID modid;

	memset(&opt, 0, sizeof(opt));
	opt.size = sizeof(opt);
	opt.mpidtext = mpid;
	mresult = 0;
	opt.flags = 0;
	opt.mpiddata = 0;
	opt.position = 0;

	ret = sceIoOpen(path, SCE_O_RDONLY, 0);
	if (ret < 0) {
		printf("sceIoOpen() returns 0x%x\n", ret);
		return ret;
	}
	fd = ret;
	ret = sceKernelLoadModuleByID(fd, 0, &opt);
	if (ret < 0) {
		printf("sceKerelLoadMoule() returns 0x%x\n", ret);
		goto ERROR_LOAD;
	}
	modid = ret;
	ret = sceKernelStartModule(modid, 0, NULL, &mresult, NULL);
	if (ret < 0) {
		printf("sceKernelStartModule() returns 0x%x", ret);
		goto ERROR_START;
	}
	sceIoClose(fd);
	return modid;

ERROR_START:
	if (modid > 0) {
		sceKernelStopModule(modid, 0, NULL, &mresult, NULL);
		printf("try to stop modules.. code = 0x%x\n", mresult);
		sceKernelUnloadModule(modid);
	}
ERROR_LOAD:
	if (fd > 0)
		sceIoClose(fd);
	return ret;
}

void ModMgrInit(void)
{
	int i;

	if (m_initflag > 0)
		return;
	for (i = 0; i < 64; i++)
		m_moduleid[i] = -1;
	strcpy(m_path[0], "/usr/local/psp/devkit/kmodule/");
	strcpy(m_device, "host0:");
	strcpy(m_path[1], "/usr/local/psp/devkit/module/");
	m_initflag++;
}

void ModMgrTerm(void)
{
	if (m_initflag == 1) {
		m_initflag = 0;
		ModMgrUnloadAllModules();
	}
}

void ModMgrSetDevice(char *device)
{
	int i;
	int len;

	if (device == NULL)
		device = "";
	len = strlen(device);
	for (i = 0; i < len; i++) {
		if (device[i] == ':')
			break;
	}
	if (len == i) {
		printf("ModMgrSetDevice: error no device name '%s'\n", device);
		return;
	}
	len = i + 1;
	if (len >= 16) {
		printf("ModMgrSetDevice: error length over %d '%s'\n", len, device);
		return;
	}
	strncpy(m_device, device, len);
	m_device[len] = 0;
	printf("ModMgrSetDevice: device = '%s'\n", device);
}

void ModMgrSetModulePath(int type, char *path)
{
	int len;

	if (type < 0 || type >= 2) {
		printf("ModMgrSetModulePath: error type range %d '%s'\n", type, path);
		return;
	}
	if (path == NULL)
		path = "";
	len = strlen(path);
	if (len >= 128) {
		printf("ModMgrSetModulePath: error length over %d '%s'\n", len, path);
		return;
	}
	strcpy(m_path[type], path);
	printf("ModMgrSetModulePath: path[%d] ='%s'\n", type, path);
}

SceUID ModMgrLoadModule(char *name, int type, char *arg)
{
	SceUID result;
	int len;
	int index;
	char path[272];

	for (index = 0; index < 64; index++) {
		if (m_moduleid[index] < 0)
			break;
	}
	if (index == 64) {
		printf("ModMgrLoadModule: index full %d '%s'\n", type, name);
		return 0x800201BB;
	}
	if (type < 0 || type >= 2) {
		printf("ModMgrLoadModule: error type range %d '%s'\n", type, name);
		return 0x800201BB;
	}
	if (name == NULL) {
		printf("ModMgrLoadModule: error name %d '%s'\n", type, NULL);
		return 0x800200D2;
	}
	len = strlen(name);
	if (len >= 128) {
		printf("ModMgrSetModulePath: error length over %d '%s'\n", len, name);
		return 0x800200D2;
	}
	strcpy(path, m_device);
	strcat(path, m_path[type]);
	strcat(path, name);
	result = LoadModule(path, m_pid[type], 0, NULL);
	printf("ModMgrLoadModule: load '%s'[%d] -> %08x\n", path, type, result);
	if (result >= 0)
		m_moduleid[index] = result;
	return result;
}

int ModMgrLoadModules(MODMGR_LOAD_PARAM *table)
{
	int result;

	if (table == NULL) {
		puts("ModMgrLoadModules: null pointer'");
		result = 0x800200D2;
	} else {
		result = 0;
		while (table->name != NULL) {
			result = ModMgrLoadModule(table->name, table->type, table->arg);
			table++;
			if (result < 0)
				return result;
		}
		result = 0;
	}
	return result;
}

int ModMgrUnloadModule(SceUID id)
{
	int i;

	if (id < 0) {
		puts("ModMgrLoadModules: null pointer'");
		return 0x800200D2;
	}
	for (i = 0; i < 64; i++) {
		if (m_moduleid[i] == id) {
			sceKernelStopModule(id, 0, NULL, NULL, NULL);
			sceKernelUnloadModule(m_moduleid[i]);
			m_moduleid[i] = -1;
			return 0;
		}
	}
	printf("ModMgrLoadModules: module not found %08x'\n", id);
	return 0x8002012E;
}

void ModMgrUnloadAllModules(void)
{
	int i;

	for (i = 63; i >= 0; i--) {
		if (m_moduleid[i] > 0)
			ModMgrUnloadModule(m_moduleid[i]);
	}
}
