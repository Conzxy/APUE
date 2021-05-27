/*
 * @version: 2021-5-22 19:59
 * @author: Conzxy
 * simple test of gettimeofday and clock_gettime
 */
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>


int main(){
	timespec tmp;
	timespec* tmp2;
	clock_gettime(CLOCK_REALTIME, &tmp);
	clock_gettime(CLOCK_REALTIME, tmp2);
	timeval val;
	gettimeofday(&val, NULL);

	printf("clock_gettime:%lu %lu\n", (unsigned long)tmp.tv_sec, (unsigned long)tmp.tv_nsec);
	printf("gettimeofday:%lu %lu\n", (unsigned long)val.tv_sec, (unsigned long)val.tv_usec);

	exit(0);

}
