#include <iostream>
#include <iomanip>

using namespace std;

int main() //Start
{
    //Display my information
    cout << "\t\t***********************************" << endl;
    cout << "\t\t*          Thomas Speich          *" << endl;
    cout << "\t\t*         Second Program          *" << endl;
    cout << "\t\t*          CPT-168-A02H           *" << endl;
    cout << "\t\t***********************************" << endl << endl;

    //Declare Variables
    float grossPay = 0.0;
    float bonus = 0.0;
    int yearsWorked = 0;
    //Input/Output
    cout << "Enter number of years worked, or (0, 99 or higher, negative number) to exit: ";
    cin >> yearsWorked;

    //Loop
    while (yearsWorked > 0 && yearsWorked < 99)
    {
            //Input/Output
            cout << "Please enter your gross pay per year: ";
            cin >> grossPay;

            //Decision/Process
            if (yearsWorked > 5)
            {
                bonus = grossPay * 0.02;
            }
            else
            {
                bonus = grossPay * 0.01;
            }

            //Output
            cout << "Your bonus is: $" << fixed << setprecision(2) << bonus << endl << endl;

            //Input/Output
            cout << "Enter number of years worked, or (0, 99 or higher, negative number) to exit: ";
            cin >> yearsWorked;
    }
    //Output
    cout << endl << "T H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0; //Stop
}

