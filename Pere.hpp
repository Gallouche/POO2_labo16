//
// Created by Pierre-Samuel Rochat on 02.06.17.
//

#ifndef POO2_LABO16_PERE_HPP
#define POO2_LABO16_PERE_HPP

#include <string>

#include "Person.hpp"

using namespace std;

class Pere: public Person {
public:
    /**
     * Pere constructor
     * @param name the name of the father
     */
    Pere(const string &name);
public:
};

#endif //POO2_LABO16_PERE_HPP
