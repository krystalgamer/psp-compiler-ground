/* lang: c++ */
/* cflags: -Os */
#pragma interface "rodata"
#include "common.h"

namespace Net {
class Network {
public:
	static Network *_instance_p;
	virtual ~Network();
	virtual void Update();
};
}

extern "C" Net::Network *SaruNet_Network__Get_Instance_p(void)
{
	return Net::Network::_instance_p;
}

extern "C" void SaruNet_Network__Update(Net::Network *n)
{
	n->Update();
}
