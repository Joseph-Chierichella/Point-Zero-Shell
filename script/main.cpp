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
		getline(cin, input);
		if (input == "quit") 
		{
			cout << findent << "Thankyou for using Point Zero Shell!" << endl;
			cout << fline << endl;
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
		else if (input == "port scan")
		{
			runPortScan();
		}
		else if (input == "guide")
		{
			guide();
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
			cout << findent << "Error || 02" << endl;
		}
	}
	return 0;
}
