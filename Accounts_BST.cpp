
#include <bits/stdc++.h>
using namespace std;

#include "Accounts_BST.h"

Accounts_BST ::Accounts_BST()
{
    this->root = NULL;
};

void Accounts_BST :: load_accounts_server(void)
{
    // cout << "loading" << endl;
    ifstream read;
    read.open("Accounts_Server.txt");

    string name = "";
    int accountno = 0;
    int password = 0;
    int balace = 0;

    while (!read.eof())
    {
        getline(read, name);
        read >> accountno;
        read >> password;
        read >> balace;
        read.ignore();
        // getline(read,name);
        // cout << "name" << name << endl;
        if (name != "" && accountno != 0 && password != 0 && balace >= 500)
        {
            Account *acc = new Account(name, accountno, password, balace);
            if (!root)
            {
                // cout << "root" << endl;
                root = acc;
            }
            else
            {
                // cout << "not root" << endl;
                Account *curr = root;
                while (1)
                {
                    if (accountno < curr->account_number)
                    {
                        if (!curr->left)
                        {
                            curr->left = acc;
                            break;
                        }
                        curr = curr->left;
                    }
                    else if (accountno > curr->account_number)
                    {
                        if (curr->right == nullptr)
                        {
                            curr->right = acc;
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

void Accounts_BST ::update_accounts_server(Account *curr,int Root)
{
    if (Root == 0)
    {
        Root++;
        remove("Accounts_Server.txt");
    }
    
    ofstream write;
    write.open("Accounts_Server.txt", ios::app);

    if (curr)
    {
        write << curr->name << endl;
        write << curr->account_number << endl;
        write << curr->password << endl;
        write << curr->balance << endl;
        update_accounts_server(curr->left,Root);
        update_accounts_server(curr->right,Root);
    }
    write.close();
}

Account *Accounts_BST ::search(int accountno)
{
    if (!root)
        return nullptr;

    Account *curr = root;
    while (curr)
    {
        if (curr->account_number == accountno)
            return curr;
        else if (accountno < curr->account_number)
            curr = curr->left;
        else if (accountno > curr->account_number)
            curr = curr->right;
    }
    return nullptr;
}

Account* Accounts_BST :: get_account(void )
{
    Account* temp=nullptr;
    int accountno=0;
    while(1)
    {
        cout << "\nEnter account number (or press -1 to exit) : ";
        cin >> accountno;
        if(accountno == -1){
            return nullptr;
        }
        temp = this->search(accountno);
        if(temp == nullptr){
            cout << "\n!! Bank Account not found !!" << endl;
            cout <<"Try Again..." << endl;
        }
        else
            return temp;
    }
}

void Accounts_BST ::add_Account(string name, int password, int balance)
{
    int accountno = 0;
    do
    {
        accountno = rand() % 1000000;

    } while (search(accountno) != nullptr);

    ofstream write;
    write.open("Accounts_Server.txt",ios::app);
    write << name << endl;
    write << accountno << endl;
    write << password << endl;
    write << balance << endl;
    write.close();

    Account *new_acc = new Account(name, accountno, password, balance);
    if (!root)
    {
        root = new_acc;
    }
    else
    {
        Account *curr = root;
        while (1)
        {
            if (accountno < curr->account_number)
            {
                if (!curr->left)
                {
                    curr->left = new_acc;
                    break;
                }
                curr = curr->left;
            }
            else if (accountno > curr->account_number)
            {
                if (!curr->right)
                {
                    curr->right = new_acc;
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
    cout << "Account successfully created..." << endl;
    cout << "your account number is : " << accountno <<endl;
}

void Accounts_BST ::delete_Account(int accountno, int password)
{
}

void Accounts_BST ::edit_account(int accountno, int password)
{
    Account *acc = search(accountno);
    string new_name = "";
    cout << "Enter New Name : " << endl;
    cin >> new_name;
    acc->name = new_name;
    cout << "name changed successfully" << endl;
    update_accounts_server(root,0);
}

void Accounts_BST ::transfer(Account *acc, Account *payee_acc, int amount)
{
    if (acc && payee_acc)
    {
        if (acc->balance - amount > 500)
        {
            acc->balance -= amount;
            payee_acc->balance += amount;
        }
        else if (acc->balance < amount)
            cout << "Insufficient Balance" << endl;
        else
            cout << "!! " << endl;
    }
    update_accounts_server(root,0);
}

void Accounts_BST ::withdraw(Account *acc, int amount)
{
    if (acc)
    {
        if (acc->balance - amount > 500)
        {
            acc->balance -= amount;
        }
        else if (acc->balance < amount)
            cout << "Insufficient Balance" << endl;
        else
            cout << "!! " << endl;
    }
    update_accounts_server(root,0);
}

void Accounts_BST ::deposit(Account *acc, int amount)
{
    if (acc)
    {
        acc->balance += amount;
    }
    update_accounts_server(root,0);
}