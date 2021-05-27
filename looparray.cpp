#include <iostream>
using namespace std;

int main()
{
	int iteration, max, min, max_array = 0, min_array = 0; 
	float sum = 0.0, average;
	cout << "Score Comparation Program\n";
	cout << "How many score that will be compared? : ";
	cin >> iteration;

	char name[iteration][30];
	int score[iteration];
	int student_id[iteration];

	for (int i=0;i<iteration;i++){
		int w=i+1;
		cout << "Input Data-" << w << endl; 
		cout << "\tName       : ";
		cin.ignore();
		cin.getline(name[i], 30);
		cout << "\tStudent No : ";
		cin >> student_id[i];

		cout << "\tScore      : ";
		cin >> score[i];

		sum += score[i];
		cout << endl;
	}

	max = score[0];
	min = score[0];
	for(int i=0; i<iteration; i++){
		if (max < score[i]){
			max = score[i];
			max_array = i;

		} else if(min > score[i]){
			min = score[i];
			min_array = i;
		}
	}
	cout << "Highest Score :\n";
	cout << "Name          : " << name[max_array] << endl;
	cout << "Student No    : " << student_id[max_array] << endl;
	cout << "Score         : " << max << endl;

	cout << "\nLowest Score  :\n";
	cout << "Name          : " << name[min_array] << endl;
	cout << "Student No    : " << student_id[min_array]<< endl;
	cout << "Score         : " << min << endl;

	average = sum/iteration;
	cout << "\nAverage Score : " << average << endl;
	
return 0;
}