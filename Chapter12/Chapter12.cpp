#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
    std::string  str1, str2;
    std::cin >> str1 >> str2;
    std::string str(str1 + str2);
    char* p = new char[str.length()]();
    std::unique_ptr<char[]> up(p);
    int count = 0;
    for (auto iter = str.cbegin(); iter != str.cend();++iter,++count) {
        std::cout << "befor: " << up[count] << std::endl;
        up[count] = (*iter);
        std::cout << "after: " << up[count] << std::endl;
    }
    delete[] p;

    return 0;
}