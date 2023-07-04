#pragma once
#include "Account_Node.h"

class Accounts_BST
{
public:

    Account *root;

	Accounts_BST();

    void load_accounts_server();
    void update_accounts_server(Account* ,int );
    Account* search(int);
    Account* get_account(void );
    void add_Account(string, int, int);
    void delete_Account(int, int);
    void withdraw(Account*, int);
    void deposit(Account*, int);
    void edit_account(int, int);
    void transfer(Account*, Account*, int);
    // void transaction_history();
    // void findMax(BST_Node *);
    // void load_Server();
    // void update_server(BST_Node *);
    // BST_Node *search(BST_Node *, int);
    // void printoinfo(BST_Node *);
};