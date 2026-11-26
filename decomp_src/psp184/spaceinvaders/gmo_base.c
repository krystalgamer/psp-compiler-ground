#include "common.h"
#include "gmo_base_sdk.h"

void sceGmoBaseConstruct( SceGmoBase *base )
{
 if ( base == 0 ) return ;
 sceGmoSubjectConstruct( &( base->m_subject ) ) ;
 sceGmoObserverConstruct( &( base->m_parent ) ) ;
}

void sceGmoBaseDestruct( SceGmoBase *base )
{
 if ( base == 0 ) return ;
 sceGmoObserverDestruct( &( base->m_parent ) ) ;
 sceGmoSubjectDestruct( &( base->m_subject ) ) ;
}

void sceGmoBaseCopy( SceGmoBase *base, const SceGmoBase *src )
{
 if ( base == 0 || src == 0 ) return ;
 sceGmoSubjectCopy( &( base->m_subject ), &( src->m_subject ) ) ;
 sceGmoObserverCopy( &( base->m_parent ), &( src->m_parent ) ) ;
}

void sceGmoBaseAttachObserver( SceGmoBase *base, SceGmoObserver *observer )
{
 if ( base == 0 ) return ;
 sceGmoSubjectAttachObserver( &( base->m_subject ), observer ) ;
}

void sceGmoBaseDetachObserver( SceGmoBase *base, SceGmoObserver *observer )
{
 if ( base == 0 ) return ;
 sceGmoSubjectDetachObserver( &( base->m_subject ), observer ) ;
}

void sceGmoBaseSetParent( SceGmoBase *base, SceGmoSubject *parent )
{
 if ( base == 0 ) return ;
 sceGmoObserverSetSubject( &( base->m_parent ), parent ) ;
}

void sceGmoObserverConstruct( SceGmoObserver *observer )
{
 if ( observer == 0 ) return ;
 observer->m_subject = 0 ;
 observer->m_next = 0 ;
}

void sceGmoObserverDestruct( SceGmoObserver *observer )
{
 sceGmoObserverSetSubject( observer, 0 ) ;
}

void sceGmoObserverCopy( SceGmoObserver *observer, const SceGmoObserver *src )
{
 sceGmoObserverSetSubject( observer, sceGmoObserverGetSubject( src ) ) ;
}

void sceGmoObserverSetSubject( SceGmoObserver *observer, SceGmoSubject *subject )
{
 sceGmoSubjectAttachObserver( subject, observer ) ;
}

void sceGmoSubjectConstruct( SceGmoSubject *subject )
{
 if ( subject == 0 ) return ;
 subject->m_observers = 0 ;
}

void sceGmoSubjectDestruct( SceGmoSubject *subject )
{
 if ( subject == 0 ) return ;
 SceGmoObserver *curr = subject->m_observers ;
 while ( curr != 0 ) {
  SceGmoObserver *next = curr->m_next ;
  curr->m_subject = 0 ;
  curr = next ;
 }
 subject->m_observers = 0 ;
}

void sceGmoSubjectCopy( SceGmoSubject *subject, const SceGmoSubject *src )
{
 ;
}

void sceGmoSubjectAttachObserver( SceGmoSubject *subject, SceGmoObserver *observer )
{
 if ( observer == 0 ) return ;
 SceGmoSubject *old = observer->m_subject ;
 if ( old == subject ) return ;
 sceGmoSubjectDetachObserver( old, observer ) ;
 observer->m_subject = subject ;
 if ( subject != 0 ) {
  observer->m_next = subject->m_observers ;
  subject->m_observers = observer ;
 }
}

void sceGmoSubjectDetachObserver( SceGmoSubject *subject, SceGmoObserver *observer )
{
 if ( subject == 0 || observer == 0 ) return ;
 SceGmoObserver *prev = 0 ;
 SceGmoObserver *curr = subject->m_observers ;
 while ( curr != 0 ) {
  if ( curr == observer ) {
   if ( prev != 0 ) {
    prev->m_next = curr->m_next ;
   } else {
    subject->m_observers = curr->m_next ;
   }
   observer->m_subject = 0 ;
   return ;
  }
  prev = curr ;
  curr = curr->m_next ;
 }
}

