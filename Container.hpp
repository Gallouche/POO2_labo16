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
    list<Person*> l;
public:
    /**
     * Container constructor
     * @param name the name of the container
     */
    Container(string name);


    virtual ~Container();
    void addPerson(Person* p);
    void removePerson(Person* p);
    bool contain(Person* p);
    virtual void displayPersons();
    void clear();
    int getSize();
    string getName();
};



#endif //LABO16_CONTAINER_HPP
