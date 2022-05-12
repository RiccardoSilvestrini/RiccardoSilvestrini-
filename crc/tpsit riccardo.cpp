#include <cstdlib>
#include <stdlib.h>
#include <time.h>

/* Punto 1 del libro
-dare la scelta di quanti bits trasmettere (da 8 a 32)
-generare uans sequenza random di bits da trasmettere
-stampare i dati origianli e il polinomio M(x) */

using namespace std;
int main() {
 int numerobits, c;
 cout<<"inserire quanti bits da trasmettere (8 a 32) :";
 cin>>numerobits;
 cout<<"numero di bits:  "<<numerobits<<endl;
 
 for(int i=0; i<numerobits; i++){
 	int c=rand() % 2;
 	cout<<c;
 }
 
}

int m=4;
int gx[m];
gx[0]=1;
gx[1]=1;
gx[2]=0;
gx[3]=1;


cout<<"\n\nmx: ";
for(int i=m; i>0; i--){
	if (gx[i-1]==1){
		cout>>"x^"<<i-1<<"x";
	}
}

for(int i=0, h=m; i<numerobits; i++, h--){
	if(h==0){
		h=4;
	}
	if(bit[i] == gx[h]){
		bit[i] = 0;
	}
}
