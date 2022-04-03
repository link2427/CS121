// CS121HomeworkOne-4
// Jacob Neel
#include <iostream>
using namespace std;
int main()
{
    // variable declerations 
	int hours;
	int minutes;
	int seconds;
	char colon;
	string AMPM;
	cout << "Enter a time in HH:MM:SS AM/PM form." << endl;
	cin >> hours >> colon >> minutes >> colon >> seconds >> AMPM;
    // checks if its PM
    if (AMPM == "PM")
    {
        // sets hours to 0 if hours are 12 and minutes/seconds are 0
        if (hours == 12 && minutes == 0 && seconds == 0)
        {
            hours = 0;
        }
        else if (hours < 12)
        {
            hours += 12;
        }
    }
    //checks if its AM and the hours are equal to 12 to set it to 0
    if ((AMPM == "AM") && (hours == 12))
    {
        hours = 0;
    }
	cout << hours << colon << minutes << colon << seconds;
    //checks if seconds is missing a 0 and adds one if it is
    if (seconds == 0)
    {
        cout << "0";
    }
}