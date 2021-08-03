#include <iostream>
using namespace  std;

int main()

{	char loop = 'y', loop1 = 'y', code, event_menu;
	int amount, order,code1, menu_code, price, paid, total, change, total_payment, sum;
	string user, pass, name, menu_name, event;
	float off, cut_off, after_cut_off;

	while(loop == 'y' || loop == 'Y'){
		system("cls");
		cout << "----------------------------------------------------\n";
		cout << "             Welcome to Family Catering             \n";
		cout << "----------------------------------------------------\n";
		cout << "Username : "; cin >> user;
		cout << "Password : "; cin >> pass;

		if(user == "admin" && pass == "admin"){
			while(loop1 == 'y'||loop1 == 'Y'){
				system("cls");

				cout << "----------------------------------------------------\n";
				cout << "               Catering Order Cashier               \n";
				cout << "----------------------------------------------------\n";
				cout << "Input Transaction Code  : "; cin >> code1;
				cout << "Input Customer Name     : ";
				cin.ignore(); getline(cin, name);
				cout << "Have Promo Code? (y/n)? : "; cin >> code;
				if(code == 'y' || code == 'Y'){
					do{
					cout << "Input Promo Code        : "; cin >> event;
						if (event == "PROMO10"){
						cout << " . . . Congratulation you get 10% off !!!" << endl; 
						}
						else{
						cout << " . . . Sorry the promo code not available" << endl;
						cout << "\nTry again (y/n)? "; cin >> event_menu;
						}
					}while(event_menu == 'y');
				}
			
		

				cout << "How many menu?          : "; cin >> order;
				cout << "----------------------------------------------------\n";

				for (int x = 1; x <= order; x++){
				cout << "-----------------------------------------------------\n\n";
				cout << "Item- " << x << endl;
				cout << "Menu Code                       : "; cin >> menu_code;
				cout << "Menu Name                       : "; cin.ignore(); getline (cin, menu_name);			
				cout << "How many servings?     : "; cin >> amount;
				cout << "Price per serving      : "; cin >> price;
				total = price*amount;
				cout << "Total Menu Price       : " << total << endl;
				total_payment += total;	
				if (amount > 10){
					cout << "----------------- CONGRATULATION!!! -----------------\n";
					cout << "you get discount 10% for buy more then 10 servings\n";
					cut_off = total * 0.1 ;
					off = total - cut_off;
					cout << "-----------------------------------------------------\n";
					cout << "Total Menu Price   : " << off;
					cout << endl;
					after_cut_off += off;
				}
			}	
				cout << "================================================\n";
				if (amount > 10){
			    cout << "total payment                   : " << after_cut_off << endl;
			    cout << "------------------------------------------------\n";
			    cout << "Money Paid        : "; cin >> paid;
			    change = paid - after_cut_off;
			    cout << "Change            : " << change << endl;
				} else {
			    cout << "total payment                   : " << total_payment << endl;
			    cout << "------------------------------------------------\n";
			    cout << "Money Paid        : "; cin >> paid;
			    change = paid - total_payment;
			    cout << "Change            : " << change << endl;
				}

				cout << "\n===================================================\n";
				if (event == "PROMO10"){
					sum=total_payment;
					cout << "Total Payment   : " << sum << endl;
					sum = sum * 0.9;
					cout << "After Discount  : " << sum << endl;
					cout << "---------------------------------------------------\n";
					cout << "Money Paid      : "; cin >> paid; 
					change = paid - sum;
				} else {
					sum=total_payment;
					cout << "Total Payment   : " << sum << endl;
					cout << "Money Paid      : "; cin >> paid; 
					change = paid - sum;
				}
				if(change < 0){
					cout << "Change          : " << change << endl;
				} else {
					cout << "Sorry your money is not enough\n";
					cout << "The amount      : " << change << endl;
				}
				cout << "\nInput new order (y/n)? "; cin >> loop1;	
			} 
		}else {
			cout << "---------------------------------------------------\n";
			cout << "Login Failed!\n";
			cout << "Please input correct username & password\n";
			cout << "---------------------------------------------------\n";
	}
}
	cout << "Back to home  (y/n)? "; cin >> loop;
	return 0;
}