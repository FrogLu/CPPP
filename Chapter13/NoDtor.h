#pragma once
class NoDtor
{
public:
    NoDtor() = default;
    ~NoDtor() = delete;
};

