#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	string currentline;
	unsigned int pos_name;
	unsigned int pos_tmax;
	unsigned int pos_tmin;
	float fmax, fmin;
	string tmax_s, tmin_s, name_s;
	ifstream infile;
	float* amax;
	float* amin;
	string* aname;
	infile.open("Weather_Station_Five_Column.txt");
	if (!infile)
	{
		cout << "Can't open file." << endl;
		return 1;
	}
	cout << "File opened" << endl;

	getline(infile, currentline);
	pos_tmax = currentline.find("TMAX");
	pos_tmin = currentline.find("TMIN");
	pos_name = currentline.find("STATION");
	getline(infile, currentline);

	int numlines = 0;
	while (getline(infile, currentline))
	{
		numlines++;
	}
	amax = new float[numlines];
	amin = new float[numlines];
	aname = new string[numlines];
	infile.close();
	infile.open("Weather_Station_Five_Column.txt");
	getline(infile, currentline);
	getline(infile, currentline);
	int counter = 0;
	while (counter < numlines)
	{
		getline(infile, currentline);
		tmax_s = currentline.substr(pos_tmax, 5);
		tmin_s = currentline.substr(pos_tmin, 5);
		name_s = currentline.substr(pos_name, 24);

		fmax = stof(tmax_s);
		fmin = stof(tmin_s);

		amax[counter] = fmax;
		amin[counter] = fmin;
		aname[counter] = name_s;
		counter++;


	}
	float max;
	float min;
	int maxindex = 0;
	int minindex = 0;
	max = amax[0];
	min = amin[0];
	int i = 0;

	while (i < numlines)
	{
		if (amax[i] > max)
		{
			max = amax[i];
			maxindex = i;
		}
		i++;
	}
	i = 0;
	while (i < numlines)
	{
		if (amin[i] < min)
		{
			min = amin[i];
			minindex = i;
		}
		i++;
	}
	maxindex = maxindex + 3;
	minindex = minindex + 3;

	cout << "Highest Temperature for March 2018: " << max << endl;
	cout << "Lowest Temperature for March 2018: " << min << endl;
	cout << "Station " << aname[maxindex] << " recorded a high of " << max << endl;
	cout << "Station " << aname[minindex] << " recorded a low of " << min << endl;
}
	

