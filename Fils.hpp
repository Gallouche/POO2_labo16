/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Fils.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Fils" herite de "Person". Defini ses conditions pour etre
               contenu dans un "Container"

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO16_FILS_HPP
#define POO2_LABO16_FILS_HPP

#include <string>

#include "Person.hpp"
#include "Container.hpp"

using namespace std;

class Fils: public Person {
private:
    Person* mere;
    Person* pere;
public:
    /**
     * Fils constructor
     * @param name the name of the son
     */
    Fils(const string &name, Person* pere, Person* mere): Person(name), pere(pere), mere(mere) {}

    /**
     * Checks if a son isn't with his mother when the dad isn't here.
     * @param l the list of people in the container
     * @return true or false
     */
    bool checkConditions(list<Person*> l) {
        bool pereFound = false;
        bool mereFound = false;

        for(Person* p : l) {
            if(p == mere) { mereFound = true; }
            if(p == pere) { pereFound = true; }
        }
        return (!mereFound && pereFound) || (mereFound && pereFound) || (!mereFound && !pereFound);
    }

    /**
     * Checks if the son can drive.
     * @return true or false
     */
    bool canDrive() {
        return false;
    }
};


#endif //POO2_LABO16_FILS_HPP
