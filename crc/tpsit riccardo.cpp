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
    cout << "M(x): " << Mx << endl << endl;
}
