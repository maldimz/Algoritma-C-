#include <iostream>
using namespace std;


int main()
{
	int a, nim, pilihan;
	double angka1, angka2, angka3, hasil;
	string nama;

	cout <<"-------------------------------------------------------------------\n";
	cout << "\tNama     : "; getline(cin, nama);
	cout << "\tNIM      : "; cin >> a;
	cout <<"-------------------------------------------------------------------\n";
		nim = a%10;

	cout << "Angka NIM paling belakang : " << nim << endl << endl;
	cout << "Program Menghitung Luas Bangun Datar atau Volume Bangun Ruang\n";
	cout << "Bangun Datar [1] / Ruang [2] : "; cin >> pilihan;
	cout << endl;

	if(nim == 1 || nim == 2){
		if(pilihan == 1){//1,3,4,7
		cout << "Menghitung Luas Bangun Datar :\n";
		cout << "1. Persegi\n";
		cout << "2. Segitiga\n";
		cout << "3. Lingkaran\n";
		cout << "4. Layang-layang\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung Luas Persegi\n";
				cout << "Masukkan nilai sisi = "; cin >> angka1;
				hasil = angka1 * angka1;
				cout << "Luas Persegi = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung Luas Segitiga\n";
				cout << "Masukkan nilai alas   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi = "; cin >> angka2;
				hasil = (angka1 * angka2)/2;
				cout << "Luas Segitiga = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung Luas Lingkaran\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				hasil = 3.14 * angka1 * angka1;
				cout << "Luas Lingkaran = " << hasil << endl;
			break;
			case 4:
				cout << "Menghitung Luas Layang-layang\n";
				cout << "Masukkan nilai diagonal 1 = "; cin >> angka1;
				cout << "Masukkan nilai diagonal 2 = "; cin >> angka2;
				hasil = 0.5 * angka1 * angka2;
				cout << "Luas Layang-layang = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}

	}else if(pilihan == 2){//2,5,7
		cout << "Menghitung Volume Bangun Datar :\n";
		cout << "1. Balok\n";
		cout << "2. Kerucut\n";
		cout << "3. Limas Segiempat\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung volume Balok\n";
				cout << "Masukkan nilai panjang = "; cin >> angka1;
				cout << "Masukkan nilai lebar   = "; cin >> angka2;
				cout << "Masukkan nilai tinggi  = "; cin >> angka3;
				hasil = angka1 * angka2 * angka3;
				cout << "Volume Balok = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung volumes Kerucut\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				cout << "Masukkan nilai tinggi    = "; cin >> angka2;
				hasil = (1/3) * 3.14 * angka1 * angka1 * angka2;
				cout << "Volume Kerucut = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung volume Limas Segiempat\n";
				cout << "Masukkan nilai panjang = "; cin >> angka1;
				cout << "Masukkan nilai lebar   = "; cin >> angka2;
				cout << "Masukkan nilai tinggi  = "; cin >> angka3;
				hasil = (1/3) * angka1 * angka2 * angka3;
				cout << "Volume Limas Segiempat = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}
	}
	}else if(nim == 3 || nim == 4){
		if(pilihan == 1){//1,3,5,8
		cout << "Menghitung Luas Bangun Datar :\n";
		cout << "1. Persegi\n";
		cout << "2. Segitiga\n";
		cout << "3. Jajar Genjang\n";
		cout << "4. Trapesiumg\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung Luas Persegi\n";
				cout << "Masukkan nilai sisi = "; cin >> angka1;
				hasil = angka1 * angka1;
				cout << "Luas Persegi = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung Luas Segitiga\n";
				cout << "Masukkan nilai alas   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi = "; cin >> angka2;
				hasil = (angka1 * angka2)/2;
				cout << "Luas Segitiga = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung Luas Jajar Genjang\n";
				cout << "Masukkan nilai alas   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Luas Jajar Genjang = " << hasil << endl;
			break;
			case 4:
				cout << "Menghitung Luas Trapesium\n";
				cout << "masukkan nilai sisi sejajar\n";
				cout << "Masukkan nilai sisi atas      = "; cin >> angka1;
				cout << "Masukkan nilai sisi bawah     = "; cin >> angka2;
				cout << "Masukkan nilai tinggi         = "; cin >> angka3;
				hasil = 0.5 * (angka1 + angka2) * angka3;
				cout << "Luas Trapesium = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}

	}else if(pilihan == 2){//2,3,8
		cout << "Menghitung Volume Bangun Datar :\n";
		cout << "1. Balok\n";
		cout << "2. Tabung\n";
		cout << "3. Prisma Segitiga\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung volume Balok\n";
				cout << "Masukkan nilai panjang = "; cin >> angka1;
				cout << "Masukkan nilai lebar   = "; cin >> angka2;
				cout << "Masukkan nilai tinggi  = "; cin >> angka3;
				hasil = angka1 * angka2 * angka3;
				cout << "Volume Balok = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung volumes Tabung\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				cout << "Masukkan nilai tinggi    = "; cin >> angka2;
				hasil = 3.14 * angka1 * angka1 * angka2;
				cout << "Volume Tabung = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung volume Prisma Segitiga\n";
				cout << "Masukkan nilai luas segitiga   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi          = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Volume Prisma Segitiga = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}
	}
	}else if(nim == 5 || nim == 6){
		if(pilihan == 1){//2,3,4,8
		cout << "Menghitung Luas Bangun Datar :\n";
		cout << "1. Persegi Panjang\n";
		cout << "2. Segitiga\n";
		cout << "3. Lingkaran\n";
		cout << "4. Trapesium\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung Luas Persegi Panjang\n";
				cout << "Masukkan nilai panjang = "; cin >> angka1;
				cout << "Masukkan nilai lebar   = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Luas Persegi Panjang = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung Luas Segitiga\n";
				cout << "Masukkan nilai alas   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi = "; cin >> angka2;
				hasil = (angka1 * angka2)/2;
				cout << "Luas Segitiga = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung Luas Lingkaran\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				hasil = 3.14 * angka1 * angka1;
				cout << "Luas Lingkaran = " << hasil << endl;
			break;
			case 4:
				cout << "Menghitung Luas Trapesium\n";
				cout << "masukkan nilai sisi sejajar\n";
				cout << "Masukkan nilai sisi atas      = "; cin >> angka1;
				cout << "Masukkan nilai sisi bawah     = "; cin >> angka2;
				cout << "Masukkan nilai tinggi         = "; cin >> angka3;
				hasil = 0.5 * (angka1 + angka2) * angka3;
				cout << "Luas Trapesium = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}

	}else if(pilihan == 2){//1,5,6
		cout << "Menghitung Volume Bangun Datar :\n";
		cout << "1. Kubus\n";
		cout << "2. Kerucut\n";
		cout << "3. Limas Segitiga\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung volume Kubus\n";
				cout << "Masukkan nilai sisi = "; cin >> angka1;
				hasil = angka1 * angka1 * angka1;
				cout << "Volume Kubus = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung volumes Kerucut\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				cout << "Masukkan nilai tinggi    = "; cin >> angka2;
				hasil = (1/3) * 3.14 * angka1 * angka1 * angka2;
				cout << "Volume Kerucut = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung volume Limas Segitiga\n";
				cout << "Masukkan nilai luas segitiga = "; cin >> angka1;
				cout << "Masukkan nilai tinggi        = "; cin >> angka2;
				hasil = (1/3) * angka1 * angka2;
				cout << "Volume Limas Segitiga = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}
	}
	}else if(nim == 7 || nim == 8){
		if(pilihan == 1){
		cout << "Menghitung Luas Bangun Datar :\n";
		cout << "1. Persegi Panjang\n";
		cout << "2. Lingkaran\n";
		cout << "3. Jajar Genjang\n";
		cout << "4. Belah Ketupat\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung Luas Persegi Panjang\n";
				cout << "Masukkan nilai panjang = "; cin >> angka1;
				cout << "Masukkan nilai lebar   = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Luas Persegi Panjang = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung Luas Lingkaran\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				hasil = 3.14 * angka1 * angka1;
				cout << "Luas Lingkaran = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung Luas Jajar Genjang\n";
				cout << "Masukkan nilai alas   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Luas Jajar Genjang = " << hasil << endl;
			break;
			case 4:
				cout << "Menghitung Luas Belah Ketupat\n";
				cout << "Masukkan nilai diagonal 1 = "; cin >> angka1;
				cout << "Masukkan nilai diagonal 2 = "; cin >> angka2;
				hasil = 0.5 * angka1 * angka2;
				cout << "Luas Belah Ketupat = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}

	}else if(pilihan == 2){
		cout << "Menghitung Volume Bangun Datar :\n";
		cout << "1. Kubus\n";
		cout << "2. Bola\n";
		cout << "3. Prisma Segitiga\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung volume Kubus\n";
				cout << "Masukkan nilai sisi = "; cin >> angka1;
				hasil = angka1 * angka1 * angka1;
				cout << "Volume Kubus = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung volumes Bola\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				hasil = 4/3 * 3.14 * angka1 * angka1 * angka1;
				cout << "Volume Bola = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung volume Prisma Segitiga\n";
				cout << "Masukkan nilai luas segitiga   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi          = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Volume Prisma Segitiga = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}
	}
	}else if(nim == 9 || nim == 0){
		if(pilihan == 1){ //1,5,6,7
		cout << "Menghitung Luas Bangun Datar :\n";
		cout << "1. Persegi\n";
		cout << "2. Jajar Genjang\n";
		cout << "3. Belah Ketupat\n";
		cout << "4. Layang-layang\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung Luas Persegi\n";
				cout << "Masukkan nilai sisi = "; cin >> angka1;
				hasil = angka1 * angka1;
				cout << "Luas Persegi = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung Luas Jajar Genjang\n";
				cout << "Masukkan nilai alas   = "; cin >> angka1;
				cout << "Masukkan nilai tinggi = "; cin >> angka2;
				hasil = angka1 * angka2;
				cout << "Luas Jajar Genjang = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung Luas Belah Ketupat\n";
				cout << "Masukkan nilai diagonal 1 = "; cin >> angka1;
				cout << "Masukkan nilai diagonal 2 = "; cin >> angka2;
				hasil = 0.5 * angka1 * angka2;
				cout << "Luas Belah Ketupat = " << hasil << endl;
			break;
			case 4:
				cout << "Menghitung Luas Layang-layang\n";
				cout << "Masukkan nilai diagonal 1 = "; cin >> angka1;
				cout << "Masukkan nilai diagonal 2 = "; cin >> angka2;
				hasil = 0.5 * angka1 * angka2;
				cout << "Luas Layang-layang = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}

	}else if(pilihan == 2){//3,4,7
		cout << "Menghitung Volume Bangun Datar :\n";
		cout << "1. Tabung\n";
		cout << "2. Bola\n";
		cout << "3. Limas Segiempat\n";
		cout << "Pilihan = "; cin >> pilihan;
		cout << endl;

		switch(pilihan){
			case 1:
				cout << "Menghitung volumes Tabung\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				cout << "Masukkan nilai tinggi    = "; cin >> angka2;
				hasil = 3.14 * angka1 * angka1 * angka2;
				cout << "Volume Tabung = " << hasil << endl;
			break;
			case 2:
				cout << "Menghitung volumes Bola\n";
				cout << "Masukkan nilai jari-jari = "; cin >> angka1;
				hasil = 4/3 * 3.14 * angka1 * angka1 * angka1;
				cout << "Volume Bola = " << hasil << endl;
			break;
			case 3:
				cout << "Menghitung volume Limas Segiempat\n";
				cout << "Masukkan nilai panjang = "; cin >> angka1;
				cout << "Masukkan nilai lebar   = "; cin >> angka2;
				cout << "Masukkan nilai tinggi  = "; cin >> angka3;
				hasil = (1/3) * angka1 * angka2 * angka3;
				cout << "Volume Limas Segiempat = " << hasil << endl;
			break;
			default:
				cout << "Input salah" << endl;
			break; 
		}
	}
	}

	return 0;
}
