#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

int x, id, result=0, sum, que;
char fileName[20], loop='y';
string uname, pw;

struct ordered{
	int orderId, amount;
	float total;
};
struct order{
	int orderId, tableId, sum, orderTotal;
	char name[20];
	ordered orderedData[10];
};	
struct menuData{
	int menuID;
	char menuName[20];
	float menuPrice;
};

menuData *searchPrice;
string table[5][5]={
	{"1","2","3","4","5"},
	{"6","7","8","9","10"},
	{"11","12","13","14","15"},
	{"16","17","18","19","20"},
	{"21","22","23","24","25"}
};

void header1();
void menu1();
void menu();//desain menu
void header();//header
void inputOrder(); //tambah order
void outputOrder(string s); // output
void viewTable();
void inputMenu();
void outputMenu();
void editMenu();
void placeOrder();
void updateTable();
void searchTable(int x);
void getTable();
void resetTable(int t);
void searchOrder();
void search_price();
void login();
bool checkMenu(int id);
void invalid();
void sortMenu();
void quickSort(menuData *item, int low, int high);
void bubbleSort(int *id, int high);
bool checkPay(order data);
string convertToString(char* a);
bool checkTable(int id);
void showData();
void sortMerging();
void quickSort2(order *item, int low, int high);

//pesan jika di antar masuk ke data antar

int main(){
	getTable();
	while(loop=='y'||loop=='Y'){
		system("cls");
		header1();
		menu1();
		switch(x){
			case 1:
				system("cls");
				outputMenu();
				inputOrder();
			break;
			case 2:
				header1();
				viewTable();
			break;
			case 3:
				header1();
				placeOrder();
			break;
			case 4:
				header1();
				cin.ignore();
				searchOrder();
			break;
			case 5:
				login();
			break;
			case 6:
				showData();
			break;
			case 7:
				cout << "\nThank You for Your Visit!\nSee you again :))" << endl;
				return 0;
				break;
			default:
				invalid();
			break;
		}
		cout << "\nBack to Menu? (y/n) : "; cin >> loop;
		
	}
	return 0;
}

