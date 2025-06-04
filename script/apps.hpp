#ifndef APPS_HPP
#define APPS_HPP
#include "termcolor.hpp"

void apps()
{
	using namespace std;
	cout << endl;
	cout << findent << termcolor::bright_green << "    Compatible Apps" << endl;
	cout << findent << "-----------------------" << endl;
	cout << termcolor::reset;
	cout << findent << termcolor::magenta << "~ Neovim" << endl;
	cout << findent << termcolor::green << "~ Vim" << endl;
	cout << findent << termcolor::bright_cyan << "~ Tshark" << endl;
	cout << termcolor::reset;
}

#endif
