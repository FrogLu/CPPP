#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"

int main() {
    Quote qt1, qt2(qt1),qt3;
    qt3 = qt2;
    //Disc_quote dsqt1, dsqt2(dsqt1), dsqt3;  //  E0322   object of abstract class type "Disc_quote" is not allowed 
    //dsqt3 = dsqt2;
    Bulk_quote blqt1, blqt2(blqt1), blqt3;
    blqt3 = blqt2;

    return 0;
}