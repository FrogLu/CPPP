#include "pch.h"
#include "Quote.h"
#include "Bulk_quote.h"
#include "Limited_quote.h"
#include "Disc_quote.h"
#include "Base.h"
#include "Basket.h"

int main() {
    Basket basket;
    basket.add_item(Bulk_quote("0-201-54848-8", 50, 10, .25));
    basket.add_item(Bulk_quote("0-201-54848-8", 50, 10, .25));
    basket.add_item(Bulk_quote("1-201-54848-8", 40, 10, .25));
    double count = 0.0;
    basket.total_receipt(std::cout); //  count is 1012.5

    return 0;
}