#include "Employee_Node.h"

Employee ::Employee()
{
    name = "";
    age = 0;
    emplooye_number = 0;
    password = 0;
    
    left = nullptr;
    right = nullptr;
}

Employee ::Employee(string name, int age, int employeeno, int password)
{
    this->name = name;
    this->age = age;
    this->emplooye_number = employeeno;
    this->password = password;
    
    left = nullptr;
    right = nullptr;
}

bool Employee :: employee_password_verify()
{
    int password=0;
    for (int i = 1; i <= 3; i++)
    {
        cout << "\nEnter password ("<<i<<"/3" <<" chance) : ";
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
