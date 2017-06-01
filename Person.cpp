//
// Created by Gallouche on 19/05/2017.
//

#include "Person.hpp"


Person::Person(string name): name(name), drive(true)
{}

Person::Person(string name, bool canDrive): name(name), drive(canDrive)
{}




bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.name == rhs.name;
}

bool Person::canDrive() {
    return drive;
}

string Person::getName() {
    return name;
}

