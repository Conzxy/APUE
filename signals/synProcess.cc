/*
 * @author: Conzxy
 * @version: 2021-6-12
 * synchronize parent process and child
 */

#include "synProcess.h"
#include <errorHandle.h>
#include <signal.h>

//volatile used to avoid overhead optimization
static volatile sig_atomic_t kSigFlag = 0;

static sigset_t kZeroMask;
static sigset_t kOldMask;
static sigset_t kNewMask;

static void
SigUSRHandler(int signo)
{
	kSigFlag = 1;	
}

void
TellWaitInit()
{
	if(signal(SIGUSR1, SigUSRHandler) == SIG_ERR)
		err_sys("signal(SIGUSR1) error");
	if(signal(SIGUSR2, SigUSRHandler) == SIG_ERR)
		err_sys("signal(SIGUSR2) error");

	sigemptyset(&kZeroMask);
	sigemptyset(&kNewMask);

	sigaddset(&kNewMask, SIGUSR1);
	sigaddset(&kNewMask, SIGUSR2);
	
	//block SIGUSR1 and SIGUSR2, saving old mask
	if(sigprocmask(SIG_BLOCK, &kNewMask, &kOldMask) < 0)
		err_sys("sigprocmask(USR1, USR2) error");
	
}

/*
 * @brief: transfer SIGUSR2 to parent process
 * @para: pid --- parent process ID
 */
void
TellParent(pid_t pid)
{
	kill(pid, SIGUSR2);
}

/*
 * @brief: transfer SIGUSR1 to child process
 * @para: pid --- child process ID
 */
void
TellChild(pid_t pid)
{
	kill(pid, SIGUSR1);
}

/*
 * @brief: wait parent process transfer SIGUSR1 to tell child is done
 */
void
WaitParent()
{
	//use 'while' better than 'if' here, because maybe other signal handler set kSigFlag = 0
	//even in mutithread environment, this work correctly
	while(! kSigFlag)
		sigsuspend(&kZeroMask);

	kSigFlag = 0;

	if(sigprocmask(SIG_SETMASK, &kOldMask, NULL) < 0)
			err_sys("SIG_SETMASK error");
}

/*
 * @berif: wait child process transfer SIGUSR2 to tell parent is done
 */
void
WaitChild()
{
	while(! kSigFlag)
		sigsuspend(&kZeroMask);

	kSigFlag = 0;

	if(sigprocmask(SIG_SETMASK, &kOldMask, NULL) < 0)
		err_sys("SIG_SETMASK error");
}
