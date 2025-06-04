#ifndef HELLOMESSAGE_HPP
#define HELLOMESSAGE_HPP
#include "termcolor.hpp"

void helloMessage()
{
	using namespace std;
	cout << termcolor::bright_green;
	cout << findent << "Hello there!" << endl;
	cout << findent << "Thanks for using Point-Zero-Shell!" << endl;
	cout << termcolor::reset;
}
#endif
