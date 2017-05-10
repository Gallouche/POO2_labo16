//
// Created by Pierre-Samuel Rochat on 08.05.17.
//

#ifndef POO2_LABO16_CONTAINER_H
#define POO2_LABO16_CONTAINER_H

#include <string>
#include <list>
#include <iostream>

#include "Person.h"

using namespace std;

class Container {
protected:
    string name;
    list<Person> l;
public:
    Container();
    ~Container();

    void addPerson(Person p);
    void removePerson(Person p);
    void displayPersons();
};

Container::Container() {}

Container::~Container() {}

void Container::addPerson(Person p) {
    l.push_back(p);
}
void Container::removePerson(Person p) {
    l.remove(p);
}

void Container::displayPersons() {
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
        cout << (*it).getName() << " ";
    cout << endl;
}

#endif //POO2_LABO16_CONTAINER_H
