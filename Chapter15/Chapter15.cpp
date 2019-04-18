#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"

int main() {
    Quote qt("FrogLu", 11.5);
    Bulk_quote blqt("xixi", 11.5, 5, 0.2);
    Limited_quote lmqt("CPPP", 11.5, 3, 0.2);
    Quote *demo = &blqt;
    //  Error C2259 'Disc_quote': cannot instantiate abstract class
    //  Error(active) E0322	object of abstract class type "Disc_quote" is not allowed
    Disc_quote dsqt;    //  Error
    qt.debug(std::cout);
    std::cout << std::endl;
    blqt.debug(std::cout);
    std::cout << std::endl;
    lmqt.debug(std::cout);
    std::cout << std::endl;
    std::cout << std::endl;
    demo->debug(std::cout);

    return 0;
}