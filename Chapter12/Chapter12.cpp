#include "pch.h"
#include "myfunction.h"
#include "StrBlob.h"

int main()
{
	const StrBlob b1{ "Hello","FrogLu" };
	
	std::cout << b1.front() << " " << b1.back() << std::endl;

	return 0;
}