// CS121 Homework One Part One
//
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x;
    cout << "Enter x for the equation r = 3x^2+5x+1 to be solved.\n";
    cin >> x;
    double r = pow (x,2)*3 + (5 * x) + 1;
    cout << r << "\n";
    x = 0;
    
    double s;
    cout << "Enter x for the equation s = (x^2-12x+27)/(x-6)^2 to be solved. \n";
    cin >> x;
    s = (pow(x, 2) - 12 * x + 27) / pow((x - 6), 2);
    cout << s << endl;
    x = 0;

    double t;
    double y;
    cout << "Enter x for the equation t = (x^2+3)/Y^3 + (x+2)/y^2 + 1/y to be solved. \n";
    cin >> x;
    cout << "Enter y for the equation t = (x^2+3)/y^3 + (x+2)/y^2 + 1/y to be solved. \n";
    cin >> y;
    t = (pow(x, 2) + 3) / pow(y, 3) + (pow(x, 2)) / pow(y, 2) + 1 / y;
    cout << t;
    
}

