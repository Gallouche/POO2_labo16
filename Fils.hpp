//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#ifndef POO2_LABO16_FILS_HPP
#define POO2_LABO16_FILS_HPP

#include <string>

#include "Person.hpp"

using namespace std;

class Fils: public Person {
private:

    Person* pere;
    Person* mere;

public:
    /**
     * Fils constructor
     * @param name the name of the son
     */
    Fils(const string &name, Person* pere, Person* mere);
};


#endif //POO2_LABO16_FILS_HPP
