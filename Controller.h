//
// Created by Pierre-Samuel Rochat on 08.05.17.
//

#ifndef POO2_LABO16_CONTROLLER_H
#define POO2_LABO16_CONTROLLER_H

#include <iostream>

#include "Bank.h"
#include "Boat.h"

using namespace std;

class Controller {
private:
    int turn;
    Bank* leftBank = new Bank();
    Bank* rightBank = new Bank();
    Boat* boat = new Boat();

public:
    void showMenu();
    void display();
    void nextTurn();
};

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


#endif //POO2_LABO16_CONTROLLER_H
