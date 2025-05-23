#ifndef CLEAR_TERM_HPP
#define CLEAR_TERM_HPP
#include <cstdlib>
#include <iostream>

void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        std::cout << "\033[2J\033[H";
        std::cout.flush();
    #endif
}

#endif
