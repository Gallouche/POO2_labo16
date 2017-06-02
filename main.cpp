/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : main.cpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe main

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#include <iostream>

#include "Controller.hpp"
#include "Fille.hpp"
#include "Fils.hpp"
#include "Voleur.hpp"

int main() {
    Person* papa = new Person("papa");
    Person* maman = new Person("maman");
    Person* paul = new Fils("paul", papa, maman);
    Person* pierre = new Fils("pierre", papa, maman);
    Person* julie = new Fille("julie", papa, maman);
    Person* jeanne = new Fille("jeanne", papa, maman);
    Person* policier = new Person("policier");
    Person* voleur = new Voleur("voleur", policier);

    Controller c({papa,maman, paul, pierre, julie, jeanne, policier, voleur});
    c.run();

    return EXIT_SUCCESS;
}