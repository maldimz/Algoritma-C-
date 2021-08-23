#include <iostream>
using namespace std;

char loop = 'y', loop2 = 'y';
int choice, x=0, bill2,z;
string user2, pass2;
bool check;

int room1[5][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},
				{16,17,18,19,20},{21,22,23,24,25}};
char room2[5][5]={{'O','O','O','O','O'},{'O','O','O','O','O'},{'O','O','O','O','O'},
				{'O','O','O','O','O'},{'O','O','O','O','O'}};

string user[100], pass[100];
int bill[100], room_i, room_b[100];

void title(string);
void line(char, int);
void exit();
void menu();
void room_check();
void reg();
void login();
void logout();
void billing();

int pluss(int,int);
int minn(int,int);
int price(int);

int main(){
	while(loop == 'y' || loop == 'Y'){
		loop2='y';
		check=0;
		system("cls");
		menu();
		system("cls");
		switch(choice){
			case 1:
				room_check();
				break;
			case 2:
				reg();
				break;
			case 3:
				login();
				break;
			case 4:
				logout();
				break;
			case 5:
				billing();
				break;
			case 6:
				exit();
				break;
			default:
				if(cin.fail()){
					cin.clear();
					cin.ignore(10000,'\n');
					cout << "Please Input An Integer only ...\n";
				}else{
					cout << "Wrong Input ... \n";
				}
				break;
		}
		system("pause");
	}

	return 0;
}

void title(string x){
	int a;
	line('-', 50);
	a = (50 - x.size())/2;
	for(int x=1;x<=a;x++){
		cout << " ";
	} cout << x << endl;
	line('-', 50);
}

void line(char x, int y){
	for(int a=1;a<=y;a++){
		cout << x;
	} cout << endl;
}

void exit(){
	title("Program Exit...");
	loop='n';
}

void menu(){
	title("Welcome to Maldims Gaming Net");
	cout << "1. Room check\n";
	cout << "2. Register\n";
	cout << "3. Login\n";
	cout << "4. Logout\n";
	cout << "5. Billing\n";
	cout << "6. Exit\n";
	cout << "Your choice : "; cin >> choice;
}

void room_check(){
	title("Room Check");
	cout << "Information :\n";
	cout << "O = Available\nX = Booked\n\n";
	cout << "Room information\n";
	for(int x=0;x<5;x++){
		cout << " ";
		for(int y=0;y<5;y++){
			cout << room1[x][y] << "  ";
		} cout << "\n ";
		for(int z=0;z<5;z++){
			if(x>=2){
				cout << room2[x][z] << "   ";
			}else{
				cout << room2[x][z] << "  ";
			}
		} cout << endl << endl;
	}
}

void reg(){
	while(loop2=='y'){
		system("cls");
		title("Register");
		cout << "Please fill the data : \n";
		cout << "Username : "; cin >> user[x];
		if(x>0){
			for(int i=0;i<x;i++){
				if(user[x]==user[i]){
					cout << "Username already used\nPlease re-input the data again ...\n";
					system("pause");
					break;
				}else{
					loop2='n';
				}
			}
		}else{
			loop2='n';
		}
	}
	cout << "Password : "; cin >> pass[x];
	cout << "\nRegister success ...\n";
	bill[x]=0;
	room_b[x]=0;
	x++;
}

