/*
 * @author: Conzxy
 * @version: 2021-6-13
 * implement of PrintMask()
 */

#include <csignal>
#include <signal.h>
#include <errorHandle.h>

#define PRINT_MASK_IF(curMask, signo)	\
	if(sigismember(&curMask, signo))	\
		printf(" %s\n", #signo);

void
PrintMask(char const* str)
{
	sigset_t curMask;

	if(sigprocmask(0, NULL, &curMask) < 0)
		err_sys("sigpromask(0, curMask) error");
	else{
		fputs(str, stdout);
		
		PRINT_MASK_IF(curMask, SIGALRM)
		PRINT_MASK_IF(curMask, SIGINT)
		PRINT_MASK_IF(curMask, SIGABRT)
		PRINT_MASK_IF(curMask, SIGBUS)
		PRINT_MASK_IF(curMask, SIGCONT)
		//PRINT_MASK_IF(curMask, SIGEMT)
		PRINT_MASK_IF(curMask, SIGCHLD)
		PRINT_MASK_IF(curMask, SIGILL)
		PRINT_MASK_IF(curMask, SIGFPE)
		PRINT_MASK_IF(curMask, SIGHUP)
		//PRINT_MASK_IF(curMask, SIGKILL)
		PRINT_MASK_IF(curMask, SIGIO)
		PRINT_MASK_IF(curMask, SIGIOT)
		PRINT_MASK_IF(curMask, SIGPIPE)
		PRINT_MASK_IF(curMask, SIGPOLL)
		PRINT_MASK_IF(curMask, SIGPROF)
		PRINT_MASK_IF(curMask, SIGPWR)
		PRINT_MASK_IF(curMask, SIGQUIT)
		PRINT_MASK_IF(curMask, SIGSEGV)
		PRINT_MASK_IF(curMask, SIGSTKFLT)
		//PRINT_MASK_IF(curMask, SIGSTOP)
		PRINT_MASK_IF(curMask, SIGSYS)
		PRINT_MASK_IF(curMask, SIGTRAP)
		PRINT_MASK_IF(curMask, SIGTERM)
		PRINT_MASK_IF(curMask, SIGTSTP)
		PRINT_MASK_IF(curMask, SIGTTIN)
		PRINT_MASK_IF(curMask, SIGTTOU)
		PRINT_MASK_IF(curMask, SIGUSR1)
		PRINT_MASK_IF(curMask, SIGUSR2)
		PRINT_MASK_IF(curMask, SIGVTALRM)
		PRINT_MASK_IF(curMask, SIGWINCH)
		PRINT_MASK_IF(curMask, SIGXCPU)
		PRINT_MASK_IF(curMask, SIGXFSZ)
	}
}
