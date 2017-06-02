//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#include "Voleur.hpp"

Voleur::Voleur(const string &name, Person* policier): Person(name), policier(policier) {}

bool Voleur::checkConditions(list<Person*> l) {
    bool policierFound = false;

    for(Person* p : l) {
        if(p == policier) { policierFound = true; }
    }
    if(!policierFound && l.size() > 1) { return false; }
    return true;
}
