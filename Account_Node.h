#pragma once
#include <bits/stdc++.h>
using namespace std;
class Account
{
public:
	string name;
	int account_number;
	int password;
	int balance;
	Account * left;
	Account * right;

	Account();
	Account(string, int, int, int);
	bool account_password_verify(void);
};
