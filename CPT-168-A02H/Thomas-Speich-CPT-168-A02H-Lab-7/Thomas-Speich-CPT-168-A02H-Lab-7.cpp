#include <iostream>
#include <string>

using namespace std;

int main() //start
{
    //declare variables
    char continueInput = ' ';
    int baseNum = 0;

    /*
        While I was testing this with various inputs, I encountered an issue.
        If a non-number was entered when prompted for a number after the first iteration, the program would break.
        It would also break if a string was entered when prompted for a character.
        The reason why it broke, was that it would not accept any further inputs as cin was in a fail state, and would endlessly loop.
        However, I fixed this by checking if cin is in a fail state, and if it is, I clear the fail flag and the cin buffer.
        Then, I ask for another input, and repeat this process until a valid input is recieved.

        Solving the input issue was definitely a challenge, but it was fun.
    */

    //post-test loop
    do 
    {
        //clear console
        system("cls");

        //display my information
        cout << "\t\t***********************************" << endl;
        cout << "\t\t*          Thomas Speich          *" << endl;
        cout << "\t\t*          CPT-168-A02H           *" << endl;
        cout << "\t\t*       Square-Cube program       *" << endl;
        cout << "\t\t***********************************" << endl << endl;

        //input/output
        cout << "Please enter a number to Square, Cube, and raise to the 4th power: ";
        cin >> baseNum;

        //clears the buffer, so that if the input is "10n", the 'n' is not pushed into continueInput at line 69
        cin.ignore(256, '\n');

        //loop until input is valid (a number)
        while (!cin) 
        {
            cin.clear(); //clears the fail flag
            cin.ignore(256, '\n'); //clears 256 characters, or until a newline character is found, from the buffer
            cout << "Invalid input." << endl << "Please enter another number: ";
            cin >> baseNum;
        }   

        //output
        cout << "\n\tNumber  Square  Cube    4th Power" << endl;
        cout <<   "\t------  ------  ------  ---------" << endl;

        //loop
        for (int row = 0; row < 10; row++)
        {
            for (int column = 0; column < 4; column++)
            {
                cout << "\t" << pow(baseNum, column + 1);
            }
            cout << endl;
            baseNum += 5;
        }

        //input/output (update read)
        cout << endl << "Would you like to continue (Y or N)? ";
        cin >> continueInput;

        //loop until input for the update read is valid (works with string input beginning with 'Y' or 'N')
        while (!cin || toupper(continueInput) != 'Y' && toupper(continueInput) != 'N')
        {
            cin.clear(); //clears the fail flag
            cin.ignore(256, '\n'); //clears the buffer
            cout << "Invalid input." << endl << "Please enter Y or N: ";
            cin >> continueInput;
        }

        //clears the buffer, so that if the input, for example, is "y157", it does not automatically push 157 into baseNum at line 38
        cin.ignore(256, '\n');

    } while (toupper(continueInput) == 'Y');

    //output
    cout << endl << "T H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0; //stop
}