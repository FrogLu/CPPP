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