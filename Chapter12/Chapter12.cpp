#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
    std::string  str1, str2;
    std::cin >> str1 >> str2;
    std::string str(str1 + str2);
    char* p = new char[str.length()]();
    for (auto iter = str.cbegin(); iter != str.cend();++iter) {
        std::cout << "befor: " << *p << std::endl;
        (*p) = (*iter);
        std::cout << "after: " << *p << std::endl;
        ++p;
    }
    delete[] p;

    return 0;
}