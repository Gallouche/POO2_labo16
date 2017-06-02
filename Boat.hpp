/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Boat.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "boat" (bateau) herite de container.

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO16_BOAT_HPP
#define LABO16_BOAT_HPP


#include "Container.hpp"
#include "Bank.hpp"

class Boat: public Container {
private:
    Bank* side;

public:
    /**
     * Boat constructor
     * @param name the name of the container
     */
    Boat(const string &name): Container(name) {}

    /**
     * Gets boat's current river side
     * @return a pointer on the bank where the boat is
     */
    Bank* getSide() { return side; }

    /**
     * Sets the boat's current bank
     * @param newSide a pointer on the new bank where the boat will be
     */
    void setSide(Bank* newSide) { side = newSide; }

    /**
     * Displays the people that are currently in the boat
     */
    void displayPersons() {
        cout << "< ";
        for (Person* p : l)
            cout <<  p->getName() << " ";
        cout << ">" << endl;
    }

    /**
     * Checks if the boat contains somebody that can drive
     * @return true or false
     */
    bool canMove() {
        for(Person* p : l)
            if(p->canDrive()) return true;
        return false;
    }
};



#endif //LABO16_BOAT_HPP
