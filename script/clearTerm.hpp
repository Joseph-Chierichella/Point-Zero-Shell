#ifndef CLEAR_TERM_HPP
#define CLEAR_TERM_HPP

void clearTerminal() {
        std::cout << "\033[2J\033[H";
        std::cout.flush();
}

#endif
