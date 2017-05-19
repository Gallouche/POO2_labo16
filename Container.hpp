//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_CONTAINER_HPP
#define LABO16_CONTAINER_HPP

#include <string>
#include <list>
#include <iostream>

#include "Person.hpp"

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



#endif //LABO16_CONTAINER_HPP
