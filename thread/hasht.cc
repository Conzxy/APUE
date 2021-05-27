#include "common.h"
#include "hasht.h"
#include <assert.h>
#include <unistd.h>

using namespace zxy;

ConHashTable ht{};

void fn1(){
	for(int i = 1; i <= 100; ++i){
		ht.insert(i);
	}

}

void fn2(){
	sleep(1);
	auto id10 = ht.find(10);
	
	for(int i = 0; i != 10; ++i){
		ht.foo_hold(id10);
	}

	printf("id=10's count: %d\n", id10->count);
}

int main(){	
	Thread thr1{fn1, "th1"};
	Thread thr2{fn2, "th2"};

	thr1.start();
	thr2.start();
	
	thr1.join();
	thr2.join();
	exit(0);
}
