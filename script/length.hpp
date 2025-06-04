#ifndef LENGTH_HPP
#define LENGTH_HPP
#include "termcolor.hpp"


void length()
{
	using namespace std;
	string word1;
	cout << ": ";
	getline(cin, word1);
	cout << termcolor::magenta;
	cout << "Your message has " << word1.length() << " characters!" << endl;
	cout << termcolor::reset;
}


#endif
