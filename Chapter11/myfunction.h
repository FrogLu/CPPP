#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

using ssumultimap = std::unordered_map<std::string, std::string>;

std::string wordprocess(const std::string & word);

void addfamily(std::istream&is,
	std::map<std::string, std::vector<std::pair<std::string, std::string>>>&families);

void pairprint(std::map<std::string, std::vector<std::pair<std::string, std::string>>>& families);

void word_transform(std::ifstream & map_file, std::ifstream & input);

ssumultimap buildMap(std::ifstream & map_file);

const std::string & transform(const std::string & s, const ssumultimap& m);

#endif // !_MYFUNCTION_H_


