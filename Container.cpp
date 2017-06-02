//
// Created by Gallouche on 19/05/2017.
//

#include "Container.hpp"

Container::Container(const string &name): name(name) {}

Container::~Container() {}

void Container::addPerson(Person* p) {
    l.push_back(p);
}
void Container::removePerson(Person* p) {
    l.remove(p);
}

void Container::displayPersons() {
    for (list<Person*>::iterator it = l.begin(); it != l.end(); it++)
        cout << (**it).getName() << " ";
    cout << endl;
}

void Container::clear() {
    l.clear();
}

bool Container::contains(Person* p) {
    for (list<Person*>::iterator it = l.begin(); it != l.end(); it++){
        if(*it == p){
            return true;
        }
    }
    return false;
}

int Container::getSize() {
    return l.size();
}

string Container::getName() {
    return name;
}

