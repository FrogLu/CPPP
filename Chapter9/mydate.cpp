#include "pch.h"
#include "mydate.h"

void mydate::stringtodate(const string & str)
{
	auto lastpos = str.find_last_of(" /,");
	auto firstpos = str.find_first_of(" /,");
	
	auto strmonth = str.substr(0, firstpos);
	mydate::stringtomonth(strmonth);
	mydate::day = stoi(str.substr(firstpos+1, lastpos - firstpos));
	mydate::year = stoi(str.substr(lastpos+1));

}

void mydate::stringtomonth(const string & strmonth)
{
	const std::vector < std::string> word3month{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	const std::vector < std::string> word10month{ "January","February","March","April","May","June","July","August","September","October","November","December" };
	if (strmonth.size() <= 0) {
		std::cerr << "wrong data" << std::endl;
	}
	else if (strmonth.size() < 3) {
		mydate::month = stoi(strmonth);
	}
	else if (strmonth.size() < 4) {
		auto pos = 0;
		while (strmonth != word3month[pos]) {
			++pos;
		}
		mydate::month = pos + 1;
	}
	else {
		auto pos = 0;
		while (strmonth != word10month[pos]) {
			++pos;
		}
		mydate::month = pos + 1;
	}
}

std::ostream& operator<<(std::ostream& os,mydate&date) {
	os << date.month << " " << date.day << " " << date.year << " " << std::endl;
	return os;
}
