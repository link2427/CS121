// CS121 Homework Two 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
int main()
{

    string word;
    char ch;
    int wordCounter[32] = { 0 };
    int w_Length = 0;
    int count = 1;
    ifstream in("UAH_sample.txt");
    if (in.is_open())
    {
        cout << "Opened file successfully" << endl;
    }
    while (!in.eof())
    {
        in >> word;

        //removes punctuation:
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

        w_Length = word.length();
        if (w_Length > 0 && w_Length <= 10)
        {
            wordCounter[w_Length] = wordCounter[w_Length] + 1;
        }
    }
    in.close();
    cout << "Word Length" << setw(10) << "Count" << endl;
    while (count <= 10)
    {
        cout << setw(3) << count << setw(20) << wordCounter[count] << endl;
        count++;
    }

    

    in.close();
    in.open("UAH_sample.txt");
    stringstream uah_sample_stream;
    uah_sample_stream << in.rdbuf();
    string str = uah_sample_stream.str();
    int counter[26] = { 0 };

    for (char c : str) {
        if (isalpha(c)) {
            counter[tolower(c) - 'a']++;
        }
    }
    cout << endl << endl;
    cout << "Letter" << setw(10) << "Count" << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << char('a' + i) << ": " << setw(13) << counter[i] << endl;
    }
}

