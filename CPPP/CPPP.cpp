// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
int main() {
    string s;
        cout << "Please Enter a string, with some punctuation better: " << endl;
    getline(cin, s);
    for (auto c : s) {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    
    return 0;
}
