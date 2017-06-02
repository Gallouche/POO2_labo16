/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Container.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Container" contient une liste de personne ainsi qu'un nom.

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

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
    Container(const string &name);

    /**
     * Container destructor
     */
    virtual ~Container();

    /**
     * Adds a person to the container
     * @param p a pointer on the person
     */
    void addPerson(Person* p);

    /**
     * Removes a person from the container
     * @param p a pointer on the person
     */
    void removePerson(Person* p);

    /**
     * Checks if a person is in the container
     * @param p a pointer on the person
     */
    bool contains(Person* p);

    /**
     * Displays all the people in the container
     */
    virtual void displayPersons();

    /**
     * Clears all the people in the container
     */
    void clear();

    /**
     * Gets the number of people by the container
     * @return the number of people
     */
    int getSize();

    /**
     * Gets the name of the container
     * @return the name
     */
    string getName();

    /**
     * Checks if the conditions are fulfilled on every person of the container
     * @return true or false
     */
    bool checkConditions();
};



#endif //LABO16_CONTAINER_HPP
