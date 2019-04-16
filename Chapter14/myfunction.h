#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

void elimDups(std::vector<std::string>& words);

const std::string make_plural(std::string::size_type count, const string& words,
    const string& suffix);

void biggies(std::vector<std::string>& words,
    std::vector<std::string>::size_type sz);

// Practice14.44 Calculator
static std::map<std::string, std::function<int(int, int)>> binOps = {
    {"+",std::plus<int>()},
    {"-",std::minus<int>()},
    {"*",std::multiplies<int>()},
    {"/",std::divides<int>()},
    {"%",std::modulus<int>()},
};

#endif // !_MYFUNCTION_H_