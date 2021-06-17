/*
 * @author: Conzxy
 * @version: 2021-6-11
 * promask demo
 * block SIGQUIT
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errorHandle.h>

static void sigQuit(int);

int
main()
{
	if(signal(SIGQUIT, sigQuit) == SIG_ERR)
		err_sys("signal(SIGQUIT) error");

	sigset_t newset, oldset;

	sigemptyset(&newset);
	sigaddset(&newset, SIGQUIT);

	if(sigprocmask(SIG_BLOCK, &newset, &oldset) < 0)
		err_sys("SIG_BLOCK error");

	sleep(5);
	
	sigset_t pendset;
	if(sigpending(&pendset) < 0)
		err_sys("sigpending error");
	if(sigismember(&pendset, SIGQUIT))
		printf("\nSIGQUIT pending\n");

	if(sigprocmask(SIG_SETMASK, &oldset, NULL) < 0)
		err_sys("SIG_SETMASK error");

	printf("SIGQUIT unblocked\n");

	sleep(5);

	_exit(0);
}

static void
sigQuit(int)
{
	printf("caught SIGQUIT\n");
	if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		err_sys("can't reset SIGQUIT");
}
