#include <iostream>
using namespace std;


struct courses{
	string name, course_id, day;
};

int main()
{
	int number, choice, i;
	string search;
	bool found;
	char loop = 'y';

	cout << "How many courses want to input? "; cin >> number;
	courses course[number];
	for (int j=0;j<number;j++){
		cin.ignore();
		cout << "Courses - " << j+1 << endl;
		cout << "Id       = "; getline(cin, course[j].course_id);
		cout << "Name     = "; getline(cin, course[j].name);
		cout << "Day      = "; cin >> course[j].day; cout << endl;
	}

	while(loop == 'y' || loop == 'Y'){
		found = false;
		i=0;
		system("cls");
		cout << "== Search courses program ==" << endl;
		cout << "Search method\n";
		cout << "1. By Name\n" << "2. By Course ID\n" << "3. By Day\n";
		cout << "Your choice = "; cin >> choice; cin.ignore();
		if(choice == 1){
			cout << "Search by name\n" << "Please input course name = ";
			getline(cin, search);
			while(i<number && !found){
				if(search == course[i].name){
					found = true;
				}else{
					i++;
				}
			}
			if(found){
				cout << "Your course is found" << endl;
				cout << "Id       = " << course[i].course_id << endl;
				cout << "Name     = " << course[i].name << endl;
				cout << "Day      = " << course[i].day << endl;
			}else{
				cout << "Your course not found!!\n";
			}

		}else if(choice == 2){
			cout << "Search by course id\n" << "Please input course id = ";
			getline(cin, search);
			while(i<number && !found){
				if(search == course[i].course_id){
					found = true;
				}else{
					i++;
				}
			}
			if(found){
				cout << "Your course is found" << endl;
				cout << "Id       = " << course[i].course_id << endl;
				cout << "Name     = " << course[i].name << endl;
				cout << "Day      = " << course[i].day << endl;
			}else{
				cout << "Your course not found!!\n";
			}
		}else if(choice == 3){
			cout << "Search by day\n" << "Please input the day = ";
			getline(cin, search);
			for(int j=0;j<number;j++){
				if(search == course[j].day){
					cout << "Id       = " << course[j].course_id << endl;
					cout << "Name     = " << course[j].name << endl;
					cout << "Day      = " << course[j].day << endl << endl;
					found = true;
				}
			}
			if(!found){
				cout << "Your course not found!!\n";
			}

		}else{
			cout << "Wrong input !!!" << endl;
		}
		cout << "\nWant to search again (y/n) ? "; cin >> loop;
	}

	
	return 0;
}
