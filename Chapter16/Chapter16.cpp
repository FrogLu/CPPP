#include "pch.h"
#include "mytemplate.h"
#include "../Chapter14/Sales_data.h"
#include "tVec.h"

int main()
{
    tVec<int> ivec = { 1,2,3,4,5,6,7,8,9 };
    for (auto &i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}