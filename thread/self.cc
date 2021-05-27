/*
 * @version: 2021-5-21 22:51
 * @author: Conzxy
 * pthread_self
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errorHandle.h>

using ul = unsigned long;

void printIDs(char const* s){
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s pid %lu tid %lu (0x%lx)\n", s, (ul)pid, (ul)tid, (ul)tid);
}

void* thr_fn(void* arg){
	printIDs("new thread: ");
	return NULL;
}

int main(){
	int err;
	pthread_t thr_1;
	err = pthread_create(&thr_1, NULL, thr_fn, NULL);
	if(err != 0)
		err_exit(err, "can't create thread");

	printIDs("main thread: ");
	
	pthread_exit(NULL);

}
