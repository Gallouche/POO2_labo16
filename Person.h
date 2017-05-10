//
// Created by Pierre-Samuel Rochat on 08.05.17.
//

#ifndef POO2_LABO16_PERSON_H
#define POO2_LABO16_PERSON_H

#include <string>

using namespace std;

class Person {
private:
    string name;
public:
    virtual bool canDrive() = 0;
    string getName();
};


#endif //POO2_LABO16_PERSON_H
