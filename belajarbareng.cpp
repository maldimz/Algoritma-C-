#include <iostream>
using namespace std;

int main()
{
	string jenjang, program, kode_fti;
	int kode_prodi, tahun;

	cout << "Jenjang Studi : "; getline(cin, jenjang);
	if(jenjang == "S1"){
		cout << "Program Studi : "; getline(cin, program);
		kode_fti = "12";
		if(program == "Teknik Kimia"){
			kode_prodi = 1;
		} else if(program == "Teknik Industri"){
			kode_prodi = 2;
		} else if(program == "Informatika"){
			kode_prodi = 3;
		} else if(program == "Sistem Informasi"){
			kode_prodi = 4;
		}
	} else if(jenjang == "D3 TK"){
		kode_fti = "02";
		kode_prodi = 1;
	}
	cout << "Tahun Masuk   : "; cin >> tahun;
	tahun=tahun%100;
	
	if(tahun >= 1 && tahun <= 9){
		cout << "NIM Anda      : " << kode_fti << kode_prodi << 0 << tahun << 0;
	}else{
		cout << "NIM Anda      : " << kode_fti << kode_prodi << tahun << 0;
		if(tahun==0){
			cout << 0;
		} 
	}
	return 0;
}
