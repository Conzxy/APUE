/*
 * @author: Conzxy
 * @version: 2021-6-13
 * use API in synProcess.h to synchronize parent and child process
 */

#include "../signals/synProcess.h"
#include <unistd.h>
#include <errorHandle.h>

static void
ProcessOut(char const* s)
{
	char const* p;
	int c;

	setbuf(stdout, NULL);
	for(p = s; (c = *p++) != 0; ){
		putc(c, stdout);
	}
}

int
main()
{
	TellWaitInit();
	
	pid_t pid;

	if((pid = fork()) < 0){
		err_sys("fork() error");
	}else if(pid == 0){
		ProcessOut("child process\n");
		TellParent(getppid());
	}else{
		WaitChild();
		ProcessOut("parent process\n");
	}

	exit(0);
}
