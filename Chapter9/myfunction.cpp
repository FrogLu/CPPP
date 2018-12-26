#include "pch.h"
#include "myfunction.h"

std::forward_list<string>::iterator flstInsertStr(
	std::forward_list<string> &flststr,
	std::string &str1,
	std::string &str2) {
	bool flag = false;
	auto prev = flststr.before_begin();
	auto curr = flststr.begin();
	for (; curr !=flststr.end(); ++curr,++prev)
	{
		if ((*curr) == str1) {
			flststr.insert_after(curr, str2);
			flag = true;
			break;
		}
	}
	if (flag) {
		return curr;
	}
	else {
		flststr.insert_after(prev, str2);
		return prev;
	}
}