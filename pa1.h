#include <iostream>
#include <cmath>
using namespace std;

/*
 * prints a passed in magic array
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
    sum = 0;
}


/*
 * Generates and prints 10 magic squares
 */
void genMS(int _msSize) {
    int m = (_msSize / 2);
    int n = (_msSize - 1);
    int msArray[15][15];
    int msArray2[15][15];
    int msArray3[15][15];
    int msArray4[15][15];
    //int msArray5[15][15];
    //int msArray6[15][15];
    //int msArray7[15][15];
    //int msArray8[15][15];
    //int msArray9[15][15];
    //int msArray10[15][15];



/*
    int **msArray = new int*[_msSize];
    for (int i = 0; i < _msSize; i++) {
        msArray[i] = new int[_msSize];
    }
*/

    //initializes all elements to 0
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray[i][j] = 0;
    }


    // generates the first magic square
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
    printMs(msArray, _msSize);

    //turns the first magic square 90 degrees clockwise to create the second magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray2[i][j] = msArray[_msSize - j - 1][i];
    }

    //prints the second magic square
    printMs(msArray2, _msSize);

    //turns the second magic square 90 degrees clockwise to create the third magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray3[i][j] = msArray2[_msSize - j - 1][i];
    }

    //prints the third magic square
    printMs(msArray3, _msSize);

    //turns the third magic square 90 degrees clockwise to create the fourth magic square
    for (int i = 0; i < _msSize; i++){
        for (int j = 0; j < _msSize; j++)
            msArray4[i][j] = msArray3[_msSize - j - 1][i];
    }

    //prints the fourth magic square
    printMs(msArray4, _msSize);


}

#ifndef PA1_PA1_H
#define PA1_PA1_H

#endif //PA1_PA1_H
