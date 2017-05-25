//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_BOAT_HPP
#define LABO16_BOAT_HPP


#include "Container.hpp"
#include "Side.hpp"

class Boat: public Container {
private:
    Side side;

public:
    Boat(string name);
    ~Boat();
    Side getSide();
    void setSide(Side newSide);
    void changeSide();
    void displayPersons();
    void embarquer(string person);
    void debarquer(string person);
};



#endif //LABO16_BOAT_HPP
