#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char loop='y', choice2;
int choice, paid, trans, trans2, t_id, t_room, xx, yy, t_facilities[100], total_f, payment, disc, rep;
string t_name, t_schedule;

bool check, room_check[5][3] = {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

string display1[5][3] = {{"O","O","O"},{"O","O","O"},{"O","O","O"},{"O","O","O"},{"O","O","O"}};
string display2[5][3] = {{"-","-","-"},{"-","-","-"},{"-","-","-"},{"-","-","-"},{"-","-","-"}};

int room_number[5][3] = {{101,102,103},{201,202,203},{301,302,303},{401,402,403},{501,502,503}};
string room_name[5][3] = {
						{"Puntadewa", "Srikandi", "Nakula"},
						{"Ir. Soekarno","Laksamana Maeda", "Moch. Hatta"},
						{"Prof. Habibie","R. A. Kartini","Ki Hadjar Dewantara"},
						{"Nelson Mandela","Bill Clinton","Immanuel Kant"},
						{"Leonardo Da Vinci","Ludwig Beethoven", "Fred Astaire"}
					};
int rental_price[5][3] = {
							{2500000,3000000,7500000},{4500000,1000000,2500000},
							{1500000,2500000,3500000},{12500000,20000000,25000000},
							{6000000,3000000,4500000}
						};
int capacity[5][3] = {{40,30,75},{40,20,15},{15,30,20},{100,100,100},{30,25,35}};

int facilities_id[10] = {1,2,3,4,5,6,7,8,9,10};
string facilities_name[10] = {"Food & Beverage","MC","Band","Operator","Decoration",
						"Security","Documentation","Staff Personnel","Souvenir","Full Services"
						};
int facilities_price[10] = {2500000,3000000,15000000,2500000,10000000,
						20000000,2500000,2000000,25000000,75000000
						};

void line(string, int);
void looping();
void wrong();
void title(string, int);
void title_main();
void title_welcome();
void display_building();
void display_rooms();
void display_facilities();
void input_transaction();
void discarge_room();
void menu();
int dis_rep(int);
int discount(int, int);
int payment2(int, int);
int min(int, int);

int main(){
	title_main();
	title_welcome();
	while(loop=='y'||loop=='Y'){
		title_main();
		menu();

		if(choice > 0 && choice <= 5){
			title_main();
			switch(choice){
				case 1:
					display_building();
					break;
				case 2:
					display_rooms();
					break;
				case 3:
					display_facilities();
					break;
				case 4:
					input_transaction();
					break;
				case 5:
					discarge_room();
					break;
			}
		} else{
			wrong();
		}
		looping();
	}

	return 0;
}

void line(string a, int c){
	for(int b=1; b<=c ; b++){
			cout << a;
		} cout << endl;
}

void looping(){
	line("=", 50);
	cout << "Back to menu? (y/n) : "; cin >> loop;
}

void wrong(){
	cout << "Wrong Input\n";
}

void title(string a, int z){
	int b=a.size();
	int c=(z-b)/2;
	for(int d=1; d<=c; d++){
		cout << " ";
	}
	cout << a << endl;
}

void title_main(){
	system("cls");
	line("=", 50);
	title("GRAHA PRAMUDYA BANDUNG", 50);
	title("4 Asia Afrika Street, Bandung, West Java", 50);
	line("=", 50); 
}

void title_welcome(){
	title("WELCOME...", 50);
	title("Trusted Partner to Held Your Important Meeting", 50);
	line("=", 50); 
	system("pause");
}

void menu(){
	cout << "ADMINISTRATION MENU\n";
	cout << "1. Display Building\n2. Display Rooms\n3. Display Facilities\n";
	cout << "4. Input Transaction\n5. Discharge Room\n";
	cout << "Selection : "; cin >> choice;
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "Please Input An Integer only\n";
	} else{
		system("cls");
	}
}

