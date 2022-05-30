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

/**
 * It asks the user to input a number between 8 and 32, and if the number is not between 8 and 32, it
 * asks the user to input a number between 8 and 32 again
 * 
 * @param numBit number of bits to be transmitted
 */
void getNumBit(int& numBit) {
    do {
        cout << "Inserire quantita' di bit da trasmettere (da 8 a 32): ";
        cin >> numBit;
        cout << endl;
        if(numBit < 8 || numBit > 32) {
            cout << "La quantita' di bit deve essere compresa tra 8 e 32" << endl << endl;
        }
    } while(numBit < 8 || numBit > 32);
}

/**
 * It generates a random bit string of a given length
 * 
 * @param length the length of the bit string
 * 
 * @return A string of random bits.
 */
string generateRandomBitString(int length) {

/* La stringa di bit con una lunghezza determinata deve iniziare per forza con 1 
        altrimenti avrebbe una lunghezza inferiore a quella richiesta */
    string bitString = "1";

    for(int i = 1; i < length; i++) {
        bitString += to_string(randomNum(1));
    }

    return bitString;
}

/**
 * It returns a random number between 0 and the number passed in
 * 
 * @param max The maximum number that can be generated.
 * 
 * @return The remainder of the random number divided by the max number plus 1.
 */
int randomNum(int max) {
    return rand() % (max + 1);
}

/**
 * It prints the length of the polynomial and the polynomial itself
 * 
 * @param length the length of the string Mx
 * @param Mx the polynomial
 */
void printCurrentData(int length, string Mx) {
    cout << "Lunghezza M(x): " << length << endl;
    cout << "M(x): " << Mx 
