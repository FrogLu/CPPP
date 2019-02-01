#include "pch.h"
#include "myfunction.h"

connection connect(destination*) { connection c; return c; };
void disconnect(connection) {};

void end_connection(connection* p) {
    disconnect(*p);
}

void f(destination& d) {
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, end_connection);
}