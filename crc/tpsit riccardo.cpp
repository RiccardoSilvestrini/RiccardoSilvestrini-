/*
 Punto 1 del libro
 - dare la scelta di quanti bits trasmettere (da 8 a 32)
 - generare una sequenza random di bits da trasmettere
 - stampare i dati originali e il polinomio M(x)

 Punto 2
 - dare la scelta di quale polinomio divisore G(X) utilizzare (stampando i polinomi riportati dal libro)
 Punto 3
 - generare e stampare il polinomio D(x)Punto 4
 - calcolare e stampare il resto della divisione in modulo 2 fra G(X) e D(x)

 - definire e stampare il codeword da trasmettere

 - generare casualmente due posizioni di bits nei dati da trasmettere, per ognuna delle due posizioni decidere casualmente, con probabilita' fra 0.1 e 0.3 (valore esatto scelto da voi) se introdurre un errore invertendo il bit in quella posizione
 - stampare se sono stati introdotti errori e in quale posizione

 - scrivere funzione prende in input la codeword/k e stampa se rileva errori o meno, immediatamente al di sotto della stampa degli errori eventualmente introdotti del punto precedente
 */

#include <iostream>
#include <string>
#include <stdlib.h>
 
include <iostream>

using namespace std;

string genera_sequenza_bits_da_trasmettere(int nr_bits)
{
    string bits(""); // classe string
    int random_bit_value = 0;
    srand(time(NULL));
    for (int i = 0; i < nr_bits; i++)
    {
        random_bit_value = rand() % 2;
        bits.append(to_string(random_bit_value));
    }

    return bits;
}
int main()
{
    int nr_bits_da_trasmettere;
    string bit_out;
    char ok='N';
    
    while(ok != 'S'){
	cout<< "\nInserisci il numero di bits (8-32)\n";
	cin>>nr_bits_da_trasmettere;
	if (nr_bits_da_trasmettere>7 && nr_bits_da_trasmettere< 33)
	        ok='S';
	else
	    cout<< "\ndeve esser compreso fra 8 e 32";
	}
    bit_out=genera_sequenza_bits_da_trasmettere(nr_bits_da_trasmettere);
    cout<< "\n--> " << bit_out;
    return 0;
}

void getGx(string& Gx) {
    int choice;
    const int MIN = 1, MAX = 2;
    const string possibleChoices[MAX] = { "1011", "10011" };

    cout << "Scegliere polinomio divisore" << endl << endl;
    for(int i = 0; i < MAX; i++) {
        cout << i + 1 << ". " << possibleChoices[i] << endl;
    }

    do {
        cout << "Inserire numero polinomio scelto: ";
        cin >> choice;
        cout << endl;
        if(choice < MIN || choice > MAX) {
            cout << "Inserire un numero valido" << endl << endl;
        }
    } while (choice < MIN || choice > MAX);

    Gx = possibleChoices[choice - 1];
}

string generateDx(string Mx, int GxLength) {
    string Dx = Mx;

    for(int i = 0; i < GxLength - 1; i++) {
        Dx += "0";
    }

    return Dx;
}

void printDx(string Dx) {
    cout << "D(x): " << Dx << endl << endl;
}


