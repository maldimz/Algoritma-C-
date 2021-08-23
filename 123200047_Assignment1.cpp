/* 
Akhmal Dimas Pratama
123200047 /Class H
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

string name[15],nim[15];
int check[15], a, x, k, choice, out_group, out_student;
char loop='n', input_group;

struct project{
	string name_project;
};

struct student{
	string name_student, number_student, group;
	project proj;
};
student stu[7][15];

void check_reset();
void title(string a, int z);
void title_main();
void line(string a, int c);
void wrong();
void menu();
void group_input();
void group_output();
void group_output_1();
void group_output_2();
void exit();

int main(){
	srand(15);

	name[0]= "Akhmal Dimas Pratama"; nim[0]="123200047";
	name[1]= "Maulana Daffa Ardiansyah"; nim[1]="123200130";
	name[2]= "Ichvan Rachmawan"; nim[2]="123200147";
	name[3]= "Rhyo Argasiwi"; nim[3]="123200059";
	name[4]= "Juan Azhar Adviseta Setiawan"; nim[4]="123200139";
	name[5]= "Haidarrachman Gustavian Rahardjo"; nim[5]="123200075";
	name[6]= "Alfa Aditya Wicaksana"; nim[6]="123200094";
	name[7]= "Qibran Idza Lafandzi"; nim[7]="123200141";
	name[8]= "Achmad Azril Mutawazin"; nim[8]="123200058";
	name[9]= "Rowang Pramudito"; nim[9]="123200098";
	name[10]= "Radivan Alan N."; nim[10]="123200072";
	name[11]= "Shafa' Tiara Tsabita Himawan"; nim[11]="123200052";
	name[12]= "Syafira Widiyanti"; nim[12]="123200057";
	name[13]= "Audrey Rosa"; nim[13]="123200172";
	name[14]= "Annisa Agusti Andini"; nim[14]="123200049";

	while(loop=='n'){
		title_main();
		cout << "Type y to start generate group . . .  input : "; cin >> loop;
		if(loop == 'y' || loop == 'Y'){
			system("pause");
		}else{
			loop='n';
			cout << "Wrong input\n";
			system("pause");
		}
	}
	
	while(loop == 'y' || loop=='Y'){
		x=0; k=0;
		check_reset();
		while(x<15){
			if(k>1 && x==14){
				k=2;
			}else if(k>1){
				k=0;
			}
			a=rand()%15;
			if(a != check[0] && a != check[1] && a != check[2] && a != check[3] && a != check[4] && 
			a != check[5] && a != check[6] && a != check[7] && a != check[8] && a != check[9] &&
			a != check[10] && a != check[11] && a != check[12] && a != check[13] && a != check[14]){
				check[x]= a;

				if(x >=0 && x<=1){
					stu[0][k].group="A";
					stu[0][k].name_student=name[a];
					stu[0][k].number_student=nim[a];
					stu[0][0].proj.name_project="-";
				}else if(x>1 && x<=3){
					stu[1][k].group="B";
					stu[1][k].name_student=name[a];
					stu[1][k].number_student=nim[a];
					stu[1][0].proj.name_project="-";
				}else if(x>3 && x<=5){
					stu[2][k].group="C";
					stu[2][k].name_student=name[a];
					stu[2][k].number_student=nim[a];
					stu[2][0].proj.name_project="-";
				}else if(x>5 && x<=7){
					stu[3][k].group="D";
					stu[3][k].name_student=name[a];
					stu[3][k].number_student=nim[a];
					stu[3][0].proj.name_project="-";
				}else if(x>7 && x<=9){
					stu[4][k].group="E";
					stu[4][k].name_student=name[a];
					stu[4][k].number_student=nim[a];
					stu[4][0].proj.name_project="-";
				}else if(x>9 && x<=11){
					stu[5][k].group="F";
					stu[5][k].name_student=name[a];
					stu[5][k].number_student=nim[a];
					stu[5][0].proj.name_project="-";
				}else if(x>11 && x<=14){
					stu[6][k].group="G";
					stu[6][k].name_student=name[a];
					stu[6][k].number_student=nim[a];
					stu[6][0].proj.name_project="-";
				}
				k++;
				x++;	
			}
		}
		title_main();
		for(int x=0;x<7;x++){
			cout << "Group - " << stu[x][0].group << endl;
			for(int y=0;y<3;y++){
				if(x==6){
					cout << " - " << stu[x][y].name_student << endl;
				}else if(x<6 && y<2){
					cout << " - " << stu[x][y].name_student << endl;
				}
			}cout << endl;
		}
		cout << "\nGenerate again y/n?"; cin >> loop;
	}
		cout << "Your group has been generated . . .\n";
		system("pause");	
	do{
		loop='y';
		menu();
		if(choice == 1){
			group_input();
		}else if(choice == 2){
			group_output();
			if(choice == 1){
				group_output_1();
			}else if(choice == 2){
				group_output_2();
			}else{
				if(cin.fail()){
					cout << "Please enter numbers only." << endl;
      				cin.clear();
      				cin.ignore(10000,'\n');
      				system("pause");
				}else{
					wrong();
				}
			}
		}else if(choice == 3){
			exit();
		}else{
			if(cin.fail()){
				cout << "Please enter numbers only." << endl;
      			cin.clear();
      			cin.ignore(10000,'\n');
      			system("pause");
			}else{
				wrong();
			}
		}
	}while(loop == 'y' || loop == 'Y');
}

void check_reset(){
	for(int b=0;b<15;b++){
		check[b]=-1;
	}
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
	title("RANDOM GROUP GENERATOR CLASS H", 50);
	line("=", 50); 
}

void line(string a, int c){
	for(int b=1; b<=c ; b++){
			cout << a;
		} cout << endl;
}

void wrong(){
	cout << "Wrong Input\n";
	cout << "Please input again\n";
	loop = 'y';
	system("pause");
}

void menu(){
	title_main();
	cout << "1. Input project title\n";
	cout << "2. Group check\n";
	cout << "3. Exit\n";
	cout << "Selection = "; cin >> choice;
}

void group_input(){
	title_main();
	cout << "Please input your group A/B/C/D/E/F/G/H\n";
	cout << "Input = "; cin >> input_group; cin.ignore();
	if(input_group=='A' || input_group=='a'){
		cout << "Input project name = ";
		getline(cin, stu[0][0].proj.name_project); 
	}else if(input_group=='B' || input_group=='b'){
		cout << "Input project name = ";
		getline(cin, stu[1][0].proj.name_project);
	}else if(input_group=='C' || input_group=='c'){
		cout << "Input project name = ";
		getline(cin, stu[2][0].proj.name_project);
	}else if(input_group=='D' || input_group=='d'){
		cout << "Input project name = ";
		getline(cin, stu[3][0].proj.name_project);
	}else if(input_group=='E' || input_group=='e'){
		cout << "Input project name = ";
		getline(cin, stu[4][0].proj.name_project);
	}else if(input_group=='F' || input_group=='f'){
		cout << "Input project name = ";
		getline(cin, stu[5][0].proj.name_project);
	}else if(input_group=='G' || input_group=='g'){
		cout << "Input project name = ";
		getline(cin, stu[6][0].proj.name_project);
	}else{
		cout << "Wrong Input\n";
		cout << "Please input again\n";
	}
	system("pause"); loop = 'y';
}

void group_output(){
	title_main();
	cout << "1. Group check specific\n";
	cout << "2. Group check all group\n";
	cout << "Selection = "; cin >> choice;
}

void group_output_1(){
	title_main();
	cout << "Please input your group A/B/C/D/E/F/G/H\n";
	cout << "Input = "; cin >> input_group;
	if(input_group=='A' || input_group=='a'){
		out_group=0; out_student=2;
	}else if(input_group=='B' || input_group=='b'){
		out_group=1; out_student=2;
	}else if(input_group=='C' || input_group=='c'){
		out_group=2; out_student=2;
	}else if(input_group=='D' || input_group=='d'){
		out_group=3; out_student=2;
	}else if(input_group=='E' || input_group=='e'){
		out_group=4; out_student=2;
	}else if(input_group=='F' || input_group=='f'){
		out_group=5; out_student=2;
	}else if(input_group=='G' || input_group=='g'){
		out_group=6; out_student=3;
	}else{
		wrong();
	}
	line("-",50);
	cout << "Group - " << stu[out_group][0].group << endl;
	cout << "Project Name : " << stu[out_group][0].proj.name_project << endl;
	cout << " No |                Name                |   NIM\n";
	for(int i=0; i<out_student; i++){
		cout << left;
		cout << " " << setw(3) << i+1 << "|";
		cout << setw(36) << stu[out_group][i].name_student << "|";
		cout << stu[out_group][i].number_student << endl;
	}
	system("pause");
}

void group_output_2(){
	title_main();
	for(int x=0;x<7;x++){
		cout << "Group - " << stu[x][0].group << endl;
		cout << "Project Name : " << stu[x][0].proj.name_project << endl;
		cout << " No |                Name                |   NIM\n";
		for(int y=0;y<3;y++){
			if(x==6){
			cout << left;
			cout << " " <<setw(3) << y+1 << "|";
			cout << setw(36) << stu[x][y].name_student << "|";
			cout << stu[x][y].number_student << endl;
			}else if(x<6 && y<2){
				cout << left;
				cout << " " <<setw(3) << y+1 << "|";
				cout << setw(36) << stu[x][y].name_student << "|";
				cout << stu[x][y].number_student << endl;
			}
		}cout << endl;
	}
	system("pause");
}

void exit(){
	system("cls");
	line("=", 50);
	title("THANK YOU", 50);
	title("HAVE A NICE DAY", 50);
	line("=", 50); 
	loop='n';
}