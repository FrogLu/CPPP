#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"

int main() {
    std::vector<std::string> svec;
    ReadString str(std::cin);
    PrintString printStr(std::cout);
    while (true) {
        std::string line = str();
        if (!line.empty()) {
            svec.push_back(line);
        }
        else {
            break;
        }
    }

    return 0;
}