//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_BOAT_HPP
#define LABO16_BOAT_HPP


#include "Container.hpp"

class Boat: public Container {
private:
    Side position;

public:
    Boat();
    ~Boat();
    enum class Side { RIGHT, LEFT };
    Side getPosition();
};



#endif //LABO16_BOAT_HPP
