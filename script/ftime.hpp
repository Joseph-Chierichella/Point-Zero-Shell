#include <iomanip>
#include <iostream>
#include <ctime>
#ifndef FTIME_HPP
#define FTIME_HPP


void printTime() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    std::cout << findent << ""
              << std::put_time(localTime, "%Y-%m-%d %H:%M:%S")
              << std::endl;
}
#endif
