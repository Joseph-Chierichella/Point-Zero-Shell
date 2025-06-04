#ifndef NVIM_HPP
#define NVIM_HPP

inline void nvim() 
{
	using namespace std;
	int result = system("nvim");
	if (result != 0)
	{
		cerr << findent << "Error || 01" << endl;
	}
}
#endif
