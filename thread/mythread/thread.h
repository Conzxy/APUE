/*
 * @version: 0.1 2021-5-23 
 * @author: Conzxy
 * Thread: pthread wrapper
 */

#ifndef _THREAD_H
#define _THREAD_H

#include <noncopyable.h>
#include <pthread.h>
#include <functional>

namespace zxy{

class Thread : public noncopyable {
public:
	using Threadfunc = std::function<void()>;

public:
	Thread(Threadfunc func, std::string const& name);
	~Thread();

	void start();
	void join();
	void setBarriered(bool is_barriered) noexcept
	{ is_barriered_ = is_barriered; }
private:

	void setDefaultname();
private:
	Threadfunc	func_;
	bool		is_started_;
	bool		is_joined_;
	bool		is_barriered_;
	pthread_t	pthreadId_;
	std::string name_;

	//static Atomic numCreated_
};

}//namespace zxy
#endif
