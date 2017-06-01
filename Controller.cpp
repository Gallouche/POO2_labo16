//
// Created by Gallouche on 19/05/2017.
//

#include "Controller.hpp"

Controller::Controller(initializer_list<Person*> p):
        turn(0),
        ended(false)
{
    listInit = list<Person*>();
    leftBank = new Bank("left");
    rightBank = new Bank("right");
    boat = new Boat("boat");
    boat->setSide(leftBank);
    for(initializer_list<Person*>::iterator it = p.begin(); it != p.end(); it++){
        leftBank->addPerson(*it);
        listInit.push_back(*it);
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
    if(boat->getSide() == leftBank)  { boat->displayPersons();}
    else cout << endl;
    cout << "==========================================================" << endl;
    if(boat->getSide() == rightBank) { boat->displayPersons(); }
    else cout << endl;
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
            embarquer(getPersonByName(person));
            display();
            break;
        case 'd':
            cin >> person;
            debarquer(getPersonByName(person));
            display();
            break;
        case 'm':
            moveBoat();
            display();
            break;
        case 'r':
            turn = -1;
            //leftBank = listInit;
            rightBank->clear();
            boat->clear();
            boat->setSide(leftBank);
            cout << "Partie reinitialisee !" << endl << endl;
            break;
        case 'q':
            cout << "Fin de la partie ! " << endl;
            ended = true;
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
    while (true){
        nextTurn();
        testTaille();
        if(finished() or ended)
            break;
    }
    if(!ended)
        cout << "Bravo, c'est gagne !" << endl;


}

void Controller::embarquer(Person *p) {
    if(boat->contain(p))
         cout << p->getName() << " est deja dans le bateau !" << endl;
    else if (!boat->getSide()->contain(p))
        cout << p->getName() << " n'est pas sur la berge !" << endl;
    else{
        boat->getSide()->removePerson(p);
        boat->addPerson(p);
    }
}

void Controller::debarquer(Person *p) {
    if(!boat->contain(p))
        cout << p->getName() << " n'est pas dans le bateau !" << endl;
    else{
        boat->removePerson(p);
        boat->getSide()->addPerson(p);
    }
}

void Controller::moveBoat() {
    if(boat->getSide() == rightBank){
        boat->setSide(leftBank);
    }
    else
        boat->setSide(rightBank);
}

Person *Controller::getPersonByName(string name) {
    for(Person* p : listInit){
        if(p->getName() == name) {
            return p;
        }
    }
    cout << "Personne inconnue !";
    return nullptr; //TODO gerer le cas ou la personne existe pas
}

bool Controller::finished() {
    return rightBank->getSize() == listInit.size();
}

void Controller::testTaille() {
    cout << "Init " << listInit.size() << endl;
    cout << "Lbank " << leftBank->getSize() << endl;
    cout << "Boat " << boat->getSize() << endl;
    cout << "Rbank " << rightBank->getSize() << endl;
    cout << finished() << endl;
}

