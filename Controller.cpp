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
    string toParse;
    getline(cin,toParse);
    Person* currentPerson;

    bool valid = checkCommand(toParse, move, person);
    currentPerson = getPersonByName(person);
    if((!currentPerson && toParse.size() > 2) || !valid) {
        cout << "Commande ou personne invalide !" << endl;
        return;
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
            reInit();
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
    return nullptr;
}

bool Controller::finished() {
    return rightBank->getSize() == listInit.size();
}

void Controller::reInit() {
    turn = 0;
    rightBank->clear();
    leftBank->clear();
    for(Person* p : listInit){
        leftBank->addPerson(p);
    }
    boat->clear();
    boat->setSide(leftBank);
    cout << "Partie reinitialisee !" << endl << endl;
}

bool Controller::checkCommand(const string &toParse, char &move, string &person) {
    //regex r("([pedrmqh] [^\\s]+)|([pedrmqh])");
//    if(regex_match(toParse,r)){
//        move = toParse.at(0);
//        person = toParse.substr(2);
//        return true;
//    }
//    else{
//        cout << "Commande invalide" << endl;
//        return false;
//    }

    if(toParse.size() < 2){
        move = toParse.at(0);
        return true;
    }
    else if(toParse.at(1) == ' '){
        move = toParse.at(0);
        person = toParse.substr(2);
        return true;
    }
    else
        return false;
}

