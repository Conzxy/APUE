#include "common.h"
#include <algorithm>
#include <assert.h>
#include <random>
#include <sys/time.h>
#include "mythread/mutexlock.h"
#include "sort.h"
#include "/home/conzxy/zxy/time/measuretime.h"

#define PRINT_SWITCH 1
using namespace zxy;
using namespace std;

#define quicksort sort

constexpr int gNumThread = 8;
constexpr int gNumElement = 800000;
constexpr int gNumPerThread = gNumElement / gNumThread;

int gIdx;
MutexLock lock{};
pthread_barrier_t b;
double nums[gNumElement];
double res[gNumElement];

void fun();
void* fun2(void* arg_);


int main()
{
	struct timeval beg, end;

	std::default_random_engine dre{};
	std::uniform_int_distribution<int> di(0, 9999);
	std::uniform_real_distribution<double> dd(0, 9999.0);
	
	for(int i = 0; i != gNumElement; ++i){
		nums[i] = dd(dre);
		res[i] = 0;
	}

	gettimeofday(&beg, NULL);
	pthread_barrier_init(&b, NULL, gNumThread + 1);
	
	{
		MEASURETIMEty(1, "quicksort(mutilthread)",  TimeType::microseconds);
		for(int i = 0; i != gNumThread; ++i){
			int idx = i * gNumPerThread;
			//printf("idx addr: %p\n", &idx);
			gIdx = i * gNumPerThread;

			Thread thr([idx](){
							quicksort(nums + idx, nums + idx + gNumPerThread);
							pthread_barrier_wait(&b);
						},
					   "thread");

			//Thread thr(fun, "thread");
			thr.setBarriered(true);
			thr.start();
		}
	
		pthread_barrier_wait(&b);
		pthread_barrier_destroy(&b);

		mymerge<gNumThread>(&*nums, nums + gNumElement, 
							&*res, res + gNumElement);
	}	
	

#if PRINT_SWITCH
	for(int i = 0; i <= gNumElement; ++i){
		if(i % 10 == 0)
			printf("%d~%d: ", i + 1, i + 10);

		printf("%.3f ", res[i]);
		
		if((i + 1) % 10 == 0)
			puts("");
	}
#endif
}

void fun(){
	//However, if you assign idx to gIdx, other thread maybe enter the critical section
	//so, the assignment action of gIdx and idx need synchronization
	lock.lock();
	int  idx = gIdx;	
	lock.unlock();
	printf("idx: %d\n", idx);//note the "idx:...", you can find some idx are same
	quicksort(nums + idx, nums + idx + gNumPerThread);
	pthread_barrier_wait(&b);
}

void* fun2(void* arg_){
	lock.lock();	
	int* arg = static_cast<int*>(arg_);
	lock.unlock();
	//printf("arg addr: %p\n", arg);
	int idx = *arg;
	
	printf("idx: %d\n", idx);//observe the "idx:...", you can find some idx are same
	quicksort(nums + idx, nums + idx + gNumPerThread);
	pthread_barrier_wait(&b);
	
	return NULL;
}
