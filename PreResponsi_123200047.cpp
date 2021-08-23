#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int choice;
char fileName[20], loop = 'y';

struct data{
	int itemNo, itemPrice, itemTotal;
	char itemName[22], category[20], supplier[22];
};

void wrong();
void output_header();
void output_body(data, int);
void menu();
void input_data();
	void input_new_data();
	void add_data();
	void show_data();
void searcing();
	void sequential_search();
	void binary_menu();
	void binary_search();
	void searching_header(string, int);
	void result_sort(string, data, int);
		void bubble_sort();
		void insertion_sort();
		void quick_sort();
			void quickSort(data *item, int low, int high);
void transaction();
void trasaction_header(string, int);
	void merge_join();
	void splitting();

int main(){
	while(loop == 'y' || loop == 'Y'){
		system("cls");
		menu();
		switch(choice){
			case 1:
			system("cls");
			input_data();
				if(choice==1){
					input_new_data();
				}else if(choice==2){
					add_data();
				}else if(choice==3){
					show_data();
				}else
					wrong();
				break;
			case 2:
			system("cls");
			searcing();
				if(choice==1){
					sequential_search();
				}else if(choice==2){
					system("cls");
					binary_menu();
					if(choice == 1){
						bubble_sort();
					}else if(choice == 2){
						insertion_sort();
					}else if(choice == 3){
						quick_sort();
					}else 
						wrong();
				}else
					wrong();
				break;
			case 3:
			system("cls");
			transaction();
				if(choice == 1){
					merge_join();
				}else if(choice == 2){
					splitting();
				}else
					wrong();
				break;
			case 4:
				return 0;
			default:
				wrong();
		}
		cout << "Back to menu (y/n)? : "; cin >> loop;
	}
	return 0;
}

void wrong(){
	cout << "\nWRONG INPUT!!\n";
	if(cin.fail()){
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "Please Input An Integer only\n";
	} 
}

void output_header(){
	cout << "====================================================================================================\n";
	cout << left;
	cout  << setw(4) << "NO";
	cout  << setw(6) << "CODE";
	cout  << setw(30) << "ITEM NAME";
	cout  << setw(20) << "CATEGORY";
	cout  << setw(10) << "PRICE";
	cout  << setw(8) << "TOTAL";
	cout  << "SUPPLIER" << endl;;
	cout << "====================================================================================================\n";
}

void output_body(data item, int i){
	cout << left;
	cout  << setw(4) << i;
	cout  << setw(6) << item.itemNo;
	cout  << setw(30) << item.itemName;
	cout  << setw(20) << item.category;
	cout  << setw(10) << item.itemPrice;
	cout  << setw(8) << item.itemTotal;
	cout  << item.supplier << endl;
}

void menu(){
	cout << "==========================\n";
	cout << "         M E N U\n";
	cout << "      1. Input data\n";
	cout << "      2. Searching\n";
	cout << "      3. Transaction\n";
	cout << "      4. Exit\n";
	cout << "==========================\n";
	cout << "         Choice : "; cin >> choice;
}

void input_data(){
	cout << "=========================\n";
	cout << "   MENU 1 - INPUT DATA   \n";
	cout << "   1. Input New Data\n";
	cout << "   2. Add Data\n";
	cout << "   3. Show Data\n";
	cout << "=========================\n";
	cout << " Choice? : "; cin >> choice;
}

void input_new_data(){
	int total;
	FILE *fp;
	data *item;

	cout << "==============================================================\n";
	cout << "  MENU 1 INPUT DATA - SUB MENU 1 : INPUT NEW DATA\n";
	cout << "==============================================================\n\n";
	cout << "\tInput File Name : "; cin >> fileName;

	fp = fopen(fileName, "wb");
	if(fp == NULL){
		cout << "\nFile Failed to Create\n" << endl;
	}else{
		cout << "\tCREATE FILE SUCCESS\n\tPLEASE INPUT THE DATA\n";
		cout << "\tHow many data ? : "; cin >> total;
		item = (data*)calloc(total, sizeof(data));

		for(int i=0;i<total;i++){
			cout << "\n\tItem Data - " << i+1 << endl;
			cout << "\tItem Code    : "; cin >> item[i].itemNo;
			cout << "\tItem Name    : "; cin.ignore(); cin.getline(item[i].itemName, 20);
			cout << "\tCategory     : "; cin.getline(item[i].category, 19);
			cout << "\n\t\tPrice      : "; cin >> item[i].itemPrice;
			cout << "\t\tTotal      : "; cin >> item[i].itemTotal;
			cout << "\t\tSupplier   : "; cin.ignore(); cin.getline(item[i].supplier, 20);
			fwrite(&item[i], sizeof(data),1,fp);
		}
	}
	cout << "______________________________________________________________\n\n";
	fclose(fp);
}

