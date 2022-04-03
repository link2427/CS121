// CS121HomeworkOne 3

#include <iostream>
#include <string>
using namespace std;

int main()
{

	string sentence = "";
	string subst = "";
	
	cout << "What is the sentence you would like to search? \n";
	// Getline is used to avoid stopping the count when whitespace is encountered
	getline(cin, sentence);
	
	cout << "What is the substring you would like to search for? \n";
	getline(cin, subst);


	// variables for converting to lowercase
	int position = 0;
	int subposition = 0;

	// converting input sentence to lowercase
	while (position < sentence.length())

	{

		sentence.at(position) = tolower(sentence.at(position));
			position++;

	}

	// also converted input substring to lowercase
	while (subposition < subst.length())

	{

		subst.at(subposition) = tolower(subst.at(subposition));
		subposition++;

	}

	// while loop to find the amount of times the substring was found
	int found = 0;
	string::size_type svec = 0;

	while ((svec = sentence.find(subst, svec)) != string::npos) {
		++found;
		svec += subst.length();
	}
	
	cout << "The substring was found " << found << " times.";
}

