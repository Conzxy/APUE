/*
 * @version: 2021-5-21 23:24
 * @author: Conzxy
 * pthread_join test
 */

#include "common.h"
#include <pthread.h>

int g_val1 = 1;
int g_val2 = 2;

void* thr_fn1(void* arg){
	printf("thread1 returning\n");
	return &g_val1;
}

void* thr_fn2(void* arg){
	printf("thread2 returning\n");
	return &g_val2;
}

int main(){
	int err;
	pthread_t tid1;
	pthread_t tid2;

	int* ret;
	
	pthread_create(&tid1, NULL, thr_fn1, NULL);
	pthread_create(&tid2, NULL, thr_fn2, NULL);

	pthread_join(tid1, (void**)&ret);
	printf("ret value:%d\n", *ret);

	pthread_join(tid2, (void**)&ret);
	printf("ret value:%d\n", *ret);

	exit(0);

}
