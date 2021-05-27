/*
 * @version: 2021-5-22
 * @author: Conzxy
 */

#ifndef _MUTEXLOCK_H
#define _MUTEXLOCK_H

#include <pthread.h>
#include <stdexcept>
#include <errorHandle.h>
#include <noncopyable.h>
#include "pthreadM.h"

namespace zxy{

class MutexException : public std::runtime_error{
public:
	using base = std::runtime_error;
public:
	explicit MutexException(char const* msg)
		: base{msg}{}
};

class MutexLock : public noncopyable{
private:
	pthread_mutex_t mutex_;

public:
	MutexLock(){
		int err = pthread_mutex_init(&mutex_, NULL);
		if(err != 0){
			char buf[MAXLINE];
			strcpy(buf, "can't init pthread_mutex_t");
			snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1,
					": %s", strerror(err));

			throw MutexException{buf};
		}
	}
	
	~MutexLock(){
		TCHECK(pthread_mutex_destroy(&mutex_));
	}

	void lock(){
		TCHECK(pthread_mutex_lock(&mutex_));
	}

	void trylock(){
		TCHECK(pthread_mutex_trylock(&mutex_));
	}

	void unlock(){
		TCHECK(pthread_mutex_unlock(&mutex_));
	}

	void timedlock(timespec const* tout){
		TCHECK(pthread_mutex_timedlock(&mutex_, tout));
	}

	pthread_mutex_t& pthreadMutex(){
		return mutex_;
	}

};

//pthread_mutex_t simple RAII wrapper
class MutexGuard {
private:
	MutexLock& mutex_;
public:
	explicit MutexGuard(MutexLock& mutex)
		: mutex_{mutex}
	{ mutex_.lock(); }

	~MutexGuard()
	{ mutex_.unlock(); };
};

}//namespace zxy
#endif
