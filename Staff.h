void staff()
{
    int opt;
    cout << endl;
    cout << "\n***** Welcome to Staff Interface *****" << endl
         << endl;

    Employee *emp = Employees_DataBase.get_employee();
    if(!emp)
        return;
    
    if (emp->employee_password_verify())
    {
        cout << "\nHello " << emp->name << endl;
        int accountno=0;
        do
        {
            cout << "\nChoose One of the following services" << endl;
            cout << "1 : See account details " << endl;
            cout << "2 : Deposite money" << endl;
            cout << "3 : Withdraw money" << endl;
            cout << "4 : Transfer money" << endl;
            cout << "5 : See your profile" << endl;
            cout << "Or press \'-1\' to go back" << endl;
            cout << "\nSelect your option : ";
            cin >> opt;
            switch (opt)
            {
            case 1:{
                cout << "\n# # Enter account details # #";
                Account *acc = Accounts_DataBase.get_account();
                if(!acc)
                    break;

                cout << "\nAccount holder's name : " << acc -> name << endl;
                cout << "Account Balance : " << acc -> balance << endl;
                break;
            }

            case 2:{
                int payin_slip_no=0;
                cout << "\nEnter pay in slip number : ";
                cin >> payin_slip_no;

                Employees_DataBase.deposit(payin_slip_no,Accounts_DataBase);
                break;
            }

            case 3:{
                int withdraw_slip_no=0;
                cout << "\nEnter withdraw slip number : ";
                cin >> withdraw_slip_no;
                
                Employees_DataBase.withdraw(withdraw_slip_no,Accounts_DataBase);
                break;
            }

            case 4:{
                int cheque_no=0;
                cout << "\nEnter cheque number : ";
                cin >> cheque_no;

                Employees_DataBase.transfer(cheque_no,Accounts_DataBase);
                break;
            }

            case 5:{
                cout << "\n# # Profile of Employee number : " << emp ->emplooye_number << endl;
                cout << "\nName : " << emp -> name << endl;
                cout << "Age : " << emp -> age << endl;
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
}
