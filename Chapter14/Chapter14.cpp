#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"

int main() {
    StrVec svec({ "hello"});
    String str("world");
    StrBlob sb({ "FrogLu" });
    std::cout << "svec[0]: " << svec[0] << std::endl;
    std::cout << "str[0]: " << str[0] << std::endl;
    std::cout << "sb[0]: " << sb[0] << std::endl;

    return 0;
}