/*
 * @version: 2021-5-22
 * @author: Conzxy
 * timedlock test
 */

#include "common.h"

using namespace zxy;

int main(){
	MutexLock lock{};
	lock.lock();
	printf("Mutex is locked\n");
	

	timespec tout;
	clock_gettime(CLOCK_REALTIME, &tout);
	auto tmp = localtime(&tout.tv_sec);
	
	char buf[MAXLINE];
	strftime(buf, sizeof(buf), "%r", tmp);
	printf("current time is %s\n", buf);

	tout.tv_sec += 10;
	
	lock.timedlock(&tout);

	clock_gettime(CLOCK_REALTIME, &tout);
	tmp = localtime(&tout.tv_sec);
	strftime(buf, sizeof(buf), "%r", tmp);
	printf("the time is now %s\n", buf);
		
	exit(0);
}
