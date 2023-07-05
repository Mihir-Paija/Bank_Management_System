#pragma once
#include "Account_Node.h"

class Accounts_BST
{
public:

    Account *root;

	Accounts_BST();

    void Display_Accounts(Account*);

    void load_accounts_server();
    void update_accounts_server(Account* ,int );
    
    Account* search(int);
    Account* get_account(void );
    Account* get_successor(Account* );
    void copy_data(Account*,Account*);

    void add_Account(string, int, int);
    void delete_Account(Account*&,int);
    void Delete();
    void edit_account(Account* );

    void withdraw(Account*, int);
    void deposit(Account*, int);
    void transfer(Account*, Account*, int);
};