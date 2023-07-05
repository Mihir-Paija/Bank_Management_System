// #pragma once
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

// #include "Account_Node.cpp"
// #include "Accounts_BST.cpp"


// #include "Verfications.h"

#include "Employee_Node.cpp"
#include "Employee_BST.cpp"

Accounts_BST Accounts_DataBase;
Employee_BST Employees_DataBase;

// #include "test.h"
#include "Customer.h"
#include "Staff.h"
#include "Admin.h"

void boot(){
    Accounts_DataBase.load_accounts_server();
    Employees_DataBase.load_employee_server();
}


int main()
{
    boot();

    int opt;
    cout << endl;

    do
    {
        cout << "\n***** Welcome to Bank Management System *****" << endl << endl;
        cout << "\nLogin As" << endl;
        cout << "1 : Customer " << endl;
        cout << "2 : Staff" << endl;
        cout << "3 : admin" << endl;
        cout << "Or press \'-1\' for exit" << endl;
        cout << "\nSelect your option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            customer();
            break;

        case 2:
            staff();
            break;

        case 3:
            admin();
            break;

        case -1:
            /* code */
            break;

        default:
            cout << "\n!! Invalid Option !!" << endl;
            break;
        }
    } while (opt != -1);

    cout << "\n***** Thanks for Visit *****" << endl;

    return 0;
}
