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
    cout << findent << " hello       : say hello to the computer" << endl;
    cout << findent << " clear       : This will clear the terminal" << endl;
    cout << findent << " guide       : This is a guide!" << endl;
    cout << findent << " port scan   : This is a port scan!" << endl;
    cout << findent << " apps        : Displays all compatible apps" << endl;
    cout << findent << " errors      : Displays all error messages" << endl;
}


#endif
