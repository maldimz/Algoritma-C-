#include <iostream>
using namespace std;

int main(){
	int choice, number, check, a;
	char loop;
	string word;
	do{
		system("cls");
		cout << "------------------------------------\n";
		cout << "    Hello Welcome to the program    \n";
		cout << "   Loops Implementation Structure   \n";
		cout << "------------------------------------\n";
		cout << "The menu:\n";
		cout << "1. Prime Number Check\n";
		cout << "2. Word Repetition\n";
		cout << "Input your choice (1/2) : "; cin >> choice;
		cout << endl;
		if(choice == 1){
			cout << "------------------------------------\n";
			cout << "         Prime Number Check         \n";
			cout << "------------------------------------\n";
			cout << "Input the number = "; cin >> number;
			check = 0;
			for(int x=2;x<=number;x++){
				if(number%x==0){
					check++;
				}
			}
			cout << "The result : ";
			if(check == 1){
				cout << number << " is prime number\n";
			} else{
				cout << number << " is not prime number\n";
			}
		}else if(choice == 2){
			cout << "------------------------------------\n";
			cout << "           Word Repetition          \n";
			cout << "------------------------------------\n";
			cout << "Enter the word = "; cin >> word;
			cout << "How many the word will be repeat? "; cin >> number;
			cout << "- - - - - - - - - - - - - - - - - - \n";
			a=1;
			while(a<=number){
				cout << a << ". " << word << endl;
				a++;
			}
		}else{
			cout << "Wrong input!!" << endl;
		}
		
	cout << "------------------------------------\n";
	cout << "\nBack to home (y/n)? "; cin >> loop;
	system("pause");

	}while(loop == 'y' || loop == 'Y');
	

	return 0;
}