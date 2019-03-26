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

void TextQuery::display_map() {
    auto iter = rowMap.cbegin(), iter_end = rowMap.cend();

    for (; iter != iter_end; ++iter) {
        std::cout << "word: " << iter->first << " {";

        auto text_locs = iter->second;
        auto loc_iter = text_locs->cbegin();
        auto loc_iter_end = text_locs->cend();

        while (loc_iter != loc_iter_end) {
            std::cout << *loc_iter;

            if (++loc_iter != loc_iter_end) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
    std::cout << std::endl;
}

std::string TextQuery::cleanup_str(const std::string& word) {
    std::string ret;
    for (auto iter = word.begin(); iter != word.end(); ++iter) {
        if (!ispunct(*iter)) {
            ret += tolower(*iter);
        }
    }
    return ret;
}