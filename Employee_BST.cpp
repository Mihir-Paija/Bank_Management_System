#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "Employee_BST.h"

Employee_BST ::Employee_BST()
{
    root = nullptr;
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
        // getline(read,name);
        // cout << "name" << name << endl;
        if (name != "" && employeeno != 0 && password != 0 && age >= 20)
        {
            Employee *emp = new Employee(name, age, employeeno, password);
            if (!root)
            {
                // cout << "root" << endl;
                root = emp;
            }
            else
            {
                // cout << "not root" << endl;
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


Employee* Employee_BST :: get_employee(void ){
    Employee* temp=nullptr;
    int employeeno=0;
    while(1)
    {
        cout << "\nEnter employee number (or press -1 to exit) : ";
        cin >> employeeno;
        if(employeeno == -1){
            return nullptr;
        }
        temp = search(employeeno);
        if(temp == nullptr){
            cout << "\n!! Employee not found !!" << endl;
            cout <<"Try Again..." << endl;
        }
        else
            return temp;
    } 
}

void Employee_BST ::add_Employee(string name, int age, int password)
{
    int empoyeeno = 0;
    do
    {
        empoyeeno = (rand() + 1000) % 1000;

    } while (search(empoyeeno) != nullptr);

    ofstream write;
    write.open("Employee_Server.txt", ios::app);
    write << name << endl;
    write << age << endl;
    write << empoyeeno << endl;
    write << password << endl;
    write.close();

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
            // else{
            //     cout << "This account is already open in the name of "<<curr->name << endl;
            //     break;
            // }
        }
    }
    cout << "\nEmployee Account successfully created..." << endl;
    cout << "your account number is : " << empoyeeno << endl;
}

void Employee_BST ::delete_Employee(int accountno, int password)
{
}

void Employee_BST ::edit_profile(int empoyeeno, int password) // change needed
{
    Employee *emp = search(empoyeeno);
    string new_name = "";
    cout << "Enter New Name : " << endl;
    cin >> new_name;
    emp->name = new_name;
    cout << "name changed successfully" << endl;
    int new_age = 0;
    cout << "Enter your age : " << endl;
    cin >> new_age;
    emp->age = new_age;
    cout << "age changed successfully" << endl;
    update_employee_server(root, 0);
}

void Employee_BST ::transfer(int cheque_no, Accounts_BST& Accounts_DataBase)
{
    while( !(cheque_no<100000 && cheque_no > 9999 && cheque_no % 347 == 0)){
        cout << "\nInvalide cheque" << endl;
        cout << "Try again..." << endl;
        cout << "\nEnter withdraw slip number : " << endl;
        cin >> cheque_no;
        if(cheque_no == -1)
            return;
    }
    cout << "\nCheque number " << cheque_no << " verified." << endl;

    cout << "\n# # Enter Accont detials of Cheuqe Owner # #" <<endl;
    Account* acc = Accounts_DataBase.get_account();
    if(!acc)
        return;

    cout << "\n# # Enter Accont detials of Payee # #" <<endl;
    Account* payee_acc = Accounts_DataBase.get_account();
    if((!payee_acc))
        return;

    int amount=0;
    cout << "\nEnter the amount that customer want to transfer : " ;
    cin >> amount;
    if(amount == -1)
        return;

    Accounts_DataBase.transfer(acc,payee_acc,amount);
}

void Employee_BST :: withdraw(int withdraw_slip_no, Accounts_BST& Accounts_DataBase)
{
    while( !(withdraw_slip_no<100000 && withdraw_slip_no > 9999 && withdraw_slip_no % 331 == 0)){
        cout << "\nInvalide deposit slip" << endl;
        cout << "Try again..." << endl;
        cout << "\nEnter withdraw slip number : " << endl;
        cin >> withdraw_slip_no;
        if(withdraw_slip_no == -1)
            return;
    }
    cout << "\nwithdraw slip number " << withdraw_slip_no << " verified." << endl;
    Account* acc = Accounts_DataBase.get_account();
    if(!acc)
        return;

    int amount=0;
    cout << "\nEnter the amount that customer want to withdraw : " ;
    cin >> amount;
    if(amount == -1)
        return;

    Accounts_DataBase.withdraw(acc,amount);
}

void Employee_BST :: deposit (int deposit_slip_no, Accounts_BST& Accounts_DataBase)
{
    while( !(deposit_slip_no<100000 && deposit_slip_no > 9999 && deposit_slip_no % 333 == 0)){
        cout << "\nInvalide deposit slip" << endl;
        cout << "Try again..." << endl;
        cout << "\nEnter deposit slip number : " << endl;
        cin >> deposit_slip_no;
        if(deposit_slip_no == -1)
            return;
    }
    cout << "\nDeposit slip number " << deposit_slip_no << " verified." << endl;
    Account* acc = Accounts_DataBase.get_account();
    if(!acc)
        return;

    int amount=0;
    cout << "\nEnter the amount that customer want to deposite : " ;
    cin >> amount;
    if(amount == -1)
        return;

    Accounts_DataBase.deposit(acc,amount);
}