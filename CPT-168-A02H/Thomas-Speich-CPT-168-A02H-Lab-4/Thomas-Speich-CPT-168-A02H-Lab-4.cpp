#include <iostream>

using namespace std;

int main() //Start
{
    //Display my information
    cout << "\t\t***********************************" << endl;
    cout << "\t\t*          Thomas Speich          *" << endl;
    cout << "\t\t*          CPT-168-A02H           *" << endl;
    cout << "\t\t* Calculate auto sales commission *" << endl;
    cout << "\t\t***********************************" << endl << endl;

    //Delcare Variables
    int carsSold = 0;
    int commission = 0;

    //Input/Output
    cout << "Please enter number of cars you sold: ";
    cin >> carsSold;

    //Process 
    if (carsSold >= 0) {
        commission = 500 * carsSold;
    }
    else {
        cout << "Invalid number of cars entered." << endl;
        system("pause");
        return 0;
    }

    //Output
    cout << "Your commission is: $" << commission << endl << endl;
    cout << "\tT H A N K  Y O U" << endl << endl;

    system("pause");
    return 0; //Stop
}