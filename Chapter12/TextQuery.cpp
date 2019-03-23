#include "pch.h"
#include "TextQuery.h"

std::set<TextQuery::SVST>::iterator QueryResult::begin()
{
    auto ret=sptr->begin();
    return ret;
}

const std::set<TextQuery::SVST>::iterator QueryResult::begin() const
{
    auto ret = sptr->cbegin();
    return ret;
}

std::set<TextQuery::SVST>::iterator QueryResult::end()
{
    auto ret = sptr->end();
    return ret;
}

const std::set<TextQuery::SVST>::iterator QueryResult::end() const
{
    auto ret = sptr->cend();
    return ret;
}