void add_data(){
	int total;
	FILE *fp;
	data *item;

	cout << "==============================================================\n";
	cout << "  MENU 1 INPUT DATA - SUB MENU 2 : ADD DATA\n";
	cout << "==============================================================\n\n";
	cout << "\tInput File Name : "; cin >> fileName;

	fp = fopen(fileName, "ab+");
	if(fp == NULL){
		cout << "\nFile Failed to Create\n" << endl;
	}else{
		cout << "\tCREATE FILE SUCCESS\n\tPLEASE INPUT THE DATA\n";
		cout << "\tHow many data ? : "; cin >> total;
		item = (data*)calloc(total, sizeof(data));

		for(int i=0;i<total;i++){
			cout << "\n\tItem Data - " << i+1 << endl;
			cout << "\tItem Code    : "; cin >> item[i].itemNo;
			cout << "\tItem Name    : "; cin.ignore(); cin.getline(item[i].itemName, 20);
			cout << "\tCategory     : "; cin.getline(item[i].category, 19);
			cout << "\n\t\tPrice      : "; cin >> item[i].itemPrice;
			cout << "\t\tTotal      : "; cin >> item[i].itemTotal;
			cout << "\t\tSupplier   : "; cin.ignore(); cin.getline(item[i].supplier, 20);
			fwrite(&item[i], sizeof(data),1,fp);
		}
	}
	cout << "______________________________________________________________\n\n";
	fclose(fp);
}

void show_data(){
	FILE *fp;
	data item;
	int i=1;

	cout << "==============================================================\n";
	cout << "  MENU 1 INPUT DATA - SUB MENU 3 : SHOW DATA\n";
	cout << "==============================================================\n\n";
	cout << "\tInput File Name : "; cin >> fileName;

	fp = fopen(fileName, "rb");
	if(fp == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		output_header();
		while(fread(&item, sizeof(data),1,fp)==1){
				output_body(item, i); i++;
		}
		cout << "____________________________________________________________________________________________________\n\n";
	}
	fclose(fp);
}

void searcing(){
	cout << "========================\n";
	cout << "   MENU 2 - SEARCING   \n";
	cout << "   1. Sequential Search\n";
	cout << "   2. Binary Search\n";
	cout << "========================\n";
	cout << " Choice? : "; cin >> choice;
}

void sequential_search(){
	int code, i=1;
	bool found=0;
	data item;
	FILE *fp;

	cout << "==============================================================\n";
	cout << "  MENU 2 SEARCHING - SUB MENU 1 : SEQUENTIAL SEARCH\n";
	cout << "==============================================================\n\n";
	cout << "\tInput File Name : "; cin >> fileName;
	fp = fopen(fileName, "rb");
	if(fp == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		cout << "\tREAD FILE SUCCESS\n\tSEARCH THE DATA\n";
		cout << "\tInput item code : "; cin >> code;
		while(fread(&item, sizeof(data),1,fp)==1){
			if(item.itemNo==code){
				found = 1;
				break;
			}
		}
		if(found){
			output_header();
			output_body(item, i);
		}
		cout << "____________________________________________________________________________________________________\n\n";
	}
	fclose(fp);
}

void searching_header(string title, int n){
	cout << "================================================================================\n";
	cout << "    MENU 2 SEARCHING - SUB MENU 2 : "<< "( " << n << ". " << title << " ) BINARY SEARCH\n";
	cout << "================================================================================\n";
}

void binary_menu(){
	cout << "======================================\n";
	cout << "  MENU SEARCHING - BINARY SEARCH\n";
	cout << "======================================\n";
	cout << "Sorting Menu Options :\n";
	cout << "  1. Bubble Sort\n";
	cout << "  2. Insertion Sort\n";
	cout << "  3. Quick Sort\n";
	cout << "======================================\n";
	cout << "Input the options : "; cin >> choice;
}

void result_sort(string name, data *item, int a){
		FILE *fp;
		cout << "   Save the result of sorting with filename? : "; cin >> fileName;
		fp = fopen(fileName, "wb");
		if(fp == NULL){
		cout << "\nFile Failed to Create\n" << endl;
		}else{
			cout << "\n\nTHE RESULT OF " << name << endl;
			int no=1;
			output_header();
			for(int i = 0; i<a;i++){
				output_body(item[i], no); no++;
				fwrite(&item[i], sizeof(data),1,fp);
			}
		cout << "____________________________________________________________________________________________________\n\n";
		}
		fclose(fp);
		binary_search();
}

