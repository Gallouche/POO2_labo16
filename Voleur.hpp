//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#ifndef POO2_LABO16_VOLEUR_HPP
#define POO2_LABO16_VOLEUR_HPP

#include <string>

#include "Person.hpp"
#include "Container.hpp"

using namespace std;

class Voleur: public Person {
private:
    Person* policier;
public:
    /**
     * Voleur constructor
     * @param name the name of the thief
     */
    Voleur(const string &name, Person* policier);

    bool checkConditions(list<Person*> l);

    bool canDrive() {
        return false;
    }
};


#endif //POO2_LABO16_VOLEUR_HPP
