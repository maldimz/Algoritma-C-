//im sorry kak this is the program that i had repaired
//but i made 'before and after' on the word/pdf
//if you want to see it, i will send it to your WA number/other
//Thanks

//Akhmal Dimas Pratama(123200047)

#include <iostream>
using namespace std;

int main()
{	string area;
	int case1, case2, death1, death2, odp1, odp2;

	cout << "==Program covid-19 zone==\n";
	cout << "Please input the name of kelurahan: ";
	getline(cin, area);

	cout << "\nSurvey 1 at the first week\n";
	cout << "Input the number case of positive covid 19: ";
	cin >> case1;
	cout << "Input the number of death: ";
	cin >> death1;
	cout << "Input the number of ODP: ";
	cin >> odp1;
	
	cout << "\nSurvey 2 at the third week\n";
	cout << "Input the number case of positive covid 19: ";
	cin >> case2;
	cout << "Input the number of death: ";
	cin >> death2;
	cout << "Input the number of ODP: ";
	cin >> odp2;

	cout << "=============================================================\n";
	if(case1 >= 0 && case2 > 0 && death1 >= 0 && death2 > 0 && odp1 >= 0 && odp2 >=0){
		cout << "Kelurahan " << area << " is Black Zone";
	} else if(case1 >= 0 && case2 > 0 && death1 >= 0 && death2 == 0 && odp1>=0 && odp2 >=0) {
		cout << "Kelurahan " << area << " is Red Zone";
	} else if(case1 > 0 && case2 == 0 && death1 >= 0 && death2 == 0 && odp1>=0 && odp2 >=0) {
		cout << "Kelurahan " << area << " is Oranye Zone";
	} else {
		cout << "Kelurahan " << area << " is Green Zone";
	}
	cout << endl;

	cin.get();
	return 0;
}
