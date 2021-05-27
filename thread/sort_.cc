#include <algorithm>
#include <stdio.h>
#include <random>
#include <sys/time.h>

constexpr int gNumElement = 800000;

using namespace std;

int main(){
	default_random_engine dre{};

	uniform_int_distribution<int> di(0, 9999);

	int nums[gNumElement];

	for(int i = 0; i != gNumElement; ++i){
		nums[i] = di(dre);
	}
	
	struct timeval beg, end;

	gettimeofday(&beg, NULL);

	sort(nums, nums + gNumElement);

	gettimeofday(&end, NULL);

	constexpr uint32_t useconds = 1000000;
	const auto  b = beg.tv_sec * useconds + beg.tv_usec;
	const auto  e = end.tv_sec * useconds + end.tv_usec;

	const auto time = static_cast<double>(e - b) / useconds;

	printf("time:%.4f\n", time);
	exit(0);
}
