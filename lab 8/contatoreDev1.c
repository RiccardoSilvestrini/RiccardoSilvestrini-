#include <pthread.h>
#include <stdLib.h>
#include <unistd.h>
#include <stdio.h>
#define TANTI 10
int globale;

void *cosaFaThread(void *arg){
 int i, locale;
 for(i = 0; i < TANTI; i++ ){
  printf("\n.ho letto %d", globale);     //scrive un numero in var condivisa
  sleep(1);
 }
 return NULL;
}

int main (void){
  pthread_t mioThread;
  int i;
  if (pthread_create( &mioThread, NULL, cosaFaThread, NULL) ) {
   printf("errore nella creazione del thread.");
   abort();
 }
 for (i = 0; i < TANTI; i++){
   globale = globale + 1;
   printf("\nho scritto %d", globale);      //scrive un numero in var condivisa
   fflush(stdout);
   sleep(1);
 }
 if (pthread_join (mioThread, NULL)){
  printf("errore nel join del thread.");
  abort();
 }
 printf("\nglobale vale %d\n", globale);
 exit(0);
}
