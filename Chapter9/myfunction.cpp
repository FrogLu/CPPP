#include "pch.h"
#include "myfunction.h"

std::vector<int> get_next(const std::string& P) {
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

int replace_string_KMP(std::string &s, const std::string &p1,
						const std::string p2) {
	int i = 0;
	int j = 0;
	std::vector<int> next;
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

std::string& fullname(std::string& name, const std::string& prefix,
					const std::string& suffix) {
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
	const std::string num("0123456789");
	auto pos = str.find_first_of(num);
	std::vector<decltype(pos)> vpos;
	while ((pos = str.find_first_of(num, pos))
		!= std::string::npos) {
		vpos.push_back(pos);
		++pos;
	}
	return vpos;
}

std::vector<std::string::size_type>  findletter(std::string &str) {
	const std::string num("0123456789");
	auto pos = str.find_first_not_of(num);
	std::vector<decltype(pos)> vpos;
	while ((pos = str.find_first_not_of(num, pos))
		!= std::string::npos) {
		vpos.push_back(pos);
		++pos;
	}
	return vpos;
}

bool findword(std::string& word) {
	const std::string num("acemnorsuvwxz");
	auto pos = word.find_first_not_of(num);
	if (pos != std::string::npos) {
		return false;
	}
	else {
		return true;
	}
}

void elimDups(std::vector<std::string> &words) {
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	return;
}

bool isShorter(const std::string &s1, const std::string &s2) {
	return s1.size() < s2.size();
}

void stackexpr(	std::stack<char> &charStack,const std::string &expr) {

	bool flag = false;
	bool flagexpr = false;
	std::string rval;
	std::string lval;
	char oper;
	for (auto c : expr) {
		if (c == ')') {
			flag = false;
			while (!charStack.empty()) {
				auto item = charStack.top();
				if (item >= '0'&&item<='9') {
					if (flagexpr == false) {
						rval.insert(0, 1, item);
					}
					else {
						lval.insert(0, 1, item);
					}
				}
				else if(item!=' '&&item!='('){
					oper = item;
					flagexpr = true;
				}
				charStack.pop();
			}
		}
		if (c == '('||flag==true) {
			charStack.push(c);
			flag = true;
		}
	}
	std::cout << "rval: " << rval << std::endl;
	std::cout << "lval: " << lval << std::endl;
	std::cout << "oper: " << oper << std::endl;
	std::cout << "result: " << stackoperation(rval, lval, oper) << std::endl;
}

int stackoperation(const std::string&rval, const std::string&lval, const char &oper) {
	int rnum = stoi(rval);
	int lnum = stoi(lval);
	switch (oper)
	{
	case '+':return rnum + lnum;
		break;
	case '-':return rnum - lnum;
		break; 
	case '*':return rnum * lnum;
		break; 
	case '/':return rnum / lnum;
		break;
	default: throw invalid_argument("invalid operator");
		break;
	}
	
}