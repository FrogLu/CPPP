// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PartA.h"
#include "Sales_data.h"
#include "Screen.h"

//#define NDEBUG  //用于DEBUG
using namespace std;

int main(int argc,char **argv) {
    Sales_data item1;
    Sales_data item2("item2");
    Sales_data item3("item3", 10, 6.0);
    //Sales_data item4(cin);
    int i = 5;
    string str(10,'A');
    // auto flag=(*(str.begin() + i)).empty();
    str[0] = '#';
    cout << str.capacity() << endl;
    item1 = add(item1, item2);
    print(cout, item1) << endl;
    print(cout, item2) << endl;
    print(cout, item3) << endl;
    //print(cout, item4) << endl;

	// Test for set()
	// Hint:There is a bug unfixed
    Screen myScreen;
    myScreen.move(4, 10).set('#');

	// Test for overload display
	Screen myScreen2(5, 3);
	const Screen blank(5, 3);
	myScreen2.set('#').display(cout);
	blank.display(cout);
    return 0;
}