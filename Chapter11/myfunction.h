#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

std::string wordprocess(const std::string & word);

void addfamily(std::istream&is,
	std::map<std::string, std::vector<std::pair<std::string, std::string>>>&families);

void pairprint(std::map<std::string, std::vector<std::pair<std::string, std::string>>>& families);

#endif // !_MYFUNCTION_H_


