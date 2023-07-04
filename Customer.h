// #pragma once

void customer()
{

    cout << endl;
    cout << "***** Welcome to Customer Interface *****" << endl
         << endl;
            
    cout << "\n # # Enter Your Account details # #" << endl;
    Account *acc = Accounts_DataBase.get_account();
    if(!acc)
        return;
    // do
    // {
    //     cout << "Enter Your account number : ";
    //     cin >> accountno;
    //     acc = Accounts_DataBase.search(accountno);
    //     if(acc == nullptr)
    //         cout << "null" << endl;
    // } while (!acc);

    cout << "\n Hello " << acc->name << endl;

    int opt;
    do
    {
        cout << "Choose One of the following services" << endl;
        cout << "1 : see account details " << endl;
        cout << "2 : deposit money" << endl;
        cout << "3 : withdraw money" << endl;
        cout << "4 : transfer money" << endl;
        cout << "Or press \'-1\' for exit" << endl;
        cout << "Select your option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            // int password = 0;
            int flag = acc->account_password_verify();
            // for (int i = 0; i < 3; i++)
            // {
            //     cout << "Enter password : ";
            //     cin >> password;
            //     if (acc->password == password)
            //     {
            //         flag = 1;
            //         break;
            //     }
            // }

            if (flag){
                cout << "\nAccount holder's name : " << acc -> name << endl;
                cout << "Account Balance : " << acc -> balance << endl;
            }
            // else
                // cout << "sorry" << endl;
            break;
        }

        case 2:
        {
            int amount = 0;
            cout << "Enter the amount you want to deposit : ";
            cin >> amount;
            if (acc->account_password_verify())
                Accounts_DataBase.deposit(acc, amount);
            // else
            //     cout << "sorry" << endl;
            break;
        }

        case 3:
        {
            int amount = 0;
            cout << "Enter the amount you want to deposite : ";
            cin >> amount;
            if (acc->account_password_verify())
                Accounts_DataBase.withdraw(acc, amount);
            // else
            //     cout << "sorry" << endl;
            break;
        }

        case 4:
        {
            int amount = 0;
            int payee = 0;
            cout << "\n # # Enter Payee's Account details # #" << endl;
            Account *payee_acc = Accounts_DataBase.get_account();
            // do
            // {
            //     cout << "Enter the account number of payee : ";
            //     cin >> payee;
            //     if (payee == -1)
            //         break;
            //     payee_acc = Accounts_DataBase.search(payee);
            // } while (!payee_acc);
            // if (payee == -1)
            //     break;
            if(!payee_acc)
                break;

            cout << "Enter the amount you want to transfer : ";
            cin >> amount;
            if(amount == -1)
                break;

            if (acc->account_password_verify())
                Accounts_DataBase.transfer(acc, payee_acc, amount);
            // else
            //     cout << "sorry" << endl;
            break;
        }

        case -1:
            /* code */
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (opt != -1);
}
