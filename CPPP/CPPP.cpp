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
int main() {
    const vector<string> scores_TD = { "twenty","thrity","forty","fifty","sixty","seventy","eighty","ninety","one hundred" };
    const vector<string> scores_SD = { "zero","one","two","three","four","five","six",
                                        "seven","eight","nine","ten",
                                        "eleven","twelve","thriteen","forteen","fifteen","sixteen",
                                        "seventeen","eighteen","ninteen"};
    unsigned int grade = 0;
    while (cin >> grade) {
        string lettergrade;
        cout << "enter your score: ";
        if (grade > 100 || grade < 0)
            cout << "The scores is illegal!" << endl;
        else
        {
            if (grade >= 20) {
                lettergrade = scores_TD[grade / 10 - 2];
                if (grade != 100) {
                    if (grade % 10) {
                        lettergrade += "-";
                        lettergrade += scores_SD[grade % 10];
                    }
                }
            }
            else {
                lettergrade = scores_SD[grade];
            }
        }
        cout << lettergrade << endl;
    }
    return 0;
}