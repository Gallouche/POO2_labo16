#include <iostream>
#include <cstdlib>
#include "Controller.hpp"

int main() {
    Person* papa = new Person("papa");
    Person* maman = new Person("maman");

    Controller c({papa,maman});
    c.run();
    return EXIT_SUCCESS;
}