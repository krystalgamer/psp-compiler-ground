/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

extern "C" void _memFree(void *p, const char *file, int line);

extern "C" int sceNetAdhocMatchingCancelTarget(int id, void *mac);

struct Task;

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

class Task;

class TaskState : public Object {
public:
	virtual ~TaskState();
	virtual void Kill(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Free(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Draw(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void KillChild(Task &t, ::Task *p, ::Task *c, unsigned int n);
	virtual int Unknown(Task &t, ::Task *p, int m, void *q, unsigned int n);
};
}

namespace Net {
struct EtherAddress {
	unsigned char data[6];
};

class Lobby {
public:
	char _p[0x18];
	int matching_id;
	void Update_TerminalList();
};

namespace LobbyState {
class Sleep : public Ys::TaskState {
public:
	virtual void Run(Lobby &l);
	virtual void Hello(Lobby &l, EtherAddress &a, int n, void *p);
	virtual void Request(Lobby &l, EtherAddress &a, int n, void *p);
	virtual void Leave(Lobby &l, EtherAddress &a);
	virtual void Deny(Lobby &l, EtherAddress &a);
	virtual void Cancel(Lobby &l, EtherAddress &a);
	virtual void Accept(Lobby &l, EtherAddress &a, int n, void *p);
	virtual void Establish(Lobby &l, EtherAddress &a);
	virtual void Timeout(Lobby &l, EtherAddress &a);
	virtual void Error(Lobby &l, EtherAddress &a);
	virtual void Bye(Lobby &l, EtherAddress &a);
};

/* Never emitted: a `delete` of a Sleep * (here a header inline, unknown in
   the original) marks the deleting destructor used before the vtable does,
   so cc1plus outputs D0 before D1 as in the original. */
inline void Delete(Sleep *s) { delete s; }

void Sleep::Hello(Lobby &l, EtherAddress &a, int n, void *p)
{
}

void Sleep::Request(Lobby &l, EtherAddress &a, int n, void *p)
{
	sceNetAdhocMatchingCancelTarget(l.matching_id, &a);
}

void Sleep::Leave(Lobby &l, EtherAddress &a)
{
}

void Sleep::Deny(Lobby &l, EtherAddress &a)
{
}

void Sleep::Cancel(Lobby &l, EtherAddress &a)
{
}

void Sleep::Accept(Lobby &l, EtherAddress &a, int n, void *p)
{
	sceNetAdhocMatchingCancelTarget(l.matching_id, &a);
}

void Sleep::Establish(Lobby &l, EtherAddress &a)
{
	sceNetAdhocMatchingCancelTarget(l.matching_id, &a);
}

void Sleep::Timeout(Lobby &l, EtherAddress &a)
{
}

void Sleep::Error(Lobby &l, EtherAddress &a)
{
}

void Sleep::Bye(Lobby &l, EtherAddress &a)
{
}

void Sleep::Run(Lobby &l)
{
	l.Update_TerminalList();
}
}
}

