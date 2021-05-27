#include "common.h"
#include "mythread/mutexlock.h"
#include <algorithm>
#include <assert.h>
#include <cstdint>
#include <pthread.h>
#include <type_traits>
#include <iterator>
#include <random>
#include <sys/time.h>
#include <functional>
#include <limits.h>

#define PRINT_SWITCH 0
using namespace zxy;
using namespace std;

#define quicksort sort

constexpr int gNumThread = 8;
constexpr int gNumElement = 800000;
constexpr int gNumPerThread = gNumElement / gNumThread;

/*
 * @brief: merge result of per threads
 *	before call this function, you should sort per threads at first * @para: void
 * @return: void
 */
template<std::size_t numthread = 1,typename RI1, typename RI2, typename BinaryPred>
void merge_impl(RI1 first1, RI1 last1,
				RI2 first2, RI2 last2,
				BinaryPred pred)
{
	int num = last1 - first1;
	int numperthread = num / numthread;

	int idx[numthread];
	//idx: record the first element index of sorted range
	for(int i = 0; i < numthread; ++i){
		idx[i] = i * numperthread;
	}

	//ridx:result index 
	for(int ridx = 0; ridx != num; ++ridx){
		int min_element = INT_MAX;
		int min_idx = 0;
		for(int tidx = 0; tidx != numthread; ++tidx){
			if((idx[tidx] < (tidx + 1) * numperthread) && (pred(*(first1 + idx[tidx]), min_element))){
				min_element = *(first1 + idx[tidx]);
				min_idx = tidx;
			}
		}
		*(first2 + ridx) = *(first1 + idx[min_idx]);
		++idx[min_idx];
	}
}

template<std::size_t numthread = 1, typename RI1, typename RI2, 
	     typename V = typename iterator_traits<RI1>::value_type,
		 typename BinaryPred = std::less<V>
		>
void mymerge(RI1 first1, RI1 last1, 
		   RI2 first2, RI2 last2,
		   BinaryPred pred = {})
{
	using V1 = typename iterator_traits<RI1>::value_type;
	using V2 = typename iterator_traits<RI2>::value_type;
	
	static_assert((is_integral<V1>::value || is_floating_point<V1>::value) && 
				  (is_integral<V2>::value || is_floating_point<V2>::value), 
				  "value_type must be integral or floating point\n");
	static_assert(is_convertible<V1, V2>::value || is_convertible<V2, V1>::value, 
				  " value_type doesn't match");
	assert(last1 - first1 == last2 - first2);

	merge_impl<numthread>(first1, last1, 
						  first2, last2,
						  pred);
}

int gIdx;
MutexLock lock{};
pthread_barrier_t b;
int nums[gNumElement];
int res[gNumElement];

void fun(){
	//However, if you assign idx to gIdx, other thread maybe enter the critical section
	//so, the assignment action of gIdx and idx need synchronization
	int  idx = gIdx;	
	printf("idx: %d\n", idx);//observe the "idx:...", you can find some idx are same
	quicksort(nums + idx, nums + idx + gNumPerThread);
	printf("%d~%d\n", idx, idx + gNumPerThread);
	pthread_barrier_wait(&b);
}

void* fun2(void* arg_){
	int* arg = static_cast<int*>(arg_);
	int idx = *arg;
	printf("idx: %d\n", idx);//observe the "idx:...", you can find some idx are same
	quicksort(nums + idx, nums + idx + gNumPerThread);
	printf("%d~%d\n", idx, idx + gNumPerThread);
	pthread_barrier_wait(&b);
	
	return NULL;
}

int main()
{
	struct timeval beg, end;


	std::default_random_engine dre{};
	std::uniform_int_distribution<int> di(0, 9999);
	for(int i = 0; i != gNumElement; ++i){
		nums[i] = di(dre);
		res[i] = 0;
	}

	gettimeofday(&beg, NULL);
	pthread_barrier_init(&b, NULL, gNumThread + 1);
	
	for(int i = 0; i != gNumThread; ++i){
		auto g = MutexGuard{lock};
		int idx = i * gNumPerThread;
		//gIdx = i * gNumPerThread;
		Thread thr([idx](){
						quicksort(nums + idx, nums + idx + gNumPerThread);

						pthread_barrier_wait(&b);
					},
				   "thread");

		//Thread thr(fun, "thread");
		thr.setBarriered(true);
		thr.start();
		/*pthread_t tid;
		TCHECK(pthread_create(&tid, NULL, fun2, (void*)&idx));*/
	}
	
	pthread_barrier_wait(&b);
	pthread_barrier_destroy(&b);

	mymerge<gNumThread>(&*nums, nums + gNumElement, 
						&*res, res + gNumElement);
	
	gettimeofday(&end, NULL);
	
	constexpr int useconds = 1000000;
	const auto startusec = beg.tv_sec * useconds + beg.tv_usec;
	const auto endusec = end.tv_sec * useconds + end.tv_usec;

	const auto time = static_cast<double>(endusec - startusec) / useconds;

	printf("sort total took %.4f\n", time);

#if PRINT_SWITCH
	for(int i = 0; i <= gNumElement; ++i){
		if(i % 10 == 0)
			printf("%d~%d: ", i + 1, i + 10);

		printf("%d ", res[i]);
		
		if((i + 1) % 10 == 0)
			puts("");
	}
#endif
}
