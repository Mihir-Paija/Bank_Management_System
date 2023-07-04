
# include "Account_Node.h"

Account :: Account()
{
	left = nullptr;
	right = nullptr;
	name = "";
    // adress = "";
    account_number = 0;
    password = 0;
    balance = 0;
}

Account :: Account(string name, int accountno, int password, int balance)
{
	left = nullptr;
	right = nullptr;
	this->name = name;
	this->account_number = accountno;
	// this->adress = adress;
	this->balance = balance;
	this->password = password;
}
bool Account :: account_password_verify(void)
{
	int password=0;
    for (int i = 1; i <= 3; i++)
    {
        cout << "\nEnter password ("<<i<<"/3" <<" chance) or press -1 to go back to customer interface: ";
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
