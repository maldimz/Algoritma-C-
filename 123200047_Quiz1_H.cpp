#include <iostream>
using namespace std;

int main(){	
	int sum, menu, price, total_all, serv, disrep, discount = 0, payment;
	char loop = 'y';
	string user, pass, name, trans, code, menu_name;
	while(loop == 'y' || loop == 'Y'){
		system("cls");
		cout << "----------------------------------------------------\n";
		cout << "             Welcome to Family Catering             \n";
		cout << "----------------------------------------------------\n";
		cout << "Username : "; cin >> user;
		cout << "Password : "; cin >> pass;
		cout << "----------------------------------------\n";
		if(user == "admin" && pass == "admin"){
			cout << "Login Successfully\n" << "----------------------------------------\n";
			system("pause");
			while(loop == 'y' || loop == 'Y'){
				system("cls");
				sum = 0;
				cout << "----------------------------------------------------\n";
				cout << "               Catering Order Cashier               \n";
				cout << "----------------------------------------------------\n";
				cout << "Input Transaction Code  : "; cin >> trans;
				cout << "Input Customer Name     : ";
				cin.ignore(); getline(cin, name);
				cout << "How many menu?          : "; cin >> menu;
				string m_name[menu];
				int total[menu], arry_serv[menu];
				cout << "----------------------------------------------------\n";
				for(int x=0; x<menu; x++){
					cout << "\nItem- " << x+1 << endl;
					cout << "Menu Code  : "; cin >> code; cin.ignore();
					if(code=="001"||code=="002"||code=="003"||code=="004"||code=="005"||code=="006"||code=="007"||code=="008"||code=="009"||code=="010"){
							if(code == "001"){
							menu_name = "Regular Menu Set";
							price = 65000;
						}else if(code == "002"){
							menu_name = "Premium Menu Set";
							price = 100000;
						}else if(code == "003"){
							menu_name = "Chicken Cutlet Set";
							price = 45000;
						}else if(code == "004"){
							menu_name = "Beef Cutlet Set";
							price = 60000;
						}else if(code == "005"){
							menu_name = "Happy Kids Meal";
							price = 40000;
						}else if(code == "006"){
							menu_name = "Vegetarian Set";
							price = 80000;
						}else if(code == "007"){
							menu_name = "Chocolicious Drink Set";
							price = 15000;
						}else if(code == "008"){
							menu_name = "Fresh Fruit Drink Set";
							price = 15000;
						}else if(code == "009"){
							menu_name = "Salad";
							price = 20000;
						}else if(code == "010"){
							menu_name = "Mini Dessert Set";
							price = 25000;
						}
						cout << "Menu Name          : " << menu_name << endl;
						cout << "How many serving?  : "; cin >> serv;
						cout << "Price per serving  : " << price << endl;
					}else{
						cout << "Menu Name          : "; getline(cin, menu_name);
						cout << "How many serving?  : "; cin >> serv;
						cout << "Price per serving  : "; cin >> price;
					}
					m_name[x]=menu_name;
					arry_serv[x]=serv;
					total[x] = price*serv;
					cout << "Total Menu Price   : " << total[x] << endl;
					sum = sum + total[x];
					cout << "---------------------------------------------------\n";
				}
				system("pause");
				while(loop == 'y' || loop == 'Y'){
					cin.ignore();
					system("cls");
					cout << "----------------------------------------------------\n";
					cout << "               Catering Order Cashier               \n";
					cout << "----------------------------------------------------\n";
					for(int x=0; x<menu; x++){
						cout << "\nItem- " << x+1 << endl;
						cout << "Menu Name          : " << m_name[x] << endl;
						cout << "Serving            : " << arry_serv[x] << " pcs\n";
						cout << "Total Menu Price   : " << total[x] << endl;
					}
					cout << "===================================================\n";
					cout << "Total Payment                  : " << sum << endl;
					disrep = sum/500000;
					discount = 0.02 * disrep * sum;
					total_all = sum-discount;
					cout << "Discount Repetition            : " << disrep << endl;
					cout << "Discount 2% (/500k)            : " << discount << endl;
					cout << "Total Payment After Discount   : " << total_all << endl;
					cout << "---------------------------------------------------\n";
					cout << "Money Paid : "; cin >> payment;
					if(payment >= total_all){
						payment = payment-total_all;
						cout << "Change : " << payment << endl;
						loop = 'N';
					}else{
						cout << "Your Paid is minus\n";
						system("pause");
					}
				}
				cout << "Input new order (y/n)? "; cin >> loop;
			}	
		}else{
			cout << "Login Failed!\n";
			cout << "Please input correct username & password\n" << "----------------------------------------\n";
		}
		cout << "Back to home (y/n) ? "; cin >> loop;
	}
	return 0;
}