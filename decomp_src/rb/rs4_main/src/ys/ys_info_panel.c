/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtable, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct Task;

namespace Ys {
struct Anim2D_LoadParam;
class Task {
public:
	virtual ~Task();
};
class AnimTask : public Task {
public:
	AnimTask *Init(int mode, Anim2D_LoadParam *param, Task *parent);
	int Receive_RunMessage(::Task *t, void *p, unsigned int n);
};
class InfoPanel : public AnimTask {
public:
	InfoPanel *Init(Anim2D_LoadParam &param, Task *parent);
	int Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

InfoPanel *InfoPanel::Init(Anim2D_LoadParam &param, Task *parent)
{
	AnimTask::Init(1, &param, parent);
	return this;
}

int InfoPanel::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	return AnimTask::Receive_RunMessage(t, p, n);
}
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_info_panel", _ZN2Ys9InfoPanelD1Ev);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_info_panel", D_00104D98);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_info_panel", _ZN2Ys9InfoPanelD0Ev);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_info_panel", _ZTIN2Ys9InfoPanelE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_info_panel", _ZTSN2Ys9InfoPanelE);
}
