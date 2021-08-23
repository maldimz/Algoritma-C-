#include <iostream>
using namespace std;

int main(){
	int a, b, c, *p ,*q;
	cout << "Input a : "; cin >> a;
	b=a*2; c=b*2; p = &a; q = &b;
	cout << "Value of a : " << a << " (Memory Address : " << &a << ")\n";
	cout << "Value of b : " << b << " (Memory Address : " << &b << ")\n";
	cout << "Value of c : " << c << " (Memory Address : " << &c << ")\n";
	cout << "Value of p : " << p << " (Memory Address : " << &p << ")\n";
	cout << "Value of q : " << q << " (Memory Address : " << &q << ")\n";
	return 0;
}
