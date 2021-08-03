#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int choice, a = 0, y = 0, info, select, sum, med, medicine, money, change, z, ite;
char queue_char, loop = 'y', loop2 = 'n', correct;
string user, pass, str;

int total[100], t_cost[100], check_stat[100], p_incre[100], medic[100];
string p_name[100], sex[100], address[100], pay_stat[100], p_que[100], phone[100];

int que[26], cost[26], increment[26];
string dr_name[26], special[26],schedule[26], dr_id[26];

bool check;

void title(string);
void menu();
void wrong();
void line(string, int);
void dr_input();
void dr_schedule();
void patient_input();
void queue_output();
void payment_menu();
void record_menu();
void payment_status();
void payment_trans(int);

void exit();

int minn(int, int);
int ReadString(string);

int main(){
	while(loop2 == 'n' || loop2 == 'N'){
		system("cls");
		title("Welcome to Pratama Hospital");
		dr_input();
	}

	while(loop == 'y' || loop == 'Y'){
		system("cls");
		menu();
		if(choice == 1){
			dr_schedule();
		}else if(choice == 2){
			patient_input();
		}else if(choice == 3){
			queue_output();
		}else if (choice == 4){
			payment_menu();
			if (select == 1){
				record_menu();
			}else if (select == 2){
				payment_status();
				if((choice>=1 && choice <=y) || y == 0){
					for(int x=0;x<y;x++){
						if (choice == p_incre[x] && check_stat[x]==1){
							cout << "\nStatus can't be open" << endl;
							cout << "Please fill the record" << endl;
						}else if (choice == p_incre[x] && check_stat[x]==2){
							payment_trans(choice);
						}else if (choice == p_incre[x] && check_stat[x]==3){
							cout << "Already paid off" << endl;
						}
					}
				}else{
					wrong();
				}
			} else {
				wrong();
				if(cin.fail()){
					cin.clear();
					cin.ignore();
					cout << "Please Input An Integer only\n";
				} 
			}	
		}else if(choice == 5){
			exit();
		}else{
			wrong();
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please Input An Integer only\n";
			} 
		}
		cout << endl;
		system("pause");
	}
	return 0;
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

void menu(){
	title("Welcome to Pratama Hospital");
	cout << "Menu :\n";
	cout << "1. Schedule\n";
	cout << "2. Patient input\n";
	cout << "3. Queue check\n";
	cout << "4. Payment\n";
	cout << "5. Exit the program\n";
	cout << "Input your choice : "; cin >> choice;	
}

void patient_input(){
	system("cls");
	title("Patient's Data");
	if(y<100){
		check=0;
		cin.ignore();
		cout << "\nPatient number - " << ++a << endl;
		cout << "Name          : "; getline(cin, p_name[y]);
		cout << "Sex           : "; getline(cin, sex[y]);
		cout << "Phone         : "; cin >> phone[y];
		cin.ignore();
		cout << "Address       : "; getline(cin, address[y]);
		cout << "Info          : "; cout << "1. " + special[0] << endl;
		for(int x=1;x<ite;x++){
			cout << setw(16) << "";
			cout << x+1 << ". " << special[x] << endl;
		}
		cout << "Input[number] : "; cin >> info;
		if(info >=1 && info <=ite){
			for(int x=0;x<ite;x++){
				if(info==increment[x]){
					t_cost[y]=cost[x];
					check=1;
				}
			}
		}else{
			wrong();
			cout << "Please input Patient Data Again\n";
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Please Input An Integer only\n";
			} 
			--a;
		}
		if(check == 1){
			cout << "\nThe data are correct? (y/n) : "; cin >> correct;
			if(correct == 'n' || correct == 'N'){
				cout << "Your Input canceled\n";
				check = 0;
				--a;
			}
		}
		cout << endl;
		if(check==1){
			pay_stat[y]="Process";
			check_stat[y]=1;
			p_incre[y]=y+1;
			line("-",50);
			queue_char='A';
			for(int x=0;x<ite;x++){
				if(info == increment[x]){
					que[x]++;
					cout << "Your queue is " << queue_char << que[x] << endl;
					str = to_string(que[x]);
					p_que[y] = p_que[y] + queue_char + str; 
				}queue_char++;
			}y++;
		}
	}else{
		cout << "\nThe patient data is maximum\n";
	}
}

