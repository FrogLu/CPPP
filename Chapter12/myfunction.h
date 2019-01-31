#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

shared_ptr<vector<int>> Foo();

shared_ptr<vector<int>> InputFoo(std::istream& is, shared_ptr<vector<int>> pivec);

void OutputFoo(std::ostream& os, shared_ptr<vector<int>> pivec);

#endif // !_MYFUNCTION_H_