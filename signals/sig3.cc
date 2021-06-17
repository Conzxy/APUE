/*
 * @author: Conzxy
 * @version: 2021-6-10
 * sleep.ver1
 * three point need to improve
 * 1):caller if already set alarm?
 *	  check alarm's return value
 *	  if return value less than argument, wait until the existing alarm expipres
 *	  otherwise, reset alarm
 * 2):reset the SIGALRM signal handler, we should restore the return value of signal()
 *    and reset the signal handler before return from sleep
 * 3):pause(): However, timer maybe expire before the call to pause()
 *    solution: 1) setjmp & longjmp
 *				2) sigpromask & sigsuspend
 *
 * improved version in sig4.cc
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errorHandle.h>

static void sig_alrm(int signo);
static unsigned int sleep1(unsigned int seconds);

int main()
{
	sleep(10);

	return 0; 
}

static void 
sig_alrm(int signo)
{
	//nothing to do
}

static unsigned int 
sleep1(unsigned int seconds)
{
	if( signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_quit("Failed in setting signal alarm");

	alarm(seconds);
	pause();

	return alarm(0);
}
