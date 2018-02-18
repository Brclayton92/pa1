#include <iostream>
#include "pa1.h"
#include <limits>;
using namespace std;

/*
 * prints a passed in magic square array and the sums of it's rows, columns, and diagonals
 */
void printMs(int msArray[15][15], int _msSize) {
    int sum = 0;

    for(int i = 0; i < _msSize; i++) {
        for(int j = 0; j < _msSize; j++){
            cout << msArray[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Checking the sums of every row:      ";

    for (int i = 0; i < _msSize; i++) {
        for (int j = 0; j < _msSize; j++)
            sum = sum + msArray[i][j];
        cout << sum << " ";
        sum = 0;
    }

    cout << endl;

    cout << "Checking the sums of every column:   ";

    for (int i = 0; i < _msSize; i++) {
        for (int j = 0; j < _msSize; j++)
            sum = sum + msArray[j][i];
        cout << sum << " ";
        sum = 0;
    }

    cout << endl;

    cout << "Checking the sums of every diagonal: ";

    for (int i = 0; i < _msSize; i++)
        sum = sum + msArray[i][i];
    cout << sum << " ";
    sum = 0;

    int j = _msSize - 1;

    for (int i = 0; i < _msSize; i++){
        sum = sum + msArray[i][j];
        j--;
    }
    cout << sum;

    cout << endl;
}

/*
 * Generates and prints 10 unique magic squares
 */
void genMS(int _msSize) {
    int m = (_msSize / 2);
    int n = (_msSize - 1);
    int msArray[15][15];
    int msArray2[15][15];
    int msArray3[15][15];
    int msArray4[15][15];
    int msArray5[15][15];
    int msArray6[15][15];
    int msArray7[15][15];
    int msArray8[15][15];
    int msArray9[15][15];
    int msArray10[15][15];

    //initializes all elements of magic square array1 to 0
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++)
            msArray[i][j] = 0;
    }

    //initializes all elements of magic square array6 to 0
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++)
            msArray5[i][j] = 0;
    }

    //initializes all elements of magic square array9 to 0
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++)
            msArray9[i][j] = 0;
    }


    // generates the first magic square using Siamese method
    for (int i = 0; i < (_msSize*_msSize); i++) {
        if (m == -1 && n == _msSize) {
            n = _msSize - 2;
            m = 0;
        }

        if (m < 0)
            m = _msSize - 1;

        if (n == _msSize)
            n = 0;

        if (msArray[m][n] != 0) {
            m++;
            n = n - 2;
        }

        msArray[m][n] = i + 1;
        m--;
        n++;
    }

    // prints the first magic square
    cout << endl << "Magic Square #1 is:" << endl << endl;
    printMs(msArray, _msSize);

    //turns the first magic square 90 degrees clockwise to create the second magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray2[i][j] = msArray[_msSize - j - 1][i];
    }

    //prints the second magic square
    cout << endl << "Magic Square #2 is:" << endl << endl;
    printMs(msArray2, _msSize);

    //turns the second magic square 90 degrees clockwise to create the third magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray3[i][j] = msArray2[_msSize - j - 1][i];
    }

    //prints the third magic square
    cout << endl << "Magic Square #3 is:" << endl << endl;
    printMs(msArray3, _msSize);

    //turns the third magic square 90 degrees clockwise to create the fourth magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray4[i][j] = msArray3[_msSize - j - 1][i];
    }

    //prints the fourth magic square
    cout << endl << "Magic Square #4 is:" << endl << endl;
    printMs(msArray4, _msSize);

    //generates a fresh magic square for magic square 5 using Siamese method
    m = 0;
    n = _msSize/2;
    for (int i = 1; i <= _msSize*_msSize; i++) {
        msArray5[m][n] = i;

        m--;
        n++;

        if (m == -1)
            m = _msSize - 1;

        if (n == _msSize)
            n = 0;

        if (msArray5[m][n] != 0) {
            n--;
            m++;

            if (m == _msSize)
                m = 0;

            m++;
        }

        if (n == -1)
            n = _msSize - 1;
    }

    //prints magic square array5
    cout << endl << "Magic Square #5 is:" << endl << endl;
    printMs(msArray5, _msSize);

    //turns the fifth magic square 90 degrees clockwise to create the sixth magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray6[i][j] = msArray5[_msSize - j - 1][i];
    }

    //prints magic square array6
    cout << endl << "Magic Square #6 is:" << endl << endl;
    printMs(msArray6, _msSize);

    //turns the 6th magic square 90 degrees clockwise to create the 7th magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray7[i][j] = msArray6[_msSize - j - 1][i];
    }

    //prints magic square array7
    cout << endl << "Magic Square #7 is:" << endl << endl;
    printMs(msArray7, _msSize);

    //turns the 7th magic square degrees clockwise to create the 8th magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray8[i][j] = msArray7[_msSize - j - 1][i];
    }

    //prints magic square array8
    cout << endl << "Magic Square #8 is:" << endl << endl;
    printMs(msArray8, _msSize);

    m = _msSize / 2;
    n = (_msSize /2) + 1;

    // generates a fresh magic square to be stored in msArray9 using Bachet de Mézeriac method
    for (int i = 1; i <= _msSize*_msSize ; i++){
        msArray9[m][n] = i;

        m--;
        n++;

        if (m == -1)
            m = _msSize - 1;

        if (n == _msSize)
            n = 0;

        if (msArray9[m][n] != 0){
            m++;
            n++;

            if (m == _msSize)
                m = 0;

            if (n == _msSize)
                n = 0;
        }
    }

    //prints magic square array9
    cout << endl << "Magic Square #9 is:" << endl << endl;
    printMs(msArray9, _msSize);

    //interchanges rows and columns of magic square 9 to form magic square 10
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++){
            msArray10[j][i] = msArray9[i][j];
        }
    }

    //prints magic square array10
    cout << endl << "Magic Square #10 is:" << endl << endl;
    printMs(msArray10, _msSize);
}

int main() {
    int msSize = 1;

    while (msSize != 0) {
        cout << "Enter the size of a magic square (enter zero to exit): ";
        cin >> msSize;

        // if statement ensures user input is of proper type
        if (cin.fail()) {
            cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(),'\n');

            // setting msSize to -1 triggers input validation else statement on next line,
            msSize = -1;
        }


        // if statement ensures user input is in proper range
        if (msSize > -1 && msSize < 16)
            genMS(msSize);

        else
            cout << "Improper input, please enter an odd integer between 0 and 15." << endl << endl;
    }

    return 0;
}