#include "pch.h"
#include "myfunction.h"

std::vector<int> get_next(const string& P) {
	const int sentinel = -1;
	size_t m = P.size(), j = 0;
	std::vector<int> next(m, -1);
	int t = sentinel;
	while (j < m - 1) {
		if (0 > t || P[j] == P[t]) {
			//next.push_back(++t);
			//++j;
			next[++j] = ++t;
		}
		else {
			t = next[t];
		}
	}
	return next;
}

int replace_string_KMP(string &s, const string &p1,const string p2) {
	int i = 0;
	int j = 0;
	vector<int> next;
	next = get_next(p1);
	/*next.assign(get_next(p1).begin(), get_next(p1).end());*/
	while (i < s.size() && j < p1.size()) {
		if (j == 0 || s[i] == p1[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j >= p1.size()) {
		//s.erase(i - p1.size(), p1.size());
		//s.insert(i-p1.size(), p2);
		s.replace(i - p1.size(), p1.size(), p2);
		return i - p1.size();
	}
	else {
		return 0;
	}
}

string& fullname(string& name, const string& prefix, const string& suffix) {
	/* Practice9.45 with iterator */
	//auto nameiter = name.begin();
	//auto iter = prefix.end();
	//do {
	//	--iter;
	//	nameiter = name.insert(nameiter, *iter);
	//} while (iter > prefix.begin());
	//name.append(suffix);
	name.insert(0, prefix);
	name.insert(name.size(), suffix);

	return name;
}

std::vector<std::string::size_type>  findnum(std::string &str) {
	const string num("0123456789");
	auto pos = str.find_first_of(num);
	vector<decltype(pos)> vpos;
	while ((pos = str.find_first_of(num, pos))
		!= string::npos) {
		vpos.push_back(pos);
		++pos;
	}
	return vpos;
}

std::vector<std::string::size_type>  findletter(std::string &str) {
	const string num("0123456789");
	auto pos = str.find_first_not_of(num);
	vector<decltype(pos)> vpos;
	while ((pos = str.find_first_not_of(num, pos))
		!= string::npos) {
		vpos.push_back(pos);
		++pos;
	}
	return vpos;
}

bool findword(string& word) {
	const string num("acemnorsuvwxz");
	auto pos = word.find_first_not_of(num);
	if (pos != std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

void elimDups(vector<string> &words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}

bool isShorter(const string &s1, const string &s2) {
	return s1.size() < s2.size();
}