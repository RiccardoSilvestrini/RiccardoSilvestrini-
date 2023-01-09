#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>  //aggiunta questa libreria perché senza non riusciva a riconoscere alcuni comandi

int calcoli_figlio1(){
	int k;
	printf("1.1 elab. parallela processo figlio \n");
	k=3+2;
	return k;

}

int calcoli_padre1(){
	int k;
	printf("1 elab. parallela processo padre \n");
	k=6-2;
	return k;
}

int calcoli_padre2(int a, int b){
	int k;
	printf ("2 elab. finale padre \n");
	k = (a+b);
	return k;

}


int main(){
int x, y, z, retv;
pid_t pid;
pid = fork();
if (pid == 0){
	x=calcoli_figlio1();
	exit(x);

}

else{
y = calcoli_padre1();
}

printf(".. join: padre aspetta \n");
wait(&retv);
x = WEXITSTATUS(retv);
z = calcoli_padre2(x,y);
printf("-> riultato finale z = %d \n", z);


}
