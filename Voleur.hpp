/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Voleur.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Voleur" herite de "Person". Defini ses conditions pour etre
               contenu dans un "Container"

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef POO2_LABO16_VOLEUR_HPP
#define POO2_LABO16_VOLEUR_HPP

#include <string>

#include "Person.hpp"
#include "Container.hpp"

using namespace std;

class Voleur: public Person {
private:
    Person* policier;
public:
    /**
     * Voleur constructor
     * @param name the name of the thief
     */
    Voleur(const string &name, Person* policier): Person(name), policier(policier) {}

    /**
     * Checks if the thief isn't with family members when the cop isn't here.
     * @param l the list of people in the container
     * @return true or false
     */
    bool checkConditions(list<Person*> l) {
        bool policierFound = false;

        for(Person* p : l) {
            if(p == policier) { policierFound = true; }
        }
        if(!policierFound && l.size() > 1) { return false; }
        return true;
    }

    /**
     * Checks if the thief can drive.
     * @return true or false
     */
    bool canDrive() { return false; }
};


#endif //POO2_LABO16_VOLEUR_HPP
