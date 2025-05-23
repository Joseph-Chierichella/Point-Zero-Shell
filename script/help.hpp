#include <iostream>
#ifndef HELP_HPP
#define HELP_HPP

void help()
{
    using namespace std;
    cout << findent << " quit        : quit the program" << endl;
    cout << findent << " help        : View the commands" << endl;
    cout << findent << " add         : add two numbers" << endl;
    cout << findent << " sub         : subtract two numbers" << endl;
    cout << findent << " tim         : multiply two numbers" << endl;
    cout << findent << " div         : divide two numbers" << endl;
    cout << findent << " time        : prints current time" << endl;
    cout << findent << " version     : Displays the version" << endl;
}


#endif
