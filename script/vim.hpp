#ifndef VIM_HPP
#define VIM_HPP
#include <iostream>
#include <cstdlib>

inline void vim()
{
	using namespace std;
	int result = system("vim");
	if (result != 0)
	{
		cerr << findent << "Error || 01" << endl;
	}
}

#endif
