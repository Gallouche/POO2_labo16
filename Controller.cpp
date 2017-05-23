//
// Created by Gallouche on 19/05/2017.
//

#include "Controller.hpp"

Controller::Controller(initializer_list<Person *> p): turn(0) {
    leftBank = new Bank("left");
    rightBank = new Bank("right");
    boat = new Boat("boat");
    for(initializer_list<Person*>::iterator it = p.begin(); it != p.end(); it++){
        leftBank->addPerson(**it);
    }
}

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
    if((*boat).getSide() == Side::LEFT)  { (*boat).displayPersons(); }
    cout << endl;
    cout << "==========================================================" << endl;
    if((*boat).getSide() == Side::RIGHT) { (*boat).displayPersons(); }
    cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Droite: ";
    (*rightBank).displayPersons();
    cout << "----------------------------------------------------------" << endl;
}

void Controller::nextTurn() {
    if(turn == 0){
        showMenu();
        display();
    }

    cout << turn << ">";
    string move, param;
    cin >> move;
    cin >> param;

    switch (move){

    }
}



