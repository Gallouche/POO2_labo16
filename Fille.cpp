//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#include "Fille.hpp"

Fille::Fille(const string &name, Person* pere, Person* mere): Person(name, false), pere(pere), mere(mere) {}