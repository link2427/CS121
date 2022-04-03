// CS121 Homework Two 2

#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    string sentence;
    string reversed;
    int pos;
    char ch;
    cout << "Enter a sentence to be reversed: " << endl;
    getline(cin, sentence);

    pos = sentence.length() - 1;
    while (pos >= 0)
    {
        ch = sentence.at(pos);
        reversed = reversed + ch;
        pos = pos - 1;
    }
    cout << "Reversed: " << reversed << endl;
}

