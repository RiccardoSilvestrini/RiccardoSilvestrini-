#include <sys/wait.h>
#include <stdio.h>
#include <fenti.h>
#include <stdlib.h>
#define NRFIGLI 4     
int main() {
	
      int status, pid, x;
      for (x=0; x < NRFIGLI; x+*) {
         pid = fork0);
         if (pid == 0) {
         printf("Sono il figlio, il mio pid e':%d.", getpid());
        exit (0);
} else{
	    printf("Sono il padre,i 1 mio pid e' %d\n", getpid());
printf("Il pid del figlio corrente e': %d\n", pid);
printf("L'exit di mio figlio (%d) e': %d\n\n"
wait(&status), status);

}
return 0;
}
