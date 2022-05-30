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

using namespace std;

int main(int argc, char const *argv[])
{
    int numBit;
    string Mx, Gx, Dx, CRC, codeword, newCodeword;
    bool thereIsErr;

    getNumBit(numBit);

    Mx = generateRandomBitString(numBit);

    printCurrentData(numBit, Mx);

    getGx(Gx);

    Dx = generateDx(Mx, Gx.size());

    printDx(Dx);

    CRC = generateCRC(Dx, Gx);

    printCRC(CRC);
    
    codeword = generateCodeword(Dx, CRC);

    printCodeword(codeword);

    newCodeword = casualErr(codeword);

    printErr(newCodeword, codeword);

    thereIsErr = checkCodeword(newCodeword, Gx);

    printErrSearch(thereIsErr);

    system("pause");

    return 0;
}

void getNumBit(int& numBit) {
    do {
        cout << "Inserire quantita' di bit da trasmettere (da 8 a 32): ";
        cin >> numBit;
        cout << endl;
        if(numBit < 8 || numBit > 32) {
            cout << "La quantita' di bit deve essere compresa tra 8 e 32" << endl << endl;
        }
    } while(numBit < 8 || numBit >
}
string generateRandomBitString(int length) {

/* La stringa di bit con una lunghezza determinata deve iniziare per forza con 1 
        altrimenti avrebbe una lunghezza inferiore a quella richiesta */
    string bitString = "1";

    for(int i = 1; i < length; i++) {
        bitString += to_string(randomNum(1));
    }

    return bitString;
}

int randomNum(int max) {
    return rand() % (max + 1);
}

void printCurrentData(int length, string Mx) {
    cout << "Lunghezza M(x): " << length << endl;
    cout << "M(x): " << Mx << endl << endl;
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

