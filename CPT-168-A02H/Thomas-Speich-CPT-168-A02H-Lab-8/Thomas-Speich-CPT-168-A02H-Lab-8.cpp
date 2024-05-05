//I did not worry about implementing the cin fail flag fix like I did in the last lab
#include <iostream>

using namespace std;

int main() //start
{    
    //declare variables
    int actorChoice = 0;
    char continueInput = ' ';
    string actorNames[6] = { "Angelina Jolie", "Brad Pitt", "Margot Robbie", "George Clooney", "Jennifer Lopez" , "Jennifer Lawrence" };
    string actorPhones[6] = { "949-232-1124", "949-865-3492", "864-235-7569", "939-453-2288", "987-209-2132", "543-239-8745" };


    //post-test loop
    do 
    {
        //clear console
        system("CLS");

        //display my information
        cout << "\t\t******************************" << endl;
        cout << "\t\t*       Thomas Speich        *" << endl;
        cout << "\t\t*     Lab-8 Actor's info     *" << endl;
        cout << "\t\t*        CPT-168-A02H        *" << endl;
        cout << "\t\t******************************" << endl << endl;

        //input/output
        cout << "Please enter a number from 1 to 6 to display an actor's info: ";
        cin >> actorChoice;

        //decision/output
        if (actorChoice <= 6 && actorChoice >= 1)
        {
            cout << endl << "Your actor's name is: " << actorNames[actorChoice - 1] << endl;
            cout << "Phone: " << actorPhones[actorChoice - 1] << endl << endl;
        }
        else 
        {
            cout << "Invalid choice." << endl;
        }

        //update read
        cout << "Would you like to continue (Y or N)? ";
        cin >> continueInput;

        //loop until input is 'Y' or 'N'
        while (toupper(continueInput) != 'Y' && toupper(continueInput) != 'N')
        {
            cout << "Invalid choice. Please enter Y or N: ";
            cin >> continueInput;
        }

    } while (toupper(continueInput) == 'Y');

    //output
    cout << endl << "T H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0; //stop
}