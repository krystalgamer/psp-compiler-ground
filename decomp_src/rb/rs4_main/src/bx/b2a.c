/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: Manager::Draw matches only with it (scene pointer IV); the rest of the object tolerates both */
#include "common.h"

struct ScePspFMatrix4 { float m[16]; } __attribute__((aligned(16)));
struct tagGpTEXDESC;

struct GpPrim {
	int a, b, c, d;
	float sx, sy, sz, sw;
	ScePspFMatrix4 mtx;
	tagGpTEXDESC *tex;
	int w, h;
	int cx, cy;
	unsigned int col;
	int pad[2];
};

struct FVEC {
	float x, y, z, w;
	void Set(float a, float b, float c, float d)
	{
		x = a;
		y = b;
		z = c;
		w = d;
	}
};

namespace B2A {

struct Player {
	float frame;
	float speed;
	int loop;
	short scene;
	short _e;
	int pause;
	unsigned char f14;
	bool active;
	Player(int);
	~Player();
	void Set(int);
};

struct LNode {
	LNode *prev;
	LNode *next;
	LNode() : prev(0), next(0) {}
};

struct PlayerNode : LNode {
	Player *player;
	Player *&data() { return player; }
};

/* ushort fields, word aligned: the struct copy in Manager() must not alias the int count */
struct ObjLink {
	unsigned short sibling, child;
	unsigned short _4, _6;
} __attribute__((aligned(4)));

struct ObjState {
	int _8;
	float rot;
	unsigned int col;
	FVEC pos;
	FVEC scale;
};

struct Object {
	ObjLink link;
	ObjState cur;
	ObjState prev;
	ScePspFMatrix4 mtx;
	unsigned char enable;
	char _a1[0xF];
	Object();
	~Object() {}
	void Clear();
	void Scale(float, float);
	void MoveTo(FVEC &v);
	void Refresh();
};
typedef Object Scene;

struct SceneEnt {
	char _0[0x30];
	int end;
};

struct B2aHdr {
	int _0, nParts, _8;
	int nScene;
	ObjLink *link;
	int _14;
	SceneEnt *ent;
	int nObject;
};

struct TM2Parts {
	char _0[0x78];
	TM2Parts();
	~TM2Parts();
	void ReAssign();
};

struct B2aFile {
	B2aHdr *hdr;
	TM2Parts *parts;
	~B2aFile();
	void ReAssign();
};

/* STAND-IN: head is typed as the node base so that node->prev stores alias it while tail
   (N *) does not (CreateB2A/CreatePlayer load order); the real declaration is unknown */
template <class N> struct List {
	LNode *head;
	N *tail;
	List() { tail = 0; head = 0; }
	~List() { Clear(); }
	void Clear()
	{
		N *n = tail;
		while (n) {
			N *next = (N *)n->next;
			delete n;
			n = next;
		}
		tail = 0;
		head = 0;
	}
	void Add(N *n)
	{
		n->prev = head;
		if (!tail)
			tail = n;
		if (head)
			head->next = n;
		head = n;
	}
	template <class T> void Push(T *d)
	{
		N *node = new N;
		node->data() = d;
		Add(node);
	}
	template <class T> T *Push2(T *d)
	{
		N *node = new N;
		node->data() = d;
		Add(node);
		return d;
	}
	template <class T> void Add2(N *node, T *d)
	{
		node->data() = d;
		Add(node);
	}
	N *Find(void *d)
	{
		for (N *n = tail; n; n = (N *)n->next)
			if (n->data() == d)
				return n;
		return 0;
	}
	void Remove(N *n)
	{
		if (n->prev)
			n->prev->next = n->next;
		N *next = (N *)n->next;
		if (next)
			next->prev = n->prev;
		if (head == n)
			head = n->prev;
		if (tail == n)
			tail = next;
	}
};

struct Manager {
	B2aFile *file;
	Scene *scene;
	int _8, _c;
	ScePspFMatrix4 mtx;
	List<PlayerNode> list;
	int _58;
	int _5c;
	Manager(B2aFile *);
	~Manager();
	void Calc();
	void Draw();
	Player *CreatePlayer(int);
	void EnableScene(int);
	void DisableScene(int);
	void play(int, float);
	int GetLoop();
	int GetPause();
	float GetSpeed();
	void SetLoop(int);
	void SetPause(int);
	void SetFrame(float);
	float GetFrame();
	float GetEndFrame();
	void SetEndFrame(float f);
	void SetSpeed(float s);
	void Refresh();
	void RefreshOne(int i, bool b);
	void CalcOne(Player *p);
	int DeletePlayer(Player *p);
	void DrawOne(int n);
	void draw(int n, ScePspFMatrix4 *a, ScePspFMatrix4 *b, unsigned int col);
};

void DeletePlayer(Player *);
Manager *CreateB2A(B2aFile *);
void Start(Manager *);
void DeleteManager(Manager *);

struct ManagerNode : LNode {
	Manager *manager;
	Manager *&data() { return manager; }
};
extern List<ManagerNode> managerList;
}

