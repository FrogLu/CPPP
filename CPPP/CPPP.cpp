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
    int result = 1;
    while (val) {
        result *= val--;
    }
    return result;
}
int main() {
    int val;
    cout << "Enter the num of n to calculate n!: ";
    cin >> val;
    int result = fact(val);
    cout << val << "! is: " << result<<endl;
    return 0;
}