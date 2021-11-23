// New Version Code
//Comentario

#include <cmath>
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

float standard_desv(vector<float> cal);
float HigherCal(vector<float> cal);
vector<vector<float>> lowerCal(vector<float> cal, float min);


int main()
{
	vector<float> cal;
	float x = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the " << i + 1 << " number: ";
		cin >> x;
		cal.push_back(x);
		system("cls");
	}
	const float higher_cal = HigherCal(cal);
	const float standard_dev = standard_desv(cal);
	const float two_deviation = higher_cal - (standard_dev * 2);
	const vector<vector<float>> Lower = lowerCal(cal, two_deviation);

	cout << "Califications: [ "; for (float cal1 : cal) cout << cal1 << " "; cout << " ]\n";

	cout << "Higher Calification = " << higher_cal << endl;
	cout << "Standard Deviation = " << standard_dev << endl;
	cout << "Two Standard Deviation = " << two_deviation << "\n\n";
	cout << "Those numbers that have Two standard Deviations are: ";

	for (auto lower : Lower[0])
		cout << lower << " ";

	cout << "\n\nPRESS ENTER TO SHOW THE NEW CURVE....\n";

	system("Pause");

	for (auto final : Lower[1])
		cout << final << " ";
}

float standard_desv(vector<float> cal)
{
	float sum = 0.0, standard_desv = 0.0;
	for (int i = 0; i < 10; i++)
		sum += cal[i];

	const float average = sum / 10;

	for (int i = 0; i < 10; i++)
		standard_desv += pow(cal[i] - average, 2);

	return sqrt(standard_desv / 10);
}

float HigherCal(vector<float> cal)
{
	float maxCal = cal[0];

	for (int i = 0; i < 10; i++)
		maxCal < cal[i] ? maxCal = cal[i] : maxCal;

	return maxCal;
}

vector<vector<float>> lowerCal(vector<float> cal, float min)
{
	vector<vector<float>> numbers;
	vector<float> low;
	vector<float> final_cal;

	for (int i = 0; i < 10; i++)
	{
		if (cal[i] < min)
		{
			low.push_back(cal[i]);
			final_cal.push_back(cal[i] + 25);
		}
		else
			final_cal.push_back(cal[i]);

	}
	numbers.push_back(low);
	numbers.push_back(final_cal);

	return numbers;
}
