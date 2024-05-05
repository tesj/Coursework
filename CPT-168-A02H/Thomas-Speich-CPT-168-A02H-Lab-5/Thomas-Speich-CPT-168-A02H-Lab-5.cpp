#include <iostream>
#include <iomanip>

using namespace std;

int main() //Start
{
    //Display my information
    cout << "\t\t***********************************" << endl;
    cout << "\t\t*          Thomas Speich          *" << endl;
    cout << "\t\t*     Calculate the gross pay     *" << endl;
    cout << "\t\t*          CPT-168-A02H           *" << endl;
    cout << "\t\t***********************************" << endl << endl;

    //Declare Variables
    float grossPay = 0.0;
    float bonus = 0.0;
    int yearsWorked = 0.0;
    //Input/Output
    cout << "Please enter your gross pay per year: ";
    cin >> grossPay;
    
    cout << "Please enter number of years you worked: ";
    cin >> yearsWorked;

    //Process
    if (yearsWorked > 5) 
    {
        bonus = grossPay * 0.02;
    }
    else if (yearsWorked > 0) 
    {
        bonus = grossPay * 0.01;
    }
    else 
    {
        //Output
        cout << "Invalid number of years entered." << endl << endl;
        cout << "T H A N K  Y O U !" << endl;
        system("pause");
        return 0; //stop
    } 
    
    //Output
    cout << "Your bonus is: $" << fixed << setprecision(2) << bonus << endl << endl;
    cout << "T H A N K  Y O U !" << endl;
    system("pause");
    return 0; //Stop
}