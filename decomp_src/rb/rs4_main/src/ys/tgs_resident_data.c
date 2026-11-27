/* lang: c++ */
/* cflags: -Os */
#include "common.h"

namespace Tgs {
class ResidentData {
public:
	unsigned int finishCardBattle : 1;
	unsigned int finishPetitGame : 1;
	static ResidentData *_instance_p;
	void Reset();
};

void ResidentData::Reset()
{
	finishCardBattle = 0;
	finishPetitGame = 0;
}
}

extern "C" bool TgsResidentData__Set_FinishPetitGame(bool finish)
{
	return Tgs::ResidentData::_instance_p->finishPetitGame = finish;
}
