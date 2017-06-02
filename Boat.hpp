//
// Created by Gallouche on 19/05/2017.
//

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
    Boat(const string &name);

    /**
     * Gets boat's current river side
     * @return a pointer on the bank where the boat is
     */
    Bank* getSide();

    /**
     * Sets the boat's current bank
     * @param newSide a pointer on the new bank where the boat will be
     */
    void setSide(Bank* newSide);

    /**
     * Displays the people that are currently in the boat
     */
    void displayPersons();
};



#endif //LABO16_BOAT_HPP
