#include "pch.h"
#include "String.h"
#include "Sales_data.h"

int main() {
    Sales_data sd;
    //  Sample input 1) 0-201-99999-9 10 24.95 2) 10 24.95 0-210-99999-9
    //  When I try Sample2 as input, I found item won't be Sale_data(),
    //  item still would be a wrong value in operator>>. But I don't know how to fix it.
    std::cin >> sd;
    std::cout << sd;

    return 0;
}