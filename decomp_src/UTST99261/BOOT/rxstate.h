#ifndef RXSTATE_H
#define RXSTATE_H
/* Coroutine-style state machines: each yield records its __LINE__ as the
   resume point and a switch jumps back there on the next call.  The struct
   is from DWARF; the macros are reconstructed from the code they produce. */

typedef struct rxStateMachine {
	unsigned char status;
	unsigned char nest;
	unsigned short adrs;
	short stack[6];
} rxStateMachine;

static __inline__ void rxStateRestart(rxStateMachine *self, unsigned short index)
{
	self->status = 0;
	self->adrs = index;
	self->nest = sizeof(self->stack) / sizeof(self->stack[0]);
}

static __inline__ void rxStateInit(rxStateMachine *self)
{
	self->status = 0;
	self->adrs = 0;
	self->nest = sizeof(self->stack) / sizeof(self->stack[0]);
}

#define RX_BEGIN(sm) \
	{ \
		rxStateMachine *_jp = (sm); \
		short *_stack = &_jp->stack[_jp->nest]; \
		int _adrs = _jp->adrs; \
		if ((char)_jp->status >= 0) \
			switch (_adrs) { \
			case 0:

/* return to the caller; the next call resumes here */
#define RX_YIELD() \
	do { \
		_jp->adrs = __LINE__; \
		goto rx_end; \
	case __LINE__:; \
	} while (0)

/* make this the resume point without returning */
#define RX_MARK() \
	_jp->adrs = __LINE__; \
	case __LINE__:

/* return to the caller; the next call resumes at the last mark */
#define RX_LEAVE()	goto rx_end

#define RX_END() \
			} \
	rx_end: \
		_jp->nest = _stack - _jp->stack; \
	}

#endif
