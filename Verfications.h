#pragma once
#include <bits/stdc++.h>
using namespace std;

// bool account_password_verify(Account* acc)
// {
//     int password=0;
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "\nEnter password ("<<i<<"/3" <<" chance) or press -1 to go back to customer interface: ";
//         cin >> password;
//         if (acc->password == password)
//         {
//             return 1;
//         }
//         else if(password == -1){
//             return 0;
//         }
//         cout << "\n!! Wrong Pasword !!" << endl;
//     }
//     cout << "\nsorry!! you lost your 3 chance" <<endl;
//     return 0;
// }

// Account* get_account(void ){
//     Account* temp=nullptr;
//     int accountno=0;
//     while(1)
//     {
//         cout << "\nEnter account number (or press -1 to exit) : ";
//         cin >> accountno;
//         if(accountno == -1){
//             return nullptr;
//         }
//         temp = Accounts_DataBase.search(accountno);
//         if(temp == nullptr){
//             cout << "\n!! Bank Account not found !!" << endl;
//             cout <<"Try Again..." << endl;
//         }
//         else
//             return temp;
//     } 
// }

// bool employee_password_verify(Employee* emp)
// {
//     int password=0;
//     for (int i = 1; i <= 3; i++)
//     {
//         cout << "\nEnter password ("<<i<<"/3" <<" chance) or press -1 to go back to customer interface: ";
//         cin >> password;
//         if (emp->password == password)
//         {
//             return 1;
//         }
//         else if(password == -1){
//             return 0;
//         }
//         cout << "\n!! Wrong Pasword !!" << endl;
//     }
//     cout << "\nsorry!! you lost your 3 chance" <<endl;
//     return 0;
// }

// Employee* get_employee(void ){
//     Employee* temp=nullptr;
//     int employeeno=0;
//     while(1)
//     {
//         cout << "\nEnter employee number (or press -1 to exit) : ";
//         cin >> employeeno;
//         if(employeeno == -1){
//             return nullptr;
//         }
//         temp = Employees_DataBase.search(employeeno);
//         if(temp == nullptr){
//             cout << "\n!! Employee not found !!" << endl;
//             cout <<"Try Again..." << endl;
//         }
//         else
//             return temp;
//     } 
// }