//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#ifndef POO2_LABO16_FILLE_HPP
#define POO2_LABO16_FILLE_HPP

#include <string>

#include "Person.hpp"

using namespace std;

class Fille: public Person {
private:

    Person* pere;
    Person* mere;

public:
    /**
     * Fille constructor
     * @param name the name of the daughter
     */
    Fille(const string &name, Person* pere, Person* mere);
};


#endif //POO2_LABO16_FILLE_HPP
