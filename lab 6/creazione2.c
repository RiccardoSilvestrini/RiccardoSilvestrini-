#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>  //aggiunta questa libreria perché senza non riusciva a riconoscere alcuni comandi

int main(){
	
	int status;
	pid_t pid_figlio;
	printf("S1 (padre1) - pid = &d\n", getpid());
	printf(" fork esterna - \n");
	if ((pid_figlio = fork()) == -1)
		printf("fork non riuscita!");
		
	else
		if(pid_figlio==0){
			printf(" figlio1: pid = %d, padre pid = %d\n", getpid(), getppid());
			ramo34();
		}
	else{
		printf(" S2 (padre1) - pid = %d\n", getpid());
		printf("wait fine ramo P34 (padre1 soin figlio1) \n");
		waitpid(pid_figlio, &status, 0);
		printf("fine attesa P34 \n");
		printf("S5 (padre1) - pid = %d\n",getpid());
		exit(0);
	}		
	
	ramo34(){
		int status;
		pid_t pid4;
		printf(" fork - processi P34 -> creazione P4 \n");
		if ((pid4=fork())==-1){
			printf(" fork non riuscita!");
			
		}
		
		if (pid4==0){
			printf("S4(figlio2) - pid=%d, padre pid= %d\n", getpid(), getppid());
			
		}
		
		else{
			printf(" S3 (padre2) - pid =%d, padre pid= %d\n", getpid(), getppid());
			printf("wait fine figlio P4 ( padre2 join figlio2) \n");
			waitpid(pid4, &status, 0);
			printf("fine attesa P4 \n");
			printf("fine ramo P34 \n");
			
		}
		exit(0);
	}
	
		
}