void header1(){
	system("cls");
	cout << "============================================================" << endl; //60
	cout << "                    SEVEN 7 RESTAURANT" << endl;
	cout << "============================================================" << endl; //60
}
void menu1 (){
	cout << "1. Input Order" << endl;
	cout << "2. Show Table" << endl;
	cout << "3. Place Order" << endl;
	cout << "4. Search Order" << endl;
	cout << "5. Edit Menu" << endl;
	cout << "6. Show Data" << endl;
	cout << "7. Exit" << endl;
	cout << "____________________________________________________________" << endl; //60
	cout << "Choice : "; cin >> x;
}
void showData(){
	header1();
	cout << "1. Show Processing Order" << endl;
	cout << "2. Show Completed Order" << endl;
	cout << "3. Show All Order" << endl;
	cout << "____________________________________________________________" << endl; //60
	cout << "Choice : "; cin >> x;
	if(x==1){
		system("cls");
		cout << "============================================================" << endl; //60
		cout << "                     Processing Order" << endl;
		cout << "============================================================" << endl; //60
		outputOrder("orderData");
	}else if(x==2){
		system("cls");
		cout << "============================================================" << endl; //60
		cout << "                      Completed Order" << endl;
		cout << "============================================================" << endl; //60
		outputOrder("placeData");
	}else if(x==3){
		system("cls");
		sortMerging();
		cout << "============================================================" << endl; //60
		cout << "                        Recap Order" << endl;
		cout << "============================================================" << endl; //60
		outputOrder("recapData");
	}else{
		invalid();
	}
}
void inputOrder(){
	bool found=0;
	order data;
	ifstream output;
	ofstream input;
	output.open("orderId.txt");
	if(output.is_open()){
		output >> id;
	}else{
		id=0;
	}
	search_price();
	output.close();
	cout << "INPUT :\n";
	data.orderTotal=0;
	cout << "Order ID : " << ++id << endl;
	data.orderId=id;
	cout << "Table ID : "; cin >> data.tableId; cin.ignore();
	found = checkTable(data.tableId);
	if(found){
		cout << "Name     : "; cin.getline(data.name, 20);
		cout << "How many menu (max 10 item)? "; cin >> data.sum;
		for(int i=0; i<data.sum; i++){
			cout << "\n\tMenu Id : "; cin >> data.orderedData[i].orderId;
			cout << "\tAmount  : ";cin >> data.orderedData[i].amount;
			for(int j=0;j<sum;j++){
				if(data.orderedData[i].orderId== searchPrice[j].menuID){
					result=searchPrice[j].menuPrice;
					break;
				}
			}
			data.orderedData[i].total = data.orderedData[i].amount * result;
			data.orderTotal += data.orderedData[i].total;
		}
		FILE *fp;
		fp = fopen("orderData", "ab+");
		if(fp == NULL){
			cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
		}else{
			searchTable(data.tableId);
			fwrite(&data, sizeof(order),1,fp);
		}	
		fclose(fp);
		input.open("orderId.txt", ios::out);
		input << id;
		input.close();
	}else{
		cout << "\nTable is being Used!" << endl;
	}
}
void outputOrder(string s){
	order data;
	int max=s.length();
	for(int i=0;i<max;i++){
		fileName[i]=s[i];
	}
	//cout << "Get Data : "; cin >> fileName;
	FILE *fp;
	fp = fopen(fileName, "rb");
	if(fp == NULL){
		cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
	}else{
		while(fread(&data, sizeof(order),1,fp)==1){
			cout << "____________________________________________________________" << endl; //60
			cout << "Name     : " << data.name << endl;
			cout << "Order ID : " << data.orderId << endl;
			cout << "Table ID : " << data.tableId << endl;
			cout << "Order Number : " << data.sum << endl;
			for(int i=0; i<data.sum; i++){
				cout << "\n\tMenu Id : " << data.orderedData[i].orderId << endl;
				cout << "\tAmount  : " << data.orderedData[i].amount << endl;
			}
			cout << "\n\tTotal : " << data.orderTotal << endl;
		}
	}	
	fclose(fp);
}
void viewTable(){
	ifstream output;
	output.open("table.txt");
	if(output.is_open()){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				output >> table[i][j];
			}
		}
		
	}
	output.close();
	cout << "||Cashier|\n         |\n\n";
	for(int i=0;i<5;i++){
		cout << "|";
		cout << left;
		for(int j=0;j<5;j++){
			cout << "|" << setw(4) << table[i][j];
		}cout << "||" << endl;
	}
}
void inputMenu(){
	menuData data;
	FILE *fp;
	bool found=0;
	ofstream input;
	
	fp = fopen("menuData", "ab+");
	if(fp == NULL){
		cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
	}else{
		while(loop=='y' || loop=='Y'){
			cout << "MenuID    : "; cin >> id;
			found=checkMenu(id);
			if(found){
				data.menuID = id;
				cout << "Menu Name : ";cin.ignore(); cin.getline(data.menuName, 19);
				cout << "Price     : "; cin >> data.menuPrice;
				fwrite(&data, sizeof(menuData),1,fp);
				cout << "Add more Menu? : "; cin >> loop;
				cin.ignore();
				input.open("menuId.txt", ios::app);
				input << id << endl;
				input.close();
				cout << endl;
			}
		}
	}	
	fclose(fp);
}
void outputMenu(){
	menuData data;
	FILE *fp;
	fp = fopen("menuData", "rb");
	if(fp == NULL){
		cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
	}else{
		cout << "============================================================" << endl; //60
		cout << "                           MENU" << endl;
		cout << "============================================================" << endl; //60
		cout << left;
		cout << setw(10) << " ";
		cout << setw(9) << "ID";
		cout << setw(20) << "NAME";
		cout << "PRICE" << endl;
		cout << "============================================================" << endl; //60
		while(fread(&data, sizeof(menuData),1,fp)==1){
			cout << setw(10) << " ";
			cout << setw(9) << data.menuID;
			cout << setw(20) << data.menuName;
			cout << data.menuPrice << endl;
		}
		cout << "============================================================" << endl; //60
	}	
	fclose(fp);
}
void editMenu(){
	menuData *data;
	FILE *fp;
	int search;
	bool found=0;
	
	fp = fopen("menuData", "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(menuData);
	data = (menuData*)calloc(a, sizeof(menuData));
	rewind(fp);
	
	if(fp == NULL){
		cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
	}else{
		for(int i=0; i<a; i++){
			fread(&data[i], sizeof(menuData),1,fp);
		}
	}	
	fclose(fp);
	
	cout << "Input Menu ID : "; cin >> search;
	for(int i=0; i<a; i++){
		if(data[i].menuID == search){
			found = 1;
			cout << "MenuID    : " << search << endl; cin.ignore();
			cout << "Menu Name : "; cin.getline(data[i].menuName, 19);
			cout << "Price     : "; cin >> data[i].menuPrice;
			break;
		}
	}
	if(found){
		fp = fopen("menuData", "wb");
		if(fp == NULL){
			cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
		}else{
			for(int i=0; i<a; i++){
				fwrite(&data[i], sizeof(menuData),1,fp);
			}
		}	
		fclose(fp);
		cout << "\nMenu Edited Succesfully" << endl;
	}else{
		cout << "\nData Not FOUND!!!" << endl;
	}
}
void placeOrder(){
	int placeId;
	bool found=0, check=0;
	order ord;
	FILE *fp1, *fp2, *fp3;
	 
	fp1 = fopen("orderData", "rb");
	fp2 = fopen("placeData", "ab+");
	fp3 = fopen("temp", "wb");
	if(fp1==NULL || fp2==NULL){
		cout << "\nInvalid filename" << endl;
	}else{
		cout << "Input your Order ID : "; cin >> placeId;
		while(fread(&ord, sizeof(order),1,fp1)==1){
			if(ord.orderId==placeId){
				check=checkPay(ord);
				found = 1;
			}
		}
		rewind(fp1);
		if(check){
			while(fread(&ord, sizeof(order),1,fp1)==1){
				if(ord.orderId==placeId){
					fwrite(&ord, sizeof(order),1,fp2);
					resetTable(ord.tableId);
				}else{
					fwrite(&ord, sizeof(order),1,fp3);
				}
			}
		}
		
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	
	if(found && check){
		fp1 = fopen("temp", "rb");
		fp2 = fopen("orderData", "wb");
		if(fp1==NULL || fp2==NULL){
			cout << "\nInvalid filename" << endl;
		}else{
			while(fread(&ord, sizeof(order),1,fp1)==1){
				fwrite(&ord, sizeof(order),1,fp2);
			}
		}
		fclose(fp1);
		fclose(fp2);
	}else if(!found){
		cout << "\nData not FOUND!!!" << endl;
	}
}
void updateTable(){
	ofstream input;
	input.open("table.txt", ios::out);
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			input << table[i][j] << endl;
		}
	}
	input.close();
}
void searchTable(int x){
	string search = to_string(x);
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(table[i][j]==search){
				table[i][j]="x";
			}
		}
	}
	updateTable();
}
void getTable(){
	ifstream output;
	output.open("table.txt");
	if(output.is_open()){
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				output >> table[i][j];
			}
		}
	}
	output.close();
}
void resetTable(int t){
	int i, j;
	string str = to_string(t);
	if(t>=1 && t<=5){
		i = 0;
		for(int k=0;k<t;k++){
			j=k;
		}
	}else if(t>=6 && t<=10){
		i = 1;
		for(int k=5;k<t;k++){
			j = k-5;
		}
	}else if(t>=11 && t<=15){
		i = 2;
		for(int k=10;k<t;k++){
			j = k-10;
		}
	}else if(t>=16 && t<=20){
		i = 3;
		for(int k=15;k<t;k++){
			j = k-15;
		}
	}else if(t>=21 && t<=25){
		i = 4;
		for(int k=20;k<t;k++){
			j = k-20;
		}
	}
	table[i][j] = str;
	updateTable();
}
void searchOrder(){
	FILE *fp;
	order *ord;
	
	fp = fopen("orderData", "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(order), length, check=0, j, i;
	char nameSearch[20];
	
	ord = (order*)calloc(a, sizeof(order));
	rewind(fp);
	if(fp==NULL){
		cout << "\nFile Failed to Open" << endl;
	}else{
		cout << "\nSearch Order by Name : "; cin.getline(nameSearch, 20);
		length = strlen(nameSearch);
		for(i=0;i<a;i++){
			fread(&ord[i], sizeof(order),1,fp);
			check=0, j=0;
			if(ord[i].name[j]==nameSearch[j]){
				check++;
				for(j=1;j<length;j++){
					if(ord[i].name[j]==nameSearch[j]){
						check++;
					}
				}
			}
			if(check==length){
				break;
			}
		}
	}
	if(check==length){
		cout << "Name         : " << ord[i].name << endl;
		cout << "Order ID     : " << ord[i].orderId << endl;
		cout << "Table ID     : " << ord[i].tableId << endl;
		cout << "Order Number : " << ord[i].sum << endl;
		for(int k=0; k<ord[i].sum; k++){
			cout << "\n\tMenu Id : " << ord[i].orderedData[k].orderId << endl;
			cout << "\tAmount  : " << ord[i].orderedData[k].amount << endl;
		}
		cout << "\nTotal : " << ord[i].orderTotal << endl << endl;
		}else{
			cout << "\nOrder Not FOUND!!!" << endl;
		}
	fclose(fp);
}
void delMenu(){
	FILE *fp1, *fp2;
	menuData menu;
	bool found=0;
	int id;
	
	ifstream output;
	ofstream input;
	output.open("menuId.txt");
	input.open("temp2.txt", ios::out);
	
	fp1 = fopen("menuData", "rb");
	fp2 = fopen("temp", "wb");
	
	if(fp1==NULL||fp2==NULL){
		cout << "\nFailed" << endl;
	}else{
		int search;
		cout << "Delete Menu ID : "; cin >> search;
		while(fread(&menu, sizeof(menuData),1,fp1)==1){
			output >> id;
			if(menu.menuID!=search){
				fwrite(&menu, sizeof(menuData),1,fp2);
				input << id << endl;
			}else{
				found = 1;
			}
		}
		output.close();
		input.close();
		fclose(fp1);
		fclose(fp2);
		if(found){
			fp1 = fopen("menuData", "wb");
			fp2 = fopen("temp", "rb");
			output.open("temp2.txt");
			input.open("menuId.txt", ios::out);
			while(fread(&menu, sizeof(menuData),1,fp2)==1){
				output >> id;
				input << id << endl;
				fwrite(&menu, sizeof(menuData),1,fp1);
			}
			fclose(fp1);
			fclose(fp2);
			output.close();
			input.close();
			cout << "\nDelete Menu Completed" << endl;
		}else{
			cout << "\nData Not FOUND!!!" << endl;
		}
	}
}
void login(){
	char loop3='y';
	system("cls");
	cout << "============================================================" << endl; //60
	cout << "                      ADMINISTRATION" << endl;
	cout << "============================================================" << endl; //60
	if(uname!="admin" || pw!="admin"){
		cout << "Username : "; cin >> uname;
		cout << "Password : "; cin >> pw;
	}
	if(uname=="admin" && pw=="admin"){
		while(loop3=='y'||loop3=='Y'){
			system("cls");
			cout << "============================================================" << endl; //60
			cout << "                      ADMINISTRATION" << endl;
			outputMenu();
			cout << "____________________________________________________________" << endl; //60
			cout << "1. Add Menu" << endl;
			cout << "2. Delete Menu" << endl;
			cout << "3. Edit Menu" << endl;
			cout << "4. Sorting Menu" << endl;
			cout << "5. Log Out" << endl;
			cout << "____________________________________________________________" << endl; //60
			cout << "Choice : "; cin >> x;
			if(x==1){
				cin.ignore();
				inputMenu();
			}else if(x==2){
				delMenu();
				system("pause");
			}else if(x==3){
				editMenu();
				system("pause");
			}else if(x==4){
				sortMenu();
				system("pause");
			}else if(x==5){
				uname = " ";
				pw = " ";
				loop3='n';
			}else{
				invalid();
				cout << "\nBack to Edit Menu? (y/n) : "; cin >> loop3;
			}
		}
	}
}
void search_price(){
	FILE *fp;
	fp = fopen("menuData", "rb");
	fseek(fp,0,SEEK_END);
	sum = ftell(fp)/sizeof(menuData);
	searchPrice = (menuData*)calloc(sum, sizeof(menuData));
	rewind(fp);
	if(fp == NULL){
		cout << "\nFile Error" << endl; //pesan jika file gagal dibuat
	}else{
		for(int i=0; i<sum; i++){
			fread(&searchPrice[i], sizeof(menuData),1,fp);
		}
	}	
	fclose(fp);
}
bool checkMenu(int id){
	int num;
	bool check=1;
	ifstream output;
	output.open("menuId.txt");

	if(id<=1){
		check=0;
		cout << "\nPlease Input The Right ID" << endl;
	}else{
		if(output.is_open()){
			while(output.eof()==0){
				output >> num;
				if(num==id){
					check=0;
					cout << "\nID is already exist" << endl;
					break;
				}
			}
		}
	}
	output.close();
	return check;
}
void invalid(){
	cout << "\nWrong Input" << endl;
	if(cin.fail()){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "\nPlese Input Integer Only!" << endl;
	}
}
void sortMenu(){
	FILE *fp;
	menuData *mnuData;
	int id[100];
	
	ifstream output;
	ofstream input;
	
	fp = fopen("menuData", "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(menuData);
	mnuData = (menuData*)calloc(a,sizeof(menuData));
	rewind(fp);
	output.open("menuId.txt");
	
	if(fp==NULL || !output){
		cout << "\nFile Not Found" << endl;		
	}else{
		for(int i=0;i<a;i++){
			fread(&mnuData[i], sizeof(menuData),1,fp);
			output >> id[i];
		}
	}
	fclose(fp);
	output.close();
	quickSort(mnuData, 0, a-1);
	bubbleSort(id, a-1);
	
	fp = fopen("menuData", "wb");
	input.open("menuId.txt", ios::out);
	for(int i=0;i<a;i++){
		fwrite(&mnuData[i], sizeof(menuData),1,fp);
		input << id[i] << endl;
	}
	fclose(fp);
	input.close();
	cout << "\nSorting Successful" << endl;
}
void quickSort(menuData *item, int low, int high){
	menuData temp, pivot;
	int i = low;
	int j = high;
	pivot = item[(i+j)/2];
	while(i<=j){
		while(item[i].menuID < pivot.menuID)
			i++;
		while(item[j].menuID > pivot.menuID)
			j--;
		if(i<=j){
			temp = item[i];
			item[i] = item[j];
			item[j] = temp;
			i++; j--;
		}
	}
	if(j>low){
		quickSort(item, low, j);
	}
	if(i<high){
		quickSort(item, i, high);
	}
}
void bubbleSort(int *id, int high){
	int temp;
	for(int i=0;i<high;i++){
		for(int j=0;j<high-i;j++){
			if(id[j] > id[j+1]){
				temp = id[j];
				id[j] = id[j+1];
				id[j+1] = temp;
			}
		}
	}
}
bool checkPay(order data){
	bool check=0;
	int pay, index, change;
	char loop1='y';
	search_price();
	
	while(loop1=='y'||loop1=='Y'){
		system("cls");
		header1();
		cout << "Name      : " << data.name << endl;
		cout << "Order Id  : " << data.orderId << endl;
		cout << "No. Table : " << data.tableId << endl;
		cout << "------------------------------------------------------------" << endl; //60
		cout << "                           MENU" << endl;
		cout << "------------------------------------------------------------" << endl; //60
		cout << left;
		cout << setw(4) << "ID";
		cout << setw(20) << "NAME";
		cout << setw(10) << "AMOUNT";
		cout << "TOTAL" << endl;
		cout << "------------------------------------------------------------" << endl; //60
		for(int i=0;i<data.sum;i++){
			cout << setw(4) << data.orderedData[i].orderId;
			for(int j=0;j<sum;j++){
				if(data.orderedData[i].orderId==searchPrice[j].menuID){
					index = j;
				}
			}
			cout << setw(20) << searchPrice[index].menuName;
			cout << setw(10) << data.orderedData[i].amount;
			cout << data.orderedData[i].total << endl;;
		}
		cout << "------------------------------------------------------------" << endl; //60
		cout << "TOTAL COST : Rp " << data.orderTotal << endl;
		cout << "PAYMENT    : Rp "; cin >> pay;
		if(pay>=data.orderTotal){
			change = pay-data.orderTotal;
			cout << "CHANGE     : Rp " << change << endl;
			cout << "------------------------------------------------------------" << endl; //60
			cout << "\nPayment Successful" << endl;
			check=1;
			loop1 = 'n';
		}else{
			check=0;
			cout << "\nPayment does not fulfill the cost" << endl;
			cout << "\nTry Again? : "; cin >> loop1;
		}
	}
	return check;
}
string convertToString(char* a){
	int size=strlen(a);
	string s="";
	for(int i=0;i<size;i++){
		s = s+a[i];
	}
	return s;
}
bool checkTable(int id){
	bool check=0;
	string str=to_string(id);
	getTable();
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(str==table[i][j]){
				check=1;
			}
		}
	}
	return check;
}
void sortMerging(){
	FILE *fp1, *fp2;
	order *ord;
	int max,j=0;
	fp1 = fopen("orderData", "rb");
	fp2 = fopen("placeData", "rb");
	fseek(fp1,0,SEEK_END);
	int a = ftell(fp1)/sizeof(order);
	fseek(fp2,0,SEEK_END);
	int b = ftell(fp2)/sizeof(order);
	max = a+b;
	ord = (order*)calloc(max,sizeof(order));
	rewind(fp1);
	rewind(fp2);
	if(fp1==NULL || fp2==NULL){
		cout << "\nFile ERROR" << endl;
	}else{
		for(int i=0;i<a;i++){
			fread(&ord[j++],sizeof(order),1,fp1);
		}
		for(int i=0;i<b;i++){
			fread(&ord[j++],sizeof(order),1,fp2);
		}
		fclose(fp1);
		fclose(fp2);
		quickSort2(ord, 0, max-1);
		
		fp1 = fopen("recapData", "wb");
		for(int i=0;i<max;i++){
			fwrite(&ord[i],sizeof(order),1,fp1);
		}
		fclose(fp1);
		
	}
}
void quickSort2(order *item, int low, int high){
	order temp, pivot;
	int i = low;
	int j = high;
	pivot = item[(i+j)/2];
	while(i<=j){
		while(item[i].orderId < pivot.orderId)
			i++;
		while(item[j].orderId > pivot.orderId)
			j--;
		if(i<=j){
			temp = item[i];
			item[i] = item[j];
			item[j] = temp;
			i++; j--;
		}
	}
	if(j>low){
		quickSort2(item, low, j);
	}
	if(i<high){
		quickSort2(item, i, high);
	}
}
