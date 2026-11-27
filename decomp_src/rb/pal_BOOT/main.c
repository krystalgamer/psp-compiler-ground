#include "common.h"

/* declarations recovered from DWARF */
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    void *ent_top;
    void *ent_end;
    void *stub_top;
    void *stub_end;
};

extern int __begin_of_section_lib_ent[];
extern int __end_of_section_lib_ent[];
extern int __begin_of_section_lib_stub[];
extern int __end_of_section_lib_stub[];
extern int _gp[];
extern const struct _scemoduleinfo __psp_moduleinfo;

int main(void);


#include "common.h"
int SystemInit(void);
int SystemTerm(void);
int MovieInit(void);
int MovieStart(void);
int MovieMain(void);
int MovieEnd(void);
int MovieTerm(void);
int main(void)
{
	SystemInit();
	MovieInit();
	for (;;) {
		MovieStart();
		MovieMain();
		MovieEnd();
	}
	MovieTerm();
	SystemTerm();
	return 0;
}
