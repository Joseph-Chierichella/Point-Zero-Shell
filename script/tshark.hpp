#ifndef TSHARK_HPP
#define TSHARK_HPP

inline void tshark()
{
	using namespace std;
	int result = system("tshark");
	if (result != 0)
	{
		cerr << findent << "Error || 01" << endl;
	}
}
#endif
