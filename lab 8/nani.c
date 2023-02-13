#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdLib.h>          //per utilizzare costanti predefinite
#define NUM_THREADS 7        //nr dei thread da far partire 
char *nome[NUM_THREADS];     //vettore contenente i nomi dei nani

void *cod_thread(void *tid){
 int tid_int;
 tid_int = *(int*) tid;         //leggo parametro da puntatore void
 //generazione ritardo casuale 
 srand(time(NULL));
 sleep(rand() % 2);
 printf("  Ciao da %d: %s \n", tid_int, nome[tid_int] ); //stampa nome 
 pthread_exit(NULL);            //uscita del thread senza valori di ritorno
}

int main(int argc, char *argv[]){
 pthread_t threads[NUM_THREADS];    //vettore dei thread
 int tid, rc;
 nome[0] = "Cucciolo";
 nome[1] = "Pisolo";
 nome[2] = "Eolo";
 nome[3] = "Dotto";
 nome[4] = "Mammolo";
 nome[5] = "Gongolo";
 nome[6] = "Brontolo";
 for (tid = 0; tid < NUM_THREADS; tid++) {
  printf("Creazione thread %d\n", tid);
  rc = pthread_create(&threads[tid], NULL, cod_thread, (void *) &tid);
  //sleep(1); //necessaria, altrimenti la velocità della macchina crea problemi sul valore di t
  if (rc) {
   printf ("ERRORE: il codice di errore di ritorno da pthread_create() e': %d\n", rc);
   exit(EXIT_FAILURE);  //
  }
 }
 pthread_exit(NULL);   //terminazione corretta del programma 
}