extern "C" const float D_00108F30;
extern "C" const float D_00108F34;
extern "C" void copUnitMat(ScePspFMatrix4 *);

extern "C" {
extern GpPrim sample_anm_list[128];
extern int GpPrim_cnt;
extern int GpPrim_dcnt;
extern const float D_00108F14;
void *memset(void *, int, unsigned int);
}

void GpPrim_Init()
{
	GpPrim *p;
	int i;

	GpPrim_cnt = 0;
	GpPrim_dcnt = 0;
	memset(sample_anm_list, 0, sizeof(sample_anm_list));
	p = sample_anm_list;
	for (i = 128; i != 0; i--, p++) {
		p->a = 0;
		p->b = 0;
		p->c = 0;
		p->sx = D_00108F14;
		p->sy = D_00108F14;
		p->sz = D_00108F14;
		p->mtx.m[0] = D_00108F14;
		p->mtx.m[1] = 0;
		p->mtx.m[2] = 0;
		p->mtx.m[3] = 0;
		p->mtx.m[4] = 0;
		p->mtx.m[5] = D_00108F14;
		p->mtx.m[6] = 0;
		p->mtx.m[7] = 0;
		p->mtx.m[8] = 0;
		p->mtx.m[9] = 0;
		p->mtx.m[10] = D_00108F14;
		p->mtx.m[11] = 0;
		p->mtx.m[12] = 0;
		p->mtx.m[13] = 0;
		p->mtx.m[14] = 0;
		p->mtx.m[15] = D_00108F14;
		p->w = 0;
		p->h = 0;
		p->cx = 0;
		p->cy = 0;
		p->col = 0x80808080;
	}
}

extern "C" const float D_00108F14 = 1.0f;

void GpPrim_SetStart()
{
	GpPrim_cnt = 0;
}

void GpPrim_DrawStart()
{
	GpPrim_dcnt = 0;
}

void GpPrim_SetTex(tagGpTEXDESC *tex)
{
	sample_anm_list[GpPrim_cnt].tex = tex;
}

void GpPrim_SetCol(int col)
{
	sample_anm_list[GpPrim_cnt].col = col;
}

void GpPrim_SetWH(int w, int h)
{
	GpPrim *p = &sample_anm_list[GpPrim_cnt];
	p->w = w;
	p->h = h;
}

void GpPrim_SetCenter(float x, float y)
{
	GpPrim *p = &sample_anm_list[GpPrim_cnt];
	p->cx = (int)x;
	p->cy = (int)y;
}

void GpPrim_SetMatrix(ScePspFMatrix4 *m)
{
	if (m) {
		GpPrim *p = &sample_anm_list[GpPrim_cnt];
		p->mtx = *m;
	}
}

tagGpTEXDESC *GpPrim_GetDrawTex()
{
	return sample_anm_list[GpPrim_dcnt].tex;
}

