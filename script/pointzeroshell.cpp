#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

// VERSION
void versionPrint() {
	using namespace std;
	cout << "Point Zero Shell | version 1.1" << endl;
}


void add(float add1, float add2) 
{
	using namespace std;
	float add3 = add1 + add2;
	cout << ": " << add1 << " + " << add2 << " = " << add3 << endl;
}
void sub(float sub1, float sub2) 
{
	using namespace std;
	float sub3 = sub1 - sub2;
	cout << ": " << sub1 << " - " << sub2 << " = " << sub3 << endl;
}
void tim(float tim1, float tim2) 
{
	using namespace std;
	float tim3 = tim1 * tim2;
	cout << ": " << tim1 << " * " << tim2 << " = " << tim3 << endl;
}
void div(float div1, float div2) 
{
	using namespace std;
	float div3 = div1 / div2;
	cout << ": " << div1 << " / " << div2 << " = " << div3 << endl;
}
int addition()
{	
	using namespace std;
	float add11;
	cout << ": ";
	cin >> add11;
	float add12;
	cout << ": " << add11 << " + ";
	cin >> add12;
	add(add11, add12);
	return 0;
}
int subtraction()
{	
	using namespace std;
	float sub11;
	cout << ": ";
	cin >> sub11;
	float sub12;
	cout << ": " << sub11 << " - ";
	cin >> sub12;
	sub(sub11, sub12);
	return 0;
}
int multiplication()
{	
	using namespace std;
	float tim11;
	cout << ": ";
	cin >> tim11;
	float tim12;
	cout << ": " << tim11 << " * ";
	cin >> tim12;
	tim(tim11, tim12);
	return 0;
}
int division()
{	
	using namespace std;
	float div11;
	cout << ": ";
	cin >> div11;
	float div12;
	cout << ": " << div11 << " / ";
	cin >> div12;
	div(div11, div12);
	return 0;
}

void printTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::cout << ""
              << std::put_time(localTime, "%Y-%m-%d %H:%M:%S")
              << std::endl;
}



// The if statements
int main() 
{
	using namespace std;
	cout << endl;
	cout << "Welcome to PointZero Shell!" << endl;
	cout << "To see commands, use our 'help' command" << endl;
	cout << "To exit the program, type 'quit'" << endl;
	cout << "------------------------------------------" << endl;
	int i = 0;
	string input;
	while (input != "quit" && i == 0) 
	{
		int i = 0;
		string input;
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
			cout << " quit        : quit the program" << endl;
			cout << " help        : View the commands" << endl;
			cout << " add         : add two numbers" << endl;
			cout << " sub         : subtract two numbers" << endl;
			cout << " tim         : multiply two numbers" << endl;
			cout << " div         : divide two numbers" << endl;
			cout << " time        : prints current time" << endl;
			cout << " version     : Displays the version" << endl;
			int i = 0;
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
			cout << "'" << input << "'" << " is not a command!" << endl;
		}
	}
	return 0;
}
