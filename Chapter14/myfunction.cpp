#include "pch.h"
#include "MyClass.h"
#include "myfunction.h"

void elimDups(std::vector<std::string>& words) {
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
    return;
}

const std::string make_plural(
    std::string::size_type count,
    const string& words,
    const string& suffix) {
    try
    {
        if (count <= 0) {
            throw std::range_error
            ("The first argument of make_plural must be greater than zero");
        }
    }
    catch (const std::range_error & rerr)
    {
        std::cout << rerr.what() << std::endl
            << "Try Again? Enter y or n" << std::endl;
        char c;
        std::cin >> c;
        if (c == 'y') {
            int num;
            std::cout << "Please Enter the new number: " << std::endl;
            std::cin >> num;
            return make_plural(num, words, suffix);
        }
    }

    if (count == 1) {
        return words;
    }
    else {
        // Can't use "words+suffix" as return value, even use const_cast.
        // Because words+suffix return a temp value,
        // and return type is a reference.
        // The most serious consequence is that it will cause cout bad!!!
        // So if use "words+suffix", need to change return type to const string.
        // Hits(Important): After testing, return const string type 
        // and using "words+suffix" can be safer than return a reference.
        return words + suffix;
    }
}

void biggies(std::vector<std::string>& words,
    std::vector<std::string>::size_type sz) {
    StrNotShorterThan sNotShorterThan(sz);
    elimDups(words);    // it will remove duplicate words, so count will less than Practice14.39
    std::stable_sort(words.begin(), words.end(), sNotShorterThan);
    auto wc = find_if(words.begin(), words.end(), sNotShorterThan);
    auto count = words.end() - wc;
    std::cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(), PrintString(std::cout, ' '));
}

