#include "common.h"

/* declarations recovered from DWARF */
typedef struct SceGmoBase SceGmoBase;
struct SceGmoBase;
struct SceGmoSubject;
struct SceGmoObserver;
struct SceGmoObserver { /* size 0xc */
    struct SceGmoObserver *m_next;
    struct SceGmoSubject *m_subject;
    void *m_reserved;
};
struct SceGmoSubject { /* size 0x4 */
    struct SceGmoObserver *m_observers;
};
struct SceGmoBase { /* size 0x10 */
    struct SceGmoSubject m_subject;
    struct SceGmoObserver m_parent;
};
typedef struct SceGmoObserver SceGmoObserver;
typedef struct SceGmoSubject SceGmoSubject;

void sceGmoBaseConstruct(SceGmoBase *base);
void sceGmoBaseDestruct(SceGmoBase *base);
void sceGmoBaseCopy(SceGmoBase *base, const SceGmoBase *src);
void sceGmoBaseAttachObserver(SceGmoBase *base, SceGmoObserver *observer);
void sceGmoBaseDetachObserver(SceGmoBase *base, SceGmoObserver *observer);
void sceGmoBaseSetParent(SceGmoBase *base, SceGmoSubject *parent);
void sceGmoObserverConstruct(SceGmoObserver *observer);
void sceGmoObserverDestruct(SceGmoObserver *observer);
void sceGmoObserverCopy(SceGmoObserver *observer, const SceGmoObserver *src);
static SceGmoSubject *sceGmoObserverGetSubject(const SceGmoObserver *observer);
void sceGmoObserverSetSubject(SceGmoObserver *observer, SceGmoSubject *subject);
void sceGmoSubjectConstruct(SceGmoSubject *subject);
void sceGmoSubjectDestruct(SceGmoSubject *subject);
void sceGmoSubjectCopy(SceGmoSubject *subject, const SceGmoSubject *src);
void sceGmoSubjectAttachObserver(SceGmoSubject *subject, SceGmoObserver *observer);
void sceGmoSubjectDetachObserver(SceGmoSubject *subject, SceGmoObserver *observer);
void sceGmoBaseConstruct(SceGmoBase *base)
{
	if (base == NULL)
		return;
	sceGmoSubjectConstruct(&base->m_subject);
	sceGmoObserverConstruct(&base->m_parent);
}

void sceGmoBaseDestruct(SceGmoBase *base)
{
	if (base == NULL)
		return;
	sceGmoObserverDestruct(&base->m_parent);
	sceGmoSubjectDestruct(&base->m_subject);
}

void sceGmoBaseCopy(SceGmoBase *base, const SceGmoBase *src)
{
	if (base == NULL || src == NULL)
		return;
	sceGmoSubjectCopy(&base->m_subject, &src->m_subject);
	sceGmoObserverCopy(&base->m_parent, &src->m_parent);
}

void sceGmoBaseAttachObserver(SceGmoBase *base, SceGmoObserver *observer)
{
	if (base == NULL)
		return;
	sceGmoSubjectAttachObserver(&base->m_subject, observer);
}

void sceGmoBaseDetachObserver(SceGmoBase *base, SceGmoObserver *observer)
{
	if (base == NULL)
		return;
	sceGmoSubjectDetachObserver(&base->m_subject, observer);
}

void sceGmoBaseSetParent(SceGmoBase *base, SceGmoSubject *parent)
{
	if (base == NULL)
		return;
	sceGmoObserverSetSubject(&base->m_parent, parent);
}

void sceGmoObserverConstruct(SceGmoObserver *observer)
{
	if (observer == NULL)
		return;
	observer->m_subject = NULL;
	observer->m_next = NULL;
}

void sceGmoObserverDestruct(SceGmoObserver *observer)
{
	sceGmoObserverSetSubject(observer, NULL);
}

void sceGmoObserverCopy(SceGmoObserver *observer, const SceGmoObserver *src)
{
	sceGmoObserverSetSubject(observer, (src == NULL) ? NULL : src->m_subject);
}

void sceGmoObserverSetSubject(SceGmoObserver *observer, SceGmoSubject *subject)
{
	sceGmoSubjectAttachObserver(subject, observer);
}

void sceGmoSubjectConstruct(SceGmoSubject *subject)
{
	if (subject == NULL)
		return;
	subject->m_observers = NULL;
}

void sceGmoSubjectDestruct(SceGmoSubject *subject)
{
	SceGmoObserver *curr;

	if (subject == NULL)
		return;
	for (curr = subject->m_observers; curr != NULL; ) {
		SceGmoObserver *next = curr->m_next;
		curr->m_subject = NULL;
		curr = next;
	}
	subject->m_observers = NULL;
}

void sceGmoSubjectCopy(SceGmoSubject *subject, const SceGmoSubject *src)
{
}

void sceGmoSubjectAttachObserver(SceGmoSubject *subject, SceGmoObserver *observer)
{
	SceGmoSubject *old;

	if (observer == NULL)
		return;
	old = observer->m_subject;
	if (old == subject)
		return;
	sceGmoSubjectDetachObserver(old, observer);
	observer->m_subject = subject;
	if (subject == NULL)
		return;
	observer->m_next = subject->m_observers;
	subject->m_observers = observer;
}

void sceGmoSubjectDetachObserver(SceGmoSubject *subject, SceGmoObserver *observer)
{
	SceGmoObserver *prev;
	SceGmoObserver *curr;

	if (subject == NULL || observer == NULL)
		return;
	prev = NULL;
	for (curr = subject->m_observers; curr != NULL; curr = curr->m_next) {
		if (curr == observer) {
			if (prev != NULL)
				prev->m_next = curr->m_next;
			else
				subject->m_observers = curr->m_next;
			observer->m_subject = NULL;
			return;
		}
		prev = curr;
	}
}
