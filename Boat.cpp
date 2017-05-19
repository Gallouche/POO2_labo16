//
// Created by Gallouche on 19/05/2017.
//

#include "Boat.hpp"


Boat::Boat(): position(Boat::Side::LEFT) {}

Boat::Side Boat::getPosition() {
    return position;
}