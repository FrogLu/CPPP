// CPPP.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test.h"
#include "Sales_data.h"
#include "Screen.h"

//#define NDEBUG  //用于DEBUG
using namespace std;

int main(int argc,char **argv) {
    Sales_data item1;
    Sales_data item2("item2");
    Sales_data item3("item3", 10, 6.0);
    //Sales_data item4(cin);

    // auto flag=(*(str.begin() + i)).empty();
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
	cout << endl;
	// Practice 7.27
	Screen myScreen3(5, 5, 'X');
	myScreen3.move(4, 0).set('#').display(cout);
	cout << endl;
	myScreen3.display(cout);
	cout << endl;
	// Practice 7.31
	X x;
	Y y;
	// Practice 7.41
	Sales_data test1;
	Sales_data test2("test", 0, 0);
	Sales_data test3("test");
	//Sales_data test4(cin);     
	// Chapter 7.5.3
	Sales_data Primer_5th_ed;
	Sales_data obj(); // obj是一个返回值为Sales_data的零参数函数
	//if (obj.isbn() == Primer_5th_ed.isbn());
	// Practice 7.44
	vector<NoDefault> vec(10,10);
    return 0;
}