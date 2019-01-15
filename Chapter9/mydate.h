#pragma once
#ifndef _MYDATE_H_
#define _MYDATE_H_
class mydate {
public:
	// constructors
	mydate() {};
	// function member
	void stringtodate(const string&str);
	void stringtomonth(const string&strmonth);
	friend std::ostream& operator<<(std::ostream& os, mydate&date);
private:
	unsigned year = 1;
	unsigned month = 13;
	unsigned day = 32;
};
#endif // !_MYDATE_H_
std::ostream& operator<<(std::ostream& os, mydate&date);