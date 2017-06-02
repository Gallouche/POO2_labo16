//
// Created by Gallouche on 19/05/2017.
//

#ifndef LABO16_PERSON_HPP
#define LABO16_PERSON_HPP

#include <string>
#include <list>

using namespace std;

class Person {
protected:
    string name;
public:

    /**
     * Person constructor
     * @param name the name of the person
     */
    Person(const string &name);

    /**
     * Person destructor
     */
    ~Person(){}

    /**
     * Gets if the person can drive or not
     * @return true or false
     */
    virtual bool canDrive();

    /**
     * Gets the name of the person
     * @return the name
     */
    string getName();

    /**
     * Comparison operator, compare the names of the 2 people
     * @param lhs the first person
     * @param rhs the second person
     * @return true or false
     */
    friend bool operator == (const Person& lhs, const Person& rhs);


    virtual bool checkConditions(list<Person*> l);
};


#endif //LABO16_PERSON_HPP
