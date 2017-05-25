//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_CONTROLLER_HPP
#define LABO16_CONTROLLER_HPP



#include <iostream>
#include <list>
#include <string>

#include "Bank.hpp"
#include "Boat.hpp"
#include "Person.hpp"

using namespace std;

class Controller {
private:
    Bank* listInit;
    int turn;
    Bank* leftBank;
    Bank* rightBank;
    Boat* boat;
    bool finished;

public:
    Controller(initializer_list<Person*> p);
    void showMenu();
    void display();
    void nextTurn();
    void run();
};


#endif //LABO16_CONTROLLER_HPP
