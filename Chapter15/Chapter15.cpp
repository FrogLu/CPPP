#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"

int main() {
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(std::make_shared<Bulk_quote>("0-201-54848-8", 50, 10, .25));
    std::cout << basket.back()->net_price(15) << std::endl;

    return 0;
}