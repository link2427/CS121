// CS 121 Homework Two 4

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
    int i = 0;
    double temps[25];
    int count = 0;
    cout << "Reading file" << endl;
    ifstream in("temps.txt");
    if (in.is_open())
    {
        cout << "Opened file successfully" << endl;
    }
    while (!in.eof())
    {
        cout << "reading" << endl;
        in >> temps[count];
        count++;
    }
    in.close();

    ofstream out("table.txt");
    out << setw(10) << "Celsius" << setw(20) << "Fahrenheit" << setw(18) << "Kelvin" << setw(0) << endl;
    
    while (i < count - 1)
    {
    out << setw(7) << temps[i] << setw(18) << (temps[i] * 9 / 5) + 32 << setw(26) << temps[i] + 273.15 << endl;
    i++;
    }
    out.close();
    return(0);
}

