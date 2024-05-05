#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>


using namespace std;

int main()
{
    //display my information
    cout << "\t\t******************************" << endl;
    cout << "\t\t*       Thomas Speich        *" << endl;
    cout << "\t\t*       CPT-168-A02H         *" << endl;
    cout << "\t\t*  Payroll Sequential File   *" << endl;
    cout << "\t\t******************************" << endl << endl;

    //declare objects
    ifstream inPayroll;
    ofstream outReport;

    //declare variables
    string name = "";
    string ssn = "";
    int hours = 0;
    int recordCount = 0;
    float payRate = 0;
    float grossPay = 0;
    float deductions = 0;
    float netPay = 0;

    inPayroll.open("Payroll.txt", ios::in);
    outReport.open("Payroll-Report.txt", ios::out);
    if (inPayroll.is_open() && outReport.is_open()) 
    {
        //display field names
        cout << "SSN \t\tName \t\tHours \t\tRate \t\tGross \t\tDeductions \tNetPay" << endl;
        cout << "____ \t\t____________ \t_____ \t\t____ \t\t_____ \t\t__________ \t______" << endl;
        outReport << "SSN \t\tName \t\tHours \t\tRate \t\tGross \t\tDeductions \tNetPay" << endl;
        outReport << "____ \t\t____________ \t_____ \t\t____ \t\t_____ \t\t__________ \t______" << endl;

        while(inPayroll.eof() == false)
        {
            recordCount++;

            //input from payroll record
            getline(inPayroll, name, '\t');
            getline(inPayroll, ssn, '\t');
            inPayroll >> hours;
            inPayroll.ignore();
            inPayroll >> payRate;
            inPayroll.ignore();

            //format name
            name.erase(1, name.find(" ") - 1);
            name.insert(1, ".");

            //shorten SSN to last 4 digits
            ssn = ssn.substr(7);

            //calculate gross pay, net pay, and deductions
            grossPay = hours * payRate;
            if (hours > 40)
            {
                grossPay += (hours - 40) * payRate / 2;
            }
            deductions = grossPay * 0.1;
            netPay = grossPay - deductions;


            //output current record with new data
            cout << ssn << "\t\t";
            if (name.length() < 8) //ensures the data lines up with the fields
            {
                cout << name << "\t\t";
            }
            else
            {
                cout << name << "\t";
            }
            cout << hours << "\t\t";
            cout << setprecision(2) << fixed << payRate << "\t\t";
            cout << grossPay << "\t\t";
            cout << deductions << "\t\t";
            cout << netPay << endl;
     
            //write data to report file
            outReport << ssn << "\t\t";
            if (name.length() < 8)
            {
                outReport << name << "\t\t";
            }
            else
            {
                outReport << name << "\t";
            }
            outReport << hours << "\t\t";
            outReport << setprecision(2) << fixed << payRate << "\t\t";
            outReport << grossPay << "\t\t";
            outReport << deductions << "\t\t";
            outReport << netPay << endl;
        }
        inPayroll.close();
        cout << endl << endl << "\tNumber of records: " << recordCount << endl << endl;
        outReport << endl << endl << "\tNumber of records: " << recordCount << endl << endl;
        outReport.close();
    }
    else
    {
        cout << "\n\t\t\t\t\tERROR" << endl;
        cout << "File(s) not found in specified location." << endl << endl;
    }

    cout << "\t\t\t\tT H A N K  Y O U !" << endl << endl;
    system("pause");
    return 0;
}
