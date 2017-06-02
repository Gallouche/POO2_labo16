/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Person.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Person" de base.

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO16_PERSON_HPP
#define LABO16_PERSON_HPP

#include <string>
#include <list>

using namespace std;

class Person {
private:
    string name;
public:

    /**
     * Person constructor
     * @param name the name of the person
     */
    Person(const string &name): name(name) {}

    /**
     * Person destructor
     */
    ~Person(){}

    /**
     * Gets if the person can drive or not
     * @return true or false
     */
    virtual bool canDrive() {
        return true;
    }

    /**
     * Gets the name of the person
     * @return the name
     */
    string getName() { return name; }

    /**
     * Comparison operator, compare the names of the 2 people
     * @param lhs the first person
     * @param rhs the second person
     * @return true or false
     */
    friend bool operator == (const Person& lhs, const Person& rhs) {
        return lhs.name == rhs.name;
    }

    /**
     * No need to check conditions on a simple person
     * @param l the list of people in the container to check
     * @return true
     */
    virtual bool checkConditions(list<Person*> l) {
        return true;
    }
};


#endif //LABO16_PERSON_HPP
