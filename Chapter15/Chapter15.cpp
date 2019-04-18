#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"

int main() {
    Quote qt("FrogLu", 11.5);
    Bulk_quote blqt("xixi", 11.5, 5, 0.2);
    Limited_quote lmqt("CPPP", 11.5, 3, 0.2);
    print_total(std::cout, qt, 5);
    print_total(std::cout, blqt, 5);
    print_total(std::cout, lmqt, 5);

    return 0;
}