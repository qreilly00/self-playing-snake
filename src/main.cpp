//include classes and headers
#include "../inc/common.hpp"

#include "Base.hpp"

int main() {

    Base b;

    bool exit = 0;
    while(exit == 0) {
        exit =
        b.gameLoop();
    }

    // Exit program.
    return 0;
}
