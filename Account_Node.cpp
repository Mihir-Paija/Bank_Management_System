
# include "Account_Node.h"

Account :: Account()
{
	name = "";
    account_number = 0;
    password = 0;
    balance = 0;
	
	left = nullptr;
	right = nullptr;
}

Account :: Account(string name, int accountno, int password, int balance)
{
	this->name = name;
	this->account_number = accountno;
	this->balance = balance;
	this->password = password;
	
	left = nullptr;
	right = nullptr;
}
bool Account :: account_password_verify(void)
{
	int password=0;
    for (int i = 1; i <= 3; i++)
    {
        cout << "\nEnter password ("<<i<<"/3" <<" chance) : ";
        cin >> password;
        if (this->password == password)
        {
            return 1;
        }
        else if(password == -1){
            return 0;
        }
        cout << "\n!! Wrong Pasword !!" << endl;
    }
    cout << "\nsorry!! you lost your 3 chance" <<endl;
    return 0;
}
