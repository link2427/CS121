#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    //variables
    ifstream infile;
    ofstream outfile;
    string currentline;
    string s_tmax = "";
    string s_tmin = "";
    string s_prcp = "";
    float tmax, tmin, prcp;
    unsigned int tmax_pos;
    unsigned int tmin_pos;
    unsigned int prcp_pos;
    unsigned int badcount = 0;

    //opening file
    infile.open("AL_Weather_Station.txt");
    if (!infile)
    {
        cout << "Can't open file." << endl;
        return 1;
    }
    cout << "File opened" << endl;

    //opening out file
    outfile.open("Filtered_AL_Weather_Station.txt");
    if (!outfile)
    {
        cout << "Can't open output file." << endl;
        return 2;
    }
    cout << "Out file opened" << endl;

    getline(infile, currentline);
    outfile << currentline << endl;

    // finding column positions
    tmax_pos = currentline.find("TMAX");
    tmin_pos = currentline.find("TMIN");
    prcp_pos = currentline.find("PRCP");

    getline(infile, currentline);
    outfile << currentline << endl;

    while (!infile.eof())
    {
        getline(infile, currentline);

        s_tmax = currentline.substr(tmax_pos, 5);
        s_tmin = currentline.substr(tmin_pos, 5);
        s_prcp = currentline.substr(prcp_pos, 5);

        tmax = stof(s_tmax);
        tmin = stof(s_tmin);
        prcp = stof(s_prcp);

        if (tmax != -9999 && tmin != -9999 && prcp != -9999)
        {
            outfile << currentline << endl;
        }
        else
        {
            badcount++;
        }

        
    }
    cout << "There were " << badcount << " ommited records." << endl;

    infile.close();
    outfile.close();


    system("pause");
    return 0;

    
}


