#include "pch.h"
#include "Quote.h"

int main() {
    Quote qt("FrogLu", 11.5);
    print_total(std::cout, qt, 5);

    return 0;
}