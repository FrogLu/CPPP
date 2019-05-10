#include "pch.h"
#include "mytemplate.h"
#include "../Chapter14/Sales_data.h"

int main()
{
    std::vector<int> ivec = { 1,2,3,4,5,6,7,8,9 };
    auto iter = myfind(ivec.begin(), ivec.end(), 5);
    std::cout << *iter << std::endl;

    return 0;
}