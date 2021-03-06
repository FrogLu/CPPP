#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

void elimDups(std::vector<std::string> &words) {
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}

bool isShorter(const std::string &s1, const std::string &s2) {
	return s1.size() < s2.size();
}

bool compareIsbn(Sales_data& sd1, Sales_data& sd2) {
	return sd1.isbn() < sd2.isbn();
}

bool stringgeq5(std::string& str) {
	return str.size() < 5;
}

void biggies(std::vector<std::string> &words,
	std::vector<std::string>::size_type sz) {
	elimDups(words);
    std::stable_sort(words.begin(), words.end(),
        std::bind(isShorter,_1,_2));
	auto wc = std::stable_partition(words.begin(), words.end(),
		std::bind(check_size,_1,sz));
	auto count = wc - words.begin();
	//auto count = std::count_if(words.begin(), words.end(),
	//	std::bind(check_size,_1,sz));
	std::cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << std::endl;
	for_each(words.begin(), words.begin()+count,
		std::bind(printstr,_1));
}

const std::string make_plural(
	std::string::size_type count,
	const std::string &words,
	const std::string &suffix) {
	try
	{
		if (count <= 0) {
			throw std::range_error
			("The first argument of make_plural must be greater than zero");
		}
	}
	catch (const std::range_error& rerr)
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
		return words+suffix;
	}
}

bool check_size(const std::string&s, std::string::size_type sz) {
	return s.size() >= sz;
}

void printstr(const string &s) {
	std::cout << s << " ";
}

void elimDups_list(std::list<string> &words) {
	words.sort();
	words.unique();
}