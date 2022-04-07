#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>


using namespace std;
int main() {

int numerobits,c;
cout<<"inserisci quanti bits da trasmettere : ";
cin>>numerobits;
cout<<"numero di bits: "<<numerobits<<endl;

for(int i=0; i<numerobits;i++)
{ int c=rand() %2;
cout<<c;
}



return 0;
}

