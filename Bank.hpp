/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 16 : Riviere
 Fichier     : Bank.hpp
 Auteur(s)   : Théo Gallandat <theo.gallandat@heig-vd.ch>
               Pierre-Samuel Rochat <pierre-samuel.rochat@heig-vd.ch>
 Date        : 02.06.2017

 But         : Classe "Bank" (rive) herite de container.

 Remarque(s) : RAS

 Compilateur : MinGW-g++ 4.8.1
 -----------------------------------------------------------------------------------
 */

#ifndef LABO16_BANK_HPP
#define LABO16_BANK_HPP

#include "Container.hpp"

class Bank: public Container {
public:
    /**
     * Bank constructor
     * @param name the name of the container
     */
    Bank(const string &name) : Container(name) {}
};

#endif //LABO16_BANK_HPP
