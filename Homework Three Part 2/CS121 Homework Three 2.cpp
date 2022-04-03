#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    ifstream infile;
    ofstream outfile;
    string currentline;
    unsigned int pos_name;
    unsigned int pos_date;
    unsigned int pos_prcp;
    unsigned int pos_tmax;
    unsigned int pos_tmin;
    float tmax, tmin;
    string tmax_s, tmin_s, name_s, date_s, prcp_s;
    string date_year, date_month, date_day;


    infile.open("Filtered_AL_Weather_Station.txt");
    if (!infile)
    {
        cout << "Can't open file." << endl;
        return 1;
    }
    cout << "File opened" << endl;

    outfile.open("Weather_Station_Five_Column.txt");
    if (!outfile)
    {
        cout << "Can't open output file." << endl;
        return 2;
    }
    cout << "Out file opened" << endl;

    string header = "                       STATION NAME                  DATE           PRCP      TMAX      TMIN";
    outfile << header << endl;

    getline(infile, currentline);
    pos_tmax = currentline.find("TMAX");
    pos_tmin = currentline.find("TMIN");
    pos_name = currentline.find("STATION_NAME");
    pos_prcp = currentline.find("PRCP");
    pos_date = currentline.find("DATE");

    getline(infile, currentline);
    outfile << currentline << endl;

    int numlines = 0;
    int counter = 0;
    while (getline(infile, currentline))
    {
        numlines++;
    }

    infile.close();
    infile.open("Filtered_AL_Weather_Station.txt");
    getline(infile, currentline);
    getline(infile, currentline);

    while (counter < numlines)
    {
        getline(infile, currentline);

        tmax_s = currentline.substr(pos_tmax, 2);
        tmin_s = currentline.substr(pos_tmin, 2);
        name_s = currentline.substr(pos_name, 47);
        prcp_s = currentline.substr(pos_prcp, 5);
        date_s = currentline.substr(pos_date, 9);
        date_year = date_s.substr(0, 4);
        date_month = date_s.substr(4, 2);
        date_day = date_s.substr(6, 2);

        tmax = stof(tmax_s);
        tmin = stof(tmin_s);
        tmax = tmax / 10;
        tmin = tmin / 10;

        tmax = (tmax * 9.0) / 5.0 + 32;
        tmin = (tmin * 9.0) / 5.0 + 32;

        outfile << name_s << setw(10) << date_year << " " << date_month << " " << date_day 
                << setw(5) << setw(10) << prcp_s << setw(10) << fixed << setprecision(2) << tmax << setw(10) << tmin << endl;
        counter++;
    }
}

