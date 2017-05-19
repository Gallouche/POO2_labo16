//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_CONTROLLER_HPP
#define LABO16_CONTROLLER_HPP



#include <iostream>

#include "Bank.hpp"
#include "Boat.hpp"

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


#endif //LABO16_CONTROLLER_HPP
