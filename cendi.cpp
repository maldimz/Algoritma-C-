#include <iostream>
using namespace std;

int main()
{
	float ipk;
	int st, as, mka, pub, npub, total;
	int tipk, tst, tas, tpub, jumlah;

	cout << "IPK = "; cin >> ipk;
	cout << "Lama studi (semester) = "; cin >> st;
	cout << "Lama menjadi Asisten (semester) = "; cin >> as;
	cout << "Banyaknya MKA Praktikum = "; cin >> mka;
	cout << "Jenis publikasi ([4]Internasional, [3]Nasional, [2]Regional, [1]UPN) = "; cin >> pub;
	cout << "Banyaknya publikasi = "; cin >> npub;
	cout << endl;

	if (ipk > 3.5 && st <=10 && as > 0 && pub > 1 ){
		cout << "Mahasiswa tersebut berhak mendapat Karya Cendika" << endl;
		if(ipk >= 3.876 && ipk <= 4){
			tipk = 20 * 4;
		} else if(ipk >=3.751 && ipk <= 3.875){
			tipk = 20 * 3;
		} else if(ipk >= 3.626 && ipk <= 3.75){
			tipk = 20 * 2;
		} else if(ipk >= 3.5 && ipk <= 3.625){
			tipk = 20;
		}
		
		if(st == 7){
			tst = 10 * 4;
		} else if(st == 8){
			tst = 10 * 3;
		} else if(st == 9){
			tst = 10 * 2;
		} else if(st == 10){
			tst = 10;
		} else {
			tst = 10;
		}

		if(as >= 4){
			tas = 10 * 4 * mka;
		} else if(as = 3){
			tas = 10 * 3 * mka;
		} else if(as = 2){
			tas = 10 * 2 * mka;
		} else if(as = 1){
			tas = 10 * mka;
		}

		if(pub = 4){
			tpub = 10 * 4 * npub;
		} else if(pub = 3){
			tpub = 10 * 3 * npub;
		} else if(pub = 2){
			tpub = 10 * 2 * npub;
		} else if(pub = 1){
			tpub = 10 * npub;
		}

	} else {
		cout << "Maaf Mahasiswa tersebut tidak berhak mendapat Karya Cendika" << endl;
		return 0;
	}
	jumlah = tipk + tst + tas + tpub;
	cout << "Jumlah skor = " << jumlah << endl;


	return 0;
}
