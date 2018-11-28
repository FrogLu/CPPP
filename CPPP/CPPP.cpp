// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int& foo() {
    int b = 55;
    int& i = b;
    return i;
}
int foobar() {
    return 0;
}
int next_num() {
    return 0;
}
int fact(int val) {
    int result = 0;
    while (val) {
        result *= val--;
    }
    return val;
}
int main() {
    double numA, numB;
    cout << "Enter two number: " << endl;
    while (cin >> numA >> numB) {
        if (numB == 0) {
            throw runtime_error("Divisor can't be zero!");
        }
        cout << "The result of NumA/NumB is: " << numA / numB << endl;

        try
        {
            if (numB == 0) {
                throw runtime_error("Divisor can't be zero!");
            }
            cout << "The result of NumA/NumB is: " << numA / numB << endl;
        }
        catch (runtime_error aha)
        {
            cout << aha.what() << endl << "Try Again?" << endl;
        }
    }
    return 0;
}