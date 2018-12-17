#pragma once
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
//#include "Window_mgr.h"

class Screen {
public:
    typedef std::string::size_type pos;
    //using pos = std::string::size_type; // equivalent declaration
    // constructor function
    Screen() = default;
    Screen(const pos &ht, const pos &wd, const char &c)
        :height(ht), width(wd), contents(ht*wd, c) { }
    Screen(const pos &ht, const pos& wd)
        :height(ht), width(wd), contents(ht*wd, ' ') { }
    // normal memeber function
	char get() const;
    char get(pos ht, pos wd) const;
    Screen& set(char c);
    Screen& set(pos r, pos col, char ch);
    Screen& move(pos r, pos c);
	Screen& display(std::ostream &os);
	const Screen& display(std::ostream &os) const;
    void some_member() const;   // just a example function
	// friend member
	friend class Window_mgr;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr = 0;  // count times of calling some_member()
	void do_display(std::ostream &os) const;
};
inline Screen& Screen::set(char c)
{
    try
    {
        if (contents.size() < cursor) {
            throw std::out_of_range("The pos of cursor is out of range");
        }
        else {
            contents[cursor] = c;
        }
    }
    catch (const std::out_of_range& cursor_out_of_range)
    {
        cerr << cursor_out_of_range.what() << endl;
        // 还需要补充如何解决越界问题
    }
    return *this;
}
inline Screen& Screen::set(pos r, pos col, char ch)
{
    contents[r*width + col] = ch;
    return *this;
}
inline Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
inline char Screen::get() const
{
	return contents[cursor];
}
inline char Screen::get(pos r, pos c) const {
    pos row = r * width;
    return contents[row + c];
}
inline Screen& Screen::display(std::ostream &os) {
	do_display(os);
	return *this;
}
inline const Screen& Screen::display(std::ostream &os) const {
	do_display(os);
	return *this;
}
inline void Screen::do_display(std::ostream &os) const {
	os << contents;
}
#endif // !SCREEN_H