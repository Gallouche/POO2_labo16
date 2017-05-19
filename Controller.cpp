//
// Created by Gallouche on 19/05/2017.
//

#include "Controller.hpp"


void Controller::showMenu() {
    cout << "p      : afficher"        << endl;
    cout << "e <nom>: embarquer <nom>" << endl;
    cout << "d <nom>: debarquer <nom>" << endl;
    cout << "m      : deplacer bateau" << endl;
    cout << "r      : reinitialiser"   << endl;
    cout << "q      : quitter"         << endl;
    cout << "h      : menu"            << endl;
}

void Controller::display() {
    cout << "----------------------------------------------------------" << endl;
    cout << "Gauche: ";
    (*leftBank).displayPersons();
    cout << "----------------------------------------------------------" << endl;
    if((*boat).getPosition() == Boat::Side::LEFT)  { (*boat).displayPersons(); }
    cout << endl;
    cout << "==========================================================" << endl;
    if((*boat).getPosition() == Boat::Side::RIGHT) { (*boat).displayPersons(); }
    cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Droite: ";
    (*rightBank).displayPersons();
    cout << "----------------------------------------------------------" << endl;
}