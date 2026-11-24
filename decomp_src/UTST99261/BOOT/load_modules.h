#ifndef LOAD_MODULES_H
#define LOAD_MODULES_H
/* types recovered from DWARF (tools/dwarfhdr.py) */
typedef struct SampleLoadModule {
	const SceUChar8 *path;
	const SceUID mpid;
} SampleLoadModule;

int LoadRequiredModules(void);
void StopDeleteLoadedModules(void);
#endif
