/*
 * @version: 2021-5-15
 * @author: Conzxy
 * test fork API
 * create parent process and child process
 * showing how changes to variables in a child process do not effect the value of the variables in the parent process
 */

#include <unistd.h>
#include <errorHandle.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(){
	int var;
	pid_t pid;

	var = 88;
	if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1){
		err_sys("write error");
	}

	printf("before fork");

	if((pid = fork()) < 0){
		err_sys("fork error");
	}else if ( pid == 0){		//child
		globvar++;
		var++;
	}else{						//parent
		sleep(2);
	}

	printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

	return 0;
}
