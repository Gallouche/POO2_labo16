#include <iostream>
#include <cstdlib>
#include "Controller.hpp"

int main() {
    Person papa("papa");
    Person maman("maman");

    Controller c({&papa,&maman});
    c.nextTurn();
    return EXIT_SUCCESS;
}