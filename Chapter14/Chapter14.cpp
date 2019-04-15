#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"

int main() {
    std::vector<std::size_t> stvec({ 1,2,3,4,5,1,2,3,4,5 });
    MyEquation eq(3);
    const std::size_t newValue = 15;
    auto print = [](std::size_t value) {std::cout << value<<" "; };

    std::for_each(stvec.begin(), stvec.end(),print);
    std::cout << std::endl;
    std::replace_if(stvec.begin(), stvec.end(), eq,newValue);
    std::for_each(stvec.begin(), stvec.end(),print);
    std::cout << std::endl;

    return 0;
}