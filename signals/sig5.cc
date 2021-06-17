/*
 * @author: Conzxy
 * @version: 2021-6-11
 * common and simple application of alarm
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errorHandle.h>
#include <wchar.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sigAlrm(int);

int
main()
{
	if(signal(SIGALRM, sigAlrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");
	
	if(setjmp(env_alrm) != 0)
		err_quit("read timeout\n");

	char buf[MAXLINE];
	int n;

	alarm(10);
//if time period between alarm() and read() > 10
//read maybe block forever except signal occurs
//solution: longjmp
	while(true)
	{
		n = read(STDIN_FILENO, buf, MAXLINE);
		if(n == 0)
			break;
		else if(n < 0)
			err_sys("read error");
		write(STDOUT_FILENO, buf, n);
	}

	alarm(0);

	exit(0);
}

static void
sigAlrm(int)
{
	fputs("sigAlrm handler\n", stdout);
	longjmp(env_alrm, 1);
}
