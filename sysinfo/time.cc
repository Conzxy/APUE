/*
 * @version: 2021-5-22
 * @author: Conzxy
 * test unix time
 */
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

constexpr int day = 86400;
constexpr int year = day * 365;

int main(){
	time_t t;
	time(&t);
	tm* tmp = localtime(&t);

	char buf1[16];
	char buf2[64];

	//maxsize(2nd parameter) including '\0'
	if(strftime(buf1, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length is too small\n");
	else
		printf("%s\n", buf1);

	if(strftime(buf2, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0)
		printf("buffer length is too small\n");
	else
		printf("%s\n", buf2);
}
