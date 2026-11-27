/* lang: c++ */
/* cflags: -Os -fno-strength-reduce */
#pragma interface "rodata"
#include "common.h"

enum NetOwnershipStatus { NetOwnership_2 = 2 };
enum NetObjectLifespan { NetLifespan_4 = 4 };
struct NetTypeBroadcastSchedule;

namespace Net {
class ObjectClass;
class Object {
public:
	void Init(ObjectClass &cls, NetOwnershipStatus o, NetObjectLifespan l, unsigned int a, int b, int c,
		  bool d, void *e, const unsigned char *f);
};
}

namespace SaruNet {
class ObjectClass {
public:
	void Register_Field();
	void Register_Field(NetTypeBroadcastSchedule &s);
};

class Object : public Net::Object {
public:
	Object &Init(Net::ObjectClass &cls, bool d, void *e, const unsigned char *f);
};

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_object", _ZN7SaruNet11ObjectClass14Register_FieldEv);
}

void ObjectClass::Register_Field(NetTypeBroadcastSchedule &s)
{
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_object", _ZN7SaruNet6Object4InitERN3Net11ObjectClassEbPvPKh);
}
}
