#pragma once
#ifndef _BULK_QUOTE_H_
#define _BULK_QUOTE_H_

#include "Disc_quote.h"
class Bulk_quote :
    public Disc_quote
{
public:
    //Bulk_quote() = default;
    //Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
    //    Disc_quote(book, p, qty, disc) {}
    //Bulk_quote(const Bulk_quote&);
    //Bulk_quote(Bulk_quote&&)noexcept;
    //Bulk_quote& operator=(const Bulk_quote&);
    //Bulk_quote& operator=(Bulk_quote&&)noexcept;
    using Disc_quote::Disc_quote;
    virtual double net_price(std::size_t) const override;
    virtual std::ostream& debug(std::ostream& os) const override;
    virtual ~Bulk_quote();
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

//inline
//Bulk_quote::Bulk_quote(const Bulk_quote& blqt):
//    Disc_quote(blqt)
//{
//    min_qty = blqt.min_qty;
//    discount = blqt.discount;
//
//    std::cout << "Bulk_quote::Bulk_quote(const Bulk_quote& blqt)" << std::endl;
//}
//
//inline 
//Bulk_quote::Bulk_quote(Bulk_quote&& blqt) noexcept:
//    Disc_quote(std::move(blqt))
//{
//    min_qty = std::move(blqt.min_qty);
//    discount = std::move(blqt.discount);
//
//    std::cout << "Bulk_quote::Bulk_quote(Bulk_quote&& blqt)" << std::endl;
//}
//
//inline 
//Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs)
//{
//    Disc_quote::operator=(rhs);
//
//    min_qty = rhs.min_qty;
//    discount = rhs.discount;
//
//    std::cout << "Bulk_quote::operator=(const Bulk_quote& rhs)" << std::endl;
//
//    return *this;
//}
//
//inline 
//Bulk_quote& Bulk_quote::operator=(Bulk_quote&& blqt) noexcept
//{
//    Disc_quote::operator=(blqt);
//
//    min_qty = std::move(blqt.min_qty);
//    discount = std::move(blqt.discount);
//
//    std::cout << "Bulk_quote::operator=(Bulk_quote&& blqt)" << std::endl;
//
//    return *this;
//}

#endif // !_BULK_QUOTE_H
