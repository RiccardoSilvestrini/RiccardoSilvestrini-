


#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
int  pid =  fork();
	if(pid == 0){
		printf(" eseguito dal figlio \n");
		exit(0);
	}
	else{
		pid = wait(&status);
		if(WIFEXITED(status))
		prinf(" ", pid,  WEXITSTATUS(status));
		else 
		if(WIFSIGNALED(status))
		printf(" n", WTERMSIG(status));
	}
}


