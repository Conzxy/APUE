/*
 * @file print_exit.h
 * 
 * @date 21-6-2021
 * @author Conzxy
 */


#include <sys/wait.h>
#include <stdio.h>

inline void PrintExit(int status){
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core file generated) " : "");
#else
				"");
#endif
	else if(WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));
}
