void admin()
{
    int opt;
    cout << endl;
    cout << "\n***** Welcome to Admin Interface *****" << endl
         << endl;
    int acc;

    string password = "";
    cout << "\nEnter Password : ";
    cin >> password;
    if (password != "nothing")
        return;

    do
    {
        cout << "\nChoose One of the following services" << endl;
        cout << "1 : Add new Bank Account" << endl;
        cout << "2 : Delete Bank Account" << endl;
        cout << "3 : Edit Bank Account Details" << endl;
        cout << "4 : Add New Employee" << endl;
        cout << "5 : Delete Employee" << endl;
        cout << "6 : Edit Employee Details" << endl;
        cout << "7 : Print Information of all Bank Accounts" << endl;
        cout << "8 : Print Information of all Employees" << endl;
        cout << "Or press \'-1\' to go back" << endl;
        cout << "\nSelect your option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            string name;
            cout << "\nEnter customer's Name : ";
            cin >> name;
            if (stoi(name) == -1)
                break;

            int password;
            cout << "Enter customer's Password : ";
            cin >> password;
            if (password == -1)
                break;

            int balance;
            do
            {
                cout << "Enter Intial Balance for new account (minimum 500) : ";
                cin >> balance;
            } while (balance < 500 && balance != -1);
            if (balance == -1)
                break;

            Accounts_DataBase.add_Account(name, password, balance);
            break;
        }

        case 2:
        {
            Accounts_DataBase.Delete();
            break;
        }

        case 3:
        {
            Account* acc = Accounts_DataBase.get_account();
            if(!acc)
                break;
            
            if(acc->account_password_verify())
                Accounts_DataBase.edit_account(acc);
            
            break;
        }

        case 4:
        {
            string name;
            cout << "\nEnter employee's Name : ";
            cin >> name;
            if (name == "-1")
                break;

            int password;
            cout << "Enter employee's Password : ";
            cin >> password;
            if (password == -1)
                break;

            int age;
            do
            {
                cout << "Enter employee's age (minimum 20) : ";
                cin >> age;
            } while (age < 20 && age != -1);
            if (age == -1)
                break;

            Employees_DataBase.add_Employee(name, age, password);
            break;
        }

        case 5:
        {
            Employees_DataBase.Delete();
            break;
        }

        case 6:
        {
            Employee* emp = Employees_DataBase.get_employee();
            if (!emp)
                break;

            if(emp->employee_password_verify())
                Employees_DataBase.edit_profile(emp);
            
            break;
        }

        case 7:
        {
            Accounts_DataBase.Display_Accounts(Accounts_DataBase.root);
            break;
        }

        case 8:
        {
            Employees_DataBase.Display_employees(Employees_DataBase.root);
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
