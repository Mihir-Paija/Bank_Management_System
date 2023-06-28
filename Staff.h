void staff(){
    int opt;
    cout << endl;
    cout << "*****Welcome to Staff Interface*****" << endl << endl;
    int Emp;
    cout << "Enter Your Employee number : ";
    cin >> Emp;

    //check Emp number;

    int pass;
    cout << "Enter Your Password : ";
    cin >> pass;
    //check pass;
    
    //print .. hello "mihir";
    cout << "Choose One of the following services" << endl;
    cout << "1 : See account details " << endl;
    cout << "2 : Deposite money" << endl;
    cout << "3 : Withdraw money" << endl;
    cout << "4 : Transfer money" << endl;
    cout << "-1 : exit" << endl;
    do
    {
        cout << "Select your option : ";
        cin >> opt;
        switch (opt)
        {
        case 1:
 
            break;

        case 2:
            
            break;

        case 3:
            
            break;

        case 4:

            break;

        case -1:
            /* code */
            break;    

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    } while (opt != -1);

}
