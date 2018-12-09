#pragma once
#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H
#include "Screen.h"

class Window_mgr {
private:
    std::vector<Screen> screens(24, 80, " ");
};
#endif // !Window_MGR_H

