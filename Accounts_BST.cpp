
#include <bits/stdc++.h>
using namespace std;

#include "Accounts_BST.h"

Accounts_BST ::Accounts_BST()
{
    this->root = NULL;
};

void Accounts_BST ::Display_Accounts(Account *curr)
{
    if (!curr)
        return;

    cout << "\nBank Account number : " << curr->account_number << endl;
    cout << "Bank Account holder Name : " << curr->name << endl;
    cout << "Bank Account Balance : " << curr->balance << endl;

    Display_Accounts(curr->left);
    Display_Accounts(curr->right);
}

void Accounts_BST ::load_accounts_server(void)
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

        if (name != "" && accountno != 0 && password != 0 && balace >= 500)
        {
            Account *acc = new Account(name, accountno, password, balace);
            if (!root)
            {
                root = acc;
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

void Accounts_BST ::update_accounts_server(Account *curr, int Root)
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
        update_accounts_server(curr->left, Root);
        update_accounts_server(curr->right, Root);
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

Account *Accounts_BST ::get_account(void)
{
    Account *temp = nullptr;
    int accountno = 0;
    while (1)
    {
        cout << "\nEnter account number : ";
        cin >> accountno;
        if (accountno == -1)
        {
            return nullptr;
        }
        temp = this->search(accountno);
        if (temp == nullptr)
        {
            cout << "\n!! Bank Account not found !!" << endl;
            cout << "Try Again..." << endl;
        }
        else
            return temp;
    }
}

Account *Accounts_BST ::get_successor(Account *acc)
{
    if (acc->right)
    {
        acc = acc->right;
        while (acc->left)
            acc = acc->left;

        return acc;
    }
    return nullptr;
}

void Accounts_BST ::copy_data(Account *x, Account *y)
{
    x->name = y->name;
    x->account_number = y->account_number;
    x->password = y->password;
    x->balance = y->balance;
}

void Accounts_BST ::add_Account(string name, int password, int balance)
{
    int accountno = 0;
    do
    {
        accountno = (rand() + 1100000) % 1000000;

    } while (!(search(accountno) == nullptr && accountno < 1000000 && accountno > 99999));

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
        }
    }

    ofstream write;
    write.open("Accounts_Server.txt", ios::app);
    write << name << endl;
    write << accountno << endl;
    write << password << endl;
    write << balance << endl;
    write.close();

    // update_accounts_server(root,0);

    cout << "\nAccount successfully created..." << endl;
    cout << "your account number is : " << accountno << endl;
}

void Accounts_BST ::delete_Account(Account *&curr, int accountno)
{

    if (curr->account_number == accountno)
    {
        if (!curr->left && !curr->right)
        {
            delete (curr);
            curr = NULL;
            return;
        }
        else if (!curr->left)
        {
            Account *temp = curr;
            curr = curr->right;
            delete (temp);
            temp = nullptr;
            return;
        }
        else if (!curr->right)
        {
            Account *temp = curr;
            curr = curr->left;
            delete (temp);
            temp = nullptr;
            return;
        }
        else
        {
            Account *succ = get_successor(curr);
            copy_data(curr, succ);
            delete_Account(curr->right, succ->account_number);
            return;
        }
    }
    else if (accountno < curr->account_number)
        delete_Account(curr->left, accountno);
    else if (accountno > curr->account_number)
        delete_Account(curr->right, accountno);
}

void Accounts_BST ::Delete()
{
    Account *acc = get_account();
    if (!acc)
        return;

    int accno = acc->account_number;
    delete_Account(root, acc->account_number);

    update_accounts_server(root, 0);

    cout << "\nBank Account of Account number " << accno << " successfully deleted." << endl;
}

void Accounts_BST ::edit_account(Account *acc)
{
    string new_name = "";
    cout << "\n# # Edit your name # #" << endl;
    cout << "\nEnter New Name : ";
    cin >> new_name;
    if (new_name == "-1")
        return;

    acc->name = new_name;
    update_accounts_server(root, 0);
    cout << "\nName changed successfully" << endl;
}

void Accounts_BST ::withdraw(Account *acc, int amount)
{
    if (acc)
    {
        if (acc->balance - amount > 500)
        {
            acc->balance -= amount;
            update_accounts_server(root, 0);
            cout << "\n"
                 << amount << " successfully withdraw from " << acc->name << "\'s Account " << endl;
            cout << "Current Balance of Bank Account " << acc->account_number << " is " << acc->balance << endl;
        }
        else if (acc->balance < amount)
            cout << "\nInsufficient Balance" << endl;
        else
        {
            cout << "\nTranscation can not be done" << endl;
            cout << "This will violate minimum balance policy of the Bank" << endl;
        }
    }
}

void Accounts_BST ::deposit(Account *acc, int amount)
{
    if (acc)
    {
        acc->balance += amount;
        update_accounts_server(root, 0);

        cout << "\n"
             << amount << " successfully deposit to " << acc->name << "\'s Account " << endl;
        cout << "Current Balance of Bank Account " << acc->account_number << " is " << acc->balance << endl;
    }
}

void Accounts_BST ::transfer(Account *acc, Account *payee_acc, int amount)
{
    if (acc && payee_acc)
    {
        if (acc->balance - amount > 500)
        {
            acc->balance -= amount;
            payee_acc->balance += amount;
            update_accounts_server(root, 0);

            cout << "\n"
                 << amount << " successfully transfer from " << acc->name << "\'s Account to " << payee_acc->name << "\'s Account" << endl;
            cout << "Current Balance of Bank Account " << acc->account_number << " is " << acc->balance << endl;
        }
    }
    else if (acc->balance < amount)
        cout << "\nInsufficient Balance" << endl;
    else
    {
        cout << "\nTranscation can not be done" << endl;
        cout << "This will violate minimum balance policy of the Bank" << endl;
    }
}
