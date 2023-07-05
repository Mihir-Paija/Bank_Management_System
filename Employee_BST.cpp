#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Employee_BST.h"

Employee_BST ::Employee_BST()
{
    root = nullptr;
}

void Employee_BST ::Display_employees(Employee *curr)
{
    if (!curr)
        return;

    cout << "\nEmployee Number : " << curr->emplooye_number << endl;
    cout << "Employee Name : " << curr->name << endl;
    cout << "Employee Age : " << curr->age << endl;
    Display_employees(curr->left);
    Display_employees(curr->right);
}

void Employee_BST ::load_employee_server(void)
{
    // cout << "loading" << endl;
    ifstream read;
    read.open("Employee_Server.txt");

    string name = "";
    int age = 0;
    int employeeno = 0;
    int password = 0;

    while (!read.eof())
    {
        getline(read, name);
        read >> age;
        read >> employeeno;
        read >> password;
        read.ignore();

        if (name != "" && employeeno != 0 && password != 0 && age >= 20)
        {
            Employee *emp = new Employee(name, age, employeeno, password);
            if (!root)
            {
                root = emp;
            }
            else
            {
                Employee *curr = root;
                while (1)
                {
                    if (employeeno < curr->emplooye_number)
                    {
                        if (!curr->left)
                        {
                            curr->left = emp;
                            break;
                        }
                        curr = curr->left;
                    }
                    else if (employeeno > curr->emplooye_number)
                    {
                        if (curr->right == nullptr)
                        {
                            curr->right = emp;
                            break;
                        }
                        curr = curr->right;
                    }
                }
            }
        }
    }

    read.close();
}

void Employee_BST ::update_employee_server(Employee *curr, int Root)
{
    if (Root == 0)
    {
        Root++;
        remove("Employee_Server.txt");
    }

    ofstream write;
    write.open("Employee_Server.txt", ios::app);

    if (curr)
    {
        write << curr->name << endl;
        write << curr->age << endl;
        write << curr->emplooye_number << endl;
        write << curr->password << endl;
        update_employee_server(curr->left, Root);
        update_employee_server(curr->right, Root);
    }
    write.close();
}

Employee *Employee_BST ::search(int empoyeeno)
{
    if (!root)
        return nullptr;

    Employee *curr = root;
    while (curr)
    {
        if (curr->emplooye_number == empoyeeno)
            return curr;
        else if (empoyeeno < curr->emplooye_number)
            curr = curr->left;
        else if (empoyeeno > curr->emplooye_number)
            curr = curr->right;
    }
    return nullptr;
}

Employee *Employee_BST ::get_employee(void)
{
    Employee *temp = nullptr;
    int employeeno = 0;
    while (1)
    {
        cout << "\nEnter employee number : ";
        cin >> employeeno;
        if (employeeno == -1)
        {
            return nullptr;
        }
        temp = search(employeeno);
        if (temp == nullptr)
        {
            cout << "\n!! Employee not found !!" << endl;
            cout << "Try Again..." << endl;
        }
        else
            return temp;
    }
}

Employee *Employee_BST ::get_successor(Employee *emp)
{
    if (emp->right)
    {
        emp = emp->right;
        while (emp->left)
            emp = emp->left;

        return emp;
    }
    return nullptr;
}

void Employee_BST ::copy_data(Employee *x, Employee *y)
{
    x->name = y->name;
    x->emplooye_number = y->emplooye_number;
    x->password = y->password;
    x->age = y->age;
}

void Employee_BST ::add_Employee(string name, int age, int password)
{
    int empoyeeno = 0;
    do
    {
        empoyeeno = (rand() + 11000) % 10000;

    } while (!(search(empoyeeno) == nullptr && empoyeeno < 10000 && empoyeeno > 999));

    Employee *new_emp = new Employee(name, age, empoyeeno, password);
    if (!root)
    {
        root = new_emp;
    }
    else
    {
        Employee *curr = root;
        while (1)
        {
            if (empoyeeno < curr->emplooye_number)
            {
                if (!curr->left)
                {
                    curr->left = new_emp;
                    break;
                }
                curr = curr->left;
            }
            else if (empoyeeno > curr->emplooye_number)
            {
                if (!curr->right)
                {
                    curr->right = new_emp;
                    break;
                }
                curr = curr->right;
            }
        }
    }

    ofstream write;
    write.open("Employee_Server.txt", ios::app);
    write << name << endl;
    write << age << endl;
    write << empoyeeno << endl;
    write << password << endl;
    write.close();

    // update_employee_server(root,0);

    cout << "\nEmployee Account successfully created..." << endl;
    cout << "your account number is : " << empoyeeno << endl;
}

