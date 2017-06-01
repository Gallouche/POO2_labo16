//
// Created by Gallouche on 19/05/2017.
//

#include "Controller.hpp"

Controller::Controller(initializer_list<Person*> p):
        turn(0),
        ended(false)
{
    listInit = list<Person*>();
    leftBank = new Bank("Gauche");
    rightBank = new Bank("Droite");
    boat = new Boat("Bateau");
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
    cout << leftBank->getName() << ": ";
    (*leftBank).displayPersons();
    cout << "----------------------------------------------------------" << endl;
    if(boat->getSide() == leftBank)  {
        cout << boat->getName() << ": ";
        boat->displayPersons();
    }
    else cout << endl;
    cout << "==========================================================" << endl;
    if(boat->getSide() == rightBank) {
        cout << boat->getName() << ": ";
        boat->displayPersons();
    }
    else cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << rightBank->getName() << ": ";
    (*rightBank).displayPersons();
    cout << "----------------------------------------------------------" << endl;
}

void Controller::nextTurn() {
    if(turn == 0){
        showMenu();
        display();
    }

    cout << turn << ">";
    turn++;
    char move;
    string person;
    string str;
    getline(cin,str);
    move = str.at(0);
    Person* currentPerson;
    if(str.size() > 1){
        person = str.substr(2);
         currentPerson = getPersonByName(person);
        if(!currentPerson){
            return;
        }
    }

    switch (move){
        case 'p':
            showMenu();
            display();
            break;
        case 'e':
            embarquer(currentPerson);
            showMenu();
            display();
            break;
        case 'd':
            debarquer(currentPerson);
            showMenu();
            display();
            break;
        case 'm':
            moveBoat();
            showMenu();
            display();
            break;
        case 'r':
            turn = 0;
            rightBank->clear();
            leftBank->clear();
            for(Person* p : listInit){
                leftBank->addPerson(p);
            }
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
}

void Controller::run() {
    while (true){
        nextTurn();
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
    cout << "Personne inconnue !" << endl;
    return nullptr;
}

bool Controller::finished() {
    return rightBank->getSize() == listInit.size();
}


