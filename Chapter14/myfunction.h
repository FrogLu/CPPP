#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

void elimDups(std::vector<std::string>& words);

const std::string make_plural(std::string::size_type count, const string& words,
    const string& suffix);

void biggies(std::vector<std::string>& words,
    std::vector<std::string>::size_type sz);

#endif // !_MYFUNCTION_H_