// CS121 Homework One - 2: Practice with Manipulators
// Jacob Neel
// 1/25/2022

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << setw(10);
    cout << "DOUBLE";
    cout << setw(15);
    cout << "FLOAT" << endl;
    cout << setfill('-');
    int counter = 1;
    int currentwidth = 8;
    int currentprecision = 1;
    double PI_D = 3.14159256359;
    float PI_F = 3.14159256359;
    while (counter <= 10)
    {
        cout << setw(currentwidth) 
             << fixed 
             << setprecision(currentprecision) 
             << PI_D << setw(16) 
             << PI_F << endl;
        currentprecision = currentprecision + 1;
        currentwidth = currentwidth + 1;
        counter = counter + 1;
    }
    
}


