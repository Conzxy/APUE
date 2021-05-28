#include "common.h"

using namespace zxy;

AtomicInt32 counter;
Barrier barrier;

constexpr int NumThread = 100;

int main(){

	barrier.start(NumThread + 1);
	for(int i = 0; i != NumThread; ++i){
		Thread thr([](){
						counter.increment();
						barrier.wait();
					});

		thr.start();
	}

	barrier.wait();

	printf("now cnt: %d\n", counter.get());

}
