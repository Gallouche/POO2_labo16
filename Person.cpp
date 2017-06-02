//
// Created by Gallouche on 19/05/2017.
//

#include "Person.hpp"

Person::Person(const string &name): name(name) {}

bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name == rhs.name;
}

bool Person::canDrive() {
    return true;
}

string Person::getName() {
    return name;
}

bool Person::checkConditions(list<Person*> l) {
    return true;
}

