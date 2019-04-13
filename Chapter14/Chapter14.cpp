#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"

int main() {
    Sales_data sd1("hello",1,2.0), sd2("world",3,4.0);
    std::cout << "sd1: " << sd1 << std::endl;
    std::cout << "sd2: " << sd2 << std::endl;
    sd1 += sd2;
    std::cout << "sd1: " << sd1 << std::endl;
    std::cout << "sd2: " << sd2 << std::endl;
    sd1 = sd2;
    std::cout << "sd1: " << sd1 << std::endl;
    std::cout << "sd2: " << sd2 << std::endl;

    return 0;
}