void queue_output(){
	system("cls");
	title("Pratama Hospital Queue");
	cout << "Total patient is " << a << endl;
	cout << "| No ";
	cout << "|     Doctor's Name     ";
	cout << "| Queue |\n";
	queue_char='A';
	for(int x=0;x<ite;x++){
		cout << left;
		cout << "|" << setw(4) << x+1;
		cout << "|" << setw(23) << dr_name[x];
		cout << "|" << queue_char << setw(6) << que[x] << "|\n";
		queue_char++;
	}
}

void payment_menu(){
	system("cls");
	title("Payment");
	cout << "1. Record\n";
	cout << "2. Payment Status\n";
	cout << "Select : "; cin >> select;
}

void record_menu(){
	check=0;
	sum=0;
	system ("cls");
	title("Record");
	cout << "Username : "; cin >> user;
	cout << "Password : "; cin >> pass;
	cout << "-------------------------------------------\n";
	if (user == "pratama" && pass == "pratama"){
		cout << "Login Successful\n";
		cout << "-------------------------------------------\n";
		system("pause");
		system("cls");
		title("Payment");
		cout << "| ID";
		cout << "|   Patient's Name \n";
		for (int x=0;x<y;x++){
			if(check_stat[x]==1){
				cout << left;
				cout << "|" << setw(3) << p_incre[x];
				cout << "|" << setw(20) << p_name[x] <<  "|\n";
				check=1;
			}
		}
		if(y==0||check==0){
			cout << "\nNo data recorded\n";
		}else{
			cout << "Please select the ID : "; cin >> select;
			system("cls");
			title("Payment");
			z=select-1;
			if(select >=1 && select <=y && check_stat[z]==1){
				cout << "Patient's Queue "<< p_que[z] << endl;
				cout << "Name       : " << p_name[z] << endl;
				cout << "Sex        : " << sex[z] << endl;
				cout << "Phone      : " << phone[z] << endl;
				cout << "Address    : " << address[z] << endl;
				cout << "-------------------------------------------\n";
				cout << "Cost of Treatment : Rp " << t_cost[z] << endl;
				cout << "-------------------------------------------\n";
				cout << "How many medicine?	: "; cin >> med;
				for (int x=0; x<med; x++){
					cout << "Cost of Medicine	: Rp "; cin >> medicine;
					sum=sum+medicine;
				}
				medic[z]=sum;
				total[z]=t_cost[z]+sum;
				cout << "-------------------------------------------\n";
				cout << "Total cost		: Rp " << total[z] << endl << endl;
				pay_stat[z]="Not Paid";
				check_stat[z]=2;
			}else{
				wrong();
			}
		}
	}else {
		cout << "Login Failed\n" << "Please input correct username and password\n";
		cout << "-------------------------------------------\n";
	}
}

void payment_status(){
	system("cls");
	title("Payment Status");
	cout << "| No";
	cout << "|   Patient's Name   ";
	cout << "|  Status  |\n";
	if(y==0){
		cout << "No data recorded\n";
	}else{
		for(int x=0;x<y;x++){
			cout << left;
			cout << "|" << setw(3) << x+1;
			cout << "|" << setw(20) << p_name[x];
			cout << "|" << setw(10) << pay_stat[x] << "|\n";
		}
		cout << "Input the number: "; cin >> choice;
	}
}

void wrong(){
    cout << "\nWrong Input\n";
}


void line(string a, int b){
	for(int x=1;x<=b;x++){
		cout << a;
	} cout << endl;
}

