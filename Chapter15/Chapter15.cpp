#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"

int main() {
    Bulk_quote blqt1("FrogLu",12.5,6,0.2), blqt2(blqt1), blqt3;
    blqt3 = blqt2;

    return 0;
}