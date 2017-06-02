//
// Created by Gallouche on 19/05/2017.
//

#include "Boat.hpp"


Boat::Boat(const string &name): Container(name) {}

Bank* Boat::getSide(){
    return side;
}

void Boat::setSide(Bank* newSide) {
    side = newSide;
}

void Boat::displayPersons() {
    cout << "< ";
    for (Person* p : l)
        cout <<  p->getName() << " ";
    cout << ">" << endl;
}

bool Boat::canMove() {
    for(Person* p : l)
        if(p->canDrive()) return true;
    return false;
}
