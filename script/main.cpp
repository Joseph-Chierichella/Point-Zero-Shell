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
#include "helloMessage.hpp"
#include <cstdlib>
#include "clearTerm.hpp"
#include "guide.hpp"
#include "credits.hpp"
#include "port_scanner.hpp"
#include "nvim.hpp"
#include "apps.hpp"
#include "error.hpp"
#include "vim.hpp"
#include "tshark.hpp"
#include "length.hpp"
#include "websiteIp.hpp"
#include "termcolor.hpp"
#include "termCommands.hpp"


// The if statements
int main() 
{
	using namespace std;
	cout << endl;
	cout << termcolor::bright_yellow;
	cout << "        Welcome to PointZero Shell!" << endl;
	cout << "To view the guide, use the 'guide' command!" << endl;
	cout << "To view the commands, use the 'help' command!" << endl;
	cout << "To quit the program, use the 'quit' command!" << endl;
	cout << termcolor::bright_yellow;
	cout << fline << endl;
	cout << termcolor::reset;
	cout << termcolor::reset;
	int i = 0;
	string input;
	while (input != "quit" && i == 0) 
	{
		int i = 0;
		string input;
		cout << termcolor::bright_cyan;
		cout << "pointzero:~$";
		cout << termcolor::reset;
		getline(cin, input);
		if (input == "quit") 
		{
			cout << termcolor::magenta;
			cout << findent << "Thankyou for using Point Zero Shell!" << endl;
			cout << termcolor::reset;
			cout << termcolor::bright_yellow;
			cout << fline << endl;
			cout << termcolor::reset;
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
		else if (input == "credits")
		{
			credits();
		}
		else if (input == "system" || input == "system " || input == "System" || input == "System ")
		{
			runCommands();
		}
		else if (input == "tshark" || input == "Tshark")
		{
			tshark();
		}
		else if (input == "nvim" || input == "neovim" || input == "Neovim")
		{
			nvim();
		}
		else if (input == "vim" || input == "Vim")
		{
			vim();
		}
		else if (input == "clear")
		{
			clearTerminal();
		}
		else if (input == "apps" || input == "Apps" || input == "app" || input == "App")
		{
			apps();
		}
		else if (input == "errors" || input == "Errors" || input == "error" || input == "Error")
		{
			errors();
		}
		else if (input == "websiteip" || input == "websiteIp" || input == "Websiteip" || input == "website ip" || input == "Website Ip")
		{
			websiteIp();
		}
		else if (input == "port scan")
		{
			runPortScan();
		}
		else if (input == "guide")
		{
			guide();
		}
		else if (input == "length" || input == "length " || input == "Length" || input == "Length ")
		{
			length();
		}
		else if (input == "hello" || input == "hi" || input == "Hello" || input == "Hi")
		{
			helloMessage();
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
			cout << termcolor::bright_yellow;
			cout << findent << "Error || 02" << endl;
			cout << termcolor::reset;
		}
		cout << termcolor::bright_yellow;
		cout << fline << endl;
		cout << termcolor::reset;

	}
	return 0;
}
