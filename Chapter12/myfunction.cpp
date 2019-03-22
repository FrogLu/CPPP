#include "pch.h"
#include "myfunction.h"
#include "TextQuery.h"

connection connect(destination*) { connection c; return c; };
void disconnect(connection) {};
void end_connection(connection* p) {
    disconnect(*p);
}

void f(destination& d) {
    connection c = connect(&d);
    std::unique_ptr<connection, decltype(end_connection)*>
        p(&c, end_connection);
}

//void myrunQueries(std::ifstream& infile) {
//    TextQuery tq(infile);
//    while (true) {
//        std::cout << "Enter word to look for, or q to quit: ";
//        std::string str;
//        if (!(std::cin >> str) || str == "q") {
//            break;
//        }
//        print(std::cout, tq.query(str)) << std::endl;
//    }
//}