unsigned int GpPrim_GetDrawCol()
{
	return sample_anm_list[GpPrim_dcnt].col;
}

void GpPrim_GetDrawCenter(float *x, float *y)
{
	GpPrim *p = &sample_anm_list[GpPrim_dcnt];
	*x = p->cx;
	*y = p->cy;
}

void GpPrim_GetDrawWH(int *w, int *h)
{
	GpPrim *p = &sample_anm_list[GpPrim_dcnt];
	*w = p->w;
	*h = p->h;
}

void GpPrim_GetDrawMatrix(ScePspFMatrix4 *m)
{
	GpPrim *p = &sample_anm_list[GpPrim_dcnt];
	if (m)
		*m = p->mtx;
}

void GpPrim_SetNext()
{
	GpPrim_cnt++;
}

void GpPrim_DrawNext()
{
	GpPrim_dcnt++;
}

int GpPrim_GetMax()
{
	return GpPrim_cnt;
}

B2A::Manager *B2A::CreateB2A(B2aFile *f)
{
	Manager *m = new Manager(f);
	managerList.Push(m);
	return m;
}

void B2A::Start(Manager *m)
{
	Player *p = m->CreatePlayer(0);
	int n = 0;
	p->f14 = 1;
	p->active = 1;
	if (m->file)
		n = m->file->hdr->nScene;
	for (int i = 0; i < n; i++)
		m->EnableScene(i);
	m->play(p->scene, 0.0f);
}

namespace B2A {
void Calc(Manager *m)
{
	m->Calc();
}
}

namespace B2A {
void Draw(Manager *m)
{
	m->Draw();
}
}

void B2A::DeleteManager(Manager *m)
{
	ManagerNode *n = managerList.Find(m);
	if (!n)
		return;
	managerList.Remove(n);
	delete n;
}

void B2A::DeletePlayer(Player *p)
{
	for (ManagerNode *n = managerList.tail; n; n = (ManagerNode *)n->next) {
		if (n->manager->DeletePlayer(p))
			return;
	}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFileC2EP7InstDatiiPP16TBxAnmInitAssign); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFileC1EP7InstDatiiPP16TBxAnmInitAssign); }

B2A::B2aFile::~B2aFile()
{
	if (hdr)
		delete[] parts;
}

void B2A::B2aFile::ReAssign()
{
	int n = hdr->nParts;
	for (int i = 0; i < n; i++)
		parts[i].ReAssign();
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7ManagerC2EPNS_7B2aFileE); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7ManagerC1EPNS_7B2aFileE); }

B2A::Manager::~Manager()
{
	List<PlayerNode> *l = &list;
	DeleteManager(this);
	for (PlayerNode *n = l->tail; n; ) {
		Player *p = n->player;
		PlayerNode *next = (PlayerNode *)n->next;
		delete p;
		n = next;
	}
	l->Clear();
	delete[] scene;
}

void B2A::Manager::EnableScene(int i)
{
	Scene *s = &scene[i];
	s->enable = 1;
}

void B2A::Manager::DisableScene(int i)
{
	Scene *s = &scene[i];
	s->enable = 0;
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager12CreatePlayerEi); }
int B2A::Manager::DeletePlayer(Player *p)
{
	PlayerNode *n = list.Find(p);
	if (!n)
		return 0;
	list.Remove(n);
	delete n;
	return 1;
}
void B2A::Manager::RefreshOne(int i, bool clear)
{
	for (;;) {
		Object &o = scene[i];
		if (clear)
			o.Clear();
		else
			o.Refresh();
		if (o.link.child)
			RefreshOne(o.link.child, clear);
		if (!o.link.sibling)
			break;
		i = o.link.sibling;
	}
}
void B2A::Manager::Refresh()
{
	int n = file->hdr->nObject;
	for (int i = 0; i < n; i++)
		RefreshOne(i, false);
}

void B2A::Manager::SetFrame(float f)
{
	PlayerNode *p;

	for (p = list.tail; p; p = (PlayerNode *)p->next)
		p->player->frame = f;
}

