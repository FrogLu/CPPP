#pragma once
#ifndef _MYDATE_H_
#define _MYDATE_H_
class mydate {
public:
	// constructors
	mydate() =default;
	mydate(string &datestr);
	// function member
	unsigned getyear() const { return year; }
	unsigned getmonth() const { return month; }
	unsigned getday() const { return day; }
	// friend member
	//// overload function
	friend std::ostream& operator<<(std::ostream& os, mydate&date);
private:
	unsigned year = 2019;
	unsigned month = 1;
	unsigned day = 15;
};
// month full name
const string month_name[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
// month abbr name
const string month_abbr[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
// max day number pre month
const std::vector<int> days = { -1,31,28,31,30,31,30,31,31,30,31,30,31 }; // -1 as a sentinel to fix days[0]

inline int get_month(std::string &datestr, int &end_of_month) {
	int outer, inner;
	for (outer = 0; outer < 12; outer++) {
		for (inner = 0; inner < month_abbr[outer].size(); inner++) {
			if (datestr[inner] != month_abbr[outer][inner]) {
				break;
			}
		}
		if (inner == month_abbr[outer].size()) {
			break;
		}
	}

	if (outer == 12) {
		throw std::invalid_argument("invalid month name!");
	}

	if (datestr[inner] == ' ') {
		end_of_month = inner + 1;
		return outer+1;
	}

	for (; inner < month_name[outer].size(); inner++) {
		if (datestr[inner] != month_name[outer][inner]) {
			break;
		}
	}
	
	if (inner == month_name[outer].size() && datestr[inner] == ' ') {
		end_of_month = inner + 1;
		return outer+1;
	}

	throw std::invalid_argument("invalid month name!");
}

inline int get_day(std::string &datestr, int month, int&pos) {
	size_t q;
	int day = stoi(datestr.substr(pos), &q);
	if (day<1 || day>days[month]) {
		throw std::invalid_argument("invalid day value!");
	}
	pos += q;
	return day;
}

inline int get_year(std::string &datestr, int &pos) {
	size_t q;
	int year = stoi(datestr.substr(pos), &q);
	if (pos + q < datestr.size()) {
		throw std::invalid_argument("invalid end content!");
	}
	return year;
}

inline mydate::mydate(std::string &datestr) {
	int pos;
	size_t q;

	if ((pos = datestr.find_first_of("0123456789")) == std::string::npos) {
		throw std::invalid_argument("no digital,invalid date!");
	}

	if (pos > 0) {
		month = get_month(datestr, pos);
		day = get_day(datestr, month, pos);
		if (datestr[pos] != ' '&&datestr[pos] != ',') {
			throw std::invalid_argument("invalid spacer!");
		}
		++pos;
		year = get_year(datestr, pos);
	}
	else {// deal with such as 1/1/1990
		month = stoi(datestr, &q);
		pos = q;
		if (month < 1 || month>12) {
			throw std::invalid_argument("invalid month value!");
		}
		if (datestr[pos++] != '/') {
			throw std::invalid_argument("invalid spacer!");
		}
		day = get_day(datestr, month, pos);
		if (datestr[pos++] != '/') {
			throw std::invalid_argument("invalid spacer!");
		}
		year = get_year(datestr, pos);
	}
}
std::ostream& operator<<(std::ostream& os, mydate&date);
#endif // !_MYDATE_H_
