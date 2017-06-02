//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#ifndef POO2_LABO16_VOLEUR_HPP
#define POO2_LABO16_VOLEUR_HPP

#include <string>

#include "Person.hpp"

using namespace std;

class Voleur: public Person {
public:
    /**
     * Voleur constructor
     * @param name the name of the thief
     */
    Voleur(const string &name);
};


#endif //POO2_LABO16_VOLEUR_HPP
