#include "identify.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < 10; ++i) {
        Base *ptr = generate();

        std::cout << "identify(ptr): ";
        identify(ptr);

        std::cout << "identify(ref): ";
        identify(*ptr);

        delete ptr;
    }

    return 0;
}
