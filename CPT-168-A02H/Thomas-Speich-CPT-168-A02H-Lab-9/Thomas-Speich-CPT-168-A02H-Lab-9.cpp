#include <iostream>
#include <string>

using namespace std;

//returns true if the string contains non-digits; uses the isdigit() function
bool ContainsNonDigits(string checkString); //definition on line 91

int main()
{

    //display my information
    cout << "\t\t******************************" << endl;
    cout << "\t\t*       Thomas Speich        *" << endl;
    cout << "\t\t*        CPT-168-A02H        *" << endl;
    cout << "\t\t*    String Manipulations    *" << endl;
    cout << "\t\t******************************" << endl;


    //declare variables
    string firstName = "";
    string lastName = "";
    string fullName = "";
    string reverseName = "";
    string phone = "";
    string social = "";
    char continueInput = ' ';

    //main loop
    do
    {
        //name I/O
        cout << endl << "Please enter your first name: ";
        getline(cin, firstName);
        cout << "Please enter your last name: ";
        getline(cin, lastName);

        //phone I/O
        do
        {
            cout << "Please enter 10 digit phone number (with no dashes or parentheses): ";
            getline(cin, phone);
        } while (phone.length() != 10 || ContainsNonDigits(phone));

        //SSN I/O
        do
        {
            cout << "Please enter 9 digit SSN (with no dashes): ";
            getline(cin, social);
        } while (social.length() != 9 || ContainsNonDigits(social));


        //combine first and last name, then reverse full name
        fullName = firstName + " " + lastName;
        reverseName = "";
        for (int index = 0; index < fullName.length(); index++)
        {
            reverseName += fullName[fullName.length() - 1 - index];
        }

        //format phone number
        phone.insert(0, "(");
        phone.insert(4, ")");
        phone.insert(8, "-");

        //format SSN
        social.insert(3, "-");
        social.insert(6, "-");

        //output
        cout << endl << "Your full name is: " << fullName << endl;
        if (fullName == "Harry Potter")
        {
            cout << endl << "Yer a wizard, Harry." << endl << endl;
        }
        cout << "Your reversed full name is: " << reverseName << endl;
        cout << "Your phone number is: " << phone << endl;
        cout << "Your SSN is: " << social << endl;


        //update read
        do
        {
            cout << endl << "Would you like to enter new information (Y or N)? ";
            cin >> continueInput;
        } while (toupper(continueInput) != 'Y' && toupper(continueInput) != 'N');
        cin.ignore();

    } while (toupper(continueInput) == 'Y');

    cout << "\n\t\tT H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0; //stop
}

//any suggestions on a better name for the checkString parameter? the name makes it sound like it's a checksum
bool ContainsNonDigits(string checkString) 
{
    for (int index = 0; index < checkString.length(); index++)
    {
        if (isdigit(checkString[index]) == 0) //isdigit() returns 0 if the character is not a digit
        {
            return true;
        }
    }
    return false;
}