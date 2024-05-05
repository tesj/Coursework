#include <iostream>

using namespace std;

int main() //start
{
    //display my information
    cout << "\t\t\t******************************" << endl;
    cout << "\t\t\t*       Thomas Speich        *" << endl;
    cout << "\t\t\t*        CPT-168-A02H        *" << endl;
    cout << "\t\t\t*           Test-3           *" << endl;
    cout << "\t\t\t******************************" << endl << endl;

    cout << "\t\t<<<<<<<<<<<<<<< Hello >>>>>>>>>>>>>>>" << endl << endl;

    //declare variables
    string horoscopes[7] = { "This week is going to be a lucky week for you, buy lotto", "You will barely escape an accident this week",
        "You are going to have a week full of surprises", "You will receive a large amount of money this week",
        "You will get promoted at your job this week", "You will get a phone call from an old friend this week", "You may have some type of car problem this week" };
    string days[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    string carolinaNums[7] = { "8,9,23,29,50", "7,19,21,38,51", "6,25,28,30,49", "22,27,33,37,42", "16,18,28,34,38", "10,3,6,13,33", "7,21,25,28,37" };
    int userChoice = 0;

    //priming read
    cout << "\tPlease enter a number from 1 - 7 or 99 to end: ";
    cin >> userChoice;

    //pre-test loop
    while (userChoice != 99)
    {
        //decision
        if (userChoice >= 1 && userChoice <= 7) 
        {
            //output
            cout << endl << "\tYour " << days[userChoice - 1] << " Horoscope: " << horoscopes[userChoice - 1] << endl;
            cout << "\tLucky Carolina5 numbers: " << carolinaNums[userChoice - 1] << endl << endl;
        } 
        else
        {
            //error output
            cout << "\tInvalid number was entered" << endl << endl;
        }

        //update read
        cout << "\tPlease enter a number from 1 - 7 or 99 to end: ";
        cin >> userChoice;
    }

    for (int index = 0; index < 7; index++)
    {
        cout << endl << "\tDay #" << index + 1 << ": " << days[index] << endl;
        cout << endl << "\tHoroscope #" << index + 1 << ": " << horoscopes[index] << endl;
        cout << endl << "\tLucky Carolina5 #" << index + 1 << ": " << carolinaNums[index] << endl << endl;
    }
    //output
    cout << endl << "\t\tT H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0; //stop
}