void login(){
	check=0;
	title("Login");
	cout << "Username  : "; cin >> user2;
	cout << "Password  : "; cin >> pass2;
	for(int y=0;y<x;y++){
		if(user2 == user[y] && pass2 == pass[y]){
			check=1;
			z=y;
			break;
		}else{
			check=0;
		}
	}
	if(check==1){
		if(room_b[z] == 0){
			while(loop2=='y'){
				system("cls");
				title("Account");
				cout << "Username : " << user[z] << endl;;
				cout << "Bill     : " << bill[z] << " hours\n";
				if(bill[z]>0){
					line('-',25);
					room_check();
					cout << "\n Please input the room number = "; cin >> room_i;
					if(room_i >=1 && room_i <=25){
						for(int i=0;i<5;i++){
							for(int j=0;j<5;j++){
								if(room_i == room1[i][j]  && room2[i][j] == 'O'){
									room_b[z]=room_i;
									room2[i][j]='X';
									loop2='n';
									cout << "Login success ...\n";
								}else if(room_i == room1[i][j]  && room2[i][j] == 'X'){
									cout << "Room already booked ...\n";
									system("pause");
								}
							}
						}
					}else{
						if(cin.fail()){
							cin.clear();
							cin.ignore();
							cout << "Please Input An Integer only\n";
						}else{
							cout << "Wrong input.. Please input 1-25..\n";
						}
					}	
				}else{
					cout << "Your billing is 0, please goto billing menu\n";
					loop2='n';
				}
			}
		}else{
			cout << "\nYour room still login !!!\n";
			cout << "Total bill  = " << bill[z] << endl;
			cout << "Room number = " << room_b[z] << endl << endl;
		}
	}else{
		cout << "Username or Password is wrong ...\n";
		cout << "Please input again\n";
	}
}

void logout(){
	title("Logout Account");
	check=0;
	cout << "Username  : "; cin >> user2;
	cout << "Password  : "; cin >> pass2;
	for(int y=0;y<x;y++){
		if(user2 == user[y] && pass2 == pass[y]){
			z=y;
			check=1;
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					if(room_b[z]==room1[i][j]){
						room2[i][j]='O';
						check=1;
					}
				}
			}
			break;
		}else{
			check=0;
		}
	}
	if(check==1){
		if(room_b[z]!=0){
			cout << "Logout success\n";
		}else{
			cout << "Please login first !!!\n";
		}
	}else{
		cout << "Username or Password is wrong ...\n";
		cout << "Please input again\n";
	}
}

void billing(){
	check = 0;
	loop='n';
	int z, price_bill, total_bill, pay, change;
	while(loop == 'n'){
		system("cls");
		title("Billing Input");
		cout << "Price :\n";
		cout << " 1 hours = Rp.6000\n 4 hours = Rp.20000\n";
		cout << " 6 hours++ = Rp.4000/hours\n";
		cout << "Username  : "; cin >> user2;
		for(int y=0;y<x;y++){
			if(user2 == user[y]){
				z=y;
				check=1;
				break;
			}else{
				check=0;
			}
		}
		if(check==1){
			cout << "Bill      : "; cin >> bill2;
			if(bill2>0){
				price_bill = price(bill2);
				cout << "Price     : Rp " << price_bill << endl;
				cout << "The data correct ? (y/n/e for cancel) : "; cin >> loop;
				if(loop == 'e'){
					cout << "Cancelled\n";
					loop = 'y';
					loop2 = 'n';
				}
			}else{
				cout << "Please input the correct number\n";
			}
		}else{
			cout << "Username is wrong ...\n";
			cout << "Please input again\n";
			loop='y';
			loop2='n';
		}
	} while(loop2 == 'y'){
		system("cls");
		title("Payment");
		cout << "Username   : " << user[z] << endl;
		cout << "Bill       : " << bill[z] << " hours\n";
		cout << "Add bill   : " << bill2 << " hours\n";
		cout << "Total bill : " << pluss(bill[z], bill2) << " hours\n";
		line('-',25);
		cout << "Price      : Rp " << price_bill << endl;
		cout << "Payment    : Rp "; cin >> pay;
		change=minn(pay,price_bill);
		if(change>=0){
			cout << "Change     : Rp " << change << endl;
			bill[z]=pluss(bill[z], bill2);
			loop2='n';
		}else{
			cout << "Your paid is minus\n";
			cout << "Paid again (y) or cancel (n) ? "; cin >> loop2;
		}
	}
}

int pluss(int a, int b){
	return a+b;
}

int minn(int a, int b){
	return a-b;
}

int price(int a){
	int total = 0;
	if(a<4){
		total = a * 6000;
	}else if(a<6){
		total = a * 5000;
	}else if(a>=6){
		total = a * 4000;
	}
	return total;
}