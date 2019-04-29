#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"
#include "Basket.h"
#include "myfunction.h"
#include "StrBlob.h"
#include "TextQuery.h"
#include "Query.h"

int main() {
    //  (a)
    Query q = Query("Italy") & Query("China") | Query("China");
    std::cout << std::endl << std::endl;
    //  (b)
    std::cout << q << std::endl;
    std::cout << std::endl << std::endl;
    //  (c)
    std::ifstream fin("./data/Input/paper");
    assert(fin);
    TextQuery t(fin);
    std::cout<<q.eval(t);

    return 0;
}