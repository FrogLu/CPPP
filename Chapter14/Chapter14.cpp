#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"
#include "myfunction.h"

int main() {
    int left, right;
    std::string op;
    std::cout << "Please enter a binary operation expression(e.g. 4 + 5 )[hint: space is necessary!]: ";
    assert(std::cin >> left >> op >> right);
    bool flag = ((op == "+") || (op == "-") || (op == "*") || (op == "/") || (op == "%"));
    assert(flag);
    std::cout << binOps[op](left, right) << std::endl;

    return 0;
}