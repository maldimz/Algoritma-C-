#include <iostream>
using namespace std;

int fibbonaci(int x);

int main(){
	int num;
	cout << "=== Fibbonaci Program ===\n";
	cout << "  Akhmal Dimas Pratama\n";
	cout << "   123200047 / Class H\n";
	cout << "=========================\n";
	cout << "Input the number  = "; cin >> num;
	cout << "Fibbonaci Sequence: \n";
	for(int x=1;x<=num;x++){
		cout << fibbonaci(x);
		if(x==num){
			cout << " ";
		}else{
			cout << " + ";
		}
	}
	cout << endl;
	cout << "Fibbonaci - " << num << "  = " << fibbonaci(num) << endl;
	return 0;
}

int fibbonaci(int x){
	int fib;
	if(x>2){
		fib = fibbonaci(x-1)+fibbonaci(x-2); 
	}else{
		fib=1;
	}
	return fib;
}
