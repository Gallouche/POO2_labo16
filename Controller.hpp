/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Controller.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Controller" contient les differents containers.  Gere les
               differents movement possibles du jeu.

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO16_CONTROLLER_HPP
#define LABO16_CONTROLLER_HPP

#include <iostream>
#include <list>
#include <string>
#include <regex>

#include "Bank.hpp"
#include "Boat.hpp"
#include "Person.hpp"

using namespace std;

class Controller {
private:
    list<Person*> listInit;
    int turn;
    Bank* leftBank;
    Bank* rightBank;
    Boat* boat;
    bool ended;

    /**
     * Displays the user's menu, shows the different possible commands.
     */
    void showMenu();

    /**
     * Displays the current river state.
     */
    void display();

    /**
     * Apply the action choosen by the user.
     */
    void nextTurn();

    /**
     * Loads the choosen person on the boat.
     * @param p a pointer on the person
     */
    void embarquer(Person* p);

    /**
     * Unloads the choosen person from the boat.
     * @param p a pointer on the person
     */
    void debarquer(Person* p);

    /**
     * Moves the boat from a bank to the other.
     */
    void moveBoat();

    /**
     * Gets a person by it's name. Throw an exception if the person doesn't exists.
     * @param name the name of the person
     * @return a pointer on the person
     */
    Person* getPersonByName(const string &name);

    /**
     * Checks if the game is finished by comparing the initial list of persons size to the right bank size.
     * If they are equals, it means that all the people have changed side.
     * @return true of false
     */
    bool finished();

    /**
     * Reinitializes the game, set it to initial state
     */
    void reInit();

    /**
     *
     * @param toParse the string to parse
     * @return a tuple that contains the command and the name of the person.
     * If the string to parse is < 2, returns a tuple that contains the command and an empty string.
     * Throw exception if the string is > 2 but the second charactere isn't a space char.
     */
    std::tuple<char, string> checkCommand(const string &toParse);

public:

    /**
     * Controller constructor
     * @param p the initializer_list of people
     */
    Controller(initializer_list<Person*> p);

    /**
     * Controller destructor
     */
    ~Controller();

    /**
     * Starts the game
     */
    void run();

};


#endif //LABO16_CONTROLLER_HPP
