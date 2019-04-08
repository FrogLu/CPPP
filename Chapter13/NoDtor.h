#pragma once
#ifndef _NODTOR_H_
#define _NODTOR_H_

class NoDtor
{
public:
    NoDtor() = default;
    ~NoDtor() = delete;
};

#endif // !_NODTOR_H_

