#include <iostream>
#include <iomanip>

using namespace std;

int main()//Start
{
	//Display my information
    cout << "\t\t***********************" << endl;
	cout << "\t\t*    Thomas Speich    *" << endl;
	cout << "\t\t*    CPT-168-A02H     *" << endl;
	cout << "\t\t*    Test-2 Amazon    *" << endl;
	cout << "\t\t***********************" << endl;

	//Declare Variables
	float packageWeight = 0.0;
	float shippingCost = 0.0;

	//Input/Output
	cout << "Please enter the package weight: ";
	cin >> packageWeight;
	
	//Decision
	if (packageWeight < 8.0) {
		//Output
		cout << "****** Free Shipping ******" << endl;
		cout << "------> Shipping cost: $" << fixed << setprecision(2) << shippingCost << endl;
		cout << "\t\t****** Thank you! ******" << endl;

		system("pause");
		return 0;//Stop
	}
	else {
		if (packageWeight < 24.0) {
			shippingCost = packageWeight * 0.2;
		}
		else {
			if (packageWeight < 50) {
				shippingCost = packageWeight * 0.3 + 20.0;
			}
			else {
				shippingCost = 100.0;
			}
		}
	}

	//Output
	cout << "------> Shipping cost: $" << fixed << setprecision(2) << shippingCost << endl;
	cout << "\t\t****** Thank you! ******" << endl;
	system("pause");
	return 0; //Stop
}
