//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#include "Policier.hpp"

Policier::Policier(const string &name, Person* voleur): Person(name, true), voleur(voleur) {}
