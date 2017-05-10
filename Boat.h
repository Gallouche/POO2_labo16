//
// Created by Pierre-Samuel Rochat on 08.05.17.
//

#ifndef POO2_LABO16_BOAT_H
#define POO2_LABO16_BOAT_H

#include "Container.h"

class Boat: public Container {
private:
    Side position;

public:
    Boat();
    ~Boat();
    enum class Side { RIGHT, LEFT };
    Side getPosition();
};

Boat::Boat() : position(Boat::Side::LEFT) {}

Boat::Side Boat::getPosition() {
    return position;
}


#endif //POO2_LABO16_BOAT_H