void dr_input(){
	check=1;
	cout << "Please input the doctor's data\n";
	cout << "How many doctor(s)? "; cin >> ite;
	if(ite >=1 && ite <=26){
		line("-",70);
		for(int x=0;x<ite;x++){
			cin.ignore();
			increment[x]=x+1;
			que[x]=0;
			cout << "Dr - " << x+1 << endl;
			cout << "Name[30]          : "; getline(cin, dr_name[x]);
			cout << "Dr ID[10]         : "; cin >> dr_id[x];
			cin.ignore();
			if(ReadString(dr_name[x])>30 || ReadString(dr_id[x])>10){
            	wrong();
            	cout << "Over Character" << endl;
           		cout << "Please Re-Input Again" << endl;
            	check=0;
				break;
			}
			cout << "Specialization    : "; getline(cin, special[x]);
			cout << "Schedule          : "; getline(cin, schedule[x]);
			cout << "Cost of treatment : Rp "; cin >> cost[x];
			cout << endl;
		}
		if(check==1){
			cout << "The data are correct? (y/n) : "; cin >> loop2;
		}
	}else{
		wrong();
		cout << "Please input 1-26\n";
	}
	system("pause");
}

void dr_schedule(){
	system("cls");
	title("Doctor Schedule");
	cout << "| No ";
	cout << "|         Name         ";
	cout << "|   Dr ID   ";
	cout << "|  Specialization  ";
	cout << "|     Schedule     ";
	cout << "| Cost of treatment |\n";
	for(int x=0;x<ite;x++){
		cout << left;
		cout << "|" << setw(4) << x+1;
		cout << "|" << setw(22) << dr_name[x];
		cout << "|" << setw(11) << dr_id[x];
		cout << "|" << setw(18) << special[x];
		cout << "|" << setw(18) << schedule[x];
		cout << "|" << setw(19) << cost[x] << "|\n";
	}
}

void payment_trans(int x){
	loop2='y';
	while(loop2 == 'y' || loop2 == 'Y'){
		system("cls");
		check=0;
		title("Payment");
		z=x-1;
		cout << "Patient's Queue "<< p_que[z] << endl;
		cout << "Name       : " << p_name[z] << endl;
		cout << "Sex        : " << sex[z] << endl;
		cout << "Phone      : " << phone[z] << endl;
		cout << "Address    : " << address[z] << endl;
		cout << "-------------------------------------------\n";
		cout << "Cost of Treatment  : Rp " << t_cost[z] << endl;
		cout << "Cost of Medicine   : Rp " << medic[z] << endl;
		cout << "-------------------------------------------\n";
		cout << "Total cost         : Rp " << total[z] << endl;
		cout << "Payment            : Rp "; cin >> money;
		change = minn(money, total[z]);
		if(change >= 0){
			cout << "Change             : Rp " << change << endl << endl;
			cout << "         Thank you !!!\n";
			cout << "Your Transaction is Success\n";
			check=1;
			loop2 = 'n';
		}else{
			cout << "-------------------------------------------\n";
			cout << "Your paid is minus\nPaid again (y) or cancel (n)? ";
			cin >> loop2;
			if(loop2 == 'y' || loop2 == 'Y'){
				system("pause");
			} else if(loop2 == 'n' || loop2 == 'N'){
				cout << "\nYour Transaction is cancelled\n";
			} else{
				wrong();
				cout << "\nPlease input your payment again\n";
			}
		}
	}
	if(check == 1){
		pay_stat[z]="Paid";
		check_stat[z]=3;
	}
}

void exit(){
	system("cls");
	cout << "=========================\n";
	cout << "       Thank you\n";
	cout << "     Have a nice Day\n";
	cout << "=========================\n";
	cout << endl;
	loop = 'n';
}

int ReadString(string a){
    int b = a.size();
    return b;
}

int minn(int c, int v){
	return c-v;
}