float B2A::Manager::GetFrame()
{
	float f = 0.0f;
	PlayerNode *p;

	for (p = list.tail; p; p = (PlayerNode *)p->next)
		f = p->player->frame;
	return f;
}

void B2A::Manager::SetLoop(int v)
{
	PlayerNode *p;

	for (p = list.tail; p; p = (PlayerNode *)p->next)
		p->player->loop = v;
}

int B2A::Manager::GetLoop()
{
	return list.tail->player->loop;
}

void B2A::Manager::SetPause(int v)
{
	PlayerNode *p;

	for (p = list.tail; p; p = (PlayerNode *)p->next)
		p->player->pause = v;
}

int B2A::Manager::GetPause()
{
	return list.tail->player->pause;
}

void B2A::Manager::SetSpeed(float sp)
{
	for (PlayerNode *p = list.tail; p; p = (PlayerNode *)p->next)
		p->player->speed = sp;
}

float B2A::Manager::GetSpeed()
{
	return list.tail->player->speed;
}

float B2A::Manager::GetEndFrame()
{
	SceneEnt *e = &file->hdr->ent[list.tail->player->scene];
	return e->end - 2;
}

/* inline-asm cvt.w.s (rounds), as in cardlistCpyTtr2Int32 */
void B2A::Manager::SetEndFrame(float f)
{
	SceneEnt *e = &file->hdr->ent[list.tail->player->scene];
	float r;
	__asm__ volatile ("cvt.w.s %0, %1" : "=f"(r) : "f"(f));
	e->end = *(int *)&r + 2;
}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F18); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F1C); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F20); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F24); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F28); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F2C); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F30); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F34); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F38); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZZN3B2A7B2aFileC1EP7InstDatiiPP16TBxAnmInitAssignE12__FUNCTION__); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F44); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F50); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F58); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F70); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F84); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FA0); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FB0); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FB8); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FBC); }

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FDC); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager7CalcOneEPNS_6PlayerE); }

void B2A::Manager::Calc()
{
	Refresh();
	for (PlayerNode *p = list.tail; p; p = (PlayerNode *)p->next) {
		Player *pl = p->player;
		if (pl->active)
			CalcOne(pl);
	}
}
void B2A::Manager::DrawOne(int n)
{
	ScePspFMatrix4 *m = &mtx;
	draw(n, m, m, 0x80808080);
}
void B2A::Manager::Draw()
{
	int n = file->hdr->nObject;
	for (int i = 0; i < n; i++) {
		Scene &sc = scene[i];
		if (sc.enable)
			DrawOne(i);
	}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager4playEif); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager4drawEiP14ScePspFMatrix4S2_j); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERfRNS_8KeyArrayINS_4LOOPEEEf); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERiRNS_8KeyArrayINS_3PTNEEEf); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERfRNS_8KeyArrayINS_3FLTEEEf); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueER4FVECRNS_8KeyArrayINS_3FXYEEEf); }

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERNS_4RGBAERNS_8KeyArrayIS1_EEf); }

B2A::Object::Object()
{
	cur._8 = 0;
	Clear();
	Refresh();
	enable = 0;
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Object5ClearEv); }

void B2A::Object::Refresh()
{
	prev = cur;
}
void B2A::Object::MoveTo(FVEC &v)
{
	cur.pos = v;
}

void B2A::Object::Scale(float x, float y)
{
	cur.scale.Set(x, y, 0.0f, 0.0f);
}

B2A::Player::Player(int i)
{
	Set(i);
}

B2A::Player::~Player()
{
	DeletePlayer(this);
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Player3SetEi); }
extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _Z41__static_initialization_and_destruction_0ii_5A4F0);

void _ZN15SAMPLE_ANM_DATAC1Ev(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _GLOBAL__I__Z11GpPrim_Initv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _GLOBAL__D__Z11GpPrim_Initv);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
