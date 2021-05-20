#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	char nama[30];
	int nim;
	string plug;
	string hobi;
	
	cout << "Masukkan :" << endl;
	cout << "Nama\t: ";
	cin.getline(nama, sizeof(nama));
	cout << "NIM\t: ";
	cin >> nim;
	cout << "Plug\t: ";
	cin >> plug;
	cout << "Hobbi\t: ";
	cin >>hobi;
	
	cout << "\nInilah data Anda :\n";
	cout << "Nama\t: " << nama << endl;
	cout << "NIM\t: " << nim << endl;
	cout << "Plug\t: " << plug << endl << endl;
	
	cout << "Dalam bentuk tabel :" << endl;
	cout << "=====================================================\n";
	
	cout <<  setw(13) "NIM";
	cout << "| Nama" << setw(31);
	cout << "| Plug" << setw(5);
	cout << "| Hobbi" << endl;
	
	//cout << "NIM       " << "|" << "Nama                          " << "|" << "Plug\n";
	
	cout << "\n=====================================================\n";
	cout << setiosflags(ios::left) << setw(10) << nim;
	cout << "|" << setiosflags(ios::left) << setw(30) << nama;
	cout << "|" << setiosflags(ios::left) << setw(5) << plug;
	
	//cout << nim << "\t| " << nama << "\t| " << plug << endl;
	
	
	cin.get();
	return 0;
	}
