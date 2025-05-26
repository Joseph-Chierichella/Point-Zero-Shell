#include <iostream>
#include "indenting.hpp"
#ifndef VERSIONPRINT_HPP
#define VERSIONPRINT_HPP

// VERSION
float version = 1.4;

void versionPrint() {
	using namespace std;
	cout << findent << "Point Zero Shell | version " << version << endl;
}



#endif
