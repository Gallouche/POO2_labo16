/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Container.cpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Implementation de la classe container.

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

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
    for (Person* p : l)
        cout <<  p->getName() << " ";
    cout << endl;
}

void Container::clear() {
    l.clear();
}

bool Container::contains(Person* person) {
    for (Person* p : l) {
        if(p == person) {
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

bool Container::checkConditions() {
    for(Person* p : l) {
        if(!p->checkConditions(l)) {
            return false;
        }
    }
    return true;
}
