/*
 * @author: Conzxy
 * @date: 2021-6-10
 * SIGCLD test
 */

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errorHandle.h>

static void sig_cld(int);

int
main()
{
	pid_t pid;
	
	if(signal (SIGCLD, sig_cld) == SIG_ERR)
		err_quit("signal handler of SIGCLD fialed");
	if((pid = fork()) < 0)
		err_quit("fork() failed");
	else if(pid == 0)
	{
		printf("child pid = %d\n", getpid());
		sleep(2);
		_exit(0);
	}
	
	printf("parent pid = %d\n", getpid());
	pause();
	exit(0);
}

static void
sig_cld(int signo)
{
	pid_t pid;
	
	printf("SIGCLD received\n");

	//if(signal(SIGCLD, sig_cld) == SIG_ERR)
		//err_quit("signal error");

	int status;
	if((pid = wait(&status)) < 0)
		err_quit("wait error");

	printf("pid = %d\n", pid);
}
