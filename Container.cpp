//
// Created by Gallouche on 19/05/2017.
//

#include "Container.hpp"

Container::Container(string name): name(name) {}

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

