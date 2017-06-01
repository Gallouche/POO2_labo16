//
// Created by Gallouche on 19/05/2017.
//

#include "Boat.hpp"


Boat::Boat(string name): Container(name) {}

Bank* Boat::getSide(){
    return side;
}

void Boat::setSide(Bank* newSide) {
    side = newSide;
}

void Boat::displayPersons() {
    cout << "< ";
    for (list<Person*>::iterator it = l.begin(); it != l.end(); it++)
        cout <<  (**it).getName() << " ";
    cout << ">" << endl;
}
