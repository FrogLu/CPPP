#include "pch.h"
#include "Employee.h"

int Employee::count = 0;

Employee::Employee()
{
    num = count++;
}

Employee::Employee(std::string str)
{
    name = str;
    num = count++;
}

Employee::Employee(const Employee& ep)
{
    num = count++;
}

Employee&
Employee::operator=(const Employee& rhs)
{
    num = count++;

    return *this;
}


Employee::~Employee()
{
}
