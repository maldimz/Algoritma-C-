#include <iostream>
using namespace std;

int main()
{
	char input1;
	long long cost;
	int  guru, murid, input2, harga = 6000;
	string instuti;

	menu:
	cout << "=========================== Hello ===========================" << endl;
	cout << "This is a program to calculate cost of internet access quota\n";
	cout << "=============================================================" << endl;
	cout << "type A for Kindergarden to Senior High School\n";
	cout << "type B for University" << endl;
	cout << "Choose the institution: "; cin >> input1;
	cout << endl;

	if(input1 == 'A'){
		cout << "type 1 for Kindergarten\n";
		cout << "type 2 for Elementary School\n";
		cout << "type 3 for Junior High School\n";
		cout << "type 4 for Senior High School\n";
		cout << "choose the institution: "; cin >> input2;
		cout << endl;

		if(input2 == 1){
			cout << "Please input the number of student\n";
			cout << "Student\t: ";
			cin >> murid;
			instuti = "Kindergarten";
			cost = murid*harga*20;

		} else if(input2 == 2){
			cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			instuti = "Elementary School";
			cost = ((42*guru)+(35*murid))*harga;

		} else if(input2 == 3){
			cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			instuti = "Junior High School";
			cost = ((42*guru)+(35*murid))*harga;

		} else if(input2 == 4){
			cout << "Please input the number of teacher and student\n";
			cout << "Teacher\t: "; cin >> guru;
			cout << "Student\t: "; cin >> murid;
			instuti = "Senior High School";
			cost = ((42*guru)+(35*murid))*harga;

		} else {
			cout << "Please input the correct number" << endl;
			system("pause");
			system("cls");
			goto menu;
		}

	} else if(input1 == 'B'){
		cout << "Please input the number of teacher and student\n";
		cout << "Teacher\t: "; cin >> guru;
		cout << "Student\t: "; cin >> murid;
		instuti = "University";
		cost = (guru+murid)*50*harga;

	} else {
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
