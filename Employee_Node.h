#pragma once
#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    /* data */
public:
    string name;
    int age;
    int emplooye_number;
    int password;
    Employee* left;
    Employee* right;

    Employee();
    Employee(string, int ,int , int);
    bool employee_password_verify();
};


