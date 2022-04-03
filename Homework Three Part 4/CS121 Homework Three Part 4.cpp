#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

void precipDay(int day, float aprcp[], string adates[], int numlines);
void precipDateRange(string startDate, string endDate, float aprcp[], string adates[], int numlines);
void precipByStation(string stationName, float aprcp[], string anames[], int numlines);
void tempExtAvgByStation(string stationName, float amax[], float amin[], string anames[], int numlines);
void tempExtAvgByDate(string stationName, string startDate, string endDate, float amax[], float amin[], string adates[], string anames[], int numlines);
int main()
{
    start:
    string u_input;
    string currentline;
    unsigned int pos_name;
    unsigned int pos_tmax;
    unsigned int pos_tmin;
    unsigned int pos_prcp;
    unsigned int pos_dates;
    int numlines = 0;
    float fmax, fmin, fprcp;
    string tmax_s, tmin_s, name_s, prcp_s, dates_s;
    int index = 0;

    ifstream infile;
    float amax[3000] = { 0 }, amin[3000] = { 0 }, aprcp[3000] = { 0 };
    string anames[3000];
    string adates[3000];


    infile.open("Weather_Station_Five_Column.txt");


    while (getline(infile, currentline))
    {
        numlines++;
    }
    infile.close();
    infile.open("Weather_Station_Five_Column.txt");

    getline(infile, currentline);
    
    pos_name = 0;
    pos_tmax = currentline.find("TMAX");
    pos_tmin = currentline.find("TMIN");
    pos_prcp = currentline.find("PRCP");
    pos_dates = currentline.find("DATE");

    //skip dashes
    getline(infile, currentline);

    while (index < numlines - 2)
    {
        getline(infile, currentline);

        tmax_s = currentline.substr(pos_tmax, 5);
        tmin_s = currentline.substr(pos_tmin, 5);
        prcp_s = currentline.substr(pos_prcp, 5);


        anames[index] = currentline.substr(pos_name, 44);
        adates[index] = currentline.substr(pos_dates + 8, 3);
        amax[index] = stof(tmax_s);
        amin[index] = stof(tmin_s);
        aprcp[index] = stof(prcp_s);

        index++;
    }
    
    infile.close();






    int selection;
    string start_date;
    string dummy;
    string end_date;
    string stationName;
    cout << "Select an option from the following menu." << endl;
    cout << "1. Total precipitation from all stations for a given day" << endl;
    cout << "2. Total precipitation over a date range." << endl;
    cout << "3. Total precipitation by station for March." << endl;
    cout << "4. Temperature max, min and average by station for March." << endl;
    cout << "5. Temperature max, min and average by station for date range." << endl;
    cout << "6. Quit." << endl;
    cin >> selection;
    switch (selection)
    {
    case 1:
        cout << "Enter a day to get total precipitation for: " << endl;
        cin >> selection;
        precipDay(selection, aprcp, adates, numlines);
        break;
    case 2:
        cout << "Enter a date range in YYYY:MM:DD to YYYY:MM:DD format: " << endl;
        cin >> start_date >> dummy >> end_date;
        precipDateRange(start_date, end_date, aprcp, adates, numlines);
        break;
    case 3:
        cout << "Enter a station name to get total precipitation for the month of March." << endl;
        cin.ignore(1, '\n');
        getline(cin, stationName);
        precipByStation(stationName, aprcp, anames, numlines);
        break;
    case 4:
        cout << "Enter a station name to get the temperature extremes and averages." << endl;
        cin.ignore(1, '\n');
        getline(cin, stationName);
        tempExtAvgByStation(stationName, amax, amin, anames, numlines);
        break;
    case 5:
        cout << "Enter a station name and date range to get the temperature extremes and averages." << endl;
        cin.ignore(1, '\n');
        cout << "Station Name: " << endl;
        getline(cin, stationName);
        cout << "Date range in YYYY:MM:DD to YYYY:MM:DD format: " << endl;
        cin >> start_date >> dummy >> end_date;
        tempExtAvgByDate(stationName, start_date, end_date, amax, amin, adates, anames, numlines);
        break;
    case 6:
        return(1);
    }

    cout << endl; 
    cout << "Continue? Y/N" << endl;
    cin >> u_input;
    if (u_input == "Y" || u_input == "y")
    {
        goto start;
    }
    else
    {
        return(1);
    }
}
void precipDay(int day, float aprcp[], string adates[], int numlines)
{
    int counter = 0;
    float total_prcp = 0;

    string day_s = to_string(day);

    //adding 0 to the string to account for date format
    if (day < 10)
    {
        day_s = "0" + day_s;
    }
    while (counter < numlines - 2)
    {
        if (adates[counter].find(day_s) != string::npos)
        {
            total_prcp = total_prcp + aprcp[counter];
        }
        counter++;
    }
    cout << "The total precipitation on March " << day << " was " << total_prcp << " inches.";
}

