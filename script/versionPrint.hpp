#include <iostream>
#include "indenting.hpp"
#include "termcolor.hpp"
#ifndef VERSIONPRINT_HPP
#define VERSIONPRINT_HPP

// VERSION
float version = 1.5;

void versionPrint() {
	using namespace std;
	cout << termcolor::magenta;
	cout << findent << "Point Zero Shell | version " << version << endl;
	cout << termcolor::reset;
}



#endif
