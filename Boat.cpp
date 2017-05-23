//
// Created by Gallouche on 19/05/2017.
//

#include "Boat.hpp"


Boat::Boat(string name): Container(name), side(Side::LEFT) {}

Side Boat::getSide(){
    return side;
}

void Boat::changeSide() {
    if(side == Side::RIGHT)
        side = Side::LEFT;
    else
        side = Side::RIGHT;
}

void Boat::displayPersons() {
    cout << "< ";
    for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
        cout <<  (*it).getName() << " ";
    cout << ">" << endl;
}
