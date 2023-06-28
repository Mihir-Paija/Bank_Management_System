// #pragma once

void customer(){
    int opt;
    cout << endl;
    cout << "*****Welcome to Customer Interface*****" << endl << endl;
    int acc;
    cout << "Enter Your account number : ";
    cin >> acc;
    //check account number;
    //print .. hello "mihir";
    cout << "Choose One of the following services" << endl;
    cout << "1 : see account details " << endl;
    cout << "2 : deposite money" << endl;
    cout << "3 : withdraw money" << endl;
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
