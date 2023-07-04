void staff()
{
    int opt;
    cout << endl;
    cout << "*****Welcome to Staff Interface*****" << endl
         << endl;

    Employee *emp = Employees_DataBase.get_employee();
    if(!emp)
        return;
    
    if (emp->employee_password_verify())
    {
        cout << "Hello " << emp->name << endl;
        int accountno=0;
        do
        {
            cout << "\nChoose One of the following services" << endl;
            cout << "1 : See account details " << endl;
            cout << "2 : Deposite money" << endl;
            cout << "3 : Withdraw money" << endl;
            cout << "4 : Transfer money" << endl;
            cout << "5 : See your profile" << endl;
            cout << "-1 : exit" << endl;
            cout << "\nSelect your option : ";
            cin >> opt;
            switch (opt)
            {
            case 1:{
                cout << "# # Enter account details # #";
                Account *acc = Accounts_DataBase.get_account();
                if(!acc)
                    break;
                cout << "Account holder's name : " << acc -> name << endl;
                cout << "Account Balance : " << acc -> balance << endl;
                break;
            }


            case 2:{
                int payin_slip_no=0;
                cout << "Enter pay in slip number : ";
                cin >> payin_slip_no;
                Employees_DataBase.deposit(payin_slip_no,Accounts_DataBase);
                break;
            }


            case 3:{
                int withdraw_slip_no=0;
                cout << "Enter withdraw slip number : ";
                cin >> withdraw_slip_no;
                Employees_DataBase.withdraw(withdraw_slip_no,Accounts_DataBase);
                break;
            }


            case 4:{
                int cheque_no=0;
                cout << "Enter cheque number : ";
                cin >> cheque_no;
                Employees_DataBase.transfer(cheque_no,Accounts_DataBase);
                break;
            }

            case 5:{
                cout << " Staff Name : " << emp -> name << endl;
                cout << "Age : " << emp -> age << endl;
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
}
