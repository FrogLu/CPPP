#pragma once
#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include "Screen.h"
#include <vector>
using std::vector;

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen& screen);
private:
    std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
inline void Window_mgr::clear(ScreenIndex index) {
	Screen &s = screens[index];
	s.contents = std::string(s.height*s.width, ' ');
}
inline Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen & screen)
{
	screens.push_back(screen);
	return screens.size() - 1;
}
#endif // !Window_MGR_H

