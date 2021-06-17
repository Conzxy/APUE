/*
 * @author: Conzxy
 * @version: 2021-6-12
 * use signal(), sigprocmask(), sigsuspend(), etc to implement
 * process-synchronized API
 */

#ifndef _SYNPROCESS_H
#define _SYNPROCESS_H

#include <unistd.h>

/*
 * Initialize sigset and install sigmask of process
 */
void TellWaitInit();

/*
 * tell parent, child is done
 */
void TellParent(pid_t pid);

/*
 * tell child, parent is done
 */
void TellChild(pid_t pid);

/*
 * wait parent to notify child
 */
void WaitParent();

/*
 * wait child to notify parent
 */
void WaitChild();

/*
 * The following codes illustrates this scenario:
 *
 * TellWaitInit();
 *
 * if((pid = fork()) < 0){
 *		err_sys("fork error");
 * }
 * else if(pid == 0){
 *		//something is done
 *		TellParent(getppid());
 *		WaitParent();
 *		//continues executing	
 *
 *		exit(0);
 * }
 * 
 * //something is done
 * TellChild(pid);
 * WaitChild();
 * //continues executing
 *
 * exit(0);
 */

#endif //_SYNPROCESS_H
