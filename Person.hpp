//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_PERSON_HPP
#define LABO16_PERSON_HPP


#include <string>

using namespace std;

class Person {
private:
    string name;
    bool drive;
public:
    Person(string name);
    Person(string name, bool canDrive);
    ~Person(){}
    bool canDrive();
    string getName();
    friend bool operator == (const Person& lhs, const Person& rhs);
};


#endif //LABO16_PERSON_HPP
