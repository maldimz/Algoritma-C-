#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef struct {
	int id;
	char menu[50];
	char category[30];
  	int price;
}master;

master data[14];

char filename[30], loop  = 'y';

void sorting_data();
void searching_data();
void merge(master *data, int l, int m, int r);
void mergeSort(master *data, int l, int r);

int main(){
	int i=0, action;
	FILE *fp;
	
	cout << "File Name\t= "; cin >> filename;
	cout << endl;
	fp = fopen(filename, "rb");
	if(fp == NULL){
		cout << "\nFile Failed" << endl;
	}else{
		while(fread(&data[i], sizeof(data[i]),1,fp) && i<14){
			i++;
		}
		fclose(fp);
		while(loop == 'y'){
			i=0;
			for(int k=1;k<=65;k++){ cout << "=";} cout << endl;
			for(int k=1;k<=27;k++){ cout << " ";}; cout << "MENU LIST"<<endl;
			for(int k=1;k<=65;k++){ cout << "=";} cout << endl;
			cout << left;
			cout << setw(4) << "N0";
			cout << setw(6) << "ID";
			cout << setw(30) << "MENU";
			cout << setw(15) << "CATEGORY";
			cout << "PRICE\n";
			for(int k=1;k<=65;k++){ cout << "=";} cout << endl;

			while(i<14)
			{
					cout << setw(4) << i+1;
					cout << setw(6) << data[i].id;
					cout << setw(30) << data[i].menu;
					cout << setw(15) << data[i].category;
					cout << data[i].price << endl;
					i++;
			}
			for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
			for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
			cout << "\t1. Sorting The Menu List\n";
			cout << "\t2. Searching The Menu ID\n\n";
			for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
			cout << "\tSelect Action (1/2) : "; cin >> action;
			switch(action){
				case 1:
					sorting_data();
				break;
				case 2:
					searching_data();
				break;
				default:
					cout << " \nWRONG INPUT . . . \n";
					if(cin.fail()){
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "Please Input An Integer only\n\n";
					} 
				break;
			}
			cout << "\tBack To Menu (y/n) ? : "; cin >> loop;
			system("cls");
		}
	}
	return 0;
}

void sorting_data(){
	FILE *fp;
	master temp[14];

	for(int i=0;i<14;i++){
		temp[i]=data[i];
	}

	cout << "Filename of sorted data? : "; cin >> filename;
	mergeSort(temp, 0, 14-1);
	cout << "\n\nSORTING RESULT\n";
	for(int k=1;k<=65;k++){ cout << "=";} cout << endl;
		cout << left;
		cout << setw(4) << "N0";
		cout << setw(6) << "ID";
		cout << setw(30) << "MENU";
		cout << setw(15) << "CATEGORY";
		cout << "PRICE\n";
	for(int k=1;k<=65;k++){ cout << "=";} cout << endl;
	for(int i=0;i<14;i++){
		cout << setw(4) << i+1;
		cout << setw(6) << temp[i].id;
		cout << setw(30) << temp[i].menu;
		cout << setw(15) << temp[i].category;
		cout << temp[i].price << endl << endl;
	}
	for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
	for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
	fp = fopen(filename, "wb");
	if(fp == NULL){
		cout << "\nFile Failed" << endl;
	}else{
		for(int i=0;i<14;i++){
			fwrite(&temp[i], sizeof(temp[i]),1,fp);
		}
	}
	fclose(fp);
}

void searching_data(){
	int search;
	bool found = false;
	cout << "\tInput Menu ID : "; cin >> search;
	cout << "\n\nSEARCHING RESULTS : \n";
	for(int k=1;k<=65;k++){ cout << "=";} cout << endl;
		cout << left;
		cout << setw(4) << "N0";
		cout << setw(6) << "ID";
		cout << setw(30) << "MENU";
		cout << setw(15) << "CATEGORY";
		cout << "PRICE\n";
	for(int k=1;k<=65;k++){ cout << "=";} cout << endl;
	for(int i=0;i<14;i++){
		if(data[i].id==search){
			found = true;
			cout << setw(4) << 1;
			cout << setw(6) << data[i].id;
			cout << setw(30) << data[i].menu;
			cout << setw(15) << data[i].category;
			cout << data[i].price << endl;
			break;
		}
	}
	for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
	for(int k=1;k<=65;k++){ cout << "_";} cout << endl;
	if(!found){
		cout << " DATA NOT FOUND . . . \n\n";
	}
}

void merge(master *data, int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;

	master L[n1], R[n2]; //create temp

	for(int i=0; i<n1;i++){ //input data into temp
		L[i]=data[l+i];
	}
	for(int j=0; j<n2; j++){
		R[j]=data[m+1+j];
	}

	//merge temp into array l .. r

	int i=0; //first index 
	int j=0;  //second index
	int k=l; //index merged

	while(i<n1 && j <n2){
		if(L[i].id <= R[j].id){
			data[k]=L[i];
			i++;
		}
		else{
			data[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		data[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		data[k]=R[j];
		j++;
		k++;
	}
}

void mergeSort(master *data, int l, int r){
	if(l>=r){
		return;
	}
		int m =(l+(r-1))/2;
		mergeSort(data,l,m);
		mergeSort(data,m+1,r);
		merge(data,l,m,r);	
}