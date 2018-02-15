#include <iostream>
#include <cmath>
using namespace std;

/*
 * prints a passed in magic array
 */
void printMs(int msArray[15][15], int _msSize) {
    int sum = 0;
    //the following for loops print unique magic squares
    for(int i = 0; i < _msSize; i++) {
        for(int j = 0; j < _msSize; j++){
            cout << msArray[i][j] << " ";
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
    sum = 0;
}

/*
 * Generates a magic array
 */
void genMS(int _msSize) {
    int m = (_msSize / 2);
    int n = (_msSize - 1);
    int msArray[15][15];

/*
    int **msArray = new int*[_msSize];
    for (int i = 0; i < _msSize; i++) {
        msArray[i] = new int[_msSize];
    }
*/

    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray[i][j] = 0;
    }

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

    printMs(msArray, _msSize);
}

#ifndef PA1_PA1_H
#define PA1_PA1_H

#endif //PA1_PA1_H