void Employee_BST ::delete_Employee(Employee *&curr, int employeeno)
{

    if (curr->emplooye_number == employeeno)
    {
        if (!curr->left && !curr->right)
        {
            delete (curr);
            curr = NULL;
            return;
        }
        else if (!curr->left)
        {
            Employee *temp = curr;
            curr = curr->right;
            delete (temp);
            temp = nullptr;
            return;
        }
        else if (!curr->right)
        {
            Employee *temp = curr;
            curr = curr->left;
            delete (temp);
            temp = nullptr;
            return;
        }
        else
        {
            Employee *succ = get_successor(curr);
            copy_data(curr, succ);
            delete_Employee(curr->right, succ->emplooye_number);
            return;
        }
    }
    else if (employeeno < curr->emplooye_number)
        delete_Employee(curr->left, employeeno);
    else if (employeeno > curr->emplooye_number)
        delete_Employee(curr->right, employeeno);
}

void Employee_BST ::Delete()
{
    Employee *emp = get_employee();
    if (!emp)
        return;

    int empno = emp->emplooye_number;
    delete_Employee(root, emp->emplooye_number);

    update_employee_server(root, 0);

    cout << "\nEmployee of employee number " << empno << " successfully deleted." << endl;
}

void Employee_BST ::edit_profile(Employee *emp) // change needed
{
    int opt;
    cout << "\nWhat you want to edit" << endl;
    cout << "1 : Edit my name" << endl;
    cout << "2 : Edit my age" << endl;
    cout << "\nSelect your option : ";
    cin >> opt;
    switch (opt)
    {
    case 1:
    {
        string new_name = "";
        cout << "\nEnter New Name : ";
        cin >> new_name;
        if (new_name == "-1")
            break;

        emp->name = new_name;
        update_employee_server(root, 0);
        cout << "\nname changed successfully" << endl;
        break;
    }

    case 2:
    {
        int new_age = 0;
        cout << "\nEnter your age : ";
        cin >> new_age;
        if(new_age == -1)
            break;

        emp->age = new_age;
        update_employee_server(root, 0);
        cout << "\nage changed successfully" << endl;
        break;
    }

    case -1:
    {
        break;
    }

    default:
        break;
    }
}

void Employee_BST ::withdraw(int withdraw_slip_no, Accounts_BST &Accounts_DataBase)
{
    while (!(withdraw_slip_no < 100000 && withdraw_slip_no > 9999 && withdraw_slip_no % 331 == 0))
    {
        if (withdraw_slip_no == -1)
            return;
        cout << "\nInvalide deposit slip" << endl;
        cout << "Try again..." << endl;
        cout << "\nEnter withdraw slip number : ";
        cin >> withdraw_slip_no;
    }
    cout << "\nwithdraw slip number " << withdraw_slip_no << " verified." << endl;
    Account *acc = Accounts_DataBase.get_account();
    if (!acc)
        return;

    int amount = 0;
    cout << "\nEnter the amount that customer want to withdraw : ";
    cin >> amount;
    if (amount == -1)
        return;

    Accounts_DataBase.withdraw(acc, amount);
}

void Employee_BST ::deposit(int deposit_slip_no, Accounts_BST &Accounts_DataBase)
{
    while (!(deposit_slip_no < 100000 && deposit_slip_no > 9999 && deposit_slip_no % 333 == 0))
    {
        if (deposit_slip_no == -1)
            return;
        cout << "\nInvalide deposit slip" << endl;
        cout << "Try again..." << endl;
        cout << "\nEnter deposit slip number : ";
        cin >> deposit_slip_no;
    }
    cout << "\nDeposit slip number " << deposit_slip_no << " verified." << endl;

    Account *acc = Accounts_DataBase.get_account();
    if (!acc)
        return;

    int amount = 0;
    cout << "\nEnter the amount that customer want to deposite : ";
    cin >> amount;
    if (amount == -1)
        return;

    Accounts_DataBase.deposit(acc, amount);
}

void Employee_BST ::transfer(int cheque_no, Accounts_BST &Accounts_DataBase)
{
    while (!(cheque_no < 100000 && cheque_no > 9999 && cheque_no % 347 == 0))
    {
        if (cheque_no == -1)
            return;
        cout << "\nInvalide cheque" << endl;
        cout << "Try again..." << endl;
        cout << "\nEnter withdraw slip number : ";
        cin >> cheque_no;
    }
    cout << "\nCheque number " << cheque_no << " verified." << endl;

    cout << "\n# # Enter Accont detials of Cheuqe Owner # #" << endl;
    Account *acc = Accounts_DataBase.get_account();
    if (!acc)
        return;

    cout << "\n# # Enter Accont detials of Payee # #" << endl;
    Account *payee_acc = Accounts_DataBase.get_account();
    if ((!payee_acc))
        return;

    int amount = 0;
    cout << "\nEnter the amount that customer want to transfer : ";
    cin >> amount;
    if (amount == -1)
        return;

    Accounts_DataBase.transfer(acc, payee_acc, amount);
}