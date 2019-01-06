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
	stable_sort(words.begin(), words.end(),
		[](const string &a, const string &b) {
			return a.size() < b.size();
		});
	auto wc = find_if(words.begin(), words.end(),
		[sz](const string &words) {
			return words.size() >= sz;
		});
	auto count = words.end() - wc;
	auto state = cout.rdstate();
	cout << count << " ";cout << make_plural(count, "word", "s") << endl;
	state = cout.rdstate();
	for_each(wc, words.end(),
		[](const string &s) {
			std::cout << s << " ";
		});
}

const std::string& make_plural(
	std::string::size_type count,
	const string &words, 
	const string &suffix) {
	try
	{
		if (count <= 0) {
			throw std::range_error
			("The first argument of make_plural must be greater than zero");
		}
	}
	catch (const std::range_error& rerr)
	{
		cout << rerr.what() << endl
		<< "Try Again? Enter y or n" << endl;
		char c;
		std::cin >> c;
		if (c == 'y') {
			int num;
			std::cout << "Please Enter the new number: " << endl;
			std::cin >> num;
			return make_plural(num, words, suffix);
		}
	}
	
	if (count == 1) {
		return words;
	}
	else {
		// Can't use "words+suffix" as return value,even use const_cast.
		// Because words+suffix return a temp value,
		// and return type is a reference.
		// The most serious consequence is that it will cause cout bad!!!
		// So if use "words+suffix",need to change return type to const string.
		return const_cast<string &>(words).append(suffix);
	}
}
