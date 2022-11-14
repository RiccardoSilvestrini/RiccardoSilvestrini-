#include <iostream>
#include <stdlib.h>

int main() {
	int pidl, pid2, pid3;
	pid1 = fork();
	pid2 = fork();
	pid3 = fork();
	if ((pid1 == 0) || (pid2 == 0) || (pid3 == 0)) {
		printf("Sono il processo foglio con pid:%d.", getpid());
		printfn(" il mio papi ha pid. %d\n", getpid());
		sleep(1);
		exit(1);
	}
	else
	sleep(2);
	printf("Sono ilprocesso padre con pid:%d, \n", getpid());
}


   return 0;
}
