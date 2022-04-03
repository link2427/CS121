// CS121HomeworkOne-5

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float startingTemp;
	float endingTemp;
	float incremementTemp;
	float currentTempC = 0;
	float currentTempF = 0;
	float currentTempK = 0;
	cout << "Enter a starting temperature in degrees celsius." << endl;
	cin >> startingTemp;
	cout << "Enter the ending temperature in degrees celsius." << endl;
	cin >> endingTemp;
	cout << "Enter the temperature to increment in degrees celsius." << endl;
	cin >> incremementTemp; 
	cout << setw(25) << "While Loop Table: " << endl;
	cout << setw(10) << "Celius" << setw(15) << "Fahrenheit" << setw(13) << "Kelvin" << endl;
	currentTempC = startingTemp;
	cout << setfill('-');
	while (currentTempC < endingTemp)
	{
		currentTempF = (9.0 / 5.0 * currentTempC + 32.0);
		currentTempK = (currentTempC + 273.15);
		cout << setw(6) << currentTempC << setw(12) << currentTempF << setw(20) << currentTempK << endl;
		currentTempC = currentTempC + incremementTemp;
	}

	cout << setfill(' ');
	cout << endl << endl;
	cout << setw(25) << "Do While Table: " << endl;
	cout << setfill('-');
	currentTempC = startingTemp;
	do 
	{

		currentTempF = (9.0 / 5.0 * currentTempC + 32.0);
		currentTempK = (currentTempC + 273.15);
		cout << setw(6) << currentTempC << setw(12) << currentTempF << setw(20) << currentTempK << endl;
		currentTempC = currentTempC + incremementTemp;
	} 
	while (currentTempC < endingTemp);


	cout << setfill(' ');
	cout << endl << endl;
	cout << setw(25) << "For Loop Table: " << endl;
	cout << setfill('-');
	currentTempC = startingTemp;
	for (currentTempC = 0; currentTempC < endingTemp;)
	{
		currentTempC = currentTempC + incremementTemp;
		currentTempF = (9.0 / 5.0 * currentTempC + 32.0);
		currentTempK = (currentTempC + 273.15);
		cout << setw(6) << currentTempC << setw(12) << currentTempF << setw(20) << currentTempK << endl;
	}

}

