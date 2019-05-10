#include "pch.h"
#include "mytemplate.h"
#include "../Chapter14/Sales_data.h"

int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    std::cout << sizeof(int) << std::endl;
    print(mybegin(arr), myend(arr));
    
    return 0;
}