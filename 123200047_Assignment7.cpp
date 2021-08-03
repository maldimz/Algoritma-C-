#include <iostream>
#include <iomanip>

using namespace std;

char loop = 'y', result;
int choice;

void wrong();
void choice_menu();
void menu();
void record();
void no_record();
void rapid_test();
void rapid();
void print(int, string, string);
void title(string);
void tracing();
void tracing_data(int, string, string, string, int);
void exit();
void vaccine();
void vaccine_menu();
void vaccine_schedule();
void vaccine_data(int, string, string);
int total(int, int);

int main(){
	char vacc;
	int x=0, pos=0, vac=0, n_ck, a_ck, sum=0, trace[100], sum2 = 0;
	string name[100], address[100], phone[100], result_test[100];
	string name_pos[100], address_pos[100], result_pos[100];
	string name_vac[100],result_vac[100];

	while(loop == 'y'){
		system("cls");
		menu();
		choice_menu();
		if(choice == 1){
			system("cls");
			rapid_test();
			choice_menu();
			system("cls");
			if(choice == 1){
				title("Registered Account Name");
				if(x == 0){
					no_record();
				}else{
					for(int y=0;y<x;y++){
						print(y+1,name[y],result_test[y]);
					}
				}
			} else if(choice == 2){
				title("Rapid Test Registration");
				cin.ignore();
				cout << "Name[30] 	: "; getline(cin, name[x]);
				cout << "Address[40]	: "; getline(cin, address[x]);
				cout << "Phone		: "; getline(cin, phone[x]);
				cout << "--------------------------------------------------\n";
				n_ck = name[x].size();
				a_ck = address[x].size();
				if(n_ck <=30 && a_ck <= 40){
					rapid();
					if(result == '+'){
						result_test[x]="Positive";
						result_pos[pos]=result_test[x];
						name_pos[pos]=name[x];
						address_pos[pos]=address[x];			
						tracing(); cin >> trace[pos];
						sum = total(sum, trace[pos]);
						name_vac[vac]=name[x];
						result_vac[vac]=result_test[x];
						sum2 = total(sum2, 1);
						vac++;
						x++;
						pos++;
						record();
						vaccine();
					} else if(result == '-'){
						result_test[x]="Negative";
						record();
						cout << "Want to get a vaccine (y/n)? "; cin >> vacc;
						if(vacc == 'y' || vacc == 'Y'){
							vaccine();
							name_vac[vac]=name[x];
							result_vac[vac]=result_test[x];
							vac++;
							sum2 = total(sum2, 1);
						} x++;
					}else{
						wrong();
					}	
				}else{
					wrong();
					cout << "Over Character\n";
				}			
			}else{
				wrong();
			}
				
		}else if(choice == 2){
			system("cls");
			title("Tracing Data COVID-19");
			if(x==0){
				no_record();
			}else{
				cout << "| NO ";
				cout << "|             Name             ";
				cout << "|                Address                 ";
				cout << "|  Result  ";
				cout << "|Contact|" << endl;
				for(int y=0;y<pos;y++){
					tracing_data(y+1,name_pos[y],address_pos[y],result_pos[y], trace[y]);
				}
				cout << "\nTotal Contact Tracing = " << sum << endl;
				
			}
		}else if(choice == 3){
			system("cls");
			vaccine_menu();
			choice_menu();
			system("cls");
			if(choice == 1){
					vaccine_schedule();
			}else if(choice == 2){
				title("Vaccinating Data COVID-19");
				if(vac==0){
					no_record();
				}else{
					cout << "| NO ";
					cout << "|             Name             ";
					cout << "|  Status  |\n";
					for(int x=0;x<vac;x++){
						vaccine_data(x+1, name_vac[x], result_vac[x]);
					}
					cout << "\nTotal Vaccinating = " << sum2 << endl;
				}	
			}else{
					wrong();
				}
		}else if(choice == 4){
			exit();
		}else{
			wrong();
		}	
		system("pause");	
	}
	return 0;
}

void wrong(){
	cout << "Wrong Input, Please input again\n";
}
void choice_menu(){
	cout << "Choose the menu : "; cin >> choice;
}
void menu(){
	title("Welcome to COVID-19 Info Program");
	cout << "1. Rapid Test\n";
	cout << "2. Tracing\n";
	cout << "3. Vaccinating\n";
	cout << "4. Exit\n";
}
void record(){
	cout << "--- Your Data Recorded ---" << endl;
}
void no_record(){
	cout << "--- No Data Record ---" << endl;
}
void rapid_test(){
	title("Rapid Test Menu");
	cout << "1. Registered Account\n";
	cout << "2. Register New Account\n";
}
void rapid(){
	cout << "Please Input The Result of Rapid Test\n";
	cout << "               Type + / -            \n";
	cout << "Input : "; cin >> result;
}
void print(int a, string b, string c){
	cout << left;
	cout << a << ". ";
	cout << setw(25)<< b << " | " << c << endl;
}
void title(string a){
	int b=a.size();
	int c=(100-b)/2;
	for(int x=1;x<=100;x++){
		cout << "-";
	} cout << endl;
	for(int y=1;y<=c;y++){
		cout << " ";
	}
	cout << a << endl;;
	for(int x=1;x<=100;x++){
		cout << "-";
	} cout << endl;
}
void tracing(){
	cout << "--------------------------------------------------\n";
	cout << "How many people have been contacted? ";
}
void tracing_data(int a, string b, string c, string d, int e){
	cout << left;
	cout << "|" << setw(4) << a;
	cout << "|" << setw(30) << b;
	cout << "|" << setw(40) << c;
	cout << "|" << setw(10) << d;
	cout << "|" << setw(7) << e << "|\n";
}
void exit(){
	cout << "--- Have a nice Day ---\n";
	loop = 'n';
}
void vaccine(){
	cout << "\nPlease check the schedule of vaccinating for getting vaccines\n";
}
void vaccine_menu(){
	title("Vacinating COVID-19 Info");
	cout << "1. Vaccinating Schedule\n";
	cout << "2. Vaccinating Data\n";
}
void vaccine_schedule(){
	title("Vaccinating Schedule");
	cout << "Monday    :08.00-17.00\n";
	cout << "Tuesday   :08.00-17.00\n";
	cout << "Wednesday :08.00-17.00\n";
	cout << "Thursday  :08.00-17.00\n";
	cout << "Friday    :13.00-19.00\n";
	cout << "Saturday  :08.00-12.00\n";
	cout << "Sunday    :08.00-12.00\n";
}
void vaccine_data(int a, string b, string c){
	cout << left;
	cout << "|" << setw(4) << a;
	cout << "|" << setw(30) << b;
	cout << "|" << setw(10) << c << "|\n";
}
int total(int a, int b){
	return a+b;
}