#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <united.h>
int main(){
	int status;
	int  pid =  fork();
	if(pid == 0){
		printf("sono il processo figlio, il mio pid è %d,getpid());
	}
	else{
		printf(" Sono il padre, il mio pid e': %d. ", getpid());
		printf(" l'exit di mio figlio (&d) e': %d\n ", wait(&status), status);
		return 0;
	}
}

