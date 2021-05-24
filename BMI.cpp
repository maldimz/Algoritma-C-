#include <iostream>
#include <iomanip>

using namespace std;

int main(){
float weight, height, BMI;
string name, classification = "";

cout << "========================================\n";
cout << "=======  Welcome to BMI Program  =======\n";
cout << "========================================\n";
cout << "Input your Name\t\t: ";
getline(cin, name);
cout << "Input your weight (kg)\t: ";
cin >> weight;
cout << "Input your height (cm)\t: ";
cin >> height;

height = height/100;
BMI = weight/(height*height);
cout << "========================================\n";
if (BMI < 18.5){
	classification = "Underweight";
} else if (BMI >= 18.5 && BMI <=24.9){
	classification = "Normal range";
} else if (BMI >= 25 && BMI <= 29.9){
	classification = "Pre-obese";
} else if (BMI >= 30 && BMI <= 34.9){
	classification = "Obese I";
} else if (BMI >= 35 && BMI <= 39.9){
	classification = "Obese II";
} else if (BMI >= 40){
	classification = "Obese III";
}
cout << "Your BMI = "<< setprecision(4) << BMI << endl;
cout << "You are " << classification << endl;

cin.get();
return 0;
}
