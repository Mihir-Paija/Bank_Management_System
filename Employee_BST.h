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

    void Display_employees(Employee*);
    void load_employee_server();
    void update_employee_server(Employee *, int);

    Employee *search(int);
    Employee* get_employee(void );
    Employee* get_successor(Employee* );
    void copy_data(Employee*,Employee*);

    void add_Employee(string, int, int);
    void Delete();
    void delete_Employee(Employee*&,int);
    void edit_profile(Employee* );

    void withdraw(int, Accounts_BST& );
    void deposit(int, Accounts_BST & );
    void transfer(int, Accounts_BST&);
};
