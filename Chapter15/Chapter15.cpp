#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"

int main() {
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;
    Base* p = &d1;
    //p = &d2;    //  E0269   conversion to inaccessible base class "Base" is not allowed
    //p = &d3;    //  E0269   conversion to inaccessible base class "Base" is not allowed
    p = &dd1;
    //p = &dd2;   //  E0269
    //p = &dd3;   //  E0269

    return 0;
}