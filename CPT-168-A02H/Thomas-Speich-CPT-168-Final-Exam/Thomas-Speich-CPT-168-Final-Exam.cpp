#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //initialize objects
    ifstream inRecords;
    ofstream outReport;

    //declare variables
    string firstName = "";
    string lastName = "";
    string zipcode = "";
    string state = "";
    string oddOrEvenYear = "";
    float acres = 0.0;
    float tax = 0.0;
    int year = 0;
    int recordCount = 0;

    //open records and report files
    inRecords.open("acres.txt", ios::in);
    outReport.open("report.txt", ios::out);

    //verify both files opened
    if (inRecords.is_open() && outReport.is_open())
    {
        //output column headings to report and console
        cout << "Last Name\tFirst Initial\tState\tZip Code\tAcres\t\Tax\t\tOdd/Even" << endl << fixed << setprecision(2);
        cout << "_________\t_____________\t_____\t__________\t_____\t______\t\t________" << endl << endl;
        outReport << "Last Name\tFirst Initial\tState\tZip Code\tAcres\t\Tax\t\tOdd/Even" << endl << fixed << setprecision(2);
        outReport << "_________\t_____________\t_____\t__________\t_____\t______\t\t________" << endl << endl;

        //read, manipulate, and output records to console/report
        while (inRecords.eof() == false)
        {
            recordCount++;

            //read all data from a record
            getline(inRecords, firstName, '#');
            getline(inRecords, lastName, '#');
            inRecords >> acres;
            inRecords.ignore();
            getline(inRecords, zipcode, '#');
            inRecords >> year;
            inRecords.ignore();

            //format first name
            firstName.erase(1);
            firstName += ".";

            //calculate tax and determine state
            if (zipcode[0] == '9')
            {
                tax = acres * 500;
                state = "CA";
            }
            else if (zipcode[0] == '2')
            {
                tax = acres * 100;
                state = "SC";
            }
            else
            {
                tax = acres * 200;
                state = "FL";
            }

            //add zipcode extension if not already present
            if (zipcode.length() < 6)
            {
                zipcode += "-8623";
            }

            //check if year is odd or even
            if (year % 2 == 0)
            {
                oddOrEvenYear = "Even Year";
            }
            else
            {
                oddOrEvenYear = "Odd Year";
            }

            //output to console/report
            if (tax < 1000)
            {
                cout << lastName << "\t\t" << firstName << "\t\t" << state << '\t' << zipcode << '\t' << acres << '\t' << '$' << tax << "\t\t" << oddOrEvenYear << endl;
                outReport << lastName << "\t\t" << firstName << "\t\t" << state << '\t' << zipcode << '\t' << acres << '\t' << '$' << tax << "\t\t" << oddOrEvenYear << endl;
            } 
            else
            {
                cout << lastName << "\t\t" << firstName << "\t\t" << state << '\t' << zipcode << '\t' << acres << '\t' << '$' << tax << "\t" << oddOrEvenYear << endl;
                outReport << lastName << "\t\t" << firstName << "\t\t" << state << '\t' << zipcode << '\t' << acres << '\t' << '$' << tax << "\t" << oddOrEvenYear << endl;
            }

        }
        //output record count to console/report
        cout << endl << "Number of records: " << recordCount;
        outReport << endl << "Number of records: " << recordCount;
    }
    else //Uh oh
    {
        cout << "Unable to open neccesary files";
    }
    //close files
    inRecords.close();
    outReport.close();

    cout << "\n\n" << "T H A N K  Y O U !" << endl;
    system("pause");
    return 0;
}