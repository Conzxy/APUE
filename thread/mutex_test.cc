#include "common.h"

using namespace zxy;

struct foo{
	int			count;
	MutexLock	lock;
	int			id;
};

foo* foo_alloc(int id){
	
	foo* fp;
	try{
		fp = new foo{};
		fp->count = 1;
		fp->id = id;
		
		return fp;
		
	}catch(MutexException const& me){
		printf("%s", me.what());
	}catch(std::bad_alloc const& ae){
		printf("%s", ae.what());
	}

	delete fp;
	return nullptr;
}

void foo_hold(foo* fp){
	MutexGuard mutex(fp->lock);	
	fp->count++;
	printf("now:%d\n", fp->count);
}

void foo_rele(foo* fp){
	MutexGuard mutex(fp->lock);
	if(--fp->count == 0){
		delete fp;
	}
	printf("now:%d\n", fp->count);
}

auto fp = foo_alloc(1);

void fn1(){

	for(int i = 0; i <= 100; ++i)
		foo_hold(fp);

}

void fn2(){

	for(int i = 0;i <= 100; ++i)
		foo_rele(fp);

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
