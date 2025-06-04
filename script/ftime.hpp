#ifndef FTIME_HPP
#define FTIME_HPP
#include "termcolor.hpp"

void printTime() {
	using namespace termcolor;
	std::cout << magenta << std::endl;
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	std::cout << findent << ""
              << std::put_time(localTime, "%Y-%m-%d %H:%M:%S")
              << std::endl;
	std::cout << reset;
}
#endif