void display_building(){
	cout << " Menu 1 : Display Building Status\n";
	line("-", 50);
	cout << " Information :\n 0 : Available\n X : Booked\n\n";
	cout << "         - 1 -   - 2 -   - 3 -\n";
	for(int x=0; x<5; x++){
		cout << " | " << x+1 << " | ";
		for(int y=0; y<3; y++){
			cout << "    " << display1[x][y] << "   ";
		} cout << endl;
	}
	cout << "Display Building Based on the transaction data? (y/n) : "; cin >> choice2;
	if(choice2=='y'||choice2=='Y'){
		system("cls");
		title_main();
		cout << " Menu 1 : Display Building Status\n Based on ID Transaction\n";
		line("-", 50);
		cout << " Information :\n - : There is no Transaction\n\n";
		cout << "         - 1 -   - 2 -   - 3 -\n";
		for(int x=0; x<5; x++){
			cout << " | " << x+1 << " | ";
			for(int y=0; y<3; y++){
				cout << "    " << display2[x][y] << "   ";
			} cout << endl;
		}
		line("=", 50);
	}
}

void display_rooms(){
	cout << " Menu 2 : Display Rooms Data\n";
	line("-", 50);
	for(int x=0; x<5; x++){
		cout << "Floor-" << x+1 << endl;
		for(int y=0; y<3; y++){
			cout << " Room Number    : " << room_number[x][y] << endl;
			cout << " Name           : " << room_name[x][y] << endl;
			cout << " Price          : " << rental_price[x][y] << " IDR (Rp) / hours\n";
			cout << " Capacity       : " << capacity[x][y] << endl << endl;
		}
		line("-", 50);
	}
}

void display_facilities(){
	cout << " Menu 3 : Display Facilities Data\n";
	line("-", 50);
	for(int x=0; x<10; x++){
		cout << " Facilities ID  : " << facilities_id[x] << endl;
		cout << " Name           : " << facilities_name[x] << endl;
		cout << " Price          : " << facilities_price[x] << " IDR (Rp) / set\n\n";
		line("-", 50);
	}
}

