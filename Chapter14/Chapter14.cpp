#include "pch.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrVec.h"
#include "MyClass.h"
#include "myfunction.h"

int main() {
    std::ifstream fint("./data/Input/int");
    assert(fint.good());
    fint.tie(&std::cout);
    std::istream_iterator<std::size_t> IsStIter(fint), StEeof;
    std::vector<std::size_t> stvec(IsStIter, StEeof);
    // Practice14.43
    while (true) {
        std::cout << "Please Enter the modulated number: ";
        std::size_t mod;
        std::cin >> mod;
        if (std::find_if(stvec.cbegin(), stvec.cend(),
            std::bind(std::modulus<std::size_t>(), std::placeholders::_1, mod)) == stvec.cend()) {
            std::cout << "Number: " << mod << "works" << std::endl;
            break;
        }
        std::cout << "Press q to quit, others to continue: ";
        char command = ' ';
        assert(std::cin >> command);
        if (command == 'q') {
            break;
        }
    }
    
    

    return 0;
}