#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"

int main() {
    StrBlob sb1({ "hello" }), sb2({ "world" });
    std::cout << "The Result of StrBlob==: " << (sb1 == sb2) << std::endl;
    std::cout << "The Result of StrBlob!=: " << (sb1 != sb2) << std::endl;

    return 0;
}