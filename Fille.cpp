//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#include "Fille.hpp"

Fille::Fille(const string &name, Person* pere, Person* mere): Person(name), pere(pere), mere(mere) {}

bool Fille::checkConditions(list<Person*> l) {
    bool pereFound = false;
    bool mereFound = false;

    for(Person* p : l) {
        if(p == mere) { mereFound = true; }
        if(p == pere) { pereFound = true; }
    }
    return (mereFound && !pereFound) || (mereFound && pereFound) || (!mereFound && !pereFound);
}