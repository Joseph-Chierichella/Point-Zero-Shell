#ifndef ERROR_HPP
#define ERROR_HPP
#include "termcolor.hpp"

void errors()
{
	using namespace std;
	cout << endl;
	cout << findent << termcolor::red << "         Error Messages" << endl;
	cout << termcolor::bright_yellow;
	cout << findent << "--------------------------------" << endl;
	cout << termcolor::magenta;
	cout << findent << "~#01  ~ APP ERROR" << endl;
	cout << findent << "~#02  ~ COMMAND DOES NOT EXIST" << endl;
	cout << findent << "~#03  ~ PORT ERROR" << endl;
	cout << findent << "~#04  ~ SOCKET ERROR" << endl;
	cout << findent << "~#05  ~ INVALID IP" << endl;
	cout << findent << "~#06  ~ INVALID WEBSITE" << endl;
	cout << findent << "~#07  ~ SYSTEM COMMAND ERROR" << endl;
	cout << termcolor::reset;
}

#endif
