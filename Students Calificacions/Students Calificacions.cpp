//Original Code 

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
float standard_desv(float cal[]);
float HigherCal(float cal[]);
vector<float> lowerCal(float cal[], float min);

int main()
{
	float cal[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the " << i + 1 << " number: ";
		cin >> cal[i];
		system("cls");
	}
	float higherCal = HigherCal(cal);
	float standardDev = standard_desv(cal);
	float twoDeviation = higherCal - (standardDev * 2);
	float finalCal[10];
	vector<float> Lower = lowerCal(cal, twoDeviation);
	cout << "Califications: [ ";
	for (float cal1 : cal)
		cout << cal1 << " ";
	cout << " ]\n";
	cout << "Higher Calification = " << higherCal << endl;
	cout << "Standard Deviation = " << standardDev << endl;
	cout << "Two Standard Deviation = " << twoDeviation << "\n\n";
	cout << "Those numbers that have Two standard Deviation are: ";

	for (float lower : Lower)
		cout << lower << " ";

	for (int i = 0; i < 10; i++)
		if (cal[i] < trunc(twoDeviation))
			finalCal[i] = cal[i] + 25;
		else
			finalCal[i] = cal[i];



	cout << "\n\nPRESS ENTER TO SHOW THE NEW CURVE....\n";
	system("Pause");

	for (auto final_cal : finalCal)
		cout << final_cal << " ";
}

float standard_desv(float cal[])
{
	float sum = 0.0, standardDesv = 0.0;
	for (int i = 0; i < 10; i++)
		sum += cal[i];

	float average = sum / 10;

	for (int i = 0; i < 10; i++)
		standardDesv += pow(cal[i] - average, 2);

	return sqrt(standardDesv / 10);
}


float HigherCal(float cal[])
{
	float maxCal = cal[0];

	for (int i = 0; i < 10; i++)
		maxCal < cal[i] ? maxCal = cal[i] : maxCal;

	return maxCal;
}

vector<float> lowerCal(float cal[], float min)
{
	vector<float> numbers;
	for (int i = 0; i < 10; i++)
	{
		if (cal[i] < trunc(min))
			numbers.push_back(cal[i]);
	}
	return numbers;
}
