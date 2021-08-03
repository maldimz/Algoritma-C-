#include <iostream>
using namespace std;

int main()
{	
	int choice, side, length, width, base;
	char menu;
	
	do{
		cout << "Draw 2D Figure\n";
		cout << "1. Square\n";
		cout << "2. Rectangle\n";
		cout << "3. Right Angle Triangle\n";
		cout << "Input Menu : "; cin >> choice;

		if(choice == 1){
			cout << "\nDRAW SQUARE\n";
			cout << "Input Side : "; cin >> side;
			cout << endl;
			for(int x = 1;x <= side; x++){
				for(int y = 1;y <= side; y++){
					cout << " *";
				}
				cout << endl;
			}
		} else if(choice == 2){
			cout << "\nDRAW RECTANGLE\n";
			cout << "Input Length : "; cin >> length;
			cout << "Input Width  : "; cin >> width;
			cout << endl;
			for(int x = 1;x <= width; x++){
				for(int y = 1;y <= length; y++){
					cout << " *";
				}
				cout << endl;
			}
		} else if(choice == 3){
			cout << "\nDRAW RIGHT ANGLE TRIANGLE\n";
			cout << "Input Base Side : "; cin >> base;
			cout << endl;
			for(int x = 1;x <= base; x++){
				for(int y = 1;y <= x; y++){
					cout << " *";
				}
				cout << endl;
			}
		} else{
			cout << "\nWrong input, please type 1/2/3\n";
			cout << "Please open the program again . . ." << endl << endl;
			system("pause");
			return 0;
		}
		cout << "\nBack to Menu ? (Y/N) : ";
		cin >> menu;
		cout << endl;
		
	} while (menu == 'Y'||menu == 'y');

	return 0;
}
