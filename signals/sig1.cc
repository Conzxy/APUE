#include <signal.h>
#include <stdio.h>
#include <errorHandle.h>
#include <unistd.h>

static void sigUser(int signo)
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if ( signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		err_dump("received signal: %d\n", signo);
}

int main()
{
	if (signal(SIGUSR1, sigUser) == SIG_ERR)
		err_sys("can't catch SIGUSR1\n");
	if (signal(SIGUSR2, sigUser) == SIG_ERR)
		err_sys("can't catch SIGUSR2\n");

	for(;;)
		pause();
}
