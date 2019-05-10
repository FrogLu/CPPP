#include "pch.h"
#include "compare.h"
#include "../Chapter14/Sales_data.h"

int main()
{
    Sales_data sd1, sd2;
    std::cout << compare(sd1, sd2) << std::endl;

    return 0;
}