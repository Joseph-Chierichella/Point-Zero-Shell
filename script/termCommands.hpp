#ifndef TERMCOMMANDS_HPP
#define TERMCOMMANDS_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include "indenting.hpp"
#include "termcolor.hpp"

void runCommands() 
{
	using namespace std;
	using namespace termcolor;
	cout << bright_yellow;
	cout << findent << "Use the '!' command to exit!" << endl;
	cout << reset;
	int i = 0;
	while (i != 1)
	{
		string input1;
		cout << magenta;
		cout << "!:~$";
		cout << reset;
		getline(cin, input1);
		if (input1 == "!" || input1 == "! ")
		{
			i++;
			break;
		}
		else if (input1.empty()) 
		{
			cout << "Error || 07" << endl;
			return;
		}
		cout << bright_yellow;
		system(input1.c_str());
		cout << reset;
	}
}
#endif

