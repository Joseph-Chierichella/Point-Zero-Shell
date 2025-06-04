#ifndef GUIDE_HPP
#define GUIDE_HPP

// VERSION
void guide() {
	using namespace std;
	cout << endl;
	cout << termcolor::bright_blue;
	cout << findent << findent << "Welcome to Point Zero Shell Guide!" << endl;
	cout << termcolor::magenta;
	cout << endl;
	cout << findent << "In point zero shell you can do many things." << endl;
	cout << findent << "You can see the commands by using the help" << endl;
	cout << findent << "command!" << endl;
	cout << termcolor::bright_green;
	cout << endl;
	cout << findent << "Something that is very important to know is" << endl;
	cout << findent << "that if you use a space at the end of the" << endl;
	cout << findent << "command, it may cause a error message. To see the" << endl;
	cout << findent << "types of error messages, use the 'errors' command!" << endl;
	cout << endl;
	cout << termcolor::blue;
	cout << findent << "Another thing to know is that uppercase letters can" << endl;
	cout << findent << "also cause error messages to pop up to. This means" << endl;
	cout << findent << "that the command will not execute or work properly." << endl;
	cout << termcolor::reset;
}



#endif
