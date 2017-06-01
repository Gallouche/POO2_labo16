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
    Boat(string name);
    Bank* getSide();
    void setSide(Bank* newSide);
    void displayPersons();
};



#endif //LABO16_BOAT_HPP
