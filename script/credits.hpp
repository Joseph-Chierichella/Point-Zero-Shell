
#ifndef CREDITS_HPP
#define CREDITS_HPP
#include "termcolor.hpp"

void credits()
{
	using namespace std;
	cout << findent << "   ";
	cout << termcolor::yellow;
	cout << termcolor::italic;
	cout << termcolor::underline;
	cout << "Credits" << endl;
	cout << termcolor::reset;
	cout << termcolor::bright_yellow;
	cout << findent << "Programmer ~~ Joseph Chierichella" << endl;
	cout << termcolor::reset;
	cout << endl;
	cout << findent << "   ";
	cout << termcolor::yellow;
	cout << termcolor::italic;
	cout << termcolor::underline;
	cout << "Sources" << endl;
	cout << termcolor::reset;
	cout << termcolor::bright_yellow;
	cout << findent << "termcolor  ~~ ikalnytskyi" << endl;
	cout << termcolor::reset;
}

#endif
