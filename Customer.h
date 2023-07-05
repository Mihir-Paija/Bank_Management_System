// #pragma once

void customer()
{

    cout << endl;
    cout << "\n***** Welcome to Customer Interface *****" << endl
         << endl;

    cout << "\n # # Enter Your Account details # #" << endl;
    Account *acc = Accounts_DataBase.get_account();
    if (!acc)
        return;

    cout << "\n Hello! " << acc->name << ";" << endl;

    int opt;
    do
    {
        cout << "\nChoose One of the following services" << endl;
        cout << "1 : see account details " << endl;
        cout << "2 : deposit money" << endl;
        cout << "3 : withdraw money" << endl;
        cout << "4 : transfer money" << endl;
         cout << "Or press \'-1\' to go back" << endl;
        cout << "\nSelect your option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {

            if (acc->account_password_verify())
            {
                cout << "\nAccount holder's name : " << acc->name << endl;
                cout << "Account Balance : " << acc->balance << endl;
            }
            break;
        }

        case 2:
        {
            int amount = 0;
            cout << "\nEnter the amount you want to deposit : ";
            cin >> amount;
            if (amount == -1)
                break;

            if (acc->account_password_verify())
                Accounts_DataBase.deposit(acc, amount);

            break;
        }

        case 3:
        {
            int amount = 0;
            cout << "\nEnter the amount you want to withdraw : ";
            cin >> amount;
            if (amount == -1)
                break;

            if (acc->account_password_verify())
                Accounts_DataBase.withdraw(acc, amount);

            break;
        }

        case 4:
        {
            cout << "\n # # Enter Payee's Account details # #" << endl;
            Account *payee_acc = Accounts_DataBase.get_account();
            if (!payee_acc)
                break;

            int amount = 0;
            cout << "\nEnter the amount you want to transfer : ";
            cin >> amount;
            if (amount == -1)
                break;

            if (acc->account_password_verify())
                Accounts_DataBase.transfer(acc, payee_acc, amount);

            break;
        }

        case -1:
            /* code */
            break;

        default:
            cout << "\nInvalid Option" << endl;
            break;
        }
    } while (opt != -1);
}
