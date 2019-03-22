#pragma once
#ifndef _MYFUNCTION_H_
#define _MYFUNCTION_H_

struct destination {
    destination()=default;

};
struct connection {
    connection() = default;
};
connection connect(destination*);
void disconnect(connection);
void end_connection(connection* p);
void f(destination& d);

//void myrunQueries(std::ifstream& infile);
#endif // !_MYFUNCTION_H_