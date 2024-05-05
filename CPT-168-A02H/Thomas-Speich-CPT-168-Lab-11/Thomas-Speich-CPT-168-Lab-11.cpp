#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//returns true if the string contains non-digits; uses the isdigit() function
bool ContainsNonDigits(string);
//receives, processes, stores, and outputs data
string ProcessUserInput();
//Populates the fields in "records.txt"
void PopulateFields(ofstream&, string);

int main()
{

    //display my information
    cout << "\t\t********************************" << endl;
    cout << "\t\t*        Thomas Speich         *" << endl;
    cout << "\t\t*         CPT-168-A02H         *" << endl;
    cout << "\t\t*     String Manipulations     *" << endl;
    cout << "\t\t*  and Sequential File Output  *" << endl;
    cout << "\t\t*        with Functions        *" << endl;
    cout << "\t\t********************************" << endl << endl;



    //initialize file object
    ofstream outInfo;

    //declare variable
    char continueInput = ' ';

    outInfo.open("Records.txt", ios::app);
    if (outInfo.is_open())
    {
        //main loop
        do
        {
            PopulateFields(outInfo, ProcessUserInput());
            //update read
            do
            {
                cout << endl << "Would you like to enter new information (Y or N)? ";
                cin >> continueInput;
            } while (toupper(continueInput) != 'Y' && toupper(continueInput) != 'N');
            cin.ignore();

        } while (toupper(continueInput) == 'Y');
    }
    else
    {
        cout << "\tError" << endl;
        cout << "Unable to open or create file" << endl;
    }
    outInfo.close();
    cout << "\n\t\tT H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0; //stop
}



    
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

string ProcessUserInput()
{

    //declare variables
    string firstName = "";
    string lastName = "";
    string fullName = "";
    string phone = "";
    string social = "";
    string record = "";
    char continueInput = ' ';

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

    //combine first and last name
    fullName = firstName + " " + lastName;

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
    cout << "Your phone number is: " << phone << endl;
    cout << "Your SSN is: " << social << endl;

    //return formatted record
    if (fullName.length() < 16)
    {
        return '\n' + fullName + "\t\t" + phone + '\t' + social;
    }
    else 
    {
        return '\n' + fullName + '\t' + phone + '\t' + social;
    }

}

void PopulateFields(ofstream& file, string record)
{
    file << record;
}