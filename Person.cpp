//
// Created by Gallouche on 19/05/2017.
//

#include "Person.hpp"


bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name.compare(rhs.name);
}

bool Person::canDrive() {
    return drive;
}

string Person::getName() {
    return name;
}

