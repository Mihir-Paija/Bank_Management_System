#pragma once
#include "Employee_Node.h"
#include "Account_Node.cpp"
#include "Accounts_BST.cpp"

class Employee_BST
{
private:
    /* data */
public:
    Employee *root;

    Employee_BST();

    Employee* get_employee(void );
    bool employee_password_verify(Employee* );
    void load_employee_server();
    void update_employee_server(Employee *, int);
    Employee *search(int);
    void add_Employee(string, int, int);
    void delete_Employee(int, int);
    void withdraw(int, Accounts_BST& );
    void deposit(int, Accounts_BST & );
    void edit_profile(int, int);
    void transfer(int, Accounts_BST&);
};
