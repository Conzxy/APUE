/*
 * @author: Conzxy
 * @version: 2021-6-10
 * sleep.ver2
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <errorHandle.h>
#include "/home/conzxy/zxy/time/measuretime.h"

static jmp_buf env_alrm;

static void sig_alrm(int);
static void sig_int(int);
static void sig_usr1(int);

static unsigned sleep2(unsigned);

int
main()
{
	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIG_INT) error");

	auto unslept = sleep2(5);
	printf("sleep2 returned:%u\n", unslept);

	return 0;
}

static void
sig_alrm(int signo)
{
	longjmp(env_alrm, 1);
	//set flag = 1, skip pause
}

static unsigned
sleep2(unsigned seconds)
{
	void(*alrm_handler)(int);
	if((alrm_handler =  signal(SIGALRM, sig_alrm)) == SIG_ERR)
		return seconds;
	
	if(setjmp(env_alrm) == 0)
	{
		auto remain_seconds = alarm(seconds);
		if(remain_seconds > 0 && remain_seconds < seconds)
			alarm(remain_seconds);		//reset alarm
		
		printf("pause before\n");

		pause();
	}
	
	if(signal(SIGALRM, alrm_handler) == SIG_ERR)
		err_ret("Failed in setting previous alrm_handler");	

	return alarm(0);
}

static void
sig_int(int signo)
{
	printf("\nsig_int starting\n");

	{
		MEASURETIME(loop, "loop");
	for(int i = 0; i < 300000; ++i)
		for(int j = 0; j < 4000; ++j)
			int k = i * j;
	}
	printf("\nsig_int ending\n");
}

static void
sig_usr1(int signo)
{
	
}
