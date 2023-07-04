#pragma once
#include <bits/stdc++.h>
using namespace std;
class Account
{
public:
	Account * left;
	Account * right;
	string name;
	// string adress;
	int account_number;
	int password;
	int balance;

	Account();
	Account(string, int, int, int);
	bool account_password_verify(void);
};
