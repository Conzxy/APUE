/*
 * @version: 2021-5-24
 * @author: Conzxy
 */

#include <stdio.h>
#include <unistd.h>
#include "common.h"

using namespace zxy;

struct msg{
	msg* next;
	const char* str;

};

struct msg* WorkQ = nullptr;

MutexLock QLock{};
Condition QReady{QLock};

void process_msg(){
	msg* mp;
	for(int i = 0; i < 1; ++i){
		QLock.lock();
		while(WorkQ == nullptr){
			QReady.wait();
		}
		mp = WorkQ;
		WorkQ = WorkQ->next;

		QLock.unlock();
		printf("message: %s", mp->str);

	}
}

void enqueue_msg(msg* mp){
	QLock.lock();

	mp->next = WorkQ;
	WorkQ = mp;

	QLock.unlock();

	QReady.notify();
}

auto m1 = new msg{nullptr, "m1"};
auto m2 = new msg{nullptr, "m2"};

void fun1(){
	puts("Here is fun1");
	enqueue_msg(m2);
}

void fun2(){
	puts("Here is fun2");
	process_msg();
}

int main(){
	Thread thr1(fun1, "1");
	Thread thr2(fun2, "2");
	
	thr2.start();
	thr1.start();
	thr1.join();
	thr2.join();
	//thr1.join();
	//thr2.join();
	
	delete m1;
	delete m2;
	return 0;
}
