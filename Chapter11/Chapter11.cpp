#include "pch.h"
#include "myfunction.h"

int main()
{
	/* fin starts */
	std::ifstream fin("./data/Input/authors_work");
	assert(fin.good());
	fin.tie(&cout);
	std::multimap<std::string, std::string> authors_books;
	std::string author, book;
	while (fin >> author && getline(fin, book)) {
		if (book.size() > 1) {
			book = book.substr(1);
		}
		else
		{
			throw std::runtime_error("error: no book name for" + author);
		}
		authors_books.insert({ author,book });
	}
	std::cout << "Origin: " << std::endl;
	for (auto aw : authors_books) {
		std::cout << "Author: " << aw.first
			<< " Book: " << "¡¶" << aw.second <<"¡·"<< std::endl;
	}
	std::cout << std::endl;
	const string search_item{ "BjarneStroustrup" };
	auto iter = authors_books.find(search_item);
	if (!(iter != authors_books.cend())) {
		std::cout << "Oops: Can't find author: " << search_item << std::endl;
	}
	while (iter!=authors_books.cend()) {
		std::cout << "Ok: Author: " << iter->first 
			<< " Book: " << "¡¶" << iter->second << "¡·" << std::endl;
		authors_books.erase(iter);
		iter = authors_books.find(search_item);
	}
	std::cout << std::endl;
	std::cout << "After find and erase:" << std::endl;
	for (auto aw : authors_books) {
		std::cout << "Author: "<<aw.first 
			<<" Book: " << "¡¶" << aw.second << "¡·" << std::endl;
	}

	return 0;
}
