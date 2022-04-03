// CS121 Homework Two 3
// Jacob Neel

#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    double numbers[10];
    int count = 0;
    double sum = 0;
    string inputString;
    stringstream stringStream;
    cout << "What numbers would you like to add?" << endl;
    getline(cin, inputString);
   
    stringStream << inputString;
    string inputCheck;
    double found;
    while (!stringStream.eof())
    {
        stringStream >> inputCheck;
        if (stringstream(inputCheck) >> found)
        {
        numbers[count] = found;
        count++;
        }
    }
    for (int i = count - 1; i >= 0; i--)
        sum += numbers[i];

    cout << "The sum is: " << sum;
}
