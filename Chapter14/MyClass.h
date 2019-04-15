#pragma once
#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class MyIfElse {
public:
    MyIfElse() = default;
    MyIfElse(const std::size_t i1, const std::size_t i2, const std::size_t i3) :iVal1(i1),iVal2(i2), iVal3(i3) {}
    std::size_t operator()(const std::size_t, const std::size_t& first, const std::size_t& last);
private:
    const std::size_t iVal1, iVal2, iVal3;
};

inline
std::size_t MyIfElse::operator()(const std::size_t condition, const std::size_t& first, const std::size_t& last) {
    return condition ? first : last;
}

class PrintString {
public:
    PrintString(std::ostream& out = std::cout, const char c = ' ') :
        os(out), sep(c) {}
    void operator()(const std::string& str) const;
private:
    std::ostream& os;
    char sep;
};

inline
void PrintString::operator()(const std::string& str) const {
    os << str << sep;
}

class ReadString {
public:
    ReadString(std::istream& in = std::cin) :
        is(in) {};
    std::string operator()(/*void*/);
private:
    std::istream& is;
    std::string str;
};

inline
std::string ReadString::operator()(/*void*/) {
    return std::getline(is, str) ? str : std::string();
}

class MyEquation {
public:
    MyEquation(std::size_t i = 0) :
        ref(i) {}
    bool operator()(std::size_t& n);
private:
    std::size_t ref;
};

inline
bool  MyEquation::operator()(std::size_t& n) {
    return n == ref;
}

class CheckSize {
public:
    CheckSize(std::string::size_type init = 0) :
        threshold(init) {}
    bool operator()(const std::string& str);
private:
    std::string::size_type threshold;
};

inline
bool CheckSize::operator()(const std::string& str) {
    return str.size() == threshold;
}
#endif // !_MYCLASS_H_
