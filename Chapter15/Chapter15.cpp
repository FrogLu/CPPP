#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"

int main() {
    Base bobj; D1 d1obj; D2 d2obj;

    Base* bp1 = &bobj, * bp2 = &d1obj, * bp3 = &d2obj;
    bp1->fcn();
    bp2->fcn();
    bp3->fcn();

    D1* d1p = &d1obj; D2* d2p = &d2obj;
    //bp2->f2();
    d1p->f2();
    d2p->f2();

    return 0;
}