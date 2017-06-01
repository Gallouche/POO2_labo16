//
// Created by Gallouche on 19/05/2017.
//

#include "Controller.hpp"

Controller::Controller(initializer_list<Person *> p):
        turn(0),
        finished(false)
{
    listInit = new Bank("initial");
    leftBank = new Bank("left");
    rightBank = new Bank("right");
    boat = new Boat("boat");
    for(initializer_list<Person*>::iterator it = p.begin(); it != p.end(); it++){
        leftBank->addPerson(*it);
        listInit->addPerson(*it);
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
    cout << "==========================================================" << endl;
    if((*boat).getSide() == Side::RIGHT) { (*boat).displayPersons(); }
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
    char move;
    string person;
    cin >> move;

    switch (move){
        case 'p':
            display();
            break;
        case 'e':
            cin >> person;
            for (list<Person*>::iterator it = l.begin(); it != l.end(); it++){

            }
            break;
        case 'd':
            break;
        case 'm':
            boat->changeSide();
            display();
            break;
        case 'r':
            turn = -1;
            leftBank = listInit;
            rightBank->clear();
            boat->clear();
            boat->setSide(Side::LEFT);
            cout << "Partie réinitialisée !" << endl;
            break;
        case 'q':
            cout << "Fin de la partie ! ";
            finished = true;
            break;
        case 'h':
            showMenu();
            break;
        default:
            cout << "Commande inconnu !" << endl;
            turn--;
            break;
    }
    turn++;
}

void Controller::run() {
    while (!finished){
        nextTurn();
    }
}



