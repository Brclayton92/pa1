#include <iostream>
#include <cmath>
#include "pa1.h"
using namespace std;



int main() {
    int msSize = 0;
    cout << "Enter the size of a magic square: ";
    cin >> msSize;

    genMS(msSize);

    return 0;
}