void input_transaction(){
	cout << " Menu 4 : Transaction\n";
	line("-", 50); cout << endl;
	cout << " "; title("Room", 60);
	cout << " "; line("=",60);
	cout << left << " ";
	cout << setw(6) << "No." << setw(21) << " Name" << setw(22) << " Price (IDR/hours)";
	cout << " Capacity\n ";
	line("=", 60);
	for(int x=0; x<5; x++){
		for(int y=0 ; y<3; y++){
			cout << setw(1) << "";
			cout << setw(6) << room_number[x][y] << setw(21) << room_name[x][y];
			cout << setw(22) << rental_price[x][y] << capacity[x][y] << endl;
		} cout << " "; line("=", 60);
	} cout << endl << endl;
	title("FACILITIES", 50);
	line("-", 50);
	cout << setw(7) << " Id." << setw(21) << " Name" << " Price (IDR/set)\n";
	line("-", 50);
	for(int x=0; x<10; x++){
		cout << setw(1) << "";
		cout << setw(7) << facilities_id[x] << setw(21) << facilities_name[x];
		cout << facilities_price[x] << endl;
		line("-", 50);
	} line("-", 50);
	cout << " Each Transaction Only for 1 Room\n How many transaction?  : "; cin >> trans;
	system("cls");
	title_main();
	for(int x=0; x<trans; x++){
		check=0;
		loop='y';
		total_f=0;
		cout << " Transaction-" << x+1 << endl;
		cout << " Transaction ID          : "; cin >> t_id; cin.ignore();
		cout << " Name                    : "; getline(cin, t_name);
		cout << " Schedule                : "; getline(cin, t_schedule);
		line("-",50);
		cout << " Select Room (NO)        : "; cin >> t_room;
		if((t_room >= 101 && t_room <=103)||(t_room >= 201 && t_room <=203)||
		(t_room >= 301 && t_room <=303)||(t_room >= 401 && t_room <=403) || (t_room >= 501 && t_room <=503))
		{
			for(int y=0;y<5;y++){
				for(int z=0;z<3;z++){
					if(t_room == room_number[y][z] && room_check[y][z] == 0 ){
						xx = y;
						yy = z;
						check = 1;
						line("-", 50);
						cout << " How many facilities?   : "; cin >> trans2;
						for(int k=0; k<trans2; k++){
							cout << " Select Facilities (ID) : "; cin >> t_facilities[k];
							if(t_facilities[k]>10 || t_facilities[k]<0){
								check = 0;
								loop='n';
								cout << " Facilities Data Invalid\n Please Re-Input Your Transaction\n";
								break;
							}
						} line("-", 50);
						if(check==1){
							cout << "Total Rooms Price       : " << rental_price[y][z] << endl;
							for(int k=0; k<trans2; k++){
								for(int m=0; m<10; m++){
									if(t_facilities[k]==facilities_id[m]){
										total_f = total_f + facilities_price[m];
									}
								}
							}
							cout << "Total Facilities Price  : " << total_f << endl;
							payment = rental_price[y][z] + total_f;
							cout << "Total Payment           : " << payment << endl;
							rep = dis_rep(payment);
							disc = discount(payment, rep);
							payment = min(payment, disc);
							system("pause");
						} 
					}else if(t_room == room_number[y][z] && room_check[y][z] == 1){
					loop='n';
					cout << " Room Number Invalid or Already Booked\n Please Re-Input Your Transaction\n";
					}
				}
			} 
		}else{
			loop='n';
			cout << " Room Number Invalid or Already Booked\n Please Re-Input Your Transaction\n";
		}
		while(loop == 'y'||loop == 'Y'){
			if(check == 1){
				line("=", 50);
				cout << "Total Payment             : " << payment << endl;
				cout << "Discount Repetition       : " << rep << endl;
				cout << "Discount 2%% (/100000)    : " << disc << endl;
				cout << "Total Payment             : " << payment << endl;
				line("-", 50);
				cout << "Money Paid      : "; cin >> paid;				
				if(min(paid, payment)>=0){
					cout << "Change          : " << min(paid, payment) << endl;
					loop = 'n';
				} else{
					cout << "Your paid is minus\nPaid again(y) or cancel(n)? : "; cin >> choice2;
					if(choice2 == 'n'){
						check = 0;
						"Your transaction canceled\n";
						loop = 'n';
					}
				} line("-", 50);
			}
		}	 
		if(check == 1){
				room_check[xx][yy] = 1;
					display1[xx][yy] = "X";
					display2[xx][yy] = to_string(t_id);
		}
	}
}

void discarge_room(){
	check = 1;
	cout << " Menu 5 : Discharge Room\n";
	line("-",50);
	cout << " Input Room Number  : "; cin >> t_room;
	if((t_room >= 101 && t_room <=103)||(t_room >= 201 && t_room <=203)||
		(t_room >= 301 && t_room <=303)||(t_room >= 401 && t_room <=403) || (t_room >= 501 && t_room <=503))
	{
		for(int y=0;y<5;y++){
			for(int z=0;z<3;z++){
				if(t_room == room_number[y][z] && room_check[y][z] == 1 ){
					room_check[y][z] = 0;
					display1[y][z] = "O";
					display2[y][z] = "-";
					cout << "Discharge Room Success\n";
					cout << "Check-out Menu-1 : Display Building Status\n";
				}else if(t_room == room_number[y][z] && room_check[y][z] == 0){
					cout << " Room Number Invalid\n Please Re-Input The Data\n";
				}
			}
		}
	}else{
		cout << " Room Number Invalid\n Please Re-Input The Data\n";
	}
	
}

int dis_rep(int a){
	return a/1000000;
}

int discount(int a, int b){
	return a*b*0.02;
}

int min(int a, int b){
	return a-b;
}