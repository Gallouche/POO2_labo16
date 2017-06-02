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
    Person* currentPerson = nullptr;

    tuple<char, string> result;

    result = checkCommand(toParse);
    move = get<0>(result);
    person = get<1>(result);
    if(person != "") {
        currentPerson = getPersonByName(person);
    }

    switch (move){
        case 'p':
            showMenu();
            display();
            break;
        case 'e':
            if(!currentPerson) throw std::invalid_argument("Personne non definie !");
            embarquer(currentPerson);
            showMenu();
            display();
            break;
        case 'd':
            if(!currentPerson) throw std::invalid_argument("Personne non definie !");
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
            throw std::invalid_argument("Commande inconnue !");
    }
}

void Controller::run() {
    while (true){
        try {
            nextTurn();
        }catch(std::exception& e) {
            cerr << e.what() << endl;
            turn--;
        }
        if(finished() or ended)
            break;
    }
    if(!ended)
        cout << "Bravo, c'est gagne !" << endl;


}

void Controller::embarquer(Person *p) {
    if(boat->getSize() == 2){
        cout << "Le bateau est plein !" << endl;
    }
    else if(boat->contains(p))
        cout << p->getName() << " est deja dans le bateau !" << endl;
    else if (!boat->getSide()->contains(p))
        cout << p->getName() << " n'est pas sur la berge !" << endl;
    else{
        boat->getSide()->removePerson(p);
        boat->addPerson(p);
    }
}

void Controller::debarquer(Person *p) {
    if(!boat->contains(p))
        cout << p->getName() << " n'est pas dans le bateau !" << endl << endl;
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

Person *Controller::getPersonByName(const string &name) {
    for(Person* p : listInit){
        if(p->getName() == name) {
            return p;
        }
    }
    throw std::invalid_argument("Personne inconnue !");
}

bool Controller::finished() {
    return rightBank->getSize() == listInit.size();
}

void Controller::reInit() {
    // Clear all containers, and set to initial state
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

tuple<char, string> Controller::checkCommand(const string &toParse) {
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

    // Throw exception if empty entry
    if(toParse == "") {
        throw std::invalid_argument("Saisie vide !");
    }

    if(toParse.size() < 2) {
        return make_tuple(toParse.at(0), "");
    } else if(toParse.at(1) == ' ') {
        return make_tuple(toParse.at(0), toParse.substr(2));
    } else {
        throw std::invalid_argument("Erreur de saisie !");
    }
}

