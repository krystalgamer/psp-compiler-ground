/* lang: c++ */
/* cflags: -Os -fno-strength-reduce */
#pragma interface "rodata"
#include "common.h"

extern "C" void *memcpy(void *, const void *, unsigned int);

namespace SaruNet {
namespace LobbyOption {
struct Hello {
	int head;
	unsigned int name[32];
	void *Set_Name(const unsigned int *s);
};

void *Hello::Set_Name(const unsigned int *s)
{
	return memcpy(name, s, sizeof(name));
}
}
}
