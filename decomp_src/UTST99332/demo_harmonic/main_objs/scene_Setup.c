/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene5SetupC2ESsb");
__asm__(".globl _GLOBAL__D__ZN5scene5SetupC2ESsb");
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene5Setup11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene5Setup5cloneESs)
    SCENE_LINKONCE(_ZN5scene5Setup5enterEv)
    SCENE_LINKONCE(_ZN5scene5Setup5leaveEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_5SetupEEERKNS0_IT_EE)
);

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Setup::getTypeName() const
{
    return "Setup";
}

inline void scene::Setup::enter()
{
}

inline void scene::Setup::leave()
{
}
SGL_LINKONCE_END

scene::Setup::Setup(std::string name, bool b) : Node(name, b)
{
    set_default_name();
}

scene::Setup::~Setup()
{
}

void scene::Setup::flatten(math::TransformStack &) {
}

/* used by clone() (asm) */
template common::handle<scene::Node>::handle(const common::handle<scene::Setup> &);

/* clone() is inline too (weak copy in the tail): asm, near-miss (tmp/cxx/drafts/s20/v/setup.txt) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Setup", _ZNK5scene5Setup5cloneESs);
