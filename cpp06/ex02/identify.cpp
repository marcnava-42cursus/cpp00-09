#include "identify.hpp"

#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base *p) {
    if (dynamic_cast<A *>(p) != NULL) {
        std::cout << "A" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p) != NULL) {
        std::cout << "B" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p) != NULL) {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception &) {
    }

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception &) {
    }

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception &) {
    }

    std::cout << "Unknown" << std::endl;
}
