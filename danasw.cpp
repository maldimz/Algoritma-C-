#include <iostream>
using namespace std;


int main()
{
	char input;
	long long cost;
	int  guru, murid, harga = 6000;
	string instuti = "";

	menu:
	cout << "=========================== Hello ===========================" << endl;
	cout << "This is a program to calculate cost of internet access quota\n";
	cout << "=============================================================" << endl;
	cout << "type A for Kindergarden\n";
	cout << "type B for Elementary School\n";
	cout << "type C for Junior High School\n";
	cout << "type D for Senior High School\n";
	cout << "type E for University" << endl;
	cout << "Choose the institution: ";
	cin >> input;
	cout << endl;

	switch(input){
		case 'A':
		cout << "Please input the number of student\n";
			cout << "Student\t: ";
			cin >> murid;
			cost = 20*murid*harga;
			instuti = "Kindergarten";
			break; 

		case 'B':
		cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			cost = ((42*guru)+(35*murid))*harga;
			instuti = "Elementary School";
			break;

		case 'C':
		cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			cost = ((42*guru)+(35*murid))*harga;
			instuti = "Junior High School";
			break;

		case 'D':
		cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			cost = ((42*guru)+(35*murid))*harga;
			instuti = "Senior High School";
			break;

		case 'E':
		cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			cost = (guru+murid)*50*harga;
			instuti = "University";
			break;
			
		default:
		 cout << "Please input the correct word" << endl;
		 	system("pause");
			system("cls");
			goto menu;
		}
	
	cout << "-------------------------------------------------------------" << endl;
	cout << "The costs that must be incurred for " << instuti << endl;
	cout << "is " << cost << " rupiah" << endl;

	cin.get();
	return 0;
}