void precipDateRange(string startDate, string endDate, float aprcp[], string adates[], int numlines)
{
    int counter = 0;
    float total_prcp = 0;
    string s_start, s_end;
    replace(startDate.begin(), startDate.end(), ':', ' ');
    replace(endDate.begin(), endDate.end(), ':', ' ');
    s_start = startDate.substr(8, 3);
    s_end = endDate.substr(8, 3);
    cout << s_end;
 
    cout << s_start << endl;
    while (counter < numlines - 2)
    {
        if (adates[counter].find(s_start) != string::npos)
        {
            total_prcp = total_prcp + aprcp[counter];
            cout << "found at index: " << counter << endl;
            while (adates[counter].find(s_end) == string::npos)
            {
                counter++;
                total_prcp = total_prcp + aprcp[counter];
            }
        }
        counter++;
    }
    cout << total_prcp;
    
}
void precipByStation(string stationName, float aprcp[], string anames[], int numlines)
{
    float total_prcp = 0;
    int counter = 0;
    while (counter < numlines - 2)
    {
        if (anames[counter].find(stationName) != string::npos)
        {
            total_prcp = total_prcp + aprcp[counter];
        }
        counter++;
    }
    cout << "The total precipitation for station " << stationName << " for the month of March was " << total_prcp << endl;
}
void tempExtAvgByStation(string stationName, float amax[], float amin[], string anames[], int numlines)
{
    int counter = 0;
    float tempMax = 0;
    float tempMin = 0;
    int maxAvgAmt = 0;
    int minAvgAmt = 0;
    float maxAvg = 0;
    float minAvg = 0;

    float tempLowest = 0;
    float highMax[3000] = { 0 };
    float lowMin[3000] = { 0 };

    while (counter < numlines - 2)
    {
        if (anames[counter].find(stationName) != string::npos)
        {
            highMax[counter] = amax[counter];
            lowMin[counter] = amin[counter];
            tempMax = tempMax + amax[counter];
            tempMin = tempMin + amin[counter];

            maxAvgAmt++;
            minAvgAmt++;
        }
        counter++;

    }
    counter = 0;
    //sorting
    float* max_temp = max_element(begin(highMax), end(highMax));
    sort(begin(lowMin), end(lowMin), less<>());

    while (counter < 3000)
    {    
        if (lowMin[counter] > 0)
        {
        break;
        }
        else
        {
        counter++;
        }
    }
    //sorting


    //averages
    maxAvg = tempMax / maxAvgAmt;
    minAvg = tempMin / minAvgAmt;


    cout << setprecision(2) << fixed;
    cout << "Max temp for station " << stationName << " was: " << *max_temp << " F" << endl;
    cout << "Min temp for station: " << lowMin[counter] << " F" << endl;
    cout << "Average high temp: "  << maxAvg << " F" << endl;
    cout << "Average min temp: " << minAvg << " F" << endl;
    

}
void tempExtAvgByDate(string stationName, string startDate, string endDate, float amax[], float amin[], string adates[], string anames[], int numlines)
{
    int counter = 0;
    float total_prcp = 0;

    float tempMax = 0, tempMin = 0;

    float highMax[3000] = { 0 };
    float lowMin[3000] = { 0 };

    int maxAvgAmt = 0;
    int minAvgAmt = 0;
    float maxAvg = 0;
    float minAvg = 0;


    string s_start, s_end;
    replace(startDate.begin(), startDate.end(), ':', ' ');
    replace(endDate.begin(), endDate.end(), ':', ' ');
    s_start = startDate.substr(8, 3);
    s_end = endDate.substr(8, 3);
    cout << s_end;

    cout << s_start << endl;
    while (counter < numlines - 2)
    {
        if (anames[counter].find(stationName) != string::npos)
        {
            if (adates[counter].find(s_start) != string::npos)
            {
                maxAvgAmt++;
                minAvgAmt++;
                tempMax = tempMax + amax[counter];
                tempMin = tempMin + amin[counter];
                while (adates[counter].find(s_end) == string::npos)
                {
                    counter++;
                    tempMax = tempMax + amax[counter];
                    tempMin = tempMin + amin[counter];

                    highMax[counter] = amax[counter];
                    lowMin[counter] = amin[counter];

                    maxAvgAmt++;
                    minAvgAmt++;
                }
            }
        }
        counter++;
    }
    counter = 0;
    float* max_temp = max_element(begin(highMax), end(highMax));
    sort(begin(lowMin), end(lowMin), less<>());

    while (counter < 3000)
    {
        if (lowMin[counter] > 0)
        {
            break;
        }
        else
        {
            counter++;
        }
    }

    maxAvg = tempMax / maxAvgAmt;
    minAvg = tempMin / minAvgAmt;

    cout << setprecision(2) << fixed;
    cout << "Max temp for station " << stationName << " was: " << *max_temp << " F" << endl;
    cout << "Min temp for station: " << lowMin[counter] << " F" << endl;
    cout << "Average high temp: " << maxAvg << " F" << endl;
    cout << "Average min temp: " << minAvg << " F" << endl;
}
