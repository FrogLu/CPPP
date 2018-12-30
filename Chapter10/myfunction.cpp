#include "pch.h"
#include "myfunction.h"
#include "Sales_data.h"

bool compareIsbn(Sales_data& sd1, Sales_data& sd2) {
	return sd1.isbn() < sd2.isbn();
}

bool stringgeq5(std::string& str) {
	return str.size() < 5;
}