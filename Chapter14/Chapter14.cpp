#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"

int main() {
    std::vector<std::string> svec;
    ReadString str;
    PrintString printStr(std::cout);
    printStr(str(std::cin));

    return 0;
}