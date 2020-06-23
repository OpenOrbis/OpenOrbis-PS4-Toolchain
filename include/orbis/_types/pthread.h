#pragma once 

#include <stdint.h>

#define ORBIS_PTHREAD_DESTRUCTOR_ITERATIONS	4
#define ORBIS_PTHREAD_KEYS_MAX			256
#define ORBIS_PTHREAD_STACK_MIN			PTHREAD_STACK_MIN
#define ORBIS_PTHREAD_THREADS_MAX			__ULONG_MAX
#define ORBIS_PTHREAD_BARRIER_SERIAL_THREAD	-1
#define ORBIS_PTHREAD_DETACHED            0x1
#define ORBIS_PTHREAD_INHERIT_SCHED       0x4
#define ORBIS_PTHREAD_NOFLOAT             0x8
#define ORBIS_PTHREAD_CREATE_DETACHED     ORBIS_PTHREAD_DETACHED
#define ORBIS_PTHREAD_CREATE_JOINABLE     0
#define ORBIS_PTHREAD_EXPLICIT_SCHED      0
#define ORBIS_PTHREAD_PROCESS_PRIVATE     0
#define ORBIS_PTHREAD_PROCESS_SHARED      1
#define ORBIS_PTHREAD_CANCEL_ENABLE		0
#define ORBIS_PTHREAD_CANCEL_DISABLE		1
#define ORBIS_PTHREAD_CANCEL_DEFERRED		0
#define ORBIS_PTHREAD_CANCEL_ASYNCHRONOUS         2
#define ORBIS_PTHREAD_CANCELED		((void *) 1)
#define ORBIS_PTHREAD_NEEDS_INIT  0
#define ORBIS_PTHREAD_DONE_INIT   1
#define ORBIS_PTHREAD_ONCE_INIT   { ORBIS_PTHREAD_NEEDS_INIT, NULL }
#define ORBIS_PTHREAD_MUTEX_INITIALIZER	NULL
#define ORBIS_PTHREAD_ADAPTIVE_MUTEX_INITIALIZER	((pthread_mutex_t)1)
#define ORBIS_PTHREAD_COND_INITIALIZER	NULL
#define ORBIS_PTHREAD_RWLOCK_INITIALIZER	NULL
#define pthread_condattr_default    NULL
#define pthread_mutexattr_default   NULL
#define pthread_attr_default        NULL
#define ORBIS_PTHREAD_PRIO_NONE           0
#define ORBIS_PTHREAD_PRIO_INHERIT        1
#define ORBIS_PTHREAD_PRIO_PROTECT        2
#define ORBIS_PTHREAD_MUTEX_DEFAULT		ORBIS_PTHREAD_MUTEX_ERRORCHECK

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum OrbisPthreadMutextype {
	PTHREAD_MUTEX_ERRORCHECK = 1,	
	PTHREAD_MUTEX_RECURSIVE = 2,	
	PTHREAD_MUTEX_NORMAL = 3,	
	PTHREAD_MUTEX_ADAPTIVE = 4,	
	PTHREAD_MUTEX_TYPE_MAX
} OrbisPthreadMutextype;

typedef enum ScePthreadRwlocktype {
	PTHREAD_RWLOCK_NORMAL = 1,
	PTHREAD_RWLOCK_PREFER_READER = 2,
	PTHREAD_RWLOCK_TYPE_MAX
} OrbisPthreadRwlocktype;


typedef pthread_once_t            OrbisPthreadOnce;
typedef pthread_barrierattr_t     OrbisPthreadBarrierattr;
typedef pthread_key_t             OrbisPthreadKey;
typedef pthread_rwlock_t          OrbisPthreadRwlock;
typedef pthread_rwlockattr_t      OrbisPthreadRwlockattr;
typedef pthread_attr_t            OrbisPthreadAttr;
typedef pthread_barrier_t         OrbisPthreadBarrier;
typedef pthread_mutex_t           OrbisPthreadMutex;
typedef pthread_condattr_t        OrbisPthreadCondattr;
typedef pthread_cond_t            OrbisPthreadCond;
typedef pthread_t                 OrbisPthread;
typedef pthread_mutexattr_t       OrbisPthreadMutexattr;

#ifdef __cplusplus
}
#endif


