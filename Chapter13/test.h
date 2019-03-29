#pragma once
class test
{
public:
    test() = default;
    test(int val) { 
        // without this constructor, synthesizes copy-Assignment operator won't work well.
        // complier will throw error message:
        // 1) C2440 'initializing: cannot convert from 'int' to 'test'
        i = val;
    }
    ~test() = default;
private:
    int i;
    //  if i is const type
    //  E0366 "test::test(int val)" provides no initializer for :
    //  C2789 'test::i' : an object of const - qualified type must be initialized
    //const int i;
};

