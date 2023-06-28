void admin(){
    int opt;
    cout << endl;
    cout << "*****Welcome to Admin Interface*****" << endl << endl;
    int acc;
    
    
    //check account number;
    //print .. hello "mihir";
    cout << "Choose One of the following services" << endl;
    cout << "1 : Create New Account" << endl;
    cout << "2 : Delete Account" << endl;
    cout << "3 : Edit Account Details" << endl;
    cout << "4 : transfer money" << endl;
    cout << "Or press \'-1\' for exit" << endl;
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