void bubble_sort(){
	FILE *fp;
	data *item, temp;
	bool check = 0;
	searching_header("BUBBLE SORT", 1);
	cout << "   Input filename to be sorted : "; cin >> fileName;
	fp = fopen(fileName, "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(data);
	item = (data*)calloc(a, sizeof(data));
	rewind(fp);

	if(fp == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		check = 1;
		for(int i=0;i<a;i++){
			fread(&item[i], sizeof(data),1,fp);
		}
		fclose(fp);
		//bubble sort porcess start
		for(int i=0;i<a-1;i++){
			for(int j=0;j<a-i-1;j++){
				if(item[j].itemNo>item[j+1].itemNo){
					temp=item[j];
					item[j]=item[j+1];
					item[j+1]=temp;
				}
			}
		}
	}
	
	if(check){
		result_sort("BUBBLE SORT", item, a);
	}
}

void insertion_sort(){
	FILE *fp;
	data *item, temp;
	bool check = 0;
	searching_header("INSERTION SORT", 2);
	cout << "   Input filename to be sorted : "; cin >> fileName;
	fp = fopen(fileName, "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(data), j;
	item = (data*)calloc(a, sizeof(data));
	rewind(fp);

	if(fp == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		check = 1;
		for(int i=0;i<a;i++){
			fread(&item[i], sizeof(data),1,fp);
		}
		fclose(fp);
		//Insertion process
		for(int i=1;i<a;i++){
			temp = item[i];
			j = i-1;
				
			while(j >= 0 && item[j].itemNo > temp.itemNo){
				item[j+1]=item[j];
				j = j-1;
			}
			item[j+1]=temp;
		}	
	}

	if(check){
		result_sort("INSERTION SORT", item, a);
	}
}

void quick_sort(){
	FILE *fp;
	data *item;
	bool check = 0;
	searching_header("QUICK SORT", 3);
	cout << "   Input filename to be sorted : "; cin >> fileName;
	fp = fopen(fileName, "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(data);
	item = (data*)calloc(a, sizeof(data));
	rewind(fp);

	if(fp == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		check = 1;
		for(int i=0;i<a;i++){
			fread(&item[i], sizeof(data),1,fp);
		}
		fclose(fp);
		//Quick Sort Process
		quickSort(item, 0, a-1);
	}
	if(check){
		result_sort("QUICK SORT", item, a);
	}
}

void quickSort(data *item, int low, int high){
	data temp, pivot;
    int i = low;
    int j = high;
    pivot = item[(i + j) / 2];

    while (i <= j){
	    while (item[i].itemNo < pivot.itemNo)
	        i++;
	    while (item[j].itemNo > pivot.itemNo)
	        j--;
	    if (i <= j){
	        temp = item[i];
	        item[i] = item[j];
	        item[j] = temp;
	        i++;
	        j--;
	    }
	}

	if (j > low){
        quickSort(item, low, j);
    }
    if (i < high){
        quickSort(item, i, high);
    }
}

void binary_search(){
	FILE *fp;
	data *item;
	bool check = 0;
	int s, e;

	cout << "   SEARCHING USE BINARY SEARCH\n";
	cout << "   Input filename (the result of sorting) : "; cin >> fileName;
	fp = fopen(fileName, "rb");
	fseek(fp,0,SEEK_END);
	int a = ftell(fp)/sizeof(data), code;
	item = (data*)calloc(a, sizeof(data));
	rewind(fp);
	if(fp == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		for(int i=0;i<a;i++){
			fread(&item[i], sizeof(data),1,fp);
		}
		s=0; e=a-1;
		cout << "\n   SEARCHING PROCESS\n";
		cout << "   Input item code to be search : "; cin >> code;
		while(s<=a && !check){
			int mid = s + (e-1)/2;
			if(mid>=a){
				mid = a-1;
			}
			if(item[mid].itemNo == code){
				check=1;
				cout << "\nDATA FOUND\n";
				output_header();
				cout << left;
				cout  << setw(4) << 1;
				cout  << setw(6) << item[mid].itemNo;
				cout  << setw(30) << item[mid].itemName;
				cout  << setw(20) << item[mid].category;
				cout  << setw(10) << item[mid].itemPrice;
				cout  << setw(8) << item[mid].itemTotal;
				cout  << item[mid].supplier << endl;;
				cout << "____________________________________________________________________________________________________\n\n";
			}
			if(item[mid].itemNo < code){
				s=mid+1;
			}else{
				e=mid-1;
			}
		}
		if(!check){
			cout << "\n DATA NOT FOUND !!!\n";
		}
	}
	fclose(fp);
}

void transaction(){
	cout << "========================\n";
	cout << "   MENU 3 - TRANSACTION   \n";
	cout << "   1. Join Merge\n";
	cout << "   2. Splitting\n";
	cout << "========================\n";
	cout << " Choice? : "; cin >> choice;
}

void transaction_header(string title, int n){
	cout << "================================================================================\n";
	cout << "    MENU 3 TRANSACTION - SUB MENU "<< n << " : " << title << endl;
	cout << "================================================================================\n";
}

void merge_join(){
	data item;
	char fileName1[20], fileName2[20], fileName3[20];
	FILE *fp1, *fp2, *fp3;
	transaction_header("JOIN MERGE", 1); cout<<endl<<endl;
	cout << "\tJOIN MERGE\n";
	cout << "\tMERGING 2 FILE\n";
	cout << "\tTransaction Result File Name? : "; cin >> fileName1;
	cout << "\tTRANSACTION PREPARATION\n\n";
	cout << "\tInput File Name Master 1     : "; cin >> fileName2; cout << endl;
	cout << "\tInput File Name Master 2     : "; cin >> fileName3; cout << endl;
	cout << "\tPROCESS MERGING 2 FILE\n";

	fp1 = fopen(fileName1, "wb");
	fp2 = fopen(fileName2, "rb");
	fp3 = fopen(fileName3, "rb");
	if(fp1==NULL || fp2==NULL || fp3==NULL){
		cout << "\nFile tidak dapat diciptakan" << endl;
	}else{
		while(fread(&item, sizeof(data),1,fp2)==1){
			fwrite(&item, sizeof(data),1,fp1);
		}
		while(fread(&item, sizeof(data),1,fp3)==1){
			fwrite(&item, sizeof(data),1,fp1);
		}
	}
	fclose(fp1); fclose(fp2); fclose(fp3);

	cout << "\tSHOW THE RESULT OF MERGING\n";
	cout << "\tFILE MERGE " << fileName2 << " AND " << fileName3 << endl;

	fp1 = fopen(fileName1, "rb");
	if(fp1 == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		int i=1;
		output_header();
		while(fread(&item, sizeof(data),1,fp1)==1){
				output_body(item, i); i++;
		}
		cout << "____________________________________________________________________________________________________\n\n";
	}
	fclose(fp1);
}

void splitting(){
	data item;
	int split, i=1;
	char fileName1[20], fileName2[20], fileName3[20];
	FILE *fp1, *fp2, *fp3;
	transaction_header("SPLITTING", 2); cout<<endl<<endl;
	cout << "\tSPLITTING TRANSACTION\n";
	cout << "\tSPLIT INTO 2 FILE\n";
	cout << "\tFile Master Name? : "; cin >> fileName1;
	cout << "\tTRANSACTION PREPARATION\n\n";
	cout << "\tInput File Name Result 1     : "; cin >> fileName2; cout << endl;
	cout << "\tInput File Name Result 2     : "; cin >> fileName3; cout << endl;
	cout << "\tPROCESS SPLIT 2 FILE\n";
	cout << "\tInput Split Indicator : "; cin >> split;
	fp1 = fopen(fileName1, "rb");
	fp2 = fopen(fileName2, "wb");
	fp3 = fopen(fileName3, "wb");
	if(fp1==NULL || fp2==NULL || fp3==NULL){
		cout << "\nFile tidak dapat diciptakan" << endl;
	}else{
		while(fread(&item, sizeof(data),1,fp1)==1){
			if(item.itemTotal <= split){
				fwrite(&item, sizeof(data),1,fp2);
			}else{
				fwrite(&item, sizeof(data),1,fp3);
			}
		}
	}
	fclose(fp1); fclose(fp2); fclose(fp3);

	cout << "\tSHOW THE RESULT OF SPLITTING\n";
	cout << "\tFILE STOCK ITEM WITH TOTAL <= " << split << endl;
	fp1 = fopen(fileName2, "rb");
	if(fp1 == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		output_header();
		while(fread(&item, sizeof(data),1,fp1)==1){
				output_body(item, i); i++;
		}
		cout << "____________________________________________________________________________________________________\n\n";
	}
	fclose(fp1);
	cout << "\n\tFILE STOCK ITEM WITH TOTAL > " << split << endl;
	fp1 = fopen(fileName3, "rb");
	if(fp1 == NULL){
		cout << "\nFile Failed to Read\n" << endl;
	}else{
		i = 1;
		output_header();
		while(fread(&item, sizeof(data),1,fp1)==1){
				output_body(item, i); i++;
		}
		cout << "____________________________________________________________________________________________________\n\n";
	}
	fclose(fp1);
}