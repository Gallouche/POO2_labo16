//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#ifndef POO2_LABO16_POLICIER_HPP
#define POO2_LABO16_POLICIER_HPP

#include <string>

#include "Person.hpp"

using namespace std;

class Policier: public Person {
private:

    Person* voleur;

public:
    /**
     * Policier constructor
     * @param name the name of the cop
     */
    Policier(const string &name, Person* voleur);
};


#endif //POO2_LABO16_POLICIER_HPP
