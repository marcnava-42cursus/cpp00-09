#include "identify.hpp"

#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    int pick = std::rand() % 3;
    if (pick == 0) {
        return new A();
    }
    if (pick == 1) {
        return new B();
    }
    return new C();
}
