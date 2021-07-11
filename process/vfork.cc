/*
 * @version: 2021-5-17
 * @author: Conzxy
 * vfork Test
 * vfork without copying the address space of the parent into the child
 * vfork guarantees that the child runs first, until the child calls exec or exit
 */

#include <unistd.h>
#include <stdio.h>
#include <errorHandle.h>


int globvar = 5;

int main(){
	int var;
	pid_t pid;

	var = 88;
	printf("before vfork\n");
	if((pid = vfork()) < 0){
		err_sys("vfork error");
	}else if(pid == 0){
		globvar++;
		var++;
		_exit(0);
	}

	//parent continues here
	printf("pid = %ld, glob = %d, var = %d\n", (long)pid, globvar, var);
}
