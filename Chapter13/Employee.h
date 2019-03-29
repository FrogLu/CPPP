#pragma once
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

class Employee
{
public:
    Employee();
    Employee(std::string str);
    Employee(const Employee& ep);
    Employee& operator=(const Employee& rhs);
    ~Employee();
private:
    std::string name;
    int num;
    static int count;
};

#endif // !_EMPLOYEE_H_


