#include <iostream>
using namespace std;

int main()
{	
	string choise, convert1 = "", convert2 = "";
	long double input, result1, result2;
	
	cout << "==============================================\n";
	cout << "===== Welcome to MONEY CONVERTER Program =====\n";
	cout << "==============================================\n";

	cout << "(Type IDR) for convert IDR to USD and JPY\n";
	cout << "(Type USD) for convert USD to IDR and JPY\n";
	cout << "(Type JPY) for convert JPY to IDR and USD\n";
	cout << "\nInput your choise\t: "; cin >> choise;

	if (choise == "IDR"||choise == "USD"||choise == "JPY"){
		cout << "Input the amount\t: ";
		cin >> input;

		if(choise == "IDR"){
			result1 = input * 0.000068195;
			convert1 = "USD";

			result2 = input * 0.007151;
			convert2 = "JPY";
		} else if(choise == "USD"){
			result1 = input * 14663.84;
			convert1 = "IDR";

			result2 = input * 104.84;
			convert2 = "JPY";
		} else if(choise == "JPY"){
			result1 = input * 139.86;
			convert1 = "IDR";

			result2 = input * 0.009538;
			convert2 = "USD";
		}
	} else {
		cout << "Please type the right word (IDR / USD / JPY)" << endl;
		return 0;
	}

	cout << "----------------------------------------------\n";
	cout << "The result are\n";
	cout << choise << " to " << convert1 << " = "  << result1 << " " << convert1 << endl;
	cout << choise << " to " << convert2 << " = "  << result2 << " " << convert2 << endl;
	
	return 0;
}
