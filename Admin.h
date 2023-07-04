void admin()
{
    int opt;
    cout << endl;
    cout << "*****Welcome to Admin Interface*****" << endl
         << endl;
    int acc;

    // check account number;
    // print .. hello "mihir";

    do
    {
        cout << "Choose One of the following services" << endl;
        cout << "1 : Create New Account" << endl;
        cout << "2 : Delete Account" << endl;
        cout << "3 : Edit Account Details" << endl;
        cout << "4 : Create New Employee" << endl;
        cout << "5 : Delete Employee" << endl;
        cout << "6 : Edit Employee Details" << endl;
        cout << "Or press \'-1\' for exit" << endl;
        cout << "Select your option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            string name;
            cout << "Enter your Name : ";
            cin >> name;
            int password;
            cout << "Enter your Password : ";
            cin >> password;
            int balance;
            do
            {
                cout << "Enter your Intial Balance (minimum 500) : ";
                cin >> balance;
            } while (balance < 500);
            Accounts_DataBase.add_Account(name,password,balance);
            break;
        }

        case 2:

            break;

        case 3:{
            int accountno;
            cout << "Enter your account number : ";
            cin >> accountno;
            int password;
            cout << "Enter your Password : ";
            cin >> password;
            Accounts_DataBase.edit_account(accountno,password);
        }

        case 4:
        {
            string name;
            cout << "Enter your Name : ";
            cin >> name;
            int password;
            cout << "Enter your Password : ";
            cin >> password;
            int age;
            do
            {
                cout << "Enter your Intial Balance (minimum 20) : ";
                cin >> age;
            } while (age < 20);
            Employees_DataBase.add_Employee(name, age, password);
            break;
        }

        case 5:

            break;

        case 6:{
            int employeeno;
            cout << "Enter your employee number : ";
            cin >> employeeno;
            int password;
            cout << "Enter your Password : ";
            cin >> password;
            /* re check............................*/
            Accounts_DataBase.edit_account(employeeno,password);
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
