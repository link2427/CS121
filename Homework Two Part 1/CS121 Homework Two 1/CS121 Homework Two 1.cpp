// CS121 Homework Two 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    cout << "How many grades would you like to enter?" << endl;
    int gradeCount;
    cin >> gradeCount;
    double grades[20];
    for (int index = 0; index < gradeCount; index++)
    {
        cout << "Enter a grade:" << endl;
        cin >> grades[index];
    }
    int maxIndex = 0;
    int smallestGrade = 0;
    int sum = 0;
    int average = 0;
    for (int index = 1; index < gradeCount; index++)
    {
        if (grades[maxIndex] > grades[index])
        {
            maxIndex = index;
        }
    }
    smallestGrade = grades[maxIndex];

    for (int index = 0; index < (gradeCount - 1); index++)
    {
        if (index != grades[maxIndex])
        {
            sum = sum + grades[index];
        }
    }

    average = sum / (gradeCount - 1);

    for (int i = gradeCount - 1; i >= 0; i--)
    {
        cout << grades[i];
        cout << " ";
    }
    cout << endl << "Dropped Grade: " << smallestGrade << endl;
    cout << "Grade Average : " << average << endl;
    
}

