/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Fille.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Fille" herite de "Person". Defini ses conditions pour etre
               contenu dans un "Container"

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO16_FILLE_HPP
#define POO2_LABO16_FILLE_HPP

#include <string>

#include "Person.hpp"
#include "Container.hpp"

using namespace std;

class Fille: public Person {
private:
    Person* pere;
    Person* mere;
public:
    /**
     * Fille constructor
     * @param name the name of the daughter
     */
    Fille(const string &name, Person* pere, Person* mere): Person(name), pere(pere), mere(mere) {}

    /**
     * Checks if a daughter isn't with his father when the mom isn't here.
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
        return (mereFound && !pereFound) || (mereFound && pereFound) || (!mereFound && !pereFound);
    }

    /**
     * Checks if the son can drive.
     * @return true or false
     */
    bool canDrive() {
        return false;
    }
};


#endif //POO2_LABO16_FILLE_HPP
