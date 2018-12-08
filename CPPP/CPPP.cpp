// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PartA.h"
#include "Sales_data.h"
//#define NDEBUG  //用于DEBUG
using namespace std;

int main(int argc,char **argv) {

    Sales_data total; // variable to hold data for the next transaction
// read the first transaction and ensure that there are data to process
    if (read(cin,total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(cin, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total.combine(trans); // update the running total
            else {
                // print results for the previous book
                print(cout, total) << endl;
                total = trans; // total now refers to the next book
            }
        }
        print(cout, total) << endl; // print the last transaction
    }
    else {
        // no input! warn the user
        std::cerr << "No data?!" << std::endl;
        return -1; // indicate failure
    }
    return 0;
}