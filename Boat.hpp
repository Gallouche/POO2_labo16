//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_BOAT_HPP
#define LABO16_BOAT_HPP


#include "Container.hpp"
#include "Side.hpp"

class Boat: public Container {
private:
    Side position;

public:
    Boat();
    ~Boat();
    Side getPosition();
};



#endif //LABO16_BOAT_HPP
