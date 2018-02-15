#include <iostream>
#include <cmath>
#include "pa1.h"
using namespace std;



int main() {
    int msSize = 1;

    while (msSize != 0) {
        cout << "Enter the size of a magic square (enter zero to exit): ";
        cin >> msSize;

        if (msSize != 0)
            genMS(msSize);
    }

    return 0;
}