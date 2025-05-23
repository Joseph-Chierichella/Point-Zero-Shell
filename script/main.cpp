#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include "math.hpp"
#include "indenting.hpp"
#include "versionPrint.hpp"
#include "ftime.hpp"
#include "help.hpp"


// The if statements
int main() 
{
	using namespace std;
	cout << endl;
	cout << "Welcome to PointZero Shell!" << endl;
	cout << "To see commands, use our 'help' command" << endl;
	cout << "To exit the program, type 'quit'" << endl;
	int i = 0;
	string input;
	while (input != "quit" && i == 0) 
	{
		int i = 0;
		string input;
		cout << fline << endl;
		cout << "pointzero:~$";
		cin >> input;
		if (input == "quit") 
		{
			cout << "Thankyou for using Point Zero Shell!" << endl;
			int i = 1;
			break;
		}
		else if (input == "help")
		{
			help();
		}
		else if (input == "add")
		{
			addition();
		}
		else if (input == "sub")
		{
			subtraction();
		}
		else if (input == "tim")
		{
			multiplication();
		}
		else if (input == "div")
		{
			division();
		}
		else if (input == "time")
		{
			printTime();
		}
		else if (input == "version")
		{
			versionPrint();
		}
		else
		{
			cout << findent << "'" << input << "'" << " is not a command!" << endl;
		}
	}
	return 0;
}
