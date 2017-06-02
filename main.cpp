#include <iostream>

#include "Controller.hpp"
#include "Fille.hpp"
#include "Fils.hpp"
#include "Voleur.hpp"

int main() {
    Person* papa = new Person("papa");
    Person* maman = new Person("maman");
    Person* paul = new Fils("paul", papa, maman);
    Person* pierre = new Fils("pierre", papa, maman);
    Person* julie = new Fille("julie", papa, maman);
    Person* jeanne = new Fille("jeanne", papa, maman);
    Person* policier = new Person("policier");
    Person* voleur = new Voleur("voleur", policier);

    Controller c({papa,maman, paul, pierre, julie, jeanne, policier, voleur});
    c.run();
    return EXIT_SUCCESS;
}