#include "pch.h"
#include "mydate.h"

std::ostream& operator<<(std::ostream& os,mydate&date) {
	os << date.month << " " << date.day << " " << date.year << " " << std::endl;
	return os;
}
