#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *codice_thread(void * arg) {
pid_t pid;
pid = getpid();
pthread_t tid;
tid = pthread_self();
printf("Sono il thread %i del processo %i\n", (int)tid, pid;
}

int main (){
 pthread_t miothread;
 printf ("il pid del main e' %d\n", (int) getpid ());
 if (pthread_create (&miothread, NULL, &codice_thread, NULL)==0)
   sleep(1);
 else
    printf ("errore nella creazione del thread!" );
 return 0;
{

